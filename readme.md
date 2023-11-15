# Remote Joystick Controller
## Features
- Control the mouse cursor with a joystick over bluetooth.
- Control pc functions like media, volume etc. by sending   
  commands using MQTT.
## Used libraries
### ESP-32
- Bluetooth mouse control: [[https://github.com/T-vK/ESP32-BLE-Mouse]]
### Back-end
- MQTT: [[https://www.npmjs.com/package/aedes]]
- PC volume control: [[https://github.com/LinusU/node-loudness]]