#define FONCTION_H
#include <stdio.h>
#include<gtk/gtk.h>
typedef struct 
{
char menuId [20];
char jour[20];
char petit_dejeuner[20] ;
char dejeuner[20];
char dinner[20];
}menu ;


void ajouter_menu (menu m) ;
void supprimer_menu (char id[10]) ;

void modifier_menu (char menuId[10] ,char nouv_jour[20],char nouv_petit_dejeuner[20]  ,char nouv_dejeuner [20],char nouv_dinner[20]) ;
void afficher_menu (GtkWidget *liste) ;
void chercher_menu(GtkWidget *liste,char id_rech[10]) ;
menu find_m (char id[20]) ;
int idExist22 (char id_s[20]) ;
int menu_moinsdechets();
