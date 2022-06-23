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
  STATIONRES tab1[1000];
  file=fopen("/Users/ibrahimandiaye/Documents/INFO/itinerairemetro/itinerairemetro/metro.csv","r");
  LIST tab[40];
  
//  char str[CHAI];
//  LIST metro={NULL, NULL};
  if(file != NULL)
  {
    loadListTab(tab, file);
      fclose(file);
  }
  else
  {
    printf("Impossible d'ouvrir le fichier \n ");
  }
  remplireserve(tab1,tab);
  SLIST reserve = {NULL,NULL};
  reserve = rempliReserve(tab);
  printSList(reserve);
//  for(int i=0;i<z;i++)
//  {
//    printf("Station %d = %s  // Horaire = %f  \n",i,tab1[i].nomS,tab1[i].Horaire);
//  }
//  printList(tab[0]);
  return 0;
}

