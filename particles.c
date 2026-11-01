

#include <raylib.h>
#include <time.h>
# define Width 800
#define Height 600
#define Particle_NUM 15
typedef struct {
    float x,y,r,vx,vy;
}particle;
particle Particles[Particle_NUM];
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
void Drawparticles(){
   for(int i=0;i<Particle_NUM;i++){
    Drawparticle(Particles+i);
   }
}
void Updateparticles(){
     for(int i=0;i<Particle_NUM;i++){
        Updateparticle(Particles+i);
     }
}
void Initparticles(){
    SetRandomSeed(time(NULL));
    for(int i=0;i<Particle_NUM;i++){
        int radius=GetRandomValue(5,15);
        Particles[i].r=radius;
        Particles[i].x=GetRandomValue(radius,Width-radius);
        Particles[i].y=GetRandomValue(radius,Height-radius);
        Particles[i].vx=GetRandomValue(-5,5);
        Particles[i].vy=GetRandomValue(-5,5);
        
    }
}

int main(){

SetTargetFPS(60);
InitWindow(800,600,"Particle Simulation");
Initparticles();
while (!WindowShouldClose())
{
    BeginDrawing();
    ClearBackground(BLACK);
    Drawparticles();
    Updateparticles();
    EndDrawing();

}
CloseWindow();
}