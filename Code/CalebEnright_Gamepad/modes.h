#include "introScreen_MASK.h"
#include "introScreen_PIX.h"
#include "WinScreen_MASK.h"
#include "WinScreen_PIX.h"
#include "LoseScreen_MASK.h"
#include "LoseScreen_PIX.h"
boolean initIntro = false;
boolean initLose = false;
boolean initWin = false;


void introScreen() {
  initLose = false;
  initWin = false;
  isLevelDrawn = false;
  heroX = 159;
  heroY = 189;
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

void nextLevel2() {
  // NEXT LEVELS
  if (heroX > 250 && heroY > 170 && heroY < 175) {
    isLevelDrawn = false;
    curMode = 1;
    heroX = 13;
    heroY = 180;
  }
}

void nextLevel2Back() {
  // NEXT LEVELS
  if (heroX < 11 && heroY > 170 && heroY < 175) {
    isLevelDrawn = false;
    curMode = 0;
    heroX = 245;
    heroY = 176;
  }
}
void nextLevel3() {
  // NEXT LEVELS
  if (heroX > 155 && heroX < 165 && heroY < -9) {
    isLevelDrawn = false;
    enemyX = random(100,300);
    enemyY = random(85,110);
    curMode = 2;
    heroX = 160;
    heroY = 188;
  }
}
void nextLevel3Back1() {
  // NEXT LEVELS
  if (heroX > 155 && heroX < 165 && heroY > 189) {
    isLevelDrawn = false;
    curMode = 0;
    heroX = 160;
    heroY = 11;
  }
}

void nextLevel4() {
  // NEXT LEVELS
  if (heroX > 215 && heroX < 225 && heroY < -9) {
    isLevelDrawn = false;
    enemyX = random(100,300);
    enemyY = random(85,150);
    curMode = 3;
    heroX = 220;
    heroY = 188;
  }
}

void nextLevel4Back3() {
  // NEXT LEVELS
  if (heroX > 215 && heroX < 225 && heroY > 189) {
    isLevelDrawn = false;
    enemyX = random(100,300);
    enemyY = random(85,130);
    curMode = 2;
    heroX = 220;
    heroY = 0;
  }
}

void nextLevel5() {
  // NEXT LEVELS
  if (heroX < 11 && heroY > 155 && heroY < 165) {
    isLevelDrawn = false;
    enemyX = random(50,200);
    enemyY = random(10,150);
    heroX = 239;
    heroY = 160;
    curMode = 4;
  }
}

void nextLevel5Back4() {
  // NEXT LEVELS
  if (heroX > 240 && heroY < 165 && heroY > 155) {
    isLevelDrawn = false;
    enemyX = random(50,1500);
    enemyY = random(80,150);
    heroX = 12;
    heroY = 160;
    curMode = 2;
  }
}

void nextLevel6back5() {
  // NEXT LEVELS
  if (heroX > 250 && heroY < 165 && heroY > 155) {
    isLevelDrawn = false;
    enemyX = random(50,200);
    enemyY = random(10,150);
    heroX = 12;
    heroY = 160;
    curMode = 4;
  }
}

void nextLevel6() {
  // NEXT LEVELS
  if (heroX < 11 && heroY > 155 && heroY < 165) {
    isLevelDrawn = false;
    enemyX = random(70,171);
    enemyY = random(10,100);
    heroX = 239;
    heroY = 160;
    curMode = 5;
  }
}

void firstLevel() {
   heroSpeed = .6;
  if (!isLevelDrawn) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevels(1);
    tft.updateScreen();
    isLevelDrawn = true;
  }
  drawLevels(1);
  pickup(curMode, heroX, heroY);
  drawHero();
  drawLevels(1);
  selectCoin();
  updateHealth(damageNum);
  nextLevel2();
  nextLevel3();
}

void secondLevel() {
  heroSpeed = .6;
  if (!isLevelDrawn) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevels(2);
    tft.updateScreen();
    isLevelDrawn = true;
  }
  drawLevels(2);
  pickup(curMode, heroX, heroY);
  drawHero();
  drawLevels(2);
  selectCoin();
  mapDamage(curMode, heroX, heroY);
  updateHealth(damageNum);
  nextLevel2Back();
}

void thirdLevel() {
  heroSpeed = .8;
  if (!isLevelDrawn) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevels(3);
    tft.updateScreen();
    isLevelDrawn = true;
  }
  fight();
  drawLevels(3);
  pickup(curMode, heroX, heroY);
  drawHero();
  drawLevels(3);
  drawEnemy(5,1,.25);
  drawLevels(3);
  selectCoin();
  updateHealth(damageNum);
  nextLevel3Back1();
  nextLevel4();
  nextLevel5();
}

void fourthLevel() {
  heroSpeed = .8;
  if (!isLevelDrawn) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevels(4);
    tft.updateScreen();
    isLevelDrawn = true;
  }
  drawLevels(4);
  pickup(curMode, heroX, heroY);
  drawHero();
  drawLevels(4);
  selectCoin();
  updateHealth(damageNum);
  nextLevel4Back3();
}

void fifthLevel() {
  heroSpeed = .6;
  if (!isLevelDrawn) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevels(5);
    tft.updateScreen();
    isLevelDrawn = true;
  }
  fight();
  drawLevels(5);
  pickup(curMode, heroX, heroY);
  drawHero();
  drawLevels(5);
  drawEnemy(3,1,.25);
  drawLevels(5);
  selectCoin();
  updateHealth(damageNum);
  nextLevel5Back4(); 
  nextLevel6();
}

void sixthLevel() {
  heroSpeed = .8;
  if (!isLevelDrawn) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevels(6);
    tft.updateScreen();
    isLevelDrawn = true;
  }
  fight();
  drawLevels(6);
  drawHero();
  drawLevels(6);
  drawBitKing(2,5,.5);
  drawLevels(6);
  selectCoin();
  updateHealth(damageNum);
  nextLevel6back5();
}

void winScreen() {
  tft.setClipRect(0, 0, screenW, screenH);
  tft.drawRGBBitmap(0, 0, WinScreen_PIX[0], screenW, screenH);
  tft.updateScreen();
  damageNum = 0;
  initIntro = false;
  if (initWin == false) {
    delay(500);
    joystickBuffer[0] = 0;
    joystickBuffer[1] = 0;
    delay(500);
    initWin = true;
  }
  if (joystickBuffer[0] == 1 || joystickBuffer[1] == 1 || joystickBuffer[0] == -1 || joystickBuffer[1] == -1) {
    curMode = -1;
    delay(200);
  }
}

void deathScreen() {
  tft.setClipRect(0, 0, screenW, screenH);
  tft.drawRGBBitmap(0, 0, LoseScreen_PIX[0], screenW, screenH);
  tft.updateScreen();
  damageNum = 0;
  initIntro = false;
  if (initLose == false) {
    delay(500);
    joystickBuffer[0] = 0;
    joystickBuffer[1] = 0;
    delay(500);
    initLose = true;
  }
  if (joystickBuffer[0] == 1 || joystickBuffer[1] == 1 || joystickBuffer[0] == -1 || joystickBuffer[1] == -1) {
    curMode = -1;
    delay(200);
  }
}

void gameReset(){
  
}

void runMode() {
  switch (curMode) {
    case -3: deathScreen(); break;
    case -2: winScreen(); break;
    case -1: gameReset(); introScreen(); break;
    case 0: firstLevel(); break;
    case 1: secondLevel(); break;
    case 2: thirdLevel(); break;
    case 3: fourthLevel(); break;
    case 4: fifthLevel(); break;
    case 5: sixthLevel(); break;
  }
}
