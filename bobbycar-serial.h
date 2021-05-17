#pragma once

#include <stdint.h>

#include "bobbycar-common.h"

struct MotorState {
    bool enable = false;
    int16_t pwm = 0;
    ControlType ctrlTyp = ControlType::FieldOrientedControl;
    ControlMode ctrlMod = ControlMode::OpenMode;
    uint8_t iMotMax = 15;                  // [A] Maximum motor current limit
    uint8_t iDcMax = 17;                   // [A] Maximum DC Link current limit (This is the final current protection. Above this value, current chopping is applied. To avoid this make sure that I_DC_MAX = I_MOT_MAX + 2A)
    uint16_t nMotMax = 1000;               // [rpm] Maximum motor speed limit
    uint8_t fieldWeakMax = 10;             // [A] Maximum Field Weakening D axis current (only for FOC). Higher current results in higher maximum speed.
    uint8_t phaseAdvMax = 40;              // [deg] Maximum Phase Advance angle (only for SIN). Higher angle results in higher maximum speed.
};

inline uint16_t calculateChecksum(MotorState state) {
    return
        uint16_t(state.enable) ^
        state.pwm ^
        uint16_t(state.ctrlTyp) ^
        uint16_t(state.ctrlMod) ^
        state.iMotMax ^
        state.iDcMax ^
        state.nMotMax ^
        state.fieldWeakMax ^
        state.phaseAdvMax;
}

struct BuzzerState {
    uint8_t freq = 0;
    uint8_t pattern = 0;
};

inline uint16_t calculateChecksum(BuzzerState state) {
    return state.freq ^ state.pattern;
}

struct Command {
    static constexpr uint16_t VALID_HEADER = 0xAAAA;
    static constexpr uint16_t INVALID_HEADER = 0xFFFF;

    uint16_t start;

    MotorState left, right;

    BuzzerState buzzer;

    bool poweroff = false;
    bool led = false;

    uint16_t checksum;
};

inline uint16_t calculateChecksum(Command command) {
    return command.start ^
           calculateChecksum(command.left) ^
           calculateChecksum(command.right) ^
           calculateChecksum(command.buzzer) ^
           command.poweroff ^
           command.led;
}

struct MotorFeedback {
    int16_t   angle = 0;
    int16_t   speed = 0;
    uint8_t   error = 0;
    int16_t   current = 0;
    uint16_t  chops = 0;
    bool      hallA = false,
        hallB = false,
        hallC = false;
};

inline uint16_t calculateChecksum(MotorFeedback feedback) {
    return feedback.angle ^ feedback.speed ^
           feedback.error ^ feedback.current ^
           feedback.chops ^
           feedback.hallA ^ feedback.hallB ^ feedback.hallC;
}

struct Feedback {
    static constexpr uint16_t VALID_HEADER = 0xAAAA;
    static constexpr uint16_t INVALID_HEADER = 0xFFFF;

    uint16_t start;

    MotorFeedback left, right;

    int16_t   batVoltage = 0;
    int16_t   boardTemp = 0;

    int16_t timeoutCntSerial   = 0;

    uint16_t checksum;
};

inline uint16_t calculateChecksum(Feedback feedback) {
    return feedback.start ^
           calculateChecksum(feedback.left) ^
           calculateChecksum(feedback.right) ^
           feedback.batVoltage ^
           feedback.boardTemp ^
           feedback.timeoutCntSerial;
}


#define ASSERT_LAYOUT(st, memb, off) \
static_assert(offsetof(st, memb) == off, "struct layout wrong");

ASSERT_LAYOUT(Feedback, start, 0);
ASSERT_LAYOUT(Feedback, left, 2);
ASSERT_LAYOUT(Feedback, left.angle, 2);
ASSERT_LAYOUT(Feedback, left.speed, 4);
ASSERT_LAYOUT(Feedback, left.error, 6);
ASSERT_LAYOUT(Feedback, left.current, 8);
ASSERT_LAYOUT(Feedback, left.chops, 10);
ASSERT_LAYOUT(Feedback, left.hallA, 12);
ASSERT_LAYOUT(Feedback, left.hallB, 13);
ASSERT_LAYOUT(Feedback, left.hallC, 14);

ASSERT_LAYOUT(Feedback, right, 16);
ASSERT_LAYOUT(Feedback, right.angle, 16);
ASSERT_LAYOUT(Feedback, right.speed, 18);
ASSERT_LAYOUT(Feedback, right.error, 20);
ASSERT_LAYOUT(Feedback, right.current, 22);
ASSERT_LAYOUT(Feedback, right.chops, 24);
ASSERT_LAYOUT(Feedback, right.hallA, 26);
ASSERT_LAYOUT(Feedback, right.hallB, 27);
ASSERT_LAYOUT(Feedback, right.hallC, 28);

ASSERT_LAYOUT(Feedback, batVoltage, 30);
ASSERT_LAYOUT(Feedback, boardTemp, 32);
ASSERT_LAYOUT(Feedback, timeoutCntSerial, 34);
ASSERT_LAYOUT(Feedback, checksum, 36);

static_assert(sizeof(Command) == 32, "sizeof(Command) wrong");

ASSERT_LAYOUT(Command, start, 0);

ASSERT_LAYOUT(Command, left, 2);
ASSERT_LAYOUT(Command, left.enable, 2);
ASSERT_LAYOUT(Command, left.pwm, 4);
ASSERT_LAYOUT(Command, left.ctrlTyp, 6);
ASSERT_LAYOUT(Command, left.ctrlMod, 7);
ASSERT_LAYOUT(Command, left.iMotMax, 8);
ASSERT_LAYOUT(Command, left.iDcMax, 9);
ASSERT_LAYOUT(Command, left.nMotMax, 10);
ASSERT_LAYOUT(Command, left.fieldWeakMax, 12);
ASSERT_LAYOUT(Command, left.phaseAdvMax, 13);

ASSERT_LAYOUT(Command, right.enable, 14);
ASSERT_LAYOUT(Command, right.pwm, 16);
ASSERT_LAYOUT(Command, right.ctrlTyp, 18);
ASSERT_LAYOUT(Command, right.ctrlMod, 19);
ASSERT_LAYOUT(Command, right.iMotMax, 20);
ASSERT_LAYOUT(Command, right.iDcMax, 21);
ASSERT_LAYOUT(Command, right.nMotMax, 22);
ASSERT_LAYOUT(Command, right.fieldWeakMax, 24);
ASSERT_LAYOUT(Command, right.phaseAdvMax, 25);

ASSERT_LAYOUT(Command, buzzer, 26);
ASSERT_LAYOUT(Command, buzzer.freq, 26);
ASSERT_LAYOUT(Command, buzzer.pattern, 27);

ASSERT_LAYOUT(Command, poweroff, 28);
ASSERT_LAYOUT(Command, led, 29);
ASSERT_LAYOUT(Command, checksum, 30);
