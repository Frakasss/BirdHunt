void outputSound_init(){}

void outputSound_gunShot(){
  gb.sound.playTick();
}

void outputSound_kwak(){
  gb.sound.playCancel();
  
}

void outputSound_dog(){
  gb.sound.playOK();
}
