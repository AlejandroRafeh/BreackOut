#include <cmath>
#include <sstream>
#include <iostream>
#include <iomanip>

#include <esat/window.h>
#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/input.h>
#include <esat/time.h>
#include <esat_extra/sqlite3.h>
#include "esat_extra/imgui.h"

#include "include/lib-math.cc"
#include "Structs.cc"
#include "Tlist.h"
#include "Player.cc"
#include "Ball.cc"
#include "Bricks.cc"
#include "imgui.cc"
#include "sqlite.cc"





void RestartGame(Ball *ball,Bricks *brick,int total_balls){
    Ball *p;
    Bricks *q;

    for(p=ball;p!=nullptr;p=p->Sig){
        p->destroyed = true;
    }

    for(q=brick;q!=nullptr;q=q->Sig){
        q->destroyed = true;
    }

    for(int i=0;i<total_balls;i++){
    FreeBall(&g_ball);
    }
    FreeNode(&g_brick);
    

    for(int i = 0; i < 12;i++){
        for(int j = 0;j < 12;j++){
            InsertBricks(&g_brick,i,j);
        }
    }

    InsertBall(&g_ball,{0,0},{ReturnDireccion()},true,10);
    g_player.lives = 3;

}


void EndGame(Ball *ball,Bricks *brick){
    Ball *p;
    Bricks *q;
    int ball_counter = 0;
    int brick_counter = 0;
    for(p=ball;p!=nullptr;p=p->Sig){
        ball_counter++;
    }

    for(q=brick;q!=nullptr;q=q->Sig){
        brick_counter++;
    }


    if(ball_counter <= 0){
        g_player.lives--;
        InsertBall(&g_ball,{0,0},{ReturnDireccion()},true,10);

    }

    if(g_player.lives < 1){
        g_state = kGameControlGameOver;
        RestartGame(g_ball,g_brick,ball_counter);
        g_player.score = 0;
    }

    if(brick_counter <= 0){
        RestartGame(g_ball,g_brick,ball_counter);
    }
}

void DrawCube(float min_x,float min_y,int space_x,int space_y){
    MATH::Vec2 *cube_points = (MATH::Vec2*) malloc(4 * sizeof(MATH::Vec2));

    *(cube_points + 0) = {min_x,min_y};
    *(cube_points + 1) = {min_x+space_x,min_y};
    *(cube_points + 2) = {min_x+space_x,min_y+space_y};
    *(cube_points + 3) = {min_x,min_y+space_y};

    esat::DrawSetStrokeColor(255,255,255);  
    esat::DrawSetFillColor(0,0,0,0);  
    esat::DrawSolidPath(&(cube_points)->x,4);
}

void DrawText(const char *text,MATH::Vec2 pos,int size,int caja = 0){
    int longitude = sizeof(text);
    longitude /= 2;
    esat::DrawSetFillColor(255, 255, 255, 255);
    esat::DrawSetTextSize(size);
    esat::DrawText(pos.x-(longitude*size),pos.y+caja,text);

}

bool IsMouseInside(float min_x,float min_y,int space_x,int space_y){
float pos_mouse_x = (float) esat::MousePositionX();
float pos_mouse_y = (float) esat::MousePositionY();
    if(pos_mouse_x > min_x && pos_mouse_x < min_x+space_x
      && pos_mouse_y > min_y && pos_mouse_y < min_y+space_y && esat::MouseButtonDown(0)){
        return true;
    }

    return false;
}

void DrawMenu(){
    DrawText("BREAKOUT",{(kIWidth/2.2),200},70);
    DrawCube((kIWidth/2)-125,(kIHeight/2)-70,250,50);
    DrawText("PLAY",{(kIWidth/2)+30,(kIHeight/2)-70},40,50);
    if(IsMouseInside((kIWidth/2)-125,(kIHeight/2)-70,250,50)){
        g_state = kGameControlGame;
    }
}


void UpdateFunctions(){
  
  DrawBricks(g_brick);
  DrawPlayerShip(&g_player);
  DrawBall(g_ball);
  Punctuation();
  WallColisions(g_ball);
  CollisionBallWhithBricks(g_brick,g_ball);
  CollisionBallWithShip(g_ball);
  MovePlayerShip(&g_player,15);
  UpdateBall(g_ball);
  LaunchBall(g_ball);
  FreeNode(&g_brick);
  FreeBall(&g_ball);
  EndGame(g_ball,g_brick);

}


void GameOver(){
    
    DrawText("GAMEOVER",{(kIWidth/2.2),200},70);
    DrawCube((kIWidth/2)-175,(kIHeight/2)-70,350,50);
    DrawText("BACK TO MENU",{(kIWidth/2)-70,(kIHeight/2)-70},40,50);
    if(IsMouseInside((kIWidth/2)-125,(kIHeight/2)-70,250,50)){
        g_state = kGameControlMenu;
    }

}

void ControlGameState(){
    switch (g_state){
       
        case 0:
            DrawMenu();
        break;

        case 1:
            UpdateFunctions();
        break;

        case 2:
            GameOver();
        break;
    }
}








int esat::main(int argc, char **argv) {
  esat::WindowInit(kIWidth,kIHeight);
  esat::DrawSetTextFont("test.ttf");
  esat::WindowSetMouseVisibility(true);
  srand(time(NULL));
    
  HandleSqlite();


    for(int i = 0; i < 12;i++){
        for(int j = 0;j < 12;j++){
            InsertBricks(&g_brick,i,j);
        }
    }

    InsertBall(&g_ball,{0,0},{ReturnDireccion()},true,10);

   g_player.points_player = (MATH::Vec2*) malloc(4 * sizeof(MATH::Vec2));
   g_player.text_score = (char*) malloc(30 * sizeof(char));

   g_delta_time = 1.0f/fps;
   
  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
  last_time = esat::Time();
  esat::DrawBegin();
  esat::DrawClear(0,0,0);

  ControlGameState();
  HandelImgui(g_ball);


  esat::DrawEnd();

  do{
            current_time = esat::Time();
        }while((current_time-last_time)<=1000.0/fps);
   esat::WindowFrame();
  }
 

  esat::WindowDestroy();
 
  return 0;
}
