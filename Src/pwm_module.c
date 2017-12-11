#include "pwm_module.h"

/*-----Module STM32F4DIS variables-----*/

/*------GPIO Configuration------
  * @brief  Configure GPIO Pin for LED control on STM32F407 Simple Kit PC6-PC7-PC8.
  * @param  None
  * @retval None
  */
void LED_PWM_Configuration(void)
{
  GPIO_InitTypeDef            GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef     TIM_TimeBaseStructure;
  TIM_OCInitTypeDef           TIM_OCInitStructure;

  /* Enable Timer 4 & GPIOD: TIM3 is connected to APB1 bus*/
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    /* Configure GPIOD pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  /* Configure GPIOD - AF mode pin */
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM3);
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM3);
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM3);

  /* Time base configuration
  timer_tick_frequency = Timer_default_frequency / (prescaller_set + 1)
  Max frequency for timer: prescaller=0:
  For Timer 4: timer_tick_frequency = 84000000 / (0 + 1) = 84000000
  TIM_Period = timer_tick_frequency / PWM_frequency - 1
  For 10Khz PWM_frequency: TIM_Period = 84000000 / 10000 - 1 = 8399 */
  TIM_TimeBaseStructure.TIM_Prescaler = 0;
  TIM_TimeBaseStructure.TIM_Period = 8399;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
  /*  PWM mode 2 = Clear on compare match
    PWM mode 1 = Set on compare match */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
  TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCPolarity_High;
  TIM_OCInitStructure.TIM_Pulse = 0;
    //TIM_OCStructInit(&TIM_OCInitStructure);
  TIM_OC1Init(TIM3, &TIM_OCInitStructure);
  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
  TIM_OC2Init(TIM3, &TIM_OCInitStructure);
  TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
  TIM_OC3Init(TIM3, &TIM_OCInitStructure);
  TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
  TIM_OC4Init(TIM3, &TIM_OCInitStructure);
  TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);

  TIM_ARRPreloadConfig(TIM3, ENABLE);
    /* TIM3 enable counter */
  TIM_Cmd(TIM3, ENABLE);
  TIM_CtrlPWMOutputs(TIM3, ENABLE);
  }

/*------GPIO Configuration------
  * @brief  Test GPIO Pin for LED control on STM32F407 Simple Kit PC6-PC7-PC8.
  * @param  Array of LED Light (0%-->100%) for PC6-PC7-PC8.
  * @retval None
  */
void LED_PWM_Control(int pulse[])
{
  /* pulse_length = ((TIM_Period + 1) * DutyCycle) / 100 - 1 */
	TIM3->CCR1 = ((8399 + 1) * pulse[0]) / 100;  // 25% Duty cycle
  TIM3->CCR2 = ((8399 + 1) * pulse[1]) / 100;  // 50% Duty cycle
  TIM3->CCR3 = ((8399 + 1) * pulse[2]) / 100;  // 75% Duty cycle
}
