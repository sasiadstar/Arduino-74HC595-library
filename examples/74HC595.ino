#include <74HC595.h>
CHIP_74HC595 chip;

//init(SER,RCLK,SRCLK,RESET,number_of_74hc595s) or init() default pins
 
// SER_Pin_ 27
// RCLK_Pin_ 26
// SRCLK_Pin_ 25
// RESET_Pin_ 33
// number_of_74hc595s_ 3 
//switchPin(pin number,ON or OFF);



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
chip.switchPin(5,ON);
delay(1000);
chip.switchPin(5,OFF);
delay(1000);
}