#include <stdio.h>
#include <math.h>
#include "batalhas.h"
typedef struct{
    float f_golpe;
    unsigned t_golpe[16];
    float g_energia;
    char nomeGolpe[210],modoGolpe[210];
}golpes; //struct criada para armazenar os dados dos golpes:  força, tipo, ganho de energia, nome do golpe e modo do Golpe (rápido ou carregado)
void golpes(pokemon p[]){
    FILE *golpes; // arquivo golpes
    char listaGolpe[50]; // vetor criado para receber o nome dos golpes
    golpes=fopen("ataques","r"); //recebe os dados do golpe
    if(golpes == NULL)){
    printf("Erro na abertura do arquivo\n");
  }
    for(int i=1; i<207;i++){ // ler os dados do arquivo
        fscanf(golpes,"%d %c %s %f %f",&golpes[i].t_golpe,&golpes[i].modoGolpe,&golpes[i].nomeGolpe,&golpes[i].f_golpe,&golpes[i].g_energia);
    }
        printf("Escolha um desses golpes: \n");
    for(int j=1; j<numPokemon;j++){ //loop para gravar os nomes dos golpes e dos seus tipos
        if(p[j].tipo1 == golpes[j].t_golpe){
            listaGolpe[j]=golpes[j].nomeGolpe;
            printf("%s",listaGolpe[j]);
        }
    }
}