<<<<<<< HEAD

#include <raylib.h>
# define Width 800
#define Height 600
#define Paticle_NUM 15
typedef struct {
    float x,y,r,vx,vy;
}particle;
void Drawparticle(particle *particle){
DrawCircle(particle->x,particle->y,particle->r,BLUE);
}
void Updateparticle(particle *particle){
    //for the movement 
    particle->x+=particle->vx;
    particle->y+=particle->vy;
    float x = particle->x;
    float y= particle->y;
    float r= particle->r;
    //collision with walls
    if (x-r<0)
    {
        particle->vx=-particle->vx;
    }
    if (x+r>Width)
    {
        particle->vx=-particle->vx;
    }
    if (y-r<0)
    {
        particle->vy=-particle->vy;
    }
    if (y+r>Height)
    {
        particle->vy=-particle->vy;
    }
}
int main(){

SetTargetFPS(60);
InitWindow(800,600,"Particle Simulation");
particle p1 ={400,300,10,5,7};
particle p2 ={200,350,10,4,2};
particle p3 ={100,200,10,3,20};
particle p4 ={400,220,10,5,6};
particle p5 ={560,30,10,7,8};
particle p6 ={700,320,10,-4,2};
particle p7 ={40,310,10,5,2};
while (!WindowShouldClose())
{
    BeginDrawing();
    ClearBackground(BLACK);
    Drawparticle(&p1);
    Updateparticle(&p1);
    Drawparticle(&p2);
    Updateparticle(&p2);
    Drawparticle(&p3);
    Updateparticle(&p3);
    Drawparticle(&p4);
    Updateparticle(&p4);
    Drawparticle(&p5);
    Updateparticle(&p5);
    Drawparticle(&p6);
    Updateparticle(&p6);
    Drawparticle(&p7);
    Updateparticle(&p7);
    EndDrawing();

}
CloseWindow();
