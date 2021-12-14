#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <capteur.h>
#include "etudiant.h"
#include "fonction.h"
#include "email.h"
#include "users.h"
#include "stock_ahmed.h"
#include "menufct.h"
#include "etudiant1.h"

/************ ACCEUIL ****************/
void
on_EXTRA_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *winadd;
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"acceuil");
    	winadd=create_windowextras();
    	gtk_widget_show(winadd);
    	gtk_widget_destroy(winmen);
}


void
on_STOCK_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *winadd;
    	GtkWidget *winmen;
	char texte[100];
	GtkWidget *output;

    	winmen=lookup_widget(objet,"acceuil");
    	winadd=create_stock_ab();
    	
    	
user u;
GtkWidget *treeview1_ahmed;


FILE *f;
	f=fopen("role_ahmed.txt","r");
	fscanf(f,"%s %s %s %s %s\n",u.espritId,u.nom,u.prenom,u.password,u.role);	
if(strcmp("AGENT_DE_FOYER",u.role)==0 ||strcmp("ADMIN",u.role)==0 ){
gtk_widget_destroy(winmen);
gtk_widget_show(winadd);
treeview1_ahmed=lookup_widget(winadd,"treeview1_ahmed");

vider_ahmed(treeview1_ahmed);
treeview_affiche_ahmed(treeview1_ahmed);
GtkWidget *combobox1_ahmed;
  combobox1_ahmed=lookup_widget(winadd,"combobox1_ahmed");
  gtk_combo_box_set_active(GTK_COMBO_BOX(combobox1_ahmed),0);
}

else{sprintf(texte,"Accées Refusé");
		output = lookup_widget(objet,"labelespace");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);
}

}


void
on_HEBERGEMENT_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input,*input1;
input1=lookup_widget(objet,"acceuil");

char texte[100];
GtkWidget *output;

user u;
char fichier[]={"etudiant.txt"};
GtkWidget *input3,*input4,*treeview1;
input3=create_GestionEtudiants_am ();
FILE *f;
	f=fopen("role_ahmed.txt","r");
	fscanf(f,"%s %s %s %s %s\n",u.espritId,u.nom,u.prenom,u.password,u.role);
	if(strcmp("AGENT_DE_FOYER",u.role)==0 ||strcmp("ADMIN",u.role)==0 ){
gtk_widget_show(input3);
gtk_widget_destroy(input1);
treeview1=lookup_widget(input3,"treeview1_0_am");
affichage_am(fichier,treeview1);}
else{sprintf(texte,"Accées Refusé");
		output = lookup_widget(objet,"labelespace");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);
}
}



void
on_CAPTEUR_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	user u;
	char texte[100];
	GtkWidget *output;
	GtkWidget *window;
	GtkWidget *window2;
	GtkWidget *treeview;
	window = lookup_widget(objet,"acceuil");
	window2 = create_gestcap ();
	FILE *f;
	f=fopen("role_ahmed.txt","r");
	fscanf(f,"%s %s %s %s %s\n",u.espritId,u.nom,u.prenom,u.password,u.role);
	if(strcmp("TECHNICIEN",u.role)==0 ||strcmp("ADMIN",u.role)==0){
	gtk_widget_destroy(window);
	gtk_widget_show(window2);	
	treeview = lookup_widget(window2,"treeviewcap");	
	afficher_capteur(treeview);
	}
	else{sprintf(texte,"Accées Refusé");
		output = lookup_widget(objet,"labelespace");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);
}

}


void
on_UTILISATEUR_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{

	
user u;
char texte[100];
GtkWidget *output;
GtkWidget *fenetre_afficher,*w1;
GtkWidget *treeview1;
w1=lookup_widget(objet,"acceuil");
fenetre_afficher=create_gestion_des_utilisateurs();
FILE *f;
f=fopen("role_ahmed.txt","r");
fscanf(f,"%s %s %s %s %s\n",u.espritId,u.nom,u.prenom,u.password,u.role);
if(strcmp("ADMIN",u.role)==0){
gtk_widget_show(fenetre_afficher);
gtk_widget_destroy(w1);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher_user(treeview1);}
else{sprintf(texte,"Accées Refusé");
		output = lookup_widget(objet,"labelespace");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);

}

}

void
on_RESTAURATION_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	user u;
	char texte[100];
	GtkWidget *output;
	GtkWidget *window;
	GtkWidget *window2;
	GtkWidget *treeview;
	window = lookup_widget(objet,"acceuil");
	window2 = create_gestion_des_menus ();
	FILE *f;
	f=fopen("role_ahmed.txt","r");
	fscanf(f,"%s %s %s %s %s\n",u.espritId,u.nom,u.prenom,u.password,u.role);
	if(strcmp("NUTRISIONNISTE",u.role)==0 ||strcmp("ADMIN",u.role)==0){
	gtk_widget_destroy(window);
	gtk_widget_show(window2);	
	treeview = lookup_widget(window2,"treeview22");	
	afficher_menu(treeview);
	}
	else{sprintf(texte,"Accées Refusé");
		output = lookup_widget(objet,"labelespace");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);
}
	
}


void
on_RECLAMATION_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *window3;
        GtkWidget *treeview2;
	user u;
	window2 = lookup_widget(objet,"acceuil");
	window1=create_Tree_view ();
	window3=create_ajouter_rec();
	FILE *f;
	f=fopen("role_ahmed.txt","r");
	fscanf(f,"%s %s %s %s %s\n",u.espritId,u.nom,u.prenom,u.password,u.role);
	if(strcmp("ADMIN",u.role)==0 ||strcmp("ADMIN",u.role)==0){
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
	treeview2=lookup_widget(window1,"treeview2") ;
        afficher_rec(treeview2) ;}
	else{gtk_widget_show (window3);
	gtk_widget_destroy(window2);}

        
}
/*************************** CAPTEUR RADHWEN *********************/



int w=1;
int z=1;
int *i=0;



void
on_radiobuttontemp_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        w = 1;
	}
}

void
on_radiobuttonmouv_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        w = 2;
	}
}




void
on_radiobuttonfum_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        w = 4;
	}
}


void
on_radiobuttondeb_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        w = 3;
	}
}


void
on_buttonconfirmadd_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;
	GtkWidget *input8;
	GtkWidget *output;
	GtkWidget *output1;

	
	int p;

	char texte[200];

	capteur c;

	input1=lookup_widget(objet,"entryidcap");
	input2=lookup_widget(objet,"entryrefcap");
	input3=lookup_widget(objet,"entrymarquecap");
	input4=lookup_widget(objet,"entryprixcap");
	input5=lookup_widget(objet,"entrynomcap");
	input6=lookup_widget(objet,"spinbutton1");
	input7=lookup_widget(objet,"spinbutton2");
	input8=lookup_widget(objet,"spinbutton3");
	
	


	if (w== 1){
		strcpy(c.service,"Temperature");
	}
	else if(w== 2){
		strcpy(c.service,"Mouvement");
	}
	else if(w== 3){
		strcpy(c.service,"Débit");
	}
	else if(w==4){
		strcpy(c.service,"Fumée");
	}

	
	
	strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(c.prix,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(c.nomdecapteur,gtk_entry_get_text(GTK_ENTRY(input5)));
	c.jourofcapteur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
	c.moisofcapteur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
	c.anneeofcapteur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
	strcpy(c.etat,"🆕");
	
	p=idExist(c.id);
	output1 = lookup_widget(objet,"labelid");
	if(!p){
		ajouter_capteur(c);
		gtk_label_set_text(GTK_LABEL(output1),"✔️ \n Cet un nouvel id");
		sprintf(texte,"Capteur ajouté avec succés");
		output = lookup_widget(objet,"outputaddcap");
		GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);}
	else{
		gtk_label_set_text(GTK_LABEL(output1),"❌ \n id existant");
		sprintf(texte,"Verfier vos données !");
		output = lookup_widget(objet,"outputaddcap");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);}	
	
}


void
on_buttonretadd_clicked                (GtkWidget         *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"addcap");
	window2 = create_gestcap ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
	GtkWidget *treeview;
	treeview = lookup_widget(window2,"treeviewcap");
	afficher_capteur(treeview);
}




void
on_buttonaddcap_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window1;
	GtkWidget *window2;
	window2 = lookup_widget(objet,"gestcap");
	window1=create_addcap();
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


/***************** SUPPRIMER *********************/
void
on_buttondelconfirm_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *input;
	GtkWidget *output;
	char id[20];
	char texte[100];

	input = lookup_widget(objet_graphique,"entryiddel");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
	
	if(idExist(id)){
		supprimer_capteur(id);		
		sprintf(texte,"Votre suppression à été effectué avec succés\n");
		output = lookup_widget(objet_graphique,"labeldelmsg");
		GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);
		
		
	}
	else{
		sprintf(texte,"Cet id n'existe pas\n");
		output = lookup_widget(objet_graphique,"labeldelmsg");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);	
	} 
}

/****************************** RETURN SUPPRIMER **************************/
void
on_buttonretdel_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"delcap");
	window2 = create_gestcap ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
	GtkWidget *treeview; 
	treeview = lookup_widget(window2,"treeviewcap");
	afficher_capteur(treeview);

}


void
on_buttondelcap_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"gestcap");
	window2 = create_delcap ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);	
}

/* ********************** TREE VIEW RADIO **************/
void
on_treeviewcap_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter Iter;	
	gchar* id;	
	gchar* reference;
	gchar* marque;
	gchar* prix;
	gchar* nom;
	gchar* date;
	gchar* service;
	gchar* etat;

	char num_id[20];	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	
	if(gtk_tree_model_get_iter(model,&Iter,path)){
		gtk_tree_model_get(GTK_LIST_STORE(model),&Iter,0, &id, 1, &reference, 2, &marque, 3, &prix, 4, &nom, 5, &date, 6, &service, 7, &etat, -1);
		
		strcpy(num_id,id);
		supprimer_capteur(id);
		afficher_capteur(treeview);
	}
}

/* *************** FIN TREE VIEW RADIO *************/
void
on_radiobuttonmouvedit_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        z = 2;
	}
}


void
on_buttonconsultid_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	char id[20];
	GtkWidget *input1;
	input1 = lookup_widget(objet,"entryconsultid");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));

	char texte1[20],texte2[20],texte3[20];
	char outputmessage[100];
	GtkWidget *outputmarque;
	GtkWidget *outputservice;
	GtkWidget *outputref;
	GtkWidget *outputnom;
	GtkWidget *output10;
	GtkWidget *tg1 ,*tg2, *tg3,*tg4;
	GtkWidget *outputt;
	if(idExist(id)==0){
		sprintf(outputmessage,"Ce capteur n'existe pas\n");
		output10 = lookup_widget(objet,"outputeditcap");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output10, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output10),outputmessage);	
	}
	else{
		capteur c;
		strcpy(c.marque,find_cap(id).marque);
		strcpy(c.nomdecapteur,find_cap(id).nomdecapteur);
		strcpy(c.reference,find_cap(id).reference);
		strcpy(c.service,find_cap(id).service);
		tg1=lookup_widget(objet,"radiobuttontempedit");
		tg2=lookup_widget(objet,"radiobuttonmouvedit");
		tg3=lookup_widget(objet,"radiobuttondebedit");
		tg4=lookup_widget(objet,"radiobuttonfumedit");
		if(strcmp(c.service,"Temperature")==0){gtk_toggle_button_set_active(GTK_RADIO_BUTTON (tg1),TRUE);gtk_label_set_text(GTK_LABEL(outputt),"");}
		if(strcmp(c.service,"Mouvement")==0){gtk_toggle_button_set_active(GTK_RADIO_BUTTON (tg2),TRUE);gtk_label_set_text(GTK_LABEL(outputt),"");}
		if(strcmp(c.service,"Débit")==0){gtk_toggle_button_set_active(GTK_RADIO_BUTTON (tg3),TRUE);gtk_label_set_text(GTK_LABEL(outputt),"");}
		if(strcmp(c.service,"Fumée")==0){gtk_toggle_button_set_active(GTK_RADIO_BUTTON (tg4),TRUE);gtk_label_set_text(GTK_LABEL(outputt),"");}
		sprintf(outputmessage,"Tapez vos nouveau donnée puis cliquez sur\n\tenregistrer les modifications\n");
		output10 = lookup_widget(objet,"outputeditcap");
		GdkColor color;
		gdk_color_parse ("#0c8ae8", &color);
		gtk_widget_modify_fg (output10, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output10),outputmessage);		

		sprintf(texte1,"%s",c.marque);
		outputmarque = lookup_widget(objet,"entrymaredit");
    		gtk_entry_set_text(GTK_ENTRY(outputmarque),texte1);

		sprintf(texte2,"%s",c.nomdecapteur);
		outputnom = lookup_widget(objet,"entrynomedit");
    		gtk_entry_set_text(GTK_ENTRY(outputnom),texte2);
		
		sprintf(texte3,"%s",c.reference);
		outputref = lookup_widget(objet,"entryrefedit");
    		gtk_entry_set_text(GTK_ENTRY(outputref),texte3);


	}
}


void
on_buttonretedit_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"editcap");
	window2 = create_gestcap ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
	GtkWidget *treeview;
	treeview = lookup_widget(window2,"treeviewcap");
	afficher_capteur(treeview);}

/* ****************  Sauvegarder Les changements ******************/
void
on_buttonsavevhange_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *input0;
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *output2;
	GtkWidget *output3;
	GtkWidget *output4;
	GtkWidget *choix;
	GtkWidget *def;

	GtkWidget *output10;
	int o,u;

	char id[20];

	char outputmessage[100];
	input0 = lookup_widget(objet,"entryconsultid");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input0)));
	if(!idExist(id)){
		sprintf(outputmessage,"Ce Capteur n'existe pas\n");
		output10 = lookup_widget(objet,"outputeditcap");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output10, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output10),outputmessage);	
	}
	else{	
		capteur c;
		
		strcpy(c.id,id);
		input1 = lookup_widget(objet,"entrymaredit");
		input2 = lookup_widget(objet,"entrynomedit");
		input3 = lookup_widget(objet,"entryrefedit");
		

		if (z==1){
		strcpy(c.service,"Temperature");
}
		else if(z==2){
		strcpy(c.service,"Mouvement");
}
		else if(z==3){
		strcpy(c.service,"Débit");
}		
		else if(z==4){
		strcpy(c.service,"Fumée");
}	
		char ch[20];
		char ch1[20];
		choix = lookup_widget(objet,"comboboxentry1");
		c.jourofcapteur = find_cap(id).jourofcapteur;
		c.moisofcapteur = find_cap(id).moisofcapteur;
		c.anneeofcapteur = find_cap(id).anneeofcapteur;
		strcpy(c.prix,find_cap(id).prix);
		/*strcpy(c.etat,find_cap(id).etat);*/
		strcpy(ch,gtk_combo_box_get_active_text(GTK_COMBO_BOX(choix)));
		if (strcmp(ch,"diffectueux")==0){strcpy(c.etat,"⛔");}
		else strcpy(c.etat,"🔵");		
		strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(input1)));
		strcpy(c.nomdecapteur,gtk_entry_get_text(GTK_ENTRY(input2)));
		strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(input3)));
		def = lookup_widget(objet,"checkbutton1");
		char ch5[200]; strcpy(ch5,"Capteur_Temp_defectueux");
		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(def)) && strcmp(c.service,"Temperature")==0) {strcpy(c.service,ch5);}
		modifier_capteur(c);
		sprintf(outputmessage,"Votre modification a été effectué avec succés\n");
		output10 = lookup_widget(objet,"outputeditcap");
		GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (output10, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output10),outputmessage);	
		

		char reset[20];
		sprintf(reset,"");
		gtk_entry_set_text(GTK_ENTRY(input1),reset);
		gtk_entry_set_text(GTK_ENTRY(input2),reset);
		gtk_entry_set_text(GTK_ENTRY(input3),reset);
		}
}
/* ****************** Fin sauvegarde changements ****************/

void
on_radiobuttonfumedit_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        z = 4;
	}
}


void
on_radiobuttontempedit_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        z = 1;
	}
}


void
on_radiobuttondebedit_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        z = 3;
	}
}


void
on_buttoneditcap_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"gestcap");
	window2 = create_editcap ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_buttonrefresh_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window;
	GtkWidget *window2;
	GtkWidget *treeview;
	window = lookup_widget(objet,"gestcap");
	window2 = create_gestcap ();
	gtk_widget_destroy(window);
	gtk_widget_show(window2);	
	treeview = lookup_widget(window2,"treeviewcap");	
	afficher_capteur(treeview);
}


void
on_buttonfindcap_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window;
	GtkWidget *window2;
	GtkWidget *treeview;
	GtkWidget *output10;
	window = lookup_widget(objet,"gestcap");
	window2 = create_findcap ();
	gtk_widget_destroy(window);
	gtk_widget_show(window2);
	
}


void
on_buttonfindok_clicked                (GtkWidget       *objet,
                                        gpointer         user_data )
{
	char id[20];
	GtkWidget *input1;
	input1 = lookup_widget(objet,"entryidfind");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));

	char texte1[20],texte2[20],texte3[20];
	char outputmessage[100];
	GtkWidget *outputmarque;
	GtkWidget *outputservice;
	GtkWidget *outputref;
	GtkWidget *outputnom;
	GtkWidget *output10;
	GtkWidget *outputt;
	GtkWidget *window2;
	GtkWidget *window3;
	GtkTreeView     *treeview;
	
	if(idExist(id)==0){
		
		sprintf(outputmessage,"CE CAPTEUR n'existe pas\n");
		output10 = lookup_widget(objet,"labelfindcap");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output10, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output10),outputmessage);
		window2 =lookup_widget(objet,"findcap");
		treeview=lookup_widget(window2,"treeviewfind");
		vider(treeview);
		
			
	}
	
	else{
		capteur c;
		
		sprintf(outputmessage,"Ce capteur existe\n Voici ses caractéristiques\n");
		output10 = lookup_widget(objet,"labelfindcap");
		GdkColor color;
		gdk_color_parse ("#0c8ae8", &color);
		gtk_widget_modify_fg (output10, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output10),outputmessage);
		window2 =lookup_widget(objet,"findcap");
		gtk_widget_show(window2);
		treeview=lookup_widget(window2,"treeviewfind");
		afficher_findcapteur(treeview,id);
}
}


void
on_treeviewfind_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter Iter;	
	gchar* id;	
	gchar* reference;
	gchar* marque;
	gchar* prix;
	gchar* nom;
	gchar* date;
	gchar* service;
	gchar* etat;

	char num_id[20];	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	
	if(gtk_tree_model_get_iter(model,&Iter,path)){
		gtk_tree_model_get(GTK_LIST_STORE(model),&Iter,0, &id, 1, &reference, 2, &marque, 3, &prix, 4, &nom, 5, &date, 6, &service, 7, &etat, -1);
		
		strcpy(num_id,id);
		supprimer_capteur(id);
		afficher_capteur(treeview);
	}
}



void
on_buttonretfind_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window;
	GtkWidget *window2;
	GtkWidget *treeview;
	window = lookup_widget(objet,"findcap");
	window2 = create_gestcap ();
	gtk_widget_destroy(window);
	gtk_widget_show(window2);	
	treeview = lookup_widget(window2,"treeviewcap");	
	afficher_capteur(treeview);
}


void
on_buttonotherfind_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{		
		
		GtkWidget *window2;
		GtkWidget *window3;
		window2 =lookup_widget(objet,"findcap");
		window3=create_findcap();
		gtk_widget_show(window3);
		gtk_widget_hide(window2);
}


void
on_Retourcapacceuil_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *window1;
	GtkWidget *window2;
	window2 = lookup_widget(objet,"gestcap");
	window1=create_acceuil ();
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);

}

/************************ FIN CAPTEUR *******************/


/************************* Etudiant Ashraf **********************/


char iden_am[20];
char ident_am[20];
int m_am;
int w_am; 
int y_am=0;
int z_am=0;

etudiant etud;
void
on_treeview1_am_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom ;
gchar* prenom;
gchar* niveau;
gchar* id;
gchar* sexe;
gchar* date;
etudiant e;

char fichier[]={"etudiant.txt"};

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&niveau,3,&id,4,&sexe,5,&date,-1);

strcpy(e.id,id);
strcpy(e.nom,nom);
strcpy(e.prenom,prenom);
strcpy(e.niveau,niveau);
strcpy(e.sexe,sexe);
strcpy(e.date,date);


affichage_am(fichier,treeview);
}

}


gboolean
on_treeview1_am_select_cursor_row         (GtkTreeView     *treeview,
                                        gboolean         start_editing,
                                        gpointer         user_data)
{

  return FALSE;
}




void
on_button9Display0_am_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
char fichier[]={"etudiant.txt"};
GtkWidget *input,*input1,*treeview1;
input=lookup_widget(objet,"GestionEtudiants_am");
input=create_GestionEtudiants_am ();
gtk_widget_show(input);
input1=lookup_widget(objet,"GestionEtudiants_am");
gtk_widget_destroy(input1);
gtk_widget_show(input);
treeview1=lookup_widget(input,"treeview1_0_am");
affichage_am(fichier,treeview1);
}



void
on_button1Add0_am_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *input,*input1;
input=lookup_widget(objet,"AjouterEtudiant_am");
input=create_AjouterEtudiant_am();
gtk_widget_show(input);
input1=lookup_widget(objet,"GestionEtudiants_am");
gtk_widget_destroy(input1);
}


void
on_button2Modify0_am_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2,*input2,*output5,*output6;

char fichierr[]={"etudiant.txt"};
char x [10];
int s ;
int n=0 ;
etudiant e;


window1=lookup_widget(objet,"GestionEtudiants_am");
input2=lookup_widget(objet,"entry10Modify0_am");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(input2)));
s=verifier_am(x);
while((strcmp(x,"")!=0)&&(n==0))
{
if ( s==0)
{
output5 = lookup_widget(objet,"label37_am") ;
gtk_label_set_text(GTK_LABEL(output5),"etudiant introuvable");
n=1;
}
else
{
window2=lookup_widget(objet,"ModifierEtudiant_am");
window2=create_ModifierEtudiant_am();
gtk_widget_show(window2);
gtk_widget_destroy(window1);
strcpy(iden_am,x);
n=1;
}
}
if(n==0)
{
output6 = lookup_widget(objet,"label37_am") ;
gtk_label_set_text(GTK_LABEL(output6),"il faut donner identifiant");
}

}


void
on_button3Delete_am_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_ajouter,*input2,*output,*output1;
GtkWidget *input,*input1,*input3;

char fichierr[]={"etudiant.txt"};
char x [10];
int s ;
int n=0 ;

window_ajouter=lookup_widget(objet,"GestionEtudiants_am");
input2=lookup_widget(objet,"entry11Delete0_am");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(input2)));
s=verifier_am(x);
while((strcmp(x,"")!=0)&&(n==0))
{
if (s==0)
{
output = lookup_widget(objet,"label36_am") ;
gtk_label_set_text(GTK_LABEL(output),"etudiant introuvable");
n=1;
}
else
{

input3=lookup_widget(objet,"ConfirmerSupression_am");
input3=create_ConfirmerSupression_am ();
gtk_widget_show(input3);
input1=lookup_widget(objet,"GestionEtudiants_am");
gtk_widget_destroy(input1);
n=1;
strcpy(ident_am,x);
}
}
if(n==0)
{
output1 = lookup_widget(objet,"label36_am") ;
gtk_label_set_text(GTK_LABEL(output1),"il faut donner identifiant");
}
}



void
on_button4Search0_am_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_ajouter,*input2,*treeview1;

char fichier[]={"test.txt"};
char fichier1[]={"etudiant.txt"};
char x [10];
etudiant e ;


window_ajouter=lookup_widget(objet,"GestionEtudiants_am");
input2=lookup_widget(objet,"entry1Search0_am");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(input2)));
e=recherche_am(fichier1,x);

FILE *f;
f = fopen(fichier,"a+");
if ( f != NULL )
fprintf(f,"%s %s %s %s %s %s \n",e.nom,e.prenom,e.niveau,e.id,e.sexe,e.date) ;
fclose (f) ;


GtkWidget *input,*input1;
input=lookup_widget(objet,"GestionEtudiants_am");
input=create_GestionEtudiants_am();
gtk_widget_show(input);
input1=lookup_widget(objet,"GestionEtudiants_am");
gtk_widget_destroy(input1);
gtk_widget_show(input);
treeview1=lookup_widget(input,"treeview1_0_am");
affichage_am(fichier,treeview1);
remove(fichier);
}



void
on_button5Back1_am_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *input,*input1;
input1=lookup_widget(objet,"AjouterEtudiant_am");
gtk_widget_destroy(input1);




char fichier[]={"etudiant.txt"};
GtkWidget *input3,*input4,*treeview1;
input3=lookup_widget(objet,"GestionEtudiants_am");
input3=create_GestionEtudiants_am ();
gtk_widget_show(input3);
input4=lookup_widget(objet,"GestionEtudiants_am");
gtk_widget_destroy(input4);
gtk_widget_show(input3);
treeview1=lookup_widget(input3,"treeview1_0_am");
affichage_am(fichier,treeview1);
}



void
on_button6Add1_am_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *spinbutton1, *spinbutton2 , *spinbutton3 ;
GtkWidget *input1, *input2,*input3,*input4,*output,*output1,*output2;
GtkWidget *window_ajouter,*combobox1;
etudiant e;
int test ;
int n = 0 ;
char texte1[7]="Homme";
char texte2[7]="Femme";
combobox1=lookup_widget(objet_graphique,"combobox1Sexe1_am");
window_ajouter=lookup_widget(objet_graphique,"AjouterEtudiant_am");
input1=lookup_widget(objet_graphique,"entry2Name1_am");
input2=lookup_widget(objet_graphique,"entry3Prenom1_am");
input3=lookup_widget(objet_graphique,"entry4umTel1_am");
input4=lookup_widget(objet_graphique,"entry5ID1_am");
if(strcmp(texte1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
strcpy(e.sexe,texte1);
if(strcmp(texte2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
strcpy(e.sexe,texte2);
strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(e.niveau,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(input4)));

int a,b,c;
char a1[20];
char b1[5];
char c1[5];
spinbutton1=lookup_widget(objet_graphique,"spinbutton2DS_am");
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1));

spinbutton2=lookup_widget(objet_graphique,"spinbutton3DS_am");
b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton2));

spinbutton3=lookup_widget(objet_graphique,"spinbutton4DS_am");
c=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton3));


sprintf(a1,"%d",a);
sprintf(b1,"%d",b);
sprintf(c1,"%d",c);
char sl[5]="/";
strcat(a1,sl);
strcat(a1,b1);
strcat(a1,sl);
strcat(a1,c1);

strcpy(e.date,a1);


test = verifier_am(e.id);
while((strcmp(e.nom,"")!=0)&&(strcmp(e.prenom,"")!=0)&&(strcmp(e.niveau,"")!=0)&&(strcmp(e.id,"")!=0)&&(n==0))
{
if(test==1)
{
output = lookup_widget(objet_graphique,"label7msg_am") ;
gtk_label_set_text(GTK_LABEL(output),"etudiant deja existant");
n=1;
}
else
{
etud=e ;
GtkWidget *input0,*input00;
input0=lookup_widget(objet_graphique,"ConfirmerAjout_am");
input0=create_ConfirmerAjout_am();
gtk_widget_show(input0);
input00=lookup_widget(objet_graphique,"AjouterEtudiant_am");
gtk_widget_destroy(input00);
n=1;

}
}
if(n==0)
{
output2=lookup_widget(objet_graphique,"label7msg_am");
gtk_label_set_text(GTK_LABEL(output2),"informations manquantes");
}
}


void
on_button12Modify_am_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*input5,*output1,*output2,*output3;
GtkWidget *window3;

etudiant x;
int m ;
int test ;
int n=0;
char fichierr[]={"etudiant.txt"};
char text1[6]="Homme";
char text2[6]="Femme";
window3=lookup_widget(objet,"ModifierEtudiant_am");
if(y_am==1)
strcpy(x.sexe,text1);
if(y_am==2)
strcpy(x.sexe,text2);


input1=lookup_widget(objet,"entry6Name2_am");
input2=lookup_widget(objet,"entry7Prenom2_am");
input3=lookup_widget(objet,"entry9ID2_am");
input4=lookup_widget(objet,"entry8NumTel2_am");
input5=lookup_widget(objet,"entry99_am");


strcpy(x.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(x.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(x.id,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(x.niveau,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(x.date,gtk_entry_get_text(GTK_ENTRY(input5)));



test = verifier_am(x.id);

while((strcmp(x.nom,"")!=0)&&(strcmp(x.prenom,"")!=0)&&(strcmp(x.niveau,"")!=0)&&(strcmp(x.id,"")!=0)&&(n==0))
{
if (test==1)
{

m =modifier_etudiant(fichierr,x);
output1 = lookup_widget(objet,"label35_am") ;
gtk_label_set_text(GTK_LABEL(output1),"Etudiant modifié avec succées");
n=1;
}
else
{
output2 = lookup_widget(objet,"label35_am") ;
gtk_label_set_text(GTK_LABEL(output2),"Identifiant non existant");
n=1;
}
}
if(n==0)
{
output3 = lookup_widget(objet,"label35_am") ;
gtk_label_set_text(GTK_LABEL(output3),"informations manquantes");
}
}



void
on_button8Back2_am_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *input,*input1;
input1=lookup_widget(objet,"ModifierEtudiant_am");
gtk_widget_destroy(input1);


char fichier[]={"etudiant.txt"};
GtkWidget *input3,*input4,*treeview1;
input3=lookup_widget(objet,"GestionEtudiants_am");
input3=create_GestionEtudiants_am ();
gtk_widget_show(input3);
input4=lookup_widget(objet,"GestionEtudiants_am");
gtk_widget_destroy(input4);
gtk_widget_show(input3);
treeview1=lookup_widget(input3,"treeview1_0_am");
affichage_am(fichier,treeview1);
}


void
on_radiobutton3_am_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{y_am=1;}
}


void
on_radiobutton4_am_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{y_am=2;}
}

void
on_button10Displaymod2_am_clicked      (GtkButton       *objet,
                                        gpointer         user_data)
{
	
	char texte1[20],texte2[20],texte3[20],texte4[20],texte5[20];
	char outputmessage[100];
	GtkWidget *outputid;
	GtkWidget *outputprenom;
	GtkWidget *outputdate;
	GtkWidget *outputnom;
	GtkWidget *outputniveau;
	GtkWidget *output10;
	GtkWidget *tg1 ,*tg2;
	GtkWidget *outputt;
	
	etudiant e;
	char fichier[]={"etudiant.txt"};
	e=recherche_am(fichier,iden_am);
	tg1=lookup_widget(objet,"radiobutton3_am");
	tg2=lookup_widget(objet,"radiobutton4_am");
	if(strcmp(e.sexe,"Homme")==0){gtk_toggle_button_set_active(GTK_RADIO_BUTTON (tg1),TRUE);gtk_label_set_text(GTK_LABEL(outputt),"");}
	if(strcmp(e.sexe,"Femme")==0){gtk_toggle_button_set_active(GTK_RADIO_BUTTON (tg2),TRUE);gtk_label_set_text(GTK_LABEL(outputt),"");}
	sprintf(outputmessage,"Tapez vos nouveau donnée puis cliquez sur\n\tModifier\n");
	output10 = lookup_widget(objet,"label33_am");
    	gtk_label_set_text(GTK_LABEL(output10),outputmessage);		

	sprintf(texte1,"%s",e.id);
	outputid = lookup_widget(objet,"entry9ID2_am");
    	gtk_entry_set_text(GTK_ENTRY(outputid),texte1);

	sprintf(texte2,"%s",e.nom);
	outputnom = lookup_widget(objet,"entry6Name2_am");
    	gtk_entry_set_text(GTK_ENTRY(outputnom),texte2);
		
	sprintf(texte3,"%s",e.prenom);
	outputprenom = lookup_widget(objet,"entry7Prenom2_am");
   	gtk_entry_set_text(GTK_ENTRY(outputprenom),texte3);

	sprintf(texte4,"%s",e.date);
	outputdate = lookup_widget(objet,"entry99_am");
    	gtk_entry_set_text(GTK_ENTRY(outputdate),texte4);

	sprintf(texte5,"%s",e.niveau);
	outputniveau = lookup_widget(objet,"entry8NumTel2_am");
    	gtk_entry_set_text(GTK_ENTRY(outputniveau),texte5);


}


void
on_radiobutton55_am_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{z_am=1;}
}

void
on_radiobutton66_am_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{z_am=2;}
}


void
on_button13ValiderAj_am_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
int n = 0 ;
while((m_am!=w_am)&&(n==0))
{
if(w_am==1)
{
ajouter_etudiant(etud);
GtkWidget *input,*input1,*input2;
input=lookup_widget(objet_graphique,"GestionEtudiants_am");
input=create_GestionEtudiants_am();
gtk_widget_show(input);
input1=lookup_widget(objet_graphique,"AjouterEtudiant_am");
gtk_widget_destroy(input1);
input2=lookup_widget(objet_graphique,"ConfirmerAjout_am");
gtk_widget_destroy(input2);
n=1;
}
if(m_am==1)
{
GtkWidget *input3,*input4;
input4=lookup_widget(objet_graphique,"AjouterEtudiant_am");
input4=create_AjouterEtudiant_am();
gtk_widget_show(input4);
input3=lookup_widget(objet_graphique,"ConfirmerAjout_am");
gtk_widget_destroy(input3);
n=1;
}
}
if(n==0)
{
GtkWidget *output2,*input5;
input5=lookup_widget(objet_graphique,"ConfirmerAjout_am");
output2 = lookup_widget(objet_graphique,"label44_am") ;
gtk_label_set_text(GTK_LABEL(output2),"choisir oui ou non");
}
}



void
on_checkbutton1_am_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{w_am=1;}
else
{w_am=0;}
}


void
on_checkbutton2_am_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{m_am=1;}
else
{m_am=0;}
}

void
on_button14ValiderSup_am_clicked       (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input,*input1,*input2,*input3,*input4,*treeview1;
char fichierr[]={"etudiant.txt"};
int s ;
if(z_am==1)
{
s=suprimer_etudiant(fichierr,ident_am);
input=lookup_widget(objet_graphique,"GestionEtudiants_am");
input=create_GestionEtudiants_am();
gtk_widget_show(input);
input1=lookup_widget(objet_graphique,"ConfirmerSupression_am");
gtk_widget_destroy(input1);
treeview1=lookup_widget(input,"treeview1_0_am");
affichage_am(fichierr,treeview1);
}
if(z_am==2)
{


GtkWidget *input,*input1;
input1=lookup_widget(objet_graphique,"ConfirmerSupression_am");
gtk_widget_destroy(input1);




char fichier[]={"etudiant.txt"};
GtkWidget *input3,*input4,*treeview1;
input3=lookup_widget(objet_graphique,"GestionEtudiants_am");
input3=create_GestionEtudiants_am ();
gtk_widget_show(input3);
input4=lookup_widget(objet_graphique,"GestionEtudiants_am");
gtk_widget_destroy(input4);
gtk_widget_show(input3);
treeview1=lookup_widget(input3,"treeview1_0_am");
affichage_am(fichier,treeview1);
}
}

void
on_button36_am_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *window1;
	GtkWidget *window2;
	window2 = lookup_widget(objet,"GestionEtudiants_am");
	window1=create_acceuil ();
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);

}

/*********************FIN ETUDIANT********************/

/******************** reclam***********************/


int x=1;
int t[2]={0,0} ;

//////////////////////////////ajouter//////////////////////////////
void
on_button_ajouter_rec_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window2 = lookup_widget(objet,"Tree_view");
	window1=create_ajouter_rec ();
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}
void
on_button_envoyer_rec_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;
	GtkWidget *input8;
        GtkWidget *input9;
        GtkWidget *input10;
        GtkWidget *input11;
        GtkWidget *input12;
        GtkWidget *input13;
        GtkWidget *output;
	GtkWidget *output1;

	char texte[200];
	char texte1[200];
	reclamation Rec ;

	input1=lookup_widget(objet,"entry_nom");
	input2=lookup_widget(objet,"entry_prenom");
	input3=lookup_widget(objet,"entry_ID");
	input4=lookup_widget(objet,"radiobutton_homme");
	input5=lookup_widget(objet,"radiobutton_femme");
	input6=lookup_widget(objet,"entry_email");
	input7=lookup_widget(objet,"checkbutton_service_resto");
	input8=lookup_widget(objet,"checkbutton_service_heberg");
	input9=lookup_widget(objet,"spinbutton_jour");
        input10=lookup_widget(objet,"spinbutton_mois");
        input11=lookup_widget(objet,"spinbutton_annee");
        input12=lookup_widget(objet,"label_coment") ;
        input13=lookup_widget(objet,"entry_txt");
        output=lookup_widget(objet,"label_msg") ;
	output1=lookup_widget(objet,"label_exist") ;
        
 	if (x==1) strcpy(Rec.sexe,"Homme");

	if(x==2) strcpy(Rec.sexe,"Femme"); 

        if (t[0]==1) strcpy(Rec.obj_rec,"Restauration");

        if (t[1]==1) strcpy(Rec.obj_rec,"Hebergement");

      /*  if ( (t[0]==1)&&(t[1]==1) ) strcpy(Rec.obj_rec,"Restauration & Hebergement"); */
	
	strcpy(Rec.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(Rec.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(Rec.id,gtk_entry_get_text(GTK_ENTRY(input3)));
        strcpy(Rec.email,gtk_entry_get_text(GTK_ENTRY(input6)));

	Rec.D.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
	Rec.D.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input10));
	Rec.D.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input11));
	strcpy(Rec.text_rec,gtk_entry_get_text(GTK_ENTRY(input13)));
    	
	if(idExist1(Rec.id)) 
        {
		sprintf(texte1,"Cet id existe déja \n");
		output1 = lookup_widget(objet,"label_exist");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output1),texte1);	
	} else 
	{
		ajouter_rec(Rec);
                sprintf(texte,"✔️ Réclamation ajoutée avec succés") ;
		GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
                gtk_label_set_text(GTK_LABEL(output),texte) ;
                sprintf(texte1,"\n");
	}
}
void
on_button_prec_ajout_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{	
	user u;
         GtkWidget *window1;
GtkWidget *window2;
GtkWidget *window3;
window2 = lookup_widget(objet,"ajouter_rec");
window1=create_Tree_view ();
window3=create_acceuil();
FILE *f;
	f=fopen("role_ahmed.txt","r");
	fscanf(f,"%s %s %s %s %s\n",u.espritId,u.nom,u.prenom,u.password,u.role);
	if(strcmp("ADMIN",u.role)==0 ){
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);}
	else{
  	gtk_widget_show (window3);
	gtk_widget_destroy(window2);}
}
//////////////////////////chercher/////////////////////////////////////
void
on_button_chercher_rec_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"Tree_view");
	window2 = create_chercher_rec ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}
void
on_button_cherch_rec_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
        /* GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"chercher_rec");
	window2 = create_Tree_view ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1); */

   GtkWidget *fenetre_chercher;
   GtkWidget *fenetre_afficher;
   GtkWidget *espritId;
   GtkWidget *treeview2;
char id_rech[10];
espritId = lookup_widget (objet, "entry_id_cher");
strcpy(id_rech, gtk_entry_get_text(GTK_ENTRY(espritId)));

fenetre_chercher=lookup_widget(objet,"chercher_rec");
fenetre_afficher=create_Tree_view();
/*fenetre_afficher=lookup_widget(objet,"Tree_view"); */

gtk_widget_destroy(fenetre_chercher);
gtk_widget_show(fenetre_afficher);

treeview2=lookup_widget(fenetre_afficher,"treeview2");
chercher_rec(treeview2,id_rech);
}
void
on_button_prec_cherch_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *window1;
	GtkWidget *window2;
	window2 = lookup_widget(objet,"chercher_rec");
	window1=create_Tree_view ();
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);

        GtkWidget *treeview2;
        treeview2=lookup_widget(window1,"treeview2") ;
        afficher_rec(treeview2) ;
}
//////////////////////////////modifier//////////////////////////////
void
on_button_modifier_rec_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"Tree_view");
	window2 = create_modifier_rec();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}
void
on_button_modif_rec_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
        GtkWidget *inputid;
        GtkWidget *inputrec;
	GtkWidget *outputmsg;

	char id[20];
        char nouv_texte[1000];
	char texte[100];
        

	inputid = lookup_widget(objet_graphique,"entry_id_modif");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(inputid)));

        inputrec = lookup_widget(objet_graphique,"entry_nouv_rec");
        strcpy(nouv_texte,gtk_entry_get_text(GTK_ENTRY(inputrec)));

	if(idExist1(id))
             {
		modifier_rec(id,nouv_texte) ;		
		sprintf(texte,"✔️ Votre modification a été effectué avec succés\n");
		outputmsg = lookup_widget(objet_graphique,"label_msg_modif");
		GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (outputmsg, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(outputmsg),texte) ;	
	   }
	/*else
       {
		sprintf(texte,"Cet id n'existe pas\n");
		outputmsg = lookup_widget(objet_graphique,"label_msg_modif");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (outputmsg, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(outputmsg),texte);	
	}  */
}
void
on_button_prec_modif_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *window1;
	GtkWidget *window2;
	window2 = lookup_widget(objet,"modifier_rec");
	window1=create_Tree_view ();
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);

        GtkWidget *treeview2;
        treeview2=lookup_widget(window1,"treeview2") ;
        afficher_rec(treeview2) ;
}
void
on_button_consulter_rec_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	char id[200] ;
	GtkWidget *input;
        GtkWidget *output;
	GtkWidget *outputmsg;
	char texte[200] ;
        char texte1[1000] ;
	input = lookup_widget(objet,"entry_id_modif"); 
	strcpy (id,gtk_entry_get_text(GTK_ENTRY(input))) ;
	if(idExist1(id))
           {
	      reclamation Rec ;
	      strcpy(Rec.text_rec,find_rec(id).text_rec) ;
	      sprintf (texte1,"%s",Rec.text_rec) ;
   	      output = lookup_widget(objet,"entry_nouv_rec");
              gtk_entry_set_text(GTK_LABEL(output),texte1) ;
	
	   }
	else
       {
		sprintf(texte,"Cet id n'existe pas\n");
		outputmsg = lookup_widget(objet,"label_msg_modif");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (outputmsg, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(outputmsg),texte);	
	} 
}
/////////////////////////supprimer/////////////////////////////////////////
void
on_button_supprimer_rec_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"Tree_view");
	window2 = create_supprimer_rec();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}
void
on_button_suppr_rec_clicked                (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
        GtkWidget *input;
	GtkWidget *output;
	char id[20];
	char texte[100];

	input = lookup_widget(objet_graphique,"entry_id_suppr");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));

	if(idExist1(id))
             {
		supprimer_rec(id);		
		sprintf(texte,"✔️ Votre suppression à été effectué avec succés\n");
		output = lookup_widget(objet_graphique,"label_suppression");
		GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);
		
		
	   }
	else{
		sprintf(texte,"Cet id n'existe pas\n");
		output = lookup_widget(objet_graphique,"label_suppression");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);	
	} 
}
void
on_button_prec_suppr_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *window1;
	GtkWidget *window2;
	window2 = lookup_widget(objet,"supprimer_rec");
	window1=create_Tree_view ();
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);

        GtkWidget *treeview2;
        treeview2=lookup_widget(window1,"treeview2") ;
        afficher_rec(treeview2) ;
}
///////////////////////check & radio////////////////////////////////////////////
void
on_radiobutton_homme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}


void
on_radiobutton_femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}


void
on_checkbutton_service_resto_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{t[0]=1;}
}


void
on_checkbutton_service_heberg_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{t[1]=1;}
}
///////////////////////////////treeview///////////////////////////////////////
void
on_treeview2_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
 GtkTreeIter iter;
       gchar* nom;
       gchar* prenom;
       gchar* id;
       gchar* sexe;
       gchar* email;
       gchar* obj_rec;
       gchar* daten ;
       gchar* text_rec;
       char ch1[20] ;

       GtkTreeModel *model = gtk_tree_view_get_model(treeview);
       if (gtk_tree_model_get_iter(model, &iter, path))
       {
           gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&id,3,&sexe,4,&email,5,&obj_rec,6,daten,7,&text_rec,-1) ;
           /* strcpy(Rec.nom,nom);
           strcpy(Rec.prenom,prenom);
           strcpy(Rec.id,id);
           strcpy(Rec.sexe,sexe);
           strcpy(Rec.email,email);
           strcpy(Rec.obj_rec,obj_rec);
           strcpy(daten,daten);
           strcpy(Rec.text_rec,text_rec); */
           strcpy(ch1,id);
           supprimer_rec (ch1) ;
           afficher_rec (treeview) ;
       }
}
void
on_button_actualiser_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;
GtkWidget *treeview2;
w1=lookup_widget(objet,"Tree_view");
fenetre_afficher=create_Tree_view();
gtk_widget_show(fenetre_afficher);
gtk_widget_destroy(w1);
treeview2=lookup_widget(fenetre_afficher,"treeview2");

afficher_rec(treeview2);
}
void
on_button_prec_tree_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *window1;
	GtkWidget *window2;
	window2 = lookup_widget(objet,"Tree_view");
	window1=create_acceuil ();
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);

}



///////////////////////////tache2////////////////////////////////////////
void
on_button_prec_serv_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *window1;
	GtkWidget *window2;
	window2 = lookup_widget(objet,"service_plus_reclame");
	window1=create_Tree_view ();
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);

        GtkWidget *treeview2;
        treeview2=lookup_widget(window1,"treeview2") ;
        afficher_rec(treeview2) ;
}
void
on_button_serv_rec_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
                GtkWidget *output;
                char texte[100];
                char ch[20];
		int i;

                i=service_plusreclame() ;
		if (i==1)
                strcpy(ch,"Restauration") ;
	
                else if (i==2)
                strcpy(ch,"Hebergement") ;
	
		
		sprintf(texte,"✔️ Le service le plus reclamé est :    %s \n",ch);
		output = lookup_widget(objet,"label_serv");
		
                GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);
}
/////////////////////////////////mfaskhine/////////////////////////////////////////

void
on_button_afficher_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
        GtkWidget *treeview2;
	window2 = lookup_widget(objet,"Acceuil");
	window1=create_Tree_view ();
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);


        treeview2=lookup_widget(window1,"treeview2") ;
        afficher_rec(treeview2) ;
} 
void
on_button_acceuil_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
/* retour a la page d'acceuil de l'application desktop */
} 
void
on_button_service_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"Tree_view");
	window2 = create_service_plus_reclame();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
} 
void
on_button_espcae_rec_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
        GtkWidget *treeview2;
	window2 = lookup_widget(objet,"espace_rec");
	window1=create_Tree_view ();
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);


        treeview2=lookup_widget(window1,"treeview2") ;
        afficher_rec(treeview2) ;
} 




/***************FIN RECLAMATION****************/ 






/**************UTILISATEURS******************/

int type=1;
char idM[30];
 user ust;
void
on_ajouterUser_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *espritId, *nom, *prenom, *jour, *mois, *annee, *email, *tel, *cin, *sexe, *role ,*tel_err,*id_err,*cin_err,*email_err,*nom_err,*prenom_err,*role_err;
char sexa[20];
char password[20];
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

espritId = lookup_widget (button, "espritIda");
nom = lookup_widget (button, "noma");
prenom = lookup_widget (button, "prenoma");
jour = lookup_widget (button, "joura");
mois = lookup_widget (button, "moisa");
annee = lookup_widget (button, "anneea");
email = lookup_widget (button, "emaila");
tel = lookup_widget (button, "tela");
cin = lookup_widget (button, "cina");
role = lookup_widget (button, "rolea");
tel_err = lookup_widget (button, "tel_err");
id_err = lookup_widget (button, "id_err");
cin_err = lookup_widget (button, "cin_err");
email_err = lookup_widget (button, "email_err");
nom_err = lookup_widget (button, "nom_err");
prenom_err = lookup_widget (button, "prenom_err");
role_err = lookup_widget (button, "role_err");
inscription(type,sexa);
genererPassword(password);
user u;
date1 d;
int test12=0;

strcpy(u.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(u.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(u.espritId, gtk_entry_get_text(GTK_ENTRY(espritId)));
strcpy(u.email, gtk_entry_get_text(GTK_ENTRY(email)));
strcpy(u.tel, gtk_entry_get_text(GTK_ENTRY(tel)));
strcpy(u.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(u.password,password);

strcpy(u.sexe,sexa);
u.dateN=d;

if(strlen(u.tel)!=8){
  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (tel_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(tel_err),"Verifier le numéro de téléphone !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(tel_err),"");
if (verifier_espritId(u.espritId)==1)
{
GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (id_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(id_err),"Id existant !");
test12 =1;

}else if (strlen(u.espritId)!=10)
{
GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (id_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(id_err),"Vérifier Id !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(id_err),"");
if (strlen(u.cin)!=8)
{
GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (cin_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(cin_err),"Vérifier CIN !");
test12 =1;

}else if (verifier_CIN(u.cin)==1)
{
GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (cin_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(cin_err),"CIN existant !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(cin_err),"");
if (strlen(u.email)==0)
{
GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (email_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(email_err),"Vérifier Email !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(email_err),"");
if(strlen(u.nom)==0){
  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (nom_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(nom_err),"Verifier le nom !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(nom_err),"");
if(strlen(u.prenom)==0){
  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (prenom_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(prenom_err),"Verifier le prenom !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(prenom_err),"");
if(strlen(u.role)==0){
  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (role_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(role_err),"Verifier le role !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(role_err),"");
if (test12==0){
ajouter_user(u);
fenetre_ajout=lookup_widget(button,"ajouter_user");
gtk_widget_destroy(fenetre_ajout);
send_mail(u.email, u.espritId,u.password);
fenetre_afficher=create_gestion_des_utilisateurs();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher_user(treeview1);
}


 
}


void
on_homme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
type=1;
}


void
on_femme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
type=2;
}


void
on_actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;
GtkWidget *treeview1;
w1=lookup_widget(objet,"gestion_des_utilisateurs");
fenetre_afficher=create_gestion_des_utilisateurs();
gtk_widget_show(fenetre_afficher);
gtk_widget_destroy(w1);
treeview1=lookup_widget(fenetre_afficher,"treeview1");

afficher_user(treeview1);
}




void
on_afficher_user_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
fenetre_ajout=lookup_widget(objet,"ajouter_user");
gtk_widget_destroy(fenetre_ajout);

fenetre_afficher=create_gestion_des_utilisateurs();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher_user(treeview1);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* espritId;

char id[20];
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model, &iter, path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,3,&espritId,-1);

strcpy(id,espritId); 
   g_print("%s\n",id); 

 supprimer_user(id);
gtk_list_store_remove(GTK_LIST_STORE(model), &iter);

afficher_user(treeview);

}

}


void
on_ajouterUtilisateur_clicked          (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;

fenetre_afficher=lookup_widget(objet,"gestion_des_utilisateurs");

gtk_widget_destroy(fenetre_afficher);
fenetre_ajout=lookup_widget(objet,"ajouter_user");
fenetre_ajout=create_ajouter_user();
gtk_widget_show(fenetre_ajout);


}





//////////////////////////////////////////////////////

void
  view_popup_menu_onDoSomething (GtkWidget *menuitem, gpointer userdata)
  {
    GtkTreeView *treeview = GTK_TREE_VIEW(userdata);

GtkWidget *fenetre_afficher;
GtkWidget *fenetre_modif;
GtkWidget *espritId, *nom, *prenom, *jour, *mois, *annee, *email, *tel, *cin, *sexe, *role,*homme,*femme ;


date1 d;
char jo[20];
char mo[20];
char an[20];
fenetre_afficher=lookup_widget(treeview,"gestion_des_utilisateurs");
gtk_widget_destroy(fenetre_afficher);
user um=modifier_user(idM);
d=um.dateN;
fenetre_modif=create_modifier_user();

espritId = lookup_widget (fenetre_modif, "espritIdm");
gtk_entry_set_text(GTK_ENTRY(espritId),um.espritId);
gtk_entry_set_editable(espritId,FALSE);
nom = lookup_widget (fenetre_modif, "nomm");
gtk_entry_set_text(GTK_ENTRY(nom),um.nom);
prenom = lookup_widget (fenetre_modif, "prenomm");
gtk_entry_set_text(GTK_ENTRY(prenom),um.prenom);
email = lookup_widget (fenetre_modif, "emailm");
gtk_entry_set_text(GTK_ENTRY(email),um.email);
tel = lookup_widget (fenetre_modif, "telm");
gtk_entry_set_text(GTK_ENTRY(tel),um.tel);
cin = lookup_widget (fenetre_modif, "cinm");
gtk_entry_set_text(GTK_ENTRY(cin),um.cin);
gtk_entry_set_editable(cin,FALSE);
jour = lookup_widget (fenetre_modif, "jourm");
//sprintf(jo,"%d",um.dateN.jour); convert int to char

gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),um.dateN.jour);
mois = lookup_widget (fenetre_modif, "moism");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),um.dateN.mois);
annee = lookup_widget (fenetre_modif, "anneem");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),um.dateN.annee);
role = lookup_widget (fenetre_modif, "rolem");
int i=  test_role(um.role);
gtk_combo_box_set_active(GTK_COMBO_BOX(role), i);
homme = lookup_widget (fenetre_modif, "hommem");
femme = lookup_widget (fenetre_modif, "femmem");
if (strcmp(um.sexe,"homme")==0){
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(homme),TRUE);
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(femme),FALSE);
}
else if (strcmp(um.sexe,"femme")==0){
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(homme),FALSE);
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(femme),TRUE);
}

gtk_widget_show(fenetre_modif);

  }


  void
  view_popup_menu (GtkWidget *treeview, GdkEventButton *event, gpointer userdata)
  {
    GtkWidget *menu, *menuitem;
GtkTreeIter iter;
GtkTreePath *path;
    menu = gtk_menu_new();

    menuitem = gtk_menu_item_new_with_label("Modifier");

    g_signal_connect(menuitem, "activate",
                     (GCallback) view_popup_menu_onDoSomething, treeview);
 if (gtk_tree_view_get_path_at_pos(GTK_TREE_VIEW(treeview),
                                             (gint) event->x, 
                                             (gint) event->y,
                                             &path, NULL, NULL, NULL))
{
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
	     gchar* espritId;

if(gtk_tree_model_get_iter(model, &iter, path)){

	     gtk_tree_model_get(GTK_LIST_STORE(model),&iter,3,&espritId,-1);

	     strcpy(idM,espritId); 

  	     
}
	}     
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

    gtk_widget_show_all(menu);

    
    gtk_menu_popup(GTK_MENU(menu), NULL, NULL, NULL, NULL,
                   (event != NULL) ? event->button : 0,
                   gdk_event_get_time((GdkEvent*)event));
	    
  }


  gboolean
on_treeview1_button_press_event         (GtkWidget *treeview, GdkEventButton *event, gpointer userdata)
  {
    
    if (event->type == GDK_BUTTON_PRESS  &&  event->button == 3)
    {
      g_print ("Single right click on the tree view.\n");

      
      if (1)
      {
        GtkTreeSelection *selection;

        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));

        
        if (gtk_tree_selection_count_selected_rows(selection)  <= 1)
        {
           GtkTreePath *path;

          
           if (gtk_tree_view_get_path_at_pos(GTK_TREE_VIEW(treeview),
                                             (gint) event->x, 
                                             (gint) event->y,
                                             &path, NULL, NULL, NULL))
           {
             gtk_tree_selection_unselect_all(selection);
             gtk_tree_selection_select_path(selection, path);
	     
             gtk_tree_path_free(path);
           }
        }
      } 

      view_popup_menu(treeview, event, userdata);

      return TRUE;
    }

    return FALSE;
  }


  gboolean
  on_treeview1_popup_menu(GtkWidget *treeview, gpointer userdata)
  {

    view_popup_menu(treeview, NULL, userdata);

    return TRUE;
  }


  

 
////////////////////////////////////////////////////////////
void
on_rechercherUser_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_rechercher;
GtkWidget *fenetre_afficher;
GtkWidget *espritId;
GtkWidget *treeview1;
char rech[20];
espritId = lookup_widget (objet, "esId");
strcpy(rech, gtk_entry_get_text(GTK_ENTRY(espritId)));
fenetre_afficher=lookup_widget(objet,"gestion_des_utilisateurs");
gtk_widget_destroy(fenetre_afficher);
fenetre_rechercher=lookup_widget(objet,"gestion_des_utilisateurs");
fenetre_rechercher=create_gestion_des_utilisateurs();
gtk_widget_show(fenetre_rechercher);
treeview1=lookup_widget(fenetre_rechercher,"treeview1");
rechercher_user(treeview1,rech);
}


void
on_retourU_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modif;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
fenetre_modif=lookup_widget(objet,"modifier_user");
gtk_widget_destroy(fenetre_modif);

fenetre_afficher=create_gestion_des_utilisateurs();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher_user(treeview1);
}


void
on_modifierUser_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *espritId, *nom, *prenom, *jour, *mois, *annee, *email, *tel, *cin, *sexe, *role ,*tel_err,*email_err,*nom_err,*prenom_err,*role_err;
char sexa[20];
char password[20];
GtkWidget *fenetre_modif;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

espritId = lookup_widget (button, "espritIdm");
nom = lookup_widget (button, "nomm");
prenom = lookup_widget (button, "prenomm");
jour = lookup_widget (button, "jourm");
mois = lookup_widget (button, "moism");
annee = lookup_widget (button, "anneem");
email = lookup_widget (button, "emailm");
tel = lookup_widget (button, "telm");
cin = lookup_widget (button, "cinm");
role = lookup_widget (button, "rolem");
tel_err = lookup_widget (button, "tel_errm");

email_err = lookup_widget (button, "email_errm");
nom_err = lookup_widget (button, "nom_errm");
prenom_err = lookup_widget (button, "prenom_errm");
role_err = lookup_widget (button, "role_errm");
inscription(type,sexa);

user u;
date1 d;
strcpy(u.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(u.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(u.espritId, gtk_entry_get_text(GTK_ENTRY(espritId)));
strcpy(u.email, gtk_entry_get_text(GTK_ENTRY(email)));
strcpy(u.tel, gtk_entry_get_text(GTK_ENTRY(tel)));
strcpy(u.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(u.password,password);
strcpy(u.sexe,sexa);
u.dateN=d;
int test12=0;
if(strlen(u.tel)!=8){
  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (tel_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(tel_err),"Verifier le numéro de téléphone !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(tel_err),"");
if (strlen(u.email)==0)
{
GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (email_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(email_err),"Vérifier Email !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(email_err),"");
if(strlen(u.nom)==0){
  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (nom_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(nom_err),"Verifier le nom !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(nom_err),"");
if(strlen(u.prenom)==0){
  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (prenom_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(prenom_err),"Verifier le prenom !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(prenom_err),"");
if(strlen(u.role)==0){
  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (role_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(role_err),"Verifier le role !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(role_err),"");
if (test12==0){

update_user(u);
fenetre_modif=lookup_widget(button,"modifier_user");
gtk_widget_destroy(fenetre_modif);

fenetre_afficher=create_gestion_des_utilisateurs();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher_user(treeview1);
}

}


void
on_hommem_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
type=1;
}


void
on_femmem_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
type=2;
}


void
on_afficher_mouvement_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview2;
treeview2=lookup_widget(objet,"treeview16");
detection_mouvement(treeview2);
}


void
on_afficher_fumee_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview3;
treeview3=lookup_widget(objet,"treeview3");
detection_fumee(treeview3);
}

void
on_buttonuseracceuil_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modif;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
fenetre_modif=lookup_widget(objet,"gestion_des_utilisateurs");
gtk_widget_destroy(fenetre_modif);

fenetre_afficher=create_acceuil();
gtk_widget_show(fenetre_afficher);
	
}


/*void
on_login_clicked                       (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *espritId, *mdp,*login_err;
user u;
espritId = lookup_widget (button, "entryusernamelogin");
mdp = lookup_widget (button, "entryusernamelogin");
login_err = lookup_widget (button, "labelconfirmsignup");
strcpy(u.espritId, gtk_entry_get_text(GTK_ENTRY(espritId)));
strcpy(u.password, gtk_entry_get_text(GTK_ENTRY(mdp)));

if(login(u.espritId,u.password,ust)==0){


  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (login_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(login_err),"Verifier vos cordonnées !");
}
else if (login(u.espritId,u.password,ust)==1){
g_print("test %s\n",ust.espritId);
GtkWidget *windowlogin;
GtkWidget *acceuil;
GtkWidget *treeview1;
windowlogin=lookup_widget(button,"windowlogin");
gtk_widget_destroy(windowlogin);

acceuil=create_acceuil();
gtk_widget_show(acceuil);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher_user(treeview1);
}

}*/



/***********************STOCK ahmed**********************/



void
on_destroy1_ahmed_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(objet,"stock_ab");
    	gtk_widget_destroy(winmen);
}


void
on_retirer_ahmed_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *winadd;
    	GtkWidget *winmen;
    	winmen=lookup_widget(objet,"stock_ab");
    	winadd=create_retirer_ab();
    	gtk_widget_show(winadd);
    	gtk_widget_destroy(winmen);
}


void
on_modifier_ahmed_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *winadd;
    	GtkWidget *winmen;
    	winmen=lookup_widget(objet,"stock_ab");
    	winadd=create_modifier_ab();
    	gtk_widget_show(winadd);
    	gtk_widget_destroy(winmen);
}


void
on_ajouter_ahmed_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *winadd;
    	GtkWidget *winmen,*w1;
    	winmen=lookup_widget(objet,"stock_ab");
    	winadd=create_ajouter_ab();
    	gtk_widget_show(winadd);
    	gtk_widget_destroy(winmen);

}


void
on_chercher_ahmed_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *winadd;
    	GtkWidget *winmen;
    	GtkWidget *chercher_ab,*w1;
	GtkWidget *treeview2_ahmed;
	GtkWidget *output,*input,*combobox1_ahmed;
	char text[100],a[20]="Not Found",b[20]="choose a category";
	int i;
	stock s;
	input=lookup_widget(objet,"entry1_ahmed");
	output=lookup_widget(objet,"label_stock_ahmed");
	strcpy(text,gtk_entry_get_text(GTK_ENTRY(input)));
	combobox1_ahmed=lookup_widget(objet,"combobox1_ahmed");
	


		GdkColor color;
		gdk_color_parse ("#C92907", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),text);




	if ((strlen(chercheid_ahmed(text).nom)>2)&&(strcmp("id",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1_ahmed)))==0))
	{
		cherche_id_ahmed(text);
		
    		winmen=lookup_widget(objet,"stock_ab");
    		winadd=create_chercher_ab();
    		gtk_widget_show(winadd);
    		gtk_widget_destroy(winmen);

		treeview2_ahmed=lookup_widget(winadd,"treeview2_ahmed");

		vider_ahmed(treeview2_ahmed);
		affiche_chercher_ahmed(treeview2_ahmed);
		
	}
	else if ((strlen(cherchenom_ahmed(text).nom)>2)&&(strcmp("nom",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1_ahmed)))==0))
	{
		cherche_nom_ahmed(text);
		
    		winmen=lookup_widget(objet,"stock_ab");
    		winadd=create_chercher_ab();
    		gtk_widget_show(winadd);
    		gtk_widget_destroy(winmen);
		treeview2_ahmed=lookup_widget(winadd,"treeview2_ahmed");
		vider_ahmed(treeview2_ahmed);
		affiche_chercher_ahmed(treeview2_ahmed);
		
	}
	else if ((strlen(cherchequan_ahmed(text).nom)>2)&&(strcmp("quan",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1_ahmed)))==0))
	{
		cherche_quan_ahmed(text);
		
    		winmen=lookup_widget(objet,"stock_ab");
    		winadd=create_chercher_ab();
    		gtk_widget_show(winadd);
    		gtk_widget_destroy(winmen);


		

		
		treeview2_ahmed=lookup_widget(winadd,"treeview2_ahmed");

		vider_ahmed(treeview2_ahmed);
		affiche_chercher_ahmed(treeview2_ahmed);
		
	}
	else if ((strlen(chercheval_ahmed(text).nom)>2)&&(strcmp("val",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1_ahmed)))==0))
	{
		cherche_val_ahmed(text);
		
    		winmen=lookup_widget(objet,"stock_ab");
    		winadd=create_chercher_ab();
    		gtk_widget_show(winadd);
    		gtk_widget_destroy(winmen);


	
		treeview2_ahmed=lookup_widget(winadd,"treeview2_ahmed");

		vider_ahmed(treeview2_ahmed);
		affiche_chercher_ahmed(treeview2_ahmed);
		
	}
	else if ((strlen(cherchecat_ahmed(text).nom)>2)&&(strcmp("type",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1_ahmed)))==0))
	{
		cherche_type_ahmed(text);
		
    		winmen=lookup_widget(objet,"stock_ab");
    		winadd=create_chercher_ab();
    		gtk_widget_show(winadd);
    		gtk_widget_destroy(winmen);


		
		treeview2_ahmed=lookup_widget(winadd,"treeview2_ahmed");

		vider_ahmed(treeview2_ahmed);
		affiche_chercher_ahmed(treeview2_ahmed);
		
	}
	else
		gtk_label_set_text(GTK_LABEL(output),a);
		/*for (int i=0;i<200000;i++)
		{
			printf("...\n");
			printf("...\n");
			
		}
		gtk_label_set_text(GTK_LABEL(output),b);*/	
}


void
on_retour1_ahmed_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *winadd;
    	GtkWidget *winmen;
    	winmen=lookup_widget(objet,"stock_ab");
    	winadd=create_acceuil();
    	gtk_widget_show(winadd);
    	gtk_widget_destroy(winmen);
}




void
on_destroy2_ahmed_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(objet,"chercher_ab");
    	gtk_widget_destroy(winmen);
}


void
on_retour2_ahmed_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *winadd;
    	GtkWidget *winmen;
    	winmen=lookup_widget(objet,"chercher_ab");
    	winadd=create_stock_ab();
    	gtk_widget_show(winadd);
    	gtk_widget_destroy(winmen);
GtkWidget *stock_ab,*w1;
GtkWidget *treeview1_ahmed;

gtk_widget_destroy(w1);
treeview1_ahmed=lookup_widget(winadd,"treeview1_ahmed");

vider_ahmed(treeview1_ahmed);
treeview_affiche_ahmed(treeview1_ahmed);

GtkWidget *combobox1_ahmed;
  combobox1_ahmed=lookup_widget(winadd,"combobox1_ahmed");
  gtk_combo_box_set_active(GTK_COMBO_BOX(combobox1_ahmed),0);
}


void
on_retour3_ahmed_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *winadd;
    	GtkWidget *winmen;
    	winmen=lookup_widget(objet,"ajouter_ab");
    	winadd=create_stock_ab();
    	gtk_widget_show(winadd);
    	gtk_widget_destroy(winmen);
GtkWidget *stock_ab,*w1;
GtkWidget *treeview1_ahmed;
treeview1_ahmed=lookup_widget(winadd,"treeview1_ahmed");

vider_ahmed(treeview1_ahmed);
treeview_affiche_ahmed(treeview1_ahmed);
GtkWidget *combobox1_ahmed;
  combobox1_ahmed=lookup_widget(winadd,"combobox1_ahmed");
  gtk_combo_box_set_active(GTK_COMBO_BOX(combobox1_ahmed),0);	
}


void
on_destroy3_ahmed_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(objet,"ajouter_ab");
    	gtk_widget_destroy(winmen);
}


void
on_ajouter1_ahmed_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	stock s;
	char a[20],b[20];
	GtkWidget *input1,*input2,*input3,*input4,*input5;
	GtkWidget *ajout;
	ajout=lookup_widget(objet,"ajouter_ab");
	input1=lookup_widget(objet,"entry2_ahmed");
	input2=lookup_widget(objet,"entry3_ahmed");
	input3=lookup_widget(objet,"entry4_ahmed");
	//input4=lookup_widget(objet,"entry5");
	strcpy(s.id,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(s.quantite,gtk_entry_get_text(GTK_ENTRY(input3)));
	//strcpy(s.val,gtk_entry_get_text(GTK_ENTRY(input4)));
	

	GtkWidget *combobox2_ahmed,*combobox3_ahmed;
	combobox2_ahmed=lookup_widget(objet,"combobox2_ahmed");
	strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2_ahmed)));
	combobox3_ahmed=lookup_widget(objet,"combobox3_ahmed");
	strcpy(b,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3_ahmed)));
	sprintf(s.val,"%s/%s",a,b);

	if (type==1)
		strcpy(s.cat,"autre");
	else if (type==2)
		strcpy(s.cat,"legume");
	else if (type==3)
		strcpy(s.cat,"fruit");
	ajouter_ahmed(s);
	GtkWidget *winadd;
    	GtkWidget *winmen;
    	winmen=lookup_widget(objet,"ajouter_ab");
    	/*winadd=create_stock_ab();
    	gtk_widget_show(winadd);*/
    	gtk_widget_destroy(winmen);

GtkWidget *stock_ab,*w1;
GtkWidget *treeview1_ahmed;

w1=lookup_widget(objet,"stock_ab");
stock_ab=create_stock_ab();

gtk_widget_show(stock_ab);

gtk_widget_destroy(w1);
treeview1_ahmed=lookup_widget(stock_ab,"treeview1_ahmed");

vider_ahmed(treeview1_ahmed);
treeview_affiche_ahmed(treeview1_ahmed);
GtkWidget *combobox1_ahmed;
  combobox1_ahmed=lookup_widget(stock_ab,"combobox1_ahmed");
  gtk_combo_box_set_active(GTK_COMBO_BOX(combobox1_ahmed),0);
}


void
on_modifier1_ahmed_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	

	GtkWidget *output,*input;
	char text[100],a[20]="Not Found";
	int i;
	stock s;
	input=lookup_widget(objet,"entry6_ahmed");
	output=lookup_widget(objet,"label_mod_ahmed");
	strcpy(text,gtk_entry_get_text(GTK_ENTRY(input)));
	


		GdkColor color;
		gdk_color_parse ("#C92907", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),text);




	if (strlen(chercheid_ahmed(text).nom)>2)




{
	GtkWidget *a,*b,*c;
	char d[20],e[20];
	stock s;
	b = lookup_widget(objet,"entry7_ahmed");
	c = lookup_widget(objet,"entry8_ahmed");
	strcpy(s.id,text);
	strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(b)));
	strcpy(s.quantite,gtk_entry_get_text(GTK_ENTRY(c)));




	GtkWidget *combobox4_ahmed,*combobox5_ahmed;
	combobox4_ahmed=lookup_widget(objet,"combobox4_ahmed");
	strcpy(d,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4_ahmed)));
	combobox5_ahmed=lookup_widget(objet,"combobox5_ahmed");
	strcpy(e,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5_ahmed)));
	sprintf(s.val,"%s/%s",d,e);

	if (type==1)
		strcpy(s.cat,"autre");
	else if (type==2)
		strcpy(s.cat,"legume");
	else if (type==3)
		strcpy(s.cat,"fruit");


	modifier_ahmed(s);

	GtkWidget *winadd;
    	GtkWidget *winmen;
    	winmen=lookup_widget(objet,"modifier_ab");
    	/*winadd=create_stock_ab();
    	gtk_widget_show(winadd);*/
    	gtk_widget_destroy(winmen);
GtkWidget *stock_ab,*w1;
GtkWidget *treeview1_ahmed;

w1=lookup_widget(objet,"stock_ab");
stock_ab=create_stock_ab();

gtk_widget_show(stock_ab);

gtk_widget_destroy(w1);
treeview1_ahmed=lookup_widget(stock_ab,"treeview1_ahmed");

vider_ahmed(treeview1_ahmed);
treeview_affiche_ahmed(treeview1_ahmed);

GtkWidget *combobox1_ahmed;
  combobox1_ahmed=lookup_widget(stock_ab,"combobox1_ahmed");
  gtk_combo_box_set_active(GTK_COMBO_BOX(combobox1_ahmed),0);
}

else
{
	gtk_label_set_text(GTK_LABEL(output),a);
}

}


void
on_destroy4_ahmed_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(objet,"modifier_ab");
    	gtk_widget_destroy(winmen);
}


void
on_retour4_ahmed_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *winadd;
    	GtkWidget *winmen;
    	winmen=lookup_widget(objet,"modifier_ab");
    	/*winadd=create_stock_ab();
    	gtk_widget_show(winadd);*/
    	gtk_widget_destroy(winmen);
GtkWidget *stock_ab,*w1;
GtkWidget *treeview1_ahmed;

w1=lookup_widget(objet,"stock_ab");
stock_ab=create_stock_ab();

gtk_widget_show(stock_ab);

gtk_widget_destroy(w1);
treeview1_ahmed=lookup_widget(stock_ab,"treeview1_ahmed");

vider_ahmed(treeview1_ahmed);
treeview_affiche_ahmed(treeview1_ahmed);

GtkWidget *combobox1_ahmed;
  combobox1_ahmed=lookup_widget(stock_ab,"combobox1_ahmed");
  gtk_combo_box_set_active(GTK_COMBO_BOX(combobox1_ahmed),0);
}


void
on_retirer1_ahmed_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{


	GtkWidget *output,*input;
	char text[100],a[20]="Not Found";
	int i;
	stock s;
	input=lookup_widget(objet,"entry10_ahmed");
	output=lookup_widget(objet,"label_supp_ahmed");
	strcpy(text,gtk_entry_get_text(GTK_ENTRY(input)));
	


		GdkColor color;
		gdk_color_parse ("#C92907", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),text);




	if (strlen(chercheid_ahmed(text).nom)>2)
	{
		supprimer_ahmed(text);
		GtkWidget *winadd;
    		GtkWidget *winmen;
    		winmen=lookup_widget(objet,"retirer_ab");
    		/*winadd=create_stock_ab();
    		gtk_widget_show(winadd);*/
    		gtk_widget_destroy(winmen);
GtkWidget *stock_ab,*w1;
GtkWidget *treeview1_ahmed;

w1=lookup_widget(objet,"stock_ab");
stock_ab=create_stock_ab();

gtk_widget_show(stock_ab);

gtk_widget_destroy(w1);
treeview1_ahmed=lookup_widget(stock_ab,"treeview1_ahmed");

vider_ahmed(treeview1_ahmed);
treeview_affiche_ahmed(treeview1_ahmed);

GtkWidget *combobox1_ahmed;
  combobox1_ahmed=lookup_widget(stock_ab,"combobox1_ahmed");
  gtk_combo_box_set_active(GTK_COMBO_BOX(combobox1_ahmed),0);
}
	else
	{
		gtk_label_set_text(GTK_LABEL(output),a);
	}
}


void
on_retour5_ahmed_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *winadd;
    	GtkWidget *winmen;
    	winmen=lookup_widget(objet,"retirer_ab");
    	/*winadd=create_stock_ab();
    	gtk_widget_show(winadd);*/
    	gtk_widget_destroy(winmen);
GtkWidget *stock_ab,*w1;
GtkWidget *treeview1_ahmed;

w1=lookup_widget(objet,"stock_ab");
stock_ab=create_stock_ab();

gtk_widget_show(stock_ab);

gtk_widget_destroy(w1);
treeview1_ahmed=lookup_widget(stock_ab,"treeview1_ahmed");

vider_ahmed(treeview1_ahmed);
treeview_affiche_ahmed(treeview1_ahmed);

GtkWidget *combobox1_ahmed;
  combobox1_ahmed=lookup_widget(stock_ab,"combobox1_ahmed");
  gtk_combo_box_set_active(GTK_COMBO_BOX(combobox1_ahmed),0);
}


void
on_destroy5_ahmed_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(objet,"retirer_ab");
    	gtk_widget_destroy(winmen);
}


void
on_fruit1_ahmed_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		type=1;
}


void
on_legume1_ahmed_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		type=2;
}


void
on_autre1_ahmed_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		type=3;
}


void
on_fruit2_ahmed_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		type=3;
}


void
on_legume2_ahmed_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		type=2;
}


void
on_autre2_ahmed_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		type=1;
}



/********************** MAIN APP ******************/
void
on_buttonsignup_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	
}


void
on_buttonlogin_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"windowmain");
	window2 = create_windowlogin ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_buttonloginconfirm_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *espritId, *mdp,*login_err;
user u,a;
char id[20];
espritId = lookup_widget (button, "entryusernamelogin");
mdp = lookup_widget (button, "entrypasswordlogin");
login_err = lookup_widget (button, "labelconfirmsignup");
strcpy(u.espritId, gtk_entry_get_text(GTK_ENTRY(espritId)));
strcpy(u.password, gtk_entry_get_text(GTK_ENTRY(mdp)));
strcpy(id,u.espritId);
if(login(u.espritId,u.password,ust)==0){


  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (login_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(login_err),"Verifier vos cordonnées !");
}
else if (login(u.espritId,u.password,ust)==1){
find_user(u.espritId);

g_print("test %s\n",ust.espritId);
GtkWidget *windowlogin;
GtkWidget *acceuil;
GtkWidget *treeview1;
windowlogin=lookup_widget(button,"windowlogin");
gtk_widget_destroy(windowlogin);

acceuil=create_acceuil();
gtk_widget_show(acceuil);
}
}


void
on_checkbuttonpassword_toggled         (GtkWidget *objet,
                                        gpointer         user_data)
{
 GtkWidget *passlock,*pass;
passlock=lookup_widget(objet,"checkbuttonpassword");
pass=lookup_widget(objet,"entrypasswordlogin");
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(passlock)))
{
gtk_entry_set_visibility(pass,FALSE);
}
else
{
gtk_entry_set_visibility(pass,TRUE);
}
}


void
on_buttoncancellogin_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"windowlogin");
	window2 = create_windowmain ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_buttoncloseapp_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	window1 = lookup_widget(objet,"windowmain");
	gtk_widget_destroy(window1);
}


void
on_buttonadmin_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"windowmain");
	window2 = create_windowespaceadmin ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_buttonvalidadmin_clicked            (GtkWidget        *objet,
                                        gpointer         user_data)
{	
	char texte[200];
	char password [20];
	GtkWidget *input1;
	GtkWidget *output;
	input1=lookup_widget(objet,"entryadminpass");
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(input1)));
	if (strcmp ("ademboujnah",password)==0){
	FILE *f;
	remove("role_ahmed.txt");
    	f=fopen("role_ahmed.txt","a");
	fprintf(f, "a a a a ADMIN\n");
	fclose(f);
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"windowespaceadmin");
	window2 = create_acceuil ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);}
	else{sprintf(texte,"Code incorrecte");
		output = lookup_widget(objet,"labeladmin");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);
}
}


void
on_buttonadmintomain_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"windowespaceadmin");
	window2 = create_windowmain ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}









/**************************** menu oussema *****************************/


int r_b=0 ;
char idsupp[20];
/////// treeview///////////
void
on_treeview22_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
 GtkTreeIter iter;
       gchar* menuId;
       gchar* jour;
       gchar* petit_dejeuner;
       gchar* dejeuner;
       gchar* dinner;
    
       char ch1[20] ;

       GtkTreeModel *model = gtk_tree_view_get_model(treeview);
       if (gtk_tree_model_get_iter(model, &iter, path))
       {
           gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&menuId,1,&jour,2,&petit_dejeuner,3,&dejeuner,4,&dinner,-1) ;

           strcpy(ch1,menuId);
           supprimer_menu (ch1) ;
           afficher_menu (treeview) ;
       }
}

//////gestion des menus//////////
void
on_button_ajout_ob_clicked                (GtkWidget      *objet,
                                        gpointer         user_data)

{
	GtkWidget *window1;
	GtkWidget *window2;
	window2 = lookup_widget(objet,"gestion_des_menus");
	window1=create_ajouterdesmenus ();
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);

}


void
on_button_chercher_ob_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"gestion_des_menus");
	window2 = create_chercherdesmenus ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_button_modifier_ob_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
   	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"gestion_des_menus");
	window2 = create_modification();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_button_suppr_ob_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"gestion_des_menus");
	window2 = create_suprime();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}



//////// ajouter des menus/////////////////

void
on_button_ajouter_mob_clicked          (GtkWidget      *objet,
                                        gpointer         user_data)
{
FILE *f=NULL ;
GtkWidget *ID ,*DATE, *MATIN, *APRES_MIDI, *NUIT ;
GtkWidget *input;
GtkWidget *output;
menu m;
char texte1[100];
char id [20];
char texte[100];


ID = lookup_widget ( objet, "entry_mid");
DATE  = lookup_widget (objet, "entry_mjour");
MATIN = lookup_widget ( objet, "entry_mpetit");
APRES_MIDI = lookup_widget ( objet, "entry_mdejeuner");
NUIT = lookup_widget (objet, "entry_mdinner");
strcpy( m.menuId , gtk_entry_get_text(GTK_ENTRY(ID)));
strcpy( m.jour , gtk_entry_get_text(GTK_ENTRY(DATE)));
strcpy( m.petit_dejeuner , gtk_entry_get_text(GTK_ENTRY(MATIN)));
strcpy( m.dejeuner , gtk_entry_get_text(GTK_ENTRY(APRES_MIDI)));
strcpy( m.dinner , gtk_entry_get_text(GTK_ENTRY(NUIT)));
if(idExist22(m.menuId)) 
{
  sprintf(texte1,"Cet id existe déja \n");

		output = lookup_widget(objet,"label_ajout_ob");

		GdkColor color;

		gdk_color_parse ("#ff250d", &color);

		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);

    		gtk_label_set_text(GTK_LABEL(output),texte1);
		sprintf(texte1,"\n");
}
else
{	          
ajouter_menu(m);
sprintf(texte,"✔️ Votre ajout à été effectué avec succés\n");
output = lookup_widget(objet,"label_ajout_ob");
GdkColor color;
gdk_color_parse ("#40e61a", &color);
gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    gtk_label_set_text(GTK_LABEL(output),texte);
sprintf(texte,"\n");
	

} 
}

void
on_button_retourner_mob_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	window2 = lookup_widget(objet,"ajouterdesmenus");
	window1=create_gestion_des_menus ();
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_button_accmob_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
  
}
//////// suprimer des menus///////////////

void
on_button_supp_mob_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{
        GtkWidget *input;
	GtkWidget *output;
	char texte[100];

	input = lookup_widget(objet,"entry_supprimer_ob");
	strcpy(idsupp,gtk_entry_get_text(GTK_ENTRY(input)));

	if(idExist22(idsupp))
             {
		
	GtkWidget *window1;
	GtkWidget *window2;
	window2 = lookup_widget(objet,"suprime");
	window1=create_con_supp ();
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
		
	   }
	else{
		sprintf(texte,"Cet id n'existe pas\n");
		output = lookup_widget(objet,"label_supprimerrr");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);	
	} 
}


void
on_button_acc_mob_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button_retoursupp_mob_clicked       (GtkWidget      *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window2 = lookup_widget(objet,"suprime");
	window1=create_gestion_des_menus ();
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);

        GtkWidget *treeview2;
        treeview2=lookup_widget(window1,"treeview22") ;
        afficher_menu(treeview2) ;
}
///////// modifier des menus ////////////:

void
on_button_ret_modif_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *window1;
	GtkWidget *window2;
	window2 = lookup_widget(objet,"modification");
	window1=create_gestion_des_menus ();
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);

        GtkWidget *treeview2;
        treeview2=lookup_widget(window1,"treeview22") ;
        afficher_menu(treeview2) ;
}


void
on_button_modif_modif_clicked          (GtkWidget      *objet,
                                        gpointer         user_data)
{

        GtkWidget *inputid;
        GtkWidget *inputjour;
	GtkWidget *outputmsg;
	GtkWidget *inputpetit;
	GtkWidget *inputdejeuner;
	GtkWidget *inputdinner;

	char id[20];
        char nouv_jour[20];
	char nouv_petit[20];
	char nouv_dejeuner[20];
	char nouv_dinner [20];
	char texte[100];
        

	inputid = lookup_widget(objet,"entry_menuId_modif");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(inputid)));

        inputjour = lookup_widget(objet,"entry_jour_modif");
        strcpy(nouv_jour,gtk_entry_get_text(GTK_ENTRY(inputjour)));

	inputpetit = lookup_widget(objet,"entry_petit_modif");
        strcpy(nouv_petit,gtk_entry_get_text(GTK_ENTRY(inputpetit)));

	inputdejeuner = lookup_widget(objet,"entry_dejeuenr_modif");
        strcpy(nouv_dejeuner,gtk_entry_get_text(GTK_ENTRY(inputdejeuner)));

	inputdinner = lookup_widget(objet,"entry_dinner_modif");
        strcpy(nouv_dinner,gtk_entry_get_text(GTK_ENTRY(inputdinner)));

	if(idExist22(id))
             {
		modifier_menu(id,nouv_jour,nouv_petit,nouv_dejeuner,nouv_dinner) ;		
		sprintf(texte,"✔️ Votre modification a été effectué avec succés\n");
		outputmsg = lookup_widget(objet,"label_modif_ob");
		GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (outputmsg, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(outputmsg),texte) ;	
	   }
		else{
		sprintf(texte,"Cet id n'existe pas\n");
		outputmsg = lookup_widget(objet,"label_modif_ob");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (outputmsg, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(outputmsg),texte);	
		}
}


void
on_button_acc_modif_clicked            (GtkWidget      *objet,
                                        gpointer         user_data)
{

}

///////////gestion des menus/////////////////

void
on_button_actualiser_ob_clicked           (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;
GtkWidget *treeview2;
w1=lookup_widget(objet,"gestion_des_menus");
fenetre_afficher=create_gestion_des_menus();
gtk_widget_show(fenetre_afficher);
gtk_widget_destroy(w1);
treeview2=lookup_widget(fenetre_afficher,"treeview22");

afficher_menu(treeview2);
}

////////// chercher des menus///////////
void
on_button_ret_cher_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
     GtkWidget *window1;
	GtkWidget *window2;
	window2 = lookup_widget(objet,"chercherdesmenus");
	window1=create_gestion_des_menus ();
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);

        GtkWidget *treeview2;
        treeview2=lookup_widget(window1,"treeview22") ;
        afficher_menu(treeview2) ;
}


void
on_button_chercher_cherch_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *fenetre_chercher;
   GtkWidget *fenetre_afficher;
   GtkWidget *Id;
   GtkWidget *treeview2;
char id_rech[20];
Id = lookup_widget (objet,"entry_cherch_mobi");
strcpy(id_rech, gtk_entry_get_text(GTK_ENTRY(Id)));

/*fenetre_chercher=lookup_widget(objet,"chercherdesmenus");
fenetre_afficher=lookup_widget(objet,"gestion_des_menus");
fenetre_afficher=create_gestion_des_menus(); 



treeview2=lookup_widget(fenetre_afficher,"treeview2");
chercher_menu(treeview2,id_rech);




gtk_widget_destroy(fenetre_chercher);
gtk_widget_show(fenetre_afficher);

} */



fenetre_chercher=lookup_widget(objet,"chercherdesmenus");
fenetre_afficher=create_gestion_des_menus();
/*fenetre_afficher=lookup_widget(objet,"gestion_des_menus");*/

gtk_widget_destroy(fenetre_chercher);
gtk_widget_show(fenetre_afficher);

treeview2=lookup_widget(fenetre_afficher,"treeview22");
chercher_menu(treeview2,id_rech);
}

//////////conf spprime////////////////

void
on_radiobutton_ob1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{r_b=1;}
}


void
on_radiobutton_ob2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{r_b=2;}
}


void
on_conf_supp_b_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *input;
	  GtkWidget *output;
	  char texte[100];
if (r_b==1) 
{
		supprimer_menu(idsupp);		
		

		GtkWidget *window1;
		GtkWidget *window2;
		window1 = lookup_widget(objet,"con_supp");
		window2 = create_suprime();
  		gtk_widget_show (window2);
		gtk_widget_destroy(window1);
		sprintf(texte,"✔️ Votre suppression à été effectué avec succés\n");
		output = lookup_widget(objet,"label_suprimerrr");
		GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte); 
		
		/*sprintf(texte,"Votre suppression à été effectué avec succés\n");
		output = lookup_widget(objet,"label_supprimerrr");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);*/
}

if (r_b==2)
{
		GtkWidget *window1;
		GtkWidget *window2;
		window1 = lookup_widget(objet,"con_supp");
		window2 = create_suprime();
  		gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}

}










void
on_button_retour_ob_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *winadd;
    	GtkWidget *winmen;
    	winmen=lookup_widget(objet,"gestion_des_menus");
    	winadd=create_acceuil();
    	gtk_widget_show(winadd);
    	gtk_widget_destroy(winmen);
}

/*******************************Destroy Buttons*********************/
void
on_quitacceuil_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"acceuil");
    	gtk_widget_destroy(winmen);
}


void
on_buttondeconnexion_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *winadd;
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"acceuil");
    	winadd=create_windowlogin();
    	gtk_widget_show(winadd);
    	gtk_widget_destroy(winmen);
}


void
on_quitwindowlogin_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"windowlogin");
    	gtk_widget_destroy(winmen);
}


void
on_quitwindowespaceadmin_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"windowespaceadmin");
    	gtk_widget_destroy(winmen);
}


void
on_quitaddcap_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"addcap");
    	gtk_widget_destroy(winmen);
}


void
on_quitgestcap_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"gestcap");
    	gtk_widget_destroy(winmen);
}


void
on_quitdelcap_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"delcap");
    	gtk_widget_destroy(winmen);
}


void
on_quitGestionEtudiants_am_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"GestionEtudiants_am");
    	gtk_widget_destroy(winmen);
}


void
on_quitAjouterEtudiants_am_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"AjouterEtudiants_am");
    	gtk_widget_destroy(winmen);
}


void
on_quitModifierEtudiant_am_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"ModifierEtudiant_am");
    	gtk_widget_destroy(winmen);
}


void
on_quitAjouterEtudiant_am_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *winmen;
    	winmen=lookup_widget(button,"AjouterEtudiant_am");
    	gtk_widget_destroy(winmen);
}


void
on_quitConfirmerAjout_am_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"ConfirmerAjout_am");
    	gtk_widget_destroy(winmen);
}


void
on_quitConfirmerSupression_am_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"ConfirmerSupression_am");
    	gtk_widget_destroy(winmen);
}


void
on_quitajouter_rec_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"ajouter_rec");
    	gtk_widget_destroy(winmen);
}


void
on_quitTree_view_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"Tree_view");
    	gtk_widget_destroy(winmen);
}


void
on_quitsupprimer_rec_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"supprimer_rec");
    	gtk_widget_destroy(winmen);
}


void
on_quitchercher_rec_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"chercher_rec");
    	gtk_widget_destroy(winmen);
}


void
on_quitmodifier_rec_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"modifier_rec");
    	gtk_widget_destroy(winmen);
}


void
on_quit_gestion_des_utilisateurs_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"gestion_des_utilisateurs");
    	gtk_widget_destroy(winmen);
}


void
on_quitmodifier_user_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"modifier_user");
    	gtk_widget_destroy(winmen);
}


void
on_quitajouter_user_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"ajouter_user");
    	gtk_widget_destroy(winmen);
}


void
on_quitgestion_des_menus_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"gestion_des_menus");
    	gtk_widget_destroy(winmen);
}


void
on_quitajouterdesmenus_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"ajouterdesmenus");
    	gtk_widget_destroy(winmen);
}


void
on_quitsuprime_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"suprime");
    	gtk_widget_destroy(winmen);
}


void
on_quitmodification_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"modification");
    	gtk_widget_destroy(winmen);
}


void
on_quitchercherdesmenus_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
    	GtkWidget *winmen;
    	winmen=lookup_widget(button,"chercherdesmenus");
    	gtk_widget_destroy(winmen);
}



/*******************************fin**************************/


void
on_quiteditcap_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *winmen;
    	winmen=lookup_widget(button,"editcap");
    	gtk_widget_destroy(winmen);
}


void
on_quitfindcap_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *winmen;
    	winmen=lookup_widget(button,"findcap");
    	gtk_widget_destroy(winmen);
}

/*****************************extra******************************/


void
on_buttonadem6_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	int jour,heure,num;
	int j,h,n;
	int t;
	GtkWidget *input6;
	GtkWidget *input7;
	GtkWidget *input8;
	GtkWidget *output;
	char texte[200];
	input6=lookup_widget(objet,"spinbuttonj");
	input7=lookup_widget(objet,"spinbuttonh");
	input8=lookup_widget(objet,"spinbuttonn");
	jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
	heure=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
	num=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
	FILE *f=NULL;
	f=fopen("mouvement.txt","r");
if (f!=NULL){
	while(fscanf(f,"%d %d %d %d\n",&j,&h,&n,&t)!=EOF)
	{
         if ((jour==j)&&(heure==h)&&(num==n)&&(t==0))
  	  {
	        sprintf(texte,"Pas De Mouvement");
		output = lookup_widget(objet,"labelshow");
		/*GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);*/
    		gtk_label_set_text(GTK_LABEL(output),texte);
          }
	
  	else {  
                sprintf(texte,"Ily'a Mouvement");
		output = lookup_widget(objet,"labelshow");
		/*GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);*/
    		gtk_label_set_text(GTK_LABEL(output),texte);}


             }
fclose(f);
}
}



void
on_bradhwen_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	int jour,heure,num;
	int j,h,n;
	float t;
	GtkWidget *input6;
	GtkWidget *input7;
	GtkWidget *input8;
	GtkWidget *output;
	char texte[200];
	input6=lookup_widget(objet,"spinbuttonj");
	input7=lookup_widget(objet,"spinbuttonh");
	input8=lookup_widget(objet,"spinbuttonn");
	jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
	heure=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
	num=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
	FILE *f=NULL;
	f=fopen("temperature.txt","r");
if (f!=NULL){
	while(fscanf(f,"%d %d %d %f\n",&j,&h,&n,&t)!=EOF)
	{if ((jour==j)&&(heure==h)&&(num==n)&&(t<30)&&(t>10))
  	{
	sprintf(texte,"Ce Capteur est fonctionnel");
		output = lookup_widget(objet,"labelshow");
		/*GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);*/
    		gtk_label_set_text(GTK_LABEL(output),texte);}	
  	else { sprintf(texte,"Ce Capteur est diffectueux");
		output = lookup_widget(objet,"labelshow");
		/*GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);*/
    		gtk_label_set_text(GTK_LABEL(output),texte);}


}
fclose(f);
}
}


void
on_bhamdi_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
 		GtkWidget *output;
                char texte[100];
                char ch[20];
		int i;

                i=service_plusreclame() ;
		if (i==1)
                strcpy(ch,"Restauration") ;
	
                else if (i==2)
                strcpy(ch,"Hebergement") ;
	
		
		sprintf(texte,"✔️ Le service le plus reclamé est :    %s \n",ch);
		output = lookup_widget(objet,"labelshow");
		
                /*GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);*/
    		gtk_label_set_text(GTK_LABEL(output),texte);
}


void
on_bahmed1_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *output;
FILE *f,*g;
char id[20],nom[20],quantite[20],val[20],type[20],a[20]="0",def[20];
f=fopen("stock.txt","r");
while (fscanf(f,"%s %s %s %s %s\n",id,nom,quantite,val,type)!=EOF)
{
	if (strcmp(quantite,a)==0)
	{
		output = lookup_widget(objet,"labelshow");
		gtk_label_set_text(GTK_LABEL(output),nom);
	}
}
fclose(f);
}


void
on_boussema_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
FILE *f;
GtkWidget *output;
char a[20],b[20],c[20],g[100];
int d,e=1000;
f=fopen("dechets.txt","r");
while (fscanf(f,"%s %s %s",a,b,c)!=EOF)
{
	d=atoi(c);
	if (d<e)
	{
		e=d;
		sprintf(g," le meilleur repas ce mois est num %s du jour %s ",b,a);
		/*strcat(g," :est le meilleur repas du mois");*/
	}
}

output = lookup_widget(objet,"labelshow");
gtk_label_set_text(GTK_LABEL(output),g);
}


void
on_bashref_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *input;
GtkWidget *output;
int nv , abc ;
char nvv[100] ;
char def[100] ;
char texte[20]="est le nombre des etudiants ";
input=lookup_widget(objet,"spinbutton_niveau66");
nv=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));
sprintf(nvv,"%d",nv); 
abc=nb_etud(nvv) ;
sprintf(def,"%d",abc); 

strcat(def," est le nombre des etudiants de ce niveau " ) ;
output = lookup_widget(objet,"labelshow");
gtk_label_set_text(GTK_LABEL(output),def);


}


void
on_bacceuilb_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *winadd;
    	GtkWidget *winmen;
    	winmen=lookup_widget(objet,"windowextras");
    	winadd=create_acceuil();
    	gtk_widget_show(winadd);
    	gtk_widget_destroy(winmen);
}


void
on_buttonadem2_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	int jour,heure,num;
	int j,h,n;
	int t;
	GtkWidget *input6;
	GtkWidget *input7;
	GtkWidget *input8;
	GtkWidget *output;
	char texte[200];
	input6=lookup_widget(objet,"spinbuttonj");
	input7=lookup_widget(objet,"spinbuttonh");
	input8=lookup_widget(objet,"spinbuttonn");
	jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
	heure=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
	num=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
	FILE *f=NULL;
	f=fopen("fumee.txt","r");
if (f!=NULL){
	while(fscanf(f,"%d %d %d %d\n",&j,&h,&n,&t)!=EOF)
	{
         if ((jour==j)&&(heure==h)&&(num==n)&&(t==0))
  	  {
	        sprintf(texte,"Pas de fumée");
		output = lookup_widget(objet,"labelshow");
		/*GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);*/
    		gtk_label_set_text(GTK_LABEL(output),texte);
          }
	
  	else {  
                sprintf(texte,"Il y'a de fumée");
		output = lookup_widget(objet,"labelshow");
		/*GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color); */
    		gtk_label_set_text(GTK_LABEL(output),texte);} 


             }
fclose(f);
}
}



void
on_quitwindowextras_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *winmen;
    	winmen=lookup_widget(button,"windowextras");
    	gtk_widget_destroy(winmen);
}

