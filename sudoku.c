#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  for(int i = 0 ; i < 9 ; i++)
  {
    int * marcadosFila = calloc(9, sizeof(int));
    int * marcadosColumna = calloc(9, sizeof(int));
    int * marcadosSubMatriz = calloc(9, sizeof(int));
    for(int k = 0 ; k < 9 ; k++)
      {
        int numFila = n->sudo[i][k];
        int numColumna = n->sudo[k][i];
        
        int filaSubMatriz = 3 * (i/3) + (k/3);
        int columnaSubMatriz = 3 * (i%3) + (k%3);
        int numSubMatriz = n->sudo[filaSubMatriz][columnaSubMatriz];
        
        if(numFila != 0)
        {
          if(marcadosFila[numFila] == 0) {
             marcadosFila[numFila] = 1;
          }else{
            return 0;
          }
        }

        if(numColumna != 0)
        {
          if(marcadosColumna[numColumna] == 0)
          {
            marcadosColumna[numColumna] = 1;
          }else{
            return 0;
          }
        }

        if(numSubMatriz != 0)
        {
          if(marcadosSubMatriz[numSubMatriz] == 0)
          {
            marcadosSubMatriz[numSubMatriz] = 1;
          }
          else
          {
            if(marcadosSubMatriz[numSubMatriz] == 0)
            {
              marcadosSubMatriz[numSubMatriz] = 1
            }
            else
            {
              return 0;
            }
          }
          
        }
          
        
        
      }
  }
    return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();

    int primerCeroEncontrado = 0;
     for(int i = 0 ; i < 9 ; i++)
      {
        for(int k = 0 ; k < 9 ; k++)
        {
          if(n->sudo[i][k] == 0)
          {
            primerCeroEncontrado = 1;
            for(int j = 0 ; j < 9 ; j++)
            {
              Node * nuevoNodo = copy(n);
              nuevoNodo->sudo[i][k] = j + 1;
              
              if(is_valid(nuevoNodo))
              {
                pushBack(list,nuevoNodo);
              }
            }
          }
          if(primerCeroEncontrado == 1)
            {
              return list;
            }
        }
      }
    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/