<title>PWR Component Dictionary</title>
# PWR Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|PWR_SET_OUTPUT|0 (0x0)|| | |
| | | |target|targets||
| | | |enabled|bool||

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|OUTPUT1|0 (0x0)|bool||
|OUTPUT2|1 (0x1)|bool||
|OUTPUT3|2 (0x2)|bool||
|OUTPUT4|3 (0x3)|bool||
|OUTPUT5|4 (0x4)|bool||
|OUTPUT6|5 (0x5)|bool||
|PV4_TLM|6 (0x6)|bool||
|HEATER1|7 (0x7)|bool||
|HEATER2|8 (0x8)|bool||

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|PWR_OUTPUT_SET|0 (0x0)|| | | | |
| | | |toggleTargetEV|devicesEV|||
| | | |enabled_EV|bool|||
