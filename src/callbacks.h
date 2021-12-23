#include <gtk/gtk.h>

/******* ACCEUIL ************/
void
on_EXTRA_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_STOCK_clicked                       (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_HEBERGEMENT_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_CAPTEUR_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_UTILISATEUR_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_RESTAURATION_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_RECLAMATION_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);
/********************* CAPTEUR RADHWEN ******************/
void
on_radiobuttonmouv_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttontemp_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonfum_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttondeb_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonconfirmadd_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonretadd_clicked                (GtkWidget         *objet,
                                        gpointer         user_data);


void
on_buttonaddcap_clicked                (GtkWidget         *objet,
                                        gpointer         user_data);



void
on_buttondelconfirm_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonretdel_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttondelcap_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeviewcap_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_radiobuttonmouvedit_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonconsultid_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonretedit_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonsavevhange_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobuttonfumedit_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttontempedit_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttondebedit_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttoneditcap_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonrefresh_clicked               (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_buttonfindcap_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonfindok_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeviewfind_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonretfind_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonotherfind_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_labeldeftemp_show                   (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_Retourcapacceuil_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);
/************* FIN CAPTEUR ***************/

/*************etudiant******************/




void
on_treeview1_am_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

gboolean
on_treeview1_am_select_cursor_row      (GtkTreeView     *treeview,
                                        gboolean         start_editing,
                                        gpointer         user_data);

void
on_button9Display0_am_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1Add0_am_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2Modify0_am_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3Delete_am_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4Search0_am_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button5Back1_am_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6Add1_am_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button12Modify_am_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button8Back2_am_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton3_am_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_am_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button10Displaymod2_am_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button11ValiderMod_am_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton55_am_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton66_am_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button13ValiderAj_am_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton1_am_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_am_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button14ValiderSup_am_clicked       (GtkButton       *button,
                                        gpointer         user_data);
void
on_button36_am_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);


/*********************RECCL Hamdi ***************/






/////////////////////////ajouter///////////////////////////////
void
on_button_ajouter_rec_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_button_envoyer_rec_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_button_prec_ajout_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);
///////////////////////////chercher/////////////////////////////////

void
on_button_chercher_rec_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_button_cherch_rec_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_button_prec_cherch_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);
//////////////////////////modifier///////////////////////////////

void
on_button_modifier_rec_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_button_modif_rec_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_button_prec_modif_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_button_consulter_rec_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);
/////////////////////////supprimer/////////////////////////////////

void
on_button_supprimer_rec_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_button_suppr_rec_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
void
on_button_prec_suppr_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);
///////////////////////////check & radio//////////////////////////////
void
on_radiobutton_homme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_service_resto_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_service_heberg_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
/////////////////////tree view//////////////////////////////////////
void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
void
on_button_actualiser_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_button_prec_tree_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

//////////////////////////tache 2////////////////////////////////////
void
on_button_prec_serv_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_button_serv_rec_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);
////////////////////////mfaskhine//////////////////////////////////
void
on_button_precedent_clicked            (GtkWidget       *objet,
                                        gpointer         user_data); 
void
on_button_afficher_clicked             (GtkWidget       *objet,
                                        gpointer         user_data); 
void
on_button_service_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_button_espcae_rec_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

/************FIN RECLAMATION-HAMDI***********/


/*************UTILISATEURS-ADEM************/





void
on_ajouterUser_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_homme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_afficher_user_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajouterUtilisateur_clicked         (GtkWidget      *objet,
                                        gpointer         user_data);

gboolean
on_treeview1_popup_menu                (GtkWidget       *widget,

                                        gpointer         user_data);

gboolean
on_treeview1_button_press_event         (GtkWidget *treeview, GdkEventButton *event, gpointer userdata);

void
on_rechercherUser_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourU_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modifierUser_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_hommem_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femmem_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_afficher_mouvement_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_afficher_fumee_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

/*void
on_login_clicked                       (GtkWidget       *button,
                                        gpointer         user_data); */

void
on_buttonuseracceuil_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

/***********************STOCK ahmed**********************/






void
on_destroy1_ahmed_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retirer_ahmed_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modifier_ahmed_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajouter_ahmed_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_chercher_ahmed_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retour1_ahmed_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_destroy2_ahmed_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retour2_ahmed_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retour3_ahmed_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_destroy3_ahmed_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajouter1_ahmed_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modifier1_ahmed_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_destroy4_ahmed_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retour4_ahmed_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retirer1_ahmed_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retour5_ahmed_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_destroy5_ahmed_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_fruit1_ahmed_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_legume1_ahmed_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_autre1_ahmed_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fruit2_ahmed_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_legume2_ahmed_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_autre2_ahmed_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

/************ MAIN APP ****************/

void
on_buttonsignup_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonlogin_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonloginconfirm_clicked          (GtkWidget       *button,
                                        gpointer         user_data);



void
on_checkbuttonpassword_toggled         (GtkWidget *objet,
                                        gpointer         user_data);

void
on_buttoncancellogin_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttoncloseapp_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonadmin_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonvalidadmin_clicked            (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_buttonadmintomain_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);








/****************************** menu oussema **************************************/




void
on_treeview22_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_ajout_ob_clicked                (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_button_chercher_ob_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_button_modifier_ob_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_button_suppr_ob_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_button_ajouter_mob_clicked          (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_button_retourner_mob_clicked        (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_button_accmob_clicked               (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_button_supp_mob_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_button_acc_mob_clicked              (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_button_retoursupp_mob_clicked       (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_button_ret_modif_clicked            (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_button_modif_modif_clicked          (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_button_acc_modif_clicked            (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_button_actualiser_ob_clicked           (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_button_ret_cher_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_chercher_cherch_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton_ob1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_ob2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_conf_supp_b_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_button_retour_ob_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_quitacceuil_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttondeconnexion_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitwindowlogin_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitwindowespaceadmin_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitaddcap_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitgestcap_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitdelcap_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitGestionEtudiants_am_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitAjouterEtudiants_am_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitModifierEtudiant_am_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitAjouterEtudiant_am_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitConfirmerAjout_am_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitConfirmerSupression_am_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitajouter_rec_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitTree_view_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitsupprimer_rec_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitchercher_rec_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitmodifier_rec_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_quit_gestion_des_utilisateurs_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitmodifier_user_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitajouter_user_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitgestion_des_menus_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitajouterdesmenus_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitsuprime_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitmodification_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitchercherdesmenus_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_quiteditcap_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitfindcap_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

/*******************Extras**********************/


void
on_buttonadem6_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bradhwen_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bhamdi_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bahmed1_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_boussema_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bashref_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bacceuilb_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonadem2_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_quitwindowextras_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_help_clicked                        (GtkButton       *button,
                                        gpointer         user_data);
