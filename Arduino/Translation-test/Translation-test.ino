 #include "KerbalSimpit.h"
#include "KerbalSimpitMessageTypes.h"
#include "PayloadStructs.h"

wheelMessage wh;

rotationMessage rotationMsg; 

KerbalSimpit mySimpit(Serial);

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
}

void loop() {
    rotationMsg.roll = constrain(map(1023,1023,512,-32767,0),-32767,0);

    mySimpit.send(ROTATION_MESSAGE, rotationMsg);

    mySimpit.update();
}
