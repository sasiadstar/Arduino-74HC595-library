 #ifndef CHIP_74HC595_H
 #define CHIP_74HC595_H

#include <Arduino.h>

#define SER_Pin_ 27
#define RCLK_Pin_ 26
#define SRCLK_Pin_ 25
#define RESET_Pin_ 33
#define number_of_74hc595s_ 3 
#define numOfRegisterPins_ number_of_74hc595s_ * 8
#define ON 1
#define OFF 0
class CHIP_74HC595 {
public:
 CHIP_74HC595();
	
	void init(uint8_t p1,uint8_t p2,uint8_t p3,uint8_t p4,uint8_t n1);
	void init();
	void switchPin(uint8_t index,byte v);
	
	void clearRegisters();
private:
	void writeRegisters();
	uint8_t SER_Pin;
	uint8_t RCLK_Pin;
	uint8_t SRCLK_Pin;
	uint8_t RESET_Pin;
	uint8_t number_of_74hc595s;
	uint8_t numOfRegisterPins;
	 boolean registers[];
	 // boolean registers[222];
	 // typedef vector <boolean> registers;
};

 #endif