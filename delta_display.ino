#include <UTFT.h>

// BOM
// 2.4 display
// arduino nano 

// Important fonts, the world needs good fonts. 
extern uint8_t SmallFont [];
extern uint8_t BigFont [];
extern uint8_t SevenSegNumFont [];

UTFT myGLCD (ITDB28,38,39,40,41); 

void setup ()
{
  myGLCD.InitLCD ();
  myGLCD.clrScr ();
}

void loop ()
{
  myGLCD.setColor (255,0,0);
  myGLCD.setBackColor (0,0,0);
  myGLCD.setFont (BigFont);
  myGLCD.print ("DeltaDiag", CENTER, 20);
  myGLCD.print ("OO == [] [] == OO", CENTER, 60);
  myGLCD.setColor (255, 255, 255);
  myGLCD.setFont (SmallFont);
  myGLCD.print ("Boost pressure is $", CENTER, 110);
  myGLCD.print ("Outdoor temp is", CENTER, 122);
  myGLCD.setColor (255, 255, 255);
  myGLCD.setFont (BigFont);
  myGLCD.print ("Volt", LEFT, 172);
  myGLCD.print ("Temp", RIGHT, 172);
  myGLCD.setColor (255, 240, 0);
  myGLCD.setFont (SevenSegNumFont);
  myGLCD.print ("123", LEFT, 190);
  myGLCD.print ("177", RIGHT, 190);
  while (1) {}; // do nothing
}
