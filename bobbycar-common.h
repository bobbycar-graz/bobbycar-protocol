#pragma once

#include <stdint.h>

enum class ControlType : uint8_t {
    Commutation,
    Sinusoidal,
    FieldOrientedControl
};

enum class ControlMode : uint8_t {
    OpenMode,
    Voltage,
    Speed, // Only with FieldOrientedControl
    Torque // Only with FieldOrientedControl
};
