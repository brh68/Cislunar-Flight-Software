<title>IMU Component Dictionary</title>
# IMU Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|IMU_CONFIGURE|0 (0x0)|set time| | |
| | | |gyroConfig|I32||
| | | |accConfig|I32||

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|IMU_GYROX|0 (0x0)|F64||
|IMU_GYROY|1 (0x1)|F64||
|IMU_GYROZ|2 (0x2)|F64||
|IMU_ACCX|3 (0x3)|F64||
|IMU_ACCY|4 (0x4)|F64||
|IMU_ACCZ|5 (0x5)|F64||
|IMU_MAGX|6 (0x6)|F64||
|IMU_MAGY|7 (0x7)|F64||
|IMU_MAGZ|8 (0x8)|F64||
|IMU_GyroConfig|9 (0x9)|I32||
|IMU_AccConfig|10 (0xa)|I32||

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|IMU_READ|0 (0x0)|| | | | |
| | | |typeEV|imuTypeEV|||
| | | |XEv|F64|||
| | | |YEv|F64|||
| | | |ZEv|F64|||
|IMU_CONFIGURED|1 (0x1)|| | | | |
| | | |IMU_GYRO_CONFIG|I32|||
| | | |IMU_ACC_CONFIG|I32|||
