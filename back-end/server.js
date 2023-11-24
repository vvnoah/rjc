let WebSocketClient = require('websocket').client;
const robot = require('robotjs');

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
          const data = JSON.parse(message.utf8Data);

          const type = data.type;
          const x = data.data.x;
          const y = data.data.y;

          if(type == "cursor") {
            moveMouseWithJoystick(x, y);
          } else if (type == "scroll") {
            robot.scrollMouse(x, y);
          }

          console.log(`[ws]: ${type}: ${x}, ${y}`);
        } catch (error) {
          console.error('Error parsing JSON:', error);
        }
      } else {
        console.error('Received non-string data:', message.utf8Data);
      }
  });
});

client.connect('ws://192.168.1.104:81/');

function moveMouseWithJoystick(x, y) {
  let pos = robot.getMousePos();
  pos.x += x + 5;
  pos.y += y + 5;
  robot.moveMouse(pos.x, pos.y);
}