#include <OneSheeld.h>

void setup(){
	// Initialize 1Sheeld
	OneSheeld.begin(57600);
	// Call a specific function when a Keypad button is clicked
	Keypad.setOnButtonChange(&onButtonChange);
}

void loop(){
	//Do nothing
}

void onButtonChange(int row, int col){
	//Notify The phone back when a button is pressed
    String msg="Button cliked, row="+row;+", col="+col;
	Notification.notifyPhone(msg);
}