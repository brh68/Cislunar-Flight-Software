<title>Aggregator Component Dictionary</title>
# Aggregator Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|GET_RTC_DATA|0 (0x0)|get time| | |
|SET_RTC_DATA|1 (0x1)|set time| | |
| | | |time|U32||
|AGG_CONFIG_IMU|2 (0x2)|| | |
| | | |configVal1|I32||
| | | |configVal2|I32||
|AGG_GET_IMU_DATA|3 (0x3)|gets gyro and accelerometer daat| | |

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|AGG_TIME|0 (0x0)|U32|The time|
|AGG_GyroX|1 (0x1)|F64||
|AGG_GyroY|2 (0x2)|F64||
|AGG_GyroZ|3 (0x3)|F64||
|AGG_AccX|4 (0x4)|F64||
|AGG_AccY|5 (0x5)|F64||
|AGG_AccZ|6 (0x6)|F64||
|AGG_IMU_Config1|7 (0x7)|I32||
|AGG_IMU_Config2|8 (0x8)|I32||

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|RTC_COMMAND_SENT|0 (0x0)|| | | | |
| | | |timeEv|U32|||
| | | |opEv|MathOpEv||The requested operation|
|IMU_COMMAND_SENT|1 (0x1)|| | | | |
| | | |opEv|IMUEventEnum||The requested operation|
