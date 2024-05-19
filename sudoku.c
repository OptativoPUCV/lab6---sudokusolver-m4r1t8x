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
        int filas = 0;
        int columnas = 0;
        for (int j = 0; j < 9; j++) {
            // Verificar filas
            if (n->sudo[i][j] != 0 && (filas & (1 << n->sudo[i][j])) != 0)
                return 0;
            filas |= (1 << n->sudo[i][j]);

            // Verificar columnas
            if (n->sudo[j][i] != 0 && (columnas & (1 << n->sudo[j][i])) != 0)
                return 0;
            columnas |= (1 << n->sudo[j][i]);
        }
    }

    // Verificar submatrices 3x3
    for (int k = 0; k < 9; k += 3) {
        for (int l = 0; l < 9; l += 3) {
            int subMatrices = 0;
            for (int i = k; i < k + 3; i++) {
                for (int j = l; j < l + 3; j++) {
                    if (n->sudo[i][j] != 0 && (subMatrices & (1 << n->sudo[i][j])) != 0)
                        return 0;
                    subMatrices |= (1 << n->sudo[i][j]);
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
                  aux1 = i;
                  aux2 = j;
                  break;
               }
            }
         if (aux1 != -1) break;
      }
   if(aux1 == -1 || aux2 == -1) return list;
   
   for(int num = 1; num <= 9; num++)
      {
         Node* adj = copy(n);
         adj->sudo[aux1][aux2] = num;
         if(is_valid(adj))
         {
            pushBack(list, adj);
         }
         else
         {
            free(adj);
         }
      }
   return list;
}


int is_final(Node* n)
{
   for(int i = 0; i < 9; i++)
      {
         for(int j = 0; j < 9; j++)
            {
               if(n->sudo[i][j] == 0)
               {
                  return 0;
               }
            }
      }
    return 1;
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