#ifndef LED_H // Checks wether the UART header file has been defined 
#define LED_H // Declares the UART header file and the following lines of code to be executed during the pre-process in the compilation

#include <stdint.h> // Include the Standard I/O for C
#include "UART.h"  // Includes the uart header file used in the project
#include "stm32f4xx.h" // Include source code for STM-Hardware and neccessary references

#define LED_PORT GPIOB // Define which GPIO will be in charge of the LED function

#define LED_PORT_CLOCK (1U<<1) // Define the clock signal for the port

// Define all the different pins for the separate LED colors:
#define LED_RED_PIN (1U<<14) // Enable pin 14 for the RED LED
#define LED_GREEN_PIN (1U<<12) // Enable pin 12 for the GREEN LED
#define LED_BLUE_PIN (1U<<15) // Enable pin 15 for the BLUE LED
#define LED_YELLOW_PIN (1U<<13) // Enable pin 13 for the YELLOW LED

// Define the mode bits for each LED color and set them to bit mode 1 to enable:
#define LED_RED_MODE_BIT (1U<<28) // Enable bit mode 1 for the RED LED
#define LED_GREEN_MODE_BIT (1U<<24) // Enable bit mode 1 for the GREEN LED
#define LED_YELLOW_MODE_BIT (1U<<26) // Enable bit mode 1 for the YELLOW LED
#define LED_BLUE_MODE_BIT (1U<<30) // Enable bit mode 1 for the BLUE LED

// Defines the four different LED colors that exists and initialize:
typedef enum {
  RED = 0,    // Only red is initialized to 0, but the rest are automatically initialized in a continuous order (to 1, 2 and 3...)  
  GREEN,
  YELLOW,
  BLUE
}LedColor_Type;

//Defines and sets the possible states the LED can be in
typedef enum {
  OFF = 0,   // When there is no signal the LED is OFF 
  ON = 1     // When there is an signal the LED is ON
}LedState_Type;

// Defines the attributes the LED (color and state):
class Led{

  // Not accessible outside of this class
  private: 
      LedColor_Type color;
      LedState_Type state;

  // Accessible outside of this class
  public:

      Led(LedColor_Type _color,LedState_Type _state);
      void setState(LedState_Type _state);
      LedState_Type getState() const;

};

#endif // End of the header file
