// CJ
// EtherRush
// Gamepad - Advanced Protootyping

#include <Metro.h>
#include "frame.h"
#include "screen.h"
#include "tile.h"
#include "controls.h"
#include "hero.h"

void setup() {
  Serial.begin(9600);
  initScreen();
//  initControls();
}

void loop() {
  checkFrame();
  screenTest();
//  drawLevels(0);
//  getControls();
  tft.updateScreen();

}
