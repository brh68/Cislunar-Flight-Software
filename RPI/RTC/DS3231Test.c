#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int test;


struct tm t_result;

long RTCUnixTime(int test)
{
	struct tm t;
	time_t t_of_day;
	t.tm_year = wiringPiI2CReadReg8(test, 0x06)+100-6*(wiringPiI2CReadReg8(test, 0x06)/0x10);
	t.tm_mon = wiringPiI2CReadReg8(test, 0x05)-1-6*(wiringPiI2CReadReg8(test, 0x05)/0x10);
	t.tm_mday = wiringPiI2CReadReg8(test, 0x04)-6*(wiringPiI2CReadReg8(test, 0x04)/0x10);
	t.tm_hour = wiringPiI2CReadReg8(test, 0x02)-6*(wiringPiI2CReadReg8(test, 0x02)/0x10);
	t.tm_min = wiringPiI2CReadReg8(test, 0x01)-6*(wiringPiI2CReadReg8(test, 0x01)/0x10);
	t.tm_sec = wiringPiI2CReadReg8(test, 0x00)-6*(wiringPiI2CReadReg8(test, 0x00)/0x10);
	t.tm_isdst = 0;
	t_of_day = mktime(&t);
	return (long)t_of_day;
}

void InputUnixTime(int test, long Ltime)
{
	time_t now = Ltime;
	struct tm ts;
	char sec[5];
	char min[5];
	char hour[5];
	char mday[5];
	char month[5];
	char year[5];
	
	ts = *localtime(&now);
	
	strftime(sec, sizeof(sec), "%S", &ts);
	wiringPiI2CWriteReg8(test,0x00, atoi(sec)+6*(atoi(sec)/10));
	
	strftime(min, sizeof(min), "%M", &ts);
	wiringPiI2CWriteReg8(test,0x01, atoi(min)+6*(atoi(min)/10));

	strftime(hour, sizeof(hour), "%H", &ts);
	wiringPiI2CWriteReg8(test,0x02, atoi(hour)+6*(atoi(hour)/10));

	strftime(mday, sizeof(mday), "%d", &ts);
	wiringPiI2CWriteReg8(test,0x04, atoi(mday)+6*(atoi(mday)/10));

	strftime(month, sizeof(month), "%m", &ts);
	wiringPiI2CWriteReg8(test,0x05, atoi(month)+6*(atoi(month)/10));

	strftime(year, sizeof(year), "%y", &ts);
	wiringPiI2CWriteReg8(test,0x06, atoi(year)+6*(atoi(year)/10));
	
}
int initWiringPiRTC(void){
	wiringPiSetup();
	int device = wiringPiI2CSetup(0x68);
	return device;
}

int main (void)
{
	wiringPiSetup();
	test = wiringPiI2CSetup(0x68);
	//printf("Init: %x ", test);
	//printf("Write: %x ", wiringPiI2CWriteReg8(test, 0x02));
for(int y = 0; y<1; y++){
	//wiringPiI2CWriteReg8(test,0x01, 0x59);
	//wiringPiI2CWriteReg8(test,0x00, 0x59);
	//wiringPiI2CWriteReg8(test,0x02, 0x23);
	//wiringPiI2CWriteReg8(test,0x04, 0x31);
	//wiringPiI2CWriteReg8(test,0x05, 0x12);	
	//for (int xeta=0; xeta<1; xeta++) {
	//	long t = 1369668347;
	//	InputUnixTime(t);
	//	printf("Input Time: %ld\n", t);
	//	printf("\n%02x:%02x:%02x\n", wiringPiI2CReadReg8(test, 0x06),wiringPiI2CReadReg8(test,0x05), wiringPiI2CReadReg8(test,0x04));
	//	printf("%02x:%02x:%02x\n", wiringPiI2CReadReg8(test, 0x02),wiringPiI2CReadReg8(test, 0x01),wiringPiI2CReadReg8(test, 0x00));
	//	printf("Unix Time: %ld\n", RTCUnixTime());
		
		//localtime_r(&t_of_day, &t_result);
		//printf("Unix Time: %ld\n", (long) t_of_day);
		//printf("%02x:%02x:%02x\n",t_result.tm_year,t_result.tm_mon,t_result.tm_mday);
		//printf("%02x:%02x:%02x\n",t_result.tm_hour,t_result.tm_min,t_result.tm_sec);
		//printf(ctime(&t_of_day));
		usleep(1000000);
	//}
}
	
	return 0;
}
