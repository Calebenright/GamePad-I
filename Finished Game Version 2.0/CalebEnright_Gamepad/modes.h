#include "introScreen_MASK.h"
#include "introScreen_PIX.h"
#include "WinScreen_MASK.h"
#include "WinScreen_PIX.h"
#include "LoseScreen_MASK.h"
#include "LoseScreen_PIX.h"
boolean initIntro = false;
boolean initLose = false;
boolean initWin = false;

// Resets All The Game Values
void gameReset(){
isDamaged = false;
isDamaged2 = false;
chest1 = false;
chest2 = false;
chest3 = false;
chest4 = false;
chest5 = false;
coinNum = 0;
for (int i = 0; i<5; i++){
  enemyInHealth[0][i] = 10;
  }
}

// Shows The Intro Screen
void introScreen() {
  gameReset();
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

// THESE SWITCH THE LEVELS AUTOMATICALLY (I PREFER IT BEING AUTOMATICALLY)

void nextLevel2() {
  // NEXT LEVEL 2
  if (heroX > 250 && heroY > 170 && heroY < 175) {
    isLevelDrawn = false;
    curMode = 1;
    heroX = 13;
    heroY = 180;
    isShooting = false;
  }
}

void nextLevel2Back() {
  // FROM LEVEL 2 BACK TO 1
  if (heroX < 11 && heroY > 170 && heroY < 175) {
    isLevelDrawn = false;
    curMode = 0;
    heroX = 245;
    heroY = 176;
    isShooting = false;
  }
}
void nextLevel3() {
  // NEXT LEVEL 3
  if (heroX > 155 && heroX < 165 && heroY < -9) {
    isLevelDrawn = false;
    enemyX = random(100,300);
    enemyY = random(85,110);
    curMode = 2;
    heroX = 160;
    heroY = 188;
    isShooting = false;
  }
}
void nextLevel3Back1() {
  // FROM LEVEL 3 BACK TO LEVEL 1
  if (heroX > 155 && heroX < 165 && heroY > 189) {
    isLevelDrawn = false;
    curMode = 0;
    heroX = 160;
    heroY = 11;
    isShooting = false;
  }
}

void nextLevel4() {
  // NEXT LEVEL 4
  if (heroX > 215 && heroX < 225 && heroY < -9) {
    isLevelDrawn = false;
    enemyX = random(100,200);
    enemyY = 60;
    curMode = 3;
    heroX = 220;
    heroY = 188;
    isShooting = false;
  }
}

void nextLevel4Back3() {
  // FROM LEVEL 4 BACK TO LEVEL 3
  if (heroX > 215 && heroX < 225 && heroY > 189) {
    isLevelDrawn = false;
    enemyX = random(100,300);
    enemyY = random(85,130);
    curMode = 2;
    heroX = 220;
    heroY = 0;
    isShooting = false;
  }
}

void nextLevel5() {
  // NEXT LEVEL 5
  if (heroX < 11 && heroY > 155 && heroY < 165) {
    isLevelDrawn = false;
    enemyX = random(50,200);
    enemyY = random(10,150);
    heroX = 239;
    heroY = 160;
    curMode = 4;
    isShooting = false;
  }
}

void nextLevel5Back4() {
  // FROM LEVEL 5 BACK TO LEVEL 3
  if (heroX > 240 && heroY < 165 && heroY > 155) {
    isLevelDrawn = false;
    enemyX = random(50,1500);
    enemyY = random(80,150);
    heroX = 12;
    heroY = 160;
    curMode = 2;
    isShooting = false;
  }
}

void nextLevel6back5() {
  // FROM LEVEL 6 BACK TO LEVEL 5
  if (heroX > 250 && heroY < 165 && heroY > 155) {
    isLevelDrawn = false;
    enemyX = random(50,200);
    enemyY = random(10,150);
    heroX = 12;
    heroY = 160;
    curMode = 4;
    isShooting = false;
  }
}

void nextLevel6() {
  // NEXT LEVEL 6
  if (heroX < 11 && heroY > 155 && heroY < 165) {
    isLevelDrawn = false;
    enemyX = random(70,171);
    enemyY = random(10,100);
    heroX = 239;
    heroY = 160;
    curMode = 5;
    isShooting = false;
  }
}


// LEVELS

// LEVEL1
void firstLevel() {
   heroSpeed = .9;
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
  shoot();
  nextLevel2();
  nextLevel3();
}

// LEVEL 2
void secondLevel() {
  heroSpeed = .9;
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
  updateHealth(damageNum);
  shoot();
  nextLevel2Back();
}

// LEVEL 3
void thirdLevel() {
  heroSpeed = 1;
  if (!isLevelDrawn) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevels(3);
    tft.updateScreen();
    isLevelDrawn = true;
  }
  drawLevels(3);
  pickup(curMode, heroX, heroY);
  drawHero();
  drawLevels(3);
  drawEnemy(5,.35,0);
  drawLevels(3);
  selectCoin();
  coinHit(0);
  fight();
  updateHealth(damageNum);
  shoot();
  nextLevel3Back1();
  nextLevel4();
  nextLevel5();
}

// LEVEL 4
void fourthLevel() {
  heroSpeed = 1;
  if (!isLevelDrawn) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevels(4);
    tft.updateScreen();
    isLevelDrawn = true;
  }
  fight();
  drawLevels(4);
  pickup(curMode, heroX, heroY);
  drawHero();
  drawLevels(4);
  coinHit(2);
  drawEnemy(5,.35,2);
  drawLevels(4);
  selectCoin();
  updateHealth(damageNum);
  drawLevels(4);
  shoot();
  nextLevel4Back3();
}

// LEVEL 5
void fifthLevel() {
  heroSpeed = 1;
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
  coinHit(1);
  drawEnemy(3,.4,1);
  drawLevels(5);
  selectCoin();
  updateHealth(damageNum);
  drawLevels(5);
  shoot();
  nextLevel5Back4(); 
  nextLevel6();
}

// LEVEL 6
void sixthLevel() {
  heroSpeed = 1;
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
  coinHit(4);
  drawBitKing(2,.6, 4);
  drawLevels(6);
  selectCoin();
  updateHealth(damageNum);
  shoot();
  nextLevel6back5();
}


// SHOWS THE WIN IMAGE
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

//SHOWS THE DEATH IMAGE
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

void runMode() {
  switch (curMode) {
    case -3: deathScreen(); break;
    case -2: winScreen(); break;
    case -1: introScreen(); break;
    case 0: firstLevel(); break;
    case 1: secondLevel(); break;
    case 2: thirdLevel(); break;
    case 3: fourthLevel(); break;
    case 4: fifthLevel(); break;
    case 5: sixthLevel(); break;
  }
}
