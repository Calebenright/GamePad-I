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
  float shootSpeed = 2;
  float shootingDir;
  boolean coinDam;


// Check to See if Hero & Enemies Collide
  boolean checkCollide(int hX, int hY, int hW, int hH, int eX, int eY, int eW, int eH){
  canFight = false;           // Assume a move can be made
  boolean xMin = false; if(hX < eX + eW){xMin = true;}               // Does the xMin collide?
  boolean xMax = false; if(hX + hW > eX){xMax = true;}               // Does the xMax collide?
  boolean yMin = false; if(hY < eY + eH){yMin = true;}               // Does the yMin collide?
  boolean yMax = false; if(hY + hH > eY){yMax = true;}               // Does the yMin collide?
  if (xMin && xMax && yMin && yMax) {canFight = true;}
  return canFight;
}

// IF HERO AND ENEMY COLLIDE, DEAL DAMAGE
void fight(){
  canFight = checkCollide(heroX, heroY, mainChar_W, mainChar_H, enemyX, enemyY, enemyW, enemyH);
  if(canFight == true){
      if (!isDamaged) {
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
void shoot(){
    if(isShooting == false){
      if (buttons[3].fell() == 1){
        coinDam = true;
        coinX = heroX+5;
        coinY = heroY+10;
        coin2X = heroX+5;
        coin2Y = heroY+10;
        coin3X = heroX+5;
        coin3Y = heroY+10;
        coin4X = heroX+5;
        coin4Y = heroY+10;
        if(heroDir==true){
        shootingDir = 1;
        } else {
        shootingDir = -1;
        }
        isShooting = true;
      }
      if(coinSwitchReset){
            tft.setClipRect(coinX - 2, coinY - 2, 20, 20);
            drawLevels(curMode+1);
            tft.updateScreen();
            tft.setClipRect(coin2X - 2, coin2Y - 2, 20, 20);
            drawLevels(curMode+1);
            tft.updateScreen();
            tft.setClipRect(coin3X - 2, coin3Y - 2, 20, 20);
            drawLevels(curMode+1);
            tft.updateScreen();
            tft.setClipRect(coin4X - 2, coin4Y - 2, 20, 20);
            drawLevels(curMode+1);
            tft.updateScreen();
            coinSwitchReset = false;
      }
   }

  // CONTROLS WHICH COIN IS SHOT
  if(isShooting == true){
    if(coinNum == 0){
      if(chest1){
      coinX = coinX + (shootingDir * shootSpeed);
      tft.setClipRect(coinX-2, coinY-2, 20, 20);
      tft.drawRGBBitmap(coinX, coinY, Coins_PIX[0], Coins_MASK[0], 16, 16);
      tft.updateScreen();
      }
    }
     if(coinNum == 1){
      if(chest2){
      shootSpeed = 3;
      coinY = coinY - shootSpeed;
      coin2Y = coin2Y + shootSpeed;
      tft.setClipRect(coinX-2, coinY-2, 20, 20);
      drawLevels(curMode+1);
      tft.drawRGBBitmap(coinX, coinY, Coins_PIX[4], Coins_MASK[4], 16, 16);
      tft.updateScreen();
      tft.setClipRect(coin2X-2, coin2Y-2, 20, 20);
      drawLevels(curMode+1);
      tft.drawRGBBitmap(coin2X, coin2Y, Coins_PIX[4], Coins_MASK[4], 16, 16);
      tft.updateScreen();
      }
    }
    if(coinNum == 2){
      if(chest3){
      coinX = shootingDir * (coinX + shootSpeed);
      coinY = shootingDir * (coinY + shootSpeed);
      tft.setClipRect(coinX-2, coinY-2, 20, 20);
      tft.drawRGBBitmap(coinX, coinY, Coins_PIX[3], Coins_MASK[3], 16, 16);
      tft.updateScreen();
      }
    }
     if(coinNum == 3){
      if(chest4){
      coinX = coinX + (shootingDir * shootSpeed);
      tft.setClipRect(coinX-2, coinY-2, 20, 20);
      tft.drawRGBBitmap(coinX, coinY, Coins_PIX[2], Coins_MASK[2], 16, 16);
      tft.updateScreen();
      }
    }
    if(coinNum == 4){
      if(chest5){
      shootSpeed = 5;
      coinX = coinX + shootSpeed;
      coin2X = coin2X - shootSpeed;
      coin3Y = coin3Y + shootSpeed;
      coin4Y = coin4Y - shootSpeed;
      tft.setClipRect(coinX-2, coinY-2, 20, 20);
      drawLevels(curMode+1);
      tft.drawRGBBitmap(coinX, coinY, Coins_PIX[1], Coins_MASK[1], 16, 16);
      tft.updateScreen();
      tft.setClipRect(coin2X-2, coin2Y-2, 20, 20);
      drawLevels(curMode+1);
      tft.drawRGBBitmap(coin2X, coin2Y, Coins_PIX[1], Coins_MASK[1], 16, 16);
      tft.updateScreen();
      tft.setClipRect(coin3X-2, coin3Y-2, 20, 20);
      drawLevels(curMode+1);
      tft.drawRGBBitmap(coin3X, coin3Y, Coins_PIX[1], Coins_MASK[1], 16, 16);
      tft.updateScreen();
      tft.setClipRect(coin4X-2, coin4Y-2, 20, 20);
      tft.drawRGBBitmap(coin4X, coin4Y, Coins_PIX[1], Coins_MASK[1], 16, 16);
      tft.updateScreen();
      }
    }
  }

    // COIN BOUNDARIES
  if (xMax < coinX || coinX < xMin || yMax < coinY || coinY < yMin) {
    isShooting = false;
    if(coinNum == 4){
    tft.setClipRect(coin2X - 2, coin2Y - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    tft.setClipRect(coin3X - 2, coin3Y - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    tft.setClipRect(coin4X - 2, coin4Y - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    }
    if(coinNum == 1){
    tft.setClipRect(coin2X - 2, coin2Y - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    }
    tft.setClipRect(coinX - 2, coinY - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
  }
}

// DEALS DAMAGE TO ENEMY WHEN HIT BY COIN
void coinHit(int eNum){
  if (coinX+5 > enemyX && coinX+5 < enemyX + enemyW && coinY+10 > enemyY && coinY+10 < enemyY + enemyH){
    isShooting = false;
    tft.setClipRect(coinX - 2, coinY - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    tft.setClipRect(coin2X - 2, coin2Y - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    tft.setClipRect(coin3X - 2, coin3Y - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    tft.setClipRect(coin4X - 2, coin4Y - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    if (coinDam == true){
      if (coinNum == 3){
        enemyInHealth[0][eNum] -= .5;
        coin4Hit = true;
      } else {
        enemyInHealth[0][eNum] -= 1;
      }
    coinDam = false;
    }
  }
    if (coin2X+5 > enemyX && coin2X+5 < enemyX + enemyW && coin2Y+10 > enemyY && coin2Y+10 < enemyY + enemyH){
    isShooting = false;
    tft.setClipRect(coinX - 2, coinY - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    tft.setClipRect(coin2X - 2, coin2Y - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    tft.setClipRect(coin3X - 2, coin3Y - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    tft.setClipRect(coin4X - 2, coin4Y - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    if (coinDam == true){
    enemyInHealth[0][eNum] -= 1;
    coinDam = false;
    }
  }
    if (coin3X+5 > enemyX && coin3X+5 < enemyX + enemyW && coin3Y+10 > enemyY && coin3Y+10 < enemyY + enemyH){
    isShooting = false;
    tft.setClipRect(coinX - 2, coinY - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    tft.setClipRect(coin2X - 2, coin2Y - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    tft.setClipRect(coin3X - 2, coin3Y - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    tft.setClipRect(coin4X - 2, coin4Y - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    if (coinDam == true){
    enemyInHealth[0][eNum] -= 1;
    coinDam = false;
    }
  }
    if (coin4X+5 > enemyX && coin4X+5 < enemyX + enemyW && coin4Y+10 > enemyY && coin4Y+10 < enemyY + enemyH){
    isShooting = false;
    tft.setClipRect(coinX - 2, coinY - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    tft.setClipRect(coin2X - 2, coin2Y - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    tft.setClipRect(coin3X - 2, coin3Y - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    tft.setClipRect(coin4X - 2, coin4Y - 2, 20, 20);
    drawLevels(curMode+1);
    tft.updateScreen();
    if (coinDam == true){
    enemyInHealth[0][eNum] -= 1;
    coinDam = false;
    }
  }
}
