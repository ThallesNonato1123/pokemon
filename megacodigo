#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>

#define num_Pokedex 151
#define num_Ataques 208
        

// Não sei se ainda vão ter uso essas variaveis
const int Normal = 0;
const int Fight = 1;
const int Flying = 2;
const int Poison = 3;
const int Ground = 4;
const int Rock = 5;
const int Bug = 6;
const int Ghost = 7;
const int Steel = 8;
const int Fire = 9;
const int Water = 10;
const int Grass = 11;
const int Eletric = 12;
const int Psychic = 13;
const int Ice = 14;
const int Dragon = 15;
const int Dark = 16;
const int Fairy = 17;



// valida atk carregado (GLOBAL)
int carregado;



// matriz de eficacia (GLOBAL) // NÃO SEI SE POSSO DECLARAR MATRIZ COM CONST
const float matriz[19][19] = {1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 2.0, 1.0, 0.5, 0.5, 1.0, 2.0, 0.5, 0.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 2.0, 1.0, 2.0, 0.5, 0.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.5, 0.5, 0.5, 1.0, 0.5, 0.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.0, 1.0, 1.0, 0.0, 2.0, 1.0, 2.0, 0.5, 1.0, 2.0, 2.0, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 2.0, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.5, 0.5, 0.5, 1.0, 1.0, 1.0, 0.5, 0.5, 0.5, 1.0, 2.0, 1.0, 2.0, 1.0, 1.0, 2.0, 0.5, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5, 0.5, 0.5, 1.0, 0.5, 1.0, 2.0, 1.0, 1.0, 2.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 2.0, 1.0, 2.0, 0.5, 0.5, 2.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 0.0, 1.0, 1.0, 0.5, 0.5, 2.0, 2.0, 0.5, 1.0, 0.5, 0.5, 2.0, 0.5, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 0.0, 1.0, 1.0, 2.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 0.5, 1.0, 1.0, 0.0, 1.0, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5, 0.5, 0.5, 2.0, 1.0, 1.0, 0.5, 2.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.0, 0.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5, 0.5, 0.0, 1.0, 2.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};



// Tipo Pokemon (GLOBAL)
typedef struct
{
        int num, num_atks[23];
        char nome[51], tipo1[10], tipo2[10] ;
        float stamina, ataque, defesa;
}Pokemon;

// Tipo Ataques (GLOBAL)
typedef struct
{
    char modo, golpe[23], tipo[15];
    float mp, g_energia;
}tAtaques;

// Tipo Treinador para Batalha (GLOBAL)
typedef struct
{
    Pokemon pok;
    tAtaques r, c;
    float nivel, velocidade, hp, energiaacumulada;
}TreinadorBatalha;



// Tipos de Pokemon com vantagem no clima escolhido
typedef struct
{
    char tipo[10];
}tClima;

Pokemon Pokedex[num_Pokedex];
tAtaques Ataques[num_Ataques];
TreinadorBatalha t1[3], t2[3];
tClima ClimaEscolhido[3];

int LeArquivos(void)
{
	FILE *stats, *golps, *atkpokemon; 

    //Le por arquivo todos os pokemons e seus atributos
    stats = fopen("pokemon.txt","r");
    
    if(stats == NULL)
    {
        printf("Erro na abertura do arquivo de Stats\n");
        return -1;
    }

	int i;
    for(i=0; i<num_Pokedex;i++)
    {
        fscanf(stats,"%d %s %f %f %f %s %s", &Pokedex[i].num, &Pokedex[i].nome, &Pokedex[i].stamina, &Pokedex[i].ataque, &Pokedex[i].defesa, &Pokedex[i].tipo1, &Pokedex[i].tipo2);
    }
    fclose(stats);
    
    //Le por arquivo todos os golpes e seus atributos
    golps = fopen("ataques.txt","r");

    if(golps == NULL)
    {
        printf("Erro na abertura do arquivo de Ataques\n");
        return -1;
    }

    for(i=0; i<num_Ataques;i++)
    {
        fscanf(golps,"%s %c", &Ataques[i].tipo, &Ataques[i].modo);
        fgets(Ataques[i].golpe, 23, golps);
        fscanf(golps, "%f %f", &Ataques[i].mp, &Ataques[i].g_energia);
    }
    fclose(golps);
    
    // Possiveis atks para cada pokemon
    atkpokemon = fopen("ataques_cada_pokemon.txt", "r");
    if(atkpokemon == NULL)
    {
        printf("Erro na abertura do arquivo de Ataques de cada Pokemon");
        return -1;
    }

    atkpokemon = fopen("ataques_cada_pokemon.txt","r");
    
    if(atkpokemon == NULL)
    {
        printf("Erro na abertura do arquivo de ataques de cada pokemon\n");
        return -1;
    }
    
    for(i=0;i<150;i++)
	{    
        fscanf(atkpokemon,"%i %i %i %i %i %i %i", &Pokedex[i].num_atks[0],&Pokedex[i].num_atks[1],&Pokedex[i].num_atks[2],&Pokedex[i].num_atks[3],&Pokedex[i].num_atks[4],&Pokedex[i].num_atks[5],&Pokedex[i].num_atks[6]);
	}
    //fscanf(atkpokemon, "%i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i", &Pokedex[151].num_atks[0],&Pokedex[151].num_atks[1],&Pokedex[151].num_atks[2],&Pokedex[151].num_atks[3],&Pokedex[151].num_atks[4],&Pokedex[151].num_atks[5],&Pokedex[151].num_atks[6], &Pokedex[151].num_atks[7],&Pokedex[151].num_atks[8],&Pokedex[151].num_atks[9],&Pokedex[151].num_atks[10],&Pokedex[151].num_atks[11],&Pokedex[151].num_atks[12],&Pokedex[151].num_atks[13], &Pokedex[151].num_atks[14],&Pokedex[151].num_atks[15],&Pokedex[151].num_atks[16],&Pokedex[151].num_atks[17],&Pokedex[151].num_atks[18],&Pokedex[151].num_atks[19],&Pokedex[151].num_atks[20], &Pokedex[151].num_atks[21],&Pokedex[151].num_atks[22],&Pokedex[151].num_atks[23],&Pokedex[151].num_atks[24],&Pokedex[151].num_atks[25],&Pokedex[151].num_atks[26],&Pokedex[151].num_atks[27], &Pokedex[151].num_atks[28],&Pokedex[151].num_atks[29],&Pokedex[151].num_atks[30],&Pokedex[151].num_atks[31],&Pokedex[151].num_atks[32], &Pokedex[151].num_atks[33],&Pokedex[151].num_atks[34],&Pokedex[151].num_atks[35],&Pokedex[151].num_atks[36],&Pokedex[151].num_atks[37],&Pokedex[151].num_atks[38]);
	fclose(atkpokemon);
	
	return 1;
}

void EscreveLinha(void)
{
	int i;
	printf("\n");
	for(i = 0; i < 235; i++)
		printf("*");
	printf("\n");
}

void ListagemPokemon(void)
{
	EscreveLinha();
	int i;
	printf("\n\t\t\t\t\t\t\t\t   Listagem dos pokemons:\n\n");
	
	for(i = 0; i < 151; i++)
	{
		printf("%d. %s\t\t", i+1, Pokedex[i].nome);
		if(i == 88)			// <---- funciona, n questione
			printf("\t");
			
		if(((i+1)%10) == 0)
			printf("\n\n");
	}
			printf("\n\n");
}

// Escolhe Clima da batalha
void EscolheClima(tClima escolhido[], int aleatorio) // sera aleatorio se aleatorio = 1
{
	if(!aleatorio)
		EscreveLinha();
	
	int clima;
    if(!aleatorio)
    {
	    
	    printf("                                                 --------------------------------------------------------------\n");
	    printf("                                                |                  Escolha o clima da sua batalha:             |\n");
	    printf("                                                |                                                              |\n");
	    printf("                                                |                      1 --- Clear/Sunny                       |\n");
	    printf("                                                |                                                              |\n");
	    printf("                                                |                      2 --- Partly Cloudly                    |\n");
	    printf("                                                |                                                              |\n");
	    printf("                                                |                      3 --- Cloudy                            |\n");
	    printf("                                                |                                                              |\n");
	    printf("                                                |                      4 --- Rain                              |\n");
	    printf("                                                |                                                              |\n");
	    printf("                                                |                      5 --- Snow                              |\n");
	    printf("                                                |                                                              |\n");
	    printf("                                                |                      6 --- Fog                               |\n");
	    printf("                                                |                                                              |\n");
	    printf("                                                |                      7 --- Windy                             |\n");
	    printf("                                                |                                                              |\n");
	    printf("                                                 --------------------------------------------------------------\n");
	
	    scanf("%d", &clima);
	}
	
	if(aleatorio)
		clima = 1 + rand() % 7;
	
    if (clima == 1)
    {
        strcpy(escolhido[0].tipo, "Fire");
        strcpy(escolhido[1].tipo, "Grass");
        strcpy(escolhido[3].tipo, "Ground");
        
		if(!aleatorio)
			printf("\t\t\t\t\t\t\t\t   O clima escolhido foi Clear/Sunny\n");
    }
    else if(clima == 2)
    {
        strcpy(escolhido[0].tipo, "Normal");
        strcpy(escolhido[1].tipo, "Rock");
        strcpy(escolhido[3].tipo, "Nada");
        
		if(!aleatorio)
			printf("\t\t\t\t\t\t\t\t   O clima escolhido foi Partly Cloudly\n");
    }
    else if(clima == 3)
    {
        strcpy(escolhido[0].tipo, "Fairy");
        strcpy(escolhido[1].tipo, "Fighting");
        strcpy(escolhido[3].tipo, "Poison");
        
        if(!aleatorio)
			printf("\t\t\t\t\t\t\t\t   O clima escolhido foi Cloudy\n");
    }
    else if(clima == 4)
    {
        strcpy(escolhido[0].tipo, "Water");
        strcpy(escolhido[1].tipo, "Eletric");
        strcpy(escolhido[3].tipo, "Bug");
        
        if(!aleatorio)
			printf("\t\t\t\t\t\t\t\t   O clima escolhido foi Rain\n");
    }
    else if(clima == 5)
    {
        strcpy(escolhido[0].tipo, "Ice");
        strcpy(escolhido[1].tipo, "Steel");
        strcpy(escolhido[3].tipo, "Nada");
        
        if(!aleatorio)
			printf("\t\t\t\t\t\t\t\t   O clima escolhido foi Snow\n");
    }
    else if(clima == 6)
    {
        strcpy(escolhido[0].tipo, "Dark");
        strcpy(escolhido[1].tipo, "Ghost");
        strcpy(escolhido[3].tipo, "Nada");
        
        if(!aleatorio)
			printf("\t\t\t\t\t\t\t\t   O clima escolhido foi Fog\n");
    }
    else if(clima == 7)
    {
        strcpy(escolhido[0].tipo, "Dragon");
        strcpy(escolhido[1].tipo, "Flying");
        strcpy(escolhido[3].tipo, "Psychic");
        
        if(!aleatorio)
			printf("\t\t\t\t\t\t\t\t   O clima escolhido foi Windly\n");
    }
    
}



// Calcula a eficacia do ataque para a funcao CalculaGamma   // baseado nos tipos de p1 e p2 
float CalculaTe(TreinadorBatalha p1, TreinadorBatalha p2)
{
    float Te;
    int a,b,c;

    if (strcmp(p1.pok.tipo1, "Normal") == 0) a=0;
    else if (strcmp(p1.pok.tipo1, "Fighting") == 0) a=1;
    else if (strcmp(p1.pok.tipo1, "Flying") == 0) a=2;
    else if (strcmp(p1.pok.tipo1, "Poison") == 0) a=3;
    else if (strcmp(p1.pok.tipo1, "Ground") == 0) a=4;
    else if (strcmp(p1.pok.tipo1, "Rock") == 0) a=5;
    else if (strcmp(p1.pok.tipo1, "Bug") == 0) a=6;
    else if (strcmp(p1.pok.tipo1, "Ghost") == 0) a=7;
    else if (strcmp(p1.pok.tipo1, "Steel") == 0) a=8;
    else if (strcmp(p1.pok.tipo1, "Fire") == 0) a=9;
    else if (strcmp(p1.pok.tipo1, "Water") == 0) a=10;
    else if (strcmp(p1.pok.tipo1, "Grass") == 0) a=11;
    else if (strcmp(p1.pok.tipo1, "Eletric") == 0) a=12;
    else if (strcmp(p1.pok.tipo1, "Psychic") == 0) a=13;
    else if (strcmp(p1.pok.tipo1, "Ice") == 0) a=14;
    else if (strcmp(p1.pok.tipo1, "Dragon") == 0) a=15;
    else if (strcmp(p1.pok.tipo1, "Dark") == 0) a=16;
    else if (strcmp(p1.pok.tipo1, "Fairy") == 0) a=17;
    
    if (strcmp(p2.pok.tipo1, "Normal") == 0) b=0;
    else if (strcmp(p2.pok.tipo1, "Fighting") == 0) b=1;
    else if (strcmp(p2.pok.tipo1, "Flying") == 0) b=2;
    else if (strcmp(p2.pok.tipo1, "Poison") == 0) b=3;
    else if (strcmp(p2.pok.tipo1, "Ground") == 0) b=4;
    else if (strcmp(p2.pok.tipo1, "Rock") == 0) b=5;
    else if (strcmp(p2.pok.tipo1, "Bug") == 0) b=6;
    else if (strcmp(p2.pok.tipo1, "Ghost") == 0) b=7;
    else if (strcmp(p2.pok.tipo1, "Steel") == 0) b=8;
    else if (strcmp(p2.pok.tipo1, "Fire") == 0) b=9;
    else if (strcmp(p2.pok.tipo1, "Water") == 0) b=10;
    else if (strcmp(p2.pok.tipo1, "Grass") == 0) b=11;
    else if (strcmp(p2.pok.tipo1, "Eletric") == 0) b=12;
    else if (strcmp(p2.pok.tipo1, "Psychic") == 0) b=13;
    else if (strcmp(p2.pok.tipo1, "Ice") == 0) b=14;
    else if (strcmp(p2.pok.tipo1, "Dragon") == 0) b=15;
    else if (strcmp(p2.pok.tipo1, "Dark") == 0) b=16;
    else if (strcmp(p2.pok.tipo1, "Fairy") == 0) b=17;
    
    //a1 e b1
    Te = matriz[a][b];
    
    //guarda o b1
    c = b;

    if (strcmp(p2.pok.tipo2, "Normal") == 0) b=0;
    else if (strcmp(p2.pok.tipo2, "Fighting") == 0) b=1;
    else if (strcmp(p2.pok.tipo2, "Flying") == 0) b=2;
    else if (strcmp(p2.pok.tipo2, "Poison") == 0) b=3;
    else if (strcmp(p2.pok.tipo2, "Ground") == 0) b=4;
    else if (strcmp(p2.pok.tipo2, "Rock") == 0) b=5;
    else if (strcmp(p2.pok.tipo2, "Bug") == 0) b=6;
    else if (strcmp(p2.pok.tipo2, "Ghost") == 0) b=7;
    else if (strcmp(p2.pok.tipo2, "Steel") == 0) b=8;
    else if (strcmp(p2.pok.tipo2, "Fire") == 0) b=9;
    else if (strcmp(p2.pok.tipo2, "Water") == 0) b=10;
    else if (strcmp(p2.pok.tipo2, "Grass") == 0) b=11;
    else if (strcmp(p2.pok.tipo2, "Eletric") == 0) b=12;
    else if (strcmp(p2.pok.tipo2, "Psychic") == 0) b=13;
    else if (strcmp(p2.pok.tipo2, "Ice") == 0) b=14;
    else if (strcmp(p2.pok.tipo2, "Dragon") == 0) b=15;
    else if (strcmp(p2.pok.tipo2, "Dark") == 0) b=16;
    else if (strcmp(p2.pok.tipo2, "Fairy") == 0) b=17;
    else b = 18;

    //a1 e b2
    Te += matriz[a][b];

    if (strcmp(p1.pok.tipo2, "Normal") == 0) a=0;
    else if (strcmp(p1.pok.tipo2, "Fighting") == 0) a=1;
    else if (strcmp(p1.pok.tipo2, "Flying") == 0) a=2;
    else if (strcmp(p1.pok.tipo2, "Poison") == 0) a=3;
    else if (strcmp(p1.pok.tipo2, "Ground") == 0) a=4;
    else if (strcmp(p1.pok.tipo2, "Rock") == 0) a=5;
    else if (strcmp(p1.pok.tipo2, "Bug") == 0) a=6;
    else if (strcmp(p1.pok.tipo2, "Ghost") == 0) a=7;
    else if (strcmp(p1.pok.tipo2, "Steel") == 0) a=8;
    else if (strcmp(p1.pok.tipo2, "Fire") == 0) a=9;
    else if (strcmp(p1.pok.tipo2, "Water") == 0) a=10;
    else if (strcmp(p1.pok.tipo2, "Grass") == 0) a=11;
    else if (strcmp(p1.pok.tipo2, "Eletric") == 0) a=12;
    else if (strcmp(p1.pok.tipo2, "Psychic") == 0) a=13;
    else if (strcmp(p1.pok.tipo2, "Ice") == 0) a=14;
    else if (strcmp(p1.pok.tipo2, "Dragon") == 0) a=15;
    else if (strcmp(p1.pok.tipo2, "Dark") == 0) a=16;
    else if (strcmp(p1.pok.tipo2, "Fairy") == 0) a=17;
    else a = 18;

    //a2 b1
    Te+= matriz[a][c];
    
    //a2 b2
    Te+= matriz[a][b];
    
    return Te;
}



// Calcula o bonus de clima para a funcao CalculaGamma   // Pokemon com vantagem climatica --> BONUS
float BonusClima(TreinadorBatalha p1)   // CHECAR NOVAMENTE
{
    int i;
	tClima ClimaEscolhido[3]; // PRECISO MSM DECLARAR?
    for(i = 0; i<3; i++)
    {
        if(strcmp(p1.pok.tipo1, ClimaEscolhido[i].tipo)== 0)
            return 1.3;
        else if(strcmp(p1.pok.tipo2, ClimaEscolhido[i].tipo)==0)
            return 1.3;
    }
    return 1;
}



// Calcula Alpha para a funcao CalculaGamma     // Aleatório
float CalculaAlpha()
{
    float a;
    a = ((100-(rand() % 15))/100);
    return a;
}



// Calcula Gamma para a funcao CalculaDano  // p1 ataca  // p2 defende
float CalculaGamma(TreinadorBatalha p1, TreinadorBatalha p2)
{
    //clima = Bonus de clima //alpha = fator aleatório pode penalizar 15% //STAB = bonus chega a 50% se (tipo atk = tipo pokemon) //Te = eficacia do atk
        
    if (carregado == 0)
    {
        // Se o Tipo1 ou Tipo2 do pokemon atacante for igual ao tipo do atk rapido --> BONUS
	    if (strcmp(p1.pok.tipo1, p1.r.tipo) == 0 || strcmp(p1.pok.tipo2, p1.r.tipo) == 0)
	        return (BonusClima(p1) * CalculaAlpha() * 1.5 * CalculaTe(p1, p2));

        // Sem Bonus para o dano do atk rapido
	    else 
	      return (BonusClima(p1) * CalculaAlpha() * CalculaTe(p1, p2));
    }
    else if (carregado == 1)
	{
        // Se o Tipo1 ou Tipo2 do pokemon atacante for igual ao tipo do atk carregado --> BONUS
	    if (strcmp(p1.pok.tipo1, p1.c.tipo)==0 || strcmp(p1.pok.tipo2, p1.c.tipo)==0)
	      return (BonusClima(p1) * CalculaAlpha() * 1.5 * CalculaTe(p1, p2));

        // Sem Bonus para o dano do atk carregado
	    else 
	        return (BonusClima(p1) * CalculaAlpha() * CalculaTe(p1, p2));
	}
}



// Calcula o Dano dos atks rapidos e carregados //p1 ataca //p2 defende
float CalculaDano(TreinadorBatalha p1, TreinadorBatalha p2)
{
    float dano;   
    
    if (p1.energiaacumulada>= p1.c.g_energia)
    {
	// carregado = 1 para ataque carregado 
	    carregado = 1;	// VALIDA O ATK CARREGADO
        dano = (((((((2*p1.nivel)/5)+2)*p1.c.mp*p1.pok.ataque/p2.pok.defesa)/50)+2)*CalculaGamma(p1, p2));
        p1.energiaacumulada-= p1.c.g_energia;
    }
    else
    {
	// carregado = 0 para ataque rapido
	    carregado = 0; 
        dano = (((((((2*p1.nivel)/5)+2)*p1.r.mp*p1.pok.ataque/p2.pok.defesa)/50)+2)*CalculaGamma(p1, p2));
    }
    return dano;
}



// Inicializa os valores de HP de cada pokemon escolhido de um treinador
void CalculaHp(TreinadorBatalha p1[])
{
 	int i;
    for (i=0; i<3; i++)
    {
        p1[i].hp = (((p1[i].pok.stamina *2 *p1[i].nivel)/100)+ p1[i].nivel +10);  
    }
}



// Calcula o Acumulo de Energia para atks rapidos e pokemon defensor //p1 ataca //p2 defende
void EnergiaAcumulada(TreinadorBatalha p1, TreinadorBatalha p2)
{
    p2.energiaacumulada += (CalculaDano(p1, p2))/2;
    if (carregado == 0)
        p1.energiaacumulada += p1.r.g_energia;
    else 
        carregado = 0;
}




// associada a selecaoPokedex; FINALIZADA, mas não da pra escolher o Mew ainda // Dratini tb n, n sei pq
tAtaques EscolheAtk(TreinadorBatalha t1, int n)
{
    int num, i = 0, rapido = 0, atkRapido, carregado = 0, atkCarregado;

	if(n)
	{
		printf("\n\t\t\t\t\t\t\t Escolha o ataque rapido e carregado de %s: \n", t1.pok.nome);
		
		while(t1.pok.num_atks[i] != 208 && i < 7)
		{
			num = t1.pok.num_atks[i];
			//printf("debug(numero do golpe): %d\n", num);
			printf("%d.\tGolpe: %s \n\tTipo: %s \n\tModo: %c \n\tMP: %f\n\tGanho de Energia: %f\n\n", i+1, Ataques[num].golpe /*tem q ler 23 caracteres contando com o \n*/, Ataques[num].tipo, Ataques[num].modo, Ataques[num].mp, Ataques[num].g_energia);
			i++;
		}
		
		while(1)
		{	
			printf("Rapido: ");
			scanf("%d", &rapido);
			if(rapido < 1 || rapido > 7)
			{
				printf("gasta n namoral\n");
				continue;
			}
			atkRapido = t1.pok.num_atks[rapido-1];
			t1.r.modo = Ataques[atkRapido].modo;
			if (t1.r.modo != 'R')
			{
				printf("tem q escolher rapido oooo animal\n");
				continue;
			}
			t1.r.g_energia = Ataques[atkRapido].g_energia;
			strcpy(t1.r.golpe, Ataques[atkRapido].golpe);
			strcpy(t1.r.tipo, Ataques[atkRapido].tipo);
			t1.r.mp = Ataques[atkRapido].mp;
			//printf("debug (\tGolpe: %s \n\tTipo: %s \n\tModo: %c \n\tMP: %f\n\tGanho de Energia: %f)\n\n", t1.r.golpe, t1.r.tipo, t1.r.modo, t1.r.mp, t1.r.g_energia);
			return t1.r;
			}
	}
	
	while(1)
	{	
		printf("Carregado: ");
		scanf("%d", &carregado);
		if(carregado < 1 || carregado > 7)
		{
			printf("gasta n namoral\n");
			continue;
		}
		atkCarregado = t1.pok.num_atks[carregado-1];
		t1.c.modo = Ataques[atkCarregado].modo;
		if (t1.c.modo != 'C')
		{
			printf("tem q escolher carregado oooo animal\n");
			continue;
		}		
		t1.c.g_energia = Ataques[atkCarregado].g_energia;
		strcpy(t1.c.golpe, Ataques[atkCarregado].golpe);
		strcpy(t1.c.tipo, Ataques[atkCarregado].tipo);
		t1.c.mp = Ataques[atkCarregado].mp;
		//printf("debug (\tGolpe: %s \n\tTipo: %s \n\tModo: %c \n\tMP: %f\n\tGanho de Energia: %f)\n\n", t1.c.golpe, t1.c.tipo, t1.c.modo, t1.c.mp, t1.c.g_energia);
		return t1.c;
	}
}

float SelecaoNivel(int aleatorio, int i) // sera aleatorio para aleatorio = 1; i é a variável de loop para dizer o numero do pokemon
{	
	if(!aleatorio)
	{	
		float nivel;
		while(1)
		{
			printf("\nNivel do pokemon %d: ", i+1);
			scanf("%f", &nivel);
			
			if(nivel < 0 || nivel > 40)
			{
				printf("O nivel deve estar entre 0 e 40!\n");
				continue;
			}
			
			//if(ceilf(nivel/0.5) == nivel/0.5)  // <---- isso aqui foi de fudekkk
				return nivel;
							
			//else
			//	printf("O nivel deve ser multiplo de 0.5!\n");		
		}
	}
	
	else if(aleatorio)
	{
		int zerovirgula5 = rand() % 2; // para criar niveis com 0.5, ja que rand() só retorna int
		float nivel = rand() % 41;
	
		if(zerovirgula5 && nivel != 0)              // como zerovirgula5 é modulo 2, isso se tornara if(0) ou if(1) dependendo da paridade de rand();
			nivel = nivel - 0.5; 
			
		return nivel;
	}
}

TreinadorBatalha selecaoPokedex(int i) // TA DANDO MERDA NO 147 (Dratini) e 148 (Dragonair)
{	
	TreinadorBatalha escolhido;
	int n;
	float nivel;
	int aleatorio = 0;			// o processo é manual	
	int rapido = 1, carregado = 0;
		
	while (1)
	{
		printf("\nNumero do pokemon %d: ", i+1);
		scanf("%d", &n);
	
        if (n < 1 || n > num_Pokedex)
        {
		    printf("O número deve estar entre 0 e 151.");
		    continue;
	    }
		
        n = n - 1;
            
        escolhido.pok.ataque = Pokedex[n].ataque;
        escolhido.pok.defesa = Pokedex[n].defesa;
        escolhido.pok.stamina = Pokedex[n].stamina;
        strcpy(escolhido.pok.nome, Pokedex[n].nome);
        escolhido.pok.num = Pokedex[n].num;
        escolhido.pok.num_atks[0] = Pokedex[n].num_atks[0];
        escolhido.pok.num_atks[1] = Pokedex[n].num_atks[1];
        escolhido.pok.num_atks[2] = Pokedex[n].num_atks[2];
        escolhido.pok.num_atks[3] = Pokedex[n].num_atks[3];
        escolhido.pok.num_atks[4] = Pokedex[n].num_atks[4];
        escolhido.pok.num_atks[5] = Pokedex[n].num_atks[5];
        escolhido.pok.num_atks[6] = Pokedex[n].num_atks[6];
        
        break;
	}
	
	escolhido.nivel = SelecaoNivel(aleatorio, 0);	//segundo argumento não será utilizado
	escolhido.r = EscolheAtk(escolhido, rapido); 
	escolhido.c = EscolheAtk(escolhido, carregado); 
	
    return escolhido;
}

tAtaques AtkAleatorio(TreinadorBatalha t1, int n)
{	
	int aleatorioR, aleatorioC, atkRapido, atkCarregado;
	
	if(n)
		while(1)
		{
			aleatorioR = rand() % 3;
			
			atkRapido = t1.pok.num_atks[aleatorioR];
						
			t1.r.modo = Ataques[atkRapido].modo;			
			if (t1.r.modo != 'R')
				continue;
			
			//printf("DEBUG: %c\n", t1.r.modo);
			t1.r.g_energia = Ataques[atkRapido].g_energia;
			strcpy(t1.r.golpe, Ataques[atkRapido].golpe);
			strcpy(t1.r.tipo, Ataques[atkRapido].tipo);
			t1.r.mp = Ataques[atkRapido].mp;
			//printf("debug (\tGolpe: %s \n\tTipo: %s \n\tModo: %c \n\tMP: %f\n\tGanho de Energia: %f)\n\n", t1.r.golpe, t1.r.tipo, t1.r.modo, t1.r.mp, t1.r.g_energia);
			return t1.r;
		}
	else
	{
		while(1)
		{
			aleatorioC = 2 + rand() % 7;
			
			atkCarregado = t1.pok.num_atks[aleatorioC];
			
			t1.c.modo = Ataques[atkCarregado].modo;
			if (t1.c.modo != 'C')
				continue;
				
			t1.c.g_energia = Ataques[atkCarregado].g_energia;
			strcpy(t1.c.golpe, Ataques[atkCarregado].golpe);
			strcpy(t1.c.tipo, Ataques[atkCarregado].tipo);
			t1.c.mp = Ataques[atkCarregado].mp;
			//printf("debug (\tGolpe: %s \n\tTipo: %s \n\tModo: %c \n\tMP: %f\n\tGanho de Energia: %f)\n\n", t1.c.golpe, t1.c.tipo, t1.c.modo, t1.c.mp, t1.c.g_energia);
			return t1.c;
		}
	}
}

TreinadorBatalha selecaoAleatoria(int n)
{	
	TreinadorBatalha escolhido;
	int aleatorio = 1;
	
	escolhido.nivel = SelecaoNivel(aleatorio, 0); //segundo argumento não será utilizado
	
	escolhido.pok.ataque = Pokedex[n].ataque;
    escolhido.pok.defesa = Pokedex[n].defesa;
    escolhido.pok.stamina = Pokedex[n].stamina;
    strcpy(escolhido.pok.nome, Pokedex[n].nome);
    escolhido.pok.num = Pokedex[n].num;
    escolhido.pok.num_atks[0] = Pokedex[n].num_atks[0];
    escolhido.pok.num_atks[1] = Pokedex[n].num_atks[1];
    escolhido.pok.num_atks[2] = Pokedex[n].num_atks[2];
    escolhido.pok.num_atks[3] = Pokedex[n].num_atks[3];
    escolhido.pok.num_atks[4] = Pokedex[n].num_atks[4];
    escolhido.pok.num_atks[5] = Pokedex[n].num_atks[5];
    escolhido.pok.num_atks[6] = Pokedex[n].num_atks[6];
    
    escolhido.r = AtkAleatorio(escolhido, 1);
    escolhido.c = AtkAleatorio(escolhido, 0);
    
    printf("%s de nivel %.1f\n", escolhido.pok.nome, escolhido.nivel);
    
    return escolhido;
}

void ExibeTreinador(TreinadorBatalha t1)
{
	printf("%s de nivel %.1f\n", t1.pok.nome, t1.nivel);
	printf("Ataque rapido:   %s\n", t1.r.golpe);
    printf("Ataque carregado:%s\n\n", t1.c.golpe);
}

int menu(void)
{	
	EscreveLinha();
	
	printf("\nO que deseja fazer?\n\n");
    printf("1  - Seguir roteiro padrao de batalha\n");
    printf("2  - Gerar batalha aleatoria\n");
    printf("3  - Exibir listagem de pokemons\n");
    printf("4  - Escolher clima da batalha\n");
    printf("5  - Escolher os 3 pokemons do Jogador 1 manualmente\n");
    printf("6  - Escolher os 3 pokemons do Jogador 1 aleatoriamente\n");
    printf("7  - Escolher os 3 pokemons do Jogador 2 manualmente\n");
    printf("8  - Escolher os 3 pokemons do Jogador 2 aleatoriamente\n");
    printf("9  - Vizualizar pokemons e golpes selecionados do Jogador 1\n");
    printf("10 - Vizualizar pokemons e golpes selecionados do Jogador 2\n");
    printf("11 - Redefinir os niveis dos pokemons\n");
    printf("12 - Iniciar batalha!\n");
	printf("13 - Sair do jogo\n\n");
    
    int menu, i;
    static int menuControle1 = 0, menuControle2 = 0, menuClima = 0;
    
    while(1)
    {
		scanf("%d", &menu);
    
    	switch(menu)
    	{
    		case 1:
    			return menu;
			case 2:
				return menu;
			case 3:
				ListagemPokemon();
				break;
			case 4:
				EscolheClima(ClimaEscolhido, 0);
				menuClima = 1;
				break;
			case 5:
				EscreveLinha();
				
				printf("\nEscolha os 3 pokemons de Jogador 1:\n");
				for(i = 0; i < 3; i++)
				{
					t1[i] = selecaoPokedex(i);
					EscreveLinha();
				}
				
				printf("\nPokemons selecionados com sucesso!\n");
				menuControle1 = 1;
				break;
			case 6:
				EscreveLinha();
				printf("\nPokemons selecionados:\n");
				for(i = 0; i < 3; i++)
					t1[i] = selecaoAleatoria(rand() % 151);
				menuControle1 = 1;
				break;
			case 7:
				EscreveLinha();
				printf("\nEscolha os 3 pokemons de Jogador 2:\n");
				for(i = 0; i < 3; i++)
				{
					t2[i] = selecaoPokedex(i);
					EscreveLinha();
				}
				printf("\nPokemons selecionados com sucesso!\n");
				menuControle2 = 1;
				break;
			case 8:
				EscreveLinha();
				printf("\nPokemons selecionados:\n");
				for(i = 0; i < 3; i++)
					t2[i] = selecaoAleatoria(rand() % 151);
				menuControle2 = 1;
				break;
			case 9:
				if(menuControle1)
				{	
					EscreveLinha();
					
					printf("\n\nPokemons e golpes selecionados:\n\n");
					for(i = 0; i < 3; i++)
						ExibeTreinador(t1[i]);
				}
				else
				{
					printf("Nao ha pokemons para mostrar.\n");
					return -1;
				}
				break;
			case 10:
				if(menuControle2)
				{
					EscreveLinha();
					
					printf("\n\nPokemons e golpes selecionados:\n\n");
					for(i = 0; i < 3; i++)
						ExibeTreinador(t2[i]);
				}
				else
				{
					printf("Nao ha pokemons para mostrar.\n");
					return -1;
				}
				break;
			case 11:
				EscreveLinha();
				
				printf("Selecione os niveis dos pokemons do Jogador 1:\n");
				for(i = 0; i < 3; i++)
					t1[i].nivel = SelecaoNivel(0, i);
				
				EscreveLinha();
				
				printf("Selecione os niveis dos pokemons do Jogador 2:\n");
				for(i = 0; i < 3; i++)
					t2[i].nivel = SelecaoNivel(0, i);
					
				printf("\n\nNiveis definidos com sucesso!\n");
				break;
			case 12:
				if(!menuControle1 || !menuControle2)
				{
					printf("Nao ha pokemons suficientes para iniciar a batalha!\n");
					break;
				}
				else if(!menuClima)
					printf("Clima nao selecionado!\n");
				else
					//batalhaPokemon();
				break;
			case 13:
				exit(1);
			default:
				printf("O numero deve estar entre 1 e 13.\n\n");
				break;
		}
		
		if(menu > 0 && menu < 14)
			break;
	}	
}

int main()
{    
    srand(time(NULL));
	
	int statusArquivos = LeArquivos();
	
	if (statusArquivos == -1)
		return -1;
	
	int retornoMenu, i;
	
	while(1)
	{
		retornoMenu = menu();
	
		if (retornoMenu == 1 || retornoMenu == 2) // 1 - roteiro padrao; 2 - batalha aleatoria
			break;   
			
		if (retornoMenu == 13) // 12 - sair do jogo
			exit(1);
    }
    
    retornoMenu = retornoMenu - 1; // será 0 se o roteiro padrao de batalha for escolhido; 1 se batalha aleatoria
    
    if(!retornoMenu)
    {
    	ListagemPokemon();
    	
    	EscreveLinha();
    	printf("\nEscolha os 3 pokemons de Jogador 1:\n");
    	for(i = 0; i < 3; i++)
    	{
			t1[i] = selecaoPokedex(i);
    		EscreveLinha();
    	}
    	
    	printf("\nEscolha os 3 pokemons de Jogador 2:\n");
    	
		for(i = 0; i < 3; i++)
		{
			t2[i] = selecaoPokedex(i);
			EscreveLinha();
		}
		
		EscolheClima(ClimaEscolhido, 0);
		
		//BatalhaPokemon(t1, t2);	
	}
	
	else if(retornoMenu)
	{
		printf("\nPokemons de Jogador 1:\n\n");
		for(i = 0; i < 3; i++)
    		t1[i] = selecaoAleatoria(rand() % 151);
    		
    	printf("\nPokemons de Jogador 2:\n\n");	
    	for(i = 0; i < 3; i++)
    		t2[i] = selecaoAleatoria(rand() % 151);
    		
    	EscolheClima(ClimaEscolhido, 1);
    	printf("\n\nClima escolhido: %s", ClimaEscolhido); // coe mega essa EscolheClima ta errada né
    	//BatalhaPokemon(t1, t2);
	}

	while(1)
		printf("marceneiro ");

    return 0;
}


