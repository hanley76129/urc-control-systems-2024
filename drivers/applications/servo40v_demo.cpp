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
    // auto& sda = *p_framework.sda;
    // auto& scl = *p_framework.scl;

    // hal::bit_bang_i2c bit_bang_i2c({ .sda = &sda, .scl = &scl }, clock);
    // bit_bang_i2c.configure(hal::i2c::settings{ .clock_rate = 100.0_kHz });
    
//     static hal::stm32f1::output_pin sda_output_pin('B', 7);
//   static hal::stm32f1::output_pin scl_output_pin('B', 6);
//   static hal::bit_bang_i2c bit_bang_i2c(
//     hal::bit_bang_i2c::pins{
//       .sda = &sda_output_pin,
//       .scl = &scl_output_pin,
//     },
//     uptime_clock());
    // auto servo = Servo40V(bit_bang_i2c, clock, terminal);
    // servo.setMode(0x0, 45.0); // Position control with setpoint 45 degrees
    // servo.setProportional(1); //controls immediate response to error, start low
    // servo.setIntegral(0); //eliminates steady-state error, start low 
    // servo.setDerivative(0); //reduce overshoot and oscillations, start low 
    // servo.setFeedForward(0); //noclue ask shin
    // servo.setSetpoint(45.0); // Set position to 45 degrees
    

    while (true) {
        hal::print(terminal, "It works!\n");
        //hal::print<64>(terminal, "Servo Degree: %f", servo.getAngle());
        hal::delay(clock, 1000ms); 
}

}
}