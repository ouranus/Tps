/*
 * fila.h
 *
 *  Created on: 17/03/2014
 *      Author: guigui
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stddef.h>
#define ERRO -1
#define true 1
#define false 0
#ifndef FILA_H_
#define FILA_H_

class fila {
public:
	fila();
	virtual ~fila();
};

#endif /* FILA_H_ */


/*
 * fila.h
 *
 *  Created on: 17/03/2014
 *      Author: Gibosky
 */

typedef int bool;
typedef int key;

typedef struct typebody{
  key id;
  struct typebody *next;
} body, *pointer;

typedef struct {
  pointer begin;
  pointer end;
} line;

void start_line(line *l){
  l->begin = NULL;
  l->end = NULL;
}

void end_line(line *l) {
  pointer end = l->begin;
  while (end != NULL){
    pointer r = end;
    end = end->next;
    ~fila(r);
  }
  l->begin = NULL;
}

int size(line *l) {
  pointer end = l->begin;
  int size = 0;
  while (end != NULL){
    size++;
    end = end->next;
  }
  return size;
}

pointer first_in_line(line *l, key *k){
  if (l->begin != NULL) *k = l->begin->id;
  return l->begin;
}

pointer last_in_line(line *l, key *k){
  pointer last = l->begin;
  if (l->begin == NULL) return NULL;
  while (last->next != NULL) last = last->next;
  *k = last->id;
  return last;
}

bool line_insert_item(line *l, body b) {
  pointer n = (pointer) malloc(sizeof(body));
  *n = b;
  n->next = NULL;
  if (l->begin==NULL){
     l->begin = n;
  }else{
     l->end->next = n;
  }
  l->end = n;
  return true;
}

bool remove_from_line(line *l, body *b) {
  if (l->begin==NULL){
    return false;
  }
  *b = *(l->begin);
  pointer r = l->begin;
  l->begin = l->begin->next;
  ~fila(r);
  if (l->begin == NULL){
    l->end = NULL;
  }
  return true;
}

void line_print(line *l){
  pointer end = l->begin;
  printf("Fila: \" ");
  while (end != NULL){
    printf("%d ", end->id);
    end = end->next;
  }
}
