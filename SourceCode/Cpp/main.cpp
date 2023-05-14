#include "led.h" // Gets the header file containing the LED functions during the compilation pre-process

//  Create three LED lights
LedState_Type led1_state;
LedState_Type led2_state;
LedState_Type led3_state;

Led led1(RED,ON); // Set first LED to color red and turn it on

int main(void){ // Main function to construct and handle the LED lights
  USART2_Init();  // Initializes the UART protocol 

  Led led2(BLUE,ON); // Set second LED to color blue, set state to turned on

  Led *led3 = new Led(YELLOW,ON); // Set third LED to new led of color yellow, the led is still turned on

  led1_state = led1.getState(); // Changes the led back to red

  led1.setState(OFF); // Turn of red led

  delete led3; // Delete yellow led

  while(1){}  // Infinite loop to repeat the main function

}
