void wyswietlWarunki (String L1, String L2, String L3, String L4, String L5, String L6) {

  //void zapal2 (int indexOfLED, String pasmo) {

  const char *linia1 = L1.c_str();
  const char *linia2 = L2.c_str();
  const char *linia3 = L3.c_str();
  const char *linia4 = L4.c_str();
  const char *linia5 = L5.c_str();
  const char *linia6 = L6.c_str();


  //updated


  Serial.println("void wyswietlWarunki (String L) jestesmy w fubkcji{");
  Serial.println("updated: ");
  Serial.print(updated);


  display.clear();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  //obszar wysiwtlacza
  //             ("......**********);
  display.println("      *22222222*"); //to nie zostanie wyświetlone
  display.println("      1234567890");//to nie zostanie wyświetlone
  //                     * +++++ *"


  //display.println("23456 3.620 Mhz");
  //display.println(linia1);
  //display.println("23456 LSB 150W");
  //display.println(linia2);
  display.println("23456     -1- ");
  display.println("23456 czy radio ");
  display.println("23456 stacja jest");
  display.println("23456 ustawiona ? ");
  display.println("23456  ");
  display.println("23456 TAK    NIE");
  //display.println(linia6);


  display.update();

}
