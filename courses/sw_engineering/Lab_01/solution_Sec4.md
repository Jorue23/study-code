# Requirements

ALARM-001: The software shall display the current time at all times.
ALARM-002: The software shall play a tone when the set alarm time is reached.
ALARM-003: The software shall provide an HMI to set alarm times and tones.
ALARM-004: The software shall provide an option to snooze alarms.
ALARM-005: The software shall offer the option to upload custom alarm tones in the defined file formats.
ALARM-006: The software shall offer the option to schedule alarms for different weekdays.
ALARM-007: The software shall play a tone even if the device is in DND or silent mode.
ALARM-008: The software shall keep running in the background even if the app is closed.

ALARM-009: The software shall support the following file fomarts for the alarm tones: mp3, wav.
ALARM-010: The alarm tone shall trigger within 2 scods of the set time.


# Group:

## Functional Requirements
- The application shall allow the user to create, manage, and store one or multiple independent alarms. (user-level)
- The application shall provide a selection of multiple pre-installed alarm sounds for the user to choose from. (software-level)
- The application shall allow the user to import and set custom audio files in common formats (e.g., MP3, AAC, WAV) as alarm sounds. (software-level)
- The application shall trigger the audible alarm even when the device is set to silent, vibrate, or Do Not Disturb (DND) mode. (software-level)
- The application shall require an explicit user interaction (such as a swipe gesture) to dismiss an active alarm. (software-level)
- The application shall provide scheduling rules for each alarm to repeat on user-defined weekdays. (software-level)
- The application shall offer optional wake-up challenges (e.g., solving math problems, typing text) that must be completed to dismiss the alarm. (software-level)
- The application shall allow the user to enable or disable any configured alarm individually via a single toggle action. (user-level)


## Non-functional requirements
 - During background standby execution, the application shall consume less than 1% of the total battery capacity over a 24-hour period. (system-level)
 - The application shall comply with platform-specific OS design guidelines and automatically support both system Light Mode and Dark Mode. (software-level)
 - The timezone of the device installed on is used for the alarm (system-level)
 - The standard snooze is 9 minutes. After this a challenge (e.g. calculations) is required to dismiss the alarm (system-level)
 - The volume shall be set by the user in configuration (user-level)