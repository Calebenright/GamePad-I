#include <Metro.h>
Metro frameT = Metro(500);
int frames = 0;
void checkFrame(){
  if (frameT.check()) {
    frames=0;
  }
  frames++;
}
