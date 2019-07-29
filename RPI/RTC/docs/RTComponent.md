<title>RTComponent Component Dictionary</title>
# RTComponent Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|RTC_COMMAND|0 (0x0)|set time| | |
| | | |time|U32|The first value|
| | | |operation|RTCOp||

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|RTC_TIME|0 (0x0)|U32|The time|

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|RTC_COMMAND_RECV|0 (0x0)|Math command received| | | | |
| | | |time|U32||The val1 argument|
| | | |op|MathOpEv||The requested operation|
