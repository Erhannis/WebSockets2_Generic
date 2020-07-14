/****************************************************************************************************************************
  WebSockets2_Generic_Debug.h
  For WebSockets2_Generic Library
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  Version: 1.0.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2020 Initial coding/porting to support nRF52 and SAMD21/SAMD51 boards. Add SINRIC/Alexa support    
 *****************************************************************************************************************************/

#ifndef WebSockets2_Generic_Debug_h
#define WebSockets2_Generic_Debug_h

#include <stdio.h>

#ifdef DEBUG_WEBSOCKETS_PORT
  #define DBG_PORT      DEBUG_WEBSOCKETS_PORT
#else
  #define DBG_PORT      Serial
#endif

// Change _WEBSOCKETS_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _WEBSOCKETS_LOGLEVEL_
  #define _WEBSOCKETS_LOGLEVEL_       2
#endif


#define LOGERROR(x)     if(_WEBSOCKETS_LOGLEVEL_>0) { DBG_PORT.print("[WS] "); DBG_PORT.println(x); }
#define LOGERROR1(x,y)  if(_WEBSOCKETS_LOGLEVEL_>0) { DBG_PORT.print("[WS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.println(y); }

#define LOGWARN(x)      if(_WEBSOCKETS_LOGLEVEL_>1) { DBG_PORT.print("[WS] "); DBG_PORT.println(x); }
#define LOGWARN1(x,y)   if(_WEBSOCKETS_LOGLEVEL_>1) { DBG_PORT.print("[WS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.println(y); }

#define LOGINFO(x)      if(_WEBSOCKETS_LOGLEVEL_>2) { DBG_PORT.print("[WS] "); DBG_PORT.println(x); }
#define LOGINFO1(x,y)   if(_WEBSOCKETS_LOGLEVEL_>2) { DBG_PORT.print("[WS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.println(y); }
#define LOGINFO2(x,y,z) if(_WEBSOCKETS_LOGLEVEL_>3) { DBG_PORT.print("[WS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.println(z); }
#define LOGINFO3(x,y,z,w) if(_WEBSOCKETS_LOGLEVEL_>3) { DBG_PORT.print("[WS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.println(z); DBG_PORT.print(" "); DBG_PORT.println(w); }

#define LOGDEBUG(x)      if(_WEBSOCKETS_LOGLEVEL_>3) { DBG_PORT.print("[WS] "); DBG_PORT.println(x); }
#define LOGDEBUG0(x)     if(_WEBSOCKETS_LOGLEVEL_>3) { DBG_PORT.print("[WS] "); DBG_PORT.print(x); }
#define LOGDEBUG1(x,y)   if(_WEBSOCKETS_LOGLEVEL_>3) { DBG_PORT.print("[WS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.println(y); }
#define LOGDEBUG2(x,y,z) if(_WEBSOCKETS_LOGLEVEL_>3) { DBG_PORT.print("[WS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.println(z); }
#define LOGDEBUG3(x,y,z,w) if(_WEBSOCKETS_LOGLEVEL_>3) { DBG_PORT.print("[WS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.println(z); DBG_PORT.print(" "); DBG_PORT.println(w); }


#endif    //WebSockets2_Generic_Debug_h