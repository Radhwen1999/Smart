#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "capteur.h"

/******************* AJOUTER CAPTEUR ***************************/
void ajouter_capteur(capteur c){
    FILE *f;
    f=fopen("capteur.txt","a");
    if(f!=NULL){
        fprintf(f,"%s %s %s %s %s %s %d %d %d %s\n",c.id,c.reference,c.marque,c.prix,c.nomdecapteur,c.service,c.jourofcapteur,c.moisofcapteur,c.anneeofcapteur,c.etat);
    }
        fclose(f);
}
/***************************** CONTREOL ID EXIST *********************/ 
int idExist(char id[]){
    capteur c;
    FILE *f;
    f = fopen("capteur.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s\n",c.id,c.reference,c.marque,c.prix,c.nomdecapteur,c.service,&c.jourofcapteur,&c.moisofcapteur,&c.anneeofcapteur,c.etat)!=EOF){
        	if(strcmp(c.id,id) == 0){
       		     return 1;
        	}
    	}
}
    fclose(f);
    return 0;
}
/************************** SUPPRIMER CAPTEUR *********************/
void supprimer_capteur(char id[]){   
    capteur c;

    FILE *f1;
    FILE *f2;
    f1 = fopen("capteur.txt","r");
    f2 = fopen("tmp.txt","a");
    while(fscanf(f1,"%s %s %s %s %s %s %d %d %d %s\n",c.id,c.reference,c.marque,c.prix,c.nomdecapteur,c.service,&c.jourofcapteur,&c.moisofcapteur,&c.anneeofcapteur,c.etat)!=EOF){
        if(strcmp(c.id,id)!=0){
            fprintf(f2,"%s %s %s %s %s %s %d %d %d %s\n",c.id,c.reference,c.marque,c.prix,c.nomdecapteur,c.service,c.jourofcapteur,c.moisofcapteur,c.anneeofcapteur,c.etat);
        }
    }
    fclose(f1);
    fclose(f2);
    remove("capteur.txt");
    rename("tmp.txt","capteur.txt");
    
}
/*********************** FIND CAPTEUR **********************************/
capteur find_cap(char id[]){
    capteur c;
    FILE *f;
    f = fopen("capteur.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s\n",c.id,c.reference,c.marque,c.prix,c.nomdecapteur,c.service,&c.jourofcapteur,&c.moisofcapteur,&c.anneeofcapteur,c.etat)!=EOF){
	if(strcmp(c.id,id) == 0){
       		return c;    
        }
       		     
       }
}

    fclose(f);
    return ;
} 
/* ************** MODIFIER UN CAPTEUR *****************/
void modifier_capteur(capteur p){
    capteur c;
    FILE *f;
    FILE *g;
    f = fopen("capteur.txt","r");
    g = fopen("tmp.txt","a");
    while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s\n",c.id,c.reference,c.marque,c.prix,c.nomdecapteur,c.service,&c.jourofcapteur,&c.moisofcapteur,&c.anneeofcapteur,c.etat) != EOF){
         if(strcmp(c.id,p.id) == 0){
            c = p;
        }
        fprintf(g,"%s %s %s %s %s %s %d %d %d %s\n",c.id,c.reference,c.marque,c.prix,c.nomdecapteur,c.service,c.jourofcapteur,c.moisofcapteur,c.anneeofcapteur,c.etat);
            
        
        
    }
    fclose(f);
    fclose(g);
    remove("capteur.txt");
    rename("tmp.txt","capteur.txt");
}
/* ********** AFFICHAGE ***************/
enum
{
	ID,
	REFERENCE,
	MARQUE,
	PRIX,
	NOM,
	DATE,
	SERVICE,
	ETAT,
	COLUMNS,
};
void afficher_capteur(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char id[20];
	char reference[20];
	char marque[20]; 
	char prix[20];
	char nom[20];
	char service[20];
	int jourofcapteur;
	int moisofcapteur;
	int anneeofcapteur;
	char etat[20];
	capteur c;
	store=NULL;
	FILE *f;
	
	store = gtk_tree_view_get_model(liste);

	if(store==NULL){
	renderer=gtk_cell_renderer_text_new();
   	column=gtk_tree_view_column_new_with_attributes("     ID     ",renderer,"text",ID,NULL);
   	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
   	column=gtk_tree_view_column_new_with_attributes("     Reference     ",renderer,"text",REFERENCE,NULL);
   	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("     Marque     ",renderer,"text",MARQUE,NULL);
   	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
   	column=gtk_tree_view_column_new_with_attributes("     Prix     ",renderer,"text",PRIX,NULL);
   	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("        Nom        ",renderer,"text",NOM,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("             Date d'ajout             ",renderer,"text",DATE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("                        Service                        ",renderer,"text",SERVICE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("  Etat   ",renderer,"text",ETAT,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    
	char text[50];
	f=fopen("capteur.txt","r");
 if(f==NULL){return ;}
else    {
	
         while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s\n",id,reference,marque,prix,nom,service,&jourofcapteur,&moisofcapteur,&anneeofcapteur,etat)!=EOF)
          {
	sprintf(text,"%d/%d/%d",jourofcapteur,moisofcapteur,anneeofcapteur);
		
           gtk_list_store_append(store,&iter);
           gtk_list_store_set(store, &iter, ID, id, REFERENCE, reference, MARQUE, marque, PRIX, prix, NOM, nom, DATE, text, SERVICE, service, ETAT, etat, -1);
          
        }
   fclose(f);
   gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
   g_object_unref (store);  
   }
}
}
/* ************************* FIN AFFFICHAGE ****************** */

/* ******************* AFFICHAGE AVEC CONDITION *************/
void afficher_findcapteur(GtkWidget *liste,char test [20])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char id[20];
	char reference[20];
	char marque[20]; 
	char prix[20];
	char nom[20];
	char service[20];
	int jourofcapteur;
	int moisofcapteur;
	int anneeofcapteur;
	char etat[20];
	capteur c;
	store=NULL;
	FILE *f;
	
	store = gtk_tree_view_get_model(liste);

	if(store==NULL){
	renderer=gtk_cell_renderer_text_new();
   	column=gtk_tree_view_column_new_with_attributes("     ID     ",renderer,"text",ID,NULL);
   	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
   	column=gtk_tree_view_column_new_with_attributes("     Reference     ",renderer,"text",REFERENCE,NULL);
   	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("     Marque     ",renderer,"text",MARQUE,NULL);
   	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
   	column=gtk_tree_view_column_new_with_attributes("     Prix     ",renderer,"text",PRIX,NULL);
   	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("        Nom        ",renderer,"text",NOM,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("             Date d'ajout             ",renderer,"text",DATE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("                        Service                        ",renderer,"text",SERVICE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("  Etat   ",renderer,"text",ETAT,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    
	char text[50];
	f=fopen("capteur.txt","r");
 if(f==NULL){return ;}
else    { 
	
         while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s\n",id,reference,marque,prix,nom,service,&jourofcapteur,&moisofcapteur,&anneeofcapteur,etat)!=EOF)
          {if (strcmp(id,test)==0){ char ch1[20];
	sprintf(text,"%d/%d/%d",jourofcapteur,moisofcapteur,anneeofcapteur);
           gtk_list_store_append(store,&iter);
           gtk_list_store_set(store, &iter, ID, id, REFERENCE, reference, MARQUE, marque, PRIX, prix, NOM, nom, DATE, text, SERVICE, service, ETAT, etat, -1);
          }
        }
   fclose(f);
   gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
   g_object_unref (store);  
   }
}
}
void vider (GtkWidget *liste)
{

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char id[20];
	char reference[20];
	char marque[20]; 
	char prix[20];
	char nom[20];
	char service[20];
	int jourofcapteur;
	int moisofcapteur;
	int anneeofcapteur;
	char etat[20];
	char text[20];
	capteur c;
	store=NULL;
	FILE *f;
	
	store = gtk_tree_view_get_model(liste);

	if(store==NULL){
	renderer=gtk_cell_renderer_text_new();
   	column=gtk_tree_view_column_new_with_attributes("     ID     ",renderer,"text",ID,NULL);
   	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
   	column=gtk_tree_view_column_new_with_attributes("     Reference     ",renderer,"text",REFERENCE,NULL);
   	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("     Marque     ",renderer,"text",MARQUE,NULL);
   	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
   	column=gtk_tree_view_column_new_with_attributes("     Prix     ",renderer,"text",PRIX,NULL);
   	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("        Nom        ",renderer,"text",NOM,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("             Date d'ajout             ",renderer,"text",DATE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("                        Service                        ",renderer,"text",SERVICE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("  Etat   ",renderer,"text",ETAT,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	
	   store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
           gtk_list_store_set(store, &iter, ID, id, REFERENCE, reference, MARQUE, marque, PRIX, prix, NOM, nom, DATE, text, SERVICE, service, ETAT, etat, -1);
   	   gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
}




