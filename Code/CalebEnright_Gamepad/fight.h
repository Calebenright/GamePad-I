
boolean canFight;

// Check to See if Hero & Enemies Collide
  boolean checkCollide(int hX, int hY, int hW, int hH, int eX, int eY, int eW, int eH){
  boolean canMove = false;           // Assume a move can be made
  boolean xMin = false; if(hX < eX + eW){xMin = true;}               // Does the xMin collide?
  boolean xMax = false; if(hX + hW > eX){xMax = true;}               // Does the xMax collide?
  boolean yMin = false; if(hY < eY + eH){yMin = true;}               // Does the yMin collide?
  boolean yMax = false; if(hY + hH > eY){yMax = true;}               // Does the yMin collide?
  if (xMin && xMax && yMin && yMax) {canMove = true;}
  return canMove;
}

void fight(){
  canFight = checkCollide(heroX, heroY, mainChar_W, mainChar_H, enemyX, enemyY, enemyW, enemyH);
  if(canFight == true){
    if(random(10) ==  0) {
      if (!isDamaged) {
        damageNum++;
        isDamaged = true;
        }
      }
      canFight = false;
    } else {
      isDamaged = false;
      canFight = true;
    }
//  mapDamage(curMode, heroX, heroY);
}
