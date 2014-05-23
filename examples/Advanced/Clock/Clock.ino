/*
Example illustrates always getting the date and time and when 
it is a certain date send a SMS whishing a HappYBirthdaY and 
update status on FaceBook
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
  /*Start Communication*/
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
  
  /*Check if the date is my birthday date send me the */
  /*SMS at 3PM that day*/
  if(hours==15&&minutes==0&&seconds==0&&day==6&&month==2&&year==2014)
  {
    /*Send me SMS*/
    SMS.send("+201286077028","HappY BirTH daY :D from OneSheeld");
    /*Update my Facebook Status*/ 
    Facebook.updateStatus("iT's My BirthDay :D ");
  }
} 
