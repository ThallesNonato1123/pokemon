#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define numPokemon 151 // 151 Pokemons, criada para o ler os status dos respectivos Pokemons no laço for

void asterisco()
{
    printf("\n");
    for (int i = 0; i < 50 ; i++)
        printf("*");
    printf("\n");
}
typedef struct{
    int t_golpe[16];  // tipo de golpe (fire, grass...)
    float g_energia; // ganho de energia
    char nomeGolpe[210], modoGolpe[210]; // modo: rápido ou carregado
    float f_golpe;
    int numGolpe[206];
}Golpes; //struct criada para armazenar os dados dos Golpes: força, tipo, ganho de energia, nome do golpe e modo do Golpe (rápido ou carregado)

typedef struct {
    float lvl;
    char nome[51];
    int num, speed,tipo1[20], tipo2[20];
    float ataque, defesa, stamina,hp;
    int numAtk[6];
    Golpes fGolpe[2];
}Pokemon;

typedef struct {
    Pokemon poke[3];
    Golpes TmodoGolpe;
}treinador;


Pokemon monstro[numPokemon];
Golpes  ataque[207];

void Read_Data() 
{ //função para ler os dados dos pokèmons
    FILE *status; // arquivo "Pokemon.txt" com os dados dos pokèmons
    status = fopen("pokemon.txt", "r");
    if (status == NULL) {
        printf("Erro na abertura de Pokemóns\n");
    }
    int i;
    for (i = 1 ; i <= numPokemon ; i++) { // loop para pegar os dados dos 151 pokèmons %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        fscanf(status, "%d %s %f %f %f %d %d", &monstro[i].num, monstro[i].nome, &monstro[i].stamina, &monstro[i].ataque, &monstro[i].defesa, monstro[i].tipo1, monstro[i].tipo2);
    }
    fclose(status);
}

void LerGolpe()
{
    FILE *polgues; // arquivo Golpes
    polgues = fopen("ataques.txt", "r"); //recebe os dados do golpe
    if (polgues == NULL) {
        printf("Erro na abertura do arquivo\n");
    }
    int i;
    for (i = 0 ; i < 207 ; i++) {
        fscanf(polgues, "%d", ataque[i].t_golpe);
        fscanf(polgues,"%c",ataque[i].modoGolpe);
        fgets(ataque[i].nomeGolpe, 23, polgues);
        fscanf(polgues, "%f %f", &ataque[i].f_golpe, &ataque[i].g_energia);
        fscanf(polgues,"%d",ataque[i].numGolpe);
    }
    fclose(polgues);
}

void TransfereDados()
{    
    FILE *dadosPoke;
    Read_Data();
    dadosPoke = fopen("DadosAtk.txt", "r");
    if(dadosPoke == NULL) {
        printf("Erro na abertura do dadosPoke\n");
    }
    int i;
    for (i = 1 ; i < numPokemon ; i++) {
        fscanf(dadosPoke,"%d %d %d %d %d %d %d", &monstro[i].numAtk[0], &monstro[i].numAtk[1], &monstro[i].numAtk[2], &monstro[i].numAtk[3], &monstro[i].numAtk[4], &monstro[i].numAtk[5], &monstro[i].numAtk[6]);
    }
    fclose(dadosPoke);
}

int LerClima(){
    int climaEscolhido;
    printf("\nEscolha o clima da batalha: \n");
    printf("1-Clear/Sunny\n2-Party Cloud\n3-Cloudy\n4-Rain\n5-Snow\n6-Fog\n7-Windy\n");
    scanf("%d",&climaEscolhido);
    return climaEscolhido;
}

int BonusClima(int a,Pokemon escolhido){
    if( a == 1 && (*escolhido.tipo1 == 1 || *escolhido.tipo2 == 8))
        printf("vantagem\n");
    
}

Pokemon EscolhePokemon()  
{   
    Pokemon p;
    int num;
       scanf("%d", &num); //  numero correspondente ao pokèmon escolhido e lvl do pokèmon
       if (num < 0 || num > 151) // para controlar a escolha de pokèmon
        { 
            printf("Pokemon invalido\n");
        }
        scanf ("%f", &monstro[num].lvl);
        monstro[num].hp = (monstro[num].stamina * 2 * monstro[num].lvl)/100 + monstro[num].lvl + 10; // cálculo do hp
        p = monstro[num];
        printf("Você escolheu %s! \n",p.nome);
        return p;
}

void EscreveNomePokemon() // NÃO TERMINADA ---------------------
{
    int i;
    for (i = 0 ; i < 145 ; i = i + 5) {
        printf("%d - %s\t", monstro[i].num, monstro[i].nome);
        printf("%d - %s\t", monstro[i+1].num, monstro[i+1].nome);
        printf("%d - %s\t", monstro[i+2].num, monstro[i+2].nome);
        printf("%d - %s\t", monstro[i+3].num, monstro[i+3].nome);
        printf("%d - %s\n", monstro[i+4].num, monstro[i+4].nome);
    }
    printf("151 - Mew");
}

void EscolheGolpe(Pokemon escolhido) // ver parada do strcmp
{
    Golpes GolpesPossiveis[6];
    int numEscolhidoC,numEscolhidoR;
    printf("Golpes possíveis para %s: \n",escolhido.nome);
    int i, j;
    for(i = 0 ; i < 7 ; i++) {
        for(j = 0 ; j < 207 ; j++) {            
            if(escolhido.numAtk[i] == *ataque[j].numGolpe) {
                GolpesPossiveis[i] = ataque[j];
            }
        }
        if (*GolpesPossiveis[i].numGolpe != 0)
            printf("%d- %s%s\n",i+1,GolpesPossiveis[i].modoGolpe,GolpesPossiveis[i].nomeGolpe);
    }
        printf("\nEscolha um Golpe rapido: ");
        scanf("%d",&numEscolhidoR);
        //if(strcmp(GolpesPossiveis[numEscolhidoR-1].modoGolpe,"C")==0)
        printf("\nVocê escolheu o golpe:%s \n",GolpesPossiveis[numEscolhidoR-1].nomeGolpe);
        printf("\nEscolha um golpe carregado: ");
        scanf("%d",&numEscolhidoC);
        printf("\nVocê escolheu o golpe:%s \n",GolpesPossiveis[numEscolhidoC-1].nomeGolpe);
        escolhido.fGolpe[0]=GolpesPossiveis[numEscolhidoR-1];
        escolhido.fGolpe[1]=GolpesPossiveis[numEscolhidoC-1];
}       

Golpes selecionaGolpe(Pokemon escolhido) // pq n ta aparecendo os fGolpe
{
    Golpes aux;
    int golpeselecionado;
    printf("Selecione o golpe que vai usar:\n1-%s\n2-%s",escolhido.fGolpe[0].nomeGolpe,escolhido.fGolpe[1].nomeGolpe);
    scanf("%d",&golpeselecionado);
    aux.f_golpe=escolhido.fGolpe[golpeselecionado-1].f_golpe;
    return aux;
}

void Battle(Pokemon p1[], Pokemon p2[]) // NAo terminado
{
    int i = 0, j = 0;
    while (i < 3 && j < 3) {
        int bate = (p1[i].speed > p2[j].speed) ? 0 : 1;
        while (p1[i].hp > 0 && p2[j].hp > 0) {
            if (bate == 0) { // P2[j] sofre dano
               p2[i].hp -= ((2 * p1[i].lvl / 5 + 2) * p1[i].fGolpe[i].f_golpe * (p1[i].ataque / p2[j].defesa)) / 50 + 2;
                bate = 1;
                } else { // P1[i] sofre dano
                p1[i].hp -= ((2 * p2[j].lvl / 5 + 2) * p2[j].fGolpe[i].f_golpe * (p2[j].ataque / p1[i].defesa)) / 50 + 2;
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

int main () {
    Pokemon A;
    int b;
    TransfereDados();
    Read_Data();
    LerGolpe();
    A=EscolhePokemon();
    b=LerClima();
    BonusClima(b,A);
    EscolheGolpe(A);
    
    return 0;
}
