
/*
Nomes:                                                        RAs:
Giuliano Marques Sanfins                                     17142837                          
Beatriz M. Lorente                                           18071597

Número máximo de cidades atendidas (time-out de 60 segundos): 32/42
Opcionais funcionando:1,5

Observações: Cidade Albuquerque removida pois estava demorando mais de 20 minutos para a execução.

Valor do Projeto:  _______ pontos



*/



#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "tipo.h"

using namespace std;


struct caminho
{
    int caminho[43]={0};
    int custo;
};
typedef struct caminho stack_element;
#include "stackld.h"

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
int matriz[43][43]= {0};
    char cidades[43][24] = {"0","seatle","portland","san francisco","los angeles",
                            "san diego", "boise",  "lake tahoe ", "las vegas", "palm springs", "yellowstone",
                            "salt lake city", "grand canyon", "phoenix",  "denver", "colorado springs",
                            "vail","aspen", "albuquerque", "minneapolis",  "omaha",  "kansas city",  "dallas",
                            "san antonio", "houston", "milwaukee", "chicago", "st louis", "little rock", "memphis",
                            "nova orleans", "detroit", "indianapolis", "nashville", "atlanta", "orlando", "fort lauderdale",
                            "miami",  "albany",  "boston", "nova york",  "washington",  "richmond"
                           };

       for(int i=1; i<43; i++)
    {
        matriz[0][i]=i;
        matriz[i][0]=i;
    }
matriz[2][1] =170;
    matriz[6][1] =500;

    matriz[1][2] =170;
    matriz[3][2] = 640;
    matriz[6][2] = 420;
    matriz[7][2] = 580;

    matriz[2][3] =640;
    matriz[4][3] =380;
    matriz[7][3] =300;

    matriz[3][4] =380;
    matriz[5][4] =120;
    matriz[8][4] =270;
    matriz[9][4] =160;

    matriz[4][5] =120;
    matriz[9][5] =140;
    matriz[13][5] =350;

    matriz[1][6] =500;
    matriz[2][6] =420;
    matriz[7][6] =420;
    matriz[10][6] =670;

    matriz[2][7] =580;
    matriz[3][7] =300;
    matriz[6][7] =420;
    matriz[9][7] =780;
    matriz[11][7] =520;

    matriz[4][8] =270;
    matriz[9][8] =290;
    matriz[11][8] =420;
    matriz[12][8] =470;

    matriz[4][9] =160;
    matriz[5][9] =140;
    matriz[7][9] =780;
    matriz[8][9] =290;
    matriz[12][9] =440;

    matriz[6][10] =670;
    matriz[14][10] =930;
    matriz[19][10] =1340;

    matriz[7][11] =520;
    matriz[8][11] =420;
    matriz[13][11] =660;
    matriz[14][11] =530;

    matriz[8][12] =470;
    matriz[9][12] =440;
    matriz[13][12] =360;

    matriz[5][13] =350;
    matriz[11][13] =660;
    matriz[12][13] =360;
    matriz[18][13] =550;
    matriz[22][13] =1070;
    matriz[23][13] =990;

    matriz[10][14] =930;
    matriz[11][14] =530;
    matriz[15][14] =120;
    matriz[16][14] =160;
    matriz[17][14] =170;
    matriz[20][14] =540;

    matriz[14][15] =120;
    matriz[17][15] =180;
    matriz[22][15] =730;

    matriz[14][16] =160;
    matriz[17][16] =80;

    matriz[14][17] =170;
    matriz[15][17] =180;
    matriz[16][17] =80;

    matriz[13][18] =350;

    matriz[10][19] =1340;
    matriz[20][19] =380;
    matriz[25][19] =340;
    matriz[26][19] =410;

    matriz[14][20] =540;
    matriz[19][20] =380;
    matriz[21][20] =190;
    matriz[26][20] =470;

    matriz[20][21] =190;
    matriz[22][21] =550;
    matriz[27][21] =250;

    matriz[13][22] =1070;
    matriz[15][22] =730;
    matriz[21][22] =550;
    matriz[23][22] =280;
    matriz[24][22] =250;
    matriz[28][22] =320;
    matriz[34][22] =790;

    matriz[13][23] =990;
    matriz[22][23] =280;
    matriz[24][23] =310;

    matriz[22][24] =250;
    matriz[23][24] =310;
    matriz[30][24] =530;

    matriz[19][25] =340;
    matriz[26][25] =90;

    matriz[19][26] =410;
    matriz[20][26] =470;
    matriz[25][26] =90;
    matriz[27][26] =300;
    matriz[31][26] =280;
    matriz[32][26] = 180;
    matriz[41][26] =700;

    matriz[21][27] =250;
    matriz[26][27] =300;
    matriz[28][27] =400;
    matriz[29][27] =290;
    matriz[32][27] =250;

    matriz[22][28] =320;
    matriz[27][28] =400;
    matriz[29][28] =140;

    matriz[27][29] = 290;
    matriz[28][29] =140;
    matriz[33][29] =210;
    matriz[34][29] =390;

    matriz[24][30] =530;
    matriz[34][30] =470;
    matriz[35][30] =640;
    matriz[37][30] =860;

    matriz[26][31] =280;
    matriz[38][31] =650;
    matriz[40][31] =640;
    matriz[41][31] =530;

    matriz[26][32] =180;
    matriz[27][32] =250;
    matriz[33][32] =290;
    matriz[41][32] =590;

    matriz[29][33] =210;
    matriz[32][33] =290;
    matriz[34][33] =240;
    matriz[42][33] =710;

    matriz[22][34] =790;
    matriz[29][34] =390;
    matriz[30][34] =470;
    matriz[33][34] =240;
    matriz[35][34] =440;
    matriz[42][34] =560;

    matriz[30][35] =640;
    matriz[34][35] =440;
    matriz[36][35] =180;
    matriz[37][35] =230;

    matriz[35][36] =180;
    matriz[37][36] =30;

    matriz[30][37] =860;
    matriz[35][37] =230;
    matriz[36][37] =30;

    matriz[31][38] =650;
    matriz[39][38] =170;
    matriz[40][38] =150;

    matriz[38][39] = 170;
    matriz[40][39] =210;

    matriz[31][40] =640;
    matriz[38][40] =150;
    matriz[39][40] =210;

    matriz[26][41] =700;
    matriz[31][41] =530;
    matriz[32][41] =590;
    matriz[40][41] =240;
    matriz[42][41] =200;

    matriz[33][42] =710;
    matriz[34][42] =560;
    matriz[41][42] =200;


    int custo_min=99999,i,j,k,g=0,flag=0,flagesc=0,escolha=0;
    int caminho_min[42]={0},caminho_res[42]={0};
    int entrada,saida,custo_res;
    int m=0;

    Stack p;
    initStack(p);
    stack_element x;

    int sockfd, newsockfd, portno,aux;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
    struct mensagem msg;

    //socket---------------------
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr,&clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");

    // bzero(msg,sizeof msg);
     n = read(newsockfd,(int*)&msg,sizeof msg);
     if (n < 0) error("ERROR reading from socket");
    //spcket -----------------------------

    entrada=msg.in;
     if(msg.escolha==2){
        saida=msg.in;
    }else if(msg.escolha==1){
        saida=msg.out;
    }
     
     printf("\n\n Espere um segundo.... \n");
     //entrada=aux;

     x.caminho[0]=entrada;
     x.custo=0;
     push(p,x);
    flag=0;
     clock_t tInicio, tFim,tDecorrido;
    tInicio = clock();
  while(!isEmpty(p))
     {
        m=0;
        x=pop(p);
        i=0;
        while(x.caminho[i]!=0)i++;

        /*if(x.caminho[i-1]==entrada&&i>35){ */
        if(escolha==1){
            if(x.caminho[i-1]==saida){
                if(x.custo<custo_min){
                    m=0;

                    custo_min=x.custo;
                    while(x.caminho[m]!=0){
                        caminho_min[m]=x.caminho[m];
                        m++;
                    }
                }
            }else flagesc =1;
        }else{
            if(x.caminho[i-1]==entrada&&i==42){ //if(x.caminho[i-1]==saida){
                if(x.custo<custo_min){
                    m=0;
                    custo_min=x.custo;
                    while(x.caminho[m]!=0){
                        caminho_min[m]=x.caminho[m];
                        m++;
                    }
                    break;
                }
            }else flagesc=1;
        }

         if(flagesc==1){
             j=1;
             while(x.caminho[i-1]!=matriz[j][0])j++;

             for(k=1;k<43;k++){

                 if(matriz[j][k]!=0){
                    custo_res=x.custo;
                    m=0;
                    g=0;

                    if(escolha==1){
                        while(x.caminho[g]!=0){
                                if(x.caminho[g]==matriz[0][k])flag =1;
                             g++;
                        }
                    }else{
                         if(matriz[0][k]==entrada&&i==41) flag=0;
                            else{
                                while(x.caminho[g]!=0){
                                        if(x.caminho[g]==matriz[0][k])flag =1;
                                     g++;
                                }
                             }

                    }

                    if(flag==0){
                     x.custo+=matriz[j][k];
                     x.caminho[i]=matriz[0][k];

                     if(custo_min>x.custo)
                     push(p,x);


                     x.custo=custo_res;
                     m=0;
                    }
                    flag=0;
                 }
             }
         }
        flagesc=0;
     }

/*
//----------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------
*/  

    i=1;

    msg.caminho_min[i-1]=caminho_min[0];
    printf("%s -> %s - (%d km)\n",cidades[caminho_min[0]],cidades[caminho_min[1]],matriz[caminho_min[0]][caminho_min[1]]);

    while(caminho_min[i]!=saida){
        msg.caminho_min[i]=caminho_min[i];
        printf("%s -> %s - (%d km)\n",cidades[caminho_min[i]],cidades[caminho_min[i+1]],matriz[caminho_min[i]][caminho_min[i+1]]);
        i++;
    }
    msg.caminho_min[i]=caminho_min[i];
    msg.custo_min=custo_min;
    printf("\n custo: %d i=%d\n",custo_min,i);

 tFim = clock();
     tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC/1000));
printf("\n Tempo:%d ms\n",tDecorrido);
    n = write(newsockfd,(int*)&msg,5000);
    if (n < 0) error("ERROR writing to socket");
    close(newsockfd);
    close(sockfd);


    return 0;
}