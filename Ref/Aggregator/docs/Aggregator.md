<title>Aggregator Component Dictionary</title>
# Aggregator Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|GET_RTC_DATA|0 (0x0)|get time| | |
|SET_RTC_DATA|1 (0x1)|set time| | |
| | | |time|U32||

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|AGG_TIME|0 (0x0)|U32|The time|

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|RTC_COMMAND_SENT|0 (0x0)|Math command sent| | | | |
| | | |timeEv|U32||The val1 argument|
| | | |opEv|MathOpEv||The requested operation|
