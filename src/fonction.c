#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include <gtk/gtk.h>
enum
{
      ENOM,
      EPRENOM,
      EID,
      ESEXE,
      EEMAIL,
      EOBJ_REC,
      EDATEN,
      ETEXT_REC,
      ECOLUMNS,
};

/////////////////// fct ajouter_rec //////////////////////////////
void ajouter_rec (reclamation Rec)
{
    FILE *f;
    f=fopen("reclamation.txt","a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s %d/%d/%d %s\n",Rec.nom,Rec.prenom,Rec.id,Rec.sexe,Rec.email,Rec.obj_rec,Rec.D.jour,Rec.D.mois,Rec.D.annee,Rec.text_rec);
    }
    fclose(f);
}
//////////////////// fct find_rec //////////////////////////////
reclamation find_rec (char id[10])
{
    reclamation Rec ;
    FILE *f=NULL;
    f=fopen("reclamation.txt","r");
    while(fscanf(f,"%s %s %s %s %s %s %d/%d/%d %s \n", Rec.nom,Rec.prenom,Rec.id,Rec.sexe,Rec.email,Rec.obj_rec,&Rec.D.jour,&Rec.D.mois,&Rec.D.annee,Rec.text_rec)!=EOF)
    {
        if((strcmp(Rec.id,id)==0))
        {
            return Rec;
        }
    }
 
    fclose(f);  
	return;}
void chercher_rec(GtkWidget *liste,char id_rech[10])
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[20];
        char prenom[20];
        char id[11];
        char sexe[20] ;
        char email[20] ;
        char obj_rec[20] ;
        char daten[20] ;
        char text_rec[1000] ;
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
   if(store == NULL)
   {
        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("Nom         ",renderer,"text",ENOM,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;


        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("Prenom         ",renderer,"text",EPRENOM,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;


        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("Id         ",renderer,"text",EID,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ; 

        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("Sexe            ",renderer,"text",ESEXE,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;


        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("Email               ",renderer,"text",EEMAIL,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("Objet Réclamation          ",renderer,"text",EOBJ_REC,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ; 

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Date Ajout          ",renderer,"text",EDATEN,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	

        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("Texte Réclamation                  ",renderer,"text",ETEXT_REC,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

   }

        store = gtk_list_store_new(ECOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
		f=fopen("reclamation.txt","r");
		if(f==NULL)
		{

			return;
		}
		else
		{

			f=fopen("reclamation.txt","r");
			while(fscanf(f,"%s %s %s %s %s %s %s %s \n",nom,prenom,id,sexe,email,obj_rec,daten,text_rec)!=EOF)
			{
			  if( strcmp(id_rech,id)==0 || strcmp(id_rech,"")==0 )
                          {
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,ENOM,nom,EPRENOM,prenom,EID,id,ESEXE,sexe,EEMAIL,email,EOBJ_REC,obj_rec,EDATEN,daten,ETEXT_REC,text_rec,-1);
                          }
			}
			fclose(f);
			gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
			g_object_unref(store);
		}
}

////////////////////// fct afficher_rec /////////////////////////////


void afficher_rec (GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[20];
        char prenom[20];
        char id[11];
        char sexe[20] ;
        char email[20] ;
        char obj_rec[20] ;
        char daten[20] ;
        char text_rec[1000] ;
	store=NULL;
	FILE *f;
	
	store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("Nom         ",renderer,"text",ENOM,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;


        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("Prenom         ",renderer,"text",EPRENOM,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;


        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("Id         ",renderer,"text",EID,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ; 

        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("Sexe            ",renderer,"text",ESEXE,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;


        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("Email               ",renderer,"text",EEMAIL,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("Objet Réclamation          ",renderer,"text",EOBJ_REC,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ; 

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Date Ajout          ",renderer,"text",EDATEN,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	

        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("Texte Réclamation                  ",renderer,"text",ETEXT_REC,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;
}

store = gtk_list_store_new(ECOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    char texte[200];
    f=fopen("reclamation.txt","r");
    if(f!=NULL)
    {
         while(fscanf(f,"%s %s %s %s %s %s %s %s \n",nom,prenom,id,sexe,email,obj_rec,daten,text_rec)!=EOF)
         {
           gtk_list_store_append(store,&iter);
           gtk_list_store_set(store,&iter,ENOM,nom,EPRENOM,prenom,EID,id,ESEXE,sexe,EEMAIL,email,EOBJ_REC,obj_rec,EDATEN,daten,ETEXT_REC,text_rec,-1);
         }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
        g_object_unref(store);  
    }
}






/////////////////////////// fct supprimer_rec /////////////////////////////
void supprimer_rec(char id[10])
{
    reclamation Rec ;
    FILE *f1;
    FILE *f2;
    f1 = fopen("reclamation.txt","r");
    f2 = fopen("tmp.txt","a");
    while (fscanf(f1,"%s %s %s %s %s %s %d/%d/%d %s \n", Rec.nom,Rec.prenom,Rec.id,Rec.sexe,Rec.email,Rec.obj_rec,&Rec.D.jour,&Rec.D.mois,&Rec.D.annee,Rec.text_rec) != EOF)
    {
        if(strcmp(Rec.id,id)!=0)
        {
            fprintf(f2,"%s %s %s %s %s %s %d/%d/%d %s \n", Rec.nom,Rec.prenom,Rec.id,Rec.sexe,Rec.email,Rec.obj_rec,Rec.D.jour,Rec.D.mois,Rec.D.annee,Rec.text_rec);
        }
    }
    fclose(f1);
    fclose(f2);
    remove("reclamation.txt");
    rename("tmp.txt","reclamation.txt");
}
////////////////////////////// fct idExist //////////////////////////////////
int idExist1(char id_s[10])
{
    reclamation Rec ;
    FILE *f;
    f = fopen("reclamation.txt","r");
    if(f != NULL){
        while(fscanf(f,"%s %s %s %s %s %s %d/%d/%d %s \n", Rec.nom,Rec.prenom,Rec.id,Rec.sexe,Rec.email,Rec.obj_rec,&Rec.D.jour,&Rec.D.mois,&Rec.D.annee,Rec.text_rec) != EOF)
        {
            if(strcmp(Rec.id,id_s) == 0)
            {
                    return 1;
            }
        }
}
    fclose(f);
    return 0;
}

/////////////////////////// fct supprimer_toute_rec /////////////////////////
/* void supprimer_toute_rec(reclamation Rec)
{
    reclamation Rec1 ;
    FILE *f1;
    FILE *f2;
    f1 = fopen("reclamation.txt","r");
    f2 = fopen("tmp.txt","a");
   if (f1==NULL || f2==NULL)
      return ;
   else
   {  
         while (fscanf(f1,"%s %s %s %s %s %s %d %d %d %s \n", Rec.nom,Rec.prenom,Rec.id,Rec.sexe,Rec.email,Rec.obj_rec,&Rec.D.jour,&Rec.D.mois,&Rec.D.annee,Rec.text_rec) != EOF)
         {
            if ( strcmp(Rec.nom,Rec1.nom)!=0 || strcmp(Rec.prenom,Rec1.prenom)!=0 ||
            strcmp(Rec.id,Rec1.id)!=0 || strcmp(Rec.sexe,Rec1.sexe)!=0 ||
            strcmp(Rec.email,Rec1.email)!=0 || strcmp(Rec.obj_rec,Rec1.obj_rec)!=0 ||
            strcmp(Rec.D.jour,Rec1.D.jour)!=0 || strcmp(Rec.D.mois,Rec1.D.mois)!=0 ||
            strcmp(Rec.D.annee,Rec1.D.annee)!=0 || strcmp(Rec.text_rec,Rec1.text_rec)!=0 )
            fprintf(f2,"%s %s %s %s %s %s %d %d %d %s \n", Rec1.nom,Rec1.prenom,Rec1.id,Rec1.sexe,Rec1.email,Rec1.obj_rec,Rec1.D.jour,Rec1.D.mois,Rec1.D.annee,Rec1.text_rec);
        }
        fclose(f1);
        fclose(f2);
   remove("reclamation.txt");
   rename("tmp.txt","reclamation.txt");
   }
}   */
/////////////////////////// fct modifier_rec/////////////////////////////
void modifier_rec (char id[10] ,char text_nouv[1000], char obj[20])
{
    reclamation Rec ;
    FILE *f1;
    FILE *f2;
    f1 = fopen("reclamation.txt","r");
    f2 = fopen("temp.txt","a");
    while(fscanf(f1,"%s %s %s %s %s %s %d/%d/%d %s \n",Rec.nom,Rec.prenom,Rec.id,Rec.sexe,Rec.email,Rec.obj_rec,&Rec.D.jour,&Rec.D.mois,&Rec.D.annee,Rec.text_rec) != EOF)
    {
        if (strcmp(Rec.id,id) == 0)
        {
            strcpy (Rec.text_rec,text_nouv);
	    strcpy(Rec.obj_rec,obj) ;
        }
        fprintf(f2,"%s %s %s %s %s %s %d/%d/%d %s \n",Rec.nom,Rec.prenom,Rec.id,Rec.sexe,Rec.email,Rec.obj_rec,Rec.D.jour,Rec.D.mois,Rec.D.annee,Rec.text_rec);
    }
    fclose(f1);
    fclose(f2);
    remove("reclamation.txt");
    rename("temp.txt","reclamation.txt");
}
//////////////////////// Le service le plus réclamé //////////////////////
int service_plusreclame()
{
    reclamation Rec ;
    //char ch[20] ;
    FILE *f=NULL;
    int restau=0 ;
    int heberg=0 ; 
    int i;
    f=fopen("reclamation.txt","r");
    while(fscanf(f,"%s %s %s %s %s %s %d/%d/%d %s \n", Rec.nom,Rec.prenom,Rec.id,Rec.sexe,Rec.email,Rec.obj_rec,&Rec.D.jour,&Rec.D.mois,&Rec.D.annee,Rec.text_rec)!=EOF)
    {
        if((strcmp(Rec.obj_rec,"Hebergement")==0))
            heberg+=1 ;
        else if((strcmp(Rec.obj_rec,"Restauration")==0))
            restau+=1 ;
    }
    fclose(f);
    i=0;
    if (restau>heberg)
    i=1;
    else 
    i=2;
    return i;
}
///////////////////////////// execution /////////////////////////////////
 /* int main ()
{
    date d= {9,2,2021} ;
    reclamation R= {"Jerbi","Hamdi","200",1,"hamdi@esprit.tn",0,d,"..................."} ;
    ajouter_rec (R) ;
    chercher_rec ("226D5662") ;
    modifier_rec ("200","hhhhhhhhhhhhhhhhhh") ;
    supprimer_rec("216D5962") ;
    afficher_rec () ;
    service_plusreclame()  ;
    return 0 ;
} */

