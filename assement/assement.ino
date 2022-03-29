#include <SparkFun_LPS25HB_Arduino_Library.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <Wire.h>

LPS25HB pressureSensor;
OpenLog myLog;
const byte OpenLogAddress = 42;

void setup() {
 Wire.begin();
 myLog.begin();
 pressureSensor.begin(Wire, LPS25HB_I2C_ADDR_DEF);
  myLog.append("Ekko.txt");
  myLog.println("This is recorded to appendMe.txt");
  myLog.syncFile();
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
if (pressureSensor.isConnected() == true)
{
  if(pressureSensor.getStatus()==0x00)
  {
    pressureSensor.begin();
  }
  Serial.print(pressureSensor.getStatus()_HEX();
   Serial.print("Pressure (hPa): ");
  Serial.print(pressureSensor.getPressure_hPa());
  Serial.print(", Temperature (degC): ");
  Serial.println(pressureSensor.getTemperature_degC());
}
  // put your main code here, to run repeatedly:

}
