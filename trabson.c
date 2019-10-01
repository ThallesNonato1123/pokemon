#include <stdio.h>
#include <math.h>

void asterisco() // só pra separar direitinho no terminal
{
    for (int i = 0; i < 35 ; i++)
        printf("*");
    printf("\n");
}

typedef struct {
    float level;
    unsigned double number, speed;
    unsigned b_atk, b_def, b_stamina, hp;
    float forca_golpe;
}pokemon;
 pokemon read_data(){
    pokemon v[];
    for (int j = 0 ; j < 3 ; j++) {
    printf("Pokemon %d", i + 1);
    scanf("%f %u %u %u %u %u %u %f", v[j].level, v[j].number, v[j].speed, v[j].b_atk,v[j].b_def, v[j].b_def, v[i].b_stamina, v[j].forca_golpe);
        }
    } 
 }

 void battle(pokemon p1[], pokemon p2[]) {
     double dano1, dano2, hp1, hp2;
     for (int i = 0 ; i < 3 ; i++) {
         dano1 = ((2 * p1[i].level / 5) + 2 * p1[i].forca_golpe * ((p1[i].b_atk / p1[i].b_def) / 50) + 2);
         dano2 = ((2 * p2[i].level / 5) + 2 * p2[i].forca_golpe * ((p2[i].b_atk / p2[i].b_def) / 50) + 2);
         hp1 = (((p1[i].b_stamina * 2 * p1[i].level) / 100) + p1[i].level + 10);
         hp2 = (((p2[i].b_stamina * 2 * p2[i].level) / 100) + p2[i].level + 10);
         if (p1[i].speed > p2[i].speed) {
             do {
                hp2 -= dano1;
                hp1 -= dano2; 
             } while (hp1 !=0 || hp2 !=0);
             if (hp1 == 0)
                printf("Jogador 2 ganhou o round");
             else
                printf("Jogador 1 ganhou o round");
         }else {
             do {
                hp1 -= dano2;
                hp2 -= dano1; 
             } while (hp1 !=0 || hp2 !=0);
             if (hp1 == 0)
                printf("Jogador 2 ganhou o round");
             else
                printf("Jogador 1 ganhou o round");
         }
     }
 }