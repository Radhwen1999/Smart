#define FONCTION_H
#include <stdio.h>
#include<gtk/gtk.h>
typedef struct 
{
int jour ;
int mois ;
int annee ;
}date ;

typedef struct 
{
char nom[20];
char prenom[20];
char id[11];
char sexe[20] ;
char email[20] ;
char obj_rec[20] ;
date D ;
char text_rec[1000] ;
} reclamation ;



void ajouter_rec (reclamation Rec) ;
void supprimer_rec (char id[10]) ;
void supprimer_toute_rec(reclamation Rec) ;
void modifier_rec (char id[10] ,char text_nouv[1000]) ;
void afficher_rec (GtkWidget *liste) ;
void chercher_rec(GtkWidget *liste,char id_rech[10]) ;
reclamation find_rec (char id[10]) ;
int idExist1(char id_s[10]) ;
int service_plusreclame() ;   // afficher le service le plus réclamé
