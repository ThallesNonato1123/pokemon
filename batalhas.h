#include <stdio.h>
#include <math.h>
typedef struct{
    float lvl;
    unsigned double number,speed;
    unsigned b_atk,b_def,b_sta,hp;
    float f_golpe;
}pokemon;
 pokemon read_data(){
    pokemon v[];
    for(int j=0;j<3;j++){
    printf("%d Pokemon",i);
    scanf("%f %u %u %u %u %u %u %f",v[j].lvl,v[j].number,v[j].speed,v[j].b_atk,v[j].b_def,v[j].b_def,v[i].b_sta,v[j].f_golpe);
        }
    } 
 }
 void battle(pokemon p1[],pokemon p2[]){
     double dano1,dano2,hp1,hp2;
     for(int i=0; i<3; i++){
         dano1=((2*p1[i].lvl/5)+2*p1[i].f_golpe*((p1[i].b_atk/p1[i].b_def)/50)+2);
         dano2=((2*p2[i].lvl/5)+2*p2[i].f_golpe*((p2[i].b_atk/p2[i].b_def)/50)+2);
         hp1=(((p1[i].b_sta*2*p1[i].lvl)/100)+p1[i].lvl+10);
         hp2=(((p2[i].b_sta*2*p2[i].lvl)/100)+p2[i].lvl+10);
         if(p1[i].speed>p2[i].speed){
             do{
                hp2-=dano1;
                hp1-=dano2; 
             }while(hp1 !=0 || hp2 !=0);
             if(hp1 == 0)
                printf("Jogador 2 ganhou o round");
             else
                printf("Jogador 1 ganhou o round");
         }else{
             do{
                hp1-=dano2;
                hp2-=dano1; 
             }while(hp1 !=0 || hp2 !=0);
             if(hp1 == 0)
                printf("Jogador 2 ganhou o round");
             else
                printf("Jogador 1 ganhou o round");
         }
     }
 }
