#include <KerbalSimpit.h>
#include <KerbalSimpitMessageTypes.h>
#include <PayloadStructs.h>

const int delay_time = 100;

/*

Const switch setup we recomend the following 
settings if you are following our directions

*/

// SAS + RCS + Mod

const int SAS_switch = 2;
const int RCS_switch = 2; // The-Bit-One(Or )
const int mod_switch = 2;

// Built in Action Groups

const int lights_switch = 2;
const int brakes_switch = 2;
const int gear_switch = 2;

/*

Const for button pin, we reccomend the 
following settings but feel free to change 
it for your controller

*/

const int stage_button = 2;

// Controls

const int roll_right_button = 2;
const int roll_left_button = 2;
const int pitch_left_button = 2;
const int pitch_right_button = 2;
const int yaw_up_button = 2;
const int yaw_down_button = 2;

// Warp button

const int WTM_button = 2; // Warp to manuver
const int warp_up_button = 2;
const int warp_down_button = 2;

// Quick Saves

const int quick_save_button = 2;
const int revert_quick_save_button = 2;


// Action Groups

const int action_1_button = 2;
const int action_2_button = 2;
const int action_3_button = 2;
const int action_4_button = 2;
const int action_5_button = 2;
const int action_6_button = 2;

/* 

Analog Pins

*/

// Throttle

const int throttle_gauge = 5;

// Done Setting Up Pins

KerbalSimpit mySimpit(Serial);



void simpitSetup(int pin){
  Serial.begin(115200);

  digitalWrite(pin, HIGH);

  // This loop continually attempts to handshake with the plugin.
  // It will keep retrying until it gets a successful handshake.
  while (!mySimpit.init()) {
    delay(100);
  }
  // Turn off the built-in LED to indicate handshaking is complete.
  digitalWrite(pin, LOW);
}

void setup() {
  pinMode(stage_button, INPUT);
  pinMode(brakes_switch, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  simpitSetup(LED_BUILTIN);


}

void loop() {
  mySimpit.update();
}
