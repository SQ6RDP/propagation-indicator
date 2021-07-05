![photo_2021-03-22_19-28-19](https://user-images.githubusercontent.com/81185184/112064903-031aa380-8b64-11eb-93ca-15cc88de22ea.jpg)
# propagation-indicator

How it works:
![obraz](https://user-images.githubusercontent.com/81185184/112226786-ee571200-8c2e-11eb-981a-562b58530ab1.png)

How to read leds:

![obraz](https://user-images.githubusercontent.com/81185184/112227525-1bf08b00-8c30-11eb-84cd-57802c8dbb53.png)


Ham Radio weather station Propagation indicator - reading from https://www.hamqsl.com/solar.html and indicating propagation condition into RGB LED and Oled. Conection via eth or WIFI based on ESP8266 or ESP32. Please help me with development if You see some potential.


[22.03.21 22:17]
Gdyby ktoś coś chciał dodać to POPROSZĘ NA PRV
w planie:
- Duży ładny zegarek sync z sieci albo GPS
- Alerty z DX Robot: https://amunters.home.xs4all.nl/index.html
- wartości oraz Trendy parametrów Ka index A index SunSpot SolarFlux index .... ewentualnie innych
- może odczyt danych via CAT
- jeden duży wyświetlacz? Jaki? (duże OLEDY były drogie, użyłem 4 mniejsza, może ich być nawet 10)

20210705:
add PSKREPORTER:
https://retrieve.pskreporter.info/query?receiverCallsign=SP6PWT&frange=144000000-145000000&rronly=true&flowStartSeconds=-7200&distance=true
