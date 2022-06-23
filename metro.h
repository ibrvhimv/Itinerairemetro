//
//  metro.h
//  itinerairemetro
//
//  Created by Ibrahima Ndiaye on 15/04/2022.
//
#ifndef metro_h
#define metro_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#define CHAI 80
#define MAT 80
typedef char STRING[CHAI];
typedef struct _STATION
{
  STRING nomS;
  double horaire;
  double tempSuiv;
  double tempPrec;
} STATION;
typedef struct _NODE
{
  STATION station;
  struct _NODE *sprec;
  struct _NODE *ssuiv;
}NODE,*PNODE;
typedef struct
{
  PNODE first;
  PNODE last;
}LIST;
typedef struct _STATION_RES
{
  STRING nomS;
  int poids ;
  struct _STATION_RES *parent;
}STATIONRES,*PSTATIONRES;
typedef struct _SNODE
{
  STATIONRES station;
  struct _SNODE *ssuiv;
  struct _SNODE *sprec;
}SNODE ,*PSNODE;
typedef struct
{
  PSNODE first;
  PSNODE last;
}SLIST;
typedef struct _TabLigne
{
  STRING nameLigne;
  LIST list;
}TABLIGNE ,*PTABLIGNE;
void printStation(STATION station , int num);
const char* getNomStation(STATION *station);
void setName(STATION *station ,STRING name );
void appendToListSTation(LIST* list, STATION station);
void loadtabTemps(double *tab, char* str , int i);
void printList(LIST list);
void loadStation(STATION* station, char* str ,double *tab , int i);
void rewind(FILE *stream);
void loadListTab(LIST *tab , FILE *file);
void loadmetroX(LIST *list,char* str , FILE* file, char a0 ,char b1 ,char c2);
void loadmetroXX(LIST *list,char* str , FILE* file , char a0 ,char b1 ,char c3);
void loadmetroXbis(LIST *list,char* str , FILE* file , char a0 ,char b1 ,char c3);
void temps_entre_2stations(LIST *tab  , int num);
void remplireserve(STATIONRES *tab,LIST *tab1);
void reechercheitineraire(SLIST reserve,LIST *tab1 , STRING depart , STRING arrive);
SLIST rempliReserve(LIST *tab1);
void printSList(SLIST list );
PSNODE suprimerDoublons(PSNODE snode1, STRING name);


 #endif /* metro_h */
