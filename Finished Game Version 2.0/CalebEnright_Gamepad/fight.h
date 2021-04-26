#include "Coins_MASK.h"
#include "Coins_PIX.h"

boolean canFight;
float coinX;
float coinY;
float coin2X;
float coin2Y;
float coin3X;
float coin3Y;
float coin4X;
float coin4Y;
float shootSpeed = 4;
float shootingDir;
boolean coinDam;
boolean isCoin1Off = false;
boolean isCoin2Off = false;
boolean isCoin3Off = false;
boolean isCoin4Off = false;
boolean isCoin1Hit = false;
boolean isCoin2Hit = false;
boolean isCoin3Hit = false;
boolean isCoin4Hit = false;


// Check to See if Hero & Enemies Collide
boolean checkCollide(int hX, int hY, int hW, int hH, int eX, int eY, int eW, int eH) {
  canFight = false;           // Assume a move can be made
  boolean xMin = false; if (hX < eX + eW) {
    xMin = true; // Does the xMin collide?
  }
  boolean xMax = false; if (hX + hW > eX) {
    xMax = true; // Does the xMax collide?
  }
  boolean yMin = false; if (hY < eY + eH) {
    yMin = true; // Does the yMin collide?
  }
  boolean yMax = false; if (hY + hH > eY) {
    yMax = true; // Does the yMin collide?
  }
  if (xMin && xMax && yMin && yMax) {
    canFight = true;
  }
  return canFight;
}

// IF HERO AND ENEMY COLLIDE, DEAL DAMAGE
void fight() {
  canFight = checkCollide(heroX, heroY, mainChar_W, mainChar_H, enemyX, enemyY, enemyW, enemyH);
  if (canFight == true) {
    if (!isDamaged) {
      tone(piezoPin, 5000, 100);
      damageNum++;
      isDamaged = true;
    }
    canFight = false;
  } else {
    isDamaged = false;
    canFight = true;
  }
}

// CRYPTO FIRING FUNCTION
void shoot() {
  if (isShooting == false) {
    if (coinSwitchReset) {
      tft.setClipRect(coinX - 2, coinY - 2, 20, 20);
      drawLevels(curMode + 1);
      tft.updateScreen();
      tft.setClipRect(coin2X - 2, coin2Y - 2, 20, 20);
      drawLevels(curMode + 1);
      tft.updateScreen();
      tft.setClipRect(coin3X - 2, coin3Y - 2, 20, 20);
      drawLevels(curMode + 1);
      tft.updateScreen();
      tft.setClipRect(coin4X - 2, coin4Y - 2, 20, 20);
      drawLevels(curMode + 1);
      tft.updateScreen();
      coinSwitchReset = false;
    }
    coinX = heroX + 5;
    coinY = heroY + 10;
    coin2X = heroX + 5;
    coin2Y = heroY + 10;
    coin3X = heroX + 5;
    coin3Y = heroY + 10;
    coin4X = heroX + 5;
    coin4Y = heroY + 10;

    if (buttons[3].fell() == 1) {
      coinDam = true;
      if (heroDir == true) {
        shootingDir = 1;
      } else {
        shootingDir = -1;
      }
      isShooting = true;
    }
  }

  // CONTROLS WHICH COIN IS SHOT
  if (isShooting == true) {
    if (coinNum == 0) {
      if (chest1) {
        coinX = coinX + (shootingDir * shootSpeed);
        tft.setClipRect(coinX - 5, coinY - 5, 25, 25);
        tft.drawRGBBitmap(coinX, coinY, Coins_PIX[0], Coins_MASK[0], 16, 16);
        tft.updateScreen();
      }
    }
    if (coinNum == 1) {
      if (chest2) {
        coinY = coinY - shootSpeed;
        coin2Y = coin2Y + shootSpeed;
        tft.setClipRect(coinX - 5, coinY - 5, 25, 25);
        drawLevels(curMode + 1);
        tft.drawRGBBitmap(coinX, coinY, Coins_PIX[4], Coins_MASK[4], 16, 16);
        tft.updateScreen();
        tft.setClipRect(coin2X - 5, coin2Y - 5, 25, 25);
        drawLevels(curMode + 1);
        tft.drawRGBBitmap(coin2X, coin2Y, Coins_PIX[4], Coins_MASK[4], 16, 16);
        tft.updateScreen();
      }
    }
    if (coinNum == 2) {
      if (chest3) {
        coinX = coinX + (shootingDir * shootSpeed);
        coinY = coinY + shootSpeed/2;
        coin2X = coin2X + (shootingDir * shootSpeed);
        coin2Y = coin2Y - shootSpeed/2;
        tft.setClipRect(coinX - 10, coinY - 10, 36, 36);
        drawLevels(curMode + 1);
        tft.drawRGBBitmap(coinX, coinY, Coins_PIX[3], Coins_MASK[3], 16, 16);
        tft.updateScreen();
        tft.setClipRect(coin2X - 10, coin2Y - 10, 36, 36);
        drawLevels(curMode + 1);
        tft.drawRGBBitmap(coin2X, coin2Y, Coins_PIX[3], Coins_MASK[3], 16, 16);
        tft.updateScreen();
      }
    }
    if (coinNum == 3) {
      if (chest4) {
        coinX = coinX + (shootingDir * shootSpeed);
        tft.setClipRect(coinX - 5, coinY - 5, 25, 25);
        tft.drawRGBBitmap(coinX, coinY, Coins_PIX[2], Coins_MASK[2], 16, 16);
        tft.updateScreen();
      }
    }
    if (coinNum == 4) {
      if (chest5) {
        coinX = coinX + shootSpeed;
        coin2X = coin2X - shootSpeed;
        coin3Y = coin3Y + shootSpeed;
        coin4Y = coin4Y - shootSpeed;
        tft.setClipRect(coinX - 10, coinY - 10, 36, 36);
        drawLevels(curMode + 1);
        tft.drawRGBBitmap(coinX, coinY, Coins_PIX[1], Coins_MASK[1], 16, 16);
        tft.updateScreen();
        tft.setClipRect(coin2X - 10, coin2Y - 10, 36, 36);
        drawLevels(curMode + 1);
        tft.drawRGBBitmap(coin2X, coin2Y, Coins_PIX[1], Coins_MASK[1], 16, 16);
        tft.updateScreen();
        tft.setClipRect(coin3X - 10, coin3Y - 10, 36, 36);
        drawLevels(curMode + 1);
        tft.drawRGBBitmap(coin3X, coin3Y, Coins_PIX[1], Coins_MASK[1], 16, 16);
        tft.updateScreen();
        tft.setClipRect(coin4X - 10, coin4Y - 10, 36, 36);
        tft.drawRGBBitmap(coin4X, coin4Y, Coins_PIX[1], Coins_MASK[1], 16, 16);
        tft.updateScreen();
      }
    }
  }
 
  

  // COIN BOUNDARIES
  if (coinNum == 1 || coinNum == 2) {
    if (xMax+10 < coinX || coinX < xMin || yMax+10 < coinY || coinY < yMin) {
      isCoin1Off = true;
    }
    if (xMax+10 < coin2X || coin2X < xMin || yMax+10 < coin2Y || coin2Y < yMin) {
      isCoin2Off = true;
    }
    if (isCoin1Off && isCoin2Off) {
      tft.setClipRect(coin2X - 2, coin2Y - 2, 20, 20);
      drawLevels(curMode + 1);
      tft.updateScreen();
      tft.setClipRect(coinX - 2, coinY - 2, 20, 20);
      drawLevels(curMode + 1);
      tft.updateScreen();
      isShooting = false;
      isCoin2Off = false;
      isCoin1Off = false;
    }
  } else if (coinNum == 4) {
    if (xMax < coinX || coinX < xMin || yMax+10 < coinY || coinY < yMin) {
      isCoin1Off = true;
    }
    if (xMax < coin2X || coin2X < xMin || yMax+10 < coin2Y || coin2Y < yMin) {
      isCoin2Off = true;
    }
    if (xMax < coin3X || coin3X < xMin || yMax+10 < coin3Y || coin3Y < yMin) {
      isCoin3Off = true;
    }
    if (xMax < coin4X || coin4X < xMin || yMax+10 < coin4Y || coin4Y < yMin) {
      isCoin4Off = true;
    }
    if (isCoin1Off && isCoin2Off && isCoin3Off && isCoin4Off) {
      tft.setClipRect(coinX - 10, coinY - 10, 36, 36);
      drawLevels(curMode + 1);
      tft.updateScreen();
      tft.setClipRect(coin2X - 10, coin2Y - 10, 36, 36);
      drawLevels(curMode + 1);
      tft.updateScreen();
      tft.setClipRect(coin3X - 10, coin3Y - 10, 36, 36);
      drawLevels(curMode + 1);
      tft.updateScreen();
      tft.setClipRect(coin4X - 10, coin4Y - 10, 36, 36);
      drawLevels(curMode + 1);
      tft.updateScreen();
      isShooting = false;
      isCoin1Off = false;
      isCoin2Off = false;
      isCoin3Off = false;
      isCoin4Off = false;
    }
  } else {
    if (xMax < coinX || coinX < xMin || yMax+10 < coinY || coinY < yMin) {
      tft.setClipRect(coinX - 2, coinY - 2, 20, 20);
      drawLevels(curMode + 1);
      tft.updateScreen();
      isShooting = false;
    }
  }

}

// DEALS DAMAGE TO ENEMY WHEN HIT BY COIN
void coinHit(int eNum) {
  if (coinX + 5 > enemyX && coinX + 5 < enemyX + enemyW && coinY + 10 > enemyY && coinY + 10 < enemyY + enemyH) {
    if (coinDam == true) {
      if (coinNum == 3) {
        enemyInHealth[0][eNum] -= .5;
        coin4Hit = true;
      } else {
        enemyInHealth[0][eNum] -= 1;
      }
      coinDam = false;
    }
    isCoin1Hit = true;
  }
  if (coin2X + 5 > enemyX && coin2X + 5 < enemyX + enemyW && coin2Y + 10 > enemyY && coin2Y + 10 < enemyY + enemyH) {
    if (coinDam == true) {
      enemyInHealth[0][eNum] -= 1;
      coinDam = false;
    }
    isCoin2Hit = true;
  }
  if (coin3X + 5 > enemyX && coin3X + 5 < enemyX + enemyW && coin3Y + 10 > enemyY && coin3Y + 10 < enemyY + enemyH) {
    if (coinDam == true) {
      enemyInHealth[0][eNum] -= 1;
      coinDam = false;
    }
    isCoin3Hit = true;
  }
  if (coin4X + 5 > enemyX && coin4X + 5 < enemyX + enemyW && coin4Y + 10 > enemyY && coin4Y + 10 < enemyY + enemyH) {
    if (coinDam == true) {
      enemyInHealth[0][eNum] -= 1;
      coinDam = false;
    }
    isCoin4Hit = true;
  }

  if (isCoin1Hit || isCoin2Hit || isCoin3Hit || isCoin4Hit) {
    tft.setClipRect(coinX - 2, coinY - 2, 20, 20);
    drawLevels(curMode + 1);
    tft.updateScreen();
    tft.setClipRect(coin2X - 2, coin2Y - 2, 20, 20);
    drawLevels(curMode + 1);
    tft.updateScreen();
    tft.setClipRect(coin3X - 2, coin3Y - 2, 20, 20);
    drawLevels(curMode + 1);
    tft.updateScreen();
    tft.setClipRect(coin4X - 2, coin4Y - 2, 20, 20);
    drawLevels(curMode + 1);
    tft.updateScreen();
    isShooting = false;
    isCoin1Hit = false;
    isCoin2Hit = false;
    isCoin3Hit = false;
    isCoin4Hit = false;
  }
}
