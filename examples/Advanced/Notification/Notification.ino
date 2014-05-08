/*
Example illustrates sensing the tmperature of the room and sending 
a Notification to your phone if it exceeded a certain value
*/

/*Inlcude OneSheeld Library*/
#include <OneSheeld.h>

/*Reserve boolean*/
boolean phoneNotified=false;
void setup()
{
	/*Start Communication on baudrate 57600*/
	OneSheeld.begin();
}

void loop()
{
	/*Always get the temperature*/
	if(TemperatureSensor.getValue()>25)
	{
		/*Check if the Phone is Notified Once*/
		if(phoneNotified==false)
		{
			/*Notify the Phone*/
			Notification.notifyPhone("Room Temperature incereased");
			/*Reset the variable*/
			phoneNotified=true;
		}
		
	}
}
