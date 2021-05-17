#pragma once

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
