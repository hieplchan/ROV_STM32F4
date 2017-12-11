#include "basic_fun.h"

/*------Delay Funtion------
  * @brief  Delay some time.
  * @param  nCount: time to delay.
  * @retval None
  */
void Delay(uint32_t nCount)
{
  while(nCount--)
  {
  }
}

/*------GPIO_Configuration Funtion------
  * @brief  Config LED of STM32F407 Simple Kit PC6-PC7-PC8.
  * @param  None
  * @retval None
  */
void GPIO_Configuration(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

  /* Configure PB0 PB1 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}

/*------LED_Test Funtion------
  * @brief  Test LED of STM32F407 Simple Kit PC6-PC7-PC8.
  * @param  None
  * @retval None
  */
void LED_Test(void)
{
  GPIO_SetBits(GPIOC, GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8);
  Delay(1000000);
  GPIO_ResetBits(GPIOC, GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8);
  Delay(1000000);
}
