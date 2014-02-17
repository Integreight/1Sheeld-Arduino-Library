#include <OneSheeld.h>

void setup(){
	// Initialize 1Sheeld
	OneSheeld.begin();
	pinMode(3,INPUT);
}

void loop(){
  	if(digitalRead(3)==HIGH){
  		// Print "Hello World!"
		LCD.print("Hello, World!");
		// Set the curson to the second row and the fourth column
		LCD.setCursor(2,4);
		// Print "From 1Sheeld"
		LCD.print("From 1Sheeld");
	}
}





