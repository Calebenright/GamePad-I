// CJ
// EtherRush 2.0
// Gamepad - Advanced Protootyping

int curMode = -1;
#include <Bounce2.h>
#include <Metro.h>
#include "frame.h"
#include "screen.h"
#include "tile.h"
#include "controls.h"

// FOUND ONLINE TO PLAY MUSIC
#include "melodies.h"
//

#include "interactions.h"
#include "status.h"
#include "hero.h"
#include "enemy.h"
#include "fight.h"
#include "modes.h"

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A9));
  initScreen();
  initControls();
  initNeighbors();
}

void loop() {
  checkFrame();
  getControls();
  runMode();
}
