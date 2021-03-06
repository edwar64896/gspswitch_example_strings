#include <Arduino.h>
#include <gspswitch.h>

//Strings


/////////////////////////////////////////////////////////////////////////////
// TWO_POSITION_TOGGLE On/Off
/////////////////////////////////////////////////////////////////////////////

gspSwitch sw1(1,"you turn me on","you turn me off");

/////////////////////////////////////////////////////////////////////////////
// Momentary Pushbutton - Active on release
/////////////////////////////////////////////////////////////////////////////

gspSwitch pb1(2,"You push me, activated on release");

/////////////////////////////////////////////////////////////////////////////
// Momentary Pushbutton - Active on push
/////////////////////////////////////////////////////////////////////////////

gspSwitch pb2(3,"You push me, activated on push", 1);

/////////////////////////////////////////////////////////////////////////////
// Momentary Pushbutton - Continuous Active on push
/////////////////////////////////////////////////////////////////////////////

gspSwitch pb3(4,"You keep pushing me", 2);

/////////////////////////////////////////////////////////////////////////////
// Momentary Pushbutton - Latching with Long Push
/////////////////////////////////////////////////////////////////////////////

gspSwitch pb4(5,"You turn me on","You turn me off","You push me long time");

/////////////////////////////////////////////////////////////////////////////
// Momentary Pushbutton - Latching with 2 Long Pushes
/////////////////////////////////////////////////////////////////////////////

gspSwitch pb5(6,"You turn me on","You turn me off","You push me long time","You push me for a very long time");


/////////////////////////////////////////////////////////////////////////////
// Setup Function
/////////////////////////////////////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  gspGrouped::register_instance( & sw1 );
  gspGrouped::register_instance( & pb1 );
  gspGrouped::register_instance( & pb2 );
  gspGrouped::register_instance( & pb3 );
  gspGrouped::register_instance( & pb4 );
  gspGrouped::register_instance( & pb5 );
}

/////////////////////////////////////////////////////////////////////////////
// Loop Function
/////////////////////////////////////////////////////////////////////////////
void loop() {
  // put your main code here, to run repeatedly:
  gspSwitch::checkAll();
}