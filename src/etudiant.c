#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "etudiant.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>


//
void ajouter_etudiant(etudiant e) 
{
FILE *f ;
f = fopen("etudiant.txt","a+");
if ( f != NULL )
fprintf(f,"%s %s %s %s %s %s \n",e.nom,e.prenom,e.niveau,e.id,e.sexe,e.date) ;
fclose (f) ;
}

//
int suprimer_etudiant(char fichier[],char iden[])
{
FILE *f ;
FILE *p ;
int n = 0 ;
char nom[20] ;
char prenom[20] ;
char niveau[40] ;
char id[10] ;
char sexe[7];
char date[20];
f = fopen(fichier,"a+");
p = fopen("temporaire.txt","a");
if ( f != NULL )
{
while(fscanf(f,"%s %s %s %s %s %s \n",nom,prenom,niveau,id,sexe,date)!=EOF)
{if (strcmp(iden,id) != 0 )
fprintf(p,"%s %s %s %s %s %s \n",nom,prenom,niveau,id,sexe,date);
  else
n=1;
}
fclose(f);
fclose(p);

}
if (n==1)
{
 remove(fichier) ;
 rename("temporaire.txt",fichier) ;
return 1 ;
}
else
remove("temporaire.txt");
return 0 ;
}

//
int modifier_etudiant(char fichier[],etudiant e)
{

FILE *f ;
FILE *p ;
int n = 0 ;
char nm[20] ;
char np[20] ;
char nt[40] ;
char ident[10] ;
char sex[7];
char date[20];
f = fopen(fichier,"a+");
p = fopen("temporaire.txt","a");
if ( f != NULL )
{
while(fscanf(f,"%s %s %s %s %s %s \n",nm,np,nt,ident,sex,date)!=EOF)
{if(strcmp(e.id,ident)!=0)
fprintf(p,"%s %s %s %s %s %s \n",nm,np,nt,ident,sex,date);
  else
{ 
fprintf(p,"%s %s %s %s %s %s \n",e.nom,e.prenom,e.niveau,e.id,e.sexe,e.date);
n=1;
}
}

fclose(f);
fclose(p);
}
 if (n==1)
{
 remove(fichier) ;
 rename("temporaire.txt",fichier) ;
return 1 ;
}
else
{
remove("temporaire.txt") ; 
return 0;
}
}

//

etudiant recherche_am(char fichier[],char x[])
{
int test = 0 ;
etudiant ua;
etudiant vide = {"--","--","--","--","--","--"};
FILE *f ;
char nm[20] ;
char pm[20] ;
char nt[40] ;
char iden[10] ;
char sex[7];
char date[20];
f=fopen(fichier,"a+");
if (f != NULL)
{
while(fscanf(f,"%s %s %s %s %s %s \n",nm,pm,nt,iden,sex,date)!=EOF)
{
if (strcmp(x,iden)==0 )
{strcpy(ua.nom,nm);
 strcpy(ua.prenom,pm);
 strcpy(ua.niveau,nt);
 strcpy(ua.id,iden) ;
 strcpy(ua.sexe,sex);
 strcpy(ua.date,date);
 test = 1 ;
}
}
fclose(f) ;
}
if ( test == 1 )
return(ua); 
else
return (vide);
}

//

enum
{   ENOM,
    EPRENOM,
    ENIVEAU,
    EID,
    ESEXE,
    EDATE,
    COLUMNS,
};

void affichage_am (char fichier[],GtkWidget *liste) 
{
	GtkCellRenderer *renderer ;
	GtkTreeViewColumn *column ;
	GtkTreeIter iter ;
	GtkListStore *store ;

	char nom[20] ;
	char prenom[20] ;
	char niveau[40] ;
	char id [10];
	char sexe[7];
	char date[20];
	store=NULL ;
	FILE *f ;
	store =gtk_tree_view_get_model(liste);
if(store == NULL )
{
renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("niveau",renderer,"text",ENIVEAU,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",EID,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",EDATE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen(fichier,"a+");
if (f != NULL)
{
while(fscanf(f,"%s %s %s %s %s %s \n",nom,prenom,niveau,id,sexe,date) != EOF )
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ENOM,nom,EPRENOM,prenom,ENIVEAU,niveau,EID,id,ESEXE,sexe,EDATE,date,-1);
}
fclose(f) ;
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
g_object_unref(store);
}
}


int verifier_am(char x[])
{

FILE *f;
char nm[20];
char pm[20];
char nt[20];
char id[10];
char sex[7];
char date[20];

f=fopen("etudiant.txt","a+");
if (f !=NULL);
{
while(fscanf(f,"%s %s %s %s %s %s \n",nm,pm,nt,id,sex,date)!=EOF)
{      
if (strcmp(x,id)==0 )
return 1 ;

}
fclose(f) ;
}
return 0 ;
}        



