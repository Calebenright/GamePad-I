#include "CryptoPunk_MASK.h"
#include "CryptoPunk_PIX.h"
#include "BitKing_MASK.h"
#include "BitKing_PIX.h"

int enemyMargin = 1;
int enemyStatus = 1;
int enemyType = 0;
float enemyX = random(70, 150);
float enemyY = random(50, 100);
float enemyXDir = 0;
float enemyYDir = 0;
int enemyW = 24;
int enemyH = 40;
int enemyFrame = 0;
boolean enemyFire = false;
int randomNum;
int enemyHealth = 5;
boolean isDrawEnemy = true;
boolean coin4Hit = false;

int enemyInHealth[1][5] {{10, 10, 10, 10, 10,},};

Metro enemyFrameTimer = Metro(250);
Metro enemyBrainTimer = Metro(1000);
Metro coin4HitTimer = Metro(1000);

void drawEnemy(int enemySmart, float enemySpeed, int enemyNum) {

  if (enemyInHealth[0][enemyNum] != 0) {
    // ENEMY AI
    if (enemyBrainTimer.check()) {
      randomNum = random(0, enemySmart);
      if (randomNum == 0) {
        enemyXDir = random(-1, 2);
        enemyYDir = random(-1, 2);
      } else {

        if (enemyX > heroX - 10) {
          enemyXDir = -1;
        }
        else if (enemyX < heroX + 10) {
          enemyXDir = 1;
        }
        else {
          enemyXDir = 0;
        }

        if (enemyY > heroY - 10) {
          enemyYDir = -1;
        }
        else if (enemyY < heroY + 10) {
          enemyYDir = 1;
        }
        else {
          enemyYDir = 0;
        }
      }
    }

    // MOVES THE ENEMY
    float nextX = enemyX + (enemyXDir * enemySpeed);
    float nextY = enemyY + (enemyYDir * enemySpeed);

    if (coin4Hit == false) {
      if (curMode == 4) {
        enemyX = nextX;
        enemyY = nextY;
      } else if (checkMove(curMode, nextX, nextY, enemyW, enemyH) == true) {
        enemyX = nextX;
        enemyY = nextY;
      }
    } else {
      enemyXDir = enemyXDir * -1;
      if (coin4HitTimer.check()) {
        coin4Hit = false;
      }
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
    // DRAWS ENEMY
    tft.setClipRect(enemyX - 2, enemyY - 2, 28, 44);
    tft.drawRGBBitmap(enemyX, enemyY, CryptoPunk_PIX[enemyFrame], CryptoPunk_MASK[enemyFrame], enemyW, enemyH);
    tft.updateScreen();
  }
  else {
    // REMOVES ENEMY
    tft.setClipRect(enemyX - 2, enemyY - 2, 28, 44);
    drawLevels(curMode + 1);
    tft.updateScreen();
    enemyX = -20;
    enemyY = -40;
  }
}

void drawBitKing(int enemySmart, float enemySpeed, int enemyNum) {
  
  if (enemyInHealth[0][enemyNum] != 0) {
    // ENEMY AI
    if (enemyBrainTimer.check()) {
      randomNum = random(0, enemySmart);
      if (randomNum == 0) {
        enemyXDir = random(-1, 2);
        enemyYDir = random(-1, 2);
      } else {

        if (enemyX > heroX - 10) {
          enemyXDir = -1;
        }
        else if (enemyX < heroX + 10) {
          enemyXDir = 1;
        }
        else {
          enemyXDir = 0;
        }

        if (enemyY > heroY - 10) {
          enemyYDir = -1;
        }
        else if (enemyY < heroY + 10) {
          enemyYDir = 1;
        }
        else {
          enemyYDir = 0;
        }
      }
    }

    // MOVES ENEMY
    float nextX = enemyX + (enemyXDir * enemySpeed);
    float nextY = enemyY + (enemyYDir * enemySpeed);

    if (coin4Hit == false) {
      if (curMode == 4) {
        enemyX = nextX;
        enemyY = nextY;
      } else if (checkMove(curMode, nextX, nextY, enemyW, enemyH) == true) {
        enemyX = nextX;
        enemyY = nextY;
      }
    } else {
      if (coin4HitTimer.check()) {
        coin4Hit = false;
      }
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

    // DRAWS ENEMY
    tft.setClipRect(enemyX - 2, enemyY - 2, 28, 44);
    tft.drawRGBBitmap(enemyX, enemyY, BitKing_PIX[enemyFrame], BitKing_MASK[enemyFrame], enemyW, enemyH);
    tft.updateScreen();

  } else {
    
    // REMOVES ENEMY
    tft.setClipRect(enemyX - 2, enemyY - 2, 28, 44);
    drawLevels(curMode + 1);
    tft.updateScreen();
    enemyX = -20;
    enemyY = -40;
    curMode = -2;
  }
}
