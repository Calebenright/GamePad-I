

// Show different Heads up Display
void updateHealth(int healthNum){
  if (healthNum == 1){
  tft.setClipRect(300, 20, 20, 20);
  tft.drawRGBBitmap(300, 20, HUD_PIX[0x2B], 20, 20);
  tft.updateScreen();
  } else if (healthNum == 2){
  tft.setClipRect(300, 20, 20, 40);
  tft.drawRGBBitmap(300, 40, HUD_PIX[0x2C], 20, 20);
  tft.drawRGBBitmap(300, 20, HUD_PIX[0x2B], 20, 20);
  tft.updateScreen();
  } else if (healthNum == 3){
  tft.setClipRect(300, 20, 20, 60);
  tft.drawRGBBitmap(300, 60, HUD_PIX[0x2D], 20, 20);
  tft.drawRGBBitmap(300, 40, HUD_PIX[0x2C], 20, 20);
  tft.drawRGBBitmap(300, 20, HUD_PIX[0x2B], 20, 20);
  tft.updateScreen();
  } else if (healthNum == 4){
  curMode = -3;
  }
}

// Show collected pickup items (Coins)
void pickups(int pickupNum){
  if (pickupNum == 1){
  tft.setClipRect(300, 220, 20, 20);
  tft.drawRGBBitmap(300, 220, HUD_PIX[0x2B], 20, 20);
  } else if (pickupNum == 2){
  tft.setClipRect(300, 200, 20, 20);
  tft.drawRGBBitmap(300, 200, HUD_PIX[0x2C], 20, 20);
  } else if (pickupNum == 3){
  tft.setClipRect(300, 180, 20, 20);
  tft.drawRGBBitmap(300, 180, HUD_PIX[0x2D], 20, 20);
  } else if (pickupNum == 4){
  tft.setClipRect(300, 160, 20, 20);
  tft.drawRGBBitmap(300, 160, HUD_PIX[0x2D], 20, 20);
  } else if (pickupNum == 5){
  tft.setClipRect(300, 140, 20, 20);
  tft.drawRGBBitmap(300, 140, HUD_PIX[0x2D], 20, 20);
  }
  tft.updateScreen();
}

// Moves arrow to select coin
void selectCoin(int coinNum){
  if (coinNum == 1){
  tft.setClipRect(280, 220, 20, 20);
  tft.drawRGBBitmap(280, 220, HUD_PIX[0x2B], 20, 20);
  } else if (coinNum == 2){
  tft.setClipRect(280, 200, 200, 20);
  tft.drawRGBBitmap(280, 200, HUD_PIX[0x2C], 20, 20);
  } else if (coinNum == 3){
  tft.setClipRect(280, 180, 180, 20);
  tft.drawRGBBitmap(280, 180, HUD_PIX[0x2D], 20, 20);
  } else if (coinNum == 4){
  tft.setClipRect(280, 160, 160, 20);
  tft.drawRGBBitmap(280, 160, HUD_PIX[0x2D], 20, 20);
  } else if (coinNum == 5){
  tft.setClipRect(280, 140, 140, 20);
  tft.drawRGBBitmap(280, 140, HUD_PIX[0x2D], 20, 20);
  }
  tft.updateScreen();
}
