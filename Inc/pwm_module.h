#include "stm32f4xx.h"

/*------SYSTEM FUNCTION DECLARE------*/

/*------USER VARIABLE DECLARE------*/
//int pulse[] = {10, 50, 100};

/*------USER FUNCTION DECLARE------*/
void LED_PWM_Configuration(void); //Configure GPIO Pin for LED control on STM32F407 Simple Kit PC6-PC7-PC8.
void LED_PWM_Control(int pulse[]); //Test GPIO Pin for LED control on STM32F407 Simple Kit PC6-PC7-PC8.
void ESC_PWM_Configuration(void); //Configure GPIO Pin for ESC control on STM32F407 Simple Kit PD12->PD15, PC6->PC9.
void ESC_PWM_Control(int16_t pulse_esc[]);
