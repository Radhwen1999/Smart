#include <gtk/gtk.h>
typedef struct 
{   
    char nom[20] ;
    char date[20];
    char prenom[20] ;
    char niveau[40] ;
    char id[10] ;
    char sexe[7];
}etudiant;




void affichage_am (char fichier[],GtkWidget *liste) ; 

etudiant recherche_am(char fichier[],char x[] );

void ajouter_etudiant(etudiant e) ; 

int suprimer_etudiant(char fichier[],char iden[]) ;

int modifier_etudiant(char fichier[],etudiant e) ;
int verifier_am(char x[]) ;


