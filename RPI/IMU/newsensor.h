#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

void writeAcc(int scale, float spinrate);

void writeGyr(int scale, float spinrate);

void writeMag();

int* readAcc();

int* readMag();

int* readGyr();
