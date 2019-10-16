#include <stdio.h>
#include <math.h>
#define numPokemon 151 // 151 pokemons, criada para o ler os status dos respectivos pokemons no laço for
typedef struct{
    int t_golpe[16];
    float g_energia;
    char nomeGolpe[210], modoGolpe[210];
}golpes; //struct criada para armazenar os dados dos golpes: força, tipo, ganho de energia, nome do golpe e modo do Golpe (rápido ou carregado)

typedef struct {
    float lvl;
    char nome[51];
    unsigned  num,speed,tipo1[10],tipo2[10];
    float ataque, defesa, stamina,hp;
    int numAtk[7];
    float f_golpe;
}pokemon;

pokemon read_data() { //função para ler os dados dos pokèmons
    pokemon aux[numPokemon]; // variável auxiliar para armazenar os dados dos pokèmons
    pokemon p; //criei para retornar os dados do pokèmon escolhido
    FILE *status; // arquivo "pokemon.txt" com os dados dos pokèmons
    status = fopen("pokemon.txt", "r");
    if (status == NULL) {
        printf("Erro na abertura do arquivo\n");
    }
    for (int i = 1 ; i < numPokemon ; i++) { // loop para pegar os dados dos 151 pokèmons %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        fscanf(status, "%d %s %f %f %f %d %d", &aux[i].num, &aux[i].nome, &aux[i].stamina, &aux[i].ataque, &aux[i].defesa, &aux[i].tipo1, &aux[i].tipo2);
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

void LerGolpe()
{
    FILE *polgues; // arquivo golpes
    polgues = fopen("ataques.txt", "r"); //recebe os dados do golpe
    if(polgues == NULL) {
        printf("Erro na abertura do arquivo\n");
    }
    for(int i = 0 ; i < 208 ; i++) {
       // fscanf(polgues, "%d %c", &golpes[i].t_golpe, &golpes[i].modoGolpe);
       // fgets(golpes[i].nomeGolpe, 23, polgues);
       // fscanf(polgues, "%f %f", &golpes[i].f_golpe, &golpes[i].g_energia);
    }
    fclose(polgues);
}

pokemon Aux;
void TransfereDados()
{
    FILE *dadospok;
    dadospok = fopen("ataque_cada_pokemon_1-1", "r");
    for(int i = 0 ; i < 150 ; i++) { // 150 pois o Mew é diferente dos demais
        //  fscanf(dadospok, "%d %d %d %d %d %d", Aux[i].numatk[0], Aux[i].numatk[1], Aux[i].numatk[2], Aux[i].numatk[3], Aux[i].numatk[4], Aux[i].numatk[5],Aux[i].numatk[6]);
    }
}
void EscolheGolpe()
{
    FILE *ataquePokemon;
    ataquePokemon = fopen("ataques.txt", "r");

}


int main () {
    pokemon A;
    A = read_data();
    printf("%s %.2f\n", A.nome, A.hp);
    return 0;
}
