//
//  main.c
//  itinerairemetro
//
//  Created by Ibrahima Ndiaye on 15/04/2022.
//
#include <stdio.h>
#include "metro.h"

int main(void)
{
  FILE* file =NULL;
  file=fopen("/Users/ibrahimandiaye/Documents/INFO/itinerairemetro/itinerairemetro/metro.csv","r");
  LIST tab[40];
  char str[CHAI];
  LIST metro={NULL, NULL};
  loadmetroX(&metro, str, file, '1', ':', 'a');
  printList(metro);
  if(file != NULL)
  {
    loadListTab(tab, file);
      fclose(file);
  }
  else
  {
    printf("Impossible d'ouvrir le fichier \n ");
  }
  printList(tab[0]);
  printList(tab[1]);


//  SLIST reserve ={NULL,NULL};
//  remplireserve(reserve , tab);
  
//  printSList(reserve);

  return 0;
}

