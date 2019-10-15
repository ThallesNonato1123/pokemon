#include <stdio.h>
#include <math.h>
#include <string.h>
#define numPokemon 151 // 151 pokemons, criada para o ler os status dos respectivos pokemons no laço for

typedef struct {
    float lvl;
    char nome[51], tipo1[10], tipo2[10];
    unsigned  num, speed;
    float ataque, defesa, stamina, hp;
    float f_golpe;
}pokemon;

void asterisco()
{
    for (int i = 0; i < 35 ; i++)
        printf("*");
    printf("\n");
}

pokemon read_data() { //função para ler os dados dos pokèmons
    pokemon aux[numPokemon]; // variável auxiliar para armazenar os dados dos pokèmons
    pokemon p; //criei para retornar os dados do pokèmon escolhido
    FILE *status; // arquivo "pokemon.txt" com os dados dos pokèmons
    status = fopen("pokemon.txt", "r"); 
    if (status == NULL) {
        printf("Erro na abertura do arquivo\n");
    }
    for (int i = 1 ; i < numPokemon ; i++) { // loop para pegar os dados dos 151 pokèmons %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        fscanf(status, "%d %s %f %f %f %s %s", &aux[i].num, &aux[i].nome, &aux[i].stamina ,&aux[i].ataque, &aux[i].defesa, &aux[i].tipo1, &aux[i].tipo2);
    }
    fclose(status);
    printf("Digite o valor correspondente ao Pokemon e o seu nivel: ");
    int num;
    scanf("%d", &num); //  numero correspondente ao pokèmon escolhido e lvl do pokèmon
    scanf ("%f", &aux[num].lvl);
    aux[num].hp = (aux[num].stamina * 2 * aux[num].lvl)/100 + aux[num].lvl + 10; // cálculo do hp
    p = aux[num]; // dados do pokemon escolhido
    return p;
}

void battle(pokemon p1[], pokemon p2[]) {
    int i = 0, j = 0;
    while (i < 3 && j < 3) {
        int bate = (p1[i].speed > p2[j].speed) ? 0 : 1;
        while (p1[i].hp > 0 && p2[j].hp > 0) {
            if (bate == 0) { // P2[j] sofre dano
               p2[i].hp -= ((2 * p1[i].lvl / 5 + 2) * p1[i].f_golpe * (p1[i].ataque / p2[j].defesa)) / 50 + 2;
                bate = 1;
                } else { // P1[i] sofre dano
                p1[i].hp -= ((2 * p2[j].lvl / 5 + 2) * p2[j].f_golpe * (p2[j].ataque / p1[i].defesa)) / 50 + 2;
                bate = 0;
                }
        }
        if (p1[i].hp > 0) { // p1[i] sobreviveu
            printf("Pokemon %d (Player %d) ganhou de %d com %f de hp restante\n", p1[i].num, 1, p2[j].num, p1[i].hp);
            j++;
        } else { // p2[j] sobreviveu
            printf("Pokemon %d (Player %d) ganhou de %d com %f de hp restante\n", p2[j].num, 2,  p1[i].num, p2[j].hp);
            i++;
        }
    }
}

int main() {
    pokemon a;
    a = read_data();
    printf("%.2f  %s\n", a.hp, a.nome);

    return 0;
}
