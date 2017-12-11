#include "stm32f4xx.h" 
#include "basic_fun.h"

int main(void)
{ 
	GPIO_Configuration();
  while (1)
  {
		LED_Test();
  }
}
