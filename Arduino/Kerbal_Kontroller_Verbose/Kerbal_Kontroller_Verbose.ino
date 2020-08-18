// FILE: Kerbal_Kontroller_Verbose.ino

#include "KerbalSimpit.h"
#include "KerbalSimpitMessageTypes.h"
#include "PayloadStructs.h"
// we need more keyboard emulation 
//char ctrlKey = KEY_LEFT_CTRL;

// Defining limits

//Dead Zone

#define DEADZONE 200

// Throttle

#define THROTTLE_HIGH -32768
#define THROTTLE_LOW 0

// Rotation Messages

#define ROTATION_HIGH 32767
#define ROTATION_LOW -32768

// Translation Messages

#define TRANSLATION_HIGH 32767
#define TRANSLATION_LOW -32768

// Kerbal Simpit rotation message

rotationMessage rotationMsg;

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
    mySimpit.update();

    // Debounce

    // im smart

    // Stage
    if(digitalRead(stage_button) == HIGH){
        // Delay 50 for hardware Debounce

        delay(50);
        
        if(digitalRead(stage_button) == LOW){
            // Button Press Counted

            mySimpit.activateAction(STAGE_ACTION);
        }
    }

    // IDK if Kerbal Simpit supports Warping yet

    if(digitalRead(WTM_button) == HIGH){
        // Delay 50 for hardware Debounce

        delay(50);
        
        if(digitalRead(WTM_button) == LOW){
            // Button Press Counted

            // IDK
        }
    } 

    // Time warp up

    if(digitalRead(warp_up_button) == HIGH){
        // Delay 50 for hardware Debounce

        delay(50);
        
        if(digitalRead(warp_up_button) == LOW){
            // Button Press Counted

            // press(".")
        }
    } 

    // Time warp down

    if(digitalRead(warp_down_button) == HIGH){
        // Delay 50 for hardware Debounce

        delay(50);
        
        if(digitalRead(warp_down_button) == LOW){
            // Button Press Counted

            // press(",")
        }
    } 

    // Press button to quick save

    if(digitalRead(quick_save_button) == HIGH){
        // Delay 50 for hardware Debounce

        delay(50);
        
        if(digitalRead(quick_save_button) == LOW){
            // Button Press Counted

            // press(F5)
        }
    }

    // Press button to revert

    if(digitalRead(revert_quick_save_button) == HIGH){
        // Delay 50 for hardware Debounce

        delay(50);
        
        if(digitalRead(revert_quick_save_button) == LOW){
            // Button Press Counted

            // press(F9) & hold
        }
    }

    // Action group 1

    if(digitalRead(action_1_button) == HIGH){
        // Delay 50 for hardware Debounce

        delay(50);
        
        if(digitalRead(action_1_button) == LOW){
            // Button Press Counted

            mySimpit.toggleCAG(1);
        }
    }

    // Action group 2

    if(digitalRead(action_2_button) == HIGH){
        // Delay 50 for hardware Debounce

        delay(50);
        
        if(digitalRead(action_2_button) == LOW){
            // Button Press Counted

            mySimpit.toggleCAG(2);
        }
    }

    // Action group 3

    if(digitalRead(action_3_button) == HIGH){
        // Delay 50 for hardware Debounce

        delay(50);
        
        if(digitalRead(action_3_button) == LOW){
            // Button Press Counted

            mySimpit.toggleCAG(3);
        }
    }

    // Action group 4

    if(digitalRead(action_4_button) == HIGH){
        // Delay 50 for hardware Debounce

        delay(50);
        
        if(digitalRead(action_4_button) == LOW){
            // Button Press Counted

            mySimpit.toggleCAG(4);
        }
    }

    // Action group 5

    if(digitalRead(action_5_button) == HIGH){
        // Delay 50 for hardware Debounce

        delay(50);
        
        if(digitalRead(action_5_button) == LOW){
            // Button Press Counted

            mySimpit.toggleCAG(5);
        }
    }

    // Action group 6

    if(digitalRead(action_6_button) == HIGH){
        // Delay 50 for hardware Debounce

        delay(50);
        
        if(digitalRead(action_6_button) == LOW){
            // Button Press Counted

            mySimpit.toggleCAG(6);
        }
    }

    /* 

    Mod buttons

    The mod buttons have 2 choices debounce or constaint
    like the control buttons the below code is the debounce
    put a close tag below, customize the action and brake the close tag
    
    

    // Mod 1

    if(digitalRead(mod_1_button) == HIGH){
        // Delay 50 for hardware Debounce

        delay(50);
        
        if(digitalRead(mod_1_button) == LOW){
            // Button Press Counted

            // Your Action
        }
    }

    // Mod 1

    if(digitalRead(mod_2_button) == HIGH){
        // Delay 50 for hardware Debounce

        delay(50);
        
        if(digitalRead(mod_2_button) == LOW){
            // Button Press Counted

            // Your Action
        }
    }

    // Mod 3

    if(digitalRead(mod_3_button) == HIGH){
        // Delay 50 for hardware Debounce

        delay(50);
        
        if(digitalRead(mod_3_button) == LOW){
            // Button Press Counted

            // Your Action
        }
    }

    // Mod 1

    if(digitalRead(mod_4_button) == HIGH){
        // Delay 50 for hardware Debounce

        delay(50);
        
        if(digitalRead(mod_4_button) == LOW){
            // Button Press Counted

            // Your Action
        }
    }

    */

    /*

    Second option

    Press down for cuntinuous action

    

    // Mod 1

    if(digitalRead(mod_1_button)){
        // Your Action
    }

    // Mod 2

    if(digitalRead(mod_2_button)){
        // Your Action
    }

    // Mod 3

    if(digitalRead(mod_3_button)){
        // Your Action
    }

    // Mod 4

    if(digitalRead(mod_4_button)){
        // Your Action
    }

    */

    // Set up rotation masking to know what to send

    rotationMsg.mask = 1|2|4;

    // Set roll

    if(digitalRead(roll_right_button)){
        // Set rotaion message roll
        rotationMsg.roll = 32767;
    }
    if(digitalRead(roll_left_button)){
        // Set rotaion message roll
        rotationMsg.roll = -32768;
    }

    // Set pitch

    if(digitalRead(pitch_left_button)){
        // Set rotaion message pitch
        rotationMsg.pitch = 32767;
    }
    if(digitalRead(pitch_right_button)){
        // Set rotaion message pitch
        rotationMsg.pitch = -32768;
    }

    // Set yaw

    if(digitalRead(yaw_up_button)){
        // Set rotaion message yaw
        rotationMsg.pitch = 32767;
    }
    if(digitalRead(yaw_down_button)){
        // Set rotaion message yaw
        rotationMsg.pitch = -32768;
    }

    // Send rotationMsg to the Kerbal Simpit plugin
    mySimpit.send(ROTATION_MESSAGE, rotationMsg);

    int brakesDigitalRead = digitalRead(gear_switch); // 1 Getting status of brakes switch we are using an integer variable but only two values are 
    // possible "HIGH" meaning true or activate and and "LOW" meaning false
    int lightDigitialRead = digitalRead(lights_switch); // 2
    int gearDigitalRead = digitalRead(gear_switch); // 3
    int sasDigitalRead = digitalRead(SAS_switch); // 4
    int rcsDigitalRead = digitalRead(RCS_switch); // 5
    int modDigitalRead = digitalRead(mod_switch); // 6

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
}
