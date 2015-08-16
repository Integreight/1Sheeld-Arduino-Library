/*

GLCD Shield Example

This example shows an application on 1Sheeld's GLCD shield.

By using this example, you can draw a simple intreface for
your home automation projects that consists of 3 buttons.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_GLCD_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A name for the LED on pin 13. */
int ledPin1 = 13;

/* A name for the LED on pin 12. */
int ledPin2 = 12;

/* A name for the relay on pin 11. */
int relayPin = 11;

/* A variable that specify if the coffee machine was on. */
bool cmWasON = false;

/* A variable that specify if the button is pressed at least once. */
bool firstTimePressed = false;

/* Borders for the interface. */
GLCDRectangle border1(0,0,255,127);
GLCDRectangle border2(2,2,251,123);

/* The three Buttons.*/
GLCDButton  lightButton1(20,49,50,30,"Light1");
GLCDButton  lightButton2(105,49,50,30,"Light2");
GLCDButton  coffeeMakerButton(190,49,50,30,"CM:ON");

void setup()
{
  /* Start communication. */
  OneSheeld.begin();

  /* Clear the GLCD. */
  GLCD.clear();

  /* Draw the three buttons. */
  drawAllShapes();

  /* Change the styles of the buttons to 3D. */
  setButtonStyles();

  /* Set the button handlers. */
  setButtonTasks();
  
  /* Set the two LEDs and the relay pins modes to output. */
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(relayPin,OUTPUT);
}

void loop()
{
  /* Leave the loop empty. */
}


void drawAllShapes()
{
  /* Draw the two borders and the three buttons. */ 
  GLCD.draw(border1);
  GLCD.draw(border2);
  GLCD.draw(lightButton1);
  GLCD.draw(lightButton2);
  GLCD.draw(coffeeMakerButton);
}

void setButtonTasks()
{
  lightButton1.setOnChange(&button1Task);
  lightButton2.setOnChange(&button2Task);
  coffeeMakerButton.setOnChange(&coffeeMakerTask);
}

void setButtonStyles()
{
  lightButton1.setStyle(STYLE_3D);
  lightButton2.setStyle(STYLE_3D);
  coffeeMakerButton.setStyle(STYLE_3D);
}

void button1Task(bool button1State)
{
  if(button1State)
  {
    digitalWrite(ledPin1,HIGH);
  }
  else
  {
    digitalWrite(ledPin1,LOW);
  }
}

void button2Task(bool button2State)
{
  if(button2State)
  {
    digitalWrite(ledPin2,HIGH);
  }
  else
  {
    digitalWrite(ledPin2,LOW);
  }
}

void coffeeMakerTask(bool coffeeMakerButtonState)
{
  if(coffeeMakerButtonState)
  {
    if(firstTimePressed)
    {
        digitalWrite(relayPin,LOW);
        coffeeMakerButton.setText("CM:ON");
        cmWasON = true;
        firstTimePressed = false;
    }
    else
    {
        digitalWrite(relayPin,HIGH);
        coffeeMakerButton.setText("CM:OFF");
        cmWasON = false;
    }
  }
  else if(!cmWasON)
  {
    
    firstTimePressed = true;
  }
}