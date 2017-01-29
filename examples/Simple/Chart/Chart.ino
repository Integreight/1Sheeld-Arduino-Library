/*

Chart Shield Example

This example shows an application on 1Sheeld's chart shield.

By using this example, you can plot and display noise data using mic over a line chart
and save it as a CSV so you can use other tools to check the data.
PS: Chart shield will automatically save 10000 plots then it will clear them from the app
for more convenient performance.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_MIC_SHIELD
#define INCLUDE_CHART_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Save a screenshot of CHART_0. */
  Chart.saveScreenShot(CHART_0);
  /* Save a csv file of CHART_0. */
  Chart.saveCsv("MicValues",CHART_0);
  /* Clear Chart 0. */
  Chart.clear(CHART_0);
}

void loop() {
  /* Add mic values to be ploted over chart. */
  Chart.add("Mic/db",Mic.getValue());
  /* Plot the values. */
  Chart.plot();
  /* Delay for 1 second. */
  OneSheeld.delay(1000);
}
