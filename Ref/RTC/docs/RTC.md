<title>RTC Component Dictionary</title>
# RTC Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|RTC_CMD_TIME|0 (0x0)|set time| | |
| | | |time|U32|The first value|

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|RTC_TIME|0 (0x0)|U32|The time|

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|RTC_PORT_CALL|0 (0x0)|Math command received| | | | |
| | | |timeEv|U32||The val1 argument|
| | | |opEv|MathOpEv||The requested operation|