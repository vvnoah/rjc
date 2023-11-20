// PC Code
const mqtt = require('mqtt');
const robot = require('robotjs');

const protocol = 'mqtt';
const host = '192.168.0.218';
const port = '1883';
const clientId = `mqtt_${Math.random().toString(16).slice(3)}`;
const connectUrl = `${protocol}://${host}:${port}`;
const username = 'ucll';
const password = '';
const topicsToSubscribe = ['volume/up', 'volume/down', 'other/topic'];

const client = mqtt.connect(connectUrl, {
  clientId,
  clean: true,
  connectTimeout: 4000,
  username: username,
  password: password,
  reconnectPeriod: 1000,
});

client.on('connect', () => {
  console.log('Connected to ESP32 MQTT Broker');
  
  // Subscribe to multiple topics
  topicsToSubscribe.forEach((topic) => {
      client.subscribe(topic, () => {
          console.log(`Subscribed to topic '${topic}'`);
      });
  });
});

client.on('message', (topic, payload) => {
    console.log('Received Message:');
    console.log('- Topic:', topic);
    console.log('- Message:', payload.toString());

    if(topic === "volume/up") {
      volume_up();
    }

    if(topic === "volume/down") {
      volume_down();
    }
});

function volume_up() {
  robot.keyTap("audio_vol_up");
}

function volume_down() {
  robot.keyTap("audio_vol_down");
}