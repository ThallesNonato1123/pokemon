#include <stdio.h>
#include <math.h>
typedef struct{
    float lvl;
    unsigned double number,speed;
    unsigned b_atk,b_def,b_sta,hp;
    float f_golpe;
}pokemon;
 pokemon read_data(){
  pokemon aux;
  scanf("%d %d", &aux.number, &aux.speed);
  scanf("%d %d %d", &aux.b_atk, &aux.b_def, &aux.b_sta);
  scanf("%f %f", &aux.lvl, &aux.f_golpe);
  aux.hp = (aux.b_sta * 2 * aux.lvl)/100 + aux.lvl + 10;
  return aux;
}
void battle(pokemon p1[], pokemon p2[]) {
  int i = 0, j = 0;
  while(i < 3 && j < 3) {
    int bate = (p1[i].speed > p2[j].speed) ? 0 : 1;
    while(p1[i].hp > 0 && p2[j].hp > 0) {
      if(bate == 0) { // P2[j] apanha
        p2[j].hp -= ((2 * p1[i].lvl / 5 + 2) * p1[i].f_golpe * (p1[i].b_atk / p2[j].b_def)) / 50 + 2;
        bate = 1;
      } else { // P1[i] apanha
        p1[i].hp -= ((2 * p2[j].lvl / 5 + 2) * p2[j].f_golpe * (p2[j].b_atk / p1[i].b_def)) / 50 + 2;
        bate = 0;
      }
    }
    if(p1[i].hp > 0) { // p1[i] sobreviveu
      printf("Pokemon %d (Player %d) ganhou de %d com %d de hp restante\n", p1[i].number, 1, p2[j].number, p1[i].hp);
      j++;
    } else { // p2[j] sobreviveu
      printf("Pokemon %d (Player %d) ganhou de %d com %d de hp restante\n", p2[j].number, 2,  p1[i].number, p2[j].hp);
      i++;
    }
  }
}
 
