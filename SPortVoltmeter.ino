#define F_CPU 16000000
#include <FrSkySportSensor.h>
#include <FrSkySportSensorFlvss.h>
#include <FrSkySportSingleWireSerial.h>
#include <FrSkySportTelemetry.h>

#define VOLTAGE 5.0 // Given in volt
#define VOLTAGE_CONVERSION_FACTOR VOLTAGE/1023

FrSkySportSensorFlvss flvss;
FrSkySportTelemetry telemetry;

/* CONNECTIONS:
 *  Digital Pin 2: SPort Data
 *  Analog  Pin 0: Battery Balancer 3.7V
 *  GND connected to either Battery Balancer 0V or SPORT GND
 *  RAW connected to Batter Balancer 7.4V or higher
 */

#define BATTERY_VOLTAGE_PIN A0
#define SPORT_PIN FrSkySportSingleWireSerial::SOFT_SERIAL_PIN_2

void setup()
{
  telemetry.begin(SPORT_PIN, &flvss);
}

void loop()
{

  /* DO YOUR STUFF HERE */
  /* Make sure you do not do any blocking calls in the loop, e.g. delay()!!! */
  int voltageRaw = analogRead(BATTERY_VOLTAGE_PIN);
  
  flvss.setData((float)voltageRaw * VOLTAGE_CONVERSION_FACTOR);
  telemetry.send();
}
