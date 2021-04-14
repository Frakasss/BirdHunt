void game_init(){
  game.gameStatus = GAMEMAKERS;
  game.globalTimer = 0;
  game.customizedRand=0;
  game.pause=0;
  game.menuOption=1;
  game.menuPauseOption=0;
}

void game_initPlayer(){
  player.difficulty=2;
  player.currentLevel=1;
  player.currentShot=0;
  player.usedBullet=0;
  player.tmpScore=0;
  player.score=0;
  game_initLevelResults();
  player.animTimer=0;
  game_initLevelCursor();
  player.cursorSlowSensi=1;
  player.cursorFastSensi=3;
}

void game_initLevelResults(){
  for(int i = 0; i<10; i++){player.results[i]=0;}
}
void game_initLevelCursor(){
  player.xCursor=40;
  player.yCursor=30;
}

void game_reset(){
  player.currentLevel=1;
  player.currentShot=0;
  player.usedBullet=0;
  if(player.difficulty==3){player.usedBullet=1;}
  if(player.difficulty==4){player.usedBullet=2;}
  player.tmpScore=0;
  player.score=0;
  game_initLevelResults();
  player.animTimer=0;
  game_initLevelCursor();  
}

void game_initAnims(){
  levelAnim[0].x=3;    levelAnim[0].y=39;  levelAnim[0].img=1;  levelAnim[0].timer=2;
  levelAnim[1].x=5;    levelAnim[1].y=39;  levelAnim[1].img=2;  levelAnim[1].timer=2;
  levelAnim[2].x=7;    levelAnim[2].y=39;  levelAnim[2].img=3;  levelAnim[2].timer=2;
  levelAnim[3].x=9;    levelAnim[3].y=39;  levelAnim[3].img=4;  levelAnim[3].timer=2;
  
  levelAnim[4].x=11;   levelAnim[4].y=39;  levelAnim[4].img=1;  levelAnim[4].timer=2;
  levelAnim[5].x=13;   levelAnim[5].y=39;  levelAnim[5].img=2;  levelAnim[5].timer=2;
  levelAnim[6].x=15;   levelAnim[6].y=39;  levelAnim[6].img=3;  levelAnim[6].timer=2;
  levelAnim[7].x=17;   levelAnim[7].y=39;  levelAnim[7].img=4;  levelAnim[7].timer=2;
  
  levelAnim[8].x=19;   levelAnim[8].y=39;  levelAnim[8].img=1;  levelAnim[8].timer=2;
  levelAnim[9].x=21;   levelAnim[9].y=39;  levelAnim[9].img=2;  levelAnim[9].timer=2;
  levelAnim[10].x=23;  levelAnim[10].y=39; levelAnim[10].img=3; levelAnim[10].timer=2;
  levelAnim[11].x=25;  levelAnim[11].y=39; levelAnim[11].img=4; levelAnim[11].timer=2;

  levelAnim[12].x=27;   levelAnim[12].y=39;  levelAnim[12].img=1;  levelAnim[12].timer=2;
  levelAnim[13].x=29;   levelAnim[13].y=39;  levelAnim[13].img=2;  levelAnim[13].timer=2;
  
  levelAnim[14].x=31; levelAnim[14].y=39; levelAnim[14].img=5; levelAnim[14].timer=12;
  
  levelAnim[15].x=34; levelAnim[15].y=37; levelAnim[15].img=6; levelAnim[15].timer=2;
  levelAnim[16].x=37; levelAnim[16].y=35; levelAnim[16].img=6; levelAnim[16].timer=2;
  levelAnim[17].x=40; levelAnim[17].y=33; levelAnim[17].img=6; levelAnim[17].timer=2;
  levelAnim[18].x=43; levelAnim[18].y=31; levelAnim[18].img=6; levelAnim[18].timer=2;
  levelAnim[19].x=46; levelAnim[19].y=34; levelAnim[19].img=6; levelAnim[19].timer=2;
  levelAnim[20].x=49; levelAnim[20].y=37; levelAnim[20].img=6; levelAnim[20].timer=2;
  levelAnim[21].x=52; levelAnim[21].y=40; levelAnim[21].img=6; levelAnim[21].timer=2;  


  successAnim[0].x=35;  successAnim[0].y=44; successAnim[0].img=1; successAnim[0].timer=2;
  successAnim[1].x=35;  successAnim[1].y=41; successAnim[1].img=1; successAnim[1].timer=2;
  successAnim[2].x=35;  successAnim[2].y=38; successAnim[2].img=1; successAnim[2].timer=2;
  successAnim[3].x=35;  successAnim[3].y=35; successAnim[3].img=1; successAnim[3].timer=2;
  successAnim[4].x=35;  successAnim[4].y=32; successAnim[4].img=1; successAnim[4].timer=10;
  successAnim[5].x=35;  successAnim[5].y=35; successAnim[5].img=1; successAnim[5].timer=2;
  successAnim[6].x=35;  successAnim[6].y=38; successAnim[6].img=1; successAnim[6].timer=2;
  successAnim[7].x=35;  successAnim[7].y=41; successAnim[7].img=1; successAnim[7].timer=2;
  successAnim[8].x=35;  successAnim[8].y=44; successAnim[8].img=1; successAnim[8].timer=2;


  failAnim[0].x=35;   failAnim[0].y=44;  failAnim[0].img=1;  failAnim[0].timer=2;
  failAnim[1].x=35;   failAnim[1].y=41;  failAnim[1].img=1;  failAnim[1].timer=2;
  failAnim[2].x=35;   failAnim[2].y=38;  failAnim[2].img=1;  failAnim[2].timer=2;
  failAnim[3].x=35;   failAnim[3].y=35;  failAnim[3].img=1;  failAnim[3].timer=2;
  failAnim[4].x=35;   failAnim[4].y=32;  failAnim[4].img=1;  failAnim[4].timer=2;
  failAnim[5].x=35;   failAnim[5].y=32;  failAnim[5].img=2;  failAnim[5].timer=2;/**/
  failAnim[6].x=35;   failAnim[6].y=32;  failAnim[6].img=1;  failAnim[6].timer=2;
  failAnim[7].x=35;   failAnim[7].y=32;  failAnim[7].img=2;  failAnim[7].timer=2;
  failAnim[8].x=35;   failAnim[8].y=32;  failAnim[8].img=1;  failAnim[8].timer=2;
  failAnim[9].x=35;   failAnim[9].y=32;  failAnim[9].img=2;  failAnim[9].timer=2;
  failAnim[10].x=35;  failAnim[10].y=32; failAnim[10].img=1; failAnim[10].timer=2;
  failAnim[11].x=35;  failAnim[11].y=32; failAnim[11].img=2; failAnim[11].timer=2;
  failAnim[12].x=35;  failAnim[12].y=32; failAnim[12].img=1; failAnim[12].timer=2;
  failAnim[13].x=35;  failAnim[13].y=32; failAnim[13].img=2; failAnim[13].timer=2;
  failAnim[14].x=35;  failAnim[14].y=32; failAnim[14].img=1; failAnim[14].timer=2;/**/
  failAnim[15].x=35;  failAnim[15].y=35; failAnim[15].img=1; failAnim[15].timer=2;
  failAnim[16].x=35;  failAnim[16].y=38; failAnim[16].img=1; failAnim[16].timer=2;
  failAnim[17].x=35;  failAnim[17].y=41; failAnim[17].img=1; failAnim[17].timer=2;
  failAnim[18].x=35;  failAnim[18].y=44; failAnim[18].img=1; failAnim[18].timer=2;
  failAnim[19].x=35;  failAnim[19].y=47; failAnim[19].img=1; failAnim[19].timer=2;
}

void game_resetTimer(){
  game.globalTimer = 0;
}

void game_manageGlobalCounter(){
  game.customizedRand = game.customizedRand + 1;
  if(game.customizedRand==983){game.customizedRand=0;}
  
  switch ( game.gameStatus ){
     //#################################### 
     case GAMEMAKERS:
        if(game.globalTimer<30){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = TITLESCREEN;
        }
        break;

     //####################################  
     case TITLESCREEN:
        if(game.globalTimer<30){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = MENU;
        }
        break;
        
     //####################################  
     case MENU:
        if(game.globalTimer<6){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
        }
        break;

     //####################################  
     case ANIM:
        player.animTimer=player.animTimer+1;
        if(player.animTimer>=levelAnim[game.globalTimer].timer){
          player.animTimer = 0;
          game.globalTimer = game.globalTimer + 1;
        }
        if(game.globalTimer>=22){
          game.gameStatus = GAME;
        }
        break;

     //####################################  
     case GAME:
        if(game.globalTimer<500){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
        }
        break;

     //####################################  
     case ANIMSHOOT:
        if(game.globalTimer<2){
          game.globalTimer = game.globalTimer +1;
        }
        break;

     //####################################  
     case ANIMSUCCESS:
        if(game.globalTimer<10){
          game.globalTimer = game.globalTimer +1;
          player.animTimer = 0;
        }
        if(game.globalTimer>=10 and game.globalTimer<=20){
          game.globalTimer = game.globalTimer +1;
          if(game.globalTimer==21){game.globalTimer=10;}
        } 
        if(game.globalTimer>20){
          player.animTimer=player.animTimer+1;
          if(player.animTimer>=successAnim[game.globalTimer-21].timer){
            player.animTimer = 0;
            game.globalTimer = game.globalTimer + 1;
          }
        }               
        break;

     //####################################  
     case ANIMFAIL:
        if(game.globalTimer<=10){
          game.globalTimer = game.globalTimer + 1;
          if(game.globalTimer==11){game.globalTimer=0;}
          player.animTimer = 0;
        }
        if(game.globalTimer>10){
          player.animTimer=player.animTimer+1;
          if(player.animTimer>=failAnim[game.globalTimer-11].timer){
            player.animTimer = 0;
            game.globalTimer = game.globalTimer + 1;
          }
        }           
        break;

      //####################################  
     case SETTINGS:
        break;

      //####################################  
     case PAUSE:
        break;
        
     //####################################  
     case CONTROLS:
        break;
        
     //####################################  
     case CREDITS:
        break;
        
     //####################################  
     case GAMEOVER:
        if(game.globalTimer<11){
          game.globalTimer = game.globalTimer + 1;
        }
        if(game.globalTimer>=11){
          player.animTimer=player.animTimer+1;
          if(player.animTimer>=failAnim[game.globalTimer-11].timer){
            player.animTimer = 0;
            game.globalTimer = game.globalTimer + 1;
            if(game.globalTimer>=25){game.globalTimer=15;}
          }
        } 
        break; 
        
     default:
        game.gameStatus = GAMEMAKERS;
        break;
  }
}


void game_checkShoot(){
  player.usedBullet = player.usedBullet + 1;
  if(gb.display.getPixelColor(player.xCursor,player.yCursor) == BLACK){
    game.gameStatus = ANIMSUCCESS;
    player.results[player.currentShot]=1;
    if(bird.birdType==0){player.score = player.score + 25; player.tmpScore=25;}
    if(bird.birdType==1){player.score = player.score + 50; player.tmpScore=50;}
    if(bird.birdType==2){player.score = player.score + 75; player.tmpScore=75;}
    if(bird.birdType==3){player.score = player.score + 225; player.tmpScore=225;}
    if(player.usedBullet==3){player.score = player.score + 25; player.tmpScore=player.tmpScore+25;}
    if(player.usedBullet==2){player.score = player.score + 50; player.tmpScore=player.tmpScore+50;}
    if(player.usedBullet==1){player.score = player.score + 75; player.tmpScore=player.tmpScore+75;}    
    
  }else{
    if(player.usedBullet==3){
      game.gameStatus = ANIMFAIL;
      player.results[player.currentShot]=2;
    }else{
      game.gameStatus = GAME;
    }
  }
}



void game_finalCheck(){
  player.currentShot = player.currentShot + 1;
  if(player.difficulty==1){player.usedBullet = 0;}
  if(player.difficulty==2){player.usedBullet = 0;}
  if(player.difficulty==3){player.usedBullet = 1;}
  if(player.difficulty==4){player.usedBullet = 2;}
  player.animTimer = 0;
  game_resetTimer();
  ennemy_initBird();
  game.gameStatus = GAME;

  if(player.currentShot==10){
    int countSuccess = 0;
    for(int i = 0; i<10; i++){
      if(player.results[i]==1){
        countSuccess = countSuccess + 1 ;
      }
    }

    if((player.difficulty==1 and countSuccess>=4)
    or (player.difficulty==2 and countSuccess>=6)
    or (player.difficulty==3 and countSuccess>=8)
    or (player.difficulty==4 and countSuccess>=10) ){
      player.currentShot = 0;
      player.usedBullet=0;
      if(player.difficulty==3){player.usedBullet=1;}
      if(player.difficulty==4){player.usedBullet=2;}
      player.currentLevel = player.currentLevel + 1;
      game_initLevelResults();
      game_initLevelCursor();
      game.gameStatus = ANIM;
    }else{
      game.gameStatus = GAMEOVER;
    }
  }
}
