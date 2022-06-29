//
//  metro.c
//  itinerairemetro
//
//  Created by Ibrahima Ndiaye on 15/04/2022.
//
#include "metro.h"

void printStation(STATION station , int num )
{
  printf("***************\n");
  printf("* STATION %d  *\n",num);
  printf("***************\n");
  printf("Nom de la station : %s \n",station.nomS);
  printf("Temps pour aller à la station précédente: %.0f min\n", station.tempPrec);
  printf("Temps pour aller à la station suivante : %.0f min\n",station.tempSuiv);
  printf("Heure de début : %lf " , station.horaire);
}
void loadtabTemps(double *tab, char* str , int i)
{

  char* new_str = strtok(str, ":");
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
  if (new_str[0]=='*')
  {
    for(int j=0;new_str[j];j++)
    {
      new_str[j]=new_str[j+1];
    }
  }
  tab[i] = atof(new_str);

}
void loadStation(STATION* station, char* str ,double *tab , int i)
{
  char* new_str = strtok(str, ":");
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
//  memset(tab, 0, 100*sizeof(int));
  strncpy(station->nomS,new_str,CHAI);
//  printf("%lf - %lf = %lf \n" ,tab[i+1],tab[i], tab[i+1]-tab[i]);
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
  station->horaire=atof(new_str);
  station->tempSuiv=tab[i+1]-tab[i];
  if(tab[i+1]-tab[i]>0.1)
  {
    station->tempSuiv = (station->tempSuiv-0.4);
  }
  station->tempSuiv=station->tempSuiv*100;
  if (station->tempSuiv<0) {
    station->tempSuiv=-station->tempSuiv;
  }
  station->tempPrec=tab[i]-tab[i-1];
  if(tab[i]-tab[i-1]>0.1)
  {
    station->tempPrec = (station->tempPrec-0.4);
//    printf(" choc2 %lf - %lf = %lf \n" ,tab[i],tab[i-1], (tab[i+1]-tab[i])-0.4);
  }
  station->tempPrec=station->tempPrec*100;
  if (station->tempPrec<0) {
    station->tempPrec=-station->tempPrec;
  }
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
//  Conversion ASCII to float
}
void appendToListSTation(LIST* list, STATION station)
{
  NODE *node;
  node = (NODE*) calloc(1 ,sizeof(NODE));
  node->station=station;
  if(list->last!=NULL && list->first!=NULL)
  {
    list->last->ssuiv=node;
    node->sprec=list->last;
    list->last=node;
  }
  else
  {
    list->first=node;
    list->last=node;
    list->first->station.tempPrec=0;
  }
}


void printList(LIST list )
{
  if(list.first==NULL && list.last==NULL)
  {
    printf("La liste est vide \n");
  }
  else
  {
    NODE* node;
    int i=1;
    node=list.first;
    while (node!=list.last)
    {
       printStation(node->station,i);
      node=node->ssuiv;
      i++;
      printf("\n");
    }
    printStation(list.last->station,i );
  }
  printf("\n");
}

void loadmetroX(LIST *list,char* str , FILE* file , char a0 ,char b1 ,char c2)
{
  double temps[400]={0,}; 
  int z=0,k=0;
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]==a0 && str[1]==b1 && str[2]==c2)
      {
        loadtabTemps(temps, str, z );
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]==a0 && str[1]==b1 && str[2]==c2)
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  rewind(file);
  list->last->station.tempSuiv=0;
}
void loadmetroXX(LIST *list,char* str , FILE* file , char a0 ,char b1 ,char c3)
{
  double temps[400];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]==a0 && str[1]==b1 && str[3]==c3)
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]==a0 && str[1]==b1 && str[3]==c3)
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  rewind(file);
  list->last->station.tempSuiv=0;
}
void loadmetroXbis(LIST *list,char* str , FILE* file , char a0 ,char b1 ,char c3)
{
  double temps[400];
  
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]==a0 && str[1]==b1 && str[5]==c3)
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]==a0 && str[1]==b1 && str[5]==c3)
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  rewind(file);
  list->last->station.tempSuiv=0;
}


void loadListTab(LIST *tab , FILE *file)
{
  char str[CHAI];
  for(int i=0;i<40;i++)
  {
    LIST metro={NULL, NULL};
    switch (i)
    {
      case 0:
        loadmetroX(&metro, str, file, '1', ':', 'a');
        tab[i]=metro;
        break;
      case 1:
        loadmetroX(&metro, str, file, '1', ':', 'b');
        tab[i]=metro;
        break;
      case 2:
        loadmetroX(&metro, str, file, '2', ':', 'a');
        tab[i]=metro;
        break;
      case 3:
        loadmetroX(&metro, str, file, '2', ':', 'b');
        tab[i]=metro;
        break;
      case 4:
        loadmetroX(&metro, str, file, '3', ':', 'a');
        tab[i]=metro;
        break;
      case 5:
        loadmetroX(&metro, str, file, '3', ':', 'b');
        tab[i]=metro;
        break;
      case 6:
        loadmetroXbis(&metro, str, file, '3', 'b', 'a');
        tab[i]=metro;
        break;
      case 7:
        loadmetroXbis(&metro, str, file, '3', 'b', 'b');
        tab[i]=metro;
        break;
      case 8:
        loadmetroX(&metro, str, file, '4', ':', 'a');
        tab[i]=metro;
        break;
      case 9:
        loadmetroX(&metro, str, file, '4', ':', 'b');
        tab[i]=metro;
        break;
      case 10:
        loadmetroX(&metro, str, file, '5', ':', 'a');
        tab[i]=metro;
        break;
      case 11:
        loadmetroX(&metro, str, file, '5', ':', 'b');
        tab[i]=metro;
        break;
      case 12:
        loadmetroX(&metro, str, file, '6', ':', 'a');
        tab[i]=metro;
        break;
      case 13:
        loadmetroX(&metro, str, file, '6', ':', 'b');
        tab[i]=metro;
        break;
      case 14:
        loadmetroX(&metro, str, file, '7', ':', 'a');
        tab[i]=metro;
        break;
      case 15:
        loadmetroX(&metro, str, file, '7', ':', 'b');
        tab[i]=metro;
        break;
      case 16:
        loadmetroXbis(&metro, str, file, '7', 'b', 'a');
        tab[i]=metro;
        break;
      case 17:
        loadmetroXbis(&metro, str, file, '7', 'b', 'b');
        tab[i]=metro;
        break;
      case 18:
        loadmetroX(&metro, str, file, '8', ':', 'a');
        tab[i]=metro;
        break;
      case 19:
        loadmetroX(&metro, str, file, '8', ':', 'b');
        tab[i]=metro;
        break;
      case 20:
        loadmetroX(&metro, str, file, '9', ':', 'a');
        tab[i]=metro;
        break;
      case 21:
        loadmetroX(&metro, str, file, '9', ':', 'b');
        tab[i]=metro;
        break;
      case 22:
        loadmetroXX(&metro, str, file, '1', '0', 'a');
        tab[i]=metro;
        break;
      case 23:
        loadmetroXX(&metro, str, file, '1', '0', 'b');
        tab[i]=metro;
        break;
      case 24:
        loadmetroXX(&metro, str, file, '1', '1', 'a');
        tab[i]=metro;
        break;
      case 25:
        loadmetroXX(&metro, str, file, '1', '1', 'b');
        tab[i]=metro;
        break;
      case 26:
        loadmetroXX(&metro, str, file, '1', '2', 'a');
        tab[i]=metro;
        break;
      case 27:
        loadmetroXX(&metro, str, file, '1', '2', 'b');
        tab[i]=metro;
        break;
      case 28:
        loadmetroXX(&metro, str, file, '1', '3', 'a');
        tab[i]=metro;
        break;
      case 29:
        loadmetroXX(&metro, str, file, '1', '3', 'c');
        tab[i]=metro;
        break;
      case 30:
        loadmetroXX(&metro, str, file, '1', '3', 'd');
        tab[i]=metro;
        break;
      case 31:
        loadmetroXX(&metro, str, file, '1', '4', 'a');
        tab[i]=metro;
        break;
      case 32:
        loadmetroXX(&metro, str, file, '1', '4', 'b');
        tab[i]=metro;
        break;
      default:
        break;
    }
  }
    fclose(file);
}
void printSList(SLIST list )
{
  if(list.first==NULL && list.last==NULL)
  {
    printf("La liste est vide \n");
  }
  else
  {
    SNODE* node;
    int i=1;
    node=list.first;
    while (node!=NULL)
    {
      printf("STATION : %s",node->station.nomS);
      node=node->ssuiv;
      i++;
      printf("\n");
    }
    printf("STATION : %s",node->station.nomS);
    printf("\nNombre STATION : %d\n" , i);
  }
  printf("\n");
}
void appendToListSTationReserve(SLIST* list, STATIONRES station)
{
  SNODE *node;
  node = (SNODE*) calloc(1 ,sizeof(SNODE));
  node->station=station;
  if(list->last!=NULL && list->first!=NULL)
  {
    list->last->ssuiv=node;
    list->last=node;
  }
  else
  {
    list->first=node;
    list->last=node;
  }
}
void remplireserve(SLIST reserve,LIST *tab1)
{
//  int z=0,j,i;
  STRING name;
  for (int i =0; i<33; i++)
  {
    NODE* node;
    LIST metro={NULL, NULL};
    metro=tab1[i];
    node=metro.first;
    int x=1;
    while(node!=NULL )
    {
      strncpy(name,node->station.nomS,CHAI);
      if (node==metro.first)
      {
        STATIONRES station ;
        strncpy(station.nomS, name, CHAI);
        appendToListSTationReserve(&reserve, station);
      }
      else
      {
        SNODE *node2 = reserve.first->ssuiv;
        while(node2!=NULL && x==1)
        {
          if(reserve.first==reserve.last)
          {
            STATIONRES station ;
            strncpy(station.nomS, name, CHAI);
            appendToListSTationReserve(&reserve,station);
            printSList(reserve);
            x=0;
          }
          if (node2!=reserve.last)
          {
            if(strcmp(node2->station.nomS,name)==0)
            {
              x=0;
            }
            else
            {
              node2=node2->ssuiv;
            }
          }
          else
          {
              if(strcmp(reserve.last->station.nomS, name)==0 )
              {
                x=0;
              }
              else
              {
                STATIONRES station ;
                strncpy(station.nomS, name, CHAI);
                appendToListSTationReserve(&reserve,station);
                printSList(reserve);
                x=0;
              }
          }
          
        }
      }
      node=node->ssuiv;
    }
  }
  printSList(reserve);
  SNODE *position = reserve.first;
  SNODE *vparcours = reserve.last;
  //on verifie si une ligne apparait deux fois on la supprime
  while (position != reserve.last)
  {
    while (vparcours != position && vparcours != reserve.first)
    {
      if (strcmp(position->station.nomS, vparcours->station.nomS)!=0)
        removeStation(&reserve, vparcours->station.nomS);
      printSList(reserve);
      vparcours = vparcours->sprec;
    }
    vparcours = reserve.last;
    position = position->ssuiv;
  }
}

//void insert(LIGNE *pLigne, STATION *station)
//{
//  STATION *vParcours = pLigne->premiereStation;
//  vParcours = pLigne->premiereStation;
//  if (pLigne->premiereStation == NULL)
//  {
//    station->suiv = NULL;
//    pLigne->premiereStation = station;
//    pLigne->derniereStation = station;
//  }
//  while (vParcours != NULL)
//  {
//    if (station->poids < vParcours->poids)
//    {
//      if (vParcours == pLigne->premiereStation)
//      {
//        vParcours->prec = station;
//        pLigne->premiereStation = station;
//        station->suiv = vParcours;
//        break;
//      }
//      else
//      {
//        station->prec = vParcours->prec;
//        vParcours->prec->suiv = station;
//        vParcours->prec = station;
//        station->suiv = vParcours;
//        break;
//      }
//    }
//    vParcours = vParcours->suiv;
//  }
//  vParcours = pLigne->derniereStation;
//  if (station->poids >= vParcours->poids)
//    appendToLigne(pLigne, *station);
//}
STATIONRES removeHeadFromList(SLIST *list)
{
  SNODE *stationToRemove = NULL;
  if (list->first==NULL)
    printf("La liste est vide \n ");
  else
  {
    stationToRemove = list->first;
    list->first = list->first->ssuiv;
    if (list->first==NULL) { /*printf("ErreUr liste Vide");*/ }
    else
      list->first->sprec= NULL;
  }
  return  stationToRemove->station;
}
STATIONRES removeTailFromList(SLIST *list)
{
  SNODE *stationToRemove=NULL;
  if(list->first==NULL && list->last==NULL)
  {
    printf("la liste est vide \n");
  }
  else
  {
    stationToRemove = list->last;
    list->last = list->last->sprec;
    if (list->first==NULL)
    {
      list->first= NULL;
      list->last= NULL;
    }
//    else
//    {
//      list->last->ssuiv=null;
//    }
  }
  return stationToRemove->station;
}
STATIONRES removeStation(SLIST * list, STRING name )
{
  PSNODE stationToRemove=list->first;
  if (list->first==NULL)
    printf("La liste est vide \n ");
  else
  {
    // Liste Update
    if (!strcmp(list->first->station.nomS,name))
      stationToRemove->station=removeHeadFromList(list);
    else if (!strcmp(list->last->station.nomS, name))
      stationToRemove->station = removeTailFromList(list);
    else
    {
      stationToRemove = list->first->ssuiv;
      while (stationToRemove != list->last && strcmp(stationToRemove->station.nomS, name)!=0)
      {
        stationToRemove = stationToRemove->ssuiv;
      }
      stationToRemove->sprec->ssuiv = stationToRemove->ssuiv;
      stationToRemove->ssuiv->sprec = stationToRemove->sprec;
    }
  }
  return stationToRemove->station;
}

