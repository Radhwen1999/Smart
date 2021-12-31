#include <stdio.h>
#include <stdlib.h>
#include "menufct.h"
#include <gtk/gtk.h>


enum
{
	EID,
	EJOUR,
	EPETIT,
	EDEJEUNER,
	EDINNER,
	ECONS ,
	ECOLUMNS,
};





/////////////////// fct ajouter_menus //////////////////////////////
void ajouter_menu(menu m)
{
    FILE *f=NULL;
    f=fopen("menu.txt","a+");
if(f!=NULL)
{


fprintf(f,"%s %s %s %s %s %s \n",m.menuId,m.jour,m.petit_dejeuner,m.dejeuner,m.dinner,m.consommateur);
}
fclose(f);

}


//////////////////// fct find_menu //////////////////////////////
menu find_m (char id[10])
{
    menu m ;
    FILE *f=NULL;
    f=fopen("menu.txt","r");
    while(fscanf(f,"%s %s %s %s %s %s \n",m.menuId , m.jour , m.petit_dejeuner , m.dejeuner , m.dinner,m.consommateur)!=EOF)
    {
        if((strcmp(m.menuId,id)==0))
        {
            return m;
        }
    }
 
    fclose(f);  
	return ;
}
void chercher_menu(GtkWidget *liste,char id_rech[20])
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char menuId[20];
        char jour[20];
        char petit_dejeuner[20];
        char dejeuner[20] ;
        char dinner[20] ;
	char consommateur [20];
        /*char id [20]; */
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
   if(store == NULL)
   {
        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("       ID du menu       ",renderer,"text",EID,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;


        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("              Date              ",renderer,"text",EJOUR,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;


        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("              Petit Déjeuner              ",renderer,"text",EPETIT,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ; 

        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("              Déjeuner              ",renderer,"text",EDEJEUNER,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;


        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("              Dinner              ",renderer,"text",EDINNER,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("                     Consommateur                     ",renderer,"text",ECONS,NULL) ;
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;


   }

        store = gtk_list_store_new(ECOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
		f=fopen("menu.txt","r");
		if(f==NULL)
		{

			return;
		}
		else
		{

			f=fopen("menu.txt","r");
			while(fscanf(f,"%s %s %s %s %s %s \n",menuId,jour,petit_dejeuner,dejeuner,dinner,consommateur)!=EOF)
			{
			  if( strcmp(id_rech,menuId)==0 || strcmp(id_rech,"")==0 )
                          {
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,EID,menuId,EJOUR,jour,EPETIT,petit_dejeuner,EDEJEUNER,dejeuner,EDINNER,dinner,ECONS,consommateur,-1);
                          }
			}
			fclose(f);
			gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
			g_object_unref(store);
		}
}
////////////////////// fct afficher_menu /////////////////////////////


void afficher_menu (GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
        char menuId[20];
        char jour[20] ;
        char petit_dejeuner[20] ;
        char dejeuner[20] ;
        char dinner[20] ;
      	char consommateur [20];
	store=NULL;
	FILE *f;
	
	store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("       ID du menu       ",renderer,"text",EID,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;


        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("              Date              ",renderer,"text",EJOUR,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;


        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("           Petit Déjeuner           ",renderer,"text",EPETIT,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ; 

        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("           Déjeuner           ",renderer,"text",EDEJEUNER,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;


        renderer = gtk_cell_renderer_text_new () ;
        column = gtk_tree_view_column_new_with_attributes("           Dinner           ",renderer,"text",EDINNER,NULL) ;
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("              Consommateur              ",renderer,"text",ECONS,NULL) ;
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;


}

store = gtk_list_store_new(ECOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    char texte[200];
    f=fopen("menu.txt","r");
    if(f!=NULL)
    {
         while(fscanf(f,"%s %s %s %s %s %s  \n",menuId,jour,petit_dejeuner,dejeuner,dinner,consommateur)!=EOF)
         {
           gtk_list_store_append(store,&iter);
           gtk_list_store_set(store,&iter,EID,menuId,EJOUR,jour,EPETIT,petit_dejeuner,EDEJEUNER,dejeuner,EDINNER,dinner,ECONS,consommateur,-1);
         }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
        g_object_unref(store);  
    }
}
////////////////////////// fct supprimer_menu /////////////////////////////
void supprimer_menu(char id[20])
{
    menu m ;
    FILE *f1;
    FILE *f2;
    f1 = fopen("menu.txt","r");
    f2 = fopen("tmp.txt","a");
    while (fscanf(f1,"%s %s %s %s %s %s \n", m.menuId,m.jour,m.petit_dejeuner,m.dejeuner,m.dinner,m.consommateur) != EOF)
    {
        if(strcmp(m.menuId,id)!=0)
        {
            fprintf(f2,"%s %s %s %s %s %s \n", m.menuId,m.jour,m.petit_dejeuner,m.dejeuner,m.dinner,m.consommateur);
        }
    }
    fclose(f1);
    fclose(f2);
    remove("menu.txt");
    rename("tmp.txt","menu.txt");
}
////////////////////////////// fct idExist //////////////////////////////////
int idExist22(char id_s[20])
{
    menu m ;
    FILE *f;
    f = fopen("menu.txt","r");
    if(f != NULL){
        while(fscanf(f,"%s %s %s %s %s %s \n", m.menuId,m.jour,m.petit_dejeuner,m.dejeuner,m.dinner,m.consommateur) != EOF)
        {
            if(strcmp(m.menuId,id_s) == 0)
            {
                    return 1;
            }
        }
}
    fclose(f);
    return 0;
}


/////////////////////////// fct modifier_menu/////////////////////////////
void modifier_menu (char id[20] ,char nouv_jour[20],char nouv_petit_dejeuner[20]  ,char nouv_dejeuner [20],char nouv_dinner[20])
{
    menu m ;
    FILE *f1;
    FILE *f2;
    f1 = fopen("menu.txt","r");
    f2 = fopen("temp.txt","a");
    while(fscanf(f1,"%s %s %s %s %s %s \n",m.menuId,m.jour,m.petit_dejeuner,m.dejeuner,m.dinner,m.consommateur) != EOF)
    {
        if (strcmp(m.menuId,id) == 0)
        {
            strcpy (m.jour ,nouv_jour) ;
	    strcpy (m.petit_dejeuner , nouv_petit_dejeuner);
	    strcpy (m.dejeuner , nouv_dejeuner);
	    strcpy(m.dinner ,nouv_dinner);
        }
        fprintf(f2,"%s %s %s %s %s %S  \n",m.menuId,m.jour,m.petit_dejeuner,m.dejeuner,m.dinner,m.consommateur);
    }
    fclose(f1);
    fclose(f2);
    remove("menu.txt");
    rename("temp.txt","menu.txt");
}
//////////////////////// Le repas avec moins de dechets //////////////////////
int menu_moinsdechets()
{

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

