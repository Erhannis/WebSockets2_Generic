/****************************************************************************************************************************
  defines.h for nRF52-Ethernet-Client_SINRIC.ino
  For nRF52 with Ethernet module/shield, using SINRIC (https://sinric.com/)
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  Version: 1.0.1

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2020 Initial coding/porting to support nRF52 and SAMD21/SAMD51 boards. Add SINRIC/Alexa support 
  1.0.1   K Hoang      16/07/2020 Add support to SAM DUE. Add support to Ethernet W5x00 to nRF52, SAMD, SAM DUE boards.    
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if ( defined(NRF52840_FEATHER) || defined(NRF52832_FEATHER) || defined(NRF52_SERIES) || defined(ARDUINO_NRF52_ADAFRUIT) || \
      defined(NRF52840_FEATHER_SENSE) || defined(NRF52840_ITSYBITSY) || defined(NRF52840_CIRCUITPLAY) || defined(NRF52840_CLUE) || \
      defined(NRF52840_METRO) || defined(NRF52840_PCA10056) || defined(PARTICLE_XENON) || defined(NINA_B302_ublox) || defined(NINA_B112_ublox) )
#if defined(WEBSOCKETS_ETHERNET_USE_SAMD)
#undef WEBSOCKETS_ETHERNET_USE_SAMD
#endif
#define WEBSOCKETS_USE_ETHERNET           true
#define WEBSOCKETS_ETHERNET_USE_SAMD      true
#else
#error This code is intended to run only on the SAMD boards ! Please check your Tools->Board setting.
#endif

#if defined(WEBSOCKETS_ETHERNET_USE_SAMD)

#if defined(NRF52840_FEATHER)
#define BOARD_TYPE      "NRF52840_FEATHER_EXPRESS"
#elif defined(NRF52832_FEATHER)
#define BOARD_TYPE      "NRF52832_FEATHER"
#elif defined(NRF52840_FEATHER_SENSE)
#define BOARD_TYPE      "NRF52840_FEATHER_SENSE"
#elif defined(NRF52840_ITSYBITSY)
#define BOARD_TYPE      "NRF52840_ITSYBITSY_EXPRESS"
#elif defined(NRF52840_CIRCUITPLAY)
#define BOARD_TYPE      "NRF52840_CIRCUIT_PLAYGROUND"
#elif defined(NRF52840_CLUE)
#define BOARD_TYPE      "NRF52840_CLUE"
#elif defined(NRF52840_METRO)
#define BOARD_TYPE      "NRF52840_METRO_EXPRESS"
#elif defined(NRF52840_PCA10056)
#define BOARD_TYPE      "NORDIC_NRF52840DK"
#elif defined(NINA_B302_ublox)
#define BOARD_TYPE      "NINA_B302_ublox"
#elif defined(NINA_B112_ublox)
#define BOARD_TYPE      "NINA_B112_ublox"
#elif defined(PARTICLE_XENON)
#define BOARD_TYPE      "PARTICLE_XENON"
#elif defined(MDBT50Q_RX)
#define BOARD_TYPE      "RAYTAC_MDBT50Q_RX"
#elif defined(ARDUINO_NRF52_ADAFRUIT)
#define BOARD_TYPE      "ARDUINO_NRF52_ADAFRUIT"
#else
#define BOARD_TYPE      "nRF52 Unknown"
#endif

#endif

// Just select one to be true. If all is false, default is Ethernet. 
// If more than one are true, the priority is USE_ETHERNET_LIB, USE_ETHERNET2_LIB, USE_ETHERNET_LARGE_LIB
#define USE_ETHERNET_LIB              false
#define USE_ETHERNET2_LIB             false
#define USE_ETHERNET_LARGE_LIB        true

#if USE_ETHERNET_LIB
  // Also default to Ethernet library
  #include <Ethernet.h>
#elif USE_ETHERNET2_LIB
  #include <Ethernet2.h>
#elif USE_ETHERNET_LARGE_LIB
  #include <EthernetLarge.h>
#else
  // Default to Ethernet library
  #include <Ethernet.h>
#endif

#define DEBUG_WEBSOCKETS_PORT     Serial
// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_     3

#define SINRIC_WEBSERVER          "iot.sinric.com"
#define SINRIC_WEBSERVER_PORT     80
#define SINRIC_API_KEY            "11111111-2222-3333-4444-555555555555"

#define SINRIC_Device_ID_1        "012345678901234567890123"   // Device ID, got from Sinric

const char* websockets_server_host    = SINRIC_WEBSERVER; //Enter server address
const uint16_t websockets_server_port = SINRIC_WEBSERVER_PORT; // Enter server port

#ifdef LED_BUILTIN
#define LED_PIN     LED_BUILTIN
#else
#define LED_PIN     13
#endif

uint8_t mac[6] =  { 0xDE, 0xAD, 0xBE, 0xEF, 0x52, 0xA9 };

// Select the IP address according to your local network
IPAddress clientIP(192, 168, 2, 225);

#define SDCARD_CS       4

#endif      //defines_h
