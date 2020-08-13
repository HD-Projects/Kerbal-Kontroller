// FILE: Kerbal_Kontroller_Verbose.ino

#include "KerbalSimpit.h"
#include "KerbalSimpitMessageTypes.h"
#include "PayloadStructs.h"
//#include "Keyboard.h"
//char ctrlKey = KEY_LEFT_CTRL;

// Kerbal Simpit rotation message

rotationMessage rotationMsg;

/*

Varables to keep track of button state

*/

int stage_button_state = 0;

int roll_right_button_state = 0;
int roll_left_button_state = 0;
int pitch_left_button_state = 0;
int pitch_right_button_state = 0;
int yaw_up_button_state = 0;
int yaw_down_button_state = 0;

int WTM_button_state = 0;
int warp_up_button_state = 0;
int warp_down_button_state = 0;

int quick_save_button_state = 0;
int revert_quick_save_button_state = 0;

int action_1_button_state = 0;
int action_2_button_state = 0;
int action_3_button_state = 0;
int action_4_button_state = 0;
int action_5_button_state = 0;
int action_6_button_state = 0;

/*

Const switch setup we recomend the following
settings if you are following our directions

*/

// SAS + RCS + Mod

#define SAS_switch 2
#define RCS_switch 2 // The-Bit-One(Or u/hogthardwarf) will never have this switch on
#define mod_switch 2

// Built in Action Groups

#define lights_switch 2
#define brakes_switch 2
#define gear_switch 2

/*

Const for button pin, we reccomend the
following settings but feel free to change
it for your controller

*/

#define stage_button 2

// Controls

#define roll_right_button 2
#define roll_left_button 2
#define pitch_left_button 2
#define pitch_right_button 2
#define yaw_up_button 2
#define yaw_down_button 2

// Warp button

#define WTM_button 2 // Warp to manuver
#define warp_up_button 2
#define warp_down_button 2

// Quick Saves

#define quick_save_button 2
#define revert_quick_save_button 2


// Action Groups

#define action_1_button 2
#define action_2_button 2
#define action_3_button 2
#define action_4_button 2
#define action_5_button 2
#define action_6_button 2

// Mod Buttons

#define mod_1_button 2
#define mod_2_button 2
#define mod_3_button 2
#define mod_4_button 2

/*

Analog Pins

*/

// Throttle

#define throttle_gauge A5

// Done Setting Up Pins

KerbalSimpit mySimpit(Serial);

// My Simpit init

void simpitSetup(int pin) {
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

    // Debounce

    // im smart

    if(digitalRead(stage_button) == HIGH){
        // Delay 50 for hardware Debounce

        delay(50);
        
        if(digitalRead(stage_button) == LOW){
            // Button Press Counted

            mySimpit.activateAction(STAGE_ACTION);
        }
    }

    if(digitalRead(roll_right_button) == HIGH){                      
        // Delay 50 for hardware Debounce

        delay(50);
    
        if(digitalRead(roll_right_button) == LOW){
            // Button Press Counted

            
        }
    }

    

    /* 1 */int brakesDigitalRead = digitalRead(gear_switch); // Getting status of brakes switch we are using an integer variable but only two values are 
    // possible "HIGH" meaning true or activate and and "LOW" meaning false
    /* 2 */int lightDigitialRead = digitalRead(lights_switch);
    /* 3 */int gearDigitalRead = digitalRead(gear_switch);
    /* 4 */int sasDigitalRead = digitalRead(SAS_switch);
    /* 5 */int rcsDigitalRead = digitalRead(RCS_switch);
    /* 6 */int modDigitalRead = digitalRead(mod_switch);

    if (brakesDigitalRead == HIGH /* high is this case is erqual to a boolean 'true' */) {
        mySimpit.deactivateAction(BRAKES_ACTION); // deavtivating brakes
    }
    else /* checking if button is not active or "LOW" */ {
        mySimpit.activateAction(BRAKES_ACTION);  // activating brakes
    }
    if (lightDigitialRead == HIGH /* high is this case is erqual to a boolean 'true' */) {
        mySimpit.deactivateAction(LIGHT_ACTION); // deavtivating brakes
    }
    else /* checking if button is not active or "LOW" */ {
        mySimpit.activateAction(LIGHT_ACTION);  // activating brakes
    }
    if (gearDigitalRead == HIGH /* high is this case is erqual to a boolean 'true' */) {
        mySimpit.deactivateAction(GEAR_ACTION); // deavtivating brakes
    }
    else /* checking if button is not active or "LOW" */ {
        mySimpit.activateAction(GEAR_ACTION);  // activating brakes
    }

    if (sasDigitalRead == HIGH /* high is this case is erqual to a boolean 'true' */) {
        mySimpit.deactivateAction(SAS_ACTION); // deavtivating brakes
    }
    else /* checking if button is not active or "LOW" */ {
        mySimpit.activateAction(SAS_ACTION);  // activating brakes
    }

    if (rcsDigitalRead == HIGH /* high is this case is erqual to a boolean 'true' */) {
        mySimpit.deactivateAction(RCS_ACTION); // deavtivating brakes
    }
    else /* checking if button is not active or "LOW" */ {
        mySimpit.activateAction(RCS_ACTION);  // activating brakes
    }

    //!!!!!!!!!!!!!!!!
    // IMPORTANT
    // Please insert your desired action in the /* Your action */ comment

    if (mod_switch == HIGH /* high is this case is erqual to a boolean 'true' */) {
        mySimpit.deactivateAction(ABORT_ACTION/* Your action */); //deavtivating brakes
    } else /* checking if button is not active or "LOW" */ {
        mySimpit.activateAction(ABORT_ACTION/* Your action */);  //activating brakes
    }
    //IMPORTANT
    //!!!!!!!!!!!!!



// keypress emulation syntax   Keyboard.press(ctrlKey); Keyboard.press('n');


    mySimpit.update();
}
