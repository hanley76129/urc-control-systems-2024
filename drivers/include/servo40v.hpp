#pragma once 

#include <libhal-util/i2c.hpp>
#include <libhal-util/serial.hpp>
#include <libhal-util/steady_clock.hpp>

namespace sjsu::drivers{
    class Servo40V{
    private:
        hal::byte deviceAddress = 0xfe; 

        hal::i2c& m_i2c;  
        hal::steady_clock& m_clock;
        hal::serial& m_terminal;

        void writeRegister(char reg, float value);
        float readRegister(char reg);
    public:
        Servo40V(hal::i2c& p_i2c, hal::steady_clock& p_clock, hal::serial& p_terminal);

        //set constants
        void setProportional(float p);
        void setIntegral(float i);
        void setDerivative(float d);
        void setFeedForward(float f);

        //setpoint
        void setSetpoint(float setpoint);

        // mode register
        void setMode(hal::byte mode, float setpoint);

        // Read Functions
        float getAngle();
        float getVelocityChange();
        float getCurrent();
    };
}