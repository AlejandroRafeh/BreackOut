
Ball *SearchBall(Ball *ball){
 
Ball *p;
    for(p=ball;p!=nullptr;p=p->Sig){
        if(p->destroyed){
                    return p;
        }
    }

    return nullptr;

}

void FreeBall(Ball **ball){

Ball *node_to_free = SearchBall(g_ball);    

if(node_to_free == nullptr){
    return;
}

    if(*ball == node_to_free){
        *ball = node_to_free->Sig;
        free(node_to_free);
    }

    Ball *Aux = *ball;
    for(Aux;Aux!=nullptr && Aux->Sig != node_to_free;Aux=Aux->Sig);

    if(Aux == nullptr){
        return;
    }

    Aux->Sig = node_to_free->Sig;
    free(node_to_free);
}



/*Links a node to the list
@param the first node of the list,numumber of the column,number of the row
*/
void InsertBricks(Bricks **brick,int i,int j){
    float width = (kIWidth-100) / 12;
    float height = (kIHeight/2.5) / 12;

    if(j % 12 == 0){
        for(int i = 0;i < 3;i++){
            *(g_change_colour + i) = rand() % 256;
        }
    }

    Bricks *p = (Bricks*) malloc(sizeof(Bricks));
    p->position_brick.x = 50+(width*j);
    p->position_brick.y = 50+height*i;
    p->destroyed = false;
    p->colour.r = *(g_change_colour + 0);
    p->colour.g = *(g_change_colour + 1);
    p->colour.b = *(g_change_colour + 2);
    p->points_brick = (MATH::Vec2*) malloc(4 * sizeof(MATH::Vec2));
    p->points_brick_collision = (MATH::Vec2*) malloc(15 * sizeof(MATH::Vec2));
    p->Sig = nullptr;

    if(*brick == nullptr){
        *brick = p;
    }else{
        p->Sig = *brick;
        *brick = p;
    }
}



/*Search if a node is destroyed
@param first node of the list
@return the node that is detroyed 
*/
Bricks * SearchNode(Bricks* node){
    Bricks *p = node;

    if(p == nullptr){
        return nullptr;
    }

    while (p != nullptr){
        if(p->destroyed){
            return p;
        }
        p=p->Sig;
    }

   return nullptr; 
    
}

/*Frees node from the list
@param the first node of the list by refrence 
*/
void FreeNode(Bricks **Cabeza){
    Bricks *aux = *Cabeza;

    // get the node that needs to be freed
    Bricks *free_node = SearchNode(g_brick);

    //if theres nothing to destroy return
    if(free_node == nullptr){
        return;
    }
   
   //if the node is the first of the list 
        if(*Cabeza == free_node){
            *Cabeza = free_node->Sig;
            free(free_node);
            return;
        }    

// if the node is not the first of the list
    while(aux->Sig != free_node){
        aux = aux->Sig;
    }

    
 // Change the pointer to bypass the node to be freed
   aux->Sig = free_node->Sig;
   free(free_node);
    

}

void InsertBall(Ball **ball,MATH::Vec2 pos,MATH::Vec2 direction,bool attached,int radius){
    Ball *new_ball = (Ball*) malloc(sizeof(Ball));
    new_ball->position_ball = pos;
    new_ball->direction = direction;
    new_ball->points_ball = (MATH::Vec2*) malloc(30 * sizeof(MATH::Vec2));
    for(int i = 0; i < 30;i++){
        *(new_ball->points_ball + i) = {0,0};
    }
    new_ball->radius_ball = 10;
    new_ball->attached = attached;
    new_ball->destroyed = false;
    new_ball->Sig = nullptr;
    if(*ball == nullptr){
        *ball = new_ball;
    }else{
        new_ball->Sig = *ball;
        *ball = new_ball;
    }
}

