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
const int RCS_switch = 2; // The-Bit-One(Or u/hogthardwarf) will never have this switch on
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
  pinMode(LED_BUILTIN, OUTPUT);

  simpitSetup(LED_BUILTIN);

  // Start input setup

  // SAS + RCS + Mod

  pinMode(SAS_switch, INPUT);
  pinMode(RCS_switch, INPUT);
  pinMode(mod_switch, INPUT);

  // Built-in Action groups

  pinMode(lights_switch, INPUT);
  pinMode(brakes_switch, INPUT);
  pinMode(gear_switch, INPUT);

  // Stage

  pinMode(stage_button, INPUT);

  // Controls

  pinMode(roll_right_button, INPUT);
  pinMode(roll_left_button, INPUT);
  pinMode(pitch_left_button, INPUT);
  pinMode(pitch_right_button, INPUT);
  pinMode(yaw_up_button, INPUT);
  pinMode(yaw_down_button, INPUT);

  // Warp Buttons

  pinMode(WTM_button, INPUT);
  pinMode(warp_up_button, INPUT);
  pinMode(warp_down_button, INPUT);

  // Quick Saves
  
  pinMode(quick_save_button, INPUT);
  pinMode(revert_quick_save_button, INPUT);

  // Action Groups

  pinMode(action_1_button, INPUT);
  pinMode(action_2_button, INPUT);
  pinMode(action_3_button, INPUT);
  pinMode(action_4_button, INPUT);
  pinMode(action_5_button, INPUT);
  pinMode(action_6_button, INPUT);

}

void loop() {





  mySimpit.update(); // up[dating data before running loop again
}
