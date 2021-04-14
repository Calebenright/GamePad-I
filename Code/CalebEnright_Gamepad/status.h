

// Show different Heads up Display
void updateHealth(int healthStatus){
  tft.setClipRect(300, 20, 20, 20);
  tft.drawRGBBitmap(300, 20, HUD_PIX[healthStatus], 20, 20);
  tft.updateScreen();
}
