#pragma once

#include <stdint.h>

namespace bobbycar {
namespace protocol {

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

} // namespace protocol
} // namespace bobbycar
