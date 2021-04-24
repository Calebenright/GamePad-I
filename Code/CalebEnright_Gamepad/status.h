

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

// Moves arrow to select coin
void selectCoin(){
  if (coinNum == 0 && chest1 == true){
  tft.setClipRect(280, 140, 20, 100);
  tft.drawRGBBitmap(280, 220, HUD_PIX[0x26], 20, 20);
  tft.drawRGBBitmap(280, 200, HUD_PIX[0x25], 20, 20);
  tft.drawRGBBitmap(280, 180, HUD_PIX[0x25], 20, 20);
  tft.drawRGBBitmap(280, 160, HUD_PIX[0x25], 20, 20);
  tft.drawRGBBitmap(280, 140, HUD_PIX[0x25], 20, 20);
  tft.updateScreen();
  } else if (coinNum == 1 && chest2 == true){
  tft.setClipRect(280, 140, 20, 100);
  tft.drawRGBBitmap(280, 220, HUD_PIX[0x25], 20, 20);
  tft.drawRGBBitmap(280, 200, HUD_PIX[0x26], 20, 20);
  tft.drawRGBBitmap(280, 180, HUD_PIX[0x25], 20, 20);
  tft.drawRGBBitmap(280, 160, HUD_PIX[0x25], 20, 20);
  tft.drawRGBBitmap(280, 140, HUD_PIX[0x25], 20, 20);
  tft.updateScreen();
  } else if (coinNum == 2 && chest3 == true){
  tft.setClipRect(280, 140, 20, 100);
  tft.drawRGBBitmap(280, 220, HUD_PIX[0x25], 20, 20);
  tft.drawRGBBitmap(280, 200, HUD_PIX[0x25], 20, 20);
  tft.drawRGBBitmap(280, 180, HUD_PIX[0x26], 20, 20);
  tft.drawRGBBitmap(280, 160, HUD_PIX[0x25], 20, 20);
  tft.drawRGBBitmap(280, 140, HUD_PIX[0x25], 20, 20);
  tft.updateScreen();
  } else if (coinNum == 3 && chest4 == true){
  tft.setClipRect(280, 140, 20, 100);
  tft.drawRGBBitmap(280, 220, HUD_PIX[0x25], 20, 20);
  tft.drawRGBBitmap(280, 200, HUD_PIX[0x25], 20, 20);
  tft.drawRGBBitmap(280, 180, HUD_PIX[0x25], 20, 20);
  tft.drawRGBBitmap(280, 160, HUD_PIX[0x26], 20, 20);
  tft.drawRGBBitmap(280, 140, HUD_PIX[0x25], 20, 20);
  tft.updateScreen();
  } else if (coinNum == 4 && chest5 == true){
  tft.setClipRect(280, 140, 20, 100);
  tft.drawRGBBitmap(280, 220, HUD_PIX[0x25], 20, 20);
  tft.drawRGBBitmap(280, 200, HUD_PIX[0x25], 20, 20);
  tft.drawRGBBitmap(280, 180, HUD_PIX[0x25], 20, 20);
  tft.drawRGBBitmap(280, 160, HUD_PIX[0x25], 20, 20);
  tft.drawRGBBitmap(280, 140, HUD_PIX[0x26], 20, 20);
  tft.updateScreen();
  }
  if (buttons[0].fell() == 1){
    coinNum = (coinNum + 1) % 5;
  }

  if (chest1){
  tft.setClipRect(300, 220, 20, 20);
  tft.drawRGBBitmap(300, 220, CoinsHUD_PIX[0x00], 20, 20);
  tft.updateScreen();
  }
  if (chest2){
  tft.setClipRect(300, 200, 20, 20);
  tft.drawRGBBitmap(300, 200, CoinsHUD_PIX[0x04], 20, 20);
  tft.updateScreen();
  }
  if (chest3){
  tft.setClipRect(300, 180, 20, 20);
  tft.drawRGBBitmap(300, 180, CoinsHUD_PIX[0x03], 20, 20);
  tft.updateScreen();
  }
  if (chest4){
  tft.setClipRect(300, 160, 20, 20);
  tft.drawRGBBitmap(300, 160, CoinsHUD_PIX[0x02], 20, 20);
  tft.updateScreen();
  }
  if (chest5){
  tft.setClipRect(300, 140, 20, 20);
  tft.drawRGBBitmap(300, 140, CoinsHUD_PIX[0x01], 20, 20);
  tft.updateScreen();
  }
}
