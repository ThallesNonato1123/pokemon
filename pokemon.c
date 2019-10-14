#include <stdio.h>
#include <math.h>
#define numPokemon 151 // 151 pokemons, criada para o ler os status dos respectivos pokemons no laço for
typedef struct{
    float lvl;
    char nome[51],tipo1[10],tipo2[10];
    unsigned  num,speed;
    float ataque,defesa,stamina,hp;
    float f_golpe;
}pokemon;
 pokemon read_data(){ //função para ler os dados dos pokémons
  pokemon aux[numPokemon]; // variável auxiliar para armazenar os dados dos pokemons
  pokemon p; //criei para retornar os dados do pokemon escolhido
  FILE *status; // arquivo "pokemon.txt" com os dados dos pokemons
  status = fopen("pokemon.txt","r"); 
  if(status == NULL){
    printf("Erro na abertura do arquivo\n");
  }
  for(int i=1; i<numPokemon ;i++){ // loop para pegar os dados dos 151 pokemons
   fscanf(status,"%d %s %f %f %f %s %s",&aux[i].num,&aux[i].nome,&aux[i].stamina,&aux[i].ataque,&aux[i].defesa,&aux[i].tipo1,&aux[i].tipo2);
   }
   fclose(status);
  printf("Digite o valor correspondente ao Pokemon e o seu nivel: ");
  int num;
  scanf("%d %f",&num,&p.lvl); //  numero correspondente ao pokemon escolhido e lvl do pokemon
  aux[num].hp = (aux[num].stamina * 2 * p.lvl)/100 + p.lvl + 10; // cálculo do hp
  p=aux[num]; // dados do pokemon escolhido
  return p;
}
void battle(pokemon p1[], pokemon p2[]) {
  int i = 0, j = 0;
  while(i < 3 && j < 3) {
    int bate = (p1[i].speed > p2[j].speed) ? 0 : 1;
    while(p1[i].hp > 0 && p2[j].hp > 0) {
      if(bate == 0) { // P2[j] apanha
        p2[j].hp -= ((2 * p1[i].lvl / 5 + 2) * p1[i].f_golpe * (p1[i].ataque / p2[j].defesa)) / 50 + 2;
        bate = 1;
      } else { // P1[i] apanha
        p1[i].hp -= ((2 * p2[j].lvl / 5 + 2) * p2[j].f_golpe * (p2[j].ataque / p1[i].defesa)) / 50 + 2;
        bate = 0;
      }
    }
    if(p1[i].hp > 0) { // p1[i] sobreviveu
      printf("Pokemon %d (Player %d) ganhou de %d com %f de hp restante\n", p1[i].num, 1, p2[j].num, p1[i].hp);
      j++;
    } else { // p2[j] sobreviveu
      printf("Pokemon %d (Player %d) ganhou de %d com %f de hp restante\n", p2[j].num, 2,  p1[i].num, p2[j].hp);
      i++;
    }
  }
}
int main(){
    pokemon a;
    a=read_data();
    printf("%d  %s\n",a.num,a.nome);
}

