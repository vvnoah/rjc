const robot = require("robotjs"); // Library to control pc functions.
const aedes = require("aedes")();                           //
const server = require("net").createServer(aedes.handle);   // MQTT Library.


// Connect to the MQTT broker
server.listen(1883, function () {
  console.log("MQTT server listening on port 1883");
});

// Handle incoming MQTT messages
aedes.on("publish", function (packet, client) {
  if (packet.topic === "media/audio_mute") {
    try {
      robot.keyTap("audio_mute");
    } catch (error) {
      console.error("Error processing MQTT message:", error);
    }
  }
  if (packet.topic === "media/audio_vol_up") {
    try {
      robot.keyTap("audio_vol_up");
    } catch (error) {
      console.error("Error processing MQTT message:", error);
    }
  }
  if (packet.topic === "media/audio_vol_down") {
    try {
      robot.keyTap("audio_vol_down");
    } catch (error) {
      console.error("Error processing MQTT message:", error);
    }
  }
  if (packet.topic === "media/audio_play") {
    try {
      robot.keyTap("audio_play");
    } catch (error) {
      console.error("Error processing MQTT message:", error);
    }
  }
  if (packet.topic === "media/audio_pauze") {
    try {
      robot.keyTap("audio_pauze")
    } catch (error) {
      console.error("Error processing MQTT message:", error);
    }
  }
});