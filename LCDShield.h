#ifndef LCDShield_h
#define LCDShield_h
#define BEGIN 0x01
#define CLEAR 0x02
#define HOME  0x03
#define NODISPLAY 0x04
#define DISPLAY   0x05
#define NOBLINK  0x06
#define BLINK	  0x07
#define NOCURSOR  0x08
#define CURSOR    0x09
#define SCROLLLEFT 0x0A
#define SCROLLRIGHT 0x0B
#define LEFT_RIGHT  0x0C
#define RIGHT_LEFT  0x0D
#define AUTOSCROLL	0x0E
#define NOAUTOSCROLL 0x0F 
#define CREATECHAR 	 0x10
#define SETCURSOR 	 0x11
#define WRITE 		 0x12
#define PRINT 		 0x13
class LCDShield
{
public:
	void begin(byte,byte);
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
	void autoScroll();
	void noAutoScroll();
	void createChar(byte ,char *);
	void setCursor(byte,byte);
	void write(byte);
	void print(char*);
private:

};

extern LCDShield LCD;
#endif