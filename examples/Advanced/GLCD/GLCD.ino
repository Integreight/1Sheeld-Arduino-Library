#define CUSTOM_SETTINGS
#define INCLUDE_GLCD_SHIELD

#include <OneSheeld.h>

int ledPin1 = 13;
int ledPin2 = 12;
int relayPin = 11;
bool cmWasON = false;
bool firstTimePressed = false;

GLCDRectangle border1(0,0,255,127);
GLCDRectangle border2(2,2,251,123);
GLCDButton  lightButton1(20,49,50,30,"Light1");
GLCDButton  lightButton2(105,49,50,30,"Light2");
GLCDButton  coffeeMakerButton(190,49,50,30,"CM:ON");

void setup() {
  // put your setup code here, to run once:
  OneSheeld.begin();
  GLCD.clear();
  drawAllShapes();
  setButtonTasks();
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(relayPin,OUTPUT);
  lightButton1.setStyle(DIMENSION_3D);
  lightButton2.setStyle(DIMENSION_3D);
  coffeeMakerButton.setStyle(DIMENSION_3D);
}

void loop() {
  // put your main code here, to run repeatedly:
}


void drawAllShapes()
{
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

void button1Task(bool button1State)
{
  if(button1State == HIGH)
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
  if(button2State == HIGH)
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
  if(coffeeMakerButtonState ==HIGH)
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
  else
  {
    if(!cmWasON)
    firstTimePressed = true;
  }
}
