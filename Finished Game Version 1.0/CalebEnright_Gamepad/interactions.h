#include "CoinsHUD_MASK.h"
#include "CoinsHUD_PIX.h"

boolean canMove;
boolean isDamaged = false;
boolean isDamaged2 = false;
boolean chest1 = false;
boolean chest2 = false;
boolean chest3 = false;
boolean chest4 = false;
boolean chest5 = false;
int coinNum = 0;
boolean isShooting = false;
boolean coinSwitchReset = false;
int whichTile;
int damageNum = 0;


// Generate an Array of Neighbors for Checking
int neighbors[192][8];

int interaction[6][tileW * tileH]{
  // LEVEL 1
  {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
  },
  // LEVEL 2
    {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x02, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
  },
  // LEVEL 3
      {
    0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x02, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x02, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
  },
  // LEVEL 4
      {
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 
    0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 
    0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 
    0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 
    0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 
    0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 
    0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 
    0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 
    0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 
  },
  // LEVEL 5
  {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0xFF, 0x02, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0xFF, 0x02, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0xFF, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
  },
  // LEVEL 6
     {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
  },
};

void initNeighbors(){
  for (int i = 0; i < tileW * tileH; i++){
    // General Rule
    int N = i - tileW; int NE = (i - tileW) + 1;  int E = i + 1;  int SE = (i + tileW) + 1;  
    int S = i + tileW; int SW = (i + tileW) - 1;  int W = i - 1;  int NW = (i - tileW) - 1;
    
    // Exceptions
    if(i < tileW){NW = -1; N = -1; NE = -1;}
    if(i > (tileW * tileH) - (tileW + 1)){SW = -1; S = -1; SE = -1;}
    if (i % tileW == 0){NW = -1; W = -1; SW = -1;}
    if ((i + 1) % tileW == 0){NE = -1; E = -1; SE = -1;}

    neighbors[i][0] = N;  neighbors[i][1] = NE;  neighbors[i][2] = E;  neighbors[i][3] = SE;  
    neighbors[i][4] = S;  neighbors[i][5] = SW;  neighbors[i][6] = W;  neighbors[i][7] = NW;  
  }
}

boolean checkMove(int curLevel, int curX, int curY, int curW, int curH){
int curTileX = curX / 20;
int curTileY = curY / 20;
int curTile = curTileX + (curTileY * tileW); 
canMove = true;
for (int i = 0; i < 8; i++){
  whichTile = neighbors[curTile][i];               // Get Current Neighbor    
  int neighborX = (whichTile % tileW) * tileSize;      // Get X Value of Neighbor
  int neighborY = (whichTile / tileW) * tileSize;      // Get Y Value of Neighbor
  boolean isOut = false; 
  boolean isxMin = false; 
  boolean isxMax = false; 
  boolean isyMin = false; 
  boolean isyMax = false; 
  if(interaction[curLevel][whichTile] == 0xFF){isOut = true;}
  if(curX < neighborX + tileSize){isxMin = true;}
  if(curX + curW > neighborX){isxMax = true;}
  if(curY < neighborY + tileSize){isyMin = true;}
  if(curY + curH > neighborY){isyMax = true;}
  if (isOut && isxMax && isxMin && isyMin && isyMax){canMove = false;}

// GETS INFORMATION
//    Serial.print("LVL:"); Serial.print(curLevel); 
//    Serial.print("\t X:"); Serial.print(curX); Serial.print("\t Y:"); Serial.print(curY); 
//    Serial.print("\t W:");  Serial.print(curW); Serial.print("\t H:"); Serial.print(curH); 
//    Serial.print("\t CT:"); Serial.print(curTile); Serial.print("\t NT:"); Serial.print(whichTile); 
//    Serial.print("\t NX:"); Serial.print(neighborX); Serial.print("\t NY:"); Serial.print(neighborY); 
//    Serial.print("\t OUT"); Serial.print(isOut);
//    Serial.print("\t xMin:"); Serial.print(isxMin); Serial.print("\t xMax:"); Serial.print(isxMax); 
//    Serial.print("\t yMin:"); Serial.print(isyMin); Serial.print("\t yMax:"); Serial.print(isyMax); 
//    Serial.print("\t ?"); Serial.print(canMove);
//    Serial.println();
}

return canMove;
}

// WAS USED FOR CERTAIN PLACES THAT DEAL DAMAGE
void mapDamage(int curLevel, int curX, int curY) {
int curTileX = curX / 20;
int curTileY = curY / 20;
int curTile = curTileX + (curTileY * tileW); 
    if(interaction[curLevel][curTile] == 0xFF){
      if (!isDamaged) {
          damageNum++;
        }
        isDamaged = true;
     } else {
        isDamaged = false;
      }
}

// CONTROLS PICKING UP THE COINS
void pickup(int curLevel, int curX, int curY){
int curTileX = curX / 20;
int curTileY = curY / 20;
int curTile = curTileX + (curTileY * tileW); 
    if(curLevel == 0){
     if(interaction[curLevel][curTile] == 0x02 && buttonBuffer[2] == 1){chest1 = true;}
        if(chest1){
            tft.setClipRect(140, 120, 20, 20);
            tft.drawRGBBitmap(140, 120, CoinsHUD_PIX[0x0D], 20, 20);
            tft.updateScreen();
        } else {
            tft.setClipRect(140, 120, 20, 20);
            tft.drawRGBBitmap(140, 120, CoinsHUD_PIX[0x0C], 20, 20);
            tft.updateScreen();
        }
    }

    if(curLevel == 1){
     if(interaction[curLevel][curTile] == 0x02 && buttonBuffer[2] == 1){chest2 = true;}
        if(chest2){
            tft.setClipRect(140, 140, 20, 20);
            tft.drawRGBBitmap(140, 140, CoinsHUD_PIX[0x0D], 20, 20);
            tft.updateScreen();
        } else {
            tft.setClipRect(140, 140, 20, 20);
            tft.drawRGBBitmap(140, 140, CoinsHUD_PIX[0x0C], 20, 20);
            tft.updateScreen();
        }
    }
    
    if(curLevel == 2){
     if(interaction[curLevel][curTile] == 0x02 && buttonBuffer[2] == 1){chest3 = true;}
        if(chest3){
            tft.setClipRect(20, 20, 20, 20);
            tft.drawRGBBitmap(20, 20, CoinsHUD_PIX[0x0B], 20, 20);
            tft.updateScreen();
        } else {
            tft.setClipRect(20, 20, 20, 20);
            tft.drawRGBBitmap(20, 20, CoinsHUD_PIX[0x0A], 20, 20);
            tft.updateScreen();
        }
    }

   if(curLevel == 3){
     if(interaction[curLevel][curTile] == 0x02 && buttonBuffer[2] == 1){chest4 = true;}
        if(chest4){
            tft.setClipRect(140, 120, 20, 20);
            tft.drawRGBBitmap(140, 120, CoinsHUD_PIX[0x0B], 20, 20);
            tft.updateScreen();
        } else {
            tft.setClipRect(140, 120, 20, 20);
            tft.drawRGBBitmap(140, 120, CoinsHUD_PIX[0x0A], 20, 20);
            tft.updateScreen();
        }
    }

    if(curLevel == 4){
     if(interaction[curLevel][curTile] == 0x02 && buttonBuffer[2] == 1){chest5 = true;}
        if(chest5){
            tft.setClipRect(80, 80, 20, 20);
            tft.drawRGBBitmap(80, 80, CoinsHUD_PIX[0x0B], 20, 20);
            tft.updateScreen();
        } else {
            tft.setClipRect(80, 80, 20, 20);
            tft.drawRGBBitmap(80, 80, CoinsHUD_PIX[0x0A], 20, 20);
            tft.updateScreen();
        }
    }
  }
