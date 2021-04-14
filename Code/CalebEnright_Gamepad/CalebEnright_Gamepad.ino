// CJ
// EtherRush
// Gamepad - Advanced Protootyping

#include <Metro.h>
#include "frame.h"
#include "screen.h"
#include "tile.h"
#include "controls.h"
#include "interactions.h"
#include "status.h"
#include "hero.h"
#include "modes.h"

void setup() {
  Serial.begin(9600);
  initScreen();
  initControls();
  initNeighbors();
}

void loop() {
  checkFrame();
  getControls();
  runMode();
}
