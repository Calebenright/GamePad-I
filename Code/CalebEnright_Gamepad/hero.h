#include "mainChar_MASK.h"
#include "mainChar_PIX.h"

//START
//float heroX = 160;
//float heroY = 190;

float heroX = 159;
float heroY = 189;
float heroSpeed = .3;
float xMax = 260;
float xMin = 5;
float yMax = 190;
float yMin = -10;
boolean heroDir = true;
int heroFrame = 0;
float heroMidX = heroX + 10;
float heroMidY = heroY + 20;
float nextX;
float nextY;

Metro heroAnim = Metro(100);

void drawHero() {

  nextX = heroX + (float(joystickBuffer[0]) * heroSpeed);
  nextY = heroY + (float(joystickBuffer[1]) * heroSpeed);

  //  Check Neighbors

  if (checkMove(curMode, nextX, nextY, mainChar_W, mainChar_H) == true) {
    heroX = nextX;
    heroY = nextY;
  }

  // DAMAGE TEST
//  if (heroX < 40 && heroY > 120 && heroY < 140) {
//    if (!isDamaged) {
//      damageNum++;
//    }
//    isDamaged = true;
//  } else {
//    isDamaged = false;
//  }

  // PICKUPS


  // BOUNDARIES
  if (xMax < heroX) {
    heroX = 260;
  }
  if (heroX < xMin) {
    heroX = 5;
  }
  if (yMax < heroY) {
    heroY = 190;
  }
  if (heroY < yMin) {
    heroY = -10;
  }

  //   MOVEMENT
  if (joystickBuffer[0] == -1 && joystickBuffer[1] == 1) {
    //  heroX = heroX - heroSpeed * 3 / 4;
    //  heroY = heroY + heroSpeed * 3 / 4;
    heroDir = false;
  } else if (joystickBuffer[0] == 1 && joystickBuffer[1] == -1) {
    //  heroX = heroX + heroSpeed * 3 / 4;
    //  heroY = heroY - heroSpeed * 3 / 4;
    heroDir = true;
  } else if (joystickBuffer[0] == 1 && joystickBuffer[1] == 1) {
    //  heroX = heroX + heroSpeed * 3 / 4;
    //  heroY = heroY + heroSpeed * 3 / 4;
    heroDir = true;
  } else if (joystickBuffer[0] == -1 && joystickBuffer[1] == -1) {
    //  heroX = heroX - heroSpeed * 3 / 4;
    //  heroY = heroY - heroSpeed * 3 / 4;
    heroDir = false;
  } else if (joystickBuffer[1] == 1) {
    //  heroY = heroY + heroSpeed;
  } else if (joystickBuffer[0] == 1) {
    //  heroX = heroX + heroSpeed;
    heroDir = true;
  } else if (joystickBuffer[1] == -1) {
    //  heroY = heroY - heroSpeed;
  } else if (joystickBuffer[0] == -1) {
    //  heroX = heroX - heroSpeed;
    heroDir = false;
  } else {
    if (heroDir) {
      heroFrame = 0;
    } else {
      heroFrame = 4;
    }
  }

  // ANIMATION
  if (heroAnim.check()) {
    if (joystickBuffer[0] != 0 || joystickBuffer[1] != 0) {
      if (heroDir == true) {
        heroFrame = (heroFrame + 1) % 4;
      } else {
        heroFrame = ((heroFrame + 1) % 4) + 4;
        //        Serial.println(heroFrame);
      }
    }
  }

  tft.setClipRect(heroX - 1, heroY - 1, 26, 42);
  tft.drawRGBBitmap(heroX, heroY, mainChar_PIX[heroFrame], mainChar_MASK[heroFrame], mainChar_W, mainChar_H);
  tft.updateScreen();


}
