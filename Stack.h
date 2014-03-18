/*
 * Stack.h
 *
 *  Created on: 17/03/2014
 *      Author: guigui
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stddef.h>
#define true 1
#define false 0
#ifndef STACK_H_
#define STACK_H_

class Stack {
public:
	Stack();
	virtual ~Stack();
};

#endif /* STACK_H_ */

typedef int bool;
typedef int key;

typedef struct typebody{
  key id;
  struct typebody *next;
} body;

typedef body* pointer;

// o ponteiro topo aponta para o topo da pilha (será NULL caso a pilha esteja vazia)
typedef struct {
  pointer top;
} stack;

void start_stack(stack *p){ // Inicializa uma pilha
  p->top = NULL;
}

bool remove_stack(stack *p){ // Apaga a pilha
  pointer r;
  pointer t = p->top;
  while (t != NULL){
        r = t;
        t = t->next;
        ~Stack(r);
  }
  p->top = NULL;
  return true;
}

int size_stack(stack *p) { // Retorna o tamanho da pilha
  pointer end = p->top;
  int size = 0;
  while (end != NULL){
    size++;
    end = end->next;
  }
  return size;
}

pointer stack_top(stack *p, key *k){ // Fala qual é a chave do elemento do topo
  if (p->top != NULL) *k = p->top->id;
  return p->top;
}

bool insert_stack(body b, stack *p) { // Insere um elemento no topo da pilha
  pointer n = (pointer) malloc(sizeof(body));
  *n = b;
  n->next = p->top;
  p->top = n;
  return true;
}

void stack_print(stack *p){ // Imprime a Pilha
  pointer end = p->top;
  printf("Pilha: \" ");
  while (end != NULL){
    printf("%d ", end->id);
    end = end->next;
  }
  printf("\"\n");
}
