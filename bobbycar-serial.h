#pragma once

#include <stdint.h>

#include "bobbycar-common.h"

namespace bobbycar {
namespace protocol {
namespace serial {

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
    bool cruiseCtrlEna = false;
    int16_t nCruiseMotTgt = 0;
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
        state.phaseAdvMax ^
        uint16_t(state.cruiseCtrlEna) ^
        state.nCruiseMotTgt;
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
    int16_t   dcLink = 0;
    int16_t   dcPhaA = 0;
    int16_t   dcPhaB = 0;
    int16_t   dcPhaC = 0;
    uint16_t  chops = 0;
    bool      hallA = false;
    bool      hallB = false;
    bool      hallC = false;
};

inline uint16_t calculateChecksum(MotorFeedback feedback) {
    return feedback.angle ^ feedback.speed ^
           feedback.error ^ feedback.dcLink ^
           feedback.dcPhaA ^ feedback.dcPhaB ^
           feedback.dcPhaC ^ feedback.chops ^
           feedback.hallA ^ feedback.hallB ^ feedback.hallC;
}

struct Feedback {
    static constexpr uint16_t VALID_HEADER = 0xAAAA;
    static constexpr uint16_t INVALID_HEADER = 0xFFFF;

    uint16_t start;

    MotorFeedback left, right;

    int16_t   batVoltage = 0;
    int16_t   boardTemp = 0;

    int16_t timeoutCntSerial = 0;

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
    //static_assert(offsetof(st, memb) == off, "struct layout wrong");

ASSERT_LAYOUT(Feedback, start, 0);
ASSERT_LAYOUT(Feedback, left, 2);
ASSERT_LAYOUT(Feedback, left.angle, 2);
ASSERT_LAYOUT(Feedback, left.speed, 4);
ASSERT_LAYOUT(Feedback, left.error, 6);
ASSERT_LAYOUT(Feedback, left.dcLink, 8);
ASSERT_LAYOUT(Feedback, left.dcPhaA, 10);
ASSERT_LAYOUT(Feedback, left.dcPhaB, 12);
ASSERT_LAYOUT(Feedback, left.dcPhaC, 14);
ASSERT_LAYOUT(Feedback, left.chops, 16);
ASSERT_LAYOUT(Feedback, left.hallA, 18);
ASSERT_LAYOUT(Feedback, left.hallB, 19);
ASSERT_LAYOUT(Feedback, left.hallC, 20);

ASSERT_LAYOUT(Feedback, right, 22);
ASSERT_LAYOUT(Feedback, right.angle, 22);
ASSERT_LAYOUT(Feedback, right.speed, 24);
ASSERT_LAYOUT(Feedback, right.error, 26);
ASSERT_LAYOUT(Feedback, right.dcLink, 28);
ASSERT_LAYOUT(Feedback, right.dcPhaA, 30);
ASSERT_LAYOUT(Feedback, right.dcPhaB, 32);
ASSERT_LAYOUT(Feedback, right.dcPhaC, 34);
ASSERT_LAYOUT(Feedback, right.chops, 36);
ASSERT_LAYOUT(Feedback, right.hallA, 38);
ASSERT_LAYOUT(Feedback, right.hallB, 39);
ASSERT_LAYOUT(Feedback, right.hallC, 40);

ASSERT_LAYOUT(Feedback, batVoltage, 42);
ASSERT_LAYOUT(Feedback, boardTemp, 44);
ASSERT_LAYOUT(Feedback, timeoutCntSerial, 46);
ASSERT_LAYOUT(Feedback, checksum, 48);

//static_assert(sizeof(Command) == 38, "sizeof(Command) wrong");

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
ASSERT_LAYOUT(Command, left.cruiseCtrlEna, 14);
ASSERT_LAYOUT(Command, left.nCruiseMotTgt, 15);

ASSERT_LAYOUT(Command, right.enable, 18);
ASSERT_LAYOUT(Command, right.pwm, 19);
ASSERT_LAYOUT(Command, right.ctrlTyp, 21);
ASSERT_LAYOUT(Command, right.ctrlMod, 22);
ASSERT_LAYOUT(Command, right.iMotMax, 23);
ASSERT_LAYOUT(Command, right.iDcMax, 24);
ASSERT_LAYOUT(Command, right.nMotMax, 25);
ASSERT_LAYOUT(Command, right.fieldWeakMax, 27);
ASSERT_LAYOUT(Command, right.phaseAdvMax, 28);
ASSERT_LAYOUT(Command, right.cruiseCtrlEna, 29);
ASSERT_LAYOUT(Command, right.nCruiseMotTgt, 31);

ASSERT_LAYOUT(Command, buzzer, 33);
ASSERT_LAYOUT(Command, buzzer.freq, 33);
ASSERT_LAYOUT(Command, buzzer.pattern, 27);

ASSERT_LAYOUT(Command, poweroff, 28);
ASSERT_LAYOUT(Command, led, 29);
ASSERT_LAYOUT(Command, checksum, 30);

} // namespace serial
} // namespace protocol
} // namespace bobbycar
