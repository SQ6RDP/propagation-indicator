#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Adafruit_NeoPixel.h> // do pbsługi LEDow neopixel
#include <Adafruit_ssd1306syp.h> // do wyswietlacz
//#include <SSD1306.h>
#define SDA_PIN 4 //piny do wyswietlacza
#define SCL_PIN 5 //piny do wyswietlacza

Adafruit_ssd1306syp display(SDA_PIN, SCL_PIN);

//const char* ssid = "ssid";
const char* ssid = "SSID_my_WIFI";
const char* password = "password_wifi";



long liczniczek = 0;

#define PIN D8


// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(55, PIN, NEO_GRB + NEO_KHZ800);




String day_80m_40m;
String day_30m_20m;
String day_17m_15m;
String day_12m_10m;
String night_80m_40m;
String night_30m_20m;
String night_17m_15m;
String night_12m_10m;

//phenomen E-SKIP
String northern_hemi;
String europe;
String north_america;
String europe_6m;
String europe_4m;
String europe2mOLED;

//parametry do wyswietlacza oled
String updated;
String solarflux;
String aindex;
String kindex;
String sunspots;
String xray;
String updatedTime;
String hhupdated;
String mmupdated;





void setup () {

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  delay(1000);
  display.initialize();
  delay(1000);
  //neopixel LEDs
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  wyswietlacz();
  //zapal tęczę
  /*
    //strip.setPixelColor(n, red, green, blue);
    strip.setPixelColor(0, 0, 0, 1); //niebieski
    strip.setPixelColor(1, 0, 1, 0); //zielony
    strip.setPixelColor(2, 0, 1, 1); //niebiesko zielony
    strip.setPixelColor(3, 1, 0, 0); //czerwony
    strip.setPixelColor(4, 1, 0, 1);  //fioletowy
    strip.setPixelColor(5, 1, 1, 0); //zolty
    strip.setPixelColor(6, 1, 1, 1); //bialy
    strip.setPixelColor(7, 0, 0, 1); //niebieski
    strip.show();
  */





  strip.setPixelColor(0, 1, 1, 1); //bialy
  strip.setPixelColor(1, 0, 0, 1); //niebieski
  strip.setPixelColor(2, 1, 1, 1); //bialy
  strip.setPixelColor(3, 0, 1, 0); //zielony
  strip.setPixelColor(4, 1, 1, 1); //bialy
  strip.setPixelColor(5, 0, 1, 1); //niebiesko zielony
  strip.setPixelColor(6, 1, 1, 1); //bialy
  strip.setPixelColor(7, 1, 0, 0); //czerwony
  strip.setPixelColor(8, 1, 1, 1); //bialy
  strip.setPixelColor(9, 1, 0, 1);  //fioletowy
  strip.setPixelColor(10, 1, 1, 1); //bialy
  strip.setPixelColor(11, 1, 1, 0); //zolty
  strip.setPixelColor(12, 1, 1, 1); //bialy


  strip.show();


  while (WiFi.status() != WL_CONNECTED) {

    delay(1000);
    Serial.println("Connecting..");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    for (int f = 0; f < 13; f++) //zgas wszystkie
    {

      strip.setPixelColor(f, 0, 0, 0);
      strip.show();

    }

    delay (1000);
    for (int f = 0; f < 13; f++) //zapal wszytskie na biało
    {

      strip.setPixelColor(f, 1, 1, 1);
      strip.show();
      delay(25);

    }

    delay(1000);







    /*

    */


  }




}

void loop() {

  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status

    HTTPClient http;  //Declare an object of class HTTPClient

    http.begin("http://www.hamqsl.com/solarxml.php");  //Specify request destination
    int httpCode = http.GET();                                                                  //Send the request

    if (httpCode > 0) { //Check the returning code

      String payload = http.getString();   //Get the request response payload
      //int httpCode = http.GET(); // a czy można tego uzyc ???
      //Serial.println(payload);                     //Print the response payload // tu wyswietla calego XMLA !!!
      /// badanie długosci

      //int num = sizeof(payload);


      //Serial.print("String length is: ");
      //Serial.println(sizeof(payload));
      //Serial.println(payload.lenght());






      //
      //PARSOWACZKA
      //

      int P;
      int K;
      //to tylko przykład
      /*
             //<band name="80m-40m" time="day">Fair</band>
            P = payload.indexOf("80m-40m") + 20;
            K = payload.indexOf("</band>", P);
            day_80m_40m = payload.substring(P, K);
            Serial.print("80m-40m_day: ");
            Serial.println(day_80m_40m);
      */

      //<updated> 20 Mar 2018 1921 GMT</updated>

      P = payload.indexOf("<updated>") + 9;
      K = payload.indexOf("</updated>");
      updated = payload.substring(P, K);
      Serial.print("updated :");
      Serial.println(updated);


      //<solarflux>69</solarflux>

      int solarflux_P = payload.indexOf("<solarflux>") + 11;
      int solarflux_K = payload.indexOf("</solarflux>");
      solarflux = payload.substring(solarflux_P, solarflux_K);
      Serial.print("solarflux: ");
      Serial.println(solarflux);

      //<aindex> 16</aindex>

      int aindex_P = payload.indexOf("<aindex>") + 8;
      int aindex_K = payload.indexOf("</aindex>");
      aindex = payload.substring(aindex_P, aindex_K);
      Serial.print("aindex: ");
      Serial.println(aindex);

      //<kindex> 2</kindex>
      P = payload.indexOf("<kindex>") + 8;
      K = payload.indexOf("</kindex>");
      kindex = payload.substring(P, K);
      Serial.print("kindex: ");
      Serial.println(kindex);

      //<kindexnt>No Report</kindexnt>
      P = payload.indexOf("<kindexnt>") + 10;
      K = payload.indexOf("</kindexnt>");
      String kindexnt = payload.substring(P, K);
      Serial.print("kindexnt: ");
      Serial.println(kindexnt);

      //<xray> A2.0   </xray>
      P = payload.indexOf("<xray>") + 6;
      K = payload.indexOf("</xray>");
      xray = payload.substring(P, K);
      Serial.print("xray: ");
      Serial.println(xray);


      //<sunspots>0</sunspots>
      P = payload.indexOf("<sunspots>") + 10;
      K = payload.indexOf("</sunspots>");
      sunspots = payload.substring(P, K);
      Serial.print("sunspots: ");
      Serial.println(sunspots);
      // <heliumline> 94.4</heliumline>
      // <protonflux>2.22e-01</protonflux>
      // <electonflux>8.80e+03</electonflux>
      // <aurora> 1</aurora>
      //<normalization>1.99</normalization>
      //<latdegree>67.5</latdegree>
      //<solarwind>414.6</solarwind>
      //<magneticfield>  1.8</magneticfield>
      //<calculatedconditions>

      //<band name="80m-40m" time="day">Fair</band>
      P = payload.indexOf("80m-40m") + 20;
      K = payload.indexOf("</band>", P);
      day_80m_40m = payload.substring(P, K);
      Serial.print("80m-40m_day: ");
      Serial.println(day_80m_40m);

      //<band name="30m-20m" time="day">Poor</band>
      P = payload.indexOf("30m-20m") + 20;
      K = payload.indexOf("</band>", P);
      day_30m_20m = payload.substring(P, K);
      Serial.print("30m-20m_day: ");
      Serial.println(day_30m_20m);


      //<band name="17m-15m" time="day">Poor</band>
      P = payload.indexOf("17m-15m") + 20;
      K = payload.indexOf("</band>", P);
      day_17m_15m = payload.substring(P, K);
      Serial.print("17m-15m_day: ");
      Serial.println(day_17m_15m);

      //<band name="12m-10m" time="day">Poor</band>

      P = payload.indexOf("12m-10m") + 20;
      K = payload.indexOf("</band>", P);
      day_12m_10m = payload.substring(P, K);
      Serial.print("12m-10m_day: ");
      Serial.println(day_12m_10m);

      //
      // test - NOC
      //

      // <band name="80m-40m" time="night">Good</band>

      P = payload.lastIndexOf("80m-40m") + 22;
      K = payload.indexOf("</band>", P);
      night_80m_40m = payload.substring(P, K);
      Serial.print("80m-40m_night: ");
      Serial.println(night_80m_40m);
      //<band name="30m-20m" time="night">Poor</band>

      P = payload.lastIndexOf("30m-20m") + 22;
      K = payload.indexOf("</band>", P);
      night_30m_20m = payload.substring(P, K);
      Serial.print("30m-20m_night: ");
      Serial.println(night_30m_20m);


      //<band name="17m-15m" time="night">Poor</band>


      P = payload.lastIndexOf("17m-15m") + 22;
      K = payload.indexOf("</band>", P);
      night_17m_15m = payload.substring(P, K);
      Serial.print("17m-15m_night: ");
      Serial.println(night_17m_15m);


      //<band name="12m-10m" time="night">Poor</band>


      P = payload.lastIndexOf("12m-10m") + 22;
      K = payload.indexOf("</band>", P);
      night_12m_10m = payload.substring(P, K);
      Serial.print("12m-10m_night: ");
      Serial.println(night_12m_10m);


      //
      //phenomenons:
      //


      //<phenomenon name="vhf-aurora" location="northern_hemi">Band Closed</phenomenon>
      P = payload.lastIndexOf("northern_hemi") + 15;
      K = payload.indexOf("</phenomenon>", P);
      northern_hemi = payload.substring(P, K);
      Serial.print("2m northern_hemi: ");
      Serial.println(northern_hemi);

      //<phenomenon name="E-Skip" location="europe">Band Closed</phenomenon>
      P = payload.lastIndexOf("europe") + 11;
      K = payload.indexOf("</phenomenon>", P);
      europe = payload.substring(P, K);
      Serial.print("2m europe: ");
      Serial.println(europe);

      //<phenomenon name="E-Skip" location="north_america">Band Closed</phenomenon>
      P = payload.lastIndexOf("north_america") + 15;
      K = payload.indexOf("</phenomenon>", P);
      north_america = payload.substring(P, K);
      Serial.print("2m north_america: ");
      Serial.println(north_america);

      //<phenomenon name="E-Skip" location="europe_6m">Band Closed</phenomenon>
      P = payload.lastIndexOf("europe_6m") + 11;
      K = payload.indexOf("</phenomenon>", P);
      europe_6m = payload.substring(P, K);
      Serial.print("europe_6m: ");
      Serial.println(europe_6m);

      //<phenomenon name="E-Skip" location="europe_4m">Band Closed</phenomenon>
      P = payload.lastIndexOf("europe_4m") + 11;
      K = payload.indexOf("</phenomenon>", P);
      europe_4m = payload.substring(P, K);
      Serial.print("europe_4m: ");
      Serial.println(europe_4m);

      //Dodatkowe parsowanie czasu
      //updated : 19 May 2018 2117 GMT

      P = updated.indexOf("GMT") - 5;
      K = updated.indexOf("GMT") - 3;
      hhupdated = updated.substring(P, K);
      Serial.print("updated hh: ");
      Serial.println(hhupdated);

      P = updated.indexOf("GMT") - 3;
      K = updated.indexOf("GMT") - 1;
      mmupdated = updated.substring(P, K);
      Serial.print("updated mm: ");
      Serial.println(mmupdated);

      updatedTime = hhupdated + ":" + mmupdated;

      //oled - 2m substring special
      //P = europe2mOLED.lastIndexOf("europe") + 11;
      //K = europe2mOLED.indexOf("</phenomenon>", P);
      //europe2mOLED = europe.replace('band');
      if (europe.indexOf("Band Closed") >= 0) {
        Serial.print("2m Europa bad Closed!  => ");
        europe2mOLED = "Closed";
      }

      if (europe.indexOf("MUF") >= 0) {
        Serial.print("2m Europa MUF!  => ");
        europe2mOLED = "MUF";
      }
      if (europe.indexOf("ES") >= 0) {
        Serial.print("2m Europa MUF!  => ");
        europe2mOLED = "ES";
      }

      //else {
        //europe2mOLED = europe;
      //}


      Serial.print("2m europe: ");
      Serial.println(europe2mOLED);


    }

    else {
      Serial.print("Brak interetu");
      for (int f = 0; f < 13; f++) //zapal wszytskie na biało

      {
        strip.setPixelColor(f, 1, 1, 1);
        strip.show();


        delay(1000);
      }

      for (int f = 0; f < 13; f++) //zapal wszytskie na biało

      {
        strip.setPixelColor(f, 0, 0, 0);
        strip.show();


        delay(1000);
      }
      goto braksieci;
    }








    http.end();   //Close connection

    /*
      Poor
      Fair
      Good
      80m_40m_day: Fair
      30m_20m_day: Poor
      17m_15m_day: Poor
      12m_10m_day: Poor
      80m_40m_night: Good
      30m_20m_night: Poor
      17m_15m_night: Poor
      12m_10m_night: Poor
    */

  }





  Serial.println(" ");
  Serial.println("end of data");
  Serial.println("wait...30s - 5m ");
  Serial.print("odczytano: ");
  Serial.println(liczniczek);
  Serial.print("Power of Wifi signal: ");
  Serial.print(WiFi.RSSI());
  Serial.println(" [dBm]");
  liczniczek ++;
  //zapal(1, night_80m_40m);

  //inne zapalamnie
  /*
    for(int f = 0; f<13; f++) //zgas wszystkie w celu uzyskania pulsu
      {

        strip.setPixelColor(f, 0, 0, 0);
        strip.show();
        //delay(1);
        Serial.println("zagas");
        }
  */

  zapal2(0, day_80m_40m);
  zapal2(1, day_30m_20m);
  zapal2(2, day_17m_15m);
  zapal2(3, day_12m_10m);
  zapal2(4, night_80m_40m);
  zapal2(5, night_30m_20m);
  zapal2(6, night_17m_15m);
  zapal2(7, night_12m_10m);
  zapal2(8, northern_hemi);
  zapal2(9, europe);
  zapal2(10, north_america);
  zapal2(11, europe_6m);
  zapal2(12, europe_4m);

  Serial.println("wywołano funkcje zapal");

  /*
    String updated;
    String solarflux;
    String aindex;
    String lindex;
    String sunspots;
  */
  //wyswietlWarunki
  wyswietlWarunki(europe2mOLED, solarflux, aindex, kindex, sunspots, updatedTime );


  delay(300000);    //Send a request every 30 seconds
  delay(15000);
  delay(300000);    //Send a request every 30 seconds
  
  Serial.println(" ");
  Serial.println("Reading... ");


  //tylko testowo
  //delay(6000);




braksieci:
  Serial.println("No Wifi  network, please wait... ");
  OLED_brak_sieci();


}

//ekran powitalny





