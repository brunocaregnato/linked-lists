/*Venicius
, Bruno   CODE BLOCK 16.01
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#define TAM 512

struct filme{
  struct filme *ant;
  char nome_filme[TAM];
  char ano[10];
  struct refAtor *lista_ator;
  struct diretores *lista_dir;
  struct filme *prox;
};

struct atores
{
    struct atores *ant;
    char nome_ator[TAM];
    struct refFilme *move;
    struct atores *prox;
};

struct diretores
{
    struct diretores *ant;
    char nome_diretor[TAM];
    struct refFilme *move;
    struct diretores *prox;
};

struct personagem
{
    struct personagem *ant;
    char nome_personagem[TAM];
    struct refFilme *move;
    struct refAtor *lista_ator;
    struct personagem *prox;
};

typedef struct refAtor{
	struct atores *at;
	struct refAtor *prox;
	struct refAtor *ant;
}refAtor;

typedef struct refDiretor{
	struct diretores *dir;
	struct refDiretor *prox;
	struct refDiretor *ant;
}refDiretor;

typedef struct refFilme{
	struct filme *fil;
	struct refFilme *prox;
	struct refFilme *ant;
}refFilme;

void removeBarraN(char string[]){

    int i;
    while(string[i]!='\0' && string[i]!='\n'){
        i++;
    }
    string[i]='\0';
}


void insere_Filme ( struct filme ** inicio , struct filme ** fim , char val[] , char year[] ,struct filme **par_memoria)
{

    struct filme * ptaux =( struct filme *) malloc ( sizeof ( struct filme ));

        strcpy(ptaux->nome_filme,val);
        strcpy(ptaux->ano,year);
        *par_memoria = ptaux;
        ptaux->lista_ator=NULL;
        ptaux->lista_dir=NULL;

        if (* inicio == NULL || strcmp((* inicio )->nome_filme,val)>0 )
        {
        ptaux -> prox =* inicio ;
        ptaux -> ant = NULL ;
        if (* inicio != NULL ) (* inicio )-> ant = ptaux ;
        else * fim = ptaux ;
        * inicio = ptaux ;
        return ;
}
    struct filme * ptaux2 =* inicio ;
        while ( ptaux2 -> prox != NULL && strcmp(ptaux2 ->prox ->nome_filme,val)<0 ) ptaux2 = ptaux2 -> prox ;
        ptaux -> prox =ptaux2 -> prox ;
        ptaux -> ant = ptaux2 ;
        ptaux2 -> prox = ptaux ;
        if (ptaux -> prox == NULL ) // inserção no final da lista
        (* fim )= ptaux ;
        else
        ptaux ->prox -> ant = ptaux ;
        return ;
}

void insere_Atores(struct atores ** inicio , struct atores ** fim , char val[] ,struct filme **par_memoria, struct atores **at)
{
    int comparacao=0;
    struct atores *next = *inicio;

    refFilme *nodo=(struct refFilme *) malloc(sizeof(refFilme));

    nodo->fil=*par_memoria;
    while(next!=NULL)
    {
        comparacao=strcmp(next->nome_ator,val);

                if(comparacao== 0)
		{
			if(next->move==NULL)
			{
				next->move=nodo;
				nodo->prox=NULL;
			}
			else
			{
				refFilme * aux4=next->move;
				while((aux4->prox)!=NULL)
				{
					aux4=aux4->prox;
				}
				aux4->prox=nodo;
				nodo->prox=NULL;
			}
			*at=next;
			return;
            }
       next=next->prox;
    }

    struct atores * ptaux =( struct atores *) malloc ( sizeof ( struct atores ));

        strcpy(ptaux->nome_ator,val);
        ptaux->move=NULL;

        if(ptaux->move==NULL)
            {
                ptaux->move=nodo;
                nodo->prox=NULL;
            }
            else
                {
                    refFilme * aux3 = ptaux->move;
                    while((aux3->prox)!=NULL)
		            {
		         	aux3=aux3->prox;
		            }
                    aux3->prox=nodo;
                    nodo->prox=NULL;
                }
            *at=ptaux;

        if (* inicio == NULL || strcmp((* inicio )->nome_ator,val)>0 )
        {
        ptaux -> prox =* inicio ;
        ptaux -> ant = NULL ;
        if (* inicio != NULL ) (* inicio )-> ant = ptaux ;
        else * fim = ptaux ;
        * inicio = ptaux ;
        return ;
}
    struct atores * ptaux2 =* inicio ;
        while ( ptaux2 -> prox != NULL && strcmp(ptaux2 ->prox ->nome_ator,val)<0 ) ptaux2 = ptaux2 -> prox ;
        ptaux -> prox =ptaux2 -> prox ;
        ptaux -> ant = ptaux2 ;
        ptaux2 -> prox = ptaux ;
        if (ptaux -> prox == NULL ) // inserção no final da lista
        (* fim )= ptaux ;
        else
        ptaux ->prox -> ant = ptaux ;
        return ;
}


void insereRefAtores(struct filme **paramet,struct atores **at)
{

    struct filme *novo=*paramet;

    refAtor *nodo=(struct refAtor *) malloc(sizeof(struct refAtor));


		if(novo->lista_ator==NULL)
		{

			novo->lista_ator=nodo;
			nodo->at=*at;
			nodo->prox=NULL;

		}
		else
		{
			refAtor *aux3=novo->lista_ator;
			while((aux3->prox)!=NULL)
			{
				aux3=aux3->prox;
			}

			aux3->prox=nodo;
			nodo->at=*at;
			nodo->prox=NULL;

		}
}

void insereDiretores(struct diretores ** inicio , struct diretores ** fim , char val[] ,struct filme **par_memoria, struct diretores **at){

    int comparacao=0;
    struct diretores *next = *inicio;

    refFilme *nodo=(struct refFilme *) malloc(sizeof(refFilme));

    nodo->fil=*par_memoria;
    while(next!=NULL)
    {
        comparacao=strcmp(next->nome_diretor,val);

                if(comparacao== 0)
		{
			if(next->move==NULL)
			{
				next->move=nodo;
				nodo->prox=NULL;
			}
			else
			{
				refFilme * aux4=next->move;
				while((aux4->prox)!=NULL)
				{
					aux4=aux4->prox;
				}
				aux4->prox=nodo;
				nodo->prox=NULL;
			}
			*at=next;
			return;
            }
       next=next->prox;
    }

    struct diretores * ptaux =( struct diretores *) malloc ( sizeof ( struct diretores ));

        strcpy(ptaux->nome_diretor,val);
        ptaux->move=NULL;

        if(ptaux->move==NULL)
            {
                ptaux->move=nodo;
                nodo->prox=NULL;
            }
            else
                {
                    refFilme * aux3 = ptaux->move;
                    while((aux3->prox)!=NULL)
		            {
		         	aux3=aux3->prox;
		            }
                    aux3->prox=nodo;
                    nodo->prox=NULL;
                }
            *at=ptaux;

        if (* inicio == NULL || strcmp((* inicio )->nome_diretor,val)>0 )
        {
        ptaux -> prox =* inicio ;
        ptaux -> ant = NULL ;
        if (* inicio != NULL ) (* inicio )-> ant = ptaux ;
        else * fim = ptaux ;
        * inicio = ptaux ;
        return ;
}
    struct diretores * ptaux2 =* inicio ;
        while ( ptaux2 -> prox != NULL && strcmp(ptaux2 ->prox ->nome_diretor,val)<0 ) ptaux2 = ptaux2 -> prox ;
        ptaux -> prox =ptaux2 -> prox ;
        ptaux -> ant = ptaux2 ;
        ptaux2 -> prox = ptaux ;
        if (ptaux -> prox == NULL ) // inserção no final da lista
        (* fim )= ptaux ;
        else
        ptaux ->prox -> ant = ptaux ;
        return ;

}

void insereRefDiretores(struct filme **paramet,struct diretores **at){


    struct filme *novo=*paramet;

    refDiretor *nodo=(struct refDiretor *) malloc(sizeof(struct refDiretor));


		if(novo->lista_dir==NULL)
		{

			novo->lista_dir=nodo;
			nodo->dir=*at;
			nodo->prox=NULL;

		}
		else
		{
			refDiretor *aux3=novo->lista_dir;
			while((aux3->prox)!=NULL)
			{
				aux3=aux3->prox;
			}

			aux3->prox=nodo;
			nodo->dir=*at;
			nodo->prox=NULL;

		}

}

//========================================================================================================================PERSONAGEM
void insereRefAtorPersonagem(struct personagem **paramet,struct atores **at)
{

    struct personagem *novo=*paramet;

    refAtor *nodo=(struct refAtor *) malloc(sizeof(struct refAtor));


		if(novo->lista_ator==NULL)
		{

			novo->lista_ator=nodo;
			nodo->at=*at;
			nodo->prox=NULL;

		}
		else
		{
			refAtor *aux3=novo->lista_ator;
			while((aux3->prox)!=NULL)
			{
				aux3=aux3->prox;
			}

			aux3->prox=nodo;
			nodo->at=*at;
			nodo->prox=NULL;

		}
}

void insere_Personagem(struct personagem ** inicio , struct personagem ** fim , char val[] ,struct filme **par_memoria, struct atores **at)
{
    int comparacao=0;
    struct personagem *next = *inicio;

    refFilme *nodo=(struct refFilme *) malloc(sizeof(refFilme));

    nodo->fil=*par_memoria;
    while(next!=NULL)
    {
        comparacao=strcmp(next->nome_personagem,val);

                if(comparacao== 0)
		{
			if(next->move==NULL)
			{
				next->move=nodo;
				nodo->prox=NULL;
			}
			else
			{
				refFilme * aux4=next->move;
				while((aux4->prox)!=NULL)
				{
					aux4=aux4->prox;
				}
				aux4->prox=nodo;
				nodo->prox=NULL;
			}
			insereRefAtorPersonagem(&next,&(*at));
			//*at=next;
			return;
            }
       next=next->prox;
    }

    struct personagem * ptaux =( struct personagem *) malloc ( sizeof ( struct personagem ));

        strcpy(ptaux->nome_personagem,val);
        ptaux->move=NULL;

        if(ptaux->move==NULL)
            {
                ptaux->move=nodo;
                nodo->prox=NULL;
            }
            else
                {
                    refFilme * aux3 = ptaux->move;
                    while((aux3->prox)!=NULL)
		            {
		         	aux3=aux3->prox;
		            }
                    aux3->prox=nodo;
                    nodo->prox=NULL;
                }
				insereRefAtorPersonagem(&ptaux,&(*at));
            //*at=ptaux;

        if (* inicio == NULL || strcmp((* inicio )->nome_personagem,val)>0 )
        {
        ptaux -> prox =* inicio ;
        ptaux -> ant = NULL ;
        if (* inicio != NULL ) (* inicio )-> ant = ptaux ;
        else * fim = ptaux ;
        * inicio = ptaux ;
        return ;
}
    struct personagem * ptaux2 =* inicio ;
        while ( ptaux2 -> prox != NULL && strcmp(ptaux2 ->prox ->nome_personagem,val)<0 ) ptaux2 = ptaux2 -> prox ;
        ptaux -> prox =ptaux2 -> prox ;
        ptaux -> ant = ptaux2 ;
        ptaux2 -> prox = ptaux ;
        if (ptaux -> prox == NULL ) // inserção no final da lista
        (* fim )= ptaux ;
        else
        ptaux ->prox -> ant = ptaux ;
        return ;
}




//========================================================================================================================PERSONAGEM

void  escreveFilme(struct filme *inicio, struct filme *fim, int valor){

	if(!valor){ // Alfabetica normal
	struct filme *primeiro = inicio;
		if(primeiro == NULL){
		printf("Lista Vazia\n");
		}
		else{
			while(primeiro != NULL){
			printf("FILME: %s  -  %s \n",primeiro->nome_filme,primeiro->ano);
			primeiro=primeiro->prox;
			}
		}

	}
	else{ //Alfabetica reversa
		struct filme *primeiro = fim;
		if(primeiro == NULL){
		printf("Lista Vazia\n");
		}
		else{
			while(primeiro != NULL){
			printf("FILME: %s  -  %s \n",primeiro->nome_filme,primeiro->ano);
			primeiro=primeiro->ant;
			}
		}
	}
}

void escreveAtores(struct atores *inicio,struct atores *fim, int valor)
{

  if(!valor){ // Alfabetica normal
      struct atores *primeiro = inicio;

      if(primeiro == NULL){
         printf("Lista Vazia\n");
      }
      else{
         while(primeiro != NULL){
                        printf("ATORES: %s \n",primeiro->nome_ator);
                        primeiro=primeiro->prox;
            }
        }
    }

    else{ //Alfabetica reversa
      struct atores *primeiro = fim;

      if(primeiro == NULL){
         printf("Lista Vazia\n");
      }
      else{
         while(primeiro != NULL){
                        printf("ATORES: %s \n",primeiro->nome_ator);
                        primeiro=primeiro->ant;
            }
        }
    }
}


int verificaDiretor(char string[]){
    char dir[5]="dir:";
    int i;

    for(i=0;i<4;i++){
        if(string[i] != dir[i]) return 0;
    }

    return 1;
}

int verificaAno(char string[])
{
    char ano[2]="1";
    char ano_b[2]="2";

    if(string[0]==ano[0] || string[0]==ano_b[0]) return 0;

    return 1;

}

int verificaString(char string[])
{
    char s[2]=",";
    int cont=0;
    char v[2]="|";
    int next=0;


    while(next==0)
        {
            if(string[cont]==s[0] && string[cont+1]==s[0] && string[cont+2]==s[0]) return 0; //nao tem ano nem diretor
            if(string[cont]==s[0] && string[cont+1]==s[0]) return 2; //nao tem ano mas tem diretor
            if(string[cont]==v[0]) next=1;
            cont++;
        }
    return 1; //tem tudo certinho
}

int existeFilme(struct filme *inicio, char string[]){

    while(inicio != NULL){
        if(strcmp(inicio->nome_filme,string) == 0) return 1;
        inicio = inicio->prox;
    }

    return 0;
}

int existeAtor(struct atores *inicio,char nomeator[]){

    while(inicio != NULL){
        if(strcmp(inicio->nome_ator,nomeator) == 0 ){
            return 1;
        }
        inicio = inicio->prox;
    }
    return 0;
}

int existeDiretor(struct diretores *inicio, char nomediretor[]){

    while(inicio != NULL){
        if(strcmp(inicio->nome_diretor,nomediretor) == 0 ){
            return 1;
        }
        inicio = inicio->prox;
    }
    return 0;
}

void remove_f(struct filme **inicio, struct filme **fim, char filme[],struct filme **memoria){

    struct filme *ptaux;

     if(strcmp((*inicio)->nome_filme,filme) == 0){
        (*inicio)->prox->ant=NULL;
        *inicio = (*inicio)->prox;
        ptaux = *inicio;
    }
    else if(strcmp((*fim)->nome_filme,filme) == 0 ){
        (*fim)->ant->prox=NULL;
        *fim = (*fim)->ant;
        ptaux = *fim;
    }
    else{
        ptaux = *memoria;
        ptaux->prox->ant = ptaux->ant;
        ptaux->ant->prox = ptaux->prox;

    }
}


void listaFilmesDeUmAtor(struct atores *inicio, char nomeator[]){
struct refFilme *ant;
struct refFilme *atual;
struct atores *aux = inicio;
struct filme *aux_filme;
int trocou = 0;
while(aux!=NULL){
    if(strcmp(aux->nome_ator,nomeator)==0)
        {
            struct refFilme *prim = aux->move;
    while(trocou==1){
					trocou=0;
					ant=prim->fil; //Primeiro nodo
					atual=ant->prox;//Segundo nodo
					while(atual != NULL){
						if(strcmp(ant->fil->ano,atual->fil->ano) > 0){
							aux_filme = ant->fil;
							ant->fil = atual->fil;
							atual->fil = (aux_filme);
							trocou=1;
						}
						ant=atual;
						atual=atual->prox;
					}
				}

				 //Printa os filmes após a ordenação
			    printf("\nFilmes em ordem cronologica do ator/atriz %s:\n\n", aux->nome_ator);
                struct refFilme *p = aux->move;
			    while(p != NULL)
			    {
			    	printf("%s (%s)\n", p->fil->nome_filme, p->fil->ano);
			    	p = p->prox;
				}
				return;
        }

aux=aux->prox;
}
}

void listaFilmesDeUmDiretor(struct diretores *inicio, char nomediretor[]){
struct refFilme *ant;
struct refFilme *atual;
struct diretores *aux = inicio;
struct filme *aux_filme;
int trocou = 0;
while(aux!=NULL){
    if(strcmp(aux->nome_diretor,nomediretor)==0)
        {
            struct refFilme *prim = aux->move;
    while(trocou==1){
					trocou=0;
					ant=prim->fil; //Primeiro nodo
					atual=ant->prox;//Segundo nodo
					while(atual != NULL){
						if(strcmp(ant->fil->ano,atual->fil->ano) > 0){
							aux_filme = ant->fil;
							ant->fil = atual->fil;
							atual->fil = (aux_filme);
							trocou=1;
						}
						ant=atual;
						atual=atual->prox;
					}
				}

				 //Printa os filmes após a ordenação
			    printf("\nFilmes em ordem cronologica do diretor/diretora %s:\n\n", aux->nome_diretor);
                struct refFilme *p = aux->move;
			    while(p != NULL)
			    {
			    	printf("%s (%s)\n", p->fil->nome_filme, p->fil->ano);
			    	p = p->prox;
				}
				return;
        }

aux=aux->prox;
}
}


void escreve(struct filme **prim)
{
  struct filme *primeiro = *prim;
  if(primeiro == NULL){
     printf("Lista Vazia\n");
  }
  else{
     while(primeiro != NULL){
                    printf("FILME: %s  -  %s \n",primeiro->nome_filme,primeiro->ano);

                    struct refDiretor *pri = primeiro->lista_dir;
                    while(pri!=NULL)
                        {
                            printf("DIRETOR: %s  \n",pri->dir->nome_diretor);
                            pri=pri->prox;
                        }
                    primeiro=primeiro->prox;
     }
   }
}

void escreve_atores(struct atores **prim)
{
  struct atores *primeiro = *prim;
  if(primeiro == NULL){
     printf("Lista Vazia\n");
  }
  else{
     while(primeiro != NULL){
                    printf("ATORES: %s \n",primeiro->nome_ator);

      struct refFilme *pri = primeiro->move;
      while(pri!=NULL)
                        {
                            printf("filme que atua: %s  \n",pri->fil->nome_filme);
                            pri=pri->prox;
                        }
                    primeiro=primeiro->prox;
     }
   }
}


void removeFilme(struct filme ** inicio,struct filme ** fim, char nome[], struct ator ** ini,struct ator ** fin)
{
   struct filme *pega = (*inicio), *ant = NULL, *aux2;
	refAtor *atorAux = NULL, *aux;
	refFilme *filmeAux = NULL;
	int comparacao;

	if((*inicio) == NULL)
	{
		printf("Filme não encontrado\n");
		return;
	}
	//localiza o filme
	while(pega != NULL)
	{
		comparacao = strcmp(nome, pega->nome_filme);
		if(comparacao == 0) //se achou entra
		{
			atorAux = pega->lista_ator;
			while(atorAux != NULL)    //vai percorrer a referencia de atores
		  {
		   filmeAux = atorAux->at->move;
		   while(filmeAux != NULL)
				{
			    if(filmeAux->fil == pega)
			    {
				  if(pega == atorAux->at->move->fil)
				  {
					if(filmeAux->prox == NULL)  //caso seja o único filme da lista
					 {
					 if(atorAux->at == *ini)
					  {
						//compara se para achar o único da lista geral
					 if(atorAux->at == *fin)
						{
						*ini = NULL;
						*fin = NULL;
						free(atorAux->at);
						}
					   else{
							atorAux->at->prox->ant = NULL;
						    *ini = atorAux->at->prox;
							free(atorAux->at);
							}
								}
								else if(atorAux->at == *fin)
								{
									atorAux->at->ant->prox = NULL;
									*fin = atorAux->at->ant;
									free(atorAux->at);
								}
								else
								{
									atorAux->at->ant->prox = atorAux->at->prox;
									atorAux->at->prox->ant = atorAux->at->ant;
									free(atorAux->at);
								}
							}
							else//se for o primeiro filme
							{
								filmeAux->prox->ant = NULL;
								atorAux->at->move = filmeAux->prox;
							}
						}
						else
						{
							filmeAux->ant->prox = filmeAux->prox;
							if(filmeAux->prox != NULL)
							{
								filmeAux->prox->ant = filmeAux->ant;
							}
						}
					}
					filmeAux = filmeAux->prox;
				}
				atorAux = atorAux->prox;
			}//TERMINA A REMOÇÃO DOS FILMES DE TODOS OS ATORES


			remove_f(&(*inicio),&(*fim),nome,&pega);
		}
		pega = pega->prox;
	}

	return;
}

void listaFilmesDuplicado(struct filme *inicio, struct filme *fim){

    int tem=0,inicioFinal=0,peloMenosUm=0;


    printf("\nFILMES DUPLICADOS: \n");
    if(inicio == NULL){
        printf("Lista vazia.\n");
    }
    else if(inicio == fim){
        printf("\nNao existem filmes duplicados.");
        inicioFinal=1;
    }
    else{
        struct filme *ptaux = inicio->prox;

        while(inicio != NULL){
            while(ptaux != NULL){
                if(strcmp(inicio->nome_filme,ptaux->nome_filme) == 0 && strcmp(inicio->ano,ptaux->ano) == 0){
                    tem += 1;
                }
                if(strcmp(inicio->nome_filme,ptaux->nome_filme) == 0 && strcmp(inicio->ano,ptaux->ano) == 0 && tem==2){
                    printf("\nFILME: %s -- ANO: %s",inicio->nome_filme,inicio->ano);
                    peloMenosUm=1;
                }
                ptaux=ptaux->prox;
            }
            inicio=inicio->prox;
            ptaux=inicio;
            tem=0;
        }
    }

    if(!inicioFinal && !peloMenosUm) printf("\nNao existem filmes duplicados.");

    printf("\n");
}

void listaAtorTrabalhoAtor(struct atores *inicio, char v[])
{
    while(inicio!=NULL)
        {
            if(strcmp(inicio->nome_ator,v)==0)
            {
                struct refFilme *aux = inicio->move;

                while (aux!=NULL)
                    {

                        struct refAtor *prim = aux->fil->lista_ator;

                        while(prim!=NULL)
                            {
                                if(strcmp(prim->at->nome_ator,v)!=0)
                                    {
                                      printf("Ator(a): %s -- Filme: %s\n",prim->at->nome_ator,aux->fil->nome_filme);
                                    }
                                prim=prim->prox;
                            }
                            printf("\n");

                aux=aux->prox;
                    }
            }
            inicio = inicio->prox;
        }
}

void listaDiretorTrabalhoAtor(struct diretores *inicio, char v[])
{
    int achou=0;

    while(inicio!=NULL)
        {
            if(strcmp(inicio->nome_diretor,v)==0)
            {
                achou=1;
                struct refFilme *aux = inicio->move;

                while (aux!=NULL)
                    {

                        struct refAtor *prim = aux->fil->lista_ator;

                        while(prim!=NULL)
                            {
                                printf("Ator(a): %s -- Filme: %s\n",prim->at->nome_ator,aux->fil->nome_filme);

                                prim=prim->prox;
                            }
                            printf("\n");

                aux=aux->prox;
                    }
            }
            inicio = inicio->prox;
        }

        if(!achou) printf("Diretor não cadastrado.\n");
}

int temPersonagem(char x[])
{
    int cont=1;
    char s[2] = "=";
    //printf("%s",x);
    while(cont<strlen(x))
        {
            if(x[cont] == s[0])
                {
                   // printf("%s",x);
                    return 1;
                }
            cont++;
        }
        return 0;
}

void listaAtorPersonagem(struct atores *inicio, char nomeator[] )
{
    char *toke;
    int existe = 0;
    char s[2]="=";
    int cont;

    while(inicio!=NULL)
        {
         existe = temPersonagem(inicio->nome_ator);
         if(existe==1)
            {
               // printf("%s\n",inicio->nome_ator);
                cont =0;
                toke = strtok(inicio->nome_ator, s);

                    while( toke != NULL )
                    {
                      if(cont==1)
                        {
                            if(strcmp(toke,nomeator)==0)
                                {
                                    printf("Ator: %s -- Filme: %s (%s)\n",inicio->nome_ator,inicio->move->fil->nome_filme,inicio->move->fil->ano);

                                }
                        }
                       toke = strtok(NULL, s);
                       cont++;
                     }
            }

         inicio=inicio->prox;
        }
}

void imprimePersonagem(struct personagem *inicio, char v[])
{
     while(inicio!=NULL)
        {
            if(strcmp(inicio->nome_personagem,v)==0)
            {
                struct refFilme *aux = inicio->move;

                while (aux!=NULL)
                    {
                    printf("Filme: %s\n",aux->fil->nome_filme);

                aux=aux->prox;
                    }


             struct refAtor *prim = inicio->lista_ator;

                        while(prim!=NULL)
                            {
                                if(strcmp(prim->at->nome_ator,v)!=0)
                                    {
                                      printf("Ator(a): %s \n",prim->at->nome_ator);
                                    }
                                prim=prim->prox;
                            }}
            inicio = inicio->prox;
        }
}


//---------------------------------------------------------------------------------------------------------TERMINA FUNCOES

void menu()
{
    printf("1 - Listar atores\n");
    printf("2 - Listar filmes de um ator em ordem cronologica\n");
    printf("3 - Listar filmes\n");
    printf("4 - Inserir filme\n");
    printf("5 - Remover filme\n");
    printf("6 - Listar filmes de um diretor em ordem cronologica\n");
    printf("7 - Listar atores que trabalharam com um determinado ator, com o filme\n");
    printf("8 - Listar atores que trabalharam com um determianado diretor, com o filme\n");
    printf("9 - Listar todos os filmes duplicados\n");
    printf("A - Listar atores que interpretaram determinado personagem, com filme e ano\n");
    printf("0 - Fechar programa\n");
}

int main(){

    setlocale(LC_ALL,"Portuguese"); // seta tudo em portugues, dai nao ocorre mais os erros com caracter especial

    fflush(stdin);

    printf("Programa desenvolvido pelos alunos: Bruno e Venicius\n\n");

    int valor,verifica;
    char resp;
    struct filme *inicio = NULL;
    struct filme *fim = NULL;
    struct filme *par_memoria = NULL;

    struct atores *inicio_a = NULL;
    struct atores *fim_a = NULL;
    struct atores *at = NULL;

    struct diretores *dir = NULL;
    struct diretores *inicio_d = NULL;
    struct diretores *fim_d = NULL;

    struct personagem *inicio_p = NULL;
    struct personagem *fim_p = NULL;

    char nomefilme[TAM],nomeator[TAM],nomediretor[TAM],ano[5];


//---------------------------------------------------------------------------------------------------------------------------------
    char local[TAM];
    FILE *arquivo;


    printf("Digite o local do seu arquivo colocando \\\\ a cada pasta: ");
    gets(local);
    //strcpy(local,"C:\\temp\\resumo.txt");
    arquivo = fopen(local,"rt");
    REFAZ: if(arquivo == NULL){
            printf("\nArquivo nao encontrado, por favor, insira um caminho valido: ");
            gets(local);
            arquivo = fopen(local,"rt");
            goto REFAZ;
    }
    else if(arquivo != NULL){
    printf("\nArquivo encontrado, comecando a leitura dos dados...\n");
    char var[1000];
    char concatena[1000];
    int cont=0, existeDuasVirgula=0;
    char s[] = ",";
    char z[2]= "=";
    char *token;
    char *tok;
    char *temp_token;
    int cont_p=0;
    char filmes[TAM],  dirXator[TAM] ,ano_filme[10], atores_i[TAM], anoXdir[TAM];

                 while(fgets(var,1000,arquivo)!=NULL)
                 {
                   // printf("teste %s \n",var);

                    strcpy(concatena,var);
                     token = strtok(var, s);
                     cont=0;

                       while( token != NULL )
                        {
                             if(cont==0)
                                {

                                   strcpy(filmes,token);
                                  // printf("FILME        %s\n",token);
                                   strupr(filmes);
                                     switch(filmes[0]){
                                        case ' ':
                                        case 'Á':
                                        case 'À': filmes[0] = 'A';
                                              break;
                                        case 'Ô':
                                        case 'Ó': filmes[0] = 'O';
                                              break;
                                        case 'Ú': filmes[0] = 'U';
                                              break;
                                        case 'Ê':
                                        case 'É': filmes[0] = 'E';
                                              break;
                                        case 'Í': filmes[0] = 'I';
                                              break;

                                }
                            }
                            if(cont==1)
                                {

                   existeDuasVirgula=verificaString(strcat(concatena,"|"));

                   /* Quando existeDuasVirgulas == 0, tem que inserir com ano e diretor "N EXIS";
                      Quando existeDuasVirgulas == 1, tem que inserir com ano "N EXIS";
                      Quando existeDuasVirgulas == 2, tem que inserir com diretor "N EXIS";
                      Quando existeDuasVirgulas == 3, insere normal pois tem todos os campos
                   */

                   if(existeDuasVirgula==0)
                    {
                        insere_Filme(&inicio,&fim,filmes,"N EXIS",&par_memoria);


                        //printf("ATORES       %s\n",token);
                        strcpy(atores_i,token);
                        strupr(atores_i);
                        removeBarraN(atores_i);

                            if(temPersonagem(atores_i)==1){
                                                  cont_p=0;
                                              tok = strtok(atores_i, z);

                                               while( tok != NULL )
                                              {
                                                  if(cont_p==0){
                        insere_Atores(&inicio_a,&fim_a,atores_i,&par_memoria,&at);
                        insereRefAtores(&par_memoria,&at);}

                                                  if(cont_p==1){
                                               // printf( " %s\n", tok );
                                                insere_Personagem(&inicio_p,&fim_p,tok,&par_memoria,&at);
                                                  }

                                                tok = strtok(NULL, z);
                                                cont_p++;
                                               }

                                              }else{  insere_Atores(&inicio_a,&fim_a,atores_i,&par_memoria,&at);
                        insereRefAtores(&par_memoria,&at);}


                        insereDiretores(&inicio_d,&fim_d,"NAO TEM",&par_memoria,&dir);
                        insereRefDiretores(&par_memoria,&dir);


                    }
                     else if(existeDuasVirgula==1 || existeDuasVirgula==2)
                            {
                                    strcpy(anoXdir,token);

                                    if(verificaAno(anoXdir))
                                        {
                                           if(existeDuasVirgula==1)
                                                {
                                                 // printf("ATORES      %s\n",anoXdir);

                                                insere_Filme(&inicio,&fim,filmes,"N EXIS",&par_memoria);
                                                strcpy(atores_i,token);
                                                strupr(atores_i);
                                                removeBarraN(atores_i);

                                                 if(temPersonagem(atores_i)==1){
                                                   cont_p=0;
                                              tok = strtok(atores_i, z);

                                               while( tok != NULL )
                                              {
                                                if(cont_p==0){
                                                insere_Atores(&inicio_a,&fim_a,atores_i,&par_memoria,&at);
                                                insereRefAtores(&par_memoria,&at);}


                                                  if(cont_p==1){
                                               // printf( " %s\n", tok );
                                                insere_Personagem(&inicio_p,&fim_p,tok,&par_memoria,&at);
                                                  }

                                                tok = strtok(NULL, z);
                                                cont_p++;
                                               }

                                              }else{insere_Atores(&inicio_a,&fim_a,atores_i,&par_memoria,&at);
                                                insereRefAtores(&par_memoria,&at);}
                                                }
                                                else{
                                                    insere_Filme(&inicio,&fim,filmes,"N EXIS",&par_memoria);
                                                    insereDiretores(&inicio_d,&fim_d,anoXdir,&par_memoria,&dir);
                                                    insereRefDiretores(&par_memoria,&dir);
                                                     // printf("DIRETOR      %s\n",anoXdir);
                                                    }
                                        }
                                    else{
                                        strcpy(ano_filme,anoXdir);
                                       // printf("ANO      %s\n",anoXdir);
                                        insere_Filme(&inicio,&fim,filmes,ano_filme,&par_memoria);
                                       /* insereDiretores(&inicio_d,&fim_d,"NAO TEM",&par_memoria,&dir);
                                        insereRefDiretores(&par_memoria,&dir);*/

                                        }
                                }
                        }

                            if(cont==2)
                                    {
                                        if(existeDuasVirgula==1)
                                            {
                                       //          printf("DIRETOR      %s\n",token);
                                                 insereDiretores(&inicio_d,&fim_d,token,&par_memoria,&dir);
                                                 insereRefDiretores(&par_memoria,&dir);

                                            }
                                        else
                                            {
                                         //       printf("ATORES      %s\n",token);
                                                strcpy(atores_i,token);
                                                strupr(atores_i);
                                                removeBarraN(atores_i);

                                                 if(temPersonagem(atores_i)==1){
                                                   cont_p=0;
                                              tok = strtok(atores_i, z);

                                               while( tok != NULL )
                                              {
                                               if(cont_p==0){
                                                insere_Atores(&inicio_a,&fim_a,atores_i,&par_memoria,&at);
                                                insereRefAtores(&par_memoria,&at);}


                                                  if(cont_p==1){
                                              //  printf( " %s\n", tok );
                                                insere_Personagem(&inicio_p,&fim_p,tok,&par_memoria,&at);
                                                  }

                                                tok = strtok(NULL, z);
                                                cont_p++;
                                               }

                                              }else{insere_Atores(&inicio_a,&fim_a,atores_i,&par_memoria,&at);
                                                insereRefAtores(&par_memoria,&at);}
                                            }

                                    }

                            if(cont>2)
                                {

                                    strcpy(dirXator,token);

                                       if(verificaDiretor(dirXator))
                                       {

                                        //printf("DIRETOR    %s\n",dirXator);
                                        insereDiretores(&inicio_d,&fim_d,anoXdir,&par_memoria,&dir);
                                        insereRefDiretores(&par_memoria,&dir);

                                       }
                                        else
                                           {
                                       //        printf("ATORES       %s\n",dirXator);
                                              strcpy(atores_i,token);
                                              strupr(atores_i);
                                              removeBarraN(atores_i);

                                               if(temPersonagem(atores_i)==1){
                                                  cont_p=0;
                                              tok = strtok(atores_i, z);

                                               while( tok != NULL )
                                              {
                                                  if(cont_p==0){
                                              insere_Atores(&inicio_a,&fim_a,atores_i,&par_memoria,&at);
                                              insereRefAtores(&par_memoria,&at);}


                                                  if(cont_p==1){
                                               // printf( " %s\n", tok );
                                                insere_Personagem(&inicio_p,&fim_p,tok,&par_memoria,&at);
                                                  }

                                                tok = strtok(NULL, z);
                                                cont_p++;
                                               }

                                              }else{insere_Atores(&inicio_a,&fim_a,atores_i,&par_memoria,&at);
                                              insereRefAtores(&par_memoria,&at);}

                                           }

                                        }


                            token = strtok(NULL, s);
                            cont++;

                        }
                 }
                 fclose(arquivo);

            printf("Dados carregados com sucesso!\n\n");
    }

//---------------------------------------------------------------------------------------------------------------------------------

      menu();
      printf("\nDigite sua opcao: ");
      resp=getch();
      fflush(stdin);

      while(resp == 'A' || ((resp>='1') && (resp<='9'))){
         switch(resp){

             case '1': printf("\nDigite 0 para listar em ordem alfabetica ou 1 para listar em ordem alfabetica reversa: ");
                       scanf("%d",&valor);
                       escreveAtores(inicio_a,fim_a,valor);
                       break;

             case '2': printf("\nDigite o nome completo do ator: ");
                       gets(nomeator);
                       strupr(nomeator);
                       verifica = existeAtor(inicio_a,nomeator);
                       if(!verifica) printf("Ator não cadastrado.\n");
                       else if(verifica) listaFilmesDeUmAtor(inicio_a,nomeator);
                       break;

             case '3': printf("\nDigite 0 para listar em ordem alfabetica ou 1 para listar em ordem alfabetica reversa: ");
                       scanf("%d",&valor);
                       escreveFilme(inicio,fim,valor);
                       break;

             case '4': printf("\nDigite o nome do filme a ser inserido: ");
                       gets(nomefilme);
                       strupr(nomefilme); //Converte em maiuscula
                       verifica = existeFilme(inicio,nomefilme);
                       if(verifica){
                         printf("O filme já existe no arquivo.\n");
                      }
                      else if(!verifica){
                        int i,numero,tamanho=0;
                        printf("\nDigite o ano do filme: ");
                        gets(ano);
                        insere_Filme(&inicio,&fim,nomefilme,ano,&par_memoria);
                        printf("\nDigite os diretores, quando quiser acabar digite enter sem nenhum dado: ");
                        gets(nomediretor);
                        strupr(nomediretor);
                        while(strlen(nomediretor) > 0){
                            printf("\nDigite os diretores, quando quiser acabar digite enter sem nenhum dado: ");
                            gets(nomediretor);
                            strupr(nomediretor);
                        }

                        printf("\nDigite os atores, quando quiser acabar digite enter sem nenhum dado: ");
                        gets(nomeator);
                        strupr(nomeator);
                        insere_Atores(&inicio_a,&fim_a,nomeator,&par_memoria,&at);
                        insereRefAtores(&par_memoria,&at);
                        while(strlen(nomeator) > 0){
                            printf("\nDigite os atores, quando quiser acabar digite enter sem nenhum dado: ");
                            gets(nomeator);
                            strupr(nomeator);
                            if(strlen(nomeator) > 0) {insere_Atores(&inicio_a,&fim_a,nomeator,&par_memoria,&at);
                            insereRefAtores(&par_memoria,&at);}
                        }

                    }

                    break;

                case '5': printf("\nDigite o nome do filme a ser excluido: ");
                          gets(nomefilme);
                          strupr(nomefilme);
                          verifica = existeFilme(inicio,nomefilme);
                          if(verifica == 0){
                            printf("\nFilme nao cadastrado.");
                            break;
                          }
                          else if(verifica){
                              removeFilme(&inicio,&fim,nomefilme,&inicio_a,&fim_a);
                              printf("\nFilme removido com sucesso.\n");
                          }
                          break;

                case '6': printf("\nDigite o nome completo do diretor: ");
                          gets(nomediretor);
                          strupr(nomediretor);
                          verifica = existeDiretor(inicio_d,nomediretor);
                          if(!verifica) printf("Diretor não cadastrado.\n");
                          else if(verifica) listaFilmesDeUmDiretor(inicio_d,nomediretor);
                          break;

                case '7': printf("\nDigite o nome do ator a ser pesquisado: ");
                          gets(nomeator);
                          strupr(nomeator);
                          verifica = existeAtor(inicio_a,nomeator);
                          if(verifica == 0){
                            printf("\nAtor nao cadastrado.");
                            break;
                          }
                          else if(verifica){
                            listaAtorTrabalhoAtor(inicio_a,nomeator);
                          }
                          break;

                case '8': printf("\nDigite o nome do diretor: ");
                          gets(nomediretor);
                          strupr(nomediretor);
                          listaDiretorTrabalhoAtor(inicio_d,nomediretor);
                          break;

                case '9': listaFilmesDuplicado(inicio,fim);
                          break;

                case 'A': printf("\nDigite o nome do personagem: ");
                          gets(nomeator);
                          strupr(nomeator);
                         // listaAtorPersonagem(inicio_a,nomeator);
                         imprimePersonagem(inicio_p,nomeator);
                          break;

        }
         printf("\n");
         menu();
         printf("\nDigite sua opcao: \n");
         resp=getch();
         fflush(stdin);
    }

}
