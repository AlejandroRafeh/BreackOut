void DrawPlayerShip(Player *player){
    *(player->points_player + 0) = {player->position_player.x,player->position_player.y};
    *(player->points_player + 1) = {player->position_player.x+(kIWidth/5),player->position_player.y};
    *(player->points_player + 2) = {player->position_player.x+(kIWidth/5),player->position_player.y+20};
    *(player->points_player + 3) = {player->position_player.x,player->position_player.y+20};

    esat::DrawSetStrokeColor(255,255,255); 
    esat::DrawSetFillColor(0,0,0,0);
    esat::DrawSolidPath(&(player->points_player)->x,4);
}


void MovePlayerShip(Player *player,int movment_speed){
      if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Right) && player->position_player.x+(kIWidth/5) < kIWidth){
        player->position_player.x += movment_speed;
    }

    if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Left) && player->position_player.x > 0){
        player->position_player.x -= movment_speed;
    }
}

void Punctuation(){
    itoa(g_player.score,g_player.text_score,10);
    esat::DrawSetFillColor(255, 255, 255, 255);
    esat::DrawSetTextSize(30);
    esat::DrawText(50, 40, "SCORE:");
    esat::DrawText(220, 40,g_player.text_score);
}


/*Once a collision is detected this function detects the length from the ball to the player
turns it to an angle with the atan2 function and lastly convert it to a direction whith the sin and cos functions 
@param first node of the list Ball
*/
void ChangeDirrBallWithPlayer(Ball *ball){
      MATH::Vec2 middle_point = {g_player.position_player.x+((kIWidth/5)/2),g_player.position_player.y+(20/2)};
      MATH::Vec2 distance = MATH::Vec2Subtract(ball->position_ball,middle_point);
      MATH::Vec2 n_length = MATH::Vec2Normalize(distance);
      float angle = atan2(n_length.y,n_length.x);
      ball->direction = {cosf(angle) * 400,sinf(angle) * 400};
}

/*Detects a colision between the ball and the ship if true reverses the direction of the ball
*/
void CollisionBallWithShip(Ball *ball) {
    MATH::Vec2 a, b, n;
    int resultado;
    Ball *p;

//points ball
    for(p=ball;p!=nullptr;p=p->Sig){
        for (int i = 0; i < 30;i++) {
            resultado = 0;

//points brick
            for (int j = 0; j < 4; j++) {
                a = *(g_player.points_player + j);
                b = (j == 3) ? *(g_player.points_player + 0) : *(g_player.points_player + j + 1);

                MATH::Vec2 v = MATH::Vec2Subtract(b, a);
                v = MATH::Vec2Normalize(v);
                n = MATH::Vec2PerpendicularMetodo1(v);
                MATH::Vec2 w = MATH::Vec2Subtract(*(p->points_ball + i), a);
                float f = MATH::Vec2Dot(w, n);

                if (f < 0) {
                    resultado++;
                }
            }

            if (resultado == 0) {
                ChangeDirrBallWithPlayer(p);
                break;
            }
        }
    }    
    
}
