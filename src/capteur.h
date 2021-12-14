
#include<gtk/gtk.h>
typedef struct
{
char id[20];
char reference[20]; 
char marque [20];
char prix[20];
char nomdecapteur[20];
char service[200];
int jourofcapteur;
int moisofcapteur;
int anneeofcapteur;
char etat [20];
}capteur;

void ajouter_capteur(capteur c);
int idExist(char id[]);
void supprimer_capteur(char id[]);
capteur find_cap(char id[]);
void modifier_capteur(capteur p);
void afficher_capteur(GtkWidget *liste);
void afficher_findcapteur(GtkWidget *liste,char test [20]);
void vider (GtkWidget *liste);


