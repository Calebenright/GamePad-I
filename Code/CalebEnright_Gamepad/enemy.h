#include "CryptoPunk_MASK.h"
#include "CryptoPunk_PIX.h"
#include "BitKing_MASK.h"
#include "BitKing_PIX.h"

int enemyMargin = 1;
int enemyStatus = 1;
int enemyType = 0;
float enemyX = random(70,171);
float enemyY = random(10,100);
float enemyXDir = 0;
float enemyYDir = 0;
int enemyW = 24;
int enemyH = 40;
int enemyFrame = 0;
boolean enemyFire = false;
int randomNum;

Metro enemyFrameTimer = Metro(250);
Metro enemyBrainTimer = Metro(1000);

void drawEnemy(int enemySmart, int enemyHealth, float enemySpeed) {
  if (enemyBrainTimer.check()) {
    randomNum = random(0, enemySmart);
    if (randomNum == 0) {
      enemyXDir = random(-1, 2);
      enemyYDir = random(-1, 2);
    } else {

      if (enemyX > heroX-10) {
        enemyXDir = -1;
      }
      else if (enemyX < heroX+10) {
        enemyXDir = 1;
      }
      else {
        enemyXDir = 0;
      }

      if (enemyY > heroY-10) {
        enemyYDir = -1;
      }
      else if (enemyY < heroY+10) {
        enemyYDir = 1;
      }
      else {
        enemyYDir = 0;
      }
    }
   }

    float nextX = enemyX + (enemyXDir * enemySpeed);
    float nextY = enemyY + (enemyYDir * enemySpeed);
    
    if (curMode == 4){
      enemyX = nextX;
      enemyY = nextY;
    } else if (checkMove(curMode, nextX, nextY, enemyW, enemyH) == true) {
      enemyX = nextX;
      enemyY = nextY;
    } 

    // BOUNDARIES
    if (xMax < enemyX) {
      enemyX = 260;
    }
    if (enemyX < xMin) {
      enemyX = 5;
    }
    if (yMax < enemyY) {
      enemyY = 190;
    }
    if (enemyY < yMin) {
      enemyY = -10;
    }

    // ANIMATION
    if (enemyFrameTimer.check()) {
        if (enemyXDir == true) {
          enemyFrame = (enemyFrame + 1) % 3;
        } else {
          enemyFrame = ((enemyFrame + 1) % 3) + 3;
        }
      }


    tft.setClipRect(enemyX - 2, enemyY - 2, 28, 44);
    tft.drawRGBBitmap(enemyX, enemyY, CryptoPunk_PIX[enemyFrame], CryptoPunk_MASK[enemyFrame], enemyW, enemyH);
    tft.updateScreen();
}

void drawBitKing(int enemySmart, int enemyHealth, float enemySpeed) {
  if (enemyBrainTimer.check()) {
    randomNum = random(0, enemySmart);
    if (randomNum == 0) {
      enemyXDir = random(-1, 2);
      enemyYDir = random(-1, 2);
    } else {

      if (enemyX > heroX-10) {
        enemyXDir = -1;
      }
      else if (enemyX < heroX+10) {
        enemyXDir = 1;
      }
      else {
        enemyXDir = 0;
      }

      if (enemyY > heroY-10) {
        enemyYDir = -1;
      }
      else if (enemyY < heroY+10) {
        enemyYDir = 1;
      }
      else {
        enemyYDir = 0;
      }
    }
   }

    float nextX = enemyX + (enemyXDir * enemySpeed);
    float nextY = enemyY + (enemyYDir * enemySpeed);
    
    if (curMode == 4){
      enemyX = nextX;
      enemyY = nextY;
    } else if (checkMove(curMode, nextX, nextY, enemyW, enemyH) == true) {
      enemyX = nextX;
      enemyY = nextY;
    } 

    // BOUNDARIES
    if (xMax < enemyX) {
      enemyX = 260;
    }
    if (enemyX < xMin) {
      enemyX = 5;
    }
    if (yMax < enemyY) {
      enemyY = 190;
    }
    if (enemyY < yMin) {
      enemyY = -10;
    }

    // ANIMATION
    if (enemyFrameTimer.check()) {
        if (enemyXDir == true) {
          enemyFrame = (enemyFrame + 1) % 3;
        } else {
          enemyFrame = ((enemyFrame + 1) % 3) + 3;
        }
      }


    tft.setClipRect(enemyX - 2, enemyY - 2, 28, 44);
    tft.drawRGBBitmap(enemyX, enemyY, BitKing_PIX[enemyFrame], BitKing_MASK[enemyFrame], enemyW, enemyH);
    tft.updateScreen();
}
