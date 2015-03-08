/*

 Internet Shield Example
 
 This example shows an application on 1Sheeld's internet shield.
 
 By using this example, you can get response of certain request and 
 print it all out on the terminal shield.
 
 */

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Create an HttpRequest and it's important to be created here as a global object.*/
HttpRequest oneSheeldRequest("http://1sheeld.com/");

/* Set an LED on pin 13.*/
int ledPin = 13;

/* Boolean for seting on next bytes.*/
bool subscribedTosetOnNextBytes = false;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* LED pin mode is OUTPUT.*/
  pinMode(ledPin,OUTPUT); 
  /* Subscribe to onSuccess for request. */
  oneSheeldRequest.setOnSuccess(&successFunction);
  /* Subscribe to onFailure for request. */
  oneSheeldRequest.setOnFailure(&failureFunction);
  /* Subscribe to onStart for request. */
  oneSheeldRequest.setOnStart(&startFunction);
  /* Subscribe to onFinish for request. */
  oneSheeldRequest.setOnFinish(&finishFunction);
  /*Perform a GET order.*/
  Internet.performGet(oneSheeldRequest);
}

void loop()
{}

void successFunction(HttpResponse &response)
{
  /* Print out the data on the terminal.*/
  Terminal.println(response.getBytes());
  /* Check if the reponse is sent till the last byte.*/
  if(!response.isSentFully())
      {
           if(!subscribedTosetOnNextBytes)
              /* Sunbscribe to setOnNextResponseBytesUpdate.*/
              response.setOnNextResponseBytesUpdate(&successFunction);
              /* Set the boolean. */
              subscribedTosetOnNextBytes = true; 
              /* Ask for nextBytes. */
              response.getNextBytes();
      }
      else
      {
        /* Subscribe to setOnError.*/
        response.setOnError(&errorFunction);
        /* Print out error message.*/
        Terminal.println("An Error occurred when getting response");
      }
}

void failureFunction(HttpResponse &response)
{
  /* Print out the status code of failure.*/
  Terminal.println(response.getStatusCode());
  /* Print out the data failure.*/
  Terminal.println(response.getBytes());
}

void startFunction()
{
  /* Turn on the LED when the request is started.*/
  digitalWrite(13,HIGH);
}

void finishFunction()
{
  /* Turn off the LED when the request has finished.*/
  digitalWrite(13,LOW);
}

void errorFunction(int errorNumber)
{
  /* Print out Error Number.*/
  Terminal.print("Error Number:");
  Terminal.println(errorNumber);
}

