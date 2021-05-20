#pragma once

#include <cstdint>

enum { //                         vv
    DeviceTypeMotorController = 0b00000000000
};

enum { //                         ..vv
    MotorControllerRec =        0b00000000000,
    MotorControllerSend =       0b00010000000,
};

enum { //                         ....vvvvv
    MotorControllerDcLink =     0b00000000000,
    MotorControllerSpeed =      0b00000000100,
    MotorControllerError =      0b00000001000,
    MotorControllerAngle =      0b00000001100,
    MotorControllerDcPhaA =     0b00000010000,
    MotorControllerDcPhaB =     0b00000010100,
    MotorControllerDcPhaC =     0b00000011000,
    MotorControllerChops =      0b00000011100,
    MotorControllerHall =       0b00000100000,
    MotorControllerVoltage =    0b00000100100,
    MotorControllerTemp =       0b00000101000
};

enum { //                         ....vvvvv
    MotorControllerEnable =     0b00000000000,
    MotorControllerInpTgt =     0b00000000100,
    MotorControllerCtrlTyp =    0b00000001000,
    MotorControllerCtrlMod =    0b00000001100,
    MotorControllerIMotMax =    0b00000010000,
    MotorControllerIDcMax =     0b00000010100,
    MotorControllerNMotMax =    0b00000011000,
    MotorControllerFieldWeakMax=0b00000011100,
    MotorControllerPhaseAdvMax =0b00000100000,
    MotorControllerBuzzerFreq = 0b00000100100,
   MotorControllerBuzzerPattern=0b00000101000,
    MotorControllerLed =        0b00000101100,
    MotorControllerPoweroff =   0b00000110000
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
    MotorControllerFrontLeftDcLink = DeviceTypeMotorController | MotorControllerSend | MotorControllerDcLink | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightDcLink = DeviceTypeMotorController | MotorControllerSend | MotorControllerDcLink | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftDcLink = DeviceTypeMotorController | MotorControllerSend | MotorControllerDcLink | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightDcLink = DeviceTypeMotorController | MotorControllerSend | MotorControllerDcLink | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftSpeed = DeviceTypeMotorController | MotorControllerSend | MotorControllerSpeed | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightSpeed = DeviceTypeMotorController | MotorControllerSend | MotorControllerSpeed | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftSpeed = DeviceTypeMotorController | MotorControllerSend | MotorControllerSpeed | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightSpeed = DeviceTypeMotorController | MotorControllerSend | MotorControllerSpeed | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftError = DeviceTypeMotorController | MotorControllerSend | MotorControllerError | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightError = DeviceTypeMotorController | MotorControllerSend | MotorControllerError | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftError = DeviceTypeMotorController | MotorControllerSend | MotorControllerError | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightError = DeviceTypeMotorController | MotorControllerSend | MotorControllerError | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftAngle = DeviceTypeMotorController | MotorControllerSend | MotorControllerAngle | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightAngle = DeviceTypeMotorController | MotorControllerSend | MotorControllerAngle | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftAngle = DeviceTypeMotorController | MotorControllerSend | MotorControllerAngle | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightAngle = DeviceTypeMotorController | MotorControllerSend | MotorControllerAngle | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftDcPhaA = DeviceTypeMotorController | MotorControllerSend | MotorControllerDcPhaA | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightDcPhaA = DeviceTypeMotorController | MotorControllerSend | MotorControllerDcPhaA | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftDcPhaA = DeviceTypeMotorController | MotorControllerSend | MotorControllerDcPhaA | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightDcPhaA = DeviceTypeMotorController | MotorControllerSend | MotorControllerDcPhaA | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftDcPhaB = DeviceTypeMotorController | MotorControllerSend | MotorControllerDcPhaB | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightDcPhaB = DeviceTypeMotorController | MotorControllerSend | MotorControllerDcPhaB | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftDcPhaB = DeviceTypeMotorController | MotorControllerSend | MotorControllerDcPhaB | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightDcPhaB = DeviceTypeMotorController | MotorControllerSend | MotorControllerDcPhaB | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftDcPhaC = DeviceTypeMotorController | MotorControllerSend | MotorControllerDcPhaC | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightDcPhaC = DeviceTypeMotorController | MotorControllerSend | MotorControllerDcPhaC | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftDcPhaC = DeviceTypeMotorController | MotorControllerSend | MotorControllerDcPhaC | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightDcPhaC = DeviceTypeMotorController | MotorControllerSend | MotorControllerDcPhaC | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftChops = DeviceTypeMotorController | MotorControllerSend | MotorControllerChops | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightChops = DeviceTypeMotorController | MotorControllerSend | MotorControllerChops | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftChops = DeviceTypeMotorController | MotorControllerSend | MotorControllerChops | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightChops = DeviceTypeMotorController | MotorControllerSend | MotorControllerChops | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftHall = DeviceTypeMotorController | MotorControllerSend | MotorControllerHall | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightHall = DeviceTypeMotorController | MotorControllerSend | MotorControllerHall | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftHall = DeviceTypeMotorController | MotorControllerSend | MotorControllerHall | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightHall = DeviceTypeMotorController | MotorControllerSend | MotorControllerHall | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftVoltage = DeviceTypeMotorController | MotorControllerSend | MotorControllerVoltage | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightVoltage = DeviceTypeMotorController | MotorControllerSend | MotorControllerVoltage | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftVoltage = DeviceTypeMotorController | MotorControllerSend | MotorControllerVoltage | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightVoltage = DeviceTypeMotorController | MotorControllerSend | MotorControllerVoltage | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftTemp = DeviceTypeMotorController | MotorControllerSend | MotorControllerTemp | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightTemp = DeviceTypeMotorController | MotorControllerSend | MotorControllerTemp | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftTemp = DeviceTypeMotorController | MotorControllerSend | MotorControllerTemp | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightTemp = DeviceTypeMotorController | MotorControllerSend | MotorControllerTemp | MotorControllerBack | MotorControllerRight,
};

enum {
    MotorControllerFrontLeftEnable = DeviceTypeMotorController | MotorControllerRec | MotorControllerEnable | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightEnable = DeviceTypeMotorController | MotorControllerRec | MotorControllerEnable | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftEnable = DeviceTypeMotorController | MotorControllerRec | MotorControllerEnable | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightEnable = DeviceTypeMotorController | MotorControllerRec | MotorControllerEnable | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftInpTgt = DeviceTypeMotorController | MotorControllerRec | MotorControllerInpTgt | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightInpTgt = DeviceTypeMotorController | MotorControllerRec | MotorControllerInpTgt | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftInpTgt = DeviceTypeMotorController | MotorControllerRec | MotorControllerInpTgt | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightInpTgt = DeviceTypeMotorController | MotorControllerRec | MotorControllerInpTgt | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftCtrlTyp = DeviceTypeMotorController | MotorControllerRec | MotorControllerCtrlTyp | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightCtrlTyp = DeviceTypeMotorController | MotorControllerRec | MotorControllerCtrlTyp | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftCtrlTyp = DeviceTypeMotorController | MotorControllerRec | MotorControllerCtrlTyp | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightCtrlTyp = DeviceTypeMotorController | MotorControllerRec | MotorControllerCtrlTyp | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftCtrlMod = DeviceTypeMotorController | MotorControllerRec | MotorControllerCtrlMod | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightCtrlMod = DeviceTypeMotorController | MotorControllerRec | MotorControllerCtrlMod | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftCtrlMod = DeviceTypeMotorController | MotorControllerRec | MotorControllerCtrlMod | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightCtrlMod = DeviceTypeMotorController | MotorControllerRec | MotorControllerCtrlMod | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftIMotMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerIMotMax | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightIMotMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerIMotMax | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftIMotMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerIMotMax | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightIMotMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerIMotMax | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftIDcMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerIDcMax | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightIDcMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerIDcMax | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftIDcMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerIDcMax | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightIDcMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerIDcMax | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftNMotMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerNMotMax | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightNMotMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerNMotMax | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftNMotMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerNMotMax | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightNMotMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerNMotMax | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftFieldWeakMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerFieldWeakMax | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightFieldWeakMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerFieldWeakMax | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftFieldWeakMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerFieldWeakMax | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightFieldWeakMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerFieldWeakMax | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftPhaseAdvMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerPhaseAdvMax | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightPhaseAdvMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerPhaseAdvMax | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftPhaseAdvMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerPhaseAdvMax | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightPhaseAdvMax = DeviceTypeMotorController | MotorControllerRec | MotorControllerPhaseAdvMax | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftBuzzerFreq = DeviceTypeMotorController | MotorControllerRec | MotorControllerBuzzerFreq | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightBuzzerFreq = DeviceTypeMotorController | MotorControllerRec | MotorControllerBuzzerFreq | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftBuzzerFreq = DeviceTypeMotorController | MotorControllerRec | MotorControllerBuzzerFreq | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightBuzzerFreq = DeviceTypeMotorController | MotorControllerRec | MotorControllerBuzzerFreq | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftBuzzerPattern = DeviceTypeMotorController | MotorControllerRec | MotorControllerBuzzerPattern | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightBuzzerPattern = DeviceTypeMotorController | MotorControllerRec | MotorControllerBuzzerPattern | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftBuzzerPattern = DeviceTypeMotorController | MotorControllerRec | MotorControllerBuzzerPattern | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightBuzzerPattern = DeviceTypeMotorController | MotorControllerRec | MotorControllerBuzzerPattern | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftLed = DeviceTypeMotorController | MotorControllerRec | MotorControllerLed | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightLed = DeviceTypeMotorController | MotorControllerRec | MotorControllerLed | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftLed = DeviceTypeMotorController | MotorControllerRec | MotorControllerLed | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightLed = DeviceTypeMotorController | MotorControllerRec | MotorControllerLed | MotorControllerBack | MotorControllerRight,

    MotorControllerFrontLeftPoweroff = DeviceTypeMotorController | MotorControllerRec | MotorControllerPoweroff | MotorControllerFront | MotorControllerLeft,
    MotorControllerFrontRightPoweroff = DeviceTypeMotorController | MotorControllerRec | MotorControllerPoweroff | MotorControllerFront | MotorControllerRight,
    MotorControllerBackLeftPoweroff = DeviceTypeMotorController | MotorControllerRec | MotorControllerPoweroff | MotorControllerBack | MotorControllerLeft,
    MotorControllerBackRightPoweroff = DeviceTypeMotorController | MotorControllerRec | MotorControllerPoweroff | MotorControllerBack | MotorControllerRight,
};

inline const char *bobbycarCanIdDesc(uint16_t id)
{
    switch (id)
    {
    case MotorControllerFrontLeftEnable: return "MotorControllerFrontLeftEnable";
    case MotorControllerFrontRightEnable: return "MotorControllerFrontRightEnable";
    case MotorControllerBackLeftEnable: return "MotorControllerBackLeftEnable";
    case MotorControllerBackRightEnable: return "MotorControllerBackRightEnable";
    case MotorControllerFrontLeftInpTgt: return "MotorControllerFrontLeftInpTgt";
    case MotorControllerFrontRightInpTgt: return "MotorControllerFrontRightInpTgt";
    case MotorControllerBackLeftInpTgt: return "MotorControllerBackLeftInpTgt";
    case MotorControllerBackRightInpTgt: return "MotorControllerBackRightInpTgt";
    case MotorControllerFrontLeftCtrlTyp: return "MotorControllerFrontLeftCtrlTyp";
    case MotorControllerFrontRightCtrlTyp: return "MotorControllerFrontRightCtrlTyp";
    case MotorControllerBackLeftCtrlTyp: return "MotorControllerBackLeftCtrlTyp";
    case MotorControllerBackRightCtrlTyp: return "MotorControllerBackRightCtrlTyp";
    case MotorControllerFrontLeftCtrlMod: return "MotorControllerFrontLeftCtrlMod";
    case MotorControllerFrontRightCtrlMod: return "MotorControllerFrontRightCtrlMod";
    case MotorControllerBackLeftCtrlMod: return "MotorControllerBackLeftCtrlMod";
    case MotorControllerBackRightCtrlMod: return "MotorControllerBackRightCtrlMod";
    case MotorControllerFrontLeftIMotMax: return "MotorControllerFrontLeftIMotMax";
    case MotorControllerFrontRightIMotMax: return "MotorControllerFrontRightIMotMax";
    case MotorControllerBackLeftIMotMax: return "MotorControllerBackLeftIMotMax";
    case MotorControllerBackRightIMotMax: return "MotorControllerBackRightIMotMax";
    case MotorControllerFrontLeftIDcMax: return "MotorControllerFrontLeftIDcMax";
    case MotorControllerFrontRightIDcMax: return "MotorControllerFrontRightIDcMax";
    case MotorControllerBackLeftIDcMax: return "MotorControllerBackLeftIDcMax";
    case MotorControllerBackRightIDcMax: return "MotorControllerBackRightIDcMax";
    case MotorControllerFrontLeftNMotMax: return "MotorControllerFrontLeftNMotMax";
    case MotorControllerFrontRightNMotMax: return "MotorControllerFrontRightNMotMax";
    case MotorControllerBackLeftNMotMax: return "MotorControllerBackLeftNMotMax";
    case MotorControllerBackRightNMotMax: return "MotorControllerBackRightNMotMax";
    case MotorControllerFrontLeftFieldWeakMax: return "MotorControllerFrontLeftFieldWeakMax";
    case MotorControllerFrontRightFieldWeakMax: return "MotorControllerFrontRightFieldWeakMax";
    case MotorControllerBackLeftFieldWeakMax: return "MotorControllerBackLeftFieldWeakMax";
    case MotorControllerBackRightFieldWeakMax: return "MotorControllerBackRightFieldWeakMax";
    case MotorControllerFrontLeftPhaseAdvMax: return "MotorControllerFrontLeftPhaseAdvMax";
    case MotorControllerFrontRightPhaseAdvMax: return "MotorControllerFrontRightPhaseAdvMax";
    case MotorControllerBackLeftPhaseAdvMax: return "MotorControllerBackLeftPhaseAdvMax";
    case MotorControllerBackRightPhaseAdvMax: return "MotorControllerBackRightPhaseAdvMax";
    case MotorControllerFrontLeftBuzzerFreq: return "MotorControllerFrontLeftBuzzerFreq";
    case MotorControllerFrontRightBuzzerFreq: return "MotorControllerFrontRightBuzzerFreq";
    case MotorControllerBackLeftBuzzerFreq: return "MotorControllerBackLeftBuzzerFreq";
    case MotorControllerBackRightBuzzerFreq: return "MotorControllerBackRightBuzzerFreq";
    case MotorControllerFrontLeftBuzzerPattern: return "MotorControllerFrontLeftBuzzerPattern";
    case MotorControllerFrontRightBuzzerPattern: return "MotorControllerFrontRightBuzzerPattern";
    case MotorControllerBackLeftBuzzerPattern: return "MotorControllerBackLeftBuzzerPattern";
    case MotorControllerBackRightBuzzerPattern: return "MotorControllerBackRightBuzzerPattern";
    case MotorControllerFrontLeftLed: return "MotorControllerFrontLeftLed";
    case MotorControllerFrontRightLed: return "MotorControllerFrontRightLed";
    case MotorControllerBackLeftLed: return "MotorControllerBackLeftLed";
    case MotorControllerBackRightLed: return "MotorControllerBackRightLed";
    case MotorControllerFrontLeftPoweroff: return "MotorControllerFrontLeftPoweroff";
    case MotorControllerFrontRightPoweroff: return "MotorControllerFrontRightPoweroff";
    case MotorControllerBackLeftPoweroff: return "MotorControllerBackLeftPoweroff";
    case MotorControllerBackRightPoweroff: return "MotorControllerBackRightPoweroff";
    case MotorControllerFrontLeftDcLink: return "MotorControllerFrontLeftDcLink";
    case MotorControllerFrontRightDcLink: return "MotorControllerFrontRightDcLink";
    case MotorControllerBackLeftDcLink: return "MotorControllerBackLeftDcLink";
    case MotorControllerBackRightDcLink: return "MotorControllerBackRightDcLink";
    case MotorControllerFrontLeftSpeed: return "MotorControllerFrontLeftSpeed";
    case MotorControllerFrontRightSpeed: return "MotorControllerFrontRightSpeed";
    case MotorControllerBackLeftSpeed: return "MotorControllerBackLeftSpeed";
    case MotorControllerBackRightSpeed: return "MotorControllerBackRightSpeed";
    case MotorControllerFrontLeftError: return "MotorControllerFrontLeftError";
    case MotorControllerFrontRightError: return "MotorControllerFrontRightError";
    case MotorControllerBackLeftError: return "MotorControllerBackLeftError";
    case MotorControllerBackRightError: return "MotorControllerBackRightError";
    case MotorControllerFrontLeftAngle: return "MotorControllerFrontLeftAngle";
    case MotorControllerFrontRightAngle: return "MotorControllerFrontRightAngle";
    case MotorControllerBackLeftAngle: return "MotorControllerBackLeftAngle";
    case MotorControllerBackRightAngle: return "MotorControllerBackRightAngle";
    case MotorControllerFrontLeftDcPhaA: return "MotorControllerFrontLeftDcPhaA";
    case MotorControllerFrontRightDcPhaA: return "MotorControllerFrontRightDcPhaA";
    case MotorControllerBackLeftDcPhaA: return "MotorControllerBackLeftDcPhaA";
    case MotorControllerBackRightDcPhaA: return "MotorControllerBackRightDcPhaA";
    case MotorControllerFrontLeftDcPhaB: return "MotorControllerFrontLeftDcPhaB";
    case MotorControllerFrontRightDcPhaB: return "MotorControllerFrontRightDcPhaB";
    case MotorControllerBackLeftDcPhaB: return "MotorControllerBackLeftDcPhaB";
    case MotorControllerBackRightDcPhaB: return "MotorControllerBackRightDcPhaB";
    case MotorControllerFrontLeftDcPhaC: return "MotorControllerFrontLeftDcPhaC";
    case MotorControllerFrontRightDcPhaC: return "MotorControllerFrontRightDcPhaC";
    case MotorControllerBackLeftDcPhaC: return "MotorControllerBackLeftDcPhaC";
    case MotorControllerBackRightDcPhaC: return "MotorControllerBackRightDcPhaC";
    case MotorControllerFrontLeftChops: return "MotorControllerFrontLeftChops";
    case MotorControllerFrontRightChops: return "MotorControllerFrontRightChops";
    case MotorControllerBackLeftChops: return "MotorControllerBackLeftChops";
    case MotorControllerBackRightChops: return "MotorControllerBackRightChops";
    case MotorControllerFrontLeftHall: return "MotorControllerFrontLeftHall";
    case MotorControllerFrontRightHall: return "MotorControllerFrontRightHall";
    case MotorControllerBackLeftHall: return "MotorControllerBackLeftHall";
    case MotorControllerBackRightHall: return "MotorControllerBackRightHall";
    case MotorControllerFrontLeftVoltage: return "MotorControllerFrontLeftVoltage";
    case MotorControllerFrontRightVoltage: return "MotorControllerFrontRightVoltage";
    case MotorControllerBackLeftVoltage: return "MotorControllerBackLeftVoltage";
    case MotorControllerBackRightVoltage: return "MotorControllerBackRightVoltage";
    case MotorControllerFrontLeftTemp: return "MotorControllerFrontLeftTemp";
    case MotorControllerFrontRightTemp: return "MotorControllerFrontRightTemp";
    case MotorControllerBackLeftTemp: return "MotorControllerBackLeftTemp";
    case MotorControllerBackRightTemp: return "MotorControllerBackRightTemp";
    }
    return "Unknown";
}
