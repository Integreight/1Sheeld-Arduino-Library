/*

Internet Shield Example

This example shows an application on 1Sheeld's internet shield.

By using this example, you can get response of certain GET request and 
print it all out on the terminal shield 64 bytes by 64 bytes.
 
OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_INTERNET_SHIELD
#define INCLUDE_TERMINAL_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Create an Http request with 1Sheeld website's url. */
/* It's important to be created here as a global object. */
HttpRequest oneSheeldRequest("http://www.1sheeld.com/");

/* Set an LED on pin 13.*/
int ledPin = 13;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* LED pin mode is output. */
  pinMode(ledPin,OUTPUT); 
  /* Subscribe to success callback for the request. */
  oneSheeldRequest.setOnSuccess(&onSuccess);
  /* Subscribe to failure callback for the request. */
  oneSheeldRequest.setOnFailure(&onFailure);
  /* Subscribe to start callback for the request. */
  oneSheeldRequest.setOnStart(&onStart);
  /* Subscribe to finish callback for the request. */
  oneSheeldRequest.setOnFinish(&onFinish);
  /* Sunbscribe to setOnNextResponseBytesUpdate to be notified once the bytes is updated in the response object. */
  oneSheeldRequest.getResponse().setOnNextResponseBytesUpdate(&onBytesUpdate);
  /* Subscribe to response errors. */
  oneSheeldRequest.getResponse().setOnError(&onError);
  /* Perform a GET request using the Internet shield. */
  Internet.performGet(oneSheeldRequest);
}

void loop()
{}

void onSuccess(HttpResponse &response)
{
  /* Print out the data on the terminal. */
  Terminal.println(response.getBytes());
  /* Ask for the next 64 bytes. */
  response.getNextBytes();
}

void onFailure(HttpResponse &response)
{
  /* Print out the status code of failure.*/
  Terminal.println(response.getStatusCode());
  /* Print out the data failure.*/
  Terminal.println(response.getBytes());
}

void onStart()
{
  /* Turn on the LED when the request is started. */
  digitalWrite(13,HIGH);
}

void onFinish()
{
  /* Turn off the LED when the request has finished. */
  digitalWrite(13,LOW);
}

void onBytesUpdate(HttpResponse &response)
{
  /* Print out the data on the terminal. */
  Terminal.println(response.getBytes());
  /* Check if the reponse is sent till the last byte. */
  if(!response.isSentFully())
    {       
      /* Ask for the next 64 bytes. */
      response.getNextBytes();
    }

}

void onError(int errorNumber)
{
  /* Print out error Number.*/
  Terminal.print("Error:");
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

