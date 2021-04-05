#include <Bounce2.h>
int buttonBounce = 10;
Bounce * buttons = new Bounce[4];

int buttonPins[4] = {0, 1, 2, 3};
int buttonBuffer[4] = {0, 0, 0, 0};

int joystickPins[2] = {A0, A1};
int joystickBuffer[2] = {0, 0};



void initControls() {
  for (int i = 0; i < 4; i++) {
    buttons[i].attach(buttonPins[i], INPUT_PULLUP);
    buttons[i].interval(buttonBounce);
  }
}

void getControls() {
  for (int i = 0; i < 4; i++) {
    buttons[i].update();
    if (buttons[i].fell()) {
      buttonBuffer[i] = 1;
    }
    if (buttons[i].rose()) {
      buttonBuffer[i] = 0;
    }
  }
  for (int i = 0; i < 2; i++) {
    joystickBuffer[i] = analogRead(joystickPins[i]);
  }
   Serial.println("joystick" + joystickBuffer[0]);
   Serial.println("button" + buttonBuffer[3]);
}
