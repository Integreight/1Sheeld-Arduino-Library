#ifndef LiquidCrystalShield_h
#define LiquidCrystalShield_h


#include <inttypes.h>


#define LCD_SHIELD_ID     0x32

// Library functions commands---fayez
#define PRINT 0x01
#define BEGIN 0x02
#define CLEAR 0x03
#define HOME 0x04
#define NO_DISPLAY 0x05
#define DISPLAY_LCD 0x06
#define NO_BLINK 0x07
#define BLINK 0x08
#define NO_CURSOR 0x09
#define CURSOR 0x0A
#define SCROLL_DISPLAY_LEFT 0x0B
#define SCROLL_DISPLAY_RIGHT 0x0C
#define LEFT_TO_RIGHT 0x0D
#define RIGHT_TO_LEFT 0x0E
#define CREATE_CHAR 0x0F
#define SET_CURSOR 0x10
#define WRITE 0x11
#define NO_AUTO_SCROLL 0x12
#define AUTO_SCROLL 0x13 

#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00


class LiquidCrystalShield {

public:
  LiquidCrystalShield();
 
    
  void begin(char cols, char rows, char charsize = LCD_5x8DOTS);

  void clear();
  void home();

  void noDisplay();
  void display();
  void noBlink();
  void blink();
  void noCursor();
  void cursor();
  void scrollDisplayLeft();
  void scrollDisplayRight();
  void leftToRight();
  void rightToLeft();
  void autoscroll();
  void noAutoscroll();

  void createChar(char, char[]);
  void setCursor(char, char); 
  void write(char);
  void print (char* data);
 
 private:
  void writePacket (char functionCommand, char* data);
  char _begin_packet[3];
  char _setCursor_packet[2];
  char _createChar_packet[9];
  char _write_packet[1];
  
  
};
 extern LiquidCrystalShield LCD;
#endif
