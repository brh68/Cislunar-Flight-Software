<title>IMU Component Dictionary</title>
# IMU Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|IMU_CONFIGURE|0 (0x0)|set time| | |
| | | |configVal1|I32||
| | | |configVal2|I32||

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|IMU_GYROX|0 (0x0)|F64||
|IMU_GYROY|1 (0x1)|F64||
|IMU_GYROZ|2 (0x2)|F64||
|IMU_ACCX|3 (0x3)|F64||
|IMU_ACCY|4 (0x4)|F64||
|IMU_ACCZ|5 (0x5)|F64||

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|IMU_READ|0 (0x0)|| | | | |
| | | |gyroXEv|F64|||
| | | |gyroYEv|F64|||
| | | |gyroZEv|F64|||
| | | |accXEv|F64|||
| | | |accYEv|F64|||
| | | |accZEv|F64|||
|IMU_CONFIGURED|1 (0x1)|| | | | |
| | | |IMU_CONFIG_VAL1|I32|||
| | | |IMU_CONFIG_VAL2|I32|||
