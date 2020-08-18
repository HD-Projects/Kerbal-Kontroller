 #include "KerbalSimpit.h"
#include "KerbalSimpitMessageTypes.h"
#include "PayloadStructs.h"

rotationMessage myRotation; 

KerbalSimpit mySimpit(Serial);

int throttleValue;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(115200);

    digitalWrite(LED_BUILTIN, HIGH);

    // This loop continually attempts to handshake with the plugin.
    // It will keep retrying until it gets a successful handshake.
    while (!mySimpit.init()) {
        delay(100);
    }
    // Turn off the built-in LED to indicate handshaking is complete.
    digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
    myRotation.mask = 1|2|4;

    myRotation.pitch = 0;

    myRotation.roll = 0; // applies the X-axis value as the rotation roll value

    myRotation.yaw = 0;

    mySimpit.send(ROTATION_MESSAGE, myRotation);

    delay(1);

    throttleValue = 32767;

    mySimpit.send(THROTTLE_MESSAGE, throttleValue);

    delay(1);

    mySimpit.update();
}
