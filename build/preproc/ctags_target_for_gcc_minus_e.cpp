# 1 "c:\\Users\\adick\\Documents\\Kerbal Kontroller\\Arduino\\Kerbal_Kontroller_Verbose\\Kerbal_Kontroller_Verbose.ino"
# 1 "c:\\Users\\adick\\Documents\\Kerbal Kontroller\\Arduino\\Kerbal_Kontroller_Verbose\\Kerbal_Kontroller_Verbose.ino"
// FILE: Kerbal_Kontroller_Verbose.ino

# 4 "c:\\Users\\adick\\Documents\\Kerbal Kontroller\\Arduino\\Kerbal_Kontroller_Verbose\\Kerbal_Kontroller_Verbose.ino" 2
# 5 "c:\\Users\\adick\\Documents\\Kerbal Kontroller\\Arduino\\Kerbal_Kontroller_Verbose\\Kerbal_Kontroller_Verbose.ino" 2
# 6 "c:\\Users\\adick\\Documents\\Kerbal Kontroller\\Arduino\\Kerbal_Kontroller_Verbose\\Kerbal_Kontroller_Verbose.ino" 2

// Defining limits

//Dead Zone



// Throttle




// Rotation Messages




// Translation Messages




// Kerbal Simpit rotation message

rotationMessage rotationMsg;

/*



Const switch setup we recomend the following

settings if you are following our directions



*/
# 39 "c:\\Users\\adick\\Documents\\Kerbal Kontroller\\Arduino\\Kerbal_Kontroller_Verbose\\Kerbal_Kontroller_Verbose.ino"
// SAS + RCS + Mod





// Built in Action Groups





/*



Const for button pin, we reccomend the

following settings but feel free to change

it for your controller



*/
# 61 "c:\\Users\\adick\\Documents\\Kerbal Kontroller\\Arduino\\Kerbal_Kontroller_Verbose\\Kerbal_Kontroller_Verbose.ino"
// Controls
# 70 "c:\\Users\\adick\\Documents\\Kerbal Kontroller\\Arduino\\Kerbal_Kontroller_Verbose\\Kerbal_Kontroller_Verbose.ino"
// Warp button





// Quick Saves





// Action Groups
# 91 "c:\\Users\\adick\\Documents\\Kerbal Kontroller\\Arduino\\Kerbal_Kontroller_Verbose\\Kerbal_Kontroller_Verbose.ino"
// Mod Buttons






/*



Analog Pins



*/
# 104 "c:\\Users\\adick\\Documents\\Kerbal Kontroller\\Arduino\\Kerbal_Kontroller_Verbose\\Kerbal_Kontroller_Verbose.ino"
// Throttle



// Done Setting Up Pins

KerbalSimpit mySimpit(Serial);

// My Simpit init

void simpitSetup(int pin) {
    Serial.begin(115200);

    digitalWrite(pin, (0x1));

    // This loop continually attempts to handshake with the plugin.
    // It will keep retrying until it gets a successful handshake.
    while (!mySimpit.init()) {
        delay(100);
    }
    // Turn off the built-in LED to indicate handshaking is complete.
    digitalWrite(pin, (0x0));
}

void setup() {
    pinMode(5, (0x01));

    simpitSetup(5);

    // Start input setup

    // SAS + RCS + Mod

    pinMode(2, (0x00));
    pinMode(2 /* The-Bit-One(Or u/hogthardwarf) will never have this switch on*/, (0x00));
    pinMode(2, (0x00));

    // Built-in Action groups

    pinMode(2, (0x00));
    pinMode(2, (0x00));
    pinMode(2, (0x00));

    // Stage

    pinMode(2, (0x00));

    // Controls

    pinMode(2, (0x00));
    pinMode(2, (0x00));
    pinMode(2, (0x00));
    pinMode(2, (0x00));
    pinMode(2, (0x00));
    pinMode(2, (0x00));

    // Warp Buttons

    pinMode(2 /* Warp to manuver*/, (0x00));
    pinMode(2, (0x00));
    pinMode(2, (0x00));

    // Quick Saves

    pinMode(2, (0x00));
    pinMode(2, (0x00));

    // Action Groups

    pinMode(2, (0x00));
    pinMode(2, (0x00));
    pinMode(2, (0x00));
    pinMode(2, (0x00));
    pinMode(2, (0x00));
    pinMode(2, (0x00));
}

void loop() {
    mySimpit.update();

    // Debounce

    // im smart

    // Stage
    if(digitalRead(2) == (0x1)){
        // Delay 50 for hardware Debounce

        delay(50);

        if(digitalRead(2) == (0x0)){
            // Button Press Counted

            mySimpit.activateAction(STAGE_ACTION);
        }
    }

    // IDK if Kerbal Simpit supports Warping yet

    if(digitalRead(2 /* Warp to manuver*/) == (0x1)){
        // Delay 50 for hardware Debounce

        delay(50);

        if(digitalRead(2 /* Warp to manuver*/) == (0x0)){
            // Button Press Counted

            // IDK
        }
    }

    // Time warp up

    if(digitalRead(2) == (0x1)){
        // Delay 50 for hardware Debounce

        delay(50);

        if(digitalRead(2) == (0x0)){
            // Button Press Counted

            // press(".")  no timewarp on Artemis ATP
        }
    }

    // Time warp down

    if(digitalRead(2) == (0x1)){
        // Delay 50 for hardware Debounce

        delay(50);

        if(digitalRead(2) == (0x0)){
            // Button Press Counted

            // press(",")  no timewarp on Artemis ATP
        }
    }

    // Press button to quick save

    if(digitalRead(2) == (0x1)){
        // Delay 50 for hardware Debounce

        delay(50);

        if(digitalRead(2) == (0x0)){
            // Button Press Counted

            // press(F5)  no timewarp on Artemis ATP
        }
    }

    // Press button to revert

    if(digitalRead(2) == (0x1)){
        // Delay 50 for hardware Debounce

        delay(50);

        if(digitalRead(2) == (0x0)){
            // Button Press Counted

            // press(F9) & hold no timewarp on Artemis ATP
        }
    }

    // Action group 1

    if(digitalRead(2) == (0x1)){
        // Delay 50 for hardware Debounce

        delay(50);

        if(digitalRead(2) == (0x0)){
            // Button Press Counted

            mySimpit.toggleCAG(1);
        }
    }

    // Action group 2

    if(digitalRead(2) == (0x1)){
        // Delay 50 for hardware Debounce

        delay(50);

        if(digitalRead(2) == (0x0)){
            // Button Press Counted

            mySimpit.toggleCAG(2);
        }
    }

    // Action group 3

    if(digitalRead(2) == (0x1)){
        // Delay 50 for hardware Debounce

        delay(50);

        if(digitalRead(2) == (0x0)){
            // Button Press Counted

            mySimpit.toggleCAG(3);
        }
    }

    // Action group 4

    if(digitalRead(2) == (0x1)){
        // Delay 50 for hardware Debounce

        delay(50);

        if(digitalRead(2) == (0x0)){
            // Button Press Counted

            mySimpit.toggleCAG(4);
        }
    }

    // Action group 5

    if(digitalRead(2) == (0x1)){
        // Delay 50 for hardware Debounce

        delay(50);

        if(digitalRead(2) == (0x0)){
            // Button Press Counted

            mySimpit.toggleCAG(5);
        }
    }

    // Action group 6

    if(digitalRead(2) == (0x1)){
        // Delay 50 for hardware Debounce

        delay(50);

        if(digitalRead(2) == (0x0)){
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
# 423 "c:\\Users\\adick\\Documents\\Kerbal Kontroller\\Arduino\\Kerbal_Kontroller_Verbose\\Kerbal_Kontroller_Verbose.ino"
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
# 457 "c:\\Users\\adick\\Documents\\Kerbal Kontroller\\Arduino\\Kerbal_Kontroller_Verbose\\Kerbal_Kontroller_Verbose.ino"
    // Set up rotation masking to know what to send

    rotationMsg.mask = 1|2|4;

    // Set roll

    if(digitalRead(2)){
        // Set rotaion message roll
        rotationMsg.roll = 32767;
    }
    if(digitalRead(2)){
        // Set rotaion message roll
        rotationMsg.roll = -32768;
    }

    // Set pitch

    if(digitalRead(2)){
        // Set rotaion message pitch
        rotationMsg.pitch = 32767;
    }
    if(digitalRead(2)){
        // Set rotaion message pitch
        rotationMsg.pitch = -32768;
    }

    // Set yaw

    if(digitalRead(2)){
        // Set rotaion message yaw
        rotationMsg.pitch = 32767;
    }
    if(digitalRead(2)){
        // Set rotaion message yaw
        rotationMsg.pitch = -32768;
    }

    // Send rotationMsg to the Kerbal Simpit plugin
    mySimpit.send(ROTATION_MESSAGE, rotationMsg);

    int brakesDigitalRead = digitalRead(2); // 1 Getting status of brakes switch we are using an integer variable but only two values are 
    // possible "HIGH" meaning true or activate and and "LOW" meaning false
    int lightDigitialRead = digitalRead(2); // 2
    int gearDigitalRead = digitalRead(2); // 3
    int sasDigitalRead = digitalRead(2); // 4
    int rcsDigitalRead = digitalRead(2 /* The-Bit-One(Or u/hogthardwarf) will never have this switch on*/); // 5
    int modDigitalRead = digitalRead(2); // 6

    if (brakesDigitalRead == (0x1) /* high is this case is erqual to a boolean 'true' */) {
        mySimpit.deactivateAction(BRAKES_ACTION); // deavtivating brakes
    }
    else /* checking if button is not active or "LOW" */ {
        mySimpit.activateAction(BRAKES_ACTION); // activating brakes
    }
    if (lightDigitialRead == (0x1) /* high is this case is erqual to a boolean 'true' */) {
        mySimpit.deactivateAction(LIGHT_ACTION); // deavtivating brakes
    }
    else /* checking if button is not active or "LOW" */ {
        mySimpit.activateAction(LIGHT_ACTION); // activating brakes
    }
    if (gearDigitalRead == (0x1) /* high is this case is erqual to a boolean 'true' */) {
        mySimpit.deactivateAction(GEAR_ACTION); // deavtivating brakes
    }
    else /* checking if button is not active or "LOW" */ {
        mySimpit.activateAction(GEAR_ACTION); // activating brakes
    }

    if (sasDigitalRead == (0x1) /* high is this case is erqual to a boolean 'true' */) {
        mySimpit.deactivateAction(SAS_ACTION); // deavtivating brakes
    }
    else /* checking if button is not active or "LOW" */ {
        mySimpit.activateAction(SAS_ACTION); // activating brakes
    }

    if (rcsDigitalRead == (0x1) /* high is this case is erqual to a boolean 'true' */) {
        mySimpit.deactivateAction(RCS_ACTION); // deavtivating brakes
    }
    else /* checking if button is not active or "LOW" */ {
        mySimpit.activateAction(RCS_ACTION); // activating brakes
    }

    //!!!!!!!!!!!!!!!!
    // IMPORTANT
    // Please insert your desired action in the /* Your action */ comment

    if (2 == (0x1) /* high is this case is erqual to a boolean 'true' */) {
        mySimpit.deactivateAction(ABORT_ACTION/* Your action */); //deavtivating brakes
    } else /* checking if button is not active or "LOW" */ {
        mySimpit.activateAction(ABORT_ACTION/* Your action */); //activating brakes
    }
    //IMPORTANT
    //!!!!!!!!!!!!!

    // keypress emulation syntax   Keyboard.press(ctrlKey); Keyboard.press('n');
}
