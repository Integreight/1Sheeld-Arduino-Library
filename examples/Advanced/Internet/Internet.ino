/*
 
 Internet Shield Example
 
 This example shows an application on 1Sheeld's internet shield
 
 By using this example, you can use the voice recognition to say any country's name and by
 using the internet shield and a weather online api, you will get the status of the weather 
 there (i.e. cloudy, sunny, snowy,,, etc) and based of the status an RGB LED cahanges its color.
 
 */

/* Include 1Sheeld Library. */
#include <OneSheeld.h>

/* Declaring an object from HttpRequest Class and enter the link for the weather api. */
HttpRequest request("http://api.openweathermap.org/data/2.5/weather");

/* Set a RGB LED on pin 8,9,10. */
int red = 8;
int green = 9;
int blue = 10;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Subscribe to onSuccess for request.*/
  request.setOnSuccess(&onSuccess);
  /* Subscribe to JsonResponse. */
  request.getResponse().setOnJsonResponse(&test);
  /* LED pin modes OUTPUT.*/
  pinMode(red, OUTPUT); 
  pinMode(green, OUTPUT); 
  pinMode(blue, OUTPUT); 
}

void loop()
{
  /* Check if new command received. */
  if(VoiceRecognition.isNewCommandReceived())
  {
    /* Add paramter to the URL with the name of the country from the voice recognition. */
    request.addParameter("q",VoiceRecognition.getLastCommand());
    /* Perform get for the request to get the response. */
    Internet.performGet(request);
    /* Wait for 5 seconds. */
    OneSheeld.delay(5000);
  }
}

void onSuccess(HttpResponse & response)
{
  /* Using the response to query the Json chain till the required . */
  response["weather"][0]["main"].query();
}

void test(JsonKeyChain & hell,char * output)
{
  /* 1Sheeld responds using text-to-speech. */
  TextToSpeech.say(output);
  /* Compare if the weather status is cloudy. */
  if (!strcmp("Clouds",output))
    blueRGB();
  /* Compare if the weather status is sandy. */
  else if (!strcmp("Sand",output))
    redRGB();
  /* Compare if the weather status is snowy. */
  else if (!strcmp("Snow",output))
    whiteRGB();
  /* Compare if the weather status is snowy. */
  else if (!strcmp("Clear",output))
    yellowRGB();
}

/* Set the pins of the RGB LED for the yellow color. */
void yellowRGB()
{
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
}

/* Set the pins of the RGB LED for the blue color. */
void blueRGB()
{
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
}

/* Set the pins of the RGB LED for the white color. */
void whiteRGB()
{
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
}

/* Set the pins of the RGB LED for the red color. */
void redRGB()
{
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
}
