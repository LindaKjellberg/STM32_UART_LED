#include "LED.h" // Gets the header file containing the LED functions during the compilation pre-process

/* Constructor for the LED lights containing the possible colors and states the LED:s can be in, 
  from the Led.h header file */
Led::Led(LedColor_Type _color, LedState_Type _state)
{

  this->color = _color;
  this->state = _state;

  // Enable the clock for the LED port (GPIOB)
  RCC->AHB1ENR |= LED_PORT_CLOCK; // 

  // Configure the status of the LED pins by color
  switch(_color){ // Switches between following cases:

    case RED: // 
      LED_PORT->MODER |= LED_RED_MODE_BIT; // In the mode register activate the port status for the LED configuration to output mode
      if(this->state == ON){
        // Turn on LED
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        // Turn off LED
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;

      case YELLOW: // Set port status for the LED configuration to output mode
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      if(this->state == ON){
        // Turn on LED
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        // Turn off LED
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE: // Set port status for the LED configuration to output mode
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      if(this->state == ON){
        // Turn on LED
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        // Turn off LED
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN: // Set port status for the LED configuration to output mode
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      if(this->state == ON){
        // Turn on LED
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        // Turn off LED
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;

  }


}

void Led::setState(LedState_Type _state){

  // Set status for LED
  this->state = _state;

  // Check color of LED to ensure that the correct LED is being manipulated
  switch(this->color){

      // In case of RED LED:
    case RED:
      // Set pin to output mode
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      // If desired status is ON
      if(this->state == ON){
        // Define pin output to active
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        // Else define pin output to inactive
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;

      // In case of YELLOW LED:
      case YELLOW:
      // Set pin to output mode
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      // If desired status is ON
      if(this->state == ON){
        // Define pin output to active
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        // Else define pin output to inactive
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      // In case of BLUE LED:
      case BLUE:
      // Set pin to output mode
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      // If desired status is ON
      if(this->state == ON){
        // Define pin output to active
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        // Else define pin output to inactive
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      // In case of GREEN LED:
      case GREEN:
      // Set pin to output mode
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      // If desired status is ON
      if(this->state == ON){
        // Define pin output to active
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        // Else define pin output to inactive
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;
  }

}

LedState_Type Led::getState(void)const{

  // Controls the color of the LED being called and then prints the status
  switch(this->color){

    case RED:
      break;

    case YELLOW:
      break;

    case BLUE:
      break;

    case GREEN:
      break;
  }
             // Returnes the LED lights status of chosen color
             return this->state;
}
