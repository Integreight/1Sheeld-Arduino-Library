/*

 Pattern Shield Example
 
 This example shows an application on 1Sheeld's pattern shield.
 
 By using this example, you can turn on a LED if you
 entered the right pattern which is "L" character.
 
 */

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A name for the LED on pin 13. */
int ledPin = 13;

/* A variable to store the right pattern which is "L" character. */
PatternNode patternStored[] = { {0,0}, {1,0}, {2,0}, {2,1}, {2,2} };

/* A variable used to check wether the pattern is right or wrong. */
int counter = 0;

/* A variable used to store the length of the pattern. */
int length = 0;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED as output. */
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  /* Always check if the user entered any pattern. */
  if (Pattern.isNewPatternReceived())
  {
    /* This pointer act as array to store the last pattern entered by user. */
    PatternNode * patternEntered = Pattern.getLastPattern();

    /* Get the length of the pattern to loop over it. */
    length = Pattern.getLastPatternSize();

    /* A for loop to check the entered pattern to the stored pattern. */
    for (int i = 0; i < length ; i++)
    {
      /* A check for the pattern by checking the row and the column of each node entered by the user. */
      if (patternEntered[i].row == patternStored[i].row && patternEntered[i].col == patternStored[i].col)
      {
        counter++;
      }
    }

    /* If condidition to check if all the nodes entered by the user are right and equal to the right pattern. */
    if (counter == 5)
    {
      digitalWrite(ledPin,HIGH);
      counter = 0;
    }
    else 
    {
      digitalWrite(ledPin,LOW);
      counter = 0;
    }
  } 
}

