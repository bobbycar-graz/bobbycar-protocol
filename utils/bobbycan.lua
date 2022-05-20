local p_bobbycan = Proto("bobbycan", "BobbyCAN")
p_bobbycan.fields = {}

local function format_voltage(val)
    return string.format("%.2f V", val / 100)
end

local function format_cmd_current(val)
    return string.format("%d A", val)
end

local function format_fb_current(val)
    return string.format("%.2f A", -val / 50)
end

local function format_angle(val)
    return string.format("%d°", val)
end

local function format_temperature(val)
    return string.format("%.1f °C", val / 10)
end

local function format_speed(val)
    return string.format("%d RPM", val)
end

local motor_cmds = {
    [ 0] = { len = 1, abbr = "enable",        name = "Enable",       type = ftypes.BOOLEAN },
    [ 1] = { len = 2, abbr = "inp_tgt",       name = "Input target", type = ftypes.INT16 },
    [ 2] = { len = 1, abbr = "ctrl_typ",      name = "Control type", type = ftypes.UINT8,
        valuestring = {"Commutation", "Sinusoidal", "FOC"} },
    [ 3] = { len = 1, abbr = "ctrl_mod",      name = "Control mode", type = ftypes.UINT8,
        valuestring = {"Open", "Voltage", "Speed", "Torque"} },
    [ 4] = { len = 1, abbr = "imotmax",       name = "Maximum motor current",           type = ftypes.UINT8,   format = format_cmd_current },
    [ 5] = { len = 1, abbr = "idcmax",        name = "Maximum DC link current",         type = ftypes.UINT8,   format = format_cmd_current },
    [ 6] = { len = 2, abbr = "nmotmax",       name = "Maximum speed",                   type = ftypes.UINT16,  format = format_speed },
    [ 7] = { len = 1, abbr = "fieldweakmax",  name = "Maximum field weakening current", type = ftypes.UINT8,   format = format_cmd_current },
    [ 8] = { len = 1, abbr = "phaseadvmax",   name = "Maximum phase advance angle",     type = ftypes.UINT16,  format = format_angle },
    [ 9] = { len = 1, abbr = "cruisectrlena", name = "Enable cruise control",           type = ftypes.BOOLEAN },
    [10] = { len = 1, abbr = "cruisemottgt",  name = "Cruise control target",           type = ftypes.INT16,   format = format_speed },
    [11] = { len = 1, abbr = "buzzerfreq",    name = "Buzzer freq. divider",            type = ftypes.UINT8 },
    [12] = { len = 1, abbr = "buzzerpattern", name = "Buzzer pattern",                  type = ftypes.UINT8 },
    [13] = { len = 1, abbr = "led",           name = "LED state",                       type = ftypes.BOOLEAN },
    [14] = { len = 1, abbr = "poweroff",      name = "Power off",                       type = ftypes.BOOLEAN },
}

local motor_errors = {
    [0] = "None",
    [1] = "Hall sensor not connected",
    [2] = "Hall sensor short circuit",
    [4] = "Motor NOT able to spin"
}

local motor_fbs = {
    [ 0] = { len = 2, abbr = "dc_link", name = "DC Link Current",         type = ftypes.INT16, format = format_fb_current },
    [ 1] = { len = 2, abbr = "speed",   name = "Speed",                   type = ftypes.INT16 },
    [ 2] = { len = 1, abbr = "error",   name = "Error",                   type = ftypes.UINT8, valuestring = motor_errors },
    [ 3] = { len = 2, abbr = "angle",   name = "Electrical angle",        type = ftypes.INT16, format = format_angle },
    [ 4] = { len = 2, abbr = "dc_a",    name = "Phase A Current",         type = ftypes.INT16, format = format_fb_current },
    [ 5] = { len = 2, abbr = "dc_b",    name = "Phase B Current",         type = ftypes.INT16, format = format_fb_current },
    [ 6] = { len = 2, abbr = "dc_c",    name = "Phase C Current",         type = ftypes.INT16, format = format_fb_current },
    [ 7] = { len = 4, abbr = "chops",   name = "Chops since last update", type = ftypes.UINT32 },
    [ 8] = { len = 1, abbr = "hall",    name = "Hall Sensors",            type = ftypes.UINT8 },
    [ 9] = { len = 2, abbr = "voltage", name = "Supply Voltage",          type = ftypes.INT16, format = format_voltage },
    [10] = { len = 2, abbr = "temp",    name = "MCU Temperature",         type = ftypes.INT16, format = format_temperature },
    [11] = { len = 2, abbr = "curr_id", name = "Id current",              type = ftypes.INT16, format = format_fb_current },
    [12] = { len = 2, abbr = "curr_iq", name = "Iq current",              type = ftypes.INT16, format = format_fb_current },
}

local motor_generated = {
    left  = { abbr = "left",  name = "Is left",     type = ftypes.BOOLEAN },
    right = { abbr = "right", name = "Is right",    type = ftypes.BOOLEAN },
    front = { abbr = "front", name = "Is front",    type = ftypes.BOOLEAN },
    back  = { abbr = "back",  name = "Is back",     type = ftypes.BOOLEAN },
    cmd   = { abbr = "cmd",   name = "Is command",  type = ftypes.BOOLEAN },
    fb    = { abbr = "fb",    name = "Is feedback", type = ftypes.BOOLEAN },
}

local function create_fields(prefix, proto)
    for k,p in pairs(proto) do
        p.field = ProtoField.new(p.name, prefix .. p.abbr, p.type, p.valuestring, p.base, p.mask, p.descr)
        table.insert(p_bobbycan.fields, p.field)
    end
end
create_fields("bobbycan.motor.", motor_cmds)
create_fields("bobbycan.motor.", motor_fbs)
create_fields("bobbycan.motor.", motor_generated)

local f_can_id = Field.new("can.id")

function to_int(t, tvsr)
    if t == ftypes.UINT8 or t == ftypes.UINT16 or t == ftypes.UINT32 then
        return tvsr:le_uint()
    else
        return tvsr:le_int()
    end
end

function p_bobbycan.dissector(buf, pkt, tree)
    pkt.cols.protocol:set("BobbyCAN")

    local can_id = f_can_id()()
    pkt.cols.info:set("test " .. can_id)

    local devtype = bit32.rshift(bit32.band(can_id, 0x700), 8)
    if devtype == 0 then
        local command = bit32.band(can_id, 0x80) == 0
        local subid = bit32.rshift(bit32.band(can_id, 0x7c), 2)
        local tbl
        local prefix

        local generated_fields = { nil, nil, nil }
        if command then
            tbl = motor_cmds
            prefix = "  CMD "
            generated_fields[1] = motor_generated.cmd.field
        else
            tbl = motor_fbs
            prefix = "  FB "
            generated_fields[1] = motor_generated.fb.field
        end

        local front = bit32.band(can_id, 0x02) == 0
        if front then
            prefix = prefix .. "F"
            generated_fields[2] = motor_generated.front.field
        else
            prefix = prefix .. "B"
            generated_fields[2] = motor_generated.back.field
        end

        local left = bit32.band(can_id, 0x01) == 0
        if left then
            prefix = prefix .. "L "
            generated_fields[3] = motor_generated.left.field
        else
            prefix = prefix .. "R "
            generated_fields[3] = motor_generated.right.field
        end

        local meta = tbl[subid]
        local tvsr = buf(0,meta.len)
        local subtree = tree:add(p_bobbycan, tvsr)

        local field_val = to_int(meta.type, tvsr)
        local ti = subtree:add_packet_field(meta.field, tvsr, ENC_LITTLE_ENDIAN)
        local val_fmt
        if meta.format then
            val_fmt = meta.format(field_val)
        elseif meta.valuestring and meta.valuestring[field_val] then
            val_fmt = string.format("%s (%d)", meta.valuestring[field_val], field_val)
        else
            val_fmt = tostring(field_val)
        end
        ti.text = meta.name..": "..val_fmt
        pkt.cols.info:set(prefix..meta.name.." = "..val_fmt)

        -- Add generated fields (front, back, left, right, cmd, fb)
        for k,f in ipairs(generated_fields) do
            subtree:add(f, true):set_generated()
        end
    end
end

can_table = DissectorTable.get("can.subdissector")
can_table:add_for_decode_as(p_bobbycan)
