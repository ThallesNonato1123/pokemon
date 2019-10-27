#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define numPokemon 151 // 151 Pokemons, criada para o ler os status dos respectivos Pokemons no laço for

void asterisco()
{
    printf("\n");
    int i;
    for (i = 0; i < 80 ; i++)
        printf("*");
    printf("\n\n");
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
Golpes ataque[207];
int golpeselecionado;
double danoEx;

void Read_Data() 
{ //função para ler os dados dos pokèmons
    FILE *status; // arquivo "Pokemon.txt" com os dados dos pokèmons
    status = fopen("pokemon.txt", "r");
    if (status == NULL) {
        printf("Erro na abertura de Pokemóns\n");
    }
    int i;
    for (i = 1 ; i <= numPokemon ; i++) { // loop para pegar os dados dos 151 pokèmons
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
        fscanf(polgues, "%c", ataque[i].modoGolpe);
        fgets(ataque[i].nomeGolpe, 23, polgues);
        fscanf(polgues, "%f %f", &ataque[i].f_golpe, &ataque[i].g_energia);
        fscanf(polgues, "%d", ataque[i].numGolpe);
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
    printf("\nEscolha o clima da batalha:\n");
    printf("1 - Clear/Sunny\n2 - Party Cloud\n3 - Cloudy\n4 - Rain\n5 - Snow\n6 - Fog\n7 - Windy\n\n");
    scanf("%d", &climaEscolhido);
    asterisco();
    return climaEscolhido;
}

float BonusClima(int a, Pokemon escolhido)
{    
    if( a == 1 && (*escolhido.tipo1 == 1 || *escolhido.tipo2 == 1 || *escolhido.tipo1 == 2 || *escolhido.tipo2 == 2 || *escolhido.tipo1 == 3 || *escolhido.tipo2 == 3  ))
        escolhido.fGolpe[golpeselecionado-1].f_golpe *= 1.3;
    
    if( a == 2 && (*escolhido.tipo1 == 4 || *escolhido.tipo2 == 4 || *escolhido.tipo1 == 5 || *escolhido.tipo2 == 5))
        escolhido.fGolpe[golpeselecionado-1].f_golpe *= 1.3;
    
    if( a == 3 && (*escolhido.tipo1 == 6 || *escolhido.tipo2 == 6 || *escolhido.tipo1 == 7 || *escolhido.tipo2 == 7 || *escolhido.tipo1 == 8 || *escolhido.tipo2 == 8  ))
        escolhido.fGolpe[golpeselecionado-1].f_golpe *= 1.3;
    
    if( a == 4 && (*escolhido.tipo1 == 9 || *escolhido.tipo2 == 9 || *escolhido.tipo1 == 10 || *escolhido.tipo2 == 10 || *escolhido.tipo1 == 11 || *escolhido.tipo2 == 11  ))
        escolhido.fGolpe[golpeselecionado-1].f_golpe *= 1.3;
    
    if( a == 5 && (*escolhido.tipo1 == 12 || *escolhido.tipo2 == 12 || *escolhido.tipo1 == 13 || *escolhido.tipo2 == 13))
        escolhido.fGolpe[golpeselecionado-1].f_golpe *= 1.3;
    
    if( a == 6 && (*escolhido.tipo1 == 14 || *escolhido.tipo2 == 14 || *escolhido.tipo1 == 15 || *escolhido.tipo2 == 15))
        escolhido.fGolpe[golpeselecionado-1].f_golpe *= 1.3;
    
    if( a == 7 && (*escolhido.tipo1 == 16 || *escolhido.tipo2 == 16 || *escolhido.tipo1 == 17 || *escolhido.tipo2 == 17 || *escolhido.tipo1 == 18 || *escolhido.tipo2 == 18 ))
        escolhido.fGolpe[golpeselecionado-1].f_golpe *= 1.3;

    return escolhido.fGolpe[golpeselecionado-1].f_golpe;
}

Pokemon EscolhePokemon()  
{   
    Pokemon p;
    int num;
    while(1) { // laço para controlar a seleção de Pokemon
        printf("Digite o numero correspondente ao Pokemon desejado: ");
        scanf("%d", &num); //  número correspondente ao Pokèmon desejado
        if (num < 0 || num > 151)
            printf("Pokemon invalido\n");
        else
            break;
    }
    asterisco();
    printf("Digite o nivel do Pokemon escolhido: ");
    scanf ("%f", &monstro[num].lvl);
    asterisco();
    monstro[num].hp = (monstro[num].stamina * 2 * monstro[num].lvl)/100 + monstro[num].lvl + 10; // cálculo do hp
    p = monstro[num];
    printf("Você escolheu %s!\n", p.nome);
    return p;
}

void EscreveNomePokemon() // NÃO TERMINADA ---------------------
{
    int i;
    for (i = 1 ; i <= 150 ; i = i + 5) {
        printf("%d - %s\t\t", monstro[i].num, monstro[i].nome);
        printf("%d - %s\t\t", monstro[i+1].num, monstro[i+1].nome);
        printf("%d - %s\t\t", monstro[i+2].num, monstro[i+2].nome);
        printf("%d - %s\t\t", monstro[i+3].num, monstro[i+3].nome);
        printf("%d - %s\n", monstro[i+4].num, monstro[i+4].nome);
    }
    printf("151 - Mew\n\n");
}

void EscolheGolpe(Pokemon escolhido) // ver parada do strcmp
{
    Golpes GolpesPossiveis[6];
    int numEscolhidoC, numEscolhidoR;
    printf("Golpes possíveis para %s:\n", escolhido.nome);
    int i, j;
    for(i = 0 ; i < 7 ; i++) {
        for(j = 0 ; j < 207 ; j++) {            
            if(escolhido.numAtk[i] == *ataque[j].numGolpe) {
                GolpesPossiveis[i] = ataque[j];
            }
        }
        if (*GolpesPossiveis[i].numGolpe != 0)
            printf("%d - %s%s\n", i+1, GolpesPossiveis[i].modoGolpe, GolpesPossiveis[i].nomeGolpe);
    }
        printf("\nEscolha um Golpe rapido: ");
        scanf("%d", &numEscolhidoR);
        //if(strcmp(GolpesPossiveis[numEscolhidoR-1].modoGolpe,"C")==0)
        printf("\nVocê escolheu o golpe: %s \n", GolpesPossiveis[numEscolhidoR-1].nomeGolpe);
        printf("\nEscolha um golpe carregado: ");
        scanf("%d",&numEscolhidoC);
        printf("\nVocê escolheu o golpe: %s \n", GolpesPossiveis[numEscolhidoC-1].nomeGolpe);
        escolhido.fGolpe[0] = GolpesPossiveis[numEscolhidoR-1];
        escolhido.fGolpe[1] = GolpesPossiveis[numEscolhidoC-1];
}       

Golpes selecionaGolpe(Pokemon escolhido) // porque nao ta aparecendo os fGolpe
{
    Golpes aux;
    int golpeselecionado;
    printf("Selecione o golpe que vai usar:\n1 - %s\n2 - %s", escolhido.fGolpe[0].nomeGolpe, escolhido.fGolpe[1].nomeGolpe);
    scanf("%d", &golpeselecionado);
    aux.f_golpe = escolhido.fGolpe[golpeselecionado-1].f_golpe;
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
              printf("Pokemon %d (Player %d) ganhou de %d com %f de hp restante\n", p2[j].num, 2, p1[i].num, p2[j].hp);
              i++;
            }
      }
}

int main () {
    Pokemon A;
    int b;
    TransfereDados();
    Read_Data();
    EscreveNomePokemon();
    LerGolpe();
    A = EscolhePokemon();
    b = LerClima();
    BonusClima(b, A);
    EscolheGolpe(A);
    
    return 0;
}
