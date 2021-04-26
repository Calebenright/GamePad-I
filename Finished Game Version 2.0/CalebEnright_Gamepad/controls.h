
int buttonBounce = 10;
Bounce * buttons = new Bounce[4];

int buttonPins[4] = {0, 1, 2, 3};
int buttonBuffer[4] = {0, 0, 0, 0};

int joystickPins[2] = {A0, A1};
int joystickBuffer[2] = {0, 0};

int piezoPin = A4;

Metro controlT = Metro(100);

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
    if (joystickBuffer[i] > 700){
      joystickBuffer[i] = -1;
    } else if (joystickBuffer[i] < 150){
      joystickBuffer[i] = 1;
    } else {
      joystickBuffer[i] = 0;
    }
  }

// CHECK CONTROLS
//
//  if (controlT.check()) {
//    // right & left
//    // middle from 470-560
//    Serial.println(joystickBuffer[0]);
//    Serial.println(analogRead(joystickPins[0]));
//    // up & down
//    // middle from 470-560
//    Serial.println(joystickBuffer[1]);
//    Serial.println(analogRead(joystickPins[1]));
//    // Top Button
//    Serial.println(buttonBuffer[0]);
//    // Right Button
//    Serial.println(buttonBuffer[1]);
//    // Left Button
//    Serial.println(buttonBuffer[2]);
//    // Bottom Button
//    Serial.println(buttonBuffer[3]);
//  }
}
