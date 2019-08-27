#include "newsensor.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define X 0
#define Y 1
#define Z 2

#define AA 0.98
#define DT 0.05
#define M_GAIN 0.0000001

#define RAD_TO_DEG 57.29578
#define M_PI 3.14159265358979323846

extern int AccScale;
extern int GyrScale;

void calculate();

float * mag_data();

float * acc_data();

void calibrate_gyro();

float * gyr_data();

float * gyrang_data();

void readdata(float arr[3]);

void calculatespin();

int main(void);