void ennemy_initBird(){
  bird.x=(game.customizedRand%55)+10;
  bird.y=32;
  bird.birdType=(game.customizedRand%3);/*0 / 1 / 2*/
  if(bird.birdType==2 and game.customizedRand<100){bird.birdType=3;}
  bird.timer=2;
  bird.flyDirection=game.customizedRand%8; /* 0-1-2-3-4-5-6-7*/
}

void ennemy_moveDeadBird(){
  if(game.globalTimer>=10 and game.globalTimer<=20){
    bird.y=bird.y+1;
    if(bird.y>=54){game.globalTimer=21;}
  }
}

void ennemy_moveFlyAwayBird(){
  if(game.globalTimer<=10){
    bird.y=bird.y-1;
    if(bird.y<-10){game.globalTimer=11;}
  }  
}

void ennemy_moveBird(){
  Coord currentCoord;
  currentCoord.x = bird.x;
  currentCoord.y = bird.y;
  Coord newCoord = ennemy_nextMove(currentCoord,bird.birdType,bird.flyDirection);
  bird.x = newCoord.x;
  bird.y = newCoord.y;
  if(ennemy_checkFlyDirection()==false){
    ennemy_changeFlyDirection();
  }
}

Coord ennemy_nextMove(Coord tmp,int type, int dir){
  if(type==0){
    switch ( dir ){
      case 0:
      tmp.x = tmp.x+1;
      tmp.y = tmp.y+2;
      break;
  
      case 1:
      tmp.x = tmp.x+2;
      tmp.y = tmp.y+1;
      break;
  
      case 2:
      tmp.x = tmp.x+2;
      tmp.y = tmp.y-1;
      break;
  
      case 3:
      tmp.x = tmp.x+1;
      tmp.y = tmp.y-2;
      break;
  
      case 4:
      tmp.x = tmp.x-1;
      tmp.y = tmp.y-2;
      break;
  
      case 5:
      tmp.x = tmp.x-2;
      tmp.y = tmp.y-1;
      break;
  
      case 6:
      tmp.x = tmp.x-2;
      tmp.y = tmp.y+1;
      break;
  
      case 7:
      tmp.x = tmp.x-1;
      tmp.y = tmp.y+2;
      break;
    } 
  }
  
  if(type==1){
    switch ( dir ){
      case 0:
      tmp.x = tmp.x+1;
      tmp.y = tmp.y+2;
      break;
  
      case 1:
      tmp.x = tmp.x+2;
      tmp.y = tmp.y+1;
      break;
  
      case 2:
      tmp.x = tmp.x+2;
      tmp.y = tmp.y-1;
      break;
  
      case 3:
      tmp.x = tmp.x+1;
      tmp.y = tmp.y-2;
      break;
  
      case 4:
      tmp.x = tmp.x-1;
      tmp.y = tmp.y-2;
      break;
  
      case 5:
      tmp.x = tmp.x-2;
      tmp.y = tmp.y-1;
      break;
  
      case 6:
      tmp.x = tmp.x-2;
      tmp.y = tmp.y+1;
      break;
  
      case 7:
      tmp.x = tmp.x-1;
      tmp.y = tmp.y+2;
      break;
    } 
  }
  
  if(type==2){
    switch ( dir ){
      case 0:
      tmp.x = tmp.x+1;
      tmp.y = tmp.y+3;
      break;
  
      case 1:
      tmp.x = tmp.x+3;
      tmp.y = tmp.y+1;
      break;
  
      case 2:
      tmp.x = tmp.x+3;
      tmp.y = tmp.y-1;
      break;
  
      case 3:
      tmp.x = tmp.x+1;
      tmp.y = tmp.y-3;
      break;
  
      case 4:
      tmp.x = tmp.x-1;
      tmp.y = tmp.y-3;
      break;
  
      case 5:
      tmp.x = tmp.x-3;
      tmp.y = tmp.y-1;
      break;
  
      case 6:
      tmp.x = tmp.x-3;
      tmp.y = tmp.y+1;
      break;
  
      case 7:
      tmp.x = tmp.x-1;
      tmp.y = tmp.y+3;
      break;
    }
  }

  if(type==3){
    switch ( dir ){
      case 0:
      tmp.x = tmp.x+1;
      tmp.y = tmp.y+3;
      break;
  
      case 1:
      tmp.x = tmp.x+3;
      tmp.y = tmp.y+1;
      break;
  
      case 2:
      tmp.x = tmp.x+3;
      tmp.y = tmp.y-1;
      break;
  
      case 3:
      tmp.x = tmp.x+1;
      tmp.y = tmp.y-3;
      break;
  
      case 4:
      tmp.x = tmp.x-1;
      tmp.y = tmp.y-3;
      break;
  
      case 5:
      tmp.x = tmp.x-3;
      tmp.y = tmp.y-1;
      break;
  
      case 6:
      tmp.x = tmp.x-3;
      tmp.y = tmp.y+1;
      break;
  
      case 7:
      tmp.x = tmp.x-1;
      tmp.y = tmp.y+3;
      break;
    } 
  }
  return tmp;
}

void ennemy_changeFlyDirection(){
  int tmpDir = 1;
  if(game.customizedRand%3==0){tmpDir = -1;}
  while(ennemy_checkFlyDirection()==false){
    if(bird.birdType==0){
      bird.flyDirection = bird.flyDirection + 1;
      if(bird.flyDirection==8){bird.flyDirection=0;}
    }
    if(bird.birdType==1){
      bird.flyDirection = bird.flyDirection + (1*tmpDir);
      if(bird.flyDirection>7){bird.flyDirection=0;}
      if(bird.flyDirection<0){bird.flyDirection=7;}
    }
    if(bird.birdType==2){
      bird.flyDirection = bird.flyDirection - 1;
      if(bird.flyDirection<0){bird.flyDirection=7;}
    }
    if(bird.birdType==3){
      bird.flyDirection = bird.flyDirection + (1*tmpDir);
      if(bird.flyDirection>7){bird.flyDirection=0;}
      if(bird.flyDirection<0){bird.flyDirection=7;}
    } 
  }
  outputSound_kwak();
}

bool ennemy_checkFlyDirection(){
  //bird.x+5, bird.y+1, 8, 8
  bool check = true;
  Coord currentCoord;
  currentCoord.x = bird.x;
  currentCoord.y = bird.y;
  Coord nextCoord = ennemy_nextMove(currentCoord,bird.birdType,bird.flyDirection);
  
  if(nextCoord.x+5<0){check = false;}
  if(nextCoord.x+13>80){check = false;}
  if(nextCoord.y<0){check = false;}
  if(nextCoord.y+9>55){check = false;}
  
  return check;
}
