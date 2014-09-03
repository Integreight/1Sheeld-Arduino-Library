/*

Voice Recognition Shield Example

This example shows an application on 1Sheeld's voice recognition shield.

By using this example, control the light intensity of a LED using your voice commands.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Counters and iterators. */ 
int stringIterator = 0;
int counter = 0;
/* A name for the LED on pin 11. */
int ledPin = 11;
/* Value from voice command. */
int speechValue = 0;
/* ConvertedValue. */
int value = 0;
/* Parsing values. */
int lastValue = 0;
int oldValue = 0;
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
  value = map(speechValue,0,100,0,255);
  /* Check flags. */
  if(makeFlag)
  {
    /* Set the value to ledPin. */
    analogWrite(ledPin,value);
    makeFlag=false;
    lastValue=0;
    oldValue=value;
  }
  else if(increaseFlag)
  {
    /* Increase new value. */
    lastValue=oldValue+value;
    oldValue=lastValue;
    if(lastValue > 255)
    {
      lastValue= 255;
      oldValue = 255;
    }
    analogWrite(ledPin,lastValue);
    increaseFlag=false;
  }
  else if(decreaseFlag)
  {
    /* Decrease new value. */
    lastValue=oldValue-value;
    oldValue=lastValue;
    if(lastValue < 0)
    {
      lastValue = 0 ;
      oldValue = 0 ;
    }
    analogWrite(ledPin,lastValue);
    decreaseFlag=false;
  }
  /* Reset counters and iterators. */
  stringIterator =0;
  counter=0;
}

/************ Functions *******************/

/* Command getter function. */
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
    {    /* Extract first number from the string. */
         if(voiceCommand[stringIterator]>='0' && voiceCommand[stringIterator]<='9')
        {
          /* Save the number in an array. */
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

