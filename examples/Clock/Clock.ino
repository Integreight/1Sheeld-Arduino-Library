/*
Example illustrates the Clock Shield by always getting the date 
and time and when it is similar to a certain date send me SMS 
whishing me a HappYBirthdaY and update my status in FaceBook
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Reserving variables to get the time (hours-minutes-seconds)*/
/*and the Date (day-month)*/
byte hours;
byte minutes;
byte seconds;
byte day;
byte month;
short year;

void setup ()
{
  /*Start UART communication on baudrate 57600*/
  OneSheeld.begin();
  /*Start the Clock Shield*/
  Clock.begin();
}

void loop () 
{
  /*Always get the Date and Time*/
  hours=Clock.getHours();
  minutes=Clock.getMinutes();
  seconds=Clock.getSeconds();
  day=Clock.getDay();
  month=Clock.getMonth();
  year=Clock.getYear();
  
  /*Check if the date is similar to my birthday date send me a*/
  /*whishing birthday SMS at 3PM that day*/
  if(hours==15&&minutes==00&&seconds==00&&day==06&&month==02&&year==2014)
  {
    /*Send me SMS*/
    SMS.send("+201286077028","HappY BirTH daY :D from OneSheeld");
    /*Update my Facebook Status*/ 
    Facebook.updateStatus("Today is My BirthDay :D ");
  }
} 
