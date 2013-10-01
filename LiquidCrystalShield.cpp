#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "HardwareSerial.h"
#include "OneSheeld.h"
#include "Arduino.h"
#include "LiquidCrystalShield.h"

// When the display powers up, it is configured as follows:
//
// 1. Display clear
// 2. Function set: 
//    DL = 1; 8-bit interface data 
//    N = 0; 1-line display 
//    F = 0; 5x8 dot character font 
// 3. Display on/off control: 
//    D = 0; Display off 
//    C = 0; Cursor off 
//    B = 0; Blinking off 
// 4. Entry mode set: 
//    I/D = 1; Increment by 1 
//    S = 0; No shift 
//
// Note, however, that resetting the Arduino doesn't reset the LCD, so we
// can't assume that its in that state when a sketch starts (and the
// LiquidCrystal constructor is called).

LiquidCrystalShield::LiquidCrystalShield(){}

void LiquidCrystalShield::begin(char cols, char lines, char dotsize) {
  // send the args with firmata protocol
  _begin_packet[0]=cols;
  _begin_packet[1]=lines;
  _begin_packet[2]=dotsize;
 OneSheeld.write(LCD_SHIELD_ID,BEGIN,_begin_packet,3);
}

/********** high level commands, for the user! */
void LiquidCrystalShield::clear()
{
 writePacket(CLEAR,0); 
}

void LiquidCrystalShield::home()
{
 writePacket(HOME,0); 
}

void LiquidCrystalShield::setCursor(char col, char row)
{
  _setCursor_packet[0]=col;
  _setCursor_packet[1]=row;
  OneSheeld.write(LCD_SHIELD_ID,SET_CURSOR,_setCursor_packet,2);  
}

// Turn the display on/off (quickly)
void LiquidCrystalShield::noDisplay() {
 writePacket(NO_DISPLAY,0); 
}
void LiquidCrystalShield::display() {
 writePacket(DISPLAY_LCD,0); 
}

// Turns the underline cursor on/off
void LiquidCrystalShield::noCursor() {
 writePacket(NO_CURSOR,0); 
}
void LiquidCrystalShield::cursor() {
 writePacket(CURSOR,0); 
}

// Turn on and off the blinking cursor
void LiquidCrystalShield::noBlink() {
 writePacket(NO_BLINK,0); 
}
void LiquidCrystalShield::blink() {
 writePacket(BLINK,0); 
}

// These commands scroll the display without changing the RAM
void LiquidCrystalShield::scrollDisplayLeft(void) {
writePacket(SCROLL_DISPLAY_LEFT,0); 
}
void LiquidCrystalShield::scrollDisplayRight(void) {
 writePacket(SCROLL_DISPLAY_RIGHT,0); 
}

// This is for text that flows Left to Right
void LiquidCrystalShield::leftToRight(void) {
  writePacket(LEFT_TO_RIGHT,0); 
}

// This is for text that flows Right to Left
void LiquidCrystalShield::rightToLeft(void) {
  writePacket(RIGHT_TO_LEFT,0); 
}

// This will 'right justify' text from the cursor
void LiquidCrystalShield::autoscroll(void) {
 writePacket(AUTO_SCROLL,0); 
}

// This will 'left justify' text from the cursor
void LiquidCrystalShield::noAutoscroll(void) {
 writePacket(NO_AUTO_SCROLL,0); 
}

// Allows us to fill the first 8 CGRAM locations
// with custom characters
void LiquidCrystalShield::createChar(char location, char charmap[]) {
  
  _createChar_packet[0]=location;
  for (int i=0;i<8;i++)
  {
  _createChar_packet[i+1]=charmap[i];
  }
 OneSheeld.write(LCD_SHIELD_ID,CREATE_CHAR,_createChar_packet,9);  
}

/*********** mid level commands, for sending data/cmds */
void LiquidCrystalShield::write(char value) {
 _write_packet[0]=value;
OneSheeld.write(LCD_SHIELD_ID,WRITE,_write_packet,1);
}
void LiquidCrystalShield::print (char* data)
{
writePacket(PRINT,data);
}
/************ low level data pushing commands **********/
void LiquidCrystalShield::writePacket (char functionCommand , char* data)
{

  OneSheeld.write(LCD_SHIELD_ID,functionCommand,data);
}

LiquidCrystalShield LCD;