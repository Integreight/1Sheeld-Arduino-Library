/*

Voice Recognition Shield Example

This example shows an application on 1Sheeld's voice recognition shield.

By using this example, you can control the light intensity of a LED using
voice commands.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_VOICE_RECOGNIZER_SHIELD
#define INCLUDE_TERMINAL_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Counters and iterators. */ 
int stringIterator = 0;
int counter = 0;
/* A name for the LED on pin 11. */
int ledPin = 11;
/* Value from voice command. */
int speechValue = 0;
/* Parsing values. */
int newLedValue = 0;
int oldLedValue = 0;
/* String holders. */
char *voiceCommand;
char integerString[4];
/* Booleans. */
bool makeFlag = false;
bool decreaseFlag = false;
bool increaseFlag = false;



void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set ledPin as output. */
  pinMode(ledPin,OUTPUT);
}

void loop() 
{
  getCommand();
  /* Convert number from string to integer. */ 
  speechValue=atoi(integerString);  
  /* Map the value 0 --> 100 to 0 --> 255. */
  newLedValue = map(speechValue,0,100,0,255);
  /* Check flags. */
  if(makeFlag && counter!=0)
  {
    /* Set the value to ledPin. */
    analogWrite(ledPin,newLedValue);
    makeFlag=false;
    oldLedValue=newLedValue;
    newLedValue=0;
  }
  else if(increaseFlag && counter!=0)
  {
    /* Increase new value. */
    newLedValue=oldLedValue+newLedValue;
    /* Set resolution. */
    if(newLedValue > 250)
    {
      newLedValue= 255;
    }
    /* Terminal shield is used for debugging. */
    Terminal.print("increased=");
    Terminal.println(newLedValue);
    
    oldLedValue=newLedValue;
    analogWrite(ledPin,newLedValue);
    increaseFlag=false;
  }
  else if(decreaseFlag && counter!=0)
  {
    /* Prevent underflowing if oldLedValue is zero. */
    if(oldLedValue==0)
    {
      newLedValue=0;
    }
    /* Decrease new value. */
    newLedValue=oldLedValue-newLedValue;
    /* Set resolution. */
    if(newLedValue < 5)
    {
      newLedValue = 0 ;
    }
    /* Terminal shield is used for debugging. */ 
    Terminal.print("decreased=");
    Terminal.println(newLedValue);
    
    oldLedValue=newLedValue;
    analogWrite(ledPin,newLedValue);
    decreaseFlag=false;
  }
  /* Reset counters and iterators. */
  stringIterator =0;
  counter=0;
}

/************ Functions ************/

/* Command processing function. */
void getCommand()
{
   /* Check if new command received. */
  if(VoiceRecognition.isNewCommandReceived())
  {
    /* Get the new command. */ 
    voiceCommand = VoiceRecognition.getLastCommand();
    /* Check on make word inside the new command. */
    if(strstr(voiceCommand,"make") != NULL)
    {
      makeFlag=true;
    }
    /* Check on increased word inside the new command. */
    else if(strstr(voiceCommand,"increase") != NULL)
    {
      increaseFlag=true;
    }
    /* Check on decreased word inside the new command. */
    else if(strstr(voiceCommand,"decrease") != NULL)
    {
      decreaseFlag=true;
    }
    /* Loop on the command string. */
    while(voiceCommand[stringIterator]!='\0')
    {    /* Extract the first number from the string. */
         if(voiceCommand[stringIterator]>='0' && voiceCommand[stringIterator]<='9')
        {
          /* Save that number in an array. */
          integerString[counter]=voiceCommand[stringIterator];
          counter++;
        }
        /* Break after extracting the first number from the string. */
        if(voiceCommand[stringIterator]==' ' && counter!=0)
        {
          break;
        }
        /* Step to the next character. */
        stringIterator++;
     }
    /* Place null at the end of the array. */
    integerString[counter]='\0';
  }
}