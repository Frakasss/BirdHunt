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
          break;

          case 3:
            game.gameStatus=CONTROLS;
          break;

          case 4:
            game.gameStatus=CREDITS;
          break;
        }
      }

      if(game.menuOption==2){
        if(gb.buttons.pressed(BUTTON_LEFT)){
          player.difficulty = player.difficulty - 1;
          if(player.difficulty<=0){player.difficulty=4;}
        }
        
        if(gb.buttons.pressed(BUTTON_RIGHT)){
          player.difficulty = player.difficulty + 1;
          if(player.difficulty>=5){player.difficulty=1;}
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
        if(gb.buttons.repeat(BUTTON_B,0)){player.yCursor = player.yCursor-3; }
        else{player.yCursor = player.yCursor-1;}
        if(player.yCursor<0){player.yCursor=0;}
      }else{
        if(gb.buttons.repeat(BUTTON_DOWN,0)){
          if(gb.buttons.repeat(BUTTON_B,0)){player.yCursor = player.yCursor+3; }
          else{player.yCursor = player.yCursor+1;}
          if(player.yCursor>50){player.yCursor=50;}
        }
      }
      
      if(gb.buttons.repeat(BUTTON_RIGHT,0)){
        if(gb.buttons.repeat(BUTTON_B,0)){player.xCursor = player.xCursor+3; }
        else{player.xCursor = player.xCursor+1;}
        if(player.xCursor>80){player.xCursor=80;}
      }else{
        if(gb.buttons.repeat(BUTTON_LEFT,0)){
          if(gb.buttons.repeat(BUTTON_B,0)){player.xCursor = player.xCursor-3; }
          else{player.xCursor = player.xCursor-1;}
          if(player.xCursor<0){player.xCursor=0;} 
        }
      }     

      if(gb.buttons.pressed(BUTTON_A)){
        game_resetTimer();
        game.gameStatus=ANIMSHOOT;
        outputSound_gunShot();
      }
     break; 
  }
}
