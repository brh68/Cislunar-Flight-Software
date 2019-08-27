#include <newsensor.h>
#include <gyro_valueswipi.h>
#include <newsensor.cpp>
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

int AccScale;
int GyrScale;

float mag[3];
float acc[3];
float gyr[3];
float gyrang[3];

float gyroXangle;
float gyroYangle;
float gyroZangle;

float rate_gyr_x;
float rate_gyr_y;
float rate_gyr_z;

float avg_rate_x_cal;
float avg_rate_y_cal;
float avg_rate_z_cal;

float spinrate = 0;

float A_GAIN;
float G_GAIN;

int count = 0;

void calculate()
{
    if (AccScale == 0) {
        A_GAIN = 0.000244;
    }
    if (GyrScale == 0) {
        G_GAIN = 0.0078125;
    }
    if (AccScale == 1) {
        A_GAIN = 0.000488;
    }
    if (GyrScale == 1) {
        G_GAIN = 0.015625;
    }
    if (AccScale == 2) {
        A_GAIN = 0.000976;
    }
    if (GyrScale == 2) {
        G_GAIN = 0.03125;
    }
    if(GyrScale == 3) {
        G_GAIN = 0.0625;
    }
    printf("AccScale = %i ", AccScale);
    printf("A_GAIN = %f\n", A_GAIN);
    printf("GyrScale = %i ", GyrScale);
    printf("G_GAIN = %f\n", G_GAIN);
}

float * mag_data()
{
    // printf("calculating mag data...\n");
    writeMag();
    int * mag_raw = readMag();
    mag[X] = (float) *(mag_raw) * M_GAIN;
    mag[Y] = (float) *(mag_raw +1) * M_GAIN;
    mag[Z] = (float) *(mag_raw +2) * M_GAIN;
    return mag;
}

float * acc_data()
{
    // printf("calculating acc data...\n");
    writeAcc(AccScale, spinrate);
    int * temp = readAcc();
    float acc_x = ((float) *(temp))*A_GAIN;
    float acc_y = ((float) *(temp+1)) *A_GAIN;
    float acc_z = ((float) *(temp+2)) *A_GAIN;
    acc[X] = acc_x;
    acc[Y] = acc_y;
    acc[Z] = acc_z;
    return acc;
}

void calibrate_gyro()
{
    printf("calibrating gyroscope...\n");
    float total_x = 0;
    float total_y = 0;
    float total_z = 0;
    int datapts = 200;
    for (int i = 0; i < datapts; i++)
    {
        int * temp = readGyr();
        // printf("for calibration... \n");
        float rate_gyr_x = (float) *temp * G_GAIN;
	float rate_gyr_y = (float) *(temp+1) * G_GAIN;
	float rate_gyr_z = (float) *(temp+2) * G_GAIN;
        total_x += rate_gyr_x;
        total_y += rate_gyr_y;
        total_z += rate_gyr_z;
        usleep(1000);
    }
    avg_rate_x_cal = total_x / datapts;
    avg_rate_y_cal = total_y / datapts;
    avg_rate_z_cal = total_z / datapts;
}

float * gyr_data()
{
    // printf("calculating gyro data...\n");
    calculatespin();
    writeGyr(GyrScale, spinrate);
    int * temp = readGyr();
    rate_gyr_x = ((float) *(temp) * G_GAIN) - avg_rate_x_cal;
    rate_gyr_y = ((float) *(temp+1) * G_GAIN) - avg_rate_y_cal;
    rate_gyr_z = ((float) *(temp+2) * G_GAIN) - avg_rate_z_cal;
    gyr[X] = rate_gyr_x;
    gyr[Y] = rate_gyr_y;
    gyr[Z] = rate_gyr_z;
    return gyr;
}

float * gyrang_data()
{
    // printf("calculating gyr angle data...\n");
    float *temp = gyr_data();
    if (count == 0) {
        gyroXangle = 0;
	    gyroYangle = 0;
        gyroZangle = 0;
    }
    count++;
    gyroXangle += rate_gyr_x * DT;
    gyroYangle += rate_gyr_y * DT;
    gyroZangle += rate_gyr_z * DT;
    gyrang[X] = gyroXangle - (((int) gyroXangle/360) * 360);
    gyrang[Y] = gyroYangle - (((int) gyroYangle/360) * 360);
    gyrang[Z] = gyroZangle - (((int) gyroZangle/360) * 360);
    return gyrang;
}

void calculatespin()
{
    spinrate = 0;
    for(int i = 0; i < 3; i++){
        if (abs(gyr[i]) > spinrate){
            spinrate = abs(gyr[i]);
        }
    }    
}

void readdata(float arr[3]){
    printf("X: %f ", arr[0]);
    printf("Y: %f ", arr[1]);
    printf("Z: %f\n", arr[2]);
}

int main(void){
   calculate();
   mag_data();
   readdata(mag);
   acc_data();
   readdata(acc);
   calibrate_gyro();
   int datapts = 100;
   for (int i = 0; i < datapts; i++)
   {
	printf("%i \n", i);
	printf("acc:");
	acc_data();
   	readdata(acc);
	printf("gyr:");
	gyr_data();
	readdata(gyr);
	printf("gyr angle:");
	gyrang_data();
	readdata(gyrang);
	printf("%f\n", spinrate);
	usleep(100000);
   }
   return 0;
}
