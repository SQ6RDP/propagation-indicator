void wyswietlacz () {



  display.clear();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  //obszar wysiwtlacza
  //             ("......**********);
  display.println("      *22222222*"); //to nie zostanie wyświetlone
  display.println("      1234567890");//to nie zostanie wyświetlone
  //                     * xxxxxxx *"
  display.println("      * indykator *");
  display.println("                ");
  display.println("      propagacji");
  display.println("                ");
  display.print("      ");
  display.print(WiFi.RSSI());
  display.println(" [dBm]");
  //display.println("    ");
  //display.println(WiFi.localIP());
  display.println("      SQ6RDP");
  //  display.setTextSize(1);
  //  display.setCursor(0,30);
  //  display.println("cccc");
  display.update();
  delay(12000);

}
