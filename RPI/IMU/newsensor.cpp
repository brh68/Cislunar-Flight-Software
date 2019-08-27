#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include "newsensor.h"

int testAcc = wiringPiI2CSetup(0x1f);
int testGyr = wiringPiI2CSetup(0x21);
int testMag = wiringPiI2CSetup(0x1f);

void writeAcc(int scale, float spinrate)
{    
	wiringPiI2CWriteReg8(testAcc, 0x2A, 0);
	wiringPiI2CWriteReg8(testAcc, 0x2B, 0x02);
	if (spinrate >= 390){
                wiringPiI2CWriteReg8(testAcc, 0x2A, 0b00000101);
        }
        else{
		wiringPiI2CWriteReg8(testAcc, 0x2A, 0b00001101);
        }
        if(scale == 0) {
                printf("scale 0: +/- 2 g\n");
                wiringPiI2CWriteReg8(testAcc, 0x0E, 0b00000000);
                return;
        }
        else if(scale == 1) {
                printf("scale 1: +/- 4g\n");
                wiringPiI2CWriteReg8(testAcc, 0x0E, 0b00000001);
                return;
        }
        else if(scale == 2) {
                printf("scale 2: +/- 8g\n");
                wiringPiI2CWriteReg8(testAcc, 0x0E, 0b00000010);
                return;
        }
        else {
                printf("Not a possible scale. Keep in range of 0 to 2\n");
                exit(1);
        }
}

void writeGyr(int scale, float spinrate)
{
        if(scale == 0) {
                printf("scale 0: 250 dps\n");
                wiringPiI2CWriteReg8(testGyr, 0x0D, 0x03);
        }
        if(scale == 1) {
                printf("scale 1: 500 dps\n");
                wiringPiI2CWriteReg8(testGyr, 0x0D, 0x02); 
        }
        if(scale == 2) {
                printf("scale 2: 1000 dps\n");
                wiringPiI2CWriteReg8(testGyr, 0x0D, 0x01);
        }
        if(scale == 3) {
                printf("scale 3: 2000 dps\n");
                wiringPiI2CWriteReg8(testGyr, 0x0D, 0x00);
        }
        if(scale > 3 || scale < 0) {
                printf("Not a possible scale. Keep in range of 0 to 3\n");
                exit(1);
        }
	if (spinrate >= 390){
                wiringPiI2CWriteReg8(testGyr, 0x13, 0b00000011);
        }
        else{
                wiringPiI2CWriteReg8(testGyr, 0x13, 0b00000111);
        }
}

void writeMag()
{
        // printf("enabling magnetometer... \n temperature disabled, minimum data output rate 100Hz\n");
        wiringPiI2CWriteReg8(testMag, 0x5b, 0x1F);
	wiringPiI2CWriteReg8(testMag, 0x5C, 0x20);
}


int * readAcc()
{
        // printf("reading accelerometer... \n");
        int* arr = new int[3];
        arr[0] = (int16_t) (wiringPiI2CReadReg8(testAcc, 0x02) + (wiringPiI2CReadReg8(testAcc, 0x01) << 8)) /4;
        arr[1] = (int16_t) (wiringPiI2CReadReg8(testAcc, 0x04) + (wiringPiI2CReadReg8(testAcc, 0x03) << 8)) /4;
        arr[2] = (int16_t) (wiringPiI2CReadReg8(testAcc, 0x06) + (wiringPiI2CReadReg8(testAcc, 0x05) << 8)) /4;
        //printing the objects within array
        //printf("X: %d", arr[0]);
        //printf("Y: %d", arr[1]);
        //printf("Z: %d\n", arr[2]);
        return arr;
}

int * readMag()
{
        // printf("reading magnetometer... \n");
        int* arr = new int[3];
        arr[0] = (int16_t) (wiringPiI2CReadReg8(testMag, 0x34) + (wiringPiI2CReadReg8(testMag, 0x33) << 8));
        arr[1] = (int16_t) (wiringPiI2CReadReg8(testMag, 0x36) + (wiringPiI2CReadReg8(testMag, 0x35) << 8));
        arr[2] = (int16_t) (wiringPiI2CReadReg8(testMag, 0x38) + (wiringPiI2CReadReg8(testMag, 0x37) << 8));
        //printing the objects within array
        //printf("X: %d", arr[0]);
        //printf("Y: %d", arr[1]);
        //printf("Z: %d\n", arr[2]);
        return arr;
}

int * readGyr()
{
        // printf("reading gyroscope... \n");
        int* arr = new int[3];
        arr[0] = (int16_t) (wiringPiI2CReadReg8(testGyr, 0x02) + (wiringPiI2CReadReg8(testGyr, 0x01) << 8));
        arr[1] = (int16_t) (wiringPiI2CReadReg8(testGyr, 0x04) + (wiringPiI2CReadReg8(testGyr, 0x03) << 8));
        arr[2] = (int16_t) (wiringPiI2CReadReg8(testGyr, 0x06) + (wiringPiI2CReadReg8(testGyr, 0x05) << 8));
        //printing the objects within array
        //printf("X: %d", arr[0]);
        //printf("Y: %d", arr[1]);
        //printf("Z: %d\n", arr[2]);
        return arr;
}