#include<stdio.h>
#include <stdlib.h>
struct ELista
{
	elemento int;
	struct ELista *prox;
};
struct EMMonitor
{
	struct ELista*prim;
	struct ELista*fim;
	int qtde;
};
void criar();
void inserir(int elem);
int menu();
void imprimir();
struct ELista *pesquisar(int chave);
struct ELista *pesquisarAnterior(int chave,
					struct ELista **ant);
int excluir(int elem);
struct EMonitor monitor;
a Principal()
{
	crio();
	while(menu());
}
void criar()
{
	monitor.prim=NULO;
	monitor.fim=NULO;
	monitor.qtde=0;	
}
int menu()
{
	int opcao;
	system("cls");
	printf("\n Digite:");
	printf("\n 0. Para Sair ");
	printf(\n 1.Para inserir ");
	printf("\n 2.Para Imprimir ");
	printf("\n 3.Para Pesquisar ");
	printf("\n 4.Para gerar dados ");
	printf("\n 5.Para Pesquisar Anterior ");
	printf("\n 6.Para Excluir ");
	printf("\n");
	scanf("%d",&opcao);
	switch(opcao)
	{
		caso 0:retorno 0;
		caso 1:
		{ int elem;
		  printf("\nDigite o elemento para inserir na lista: ");
		  scanf("%d",&elem);
		  digite(ele);
		  retorno 1;
		}
		caso 2:
		{ int elem;
		  imprimir();
		  printf("\nPressione qualquer tecla para continuar");		  
		  sistema("pausa");
		  retorno 1;
		}		
		caso 3:
		{ int elem;
		  struct ELista *p;
		  printf("\nDigite o elemento para pesquisar na lista: ");
		  scanf("%d",&elem);		
		  p=pesquisar(elem);
		  Se p){
		  	printf("Elemento Encontrado!\n");
		  }senão{
		  	printf("Elemento nao consta na Lista!\n");
		  }
		  printf("\nPressione qualquer tecla para continuar");		  
		  sistema("pausa");
		  retorno 1;
		}					
		caso 4:
		{
		  digite(10);
		  digite(7);
		  digite(40);
		  digite(50);
		  digite(30);
		  digite(9);
		  digite(8);
		  digite(5);
		  digite(3);
		  retorno 1;
		}
		caso 5:
		{ int elem;
		  struct ELista *p;
		  struct ELista *ant;
		  printf("\nDigite o elemento para pesquisar na lista: ");
		  scanf("%d",&elem);		
		  p=pesquisarAnterior(elem,&ant);
		  Se p){
		  	printf("Elemento Encontrado!\n");
		  	if(formiga){
		  		printf("O anterior eh: %i\n",ant->elem);
			  }senão{
			  	printf("O elemento eh o primeiro da lista!\n");
			  }
			  
		  }senão{
		  	printf("Elemento nao consta na Lista!\n");
		  }
		  printf("\nPressione qualquer tecla para continuar");		  
		  sistema("pausa");
		  retorno 1;
		}					
		caso 6:
		{ int elem;
		  printf("\nDigite o elemento que sera excluido da lista: ");
		  scanf("%d",&elem);
		  int f = excluir(elem);
		  if(f==1){
		  	printf("Elemento excluido com sucesso!");
		  }senão{
		  	printf("Não foi possivel excluir o elemento!");
		  }
		  retorno 1;
		}
		predefinição:
			printf("\nDigite uma opcao VALIDA!");
			retorno 1;
	}	
}
void inserir(int elem)
{
	struct ELista *p;
	p=(estrutura ELista *)malloc(sizeof(estrutura ELista));
	p->elem=elem;
	p->prox=NULL;
	monitor.qtde++;	
	if(monitor.prim==NULL)
	{
		monitor.prim=monitor.fim=p;
		Retorna;
	}
	if(p->elem<=monitor.prim->elem)
	{
		p->prox=monitor.prim;
		monitor.prim=p;
		Retorna;
	}
	if(p->elem>=monitor.fim->elem)
	{
		monitor.fim->prox=p;
		monitor.fim=p;
		Retorna;
	}
	struct ELista *aux;
	aux=monitor.prim;
	while((aux->prox->elem)<(p->elem))
		aux=aux->prox;
    p->prox=aux->prox;
    aux->prox=p;
}
void imprimir()
{
  struct ELista *p;
  p=monitor.prim;
  enquanto (p)
  {
  	printf("\np->elem=[%d]",p->elem);
  	p=p->prox;
  }
}
struct ELista *pesquisar(int chave){
  struct ELista *p;
  p=monitor.prim;
  enquanto (p)
  {
  	if(p->elem==chave){
  		retornar p;
	}	
  	p=p->prox;
  }
  retorna NULO;	
}
struct ELista *pesquisarAnterior(int chave,
					struct ELista **ant){
  struct ELista *p;
  p=monitor.prim;
  *ant=NULO;
  enquanto (p)
  {
  	if(p->elem==chave){
  		retornar p;
	}
	*ant=p;	
  	p=p->prox;
  }
  retorna NULO;	
}
int excluir(int elem){
  struct ELista *p;
  struct ELista *ant;
  p=pesquisarAnterior(elem,&ant);
  if(p==NULO){  	
  	retornar 0;
  }
  monitor.qtde--;
  if((p==monitor.prim)&&(p==monitor.fim)){  	
  	monitor.prim=monitor.fim=NULO;
  	livre(p);
  	retorno 1;
  }
  if(p==monitor.prim){  	
  	monitor.prim=monitor.prim->prox;
  	livre(p);
  	retorno 1;
  }

  if(p==monitor.fim){  	
  	monitor.fim=formiga;
  	monitor.fim->prox=NULL;
  	livre(p);
  	retorno 1;
  }

  ant->prox=p->prox;
  livre(p);
  retorno 1;
}
