#include <Gamebuino-Meta.h>
#define GAMEMAKERS 0
#define TITLESCREEN 1
#define MENU 2
#define ANIM 3
#define GAME 4
#define ANIMSHOOT 5
#define ANIMSUCCESS 6
#define ANIMFAIL 7
#define GAMEOVER 8

#define CONTROLS 20
#define CREDITS 21

#define SCREENHEIGHT 64
#define SCREENWIDTH 80



//###########################
//##### INFO Global #########
//###########################
typedef struct{
  int gameStatus; 
  int globalTimer;
  int customizedRand;
  int pause;
  int menuOption;
  int menuPauseOption;
}GameInfo;
GameInfo game;

typedef struct{
  int difficulty;
  int currentLevel;
  int currentShot;
  int usedBullet;
  int tmpScore;
  int score;
  int results[10]; /*0:not played - 1:success - 2:fail*/
  int animTimer;
  int xCursor;
  int yCursor;
}PlayerParam;
PlayerParam player;

typedef struct{
  int x;
  int y;
}Coord;

typedef struct{
  int x;
  int y;
  int birdType;
  int timer;
  int flyDirection;
}BirdParam;
BirdParam bird;

typedef struct{
  int x;
  int y;
  int img;
  int timer;
}Anim;

Anim levelAnim[22];
int levelAnimLength = 22;

Anim successAnim[20];
int successAnimLength = 20;

Anim failAnim[20];
int failAnimLength = 20;


typedef struct {
  int8_t weapon;
  int8_t bonus;
  int8_t playerDamage;
  int8_t music;
}SoundInfo;
SoundInfo sounds;


/*
int strategies[5][10];
*/


//###########################
//##### Game Setup ##########
//###########################
void setup(){
  gb.begin();
  game_init();
  game_initAnims();
  game_initPlayer();
  ennemy_initBird();
  gb.pickRandomSeed();
  loop();
}


//###########################
//##### Game Loop ###########
//###########################
void loop(){
  while(1){
    if(gb.update()){
      game_manageGlobalCounter();
      
      switch ( game.gameStatus )
      {
         //####################################
         case GAMEMAKERS:
            outputScreen_gamemakers();
            button_check(GAMEMAKERS);
            break;

         //#################################### 
         case TITLESCREEN:
            outputScreen_clear();
            outputScreen_title();
            button_check(TITLESCREEN);
            break;
            
         //####################################  
         case MENU:
            outputScreen_clear();
            outputScreen_menu();
            button_check(MENU);
            break;

         //####################################  
         case ANIM:
            outputScreen_clear();
            outputScreen_anim();
            break;

         //####################################  
         case GAME:
            outputScreen_clear();
            ennemy_moveBird();
            outputScreen_background();
            outputScreen_bird();
            outputScreen_landscape();
            outputScreen_hub();
            outputScreen_cursor();
            button_check(GAME); 
            break;

         //####################################  
         case ANIMSHOOT:
            outputScreen_shoot();
            outputLights_shoot();
            if(game.globalTimer==2){
              game_checkShoot(); /*Si timer fly away, le check doit aussi être fait au timeout*/
            }
            break;
            
         //####################################  
         case ANIMSUCCESS:
            outputScreen_clear();
            outputScreen_background();
            outputScreen_animDeadBird();
            outputScreen_animFallingBird();
            outputScreen_animSuccessDog();
            outputScreen_landscape();
            outputScreen_hub();
            ennemy_moveDeadBird();
            if(game.globalTimer>=30){game_finalCheck();}
            break;

         //####################################  
         case ANIMFAIL:
            outputScreen_clear();
            outputScreen_background();
            outputScreen_animFlyAwayBird();
            outputScreen_animFailDog();
            outputScreen_Panel();
            outputScreen_FlyAway();
            outputScreen_landscape();
            outputScreen_hub();
            ennemy_moveFlyAwayBird();
            if(game.globalTimer>=30){game_finalCheck();}
            break;

         //#################################### 
         case CONTROLS:
            outputScreen_clear();
            outputScreen_controls();
            button_check(CONTROLS);
            break;

         //#################################### 
         case CREDITS:
            outputScreen_clear();
            outputScreen_credits();
            button_check(CREDITS);
            break;
            
         //####################################  
         case GAMEOVER:
            outputScreen_clear();
            outputScreen_background();
            outputScreen_animFailDog();
            outputScreen_Panel();
            outputScreen_GameOver();
            outputScreen_landscape();
            outputScreen_hub();
            break;


         //####################################                     
         default:
            game.gameStatus = GAMEMAKERS;
            break;
      }      
    }  
  }
}
