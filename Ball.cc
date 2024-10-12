
MATH::Vec2 ReturnDireccion(){
    return {cosf(3+rand() % 7)*350+rand()%200,sinf(3+rand() % 7)*350+rand()%200};
}


void DrawBall(Ball *ball){
    Ball *p;
    float angle = 6.28 / 30;
    
 for(p=ball;p!=nullptr;p=p->Sig) {  
    for(int i = 0; i < 30;i++){
        *(p->points_ball + i) = {cosf(angle * i) * p->radius_ball + p->position_ball.x,sinf(angle * i) * p->radius_ball + p->position_ball.y};
    }

    esat::DrawSetStrokeColor(255,255,255);  
    esat::DrawSetFillColor(0,0,0,0);
    esat::DrawSolidPath(&(p->points_ball)->x,30);
    }
}



/*Moves the ball every frame 
@param ball stucture
*/
void UpdateBall(Ball *ball){
    Ball *p;

    for(p=ball;p!=nullptr;p=p->Sig){
        if(p->attached){
            p->position_ball.x = g_player.position_player.x+((kIWidth/5)/2);
            p->position_ball.y = g_player.position_player.y-p->radius_ball;
        }else{
            p->position_ball.x += p->direction.x * g_delta_time;
            p->position_ball.y += p->direction.y * g_delta_time;
        }
    }

}




void LaunchBall(Ball *ball){
    Ball *p; 
    
        for(p=ball;p!=nullptr;p=p->Sig){
         if(p->attached){    
                if(esat::IsSpecialKeyDown(esat::kSpecialKey_Space)){
                        p->attached = false;
                }
         }
    }
}




/*Detects collision between the wall and the ball 
@param ball stucture
*/
void WallColisions(Ball *ball){
    Ball *p;

    for(p=ball;p!=nullptr;p=p->Sig){
        if(p->position_ball.x-p->radius_ball <= 0){
            p->position_ball.x = p->radius_ball;
            p->direction.x = -p->direction.x;
        }

        if(p->position_ball.x+p->radius_ball >= kIWidth){
            p->position_ball.x = kIWidth-p->radius_ball;
            p->direction.x = -p->direction.x;
        }

        if(p->position_ball.y-p->radius_ball <= 0){
            p->direction.y = -p->direction.y;
        }

        if(p->position_ball.y+p->radius_ball >= kIHeight){
            p->destroyed = true;
        }
    }
}


