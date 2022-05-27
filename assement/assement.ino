#include <SparkFun_LPS25HB_Arduino_Library.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <Wire.h>
#include <Servo.h>
int pos = 0;

LPS25HB sensor;
OpenLog data;
Servo servo;
const byte OpenLogAddress = 42;
const byte DELAY = 10000;

//--------------------------------------
// methods should have desciptions before them
//--------------------------------------
void setup() {
  Wire.begin();
  data.begin();
  sensor.begin(Wire, LPS25HB_I2C_ADDR_DEF);

  //--------------------------------------
  // csv file setup should have column names
  //--------------------------------------
  data.append("Ekko.txt");
  data.println("Pressure,Tempratue");
  data.syncFile();
  Serial.begin(9600);
  //--------------------------------------
  //servo should have a const not 9
  //--------------------------------------
  servo.attach(11);
  // put your setup code here, to run once:
  servo.write(pos);

  Serial.print("set up finished ");
}

void loop() {
  if (sensor.isConnected() == true)
  {
    if (sensor.getStatus() == 0x00)
    {
      sensor.begin();
    }

    Serial.print("Pressure (hPa): ");
    Serial.print(sensor.getPressure_hPa());
    Serial.print(", Temperature (degC): ");
    Serial.println(sensor.getTemperature_degC());

    //--------------------------------------
    // don't need the text just sensor readings and commas
    //--------------------------------------
    //data.print("Pressure (hPa): ");
    data.print(sensor.getPressure_hPa());
    data.print(",");
    data.println(sensor.getTemperature_degC());


    //--------------------------------------
    // when will we move this/ look at millis() method for help
    //--------------------------------------
    // servo.write(180);
    if (millis() > DELAY) {

      Serial.print("parachute");
      servo.write(180);
    }
  }


}
