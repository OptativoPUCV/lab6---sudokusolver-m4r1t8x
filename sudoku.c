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

int is_valid(Node* n)
{
   for (int i = 0; i < 9; i++) {
        int row_mask = 0;
        int col_mask = 0;
        for (int j = 0; j < 9; j++) {
            // Verificar filas
            if (n->sudo[i][j] != 0 && (row_mask & (1 << n->sudo[i][j])) != 0)
                return 0;
            row_mask |= (1 << n->sudo[i][j]);

            // Verificar columnas
            if (n->sudo[j][i] != 0 && (col_mask & (1 << n->sudo[j][i])) != 0)
                return 0;
            col_mask |= (1 << n->sudo[j][i]);
        }
    }

    // Verificar submatrices 3x3
    for (int k = 0; k < 9; k += 3) {
        for (int l = 0; l < 9; l += 3) {
            int sub_mask = 0;
            for (int i = k; i < k + 3; i++) {
                for (int j = l; j < l + 3; j++) {
                    if (n->sudo[i][j] != 0 && (sub_mask & (1 << n->sudo[i][j])) != 0)
                        return 0;
                    sub_mask |= (1 << n->sudo[i][j]);
                }
            }
        }
    }

    return 1;
}


List* get_adj_nodes(Node* n)
{
   List* list = createList();
   int aux1 = -1, aux2 = -1;
   int i, j;
   for (i = 0; i < 9; i++)
      {
         for (j = 0; j < 9; j++)
            {
               if (n->sudo[i][j] == 0)
               {
                  for(int k = 0; k <= 9; k++)
                     {
                        Node *valor = copy(n);
                        valor->sudo[i][j] = k;
                        pushBack(list, valor);
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