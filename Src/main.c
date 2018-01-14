#include "stm32f4xx.h"
#include "math.h"
#include "float.h"

#include "basic_fun.h"
#include "pwm_module.h"
#include "adc_module.h"
#include "mpu6050_hal.h"
#include "hmc5883L_hal.h"


void imu(float* acc_in, float* gyro_in, float dt, float* out);
void Delay(uint32_t nCount);

/*-----Module STM32F4DIS variables-----*/

/*-----User variables-----*/
int pulse[] = {100, 100, 100};
extern uint16_t ADCValue;

int16_t MPU6050data[7];
int16_t HMC5883Ldata[3];
float temperature;
float acc[3];
float gyro[3];
float angle[3];

float test;
int16_t test2 = 1234;

/*------Main funtion------*/
int main(void)
{
	SystemInit();
	LED_PWM_Configuration();
	ADC_Config();
	
	LED_PWM_Control(pulse);	

	MPU6050_I2C_Configuration();
	MPU6050_Initialize();
//	HMC5883L_Initialize();


  while (1)
  {
		
		
		
		
		
		
		
		
		
		
		
//		MPU6050_GetRawAccelTempGyro(MPU6050data);
//		//HMC5883L_GetHeading(HMC5883Ldata);
//		
//		acc[0] = (float)(MPU6050data[0])/(float)(16384.0);
//		acc[1] = (float)(MPU6050data[1])/(float)(16384.0);
//		acc[2] = (float)(MPU6050data[2])/(float)(16384.0);		

//		temperature = (float)((float)MPU6050data[3]/(float)340.0 + (float)36.53);
//		gyro[0] = (float)(MPU6050data[4])/(float)(16.4);
//		gyro[1] = (float)(MPU6050data[5])/(float)(16.4);
//		gyro[2] = (float)(MPU6050data[6])/(float)(16.4);
//				
//		imu(acc, gyro, 0.1f, angle);
		
  }
}
