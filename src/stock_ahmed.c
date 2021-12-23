#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stock_ahmed.h"
#include <gtk/gtk.h>



void ajouter_ahmed(stock s)
{
    FILE *f=NULL;
    f=fopen("stock.txt","a");
    if (f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s\n",s.id,s.nom,s.quantite,s.val,s.cat);
    }
    fclose(f);
}



stock chercheid_ahmed(char b[])
{
    stock s;
    FILE *f,*g;
    f=fopen("stock.txt","r");
    //g=fopen("cher.txt","a");
    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s",s.id,s.nom,s.quantite,s.val,s.cat)!=EOF)
        {
            if (strcmp(s.id,b)==0)
            {
                return s;
            }
        }
    }
    //fclose(g);
    fclose(f);
}


stock cherchenom_ahmed(char b[])
{
    stock s;
    FILE *f,*g;
    f=fopen("stock.txt","r");
    //g=fopen("cher.txt","a");
    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s",s.id,s.nom,s.quantite,s.val,s.cat)!=EOF)
        {
            if (strcmp(s.nom,b)==0)
            {
                return s;
            }
        }
    }
    //fclose(g);
    fclose(f);
}



stock cherchequan_ahmed(char b[])
{
    stock s;
    FILE *f,*g;
    f=fopen("stock.txt","r");
    //g=fopen("cher.txt","a");
    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s",s.id,s.nom,s.quantite,s.val,s.cat)!=EOF)
        {
            if (strcmp(s.quantite,b)==0)
            {
                return s;
            }
        }
    }
    //fclose(g);
    fclose(f);
}



stock chercheval_ahmed(char b[])
{
    stock s;
    FILE *f,*g;
    f=fopen("stock.txt","r");
    //g=fopen("cher.txt","a");
    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s",s.id,s.nom,s.quantite,s.val,s.cat)!=EOF)
        {
            if (strcmp(s.val,b)==0)
            {
                return s;
            }
        }
    }
    //fclose(g);
    fclose(f);
}



stock cherchecat_ahmed(char b[])
{
    stock s;
    FILE *f,*g;
    f=fopen("stock.txt","r");
    //g=fopen("cher.txt","a");
    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s",s.id,s.nom,s.quantite,s.val,s.cat)!=EOF)
        {
            if (strcmp(s.cat,b)==0)
            {
                return s;
            }
        }
    }
    //fclose(g);
    fclose(f);
}





void cherche_id_ahmed(char b[])
{
    stock s;
    FILE *f,*g;
    remove("cher.txt");
    f=fopen("stock.txt","r");
    g=fopen("cher.txt","a");
    if (f!=NULL)
    {
	while(fscanf(f,"%s %s %s %s %s",s.id,s.nom,s.quantite,s.val,s.cat)!=EOF)
        {
            if (strcmp(s.id,b)==0)
            {
                fprintf(g,"%s %s %s %s %s\n",s.id,s.nom,s.quantite,s.val,s.cat);
            }
        }
        
    }
    fclose(g);
    fclose(f);
}


void cherche_nom_ahmed(char b[])
{
    stock s;
    FILE *f,*g;
    remove("cher.txt");
    f=fopen("stock.txt","r");
    g=fopen("cher.txt","a");
    if (f!=NULL)
    {
	while(fscanf(f,"%s %s %s %s %s",s.id,s.nom,s.quantite,s.val,s.cat)!=EOF)
        {
            if (strcmp(s.nom,b)==0)
            {
                fprintf(g,"%s %s %s %s %s\n",s.id,s.nom,s.quantite,s.val,s.cat);
            }
        }
        
    }
    fclose(g);
    fclose(f);
}


void cherche_quan_ahmed(char b[])
{
    stock s;
    FILE *f,*g;
    remove("cher.txt");
    f=fopen("stock.txt","r");
    g=fopen("cher.txt","a");
    if (f!=NULL)
    {
	while(fscanf(f,"%s %s %s %s %s",s.id,s.nom,s.quantite,s.val,s.cat)!=EOF)
        {
            if (strcmp(s.quantite,b)==0)
            {
                fprintf(g,"%s %s %s %s %s\n",s.id,s.nom,s.quantite,s.val,s.cat);
            }
        }
        
    }
    fclose(g);
    fclose(f);
}


void cherche_val_ahmed(char b[])
{
    stock s;
    FILE *f,*g;
    remove("cher.txt");
    f=fopen("stock.txt","r");
    g=fopen("cher.txt","a");
    if (f!=NULL)
    {
	while(fscanf(f,"%s %s %s %s %s",s.id,s.nom,s.quantite,s.val,s.cat)!=EOF)
        {
            if (strcmp(s.val,b)==0)
            {
                fprintf(g,"%s %s %s %s %s\n",s.id,s.nom,s.quantite,s.val,s.cat);
            }
        }
        
    }
    fclose(g);
    fclose(f);
}


void cherche_type_ahmed(char b[])
{
    stock s;
    FILE *f,*g;
    remove("cher.txt");
    f=fopen("stock.txt","r");
    g=fopen("cher.txt","a");
    if (f!=NULL)
    {
	while(fscanf(f,"%s %s %s %s %s",s.id,s.nom,s.quantite,s.val,s.cat)!=EOF)
        {
            if (strcmp(s.cat,b)==0)
            {
                fprintf(g,"%s %s %s %s %s\n",s.id,s.nom,s.quantite,s.val,s.cat);
            }
        }
        
    }
    fclose(g);
    fclose(f);
}


void supprimer_ahmed(char a[])
{
    stock s;
    FILE *f,*g;
    f=fopen("stock.txt","r");
    g=fopen("temp.txt","a");
    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s",s.id,s.nom,s.quantite,s.val,s.cat)!=EOF)
        {
            if (strcmp(s.id,a)!=0)
            {
                fprintf(g,"%s %s %s %s %s\n",s.id,s.nom,s.quantite,s.val,s.cat);
            }
        
        }
    }
    fclose(f);
    fclose(g);
    remove("stock.txt");
    rename("temp.txt","stock.txt");
}

void modifier_ahmed(stock s)
{
    stock b;
    FILE *f,*g;
    f=fopen("stock.txt","r");
    g=fopen("tmp.txt","a");
    if (f!=NULL)
    {
        while (fscanf(f,"%s %s %s %s %s",b.id,b.nom,b.quantite,b.val,b.cat)!=EOF)
        {
            if (strcmp(s.id,b.id)==0)
            {
                b=s;
            }
            fprintf(g,"%s %s %s %s %s\n",b.id,b.nom,b.quantite,b.val,b.cat);
        }
    }
    fclose(f);
    fclose(g);
    remove("stock.txt");
    rename("tmp.txt","stock.txt");
}







void rupture()
{
    FILE *f;
    stock s;
    f=fopen("stock.txt","r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s",s.id,s.nom,s.quantite,s.val)!=EOF)
        {
            if(strcmp(s.quantite,"0")==0)
            {
                printf("%s %s %s %s\n",s.id,s.nom,s.quantite,s.val);
            }
        }
    }
    fclose(f);
}



enum
{
	ID,
	NOM,
	QUAN,
	VAL,
	CAT,
	COLUMNS,
};	
void treeview_affiche_ahmed(GtkWidget *liste)
{       
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char ch1[200],ch2[200],ch3[200],ch4[200],ch5[200];
store=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("         ID du Produit         ",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("                Nom du Produit                ",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("             Quantite             ",renderer,"text",QUAN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("                    Validite                    ",renderer,"text",VAL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("                Categorie                ",renderer,"text",CAT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
FILE *f=NULL;
f=fopen("stock.txt","r");
if (f!=NULL)
{f=fopen("stock.txt","a+");
while(fscanf(f,"%s %s %s %s %s\n",ch1,ch2,ch3,ch4,ch5)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,ch1,NOM,ch2,QUAN,ch3,VAL,ch4,CAT,ch5,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}


void vider_ahmed(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char ch1[200],ch2[200],ch3[200],ch4[200],ch5[200];
store=NULL;
FILE *f=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("         ID du Produit         ",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("                Nom du Produit                ",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("             Quantite             ",renderer,"text",QUAN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("                    Validite                    ",renderer,"text",VAL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("                Categorie                ",renderer,"text",CAT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}

void affiche_chercher_ahmed(GtkWidget *liste)
{       
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char ch1[200],ch2[200],ch3[200],ch4[200],ch5[200];
store=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("         ID du Produit         ",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("                Nom du Produit                ",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("             Quantite             ",renderer,"text",QUAN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("                    Validite                    ",renderer,"text",VAL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("                Categorie                ",renderer,"text",CAT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
FILE *f=NULL;
f=fopen("cher.txt","r");
if (f!=NULL)
{f=fopen("cher.txt","a+");
while(fscanf(f,"%s %s %s %s %s\n",ch1,ch2,ch3,ch4,ch5)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,ch1,NOM,ch2,QUAN,ch3,VAL,ch4,CAT,ch5,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}













void rechercher_stock(GtkWidget *liste,char rech[])
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
char ch1[200],ch2[200],ch3[200],ch4[200],ch5[200];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store == NULL)
	{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("         ID du Produit         ",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("                Nom du Produit                ",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("             Quantite             ",renderer,"text",QUAN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("                    Validite                    ",renderer,"text",VAL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("                Categorie                ",renderer,"text",CAT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);
		f=fopen("stock.txt","r");
		if(f==NULL)
		{

			return;
		}
		else
		{

			f=fopen("stock.txt","r");
			while(fscanf(f,"%s %s %s %s %s\n",ch1,ch2,ch3,ch4,ch5)!=EOF)
			{
				if(strcmp(rech,ch1)==0 ||strcmp(rech,ch2)==0||strcmp(rech,"")==0 )
				{
					gtk_list_store_append(store,&iter);
					gtk_list_store_set(store,&iter,ID,ch1,NOM,ch2,QUAN,ch3,VAL,ch4,CAT,ch5,-1);
				}
			}
			fclose(f);
			gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
			g_object_unref(store);
		}
	}
}


