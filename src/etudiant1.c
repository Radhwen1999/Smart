#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "etudiant1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

int nb_etud(char niv[])
{
FILE *f;
char id[100];
char nom[100];
char prn[100];
char nv[100];
char sexe[100];
char date[100];
int i=0;
f=fopen("etudiant.txt","r");
while (fscanf(f,"%s %s %s %s %s %s \n",nom,prn,nv,id,sexe,date)!=EOF)
{
if(strcmp(nv,niv )==0)
{
i=i+1;
}
}
fclose(f);
return (i);
}
//////////////////////// Le service le plus réclamé //////////////////////



///////////////// le meilleur menu/////////////////////









