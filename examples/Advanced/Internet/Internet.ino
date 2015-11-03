/*
 
Internet Shield Example

This example shows an application on 1Sheeld's internet shield

By using this example, you can use the voice recognition shield to say any country's name and 
get the status of its weather using the internet shield and the open weather map api and
based of the weather status (i.e. cloudy, sunny, snowy,... etc) an RGB LED changes its color.
 
OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_INTERNET_SHIELD
#define INCLUDE_TERMINAL_SHIELD
#define INCLUDE_TEXT_TO_SPEECH_SHIELD
#define INCLUDE_VOICE_RECOGNIZER_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Create an Http request with openweathermap.org api url. */
/* It's important to be created here as a global object. */
HttpRequest request("http://api.openweathermap.org/data/2.5/weather?appid=2711d6a2cc90e292afaf00f9335028b1");

/* Set a RGB LED on pin 8,9 and 10. */
int red = 8;
int green = 9;
int blue = 10;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Subscribe to success callback for the request. */
  request.setOnSuccess(&onSuccess);
  /* Subscribe to json value replies. */
  request.getResponse().setOnJsonResponse(&onJsonReply);
  /* Subscribe to response errors. */
  request.getResponse().setOnError(&onResponseError);
  /* Subscribe to Internet errors. */
  Internet.setOnError(&onInternetError);
  /* LED pin modes OUTPUT.*/
  pinMode(red, OUTPUT); 
  pinMode(green, OUTPUT); 
  pinMode(blue, OUTPUT); 
}

void loop()
{
  /* Check if a new command is received. */
  if(VoiceRecognition.isNewCommandReceived())
  {
    /* Add paramter to the URL with the name of the country from the voice recognition. */
    request.addParameter("q",VoiceRecognition.getLastCommand());
    /* Perform a GET request using the Internet shield. */
    Internet.performGet(request);
    /* Wait for 5 seconds. */
    OneSheeld.delay(5000);
  }
}

void onSuccess(HttpResponse & response)
{
  /* Using the response to query the Json chain till the required value. */
  /* i.e. Get the value of 'main' in the first object of the array 'weather' in the response. */
  /* Providing that the response is in JSON format. */
  response["weather"][0]["main"].query();
}

void onJsonReply(JsonKeyChain & hell,char * output)
{
  /* 1Sheeld responds using text-to-speech shield. */
  TextToSpeech.say(output);
  /* Check if the weather status is cloudy. */
  if (!strcmp("Clouds",output))
    blueRGB();
  /* Check if the weather status is sandy. */
  else if (!strcmp("Sand",output))
    redRGB();
  /* Check if the weather status is snowy. */
  else if (!strcmp("Snow",output))
    whiteRGB();
  /* Check if the weather status is snowy. */
  else if (!strcmp("Clear",output))
    yellowRGB();
}

/* Set the pins of the RGB LED to the yellow color. */
void yellowRGB()
{
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
}

/* Set the pins of the RGB LED to the blue color. */
void blueRGB()
{
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
}

/* Set the pins of the RGB LED to the white color. */
void whiteRGB()
{
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
}

/* Set the pins of the RGB LED to the red color. */
void redRGB()
{
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
}

void onResponseError(int errorNumber)
{
  /* Print out error Number.*/
  Terminal.print("Response error:");
  switch(errorNumber)
  {
    case INDEX_OUT_OF_BOUNDS: Terminal.println("INDEX_OUT_OF_BOUNDS");break;
    case RESPONSE_CAN_NOT_BE_FOUND: Terminal.println("RESPONSE_CAN_NOT_BE_FOUND");break;
    case HEADER_CAN_NOT_BE_FOUND: Terminal.println("HEADER_CAN_NOT_BE_FOUND");break;
    case NO_ENOUGH_BYTES: Terminal.println("NO_ENOUGH_BYTES");break;
    case REQUEST_HAS_NO_RESPONSE: Terminal.println("REQUEST_HAS_NO_RESPONSE");break;
    case SIZE_OF_REQUEST_CAN_NOT_BE_ZERO: Terminal.println("SIZE_OF_REQUEST_CAN_NOT_BE_ZERO");break;
    case UNSUPPORTED_HTTP_ENTITY: Terminal.println("UNSUPPORTED_HTTP_ENTITY");break;
    case JSON_KEYCHAIN_IS_WRONG: Terminal.println("JSON_KEYCHAIN_IS_WRONG");break;
  }
}

void onInternetError(int requestId, int errorNumber)
{
  /* Print out error Number.*/
  Terminal.print("Request id:");
  Terminal.println(requestId);
  Terminal.print("Internet error:");
  switch(errorNumber)
  {
    case REQUEST_CAN_NOT_BE_FOUND: Terminal.println("REQUEST_CAN_NOT_BE_FOUND");break;
    case NOT_CONNECTED_TO_NETWORK: Terminal.println("NOT_CONNECTED_TO_NETWORK");break;
    case URL_IS_NOT_FOUND: Terminal.println("URL_IS_NOT_FOUND");break;
    case ALREADY_EXECUTING_REQUEST: Terminal.println("ALREADY_EXECUTING_REQUEST");break;
    case URL_IS_WRONG: Terminal.println("URL_IS_WRONG");break;
  }
}

