


/*Draws the bricks
@param the first node of the list
*/
void DrawBricks(Bricks *A){
    Bricks *p;
    float width = (kIWidth-100) / 12;
    float height = (kIHeight/2.5) / 12;
    
 for(p = A;p!=nullptr;p=p->Sig){
        
        *(p->points_brick + 0) = {p->position_brick.x,p->position_brick.y};
        *(p->points_brick + 1) = {p->position_brick.x+width,p->position_brick.y};
        *(p->points_brick + 2) = {p->position_brick.x+width,p->position_brick.y+height};
        *(p->points_brick + 3) = {p->position_brick.x,p->position_brick.y+height};

        esat::DrawSetStrokeColor(p->colour.r,p->colour.g,p->colour.b);  
        esat::DrawSetFillColor(0,0,0,0);  
        esat::DrawSolidPath(&(p->points_brick)->x,4);
    }
}

/*Once a collision is detected this function detects the length from the ball to the brick
turns it to an angle with the atan2 function and lastly convert it to a direction whith the sin and cos functions 
@param first node of the list Ball ans Bricks
*/
void ChangeDirrBallWithBrick(Ball *ball,Bricks *brick){
      float width = (kIWidth-100) / 12;
      float height = (kIHeight/2.5) / 12;
      MATH::Vec2 middle_point = {brick->position_brick.x+(width/2),brick->position_brick.y+(kIHeight/2)};
      MATH::Vec2 distance = MATH::Vec2Subtract(ball->position_ball,brick->position_brick);
      MATH::Vec2 n_length = MATH::Vec2Normalize(distance);
      float angle = atan2(n_length.y,n_length.x);
      ball->direction = {cosf(angle) * 400,sinf(angle) * 400};
}




/*Detects if theres a colision between the ball and the bricks if true destroys the brick and reverses the direction of the ball 
@param the first node of the list
*/
void CollisionBallWhithBricks(Bricks *q,Ball *ball) {
    Bricks *p;
    MATH::Vec2 a, b, n;
    int resultado;
    Ball *ba;

for(ba=ball;ba!=nullptr;ba=ba->Sig){
    for (p = q;p!=nullptr;p=p->Sig) {
        for (int i = 0; i <30;i++) {
            resultado = 0;

            for (int j = 0; j < 4; j++) {
                a = *(p->points_brick + j);
                b = (j == 3) ? *(p->points_brick + 0) : *(p->points_brick + j + 1);

                MATH::Vec2 v = MATH::Vec2Subtract(b, a);
                v = MATH::Vec2Normalize(v);
                n = MATH::Vec2PerpendicularMetodo1(v);
                MATH::Vec2 w = MATH::Vec2Subtract(*(ba->points_ball + i), a);
                float f = MATH::Vec2Dot(w, n);

                if (f < 0) {
                    resultado++;
                }
            }

            if (resultado == 0) {
                ChangeDirrBallWithBrick(ba,p);
                g_player.score += 20;
                p->destroyed = true;
                break;
            }
        }
    }
}
}
