void OLED_brak_sieci () {



  display.clear();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  //obszar wysiwtlacza
  //             ("......**********);
  display.println("      *22222222*"); //to nie zostanie wyświetlone
  display.println("      1234567890");//to nie zostanie wyświetlone
  //                     * SQ6+++ *"
  display.println("      * - - - *");
  display.println("      BRAK SIECI");
  display.print("      ");
  display.print(WiFi.RSSI());
  display.println(" [dBm]");
  display.print("    ");
  display.println(WiFi.localIP());
  //  display.setTextSize(1);
  //  display.setCursor(0,30);
  //  display.println("cccc");
  display.update();

}
