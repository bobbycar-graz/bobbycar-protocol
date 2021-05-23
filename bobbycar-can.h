#pragma once

#include <cstdint>

namespace bobbycar {
namespace can {
template<bool isBack, bool isRight>
class MotorController
{
private:
    enum { //                         vvv
        DeviceTypeMotorController = 0b00000000000
    };

    enum { //                         ...v
        MotorControllerCommand =    0b00000000000,
        MotorControllerFeedback =   0b00010000000,
    };

    enum { //                         .........v
        MotorControllerFront =      0b00000000000,
        MotorControllerBack =       0b00000000010,
    };

    enum { //                         ..........v
        MotorControllerLeft =       0b00000000000,
        MotorControllerRight =      0b00000000001,
    };

    enum {
        MotorControllerMask =
            DeviceTypeMotorController |
            (isBack ? MotorControllerBack : MotorControllerFront) |
            (isRight ? MotorControllerRight : MotorControllerLeft)
    };

public:
    MotorController() = delete;
    ~MotorController() = delete;

    class Command {
    private:
        enum {
            MotorControllerCommandMask = MotorControllerMask | MotorControllerCommand
        };

    public:
        Command() = delete;
        ~Command() = delete;

        enum { //             ....vvvvv
            Enable =        0b00000000000 | MotorControllerCommandMask,
            InpTgt =        0b00000000100 | MotorControllerCommandMask,
            CtrlTyp =       0b00000001000 | MotorControllerCommandMask,
            CtrlMod =       0b00000001100 | MotorControllerCommandMask,
            IMotMax =       0b00000010000 | MotorControllerCommandMask,
            IDcMax =        0b00000010100 | MotorControllerCommandMask,
            NMotMax =       0b00000011000 | MotorControllerCommandMask,
            FieldWeakMax =  0b00000011100 | MotorControllerCommandMask,
            PhaseAdvMax =   0b00000100000 | MotorControllerCommandMask,
            CruiseCtrlEna = 0b00000100100 | MotorControllerCommandMask,
            CruiseMotTgt =  0b00000101000 | MotorControllerCommandMask,
            BuzzerFreq =    0b00000101100 | MotorControllerCommandMask,
            BuzzerPattern = 0b00000110000 | MotorControllerCommandMask,
            Led =           0b00000110100 | MotorControllerCommandMask,
            Poweroff =      0b00000111000 | MotorControllerCommandMask
        };
    };

    class Feedback {
    private:
        enum {
            MotorControllerFeedbackMask = MotorControllerMask | MotorControllerFeedback
        };

    public:
        Feedback() = delete;
        ~Feedback() = delete;

        enum { //          ....vvvvv
            DcLink =     0b00000000000 | MotorControllerFeedbackMask,
            Speed =      0b00000000100 | MotorControllerFeedbackMask,
            Error =      0b00000001000 | MotorControllerFeedbackMask,
            Angle =      0b00000001100 | MotorControllerFeedbackMask,
            DcPhaA =     0b00000010000 | MotorControllerFeedbackMask,
            DcPhaB =     0b00000010100 | MotorControllerFeedbackMask,
            DcPhaC =     0b00000011000 | MotorControllerFeedbackMask,
            Chops =      0b00000011100 | MotorControllerFeedbackMask,
            Hall =       0b00000100000 | MotorControllerFeedbackMask,
            Voltage =    0b00000100100 | MotorControllerFeedbackMask,
            Temp =       0b00000101000 | MotorControllerFeedbackMask
        };
    };
};

inline const char *bobbycarCanIdDesc(uint16_t id)
{
    switch (id)
    {
    case MotorController<false, false>::Command::Enable: return "Enable (Command, Front, Left)";
    case MotorController<false, true>::Command::Enable: return "Enable (Command, Front, Right)";
    case MotorController<true, false>::Command::Enable: return "Enable (Command, Back, Left)";
    case MotorController<true, true>::Command::Enable: return "Enable (Command, Back, Right)";
    case MotorController<false, false>::Command::InpTgt: return "InpTgt (Command, Front, Left)";
    case MotorController<false, true>::Command::InpTgt: return "InpTgt (Command, Front, Right)";
    case MotorController<true, false>::Command::InpTgt: return "InpTgt (Command, Back, Left)";
    case MotorController<true, true>::Command::InpTgt: return "InpTgt (Command, Back, Right)";
    case MotorController<false, false>::Command::CtrlTyp: return "CtrlTyp (Command, Front, Left)";
    case MotorController<false, true>::Command::CtrlTyp: return "CtrlTyp (Command, Front, Right)";
    case MotorController<true, false>::Command::CtrlTyp: return "CtrlTyp (Command, Back, Left)";
    case MotorController<true, true>::Command::CtrlTyp: return "CtrlTyp (Command, Back, Right)";
    case MotorController<false, false>::Command::CtrlMod: return "CtrlMod (Command, Front, Left)";
    case MotorController<false, true>::Command::CtrlMod: return "CtrlMod (Command, Front, Right)";
    case MotorController<true, false>::Command::CtrlMod: return "CtrlMod (Command, Back, Left)";
    case MotorController<true, true>::Command::CtrlMod: return "CtrlMod (Command, Back, Right)";
    case MotorController<false, false>::Command::IMotMax: return "IMotMax (Command, Front, Left)";
    case MotorController<false, true>::Command::IMotMax: return "IMotMax (Command, Front, Right)";
    case MotorController<true, false>::Command::IMotMax: return "IMotMax (Command, Back, Left)";
    case MotorController<true, true>::Command::IMotMax: return "IMotMax (Command, Back, Right)";
    case MotorController<false, false>::Command::IDcMax: return "IDcMax (Command, Front, Left)";
    case MotorController<false, true>::Command::IDcMax: return "IDcMax (Command, Front, Right)";
    case MotorController<true, false>::Command::IDcMax: return "IDcMax (Command, Back, Left)";
    case MotorController<true, true>::Command::IDcMax: return "IDcMax (Command, Back, Right)";
    case MotorController<false, false>::Command::NMotMax: return "NMotMax (Command, Front, Left)";
    case MotorController<false, true>::Command::NMotMax: return "NMotMax (Command, Front, Right)";
    case MotorController<true, false>::Command::NMotMax: return "NMotMax (Command, Back, Left)";
    case MotorController<true, true>::Command::NMotMax: return "NMotMax (Command, Back, Right)";
    case MotorController<false, false>::Command::FieldWeakMax: return "FieldWeakMax (Command, Front, Left)";
    case MotorController<false, true>::Command::FieldWeakMax: return "FieldWeakMax (Command, Front, Right)";
    case MotorController<true, false>::Command::FieldWeakMax: return "FieldWeakMax (Command, Back, Left)";
    case MotorController<true, true>::Command::FieldWeakMax: return "FieldWeakMax (Command, Back, Right)";
    case MotorController<false, false>::Command::PhaseAdvMax: return "PhaseAdvMax (Command, Front, Left)";
    case MotorController<false, true>::Command::PhaseAdvMax: return "PhaseAdvMax (Command, Front, Right)";
    case MotorController<true, false>::Command::PhaseAdvMax: return "PhaseAdvMax (Command, Back, Left)";
    case MotorController<true, true>::Command::PhaseAdvMax: return "PhaseAdvMax (Command, Back, Right)";
    case MotorController<false, false>::Command::BuzzerFreq: return "BuzzerFreq (Command, Front, Left)";
    case MotorController<false, true>::Command::BuzzerFreq: return "BuzzerFreq (Command, Front, Right)";
    case MotorController<true, false>::Command::BuzzerFreq: return "BuzzerFreq (Command, Back, Left)";
    case MotorController<true, true>::Command::BuzzerFreq: return "BuzzerFreq (Command, Back, Right)";
    case MotorController<false, false>::Command::BuzzerPattern: return "BuzzerPattern (Command, Front, Left)";
    case MotorController<false, true>::Command::BuzzerPattern: return "BuzzerPattern (Command, Front, Right)";
    case MotorController<true, false>::Command::BuzzerPattern: return "BuzzerPattern (Command, Back, Left)";
    case MotorController<true, true>::Command::BuzzerPattern: return "BuzzerPattern (Command, Back, Right)";
    case MotorController<false, false>::Command::Led: return "Led (Command, Front, Left)";
    case MotorController<false, true>::Command::Led: return "Led (Command, Front, Right)";
    case MotorController<true, false>::Command::Led: return "Led (Command, Back, Left)";
    case MotorController<true, true>::Command::Led: return "Led (Command, Back, Right)";
    case MotorController<false, false>::Command::Poweroff: return "Poweroff (Command, Front, Left)";
    case MotorController<false, true>::Command::Poweroff: return "Poweroff (Command, Front, Right)";
    case MotorController<true, false>::Command::Poweroff: return "Poweroff (Command, Back, Left)";
    case MotorController<true, true>::Command::Poweroff: return "Poweroff (Command, Back, Right)";
    case MotorController<false, false>::Feedback::DcLink: return "DcLink (Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::DcLink: return "DcLink (Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::DcLink: return "DcLink (Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::DcLink: return "DcLink (Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::Speed: return "Speed (Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::Speed: return "Speed (Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::Speed: return "Speed (Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::Speed: return "Speed (Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::Error: return "Error (Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::Error: return "Error (Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::Error: return "Error (Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::Error: return "Error (Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::Angle: return "Angle (Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::Angle: return "Angle (Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::Angle: return "Angle (Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::Angle: return "Angle (Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::DcPhaA: return "DcPhaA (Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::DcPhaA: return "DcPhaA (Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::DcPhaA: return "DcPhaA (Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::DcPhaA: return "DcPhaA (Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::DcPhaB: return "DcPhaB (Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::DcPhaB: return "DcPhaB (Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::DcPhaB: return "DcPhaB (Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::DcPhaB: return "DcPhaB (Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::DcPhaC: return "DcPhaC (Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::DcPhaC: return "DcPhaC (Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::DcPhaC: return "DcPhaC (Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::DcPhaC: return "DcPhaC (Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::Chops: return "Chops (Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::Chops: return "Chops (Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::Chops: return "Chops (Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::Chops: return "Chops (Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::Hall: return "Hall (Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::Hall: return "Hall (Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::Hall: return "Hall (Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::Hall: return "Hall (Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::Voltage: return "Voltage (Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::Voltage: return "Voltage (Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::Voltage: return "Voltage (Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::Voltage: return "Voltage (Feedback, Back, Right)";
    case MotorController<false, false>::Feedback::Temp: return "Temp (Feedback, Front, Left)";
    case MotorController<false, true>::Feedback::Temp: return "Temp (Feedback, Front, Right)";
    case MotorController<true, false>::Feedback::Temp: return "Temp (Feedback, Back, Left)";
    case MotorController<true, true>::Feedback::Temp: return "Temp (Feedback, Back, Right)";
    }
    return "Unknown";
}
}
}
