
#include <math.h>
#include <raylib.h>
#include <time.h>
# define Width 800
#define Height 600
#define Particle_NUM 80
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
    {   particle->x=r;
        particle->vx=-particle->vx;
    }
    if (x+r>Width)
    {   particle->x=Width-r;
        particle->vx=-particle->vx;
    }
    if (y-r<0)
    {    particle->y=r;
        particle->vy=-particle->vy;
    }
    if (y+r>Height)
    {particle->y=Height-r;
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
void CollideAllparticles(){
    particle p1;
    particle p2;
    for(int i=0;i<Particle_NUM;i++){
        for(int j=i+1;j<Particle_NUM;j++){
            if(i==j) break;
         p1=Particles[i];
         p2=Particles[j];
         Vector2 c1={p1.x,p1.y};
         Vector2 c2={p2.x,p2.y};
         bool collide= CheckCollisionCircles(c1,p1.r,c2,p2.r);
         if(collide==true){
            float dx=p1.x-p2.x;
            float dy=p1.y-p2.y;
            float abs_d=sqrt(pow(dx,2)+pow(dy,2));
            float nx=dx/abs_d;
            float ny=dy/abs_d;
            float overlap=((p2.r+p1.r)-abs_d);
            Particles[i].x+=nx*overlap/2;
            Particles[i].y+=ny*overlap/2;
            Particles[j].x+=-nx*overlap/2;
            Particles[j].y+=-ny*overlap/2;
            float tx=-ny;
            float ty=nx;
            float v1t=(p1.vx*tx+p1.vy*ty);
            float v1n=(p1.vx*nx+p1.vy*ny);
            float v2t=(p2.vx*tx+p2.vy*ty);
            float v2n=(p2.vx*nx+p2.vy*ny);
            float vflip=v2n;
            v2n=v1n;
            v1n=vflip;
            Particles[i].vx=v1t;
            Particles[i].vy=v1n;
            Particles[j].vx=v2t;
            Particles[j].vy=v2n;
         }
        }
    }
}
void Initparticles(){
    SetRandomSeed(time(NULL));
    for(int i=0;i<Particle_NUM;i++){
        int radius=GetRandomValue(10,15);
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
    CollideAllparticles();
    Updateparticles();
    Drawparticles();
   
    
    
    
    EndDrawing();

}
CloseWindow();
}