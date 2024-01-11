let WebSocketClient = require('websocket').client;
const robot = require('robotjs');

robot.setKeyboardDelay(0);
robot.setMouseDelay(0);

let client = new WebSocketClient();

client.on('connect', function(connection) {
  console.log('WebSocket Connected');
  connection.on('error', function(error) {
      console.log("Connection Error: " + error.toString());
  });
  connection.on('close', function() {
      console.log('Connection Closed.');
  });
  connection.on('message', function(message) {
    if (typeof message.utf8Data === 'string') {
        try {
          const json = JSON.parse(message.utf8Data);
          console.log(json);

          if(json.mode == "cursor")
          {
            const joystick_x = json.joystick_position.x;
            const joystick_y = json.joystick_position.y;
  
            if(joystick_x != 0 || joystick_y != 0)
            {
              let mouse_position = robot.getMousePos();
              mouse_position.x += joystick_x;
              mouse_position.y += joystick_y;
              robot.moveMouse(mouse_position.x, mouse_position.y);
            }          
            
            if(json.buttons.button_1 == 1) robot.mouseClick();
            if(json.buttons.button_2 == 1) robot.mouseClick("right");
          }
          
          if(json.mode == "media")
          {
            if(json.buttons.button_1 == 1) robot.keyTap("audio_vol_up");  
            if(json.buttons.button_2 == 1) robot.keyTap("audio_vol_down");
          }          
        } catch (error) {
          console.error('Error parsing JSON:', error);
        }
      } else {
        console.error('Received non-string data:', message.utf8Data);
      }
  });
});

client.connect('ws://192.168.0.86:81');