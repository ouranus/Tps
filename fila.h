/*
 * fila.h
 *
 *  Created on: 17/03/2014
 *      Author: guigui
 */

#ifndef FILA_H_
#define FILA_H_

class fila {
public:
	fila();
	virtual ~fila();
};

#endif /* FILA_H_ */


/*
 * Listadulpaencadeada.h
 *
 *  Created on: 17/03/2014
 *      Author: guigui
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

int tamanho(FILA *f) {
  PONT end = f->inicio;
  int tam = 0;
  while (end != NULL){
    tam++;
    end = end->prox;
  }
  return tam;
}

