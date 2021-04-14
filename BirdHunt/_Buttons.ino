void button_check(int typeCheck){
  switch(typeCheck){
     //####################################
     //########### Skip Logo ##############
     //####################################
     case GAMEMAKERS:
      if(gb.buttons.pressed(BUTTON_A)){
        game.globalTimer = 0;
        game.gameStatus=TITLESCREEN;
      }
     break;    
    
     //####################################
     //########### Skip title #############
     //####################################
     case TITLESCREEN:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.globalTimer = 0;
        game.gameStatus=MENU;
      }
     break; 
     
     //#######################################
     //############# Menu ####################
     //#######################################
     case MENU:      
      if(gb.buttons.pressed(BUTTON_A)){
        switch(game.menuOption){
          case 0:
          break;

          case 1:
            game_resetTimer();
            game.gameStatus=ANIM;
          break;

          case 2:
            game.menuOption=1;
            game.gameStatus=SETTINGS;
          break;

          case 3:
            game.gameStatus=CONTROLS;
          break;

          case 4:
            game.gameStatus=CREDITS;
          break;
        }
      }

      if(gb.buttons.pressed(BUTTON_UP)){    
        game.menuOption = game.menuOption - 1;
        if(game.menuOption<=0){game.menuOption=4;}
      }

      if(gb.buttons.pressed(BUTTON_DOWN)){    
        game.menuOption = game.menuOption + 1;
        if(game.menuOption>=5){game.menuOption=1;}
      }
      break;

     //#######################################
     //############# Settings ################
     //#######################################
     case SETTINGS: 
     //difficulty
      if(game.menuOption==1){
        if(gb.buttons.pressed(BUTTON_LEFT)){
          player.difficulty = player.difficulty - 1;
          if(player.difficulty<=0){player.difficulty=1;}
          if(player.difficulty==1){player.usedBullet=0;}
          if(player.difficulty==2){player.usedBullet=0;}
          if(player.difficulty==3){player.usedBullet=1;}
          if(player.difficulty==4){player.usedBullet=2;}
        }
        
        if(gb.buttons.pressed(BUTTON_RIGHT)){
          player.difficulty = player.difficulty + 1;
          if(player.difficulty>=5){player.difficulty=4;}
          if(player.difficulty==1){player.usedBullet=0;}
          if(player.difficulty==2){player.usedBullet=0;}
          if(player.difficulty==3){player.usedBullet=1;}
          if(player.difficulty==4){player.usedBullet=2;}
        }
      }
      //sensitivity
      if(game.menuOption==2){
        if(gb.buttons.pressed(BUTTON_LEFT)){
          player.cursorSlowSensi=player.cursorSlowSensi-1;
          if(player.cursorSlowSensi<1){player.cursorSlowSensi=1;}
        }
        
        if(gb.buttons.pressed(BUTTON_RIGHT)){
          player.cursorSlowSensi=player.cursorSlowSensi+1;
          if(player.cursorSlowSensi>3){player.cursorSlowSensi=3;}
        }
        if(player.cursorSlowSensi==1){player.cursorFastSensi=3;}
        if(player.cursorSlowSensi==2){player.cursorFastSensi=4;}
        if(player.cursorSlowSensi==3){player.cursorFastSensi=5;}
      }
      //back
      if(game.menuOption==3){
        if(gb.buttons.pressed(BUTTON_A)){
          game.menuOption=2;
          game.gameStatus=MENU;
        }
      }

      if(gb.buttons.pressed(BUTTON_UP)){    
        game.menuOption = game.menuOption - 1;
        if(game.menuOption<=0){game.menuOption=3;}
      }
      if(gb.buttons.pressed(BUTTON_DOWN)){    
        game.menuOption = game.menuOption + 1;
        if(game.menuOption>=4){game.menuOption=1;}
      }  
      if(gb.buttons.pressed(BUTTON_B)){
        game.menuOption=2;
        game.gameStatus=MENU;
      }      
     break; 

     //#######################################
     //############# Pause ###################
     //#######################################
     case PAUSE: 
      //Continue
      if(game.menuOption==1){
        if(gb.buttons.pressed(BUTTON_A)){
          game.menuOption=1;
          game.gameStatus=previousStatus;      
        }
      }
      //Give Up
      if(game.menuOption==2){
        if(gb.buttons.pressed(BUTTON_A)){
          game.menuOption=1;
          game_reset();
          game.gameStatus=MENU;
        }
      }

      if(gb.buttons.pressed(BUTTON_UP)){    
        game.menuOption = game.menuOption - 1;
        if(game.menuOption<=0){game.menuOption=2;}
      }
      if(gb.buttons.pressed(BUTTON_DOWN)){    
        game.menuOption = game.menuOption + 1;
        if(game.menuOption>=3){game.menuOption=1;}
      }  
      if(gb.buttons.pressed(BUTTON_MENU) or gb.buttons.pressed(BUTTON_B)){
        game.menuOption=1;
        game.gameStatus=previousStatus;
      }      
     break; 

     //####################################
     //########### Controls P1 ############
     //####################################
     case CONTROLS:      
      if(gb.buttons.pressed(BUTTON_B)){
        game.gameStatus=MENU;
      }
     break; 

     //####################################
     //########### Credits ################
     //####################################
     case CREDITS:      
      if(gb.buttons.pressed(BUTTON_B)){
        game.gameStatus=MENU;
      }
     break;
     
     //####################################
     //########### Game Over ##############
     //####################################
     case GAMEOVER: 
      if(game.globalTimer>=10){
        if(gb.buttons.pressed(BUTTON_A) or gb.buttons.pressed(BUTTON_B)){
          game.gameStatus=MENU;
        }
      }
     break;


     //####################################
     //########### GAME ############
     //####################################
     case GAME:
      if(gb.buttons.repeat(BUTTON_UP,0)){
        if(gb.buttons.repeat(BUTTON_B,0)){player.yCursor = player.yCursor-player.cursorFastSensi; }
        else{player.yCursor = player.yCursor-player.cursorSlowSensi;}
        if(player.yCursor<0){player.yCursor=0;}
      }else{
        if(gb.buttons.repeat(BUTTON_DOWN,0)){
          if(gb.buttons.repeat(BUTTON_B,0)){player.yCursor = player.yCursor+player.cursorFastSensi; }
          else{player.yCursor = player.yCursor+player.cursorSlowSensi;}
          if(player.yCursor>50){player.yCursor=50;}
        }
      }
      
      if(gb.buttons.repeat(BUTTON_RIGHT,0)){
        if(gb.buttons.repeat(BUTTON_B,0)){player.xCursor = player.xCursor+player.cursorFastSensi; }
        else{player.xCursor = player.xCursor+player.cursorSlowSensi;}
        if(player.xCursor>80){player.xCursor=80;}
      }else{
        if(gb.buttons.repeat(BUTTON_LEFT,0)){
          if(gb.buttons.repeat(BUTTON_B,0)){player.xCursor = player.xCursor-player.cursorFastSensi; }
          else{player.xCursor = player.xCursor-player.cursorSlowSensi;}
          if(player.xCursor<0){player.xCursor=0;} 
        }
      }     

      if(gb.buttons.pressed(BUTTON_A)){
        game_resetTimer();
        game.gameStatus=ANIMSHOOT;
        outputSound_gunShot();
      }
      
      if(gb.buttons.pressed(BUTTON_MENU)){    
        game.menuOption=1;
        previousStatus = GAME;
        game.gameStatus=PAUSE;
      }
     break; 

     //####################################  
     case ANIMFAIL:
      if(gb.buttons.pressed(BUTTON_MENU)){    
        game.menuOption=1;
        previousStatus = ANIMFAIL;
        game.gameStatus=PAUSE;
      }
     break;
     
     //####################################  
     case ANIMSUCCESS:
      if(gb.buttons.pressed(BUTTON_MENU)){    
        game.menuOption=1;
        previousStatus = ANIMSUCCESS;
        game.gameStatus=PAUSE;
      }
     break;
     
     //####################################  
     case ANIM:
      if(gb.buttons.pressed(BUTTON_MENU)){    
        game.menuOption=1;
        previousStatus = ANIM;
        game.gameStatus=PAUSE;
      }
     break;
     

  }
}
