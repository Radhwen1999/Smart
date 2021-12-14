#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct
{
    	char id[20];
	char nom[20];
	char quantite[20];
	char val[20];
	char cat[20];
}stock;
void ajouter_ahmed(stock s);
stock chercheid_ahmed(char b[]);
stock cherchenom_ahmed(char b[]);
stock cherchequan_ahmed(char b[]);
stock chercheval_ahmed(char b[]);
stock cherchecat_ahmed(char b[]);
void supprimer_ahmed(char a[]);
void modifier_ahmed(stock s);
void rupture();
void vider_ahmed(GtkWidget *liste);
void treeview_affiche_ahmed(GtkWidget *liste);
void affiche_chercher_ahmed(GtkWidget *liste);
void cherche_id_ahmed(char b[]);
void cherche_nom_ahmed(char b[]);
void cherche_quan_ahmed(char b[]);
void cherche_val_ahmed(char b[]);
void cherche_type_ahmed(char b[]);

