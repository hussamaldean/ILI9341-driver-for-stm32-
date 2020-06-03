#include "stm32f4xx.h"                  // Device header
#include "delay.h"
#include "ILI9341.h"
#include "SPI.h"
#include <stdio.h>
#include <String.h>
#include "MPU9250.h"
#define size 8
float accx,accy,accz,gyrox,gyroy,gyroz,comx,comy,comz,dir;
char strax[size],stray[size],straz[size],strgx[size],strgy[size],strgz[size],strcx[size],strcy[size],strcz[size];
int main(void)
{
SystemCoreClockUpdate();
systick_init();
spi_init();
i2c_init();
ILI9341_Init();
ILI9341_setRotation(1);
ILI9341_Fill(COLOR_RED);
ILI9341_DrawString(0,1,"MPU9250 interface",COLOR_PURPLE,COLOR_RED,2);
ILI9341_DrawString(0,2,"with ILI9341",COLOR_PURPLE,COLOR_RED,2);
ILI9341_DrawString(0,3,"I2C and SPI",COLOR_PURPLE,COLOR_RED,2);
ILI9341_DrawString(0,4,"STM32 developers",COLOR_PURPLE,COLOR_RED,2);
ILI9341_DrawString(0,5,"Hussam Aldean",COLOR_PURPLE,COLOR_RED,2);
ILI9341_DrawString(0,6,"Embedded Frimware",COLOR_PURPLE,COLOR_RED,2);
MPU9250_beginAccel(ACC_FULL_SCALE_16_G);
MPU9250_beginGyro(GYRO_FULL_SCALE_2000_DPS);
MPU9250_beginMag(MAG_MODE_CONTINUOUS_100HZ);
delay(4000);
ILI9341_Fill(COLOR_RED);

while(1){

MPU9250_accelUpdate();
MPU9250_gyroUpdate();
MPU9250_magUpdate();
//acclerometer
sprintf(strax,"ax=%f    g  " ,MPU9250_accelX());	
ILI9341_DrawString(0,0,"Acceleration",COLOR_BLUE,COLOR_RED,2);	
ILI9341_DrawString(0,1,strax,COLOR_BLUE,COLOR_RED,2);
sprintf(stray,"ay=%f    g  " ,MPU9250_accelY());
ILI9341_DrawString(0,2,stray,COLOR_BLUE,COLOR_RED,2);
sprintf(straz,"az=%f    g  " ,MPU9250_accelZ());
ILI9341_DrawString(0,3,straz,COLOR_BLUE,COLOR_RED,2);
////-----gyroscope
ILI9341_DrawString(0,4,"Gyroscope",COLOR_BLUE,COLOR_RED,2);
sprintf(strgx,"gx=%f    dps    " ,MPU9250_gyroX());
ILI9341_DrawString(0,5,strgx,COLOR_BLUE,COLOR_RED,2);
sprintf(strgy,"gy=%f    dps   " ,MPU9250_gyroY());
ILI9341_DrawString(0,6,strgy,COLOR_BLUE,COLOR_RED,2);
sprintf(strgz,"gz=%f    dps   " ,MPU9250_gyroZ());
ILI9341_DrawString(0,7,strgz,COLOR_BLUE,COLOR_RED,2);

//----compass 


ILI9341_DrawString(0,8,"Compass",COLOR_BLUE,COLOR_RED,2);
sprintf(strgx,"cx=%f    uT   " ,MPU9250_magX());
ILI9341_DrawString(0,9,strgx,COLOR_BLUE,COLOR_RED,2);
sprintf(strgy,"cy=%f    uT   " ,MPU9250_magY());
ILI9341_DrawString(0,10,strgy,COLOR_BLUE,COLOR_RED,2);
sprintf(strgz,"cz=%f    uT   " ,MPU9250_magZ());
ILI9341_DrawString(0,11,strgz,COLOR_BLUE,COLOR_RED,2);



sprintf(strcx,"");
sprintf(strcy,"");
sprintf(strcz,"");
sprintf(strgx,"");
sprintf(strgy,"");
sprintf(strgz,"");
sprintf(strax,"");
sprintf(stray,"");
sprintf(straz,"");
}


}
