#include "introScreen_MASK.h"
#include "introScreen_PIX.h"

int curMode = -1;
boolean initIntro = false;

void introScreen() {
  if (initIntro == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    tft.drawRGBBitmap(0, 0, introScreen_PIX[0], screenW, screenH);
    tft.updateScreen();
    initIntro = true;
  }
  if (buttonBuffer[0] == 1 || buttonBuffer[1] == 1 || buttonBuffer[2] == 1 || buttonBuffer[3] == 1) {
    curMode = 0;
  }
}


void nextFirstLevel() {
  // NEXT LEVELS
  if (heroX > 250 && heroY > 170 && heroY < 175) {
    isLevelDrawn = false;
    curMode = 1;
    heroX = 13;
    heroY = 180;
  }
}

void nextSecondLevel() {
  // NEXT LEVELS
  if (heroX < 11 && heroY > 170 && heroY < 175) {
    isLevelDrawn = false;
    curMode = 0;
    heroX = 245;
    heroY = 176;
  }
}
void nextThirdLevel() {
  // NEXT LEVELS
  if (heroX > 155 && heroX < 165 && heroY < 10) {
    isLevelDrawn = false;
    curMode = 2;
    heroX = 160;
    heroY = 188;
  }
}
void nextThirdLevelBack() {
  // NEXT LEVELS
  if (heroX > 155 && heroX < 165 && heroY > 189) {
    isLevelDrawn = false;
    curMode = 0;
    heroX = 160;
    heroY = 11;
  }
}

void firstLevel() {
  if (!isLevelDrawn) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevels(1);
    tft.updateScreen();
    Serial.println("Screen Drawn");
    isLevelDrawn = true;
  }
  drawLevels(1);
  drawHero(curMode);
  nextFirstLevel();
  nextThirdLevel();
}

void secondLevel() {
  if (!isLevelDrawn) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevels(2);
    tft.updateScreen();
    Serial.println("Screen Drawn");
    isLevelDrawn = true;
  }
  drawLevels(2);
  drawHero(curMode);
  nextSecondLevel();
}

void thirdLevel() {
  if (!isLevelDrawn) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevels(3);
    tft.updateScreen();
    Serial.println("Screen Drawn");
    isLevelDrawn = true;
  }
  drawLevels(3);
  drawHero(curMode);
  nextThirdLevelBack();
}


void runMode() {
  switch (curMode) {
    case -1: introScreen(); break;
    case 0: firstLevel(); break;
    case 1: secondLevel(); break;
    case 2: thirdLevel(); break;
  }
}
