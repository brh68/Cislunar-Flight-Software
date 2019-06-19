<title>ADC Component Dictionary</title>
# ADC Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|ADC_CONFIGURE|0 (0x0)|| | |
| | | |VoltageGain|F64||
| | | |SampleRate|I32||

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|ADC_Temperature|0 (0x0)|F64||
|ADC_Pressure|1 (0x1)|F64||
|ADC_VoltageGain|2 (0x2)|F64||
|ADC_SampleRate|3 (0x3)|I32||

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|ADC_READ|0 (0x0)|| | | | |
| | | |typeEV|adcTypeEV|||
| | | |value|F64|||
|ADC_CONFIGURED|1 (0x1)|| | | | |
| | | |ADC_VOLTAGE_GAIN_CONFIG|F64|||
| | | |ADC_SAMPLE_RATE_CONFIG|I32|||
