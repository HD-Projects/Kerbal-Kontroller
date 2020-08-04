#include <KerbalSimpit.h>
#include <KerbalSimpitMessageTypes.h>
#include <PayloadStructs.h>

const int delay_time = 100;

const int brakes_switch = 2;
const int SAS_switch = 2;
const int lights_switch = 2;

const int stage_button = 3;

int probe_value;

bool brakes_status = false;

KerbalSimpit mySimpit(Serial);

void setup() {
  pinMode(stage_button, INPUT);
  pinMode(brakes_switch, INPUT);
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
  
  attachInterrupt(digitalPinToInterrupt(brakes_switch), brakes_interupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(stage_button), stage_interupt, RISING);
}

void stage_interupt(){
  delay(delay_time);
  probe_value = digitalRead(brakes_switch);
  if(probe_value == HIGH){
    mySimpit.activateAction(STAGE_ACTION);
  }
}

void brakes_interupt(){
  delay(delay_time);
  probe_value = digitalRead(brakes_switch);
  if(probe_value == HIGH){
    mySimpit.activateAction(BRAKES_ACTION);
  } else {
    mySimpit.deactivateAction(BRAKES_ACTION);
  }
}



void loop() {
  mySimpit.update();
}
