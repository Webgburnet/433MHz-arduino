#include <VirtualWire.h>

    //Grove - 315(433) RF link kit Demo v1.0
    //by :http://www.seeedstudio.com/
    //connect the sent module to D2 to use  
    #include <VirtualWire.h>

    int RF_TX_PIN = 2;
    String envoie="";
    
    void setup()
    {
      Serial.begin(9600);
      vw_set_tx_pin(RF_TX_PIN); // Setup transmit pin
      vw_setup(2000); // Transmission speed in bits per second.
      Serial.println("L'émetteur ne peut envoyer que 26 symboles à la fois.");
    }

    void loop()
    {
      if(Serial.available()>0)
      {
        envoie=Serial.readString();
        Serial.println(envoie);

        if (envoie.length() != 0) //Regarder si le String contient des données différentes de 0
        {
          char *p = const_cast<char*>(envoie.c_str()); //conversion du String en un pointeur de type char
          vw_send((uint8_t *)p, strlen(p)); // Envoie des données via le module transmetteur 433MHz
        }
      }
    }
