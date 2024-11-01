/**
 * Send and receive LoRa-modulation packets with a sequence number, showing RSSI
 * and SNR for received packets on the little display.
 *
 * Note that while this send and received using LoRa modulation, it does not do
 * LoRaWAN. For that, see the LoRaWAN_TTN example.
 *
 * This works on the stick, but the output on the screen gets cut off.
*/
void rx();

// Load the local configuration options.
#include <config.h>
#include <node.h>
#include <country.h>
#include <packet.h>
#include <message.h>

// Turns the 'PRG' button into the power button, long press is off 
#define HELTEC_POWER_BUTTON   // must be before "#include <heltec_unofficial.h>"
#include <heltec_unofficial.h>
#include <WiFi.h>

String rxdata;
volatile bool rxFlag = false;

// The definition of this node, it should be used as the from
// field of all packets.
Node me = Node(
  DEVICE_NAME,
  DEVICE_COUNTRY,
  DEVICE_REGION,
  DEVICE_NUMBER,
  WIFI);            // Set to true to enable WiFI

long counter = 0;
uint64_t last_tx = 0;
uint64_t tx_time;
uint64_t minimum_pause;

void setup() {
  heltec_setup();

  if (me.hasWIFI) {
    // Begin Wi-Fi connection
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    
    // Wait until connected
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
  
    both.println("IP Address: ");
    both.println(WiFi.localIP());
  }
  
  //Serial.println("Radio init");
  RADIOLIB_OR_HALT(radio.begin());
  // Set the callback function for received packets
  radio.setDio1Action(rx);
  // Set radio parameters
  Serial.printf("Frequency: %.2f MHz\n", FREQUENCY);
  RADIOLIB_OR_HALT(radio.setFrequency(FREQUENCY));
  // Serial.printf("Bandwidth: %.1f kHz\n", BANDWIDTH);
  RADIOLIB_OR_HALT(radio.setBandwidth(BANDWIDTH));
  // Serial.printf("Spreading Factor: %i\n", SPREADING_FACTOR);
  RADIOLIB_OR_HALT(radio.setSpreadingFactor(SPREADING_FACTOR));
  // Serial.printf("TX power: %i dBm\n", TRANSMIT_POWER);
  RADIOLIB_OR_HALT(radio.setOutputPower(TRANSMIT_POWER));
  // Start receiving
  RADIOLIB_OR_HALT(radio.startReceive(RADIOLIB_SX126X_RX_TIMEOUT_INF));
}

void loop() {
  heltec_loop();
  
  bool tx_legal = millis() > last_tx + minimum_pause;
  // Transmit a packet every PAUSE seconds or when the button is pressed
  if ((PAUSE && tx_legal && millis() - last_tx > (PAUSE * 1000))) {
    // In case of button click, tell user to wait
    if (!tx_legal) {
      Serial.printf("Legal limit, wait %i sec.\n", (int)((minimum_pause - (millis() - last_tx)) / 1000) + 1);
      return;
    }

    // Who are we sending this packet to?
    Node recipient = Node("Base", CountryCode::AU, 'A', '1');
    Serial.printf("FROM: %s\n", me.getDeviceID().c_str());
    Serial.printf("TO: %s\n", recipient.getDeviceID().c_str());

    Packet packet = Packet(me, recipient);

    // Create two messages to add to the current paket
    Message data1 = Message(OpCode::Push, 0, 1, 5);
    Serial.printf("MESSAGE: %s\n", data1.toString().c_str());
    packet.addMessage(data1);

    Message data2 = Message(OpCode::Push, 1, 240, 5);
    Serial.printf("MESSAGE: %s\n", data1.toString().c_str());
    packet.addMessage(data2);

    // Display the current packet about to be sent.
    Serial.println("PACKET:");
    both.printf("TX: %s\n", packet.toString().c_str());

    radio.clearDio1Action();

    heltec_led(50); // 50% brightness is plenty for this LED
    tx_time = millis();
    RADIOLIB(radio.transmit(packet.toString().c_str()));
    tx_time = millis() - tx_time;
    heltec_led(0);

    // Check if transmission of packet succeeded
    if (_radiolib_status != RADIOLIB_ERR_NONE) {
      both.printf("fail (%i)\n", _radiolib_status);
    }
    // Maximum 1% duty cycle
    minimum_pause = tx_time * 100;
    last_tx = millis();
    radio.setDio1Action(rx);
    RADIOLIB_OR_HALT(radio.startReceive(RADIOLIB_SX126X_RX_TIMEOUT_INF));

  }

  // If a packet was received, display it and the SNR
  if (rxFlag) {
    rxFlag = false;
    radio.readData(rxdata);
    if (_radiolib_status == RADIOLIB_ERR_NONE) {
      both.printf("RX: %s\n", rxdata.c_str());
      both.printf("  SNR: %.2f dB\n", radio.getSNR());
    }
    RADIOLIB_OR_HALT(radio.startReceive(RADIOLIB_SX126X_RX_TIMEOUT_INF));
  }
}

// Can't do Serial or display things here, takes too much time for the interrupt
void rx() {
  rxFlag = true;
}
