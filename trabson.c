/* Lista de funções: asterisco - ReadData - Ler Golpe - TransfereDados - LerClima - BonusClima - ceiladora - EscolhePokemon - EscreveNome
                     EscreveNomePokemon - getBound - ValidaEntrada - EscolheGolpe - selecionaGolpe - Battle */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#define numPokemon 151 // 151 Pokemons, criada para o ler os status dos respectivos Pokemons no laço for

typedef struct{
    int t_golpe[16];  // tipo de golpe (fire, grass...)
    float g_energia; // ganho de energia
    char nomeGolpe[210], modoGolpe; // modo: rápido ou carregado
    float f_golpe;
    int numGolpe;
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

//Variáveis globais
Pokemon monstro[numPokemon];
Golpes ataque[207];
int golpeselecionado;
double danoEx;

void asterisco()
{
    printf("\n");
    int i;
    for (i = 0; i < 100 ; i++)
        printf("*");
    printf("\n\n");
}

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
        fscanf(polgues, "%c", &ataque[i].modoGolpe);
        fgets(ataque[i].nomeGolpe, 24, polgues); puts(ataque[i].nomeGolpe);
        fscanf(polgues, "%f %f", &ataque[i].f_golpe, &ataque[i].g_energia);
        fscanf(polgues, "%d", &ataque[i].numGolpe);
    }
    char c; while ( (c=getchar()) != 'q') {}
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

int LerClima() 
{
    int climaEscolhido;
    printf("\n\n\n\n\n\n");
    printf("                                                                         Escolha o clima da batalha\n");
    printf("                                                         -------------------------------------------------------------\n");
    printf("                                                        |                                                             |\n");
    printf("                                                        |                    1 _____ Clear / Sunny                    |\n");
    printf("                                                        |                                                             |\n");
    printf("                                                        |                    2 _____ Partly Cloudy                    |\n");
    printf("                                                        |                                                             |\n");
    printf("                                                        |                    3 _____ Cloudy                           |\n");
    printf("                                                        |                                                             |\n");
    printf("                                                        |                    4 _____ Rain                             |\n");
    printf("                                                        |                                                             |\n");
    printf("                                                        |                    5 _____ Snow                             |\n");
    printf("                                                        |                                                             |\n");
    printf("                                                        |                    6 _____ Fog                              |\n");
    printf("                                                        |                                                             |\n");
    printf("                                                        |                    7 _____ Windy                            |\n");
    printf("                                                        |                                                             |\n");            
    printf("                                                         -------------------------------------------------------------\n");
    printf("\n\n\n\n\n\n");
    while(1) {
        printf("Selecione o clima desejado: ");
        scanf("%d", &climaEscolhido);
        if(climaEscolhido == 1 || climaEscolhido == 2 || climaEscolhido == 3 || climaEscolhido == 4 || climaEscolhido == 5 || climaEscolhido == 6 || climaEscolhido == 7)
            break;
        else
            printf("Escolha um clima valido\n");    
    }
    asterisco();
    return climaEscolhido;
}

void BonusClima(int a, Pokemon escolhido)
{    
    if( a == 1 && (*escolhido.fGolpe[0].t_golpe == 1 ||  *escolhido.fGolpe[0].t_golpe == 2 || *escolhido.fGolpe[0].t_golpe == 3  ))
        escolhido.fGolpe[0].f_golpe *= 1.3;
    
    if( a == 2 && (*escolhido.fGolpe[0].t_golpe == 4 || *escolhido.fGolpe[0].t_golpe == 5))
        escolhido.fGolpe[0].f_golpe *= 1.3;
    
    if( a == 3 && (*escolhido.fGolpe[0].t_golpe == 6 || *escolhido.fGolpe[0].t_golpe == 7 || *escolhido.fGolpe[0].t_golpe == 8 ))
        escolhido.fGolpe[0].f_golpe *= 1.3;
    
    if( a == 4 && (*escolhido.fGolpe[0].t_golpe == 9 || *escolhido.fGolpe[0].t_golpe == 10 || *escolhido.fGolpe[0].t_golpe == 11  ))
        escolhido.fGolpe[0].f_golpe *= 1.3;
    
    if( a == 5 && (*escolhido.fGolpe[0].t_golpe == 12 || *escolhido.fGolpe[0].t_golpe == 13 ))
        escolhido.fGolpe[0].f_golpe *= 1.3;
    
    if( a == 6 && (*escolhido.fGolpe[0].t_golpe == 14  || *escolhido.fGolpe[0].t_golpe == 15 ))
        escolhido.fGolpe[0].f_golpe *= 1.3;
    
    if( a == 7 && (*escolhido.fGolpe[0].t_golpe == 16  || *escolhido.fGolpe[0].t_golpe == 17  || *escolhido.fGolpe[0].t_golpe == 18))
        escolhido.fGolpe[0].f_golpe *= 1.3;

    //golpe 2

    if( a == 1 && (*escolhido.fGolpe[1].t_golpe == 1 ||  *escolhido.fGolpe[1].t_golpe == 2 || *escolhido.fGolpe[1].t_golpe == 3  ))
        escolhido.fGolpe[1].f_golpe *= 1.3;
    
    if( a == 2 && (*escolhido.fGolpe[1].t_golpe == 4 || *escolhido.fGolpe[1].t_golpe == 5))
        escolhido.fGolpe[1].f_golpe *= 1.3;
    
    if( a == 3 && (*escolhido.fGolpe[1].t_golpe == 6 || *escolhido.fGolpe[1].t_golpe == 7 || *escolhido.fGolpe[1].t_golpe == 8 ))
        escolhido.fGolpe[1].f_golpe *= 1.3;
    
    if( a == 4 && (*escolhido.fGolpe[1].t_golpe == 9 || *escolhido.fGolpe[1].t_golpe == 10 || *escolhido.fGolpe[1].t_golpe == 11  ))
        escolhido.fGolpe[1].f_golpe *= 1.3;
    
    if( a == 5 && (*escolhido.fGolpe[1].t_golpe == 12 || *escolhido.fGolpe[1].t_golpe == 13 ))
        escolhido.fGolpe[1].f_golpe *= 1.3;
    
    if( a == 6 && (*escolhido.fGolpe[1].t_golpe == 14  || *escolhido.fGolpe[1].t_golpe == 15 ))
        escolhido.fGolpe[1].f_golpe *= 1.3;
    
    if( a == 7 && (*escolhido.fGolpe[1].t_golpe == 16  || *escolhido.fGolpe[1].t_golpe == 17  || *escolhido.fGolpe[1].t_golpe == 18))
        escolhido.fGolpe[1].f_golpe *= 1.3;

    
}

float ceiladora(float a) // função ceil(x) da biblioteca math.h que não estava funcionando
{
    // se o numero decimal foi igual ao inteiro correspondente, a função retorna o decimal
    if ((a / (int) a) == 1)
        return a;

    // para qualquer outra situaçao o numero é convertido pra inteiro, perdendo a parte decimal, depois incrementado em uma unidade
    // e convertido de volta para decimal
    return (float)((int) a + 1.0);
}

Pokemon EscolhePokemon()  
{   
    Pokemon p;
    int num;
    while(1) { // laço para controlar a seleção de Pokemon
        scanf("%d", &num); //  número correspondente ao Pokèmon desejado
        if (num < 1 || num > 151)
            printf("Pokemon invalido\n");
        else
            break;
    }
    getchar();
    asterisco();
    while(1) { // laço para controlar a seleção do nível do Pokèmon
        printf("Digite o nivel do Pokemon escolhido: ");
        char buffer[1024];
        //scanf ("%f", &monstro[num].lvl);
        fgets (buffer, 1024, stdin);
        if (!(monstro[num].lvl = atof(buffer)))
            continue;
        if(monstro[num].lvl < 1 || monstro[num].lvl > 40) {
            printf("Informe nivel valido\n");
            continue;
        }
        if(ceiladora(monstro[num].lvl/0.5) == monstro[num].lvl/0.5)
            break;
        else {
            printf("Informe nivel valido\n");
            continue;
        }
    }
    monstro[num].hp = (monstro[num].stamina * 2 * monstro[num].lvl)/100 + monstro[num].lvl + 10; // cálculo do hp
    p = monstro[num];
    printf("Você escolheu %s!\n", p.nome);
    return p;
}

void EscreveNome(Pokemon monstro) {
    int i = 0;

    if (monstro.num < 10)
        printf("00%d - ", monstro.num);
    else if (monstro.num < 100)
        printf("0%d - ", monstro.num);
    else
        printf("%d - ", monstro.num);

    while (i < (strlen(monstro.nome) + 8) + 10 - strlen(monstro.nome)) {
        if(monstro.nome[i]) {
            printf("%c", monstro.nome[i]);
        }
        else{
            printf(" ");
        }
        i++;
    }
}

void EscreveNomePokemon()
{
    int i;
    for (i = 1 ; i <= 150 ; i = i + 5) {
        EscreveNome(monstro[i]);
        EscreveNome(monstro[i+1]);
        EscreveNome(monstro[i+2]);
        EscreveNome(monstro[i+3]);
        EscreveNome(monstro[i+4]);
        puts("");
    }
    printf("151 - Mew\n\n");
}

void MostraGolpes(Pokemon *escolhido, Golpes GolpesPossiveis[]) {
    int i;
    
    for(i = 0 ; i < 7 ; i++) {
        if (escolhido->numAtk[i] == 208) {
            GolpesPossiveis[i].numGolpe = 208;
            break;
        }
    
        GolpesPossiveis[i] = ataque[escolhido->numAtk[i]];
        if (GolpesPossiveis[i].numGolpe != 208)
            printf("%d - %c%s\n", i + 1, GolpesPossiveis[i].modoGolpe, GolpesPossiveis[i].nomeGolpe);
    }
}

int getBound(Golpes possiveis[7]){
    for (int i = 0; i < 7; i++) {
        if (possiveis[i].numGolpe == 208)
        return i;
    }
    return 7;
}

int ValidaEntrada(char target, char* msg, Golpes possiveis[7]) {
    int input = 0;
    while(1) {
        printf("%s", msg);
        if (!scanf("%d", &input)) {
            printf("Entrada invalida!\n");
            getchar();
            continue;
        }

        if (input < 1 || input > getBound(possiveis)) {
            printf("Numero invalido!\n");
            continue;
        }

        if(possiveis[input-1].modoGolpe != target) {
            printf("Esse golpe nao eh do tipo correto!\n");
        } else
            return input;
    }

    return -1;
}

void EscolheGolpe(Pokemon *escolhido) // ver parada do strcmp
{
    Golpes GolpesPossiveis[7];
    int numEscolhidoC, numEscolhidoR;

    printf("Golpes possíveis para %s:\n", escolhido->nome);
    MostraGolpes(escolhido, GolpesPossiveis);   

    numEscolhidoR = ValidaEntrada('R', "\nEscolha um Golpe rapido: ", GolpesPossiveis);
    if (numEscolhidoR == -1) 
        exit(1);
    printf("\nVocê escolheu o golpe: %s \n", GolpesPossiveis[numEscolhidoR-1].nomeGolpe);

    numEscolhidoC = ValidaEntrada('C', "\nEscolha um golpe carregado: ", GolpesPossiveis);
    if (numEscolhidoC == -1) 
        exit(1);
    printf("\nVocê escolheu o golpe: %s \n", GolpesPossiveis[numEscolhidoC-1].nomeGolpe);

    // printf();
    // scanf("%d",&numEscolhidoC);
    // printf("\nVocê escolheu o golpe: %s \n", GolpesPossiveis[numEscolhidoC-1].nomeGolpe);
    /*     . para acessar um campo de uma struct
          -> para acessar um campo de uma struct a partir de um ponteiro 
     */
    escolhido->fGolpe[0] = GolpesPossiveis[numEscolhidoR-1];
    escolhido->fGolpe[1] = GolpesPossiveis[numEscolhidoC-1];
}       

Golpes selecionaGolpe(Pokemon escolhido) // porque não está aparecendo os fGolpe
{
    Golpes aux;
    int golpeselecionado;
    printf("\nSelecione o golpe que vai usar:\n1 - %s\n2 - %s\n", escolhido.fGolpe[0].nomeGolpe, escolhido.fGolpe[1].nomeGolpe);
    scanf("%d", &golpeselecionado);
    aux.f_golpe = escolhido.fGolpe[golpeselecionado-1].f_golpe;
    return aux;
}

double matrizVant(Pokemon p1,Pokemon p2){
    double bonus;
    double matriz[19][19]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0.5,2,1,1,0.5,1,1,1,0.5,1,1,2,2,2,1,1,0.5,1},
                          {0,0.5,0.5,2,1,2,1,1,0.5,2,1,0.5,1,0.5,1,1,0.5,0.5,1},
                          {0,2,0.5,1,1,2,1,1,2,1,2,0.5,1,2,1,1,1,0,1},
                          {0,1,1,1,1,0.5,1,1,1,1,1,1,1,0.5,1,0,1,1,1},
                          {0,2,1,0.5,1,1,1,0.5,1,1,1,2,2,0.5,1,1,1,2,1},
                          {0,0.5,1,1,1,1,1,2,0.5,1,1,1,1,0.5,2,1,2,1,1},
                          {0,1,1,1,2,2,0.5,1,0.5,1,1,0.5,2,2,2,0,1,0.5,0.5},
                          {0,1,2,0.5,1,0.5,2,0.5,1,0.5,1,1,1,1,0,1,1,1,1},
                          {0,2,0.5,2,1,2,1,1,1,0.5,1,1,1,1,1,1,0.5,1,1},
                          {0,1,0.5,0,1,1,1,1,1,2,0.5,1,1,1,1,1,0.5,2,1},
                          {0,0.5,2,1,1,1,0.5,0.5,0.5,1,1,1,1,0.5,0.5,1,0.5,2},
                          {0,0.5,2,2,1,1,1,1,1,2,1,1,0.5,0.5,1,1,2,2,1},
                          {0,0.5,1,1,1,2,2,1,1,0.5,0.5,1,2,0.5,1,1,1,1,1},
                          {0,1,1,1,1,1,0.5,0.5,1,1,1,1,1,1,0.5,2,1,1,2},
                          {0,1,1,1,0,1,1,1,1,1,1,1,1,1,0.5,2,1,1,2},
                          {0,1,1,1,1,1,0,1,1,1,1,1,1,0.5,1,1,2,1,1},
                          {0,1,2,1,1,0.5,1,2,1,1,0.5,2,1,0.5,1,1,1,1,1},
                          {0,1,1,1,1,1,1,2,2,1,1,1,1,0.5,0,1,1,1,0.5}};
        bonus= matriz[*p1.fGolpe[0].t_golpe][*p2.tipo1] * matriz[*p1.fGolpe[0].t_golpe][*p2.tipo2];
        return bonus;
}

double alpha(Pokemon p1,Pokemon p2,int b){
  double dano;
  dano = matrizVant(p1,p2)*(1-(rand()%15/100));
  if( p1.tipo1 == p1.fGolpe[b].t_golpe || p1.tipo2 == p1.fGolpe[0].t_golpe){
    dano=matrizVant(p1,p2)*(1-(rand()%15/100))*1.5;
    }
    return dano;
}

void Battle(Pokemon p1[], Pokemon p2[]) // NAo terminado
{
    int i = 1, j = 1;
    int P1porradao, P2porradao;
    
    while (i <= 3 && j <= 3) 
    {        
        int bate = (p1[i].speed > p2[j].speed) ? 0 : 1;
        usleep(100000);
        
        while (p1[i].hp > 0 && p2[j].hp > 0) 
        {
            if (bate == 0) 
            { // P2[j] sofre dano
                p2[i].hp -= (((2 * p1[i].lvl / 5 + 2) * p1[i].fGolpe[0].f_golpe * (p1[i].ataque / p2[j].defesa)) / 50 + 2)*alpha(p1[i],p2[i],0);
                P1porradao += p1[i].fGolpe[0].g_energia;
                if(P1porradao == p1[i].fGolpe[1].g_energia) {
                    usleep(100000);
                    printf("%s usará o golpe carregado %s",p1[i].nome,p1[i].fGolpe->nomeGolpe);
                    p2[i].hp -= (((2 * p1[i].lvl / 5 + 2) * p2[i].fGolpe[1].f_golpe * (p1[i].ataque / p2[j].defesa)) / 50 + 2) * alpha(p1[i],p2[i],1);
                    P1porradao -= p1[i].fGolpe[1].g_energia;
                }
                bate = 1;
            } 
            else 
            { // P1[i] sofre dano
                p1[i].hp -= (((2 * p2[j].lvl / 5 + 2) * p2[i].fGolpe[0].f_golpe * (p2[j].ataque / p1[i].defesa)) / 50 + 2)*alpha(p2[i],p1[i],0);
                if(P2porradao == p2[i].fGolpe[1].g_energia)
                {
                    usleep(100000);
                    printf("%s usará o golpe carregado %s ",p2[i].nome,p2[i].fGolpe->nomeGolpe);
                    p1[i].hp -= (((2 * p2[j].lvl / 5 + 2) * p1[i].fGolpe[1].f_golpe * (p2[j].ataque / p1[i].defesa)) / 50 + 2)*alpha(p2[i],p1[i],1);
                    P2porradao -= p2[i].fGolpe[1].g_energia;
                }
                bate = 0;
            }
        }
            if (p1[i].hp > 0) { // p1[i] sobreviveu
                usleep(100000);
                printf("\nPokemon %s (Player %d) ganhou de %s com %.2f de hp restante\n", p1[i].nome, 1, p2[j].nome, p1[i].hp);
                j++;
            } 
            else { // p2[j] sobreviveu
                usleep(100000);
                printf("\nPokemon %s (Player %d) ganhou de %s com %.2f de hp restante\n", p2[j].nome, 2, p1[i].nome, p2[j].hp);
                i++;
            }
    }
    if((p1[1].hp+p1[2].hp+p1[3].hp)>0 )
        printf("\n\n\n\t\t\t\t\t\t\t\tPlayer 1 ganhou!\n\n\n\n");
    else
        printf("\n\n\n\t\t\t\t\t\t\t\tPlayer 2 ganhou!\n\n\n\n");     
}

int main () {
    printf("\e[H\e[2J"); // comando equivalente ao clear do terminal
    Pokemon P1[4],P2[4];
    int clima;
    TransfereDados();
    Read_Data();
    EscreveNomePokemon();
    LerGolpe();
    int i;
    
    printf("\n\n\n");
    printf("\t\t\t ----------------\n");
    printf("\t\t\t|                |\n");
    printf("\t\t\t|   Jogagor 1:   |\n");
    printf("\t\t\t|                |\n");
    printf("\t\t\t ----------------\n\n\n");
            for(i = 1 ; i <= 3 ; i++) {
                printf("\nEscolha o %dº pokémon: ", i);
                P1[i] = EscolhePokemon();
                EscolheGolpe(&P1[i]);
            }
    
    printf("\n\n\n");
    printf("\t\t\t ----------------\n");
    printf("\t\t\t|                |\n");
    printf("\t\t\t|   Jogagor 2:   |\n");
    printf("\t\t\t|                |\n");
    printf("\t\t\t ----------------\n\n\n");
    for(i = 1 ; i <= 3 ; i++) {
            printf("\nEscolha o %dº pokémon: ", i);
            P2[i] = EscolhePokemon();
            EscolheGolpe(&P2[i]);
    }
    
        clima = LerClima();
        
    for(i = 0 ; i < 3 ; i++) {
        BonusClima(clima, P1[i]);
        BonusClima(clima, P2[i]);
    }
    Battle(P1, P2);
    matrizVant(P1[1],P2[1]);
    
    return 0;
}
