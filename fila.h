//Code by:Eric Mnz
#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#define MAX 100

//cria o tipo do item que esta contido na fila
typedef int tp_item;

//cria o struct para poder criar o tipo abstrato de dados chamado fila
typedef struct {
    tp_item item[MAX];
    int ini, fim;
    int tam;
}tp_fila;

//esta funcao inicializa o tipo abstrato de fila
void inicializa_fila(tp_fila *f){
    f->ini = f->fim = MAX-1;
    f->tam=0;
}
//esta funcao verifica se a fila esta vazia retornando 1 como verdadeiro e 0 como falso
int fila_vazia(tp_fila *f){
	if(f->ini == f->fim) return 1;
	return 0;
}
//esta funcao comanda para ir para o proximo elemento da fila
int proximo (int pos){
	if(pos == MAX-1) return 0;
	return ++pos;
}
//esta funcao verifica se a fila esta cheia retornando 1 como verdadeiro e 0 como falso
int fila_cheia (tp_fila *f){
	if(proximo(f->fim) == f->ini)
	  return 1;
	return 0;
}
//esta funcao insere um elemento na fila
int insere_fila (tp_fila *f, tp_item e){
	if(fila_cheia(f))
	   return 0; // nao foi possivel adicionar a fila
	f->fim = proximo(f->fim);
	f->item[f->fim]= e;
    f->tam++;
    return 1;
}

//esta funcao remove um elemento da fila e o armazena no item "e"
int remove_fila(tp_fila *f, tp_item *e){
	
	if(fila_vazia(f))
	 return 0;
	f->ini = proximo(f->ini);
	*e = f->item[f->ini];
	f->tam--;
	return 1;
	
}
//esta funcao imprime a fila
void imprime_fila(tp_fila f){
	tp_item e;
	while(!fila_vazia(&f)){
		remove_fila(&f, &e);
		printf("\n%d", e);
	}
}
//esta funcao verifica e retorna o tamanho da fila
int tamanho_fila(tp_fila *f){
	if(fila_vazia(f))
	return 0;
	
	if(f->ini < f->fim)
	 return f->fim - f->ini;
	return MAX - 1 - f->ini + f->fim +1;
}





#endif