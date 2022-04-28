#pragma once

#include <cstdint>

namespace bobbycar {
namespace protocol {
namespace can {

enum : uint16_t { //              vvv'
    DeviceTypeMotorController = 0b000'00000000,
    DeviceTypeBoardcomputer =   0b001'00000000
};

template<bool isBack, bool isRight>
class MotorController
{
private:
    enum : uint16_t { //              ...v
        MotorControllerCommand =    0b00000000000, // send only TO the motor controller
        MotorControllerFeedback =   0b00010000000, // send only FROM the motor controller
    };

    enum : uint16_t { //              .........v
        MotorControllerFront =      0b00000000000,
        MotorControllerBack =       0b00000000010,
    };

    enum : uint16_t { //              ..........v
        MotorControllerLeft =       0b00000000000,
        MotorControllerRight =      0b00000000001,
    };

    enum : uint16_t {
        MotorControllerMask =
            uint16_t(DeviceTypeMotorController) |
            uint16_t(isBack ? MotorControllerBack : MotorControllerFront) |
            uint16_t(isRight ? MotorControllerRight : MotorControllerLeft)
    };

public:
    MotorController() = delete;
    ~MotorController() = delete;

    // send only TO the motor controller
    class Command
    {
    private:
        enum : uint16_t {
            MotorControllerCommandMask =
                uint16_t(MotorControllerMask) |
                uint16_t(MotorControllerCommand)
        };

    public:
        Command() = delete;
        ~Command() = delete;

        enum : uint16_t { //  ....'vvvvv'..
            Enable =        0b0000'00000'00 | MotorControllerCommandMask,
            InpTgt =        0b0000'00001'00 | MotorControllerCommandMask,
            CtrlTyp =       0b0000'00010'00 | MotorControllerCommandMask,
            CtrlMod =       0b0000'00011'00 | MotorControllerCommandMask,
            IMotMax =       0b0000'00100'00 | MotorControllerCommandMask,
            IDcMax =        0b0000'00101'00 | MotorControllerCommandMask,
            NMotMax =       0b0000'00110'00 | MotorControllerCommandMask,
            FieldWeakMax =  0b0000'00111'00 | MotorControllerCommandMask,
            PhaseAdvMax =   0b0000'01000'00 | MotorControllerCommandMask,
            CruiseCtrlEna = 0b0000'01001'00 | MotorControllerCommandMask,
            CruiseMotTgt =  0b0000'01010'00 | MotorControllerCommandMask,
            BuzzerFreq =    0b0000'01011'00 | MotorControllerCommandMask,
            BuzzerPattern = 0b0000'01100'00 | MotorControllerCommandMask,
            Led =           0b0000'01101'00 | MotorControllerCommandMask,
            Poweroff =      0b0000'01110'00 | MotorControllerCommandMask
        };
    };

    // send only FROM the motor controller
    class Feedback
    {
    private:
        enum : uint16_t {
            MotorControllerFeedbackMask =
                uint16_t(MotorControllerMask) |
                uint16_t(MotorControllerFeedback)
        };

    public:
        Feedback() = delete;
        ~Feedback() = delete;

        enum : uint16_t { // ....'vvvvv'..
            DcLink =       0b0000'00000'00 | MotorControllerFeedbackMask,
            Speed =        0b0000'00001'00 | MotorControllerFeedbackMask,
            Error =        0b0000'00010'00 | MotorControllerFeedbackMask,
            Angle =        0b0000'00011'00 | MotorControllerFeedbackMask,
            DcPhaA =       0b0000'00100'00 | MotorControllerFeedbackMask, // unused
            DcPhaB =       0b0000'00101'00 | MotorControllerFeedbackMask, // unused
            DcPhaC =       0b0000'00110'00 | MotorControllerFeedbackMask, // unused
            Chops =        0b0000'00111'00 | MotorControllerFeedbackMask,
            Hall =         0b0000'01000'00 | MotorControllerFeedbackMask,
            Voltage =      0b0000'01001'00 | MotorControllerFeedbackMask,
            Temp =         0b0000'01010'00 | MotorControllerFeedbackMask,
            Id =           0b0000'01011'00 | MotorControllerFeedbackMask,
            Iq =           0b0000'01100'00 | MotorControllerFeedbackMask,
        };
    };
};

class Boardcomputer
{
private:
    enum : uint16_t { //            ...v
        BoardcomputerCommand =    0b00000000000, // send only TO the boardcomputer
        BoardcomputerFeedback =   0b00010000000, // send only FROM the boardcomputer
    };

public:
    Boardcomputer() = delete;
    ~Boardcomputer() = delete;

    // used with ButtonPressed and ButtonReleased
    enum class Button {
        Profile0 = 1,
        Profile1 = 2,
        Profile2 = 4,
        Profile3 = 8,
        Left = 16,
        Right = 32,
        Up = 64,
        Down = 128,
        Left2 = 256,
        Right2 = 512,
        Up2 = 1024,
        Down2 = 2048,
    };

    // send only TO the boardcomputer
    class Command
    {
    private:
        enum : uint16_t {
            BoardcomputerCommandMask =
                uint16_t(DeviceTypeBoardcomputer) |
                uint16_t(BoardcomputerCommand)
        };

    public:
        Command() = delete;
        ~Command() = delete;

        enum : uint16_t { //      ....'vvvvvvv
            RawButtonPressed  = 0b0000'0000000 | BoardcomputerCommandMask,
            RawButtonReleased = 0b0000'0000001 | BoardcomputerCommandMask,
            ButtonPressed     = 0b0000'0000010 | BoardcomputerCommandMask,
            ButtonReleased    = 0b0000'0000011 | BoardcomputerCommandMask,
            RawGas            = 0b0000'0000100 | BoardcomputerCommandMask,
            RawBrems          = 0b0000'0000101 | BoardcomputerCommandMask
        };
    };

    // send only FROM the boardcomputer
    class Feedback
    {
    private:
        enum : uint16_t {
            BoardcomputerFeedbackMask =
                uint16_t(DeviceTypeBoardcomputer) |
                uint16_t(BoardcomputerFeedback)
        };

    public:
        Feedback() = delete;
        ~Feedback() = delete;

        enum : uint16_t { //  ....'vvvvvvv
            ButtonLeds =    0b0000'0000000 | BoardcomputerFeedbackMask,
        };
    };
};

inline const char *bobbycarCanIdDesc(uint16_t id)
{
    switch (id)
    {
    case MotorController<false, false>::Command::Enable: return "Enable (MotorController, Command, Front, Left)";
    case MotorController<false, true>::Command::Enable: return "Enable (MotorController, Command, Front, Right)";
    case MotorController<true, false>::Command::Enable: return "Enable (MotorController, Command, Back, Left)";
    case MotorController<true, true>::Command::Enable: return "Enable (MotorController, Command, Back, Right)";
    case MotorController<false, false>::Command::InpTgt: return "InpTgt (MotorController, Command, Front, Left)";
    case MotorController<false, true>::Command::InpTgt: return "InpTgt (MotorController, Command, Front, Right)";
    case MotorController<true, false>::Command::InpTgt: return "InpTgt (MotorController, Command, Back, Left)";
    case MotorController<true, true>::Command::InpTgt: return "InpTgt (MotorController, Command, Back, Right)";
    case MotorController<false, false>::Command::CtrlTyp: return "CtrlTyp (MotorController, Command, Front, Left)";
    case MotorController<false, true>::Command::CtrlTyp: return "CtrlTyp (MotorController, Command, Front, Right)";
    case MotorController<true, false>::Command::CtrlTyp: return "CtrlTyp (MotorController, Command, Back, Left)";
    case MotorController<true, true>::Command::CtrlTyp: return "CtrlTyp (MotorController, Command, Back, Right)";
    case MotorController<false, false>::Command::CtrlMod: return "CtrlMod (MotorController, Command, Front, Left)";
    case MotorController<false, true>::Command::CtrlMod: return "CtrlMod (MotorController, Command, Front, Right)";
    case MotorController<true, false>::Command::CtrlMod: return "CtrlMod (MotorController, Command, Back, Left)";
    case MotorController<true, true>::Command::CtrlMod: return "CtrlMod (MotorController, Command, Back, Right)";
    case MotorController<false, false>::Command::IMotMax: return "IMotMax (MotorController, Command, Front, Left)";
    case MotorController<false, true>::Command::IMotMax: return "IMotMax (MotorController, Command, Front, Right)";
    case MotorController<true, false>::Command::IMotMax: return "IMotMax (MotorController, Command, Back, Left)";
    case MotorController<true, true>::Command::IMotMax: return "IMotMax (MotorController, Command, Back, Right)";
    case MotorController<false, false>::Command::IDcMax: return "IDcMax (MotorController, Command, Front, Left)";
    case MotorController<false, true>::Command::IDcMax: return "IDcMax (MotorController, Command, Front, Right)";
    case MotorController<true, false>::Command::IDcMax: return "IDcMax (MotorController, Command, Back, Left)";
    case MotorController<true, true>::Command::IDcMax: return "IDcMax (MotorController, Command, Back, Right)";
    case MotorController<false, false>::Command::NMotMax: return "NMotMax (MotorController, Command, Front, Left)";
    case MotorController<false, true>::Command::NMotMax: return "NMotMax (MotorController, Command, Front, Right)";
    case MotorController<true, false>::Command::NMotMax: return "NMotMax (MotorController, Command, Back, Left)";
    case MotorController<true, true>::Command::NMotMax: return "NMotMax (MotorController, Command, Back, Right)";
    case MotorController<false, false>::Command::FieldWeakMax: return "FieldWeakMax (MotorController, Command, Front, Left)";
    case MotorController<false, true>::Command::FieldWeakMax: return "FieldWeakMax (MotorController, Command, Front, Right)";
    case MotorController<true, false>::Command::FieldWeakMax: return "FieldWeakMax (MotorController, Command, Back, Left)";
    case MotorController<true, true>::Command::FieldWeakMax: return "FieldWeakMax (MotorController, Command, Back, Right)";
    case MotorController<false, false>::Command::PhaseAdvMax: return "PhaseAdvMax (MotorController, Command, Front, Left)";
    case MotorController<false, true>::Command::PhaseAdvMax: return "PhaseAdvMax (MotorController, Command, Front, Right)";
    case MotorController<true, false>::Command::PhaseAdvMax: return "PhaseAdvMax (MotorController, Command, Back, Left)";
    case MotorController<true, true>::Command::PhaseAdvMax: return "PhaseAdvMax (MotorController, Command, Back, Right)";
    case MotorController<false, false>::Command::BuzzerFreq: return "BuzzerFreq (MotorController, Command, Front, Left)";
    case MotorController<false, true>::Command::BuzzerFreq: return "BuzzerFreq (MotorController, Command, Front, Right)";
    case MotorController<true, false>::Command::BuzzerFreq: return "BuzzerFreq (MotorController, Command, Back, Left)";
    case MotorController<true, true>::Command::BuzzerFreq: return "BuzzerFreq (MotorController, Command, Back, Right)";
    case MotorController<false, false>::Command::BuzzerPattern: return "BuzzerPattern (MotorController, Command, Front, Left)";
    case MotorController<false, true>::Command::BuzzerPattern: return "BuzzerPattern (MotorController, Command, Front, Right)";
    case MotorController<true, false>::Command::BuzzerPattern: return "BuzzerPattern (MotorController, Command, Back, Left)";
    case MotorController<true, true>::Command::BuzzerPattern: return "BuzzerPattern (MotorController, Command, Back, Right)";
    case MotorController<false, false>::Command::Led: return "Led (MotorController, Command, Front, Left)";
    case MotorController<false, true>::Command::Led: return "Led (MotorController, Command, Front, Right)";
    case MotorController<true, false>::Command::Led: return "Led (MotorController, Command, Back, Left)";
    case MotorController<true, true>::Command::Led: return "Led (MotorController, Command, Back, Right)";
    case MotorController<false, false>::Command::Poweroff: return "Poweroff (MotorController, Command, Front, Left)";
    case MotorController<false, true>::Command::Poweroff: return "Poweroff (MotorController, Command, Front, Right)";
    case MotorController<true, false>::Command::Poweroff: return "Poweroff (MotorController, Command, Back, Left)";
    case MotorController<true, true>::Command::Poweroff: return "Poweroff (MotorController, Command, Back, Right)";
    case MotorController<false, false>::Feedback::DcLink: return "DcLink (MotorController, Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::DcLink: return "DcLink (MotorController, Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::DcLink: return "DcLink (MotorController, Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::DcLink: return "DcLink (MotorController, Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::Speed: return "Speed (MotorController, Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::Speed: return "Speed (MotorController, Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::Speed: return "Speed (MotorController, Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::Speed: return "Speed (MotorController, Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::Error: return "Error (MotorController, Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::Error: return "Error (MotorController, Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::Error: return "Error (MotorController, Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::Error: return "Error (MotorController, Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::Angle: return "Angle (MotorController, Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::Angle: return "Angle (MotorController, Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::Angle: return "Angle (MotorController, Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::Angle: return "Angle (MotorController, Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::DcPhaA: return "DcPhaA (MotorController, Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::DcPhaA: return "DcPhaA (MotorController, Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::DcPhaA: return "DcPhaA (MotorController, Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::DcPhaA: return "DcPhaA (MotorController, Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::DcPhaB: return "DcPhaB (MotorController, Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::DcPhaB: return "DcPhaB (MotorController, Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::DcPhaB: return "DcPhaB (MotorController, Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::DcPhaB: return "DcPhaB (MotorController, Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::DcPhaC: return "DcPhaC (MotorController, Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::DcPhaC: return "DcPhaC (MotorController, Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::DcPhaC: return "DcPhaC (MotorController, Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::DcPhaC: return "DcPhaC (MotorController, Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::Chops: return "Chops (MotorController, Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::Chops: return "Chops (MotorController, Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::Chops: return "Chops (MotorController, Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::Chops: return "Chops (MotorController, Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::Hall: return "Hall (MotorController, Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::Hall: return "Hall (MotorController, Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::Hall: return "Hall (MotorController, Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::Hall: return "Hall (MotorController, Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::Voltage: return "Voltage (MotorController, Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::Voltage: return "Voltage (MotorController, Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::Voltage: return "Voltage (MotorController, Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::Voltage: return "Voltage (MotorController, Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::Temp: return "Temp (MotorController, Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::Temp: return "Temp (MotorController, Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::Temp: return "Temp (MotorController, Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::Temp: return "Temp (MotorController, Feedback, Back, Right)";
    case Boardcomputer::Command::RawButtonPressed: return "RawButtonPressed (Boardcomputer, Command)";
    case Boardcomputer::Command::RawButtonReleased: return "RawButtonReleased (Boardcomputer, Command)";
    case Boardcomputer::Command::ButtonPressed: return "ButtonPressed (Boardcomputer, Command)";
    case Boardcomputer::Command::ButtonReleased: return "ButtonReleased (Boardcomputer, Command)";
    case Boardcomputer::Command::RawGas: return "RawGas (Boardcomputer, Command)";
    case Boardcomputer::Command::RawBrems: return "RawBrems (Boardcomputer, Command)";
    case Boardcomputer::Feedback::ButtonLeds: return "ButtonLeds (Boardcomputer, Feedback)";
    }
    return "Unknown";
}

} // namespace can
} // namespace protocol
} // namespace bobbycar
