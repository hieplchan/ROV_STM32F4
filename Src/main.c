#include "stm32f4xx.h"
#include "math.h"
#include "float.h"

#include "basic_fun.h"
#include "pwm_module.h"
#include "mpu6050_module.h"

void imu(float* acc_in, float* gyro_in, float dt, float* out);
void Delay(uint32_t nCount);

/*-----Module STM32F4DIS variables-----*/

/*-----User variables-----*/
int pulse[] = {100, 100, 100};

int16_t MPU6050data[7];
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

	MPU6050_I2C_Configuration();
	MPU6050_Initialize();

  while (1)
  {
		MPU6050_GetRawAccelTempGyro(MPU6050data);

		acc[0] = (float)(MPU6050data[0])/(float)(16384.0);
		acc[1] = (float)(MPU6050data[1])/(float)(16384.0);
		acc[2] = (float)(MPU6050data[2])/(float)(16384.0);		

		temperature = (float)((float)MPU6050data[3]/(float)340.0 + (float)36.53);
		gyro[0] = (float)(MPU6050data[4])/(float)(16.4);
		gyro[1] = (float)(MPU6050data[5])/(float)(16.4);
		gyro[2] = (float)(MPU6050data[6])/(float)(16.4);
		
		LED_PWM_Control(pulse);		

		
//		imu(acc, gyro, 0.1f, angle);
  }
}
