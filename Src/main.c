#include "stm32f4xx.h"
#include "basic_fun.h"
#include "pwm_module.h"

/*-----Module STM32F4DIS variables-----*/

/*-----User variables-----*/
int pulse[] = {10, 50, 100};

/*------Main funtion------*/
int main(void)
{
	LED_PWM_Configuration();
	LED_PWM_Control(pulse);

  while (1)
  {

  }
}
