const robot = require("robotjs"); // Library to control pc functions.
const aedes = require("aedes")();                           //
const server = require("net").createServer(aedes.handle);   // MQTT Library.


// Connect to the MQTT broker
server.listen(1883, function () {
  console.log("MQTT server listening on port 1883");
});

// Handle incoming MQTT messages
aedes.on("publish", function (packet, client) {
  if (packet.topic === "packet_name") {
    try {
      // Do something.
    } catch (error) {
      console.error("Error processing MQTT message:", error);
    }
  }
});
