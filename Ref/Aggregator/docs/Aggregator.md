<title>Aggregator Component Dictionary</title>
# Aggregator Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|GET_RTC_DATA|0 (0x0)|get time| | |
|SET_RTC_DATA|1 (0x1)|set time| | |
| | | |time|U32||
|AGG_CONFIG_IMU|2 (0x2)|| | |
| | | |GyroConfig|I32||
| | | |AccConfig|I32||
|AGG_GET_IMU_DATA|3 (0x3)|| | |
| | | |Sensor|SensorType||
|AGG_CONFIG_ADC|4 (0x4)|| | |
| | | |VoltageGain|F64||
| | | |SampleRate|I32||
|AGG_GET_ADC_TEMP|5 (0x5)|| | |
| | | |AmbientTemp|F64||
|AGG_GET_ADC_PRESSURE|6 (0x6)|| | |

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|AGG_TIME|0 (0x0)|U32||
|AGG_GyroX|1 (0x1)|F64||
|AGG_GyroY|2 (0x2)|F64||
|AGG_GyroZ|3 (0x3)|F64||
|AGG_AccX|4 (0x4)|F64||
|AGG_AccY|5 (0x5)|F64||
|AGG_AccZ|6 (0x6)|F64||
|AGG_MagX|7 (0x7)|F64||
|AGG_MagY|8 (0x8)|F64||
|AGG_MagZ|9 (0x9)|F64||
|AGG_IMU_GyroConfig|10 (0xa)|I32||
|AGG_IMU_AccConfig|11 (0xb)|I32||
|AGG_ADC_VGAIN|12 (0xc)|F64||
|AGG_ADC_SAMPLE_RATE|13 (0xd)|I32||
|AGG_ADC_TEMP|14 (0xe)|F64||
|AGG_ADC_PRESSURE|15 (0xf)|F64||

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|RTC_COMMAND_SENT|0 (0x0)|| | | | |
| | | |timeEv|U32|||
| | | |opEv|MathOpEv||The requested operation|
|IMU_COMMAND_SENT|1 (0x1)|| | | | |
| | | |opEv|IMUEventEnum|||
|ADC_COMMAND_SENT|2 (0x2)|| | | | |
| | | |opEv|ADCEventEnum|||
