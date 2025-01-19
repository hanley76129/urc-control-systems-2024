#include "../include/servo40v.hpp"
#include "../hardware_map.hpp"

#include <libhal-util/bit_bang_i2c.hpp> 
#include <libhal-util/serial.hpp>
#include <libhal-util/steady_clock.hpp>
#include <libhal/units.hpp>

using namespace hal::literals;
using namespace std::chrono_literals;

namespace sjsu::drivers {
void application(application_framework &p_framework){
    
    auto& clock = *p_framework.steady_clock;
    auto& terminal = *p_framework.terminal;
    auto& sda = *p_framework.sda;
    auto& scl = *p_framework.scl;

    hal::print(terminal, "hola\n");

    hal::bit_bang_i2c bit_bang_i2c({ .sda = &sda, .scl = &scl }, clock);
    bit_bang_i2c.configure(hal::i2c::settings{ .clock_rate = 100.0_kHz });

    hal::print(terminal, "bit bang intialized\n");
    
    auto servo = Servo40V(bit_bang_i2c, clock, terminal);

    hal::print(terminal, "servo intialized\n");

    servo.setMode(0x0, 45.0); // Position control with setpoint 45 degrees
    hal::print(terminal, "servo setMode\n");
    servo.setProportional(1); //controls immediate response to error, start low
    hal::print(terminal, "servo setProp\n");
    servo.setIntegral(0); //eliminates steady-state error, start low 
    hal::print(terminal, "servo setInt\n");
    servo.setDerivative(0); //reduce overshoot and oscillations, start low
    hal::print(terminal, "servo setDer\n"); 
    servo.setFeedForward(0); //noclue ask shin
    hal::print(terminal, "servo setFeed\n");
    servo.setSetpoint(45.0); // Set position to 45 degrees
    hal::print(terminal, "servo setpoint\n");
    
    hal::print(terminal, "It works\n");
    while (true) {
        hal::print<64>(terminal, "Servo Degree: %f \n", servo.getAngle());
        hal::delay(clock, 1000ms); 
}

}
}