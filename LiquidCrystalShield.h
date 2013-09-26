#ifndef LiquidCrystalShield_h
#define LiquidCrystalShield_h


#include <inttypes.h>


#define LCD_SHIELD_ID     0x64

// Library functions commands---fayez
#define INIT 0xA0
#define BEGIN 0xA1
#define CLEAR 0xA2
#define HOME 0xA3
#define NO_DISPLAY 0xA4
#define DISPLAY_LCD 0xA5
#define NO_BLINK 0xA6
#define BLINK 0xA7
#define NO_CURSOR 0xA8
#define CURSOR 0xA9
#define SCROLL_DISPLAY_LEFT 0xAA
#define SCROLL_DISPLAY_RIGHT 0xAB
#define LEFT_TO_RIGHT 0xAC
#define RIGHT_TO_LEFT 0xAD
#define CREATE_CHAR 0xAE
#define SET_CURSOR 0xAF
#define WRITE 0xB0
#define COMMAND 0xB1
#define NO_AUTO_SCROLL 0xB2
#define AUTO_SCROLL 0xB3 

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

// baudrate for softwareSerial port
#define BAUD_RATE 57600

// Library functions commands---fayez
#define begin_fn 0xA1
#define clear_fn 0xA2
#define home_fn 0xA3
#define noDisplay_fn 0xA4
#define display_fn 0xA5
#define noBlink_fn 0xA6
#define blink_fn 0xA7
#define noCursor_fn 0xA8
#define cursor_fn 0xA9
#define scrollDisplayLeft_fn 0xAA
#define scrollDisplayRight_fn 0xAB
#define leftToRight_fn 0xAC
#define rightToLeft_fn 0xAD
#define createChar_fn 0xAE
#define setCursor_fn 0xAF
#define write_fn 0xB0
#define command_fn 0xB1
#define noAutoscroll_fn 0xB2
#define autoscroll_fn 0xB3 

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
  void command(char);
  
 // using Print::write;

 private:
  void writePacket (char functionCommand, char* data);
  char _data_pins[8];
  char _init_packet[12];
  char _begin_packet[3];
  char _setCursor_packet[2];
  char _createChar_packet[9];
  char _command_packet[1];
  char _write_packet[1];
  
};
 extern LiquidCrystalShield LCD;
#endif
