# ExpLoRa
A network of LoRa devices to act as sensors or controllers.

This code is specifically designed to work with the heltec_wifi_lora_32_V3 board
but will be adapted to other boards in the future.

Each ESP32 board is represented in the code as a Node. A Node has a display name
and a unique ID. The unique ID is a two character country code followed by two
more characters: one for the region and one for the specific board. For example, "AU00"

Radio communication is handled using the heltec_unofficial library https://github.com/ropg/heltec_esp32_lora_v3

Data is sent using the class Packet. A packet contains a "from" Node and a "to" Node and an array of
Messages.

Messages contain a Op Code which is a three character string, a device (uint8), a value (uint8) and a priority (uint8)


