void zapal2 (int indexOfLED, String pasmo) {


  //testowo zapal na niebiesko
  strip.setPixelColor(indexOfLED, 0, 0, 1); //zapala na NIEBIESKO albo czarno
  strip.show();
  delay(20);


  if (pasmo == "Good") {
    strip.setPixelColor(indexOfLED, 0, 5, 0); //zapala na zielono
    strip.show();
    delay(5);
  }
  if (pasmo == "Fair") {
    strip.setPixelColor(indexOfLED, 2, 1, 0); //zapala na zolto
    strip.show();
    delay(5);
  }
  if (pasmo == "Poor") {
    strip.setPixelColor(indexOfLED, 1, 0, 0); //zapala
    strip.show();
    delay(5);
  }
  if (pasmo == "Band Closed") {
    strip.setPixelColor(indexOfLED, 1, 0, 0); //zapala
    strip.show();
    delay(5);

  }
/*
  if (pasmo == "High MUF") { //mus sporadic albo coś innego - to trzeba uzupelnic
    strip.setPixelColor(indexOfLED, 0, 1, 1); //zapala
    strip.show();
    delay(5);
  }
*/
  if (pasmo == "50MHz ES") { //mus sporadic albo coś innego - to trzeba uzupelnic
    strip.setPixelColor(indexOfLED, 0, 0, 25); //zapala
    strip.show();
    delay(5);
  }
  if (pasmo == "70MHz ES") { //mus sporadic albo coś innego - to trzeba uzupelnic
    strip.setPixelColor(indexOfLED, 0, 0, 25); //zapala
    strip.show();
    delay(5);
  }
  if (pasmo == "144MHz ES") { //mus sporadic albo coś innego - to trzeba uzupelnic
    strip.setPixelColor(indexOfLED, 0, 0, 25); //zapala o
    strip.show();
    delay(5);
  }


//dodc MID LAT AUR <phenomenon name="vhf-aurora" location="northern_hemi">MID LAT AUR</phenomenon>
    if (pasmo == "MID LAT AUR") { //mus sporadic albo coś innego - to trzeba uzupelnic
    strip.setPixelColor(indexOfLED, 0, 3, 2); //zapala o
    strip.show();
    delay(5);
  }

  
// High LAT AUR
    if (pasmo == "High LAT AUR") { //mus sporadic albo coś innego - to trzeba uzupelnic
    strip.setPixelColor(indexOfLED, 3, 0, 3); //zapala o
    strip.show();
    delay(5);
  }
// High MUF (2M only)
    if (pasmo == "High MUF (2M only)") { //mus sporadic albo coś innego - to trzeba uzupelnic
    strip.setPixelColor(indexOfLED, 3, 0, 3); //zapala o
    strip.show();
    delay(5);
  }


  
//High MUF
    if (pasmo == "High MUF") { //mus sporadic albo coś innego - to trzeba uzupelnic
    strip.setPixelColor(indexOfLED, 3, 0, 3); //zapala o
    strip.show();
    delay(5);
  }






}
