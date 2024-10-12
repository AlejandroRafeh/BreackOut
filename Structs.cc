unsigned char fps=25.0f; 
double current_time,last_time;

int *g_change_colour = (int*) malloc(3 * sizeof(int));
double g_delta_time;
const int kIHeight = 750;
const int kIWidth = 750;




typedef struct Colour{
    unsigned char r,g,b,a;
}Colour;

struct Bricks{
    MATH::Vec2 position_brick,*points_brick,*points_brick_collision;
    bool destroyed;
    Colour colour;
    Bricks *Sig;
};

struct Player{
    MATH::Vec2 position_player,*points_player;
    char *text_score;
    int lives,score;
};


struct Ball{
    MATH::Vec2 position_ball,direction,*points_ball;
    bool attached,destroyed;
    int radius_ball;
    Ball *Sig;
};


enum GameControl{
    kGameControlMenu = 0,
    kGameControlGame,
    kGameControlGameOver,
};

GameControl g_state = kGameControlMenu;
Bricks *g_brick;
Player g_player = {{400.0f,700.0f},NULL,'\0',3,0};
Ball *g_ball;


