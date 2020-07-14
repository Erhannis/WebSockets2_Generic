/****************************************************************************************************************************
  esp8266_tcp.hpp
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
 
#pragma once

#ifdef ESP8266 

#include <Tiny_Websockets_Generic/internals/ws_common.hpp>
#include <Tiny_Websockets_Generic/network/tcp_client.hpp>
#include <Tiny_Websockets_Generic/network/tcp_server.hpp>
#include <Tiny_Websockets_Generic/network/generic_esp/generic_esp_clients.hpp>

#include <ESP8266WiFi.h>

namespace websockets2_generic
{
  namespace network2_generic
  {
    typedef GenericEspTcpClient<WiFiClient> Esp8266TcpClient;
    
    class SecuredEsp8266TcpClient : public GenericEspTcpClient<WiFiClientSecure> 
    {
      public:
        void setInsecure() 
        {
          this->client.setInsecure();
        }
    
        void setFingerprint(const char* fingerprint) 
        {
          this->client.setFingerprint(fingerprint);
        }
    
        void setClientRSACert(const X509List *cert, const PrivateKey *sk) 
        {
          this->client.setClientRSACert(cert, sk);
        }
    
        void setTrustAnchors(const X509List *ta) 
        {
          this->client.setTrustAnchors(ta);
        }
    
    };
    
    #define DUMMY_PORT 0
    
    class Esp8266TcpServer : public TcpServer 
    {
      public:
        Esp8266TcpServer() : server(DUMMY_PORT) {}
        
        bool poll() override 
        {
          yield();
          return server.hasClient();
        }
    
        bool listen(const uint16_t port) override 
        {
          yield();
          server.begin(port);
          return available();
        }
    
        TcpClient* accept() override 
        {
          while (available()) 
          {
            yield();
            auto client = server.available();
            
            if (client) 
              return new Esp8266TcpClient{client};
          }
          return new Esp8266TcpClient;
        }
    
        bool available() override 
        {
          yield();
          return server.status() != CLOSED;
        }
    
        void close() override 
        {
          yield();
          server.close();
        }
    
        virtual ~Esp8266TcpServer() 
        {
          if (available()) close();
        }
    
      protected:
        int getSocket() const override 
        {
          return -1;
        }
    
      private:
        WiFiServer server;
    };
  }   // namespace network2_generic
}     // namespace websockets2_generic
#endif // #ifdef ESP8266 