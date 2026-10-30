#include <raylib.h>
# define Width 800
#define Height 600
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