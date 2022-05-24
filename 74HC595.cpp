/*
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software< /span>
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* Created JB Apps 2022
  */


#include "74HC595.h"
 

 CHIP_74HC595::CHIP_74HC595(){
//public boolean registers[24] ;	 
  SER_Pin= SER_Pin_;
	   RCLK_Pin= RCLK_Pin_;
	  SRCLK_Pin= SRCLK_Pin_;
	   RESET_Pin= RESET_Pin_;
	   number_of_74hc595s= number_of_74hc595s_;
	   numOfRegisterPins= number_of_74hc595s_ * 8;	 
	 
	 
 }
 
// void CHIP_74HC595::init(){
	   // SER_Pin= SER_Pin_;
	   // RCLK_Pin= RCLK_Pin_;
	  // SRCLK_Pin= SRCLK_Pin_;
	   // RESET_Pin= RESET_Pin_;
	   // number_of_74hc595s= number_of_74hc595s_;
	   // numOfRegisterPins= number_of_74hc595s_ * 8;
	 // registers[numOfRegisterPins] ;
 
	// pinMode(SER_Pin, OUTPUT);
	// pinMode(RCLK_Pin, OUTPUT);
	// pinMode(SRCLK_Pin, OUTPUT);
	// pinMode(RESET_Pin, OUTPUT);
	// digitalWrite(RESET_Pin, HIGH);
 
  // clearRegisters();
 
 
// }
void CHIP_74HC595::init(uint8_t p1,uint8_t p2,uint8_t p3,uint8_t p4,uint8_t n1){
 SER_Pin = p1;
 RCLK_Pin = p2;
 SRCLK_Pin = p3;
 RESET_Pin = p4;
 number_of_74hc595s = n1;
numOfRegisterPins = number_of_74hc595s * 8	;
registers[numOfRegisterPins] ;	
	pinMode(SER_Pin, OUTPUT);
	pinMode(RCLK_Pin, OUTPUT);
	pinMode(SRCLK_Pin, OUTPUT);
	pinMode(RESET_Pin, OUTPUT);
	digitalWrite(RESET_Pin, HIGH);
  clearRegisters();
 	
}
 
 void CHIP_74HC595::clearRegisters(){
for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = LOW;
  }	 
	 writeRegisters();
 } 
 void CHIP_74HC595::writeRegisters(){
	  digitalWrite(RCLK_Pin, LOW);

  for(int i = numOfRegisterPins - 1; i >=  0; i--){
    digitalWrite(SRCLK_Pin, LOW);

    int val = registers[i];

    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);

  }
  digitalWrite(RCLK_Pin, HIGH); 
	 
	// Serial.println(SER_Pin); Serial.println(SRCLK_Pin); Serial.println(RCLK_Pin); 
 }
 void CHIP_74HC595::switchPin(uint8_t index,byte v){
	registers[index] = v; 
	  writeRegisters();
	// Serial.println("xxx");
 }
 
