#include <gtk/gtk.h>

GtkWidget *g_dashboard_notebook;

typedef struct {  //Home Tab
	GtkWidget *g_home_pane;
	GtkWidget *g_img_home;
	
	// All home_bal widgets
	GtkWidget *g_home_bal_pane;
	GtkWidget *g_lbl_home_bal_wel;
	GtkWidget *g_lbl_current_bal;
	GtkWidget *g_lbl_home_bal;
	GtkWidget *g_lbl_home_accid;
	GtkWidget *g_home_bal_sep;
	GtkWidget *g_lbl_home_mess;
	GtkWidget *g_home_bal_notifs;
	
	// All home_details widgets
	GtkWidget *g_home_details_pane;
	GtkWidget *g_img_home_acc;
	GtkWidget *g_lbl_home_lastlogin;
	GtkWidget *g_lbl_home_acc_details;
	GtkWidget *g_lbl_home_name;
	GtkWidget *g_lbl_home_email;
	GtkWidget *g_lbl_home_mob_no;
	GtkWidget *g_lbl_home_upi_handler;
	GtkWidget *g_lbl_home_upi_passcode;
	GtkWidget *g_lbl_home_upi;
	
	GtkWidget *g_img_home_acc_img;
	GtkWidget *g_img_visible;
	GtkWidget *g_img_home_name;
	GtkWidget *g_img_home_email;
	GtkWidget *g_img_home_mobno;
	GtkWidget *g_img_home_upi;
	GtkWidget *g_img_home_upih;
	GtkWidget *g_img_home_upip;
	GtkWidget *g_img_home_lastlogin;
	
	GtkWidget *g_home_data_sep;
	GtkWidget *g_home_details_1;
	GtkWidget *g_home_sep2;
} homeWidgets;

typedef struct{
	GtkWidget *g_add_funds_pane;
	GtkWidget *g_img_add_funds;
} add_funds_Widgets;

typedef struct {  //Withdraw Tab
	GtkWidget *g_withd_pane;
	GtkWidget *g_img_withd;
	
	// All withdraw widgets
	GtkWidget *g_pane_withdraw;
	GtkWidget *g_lbl_withd_wel;
	GtkWidget *g_lbl_witd;
	GtkWidget *g_lbl_withd_method1;
	GtkWidget *g_lbl_witd_pass;
	
	GtkWidget *g_entry_withd_amt;
	GtkWidget *g_entry_withd_pass;
	GtkWidget *g_entry_withd_accid;
	GtkWidget *g_entry_withd_upir;
	
	GtkWidget *g_sep_witd;
	GtkWidget *g_btn_withdraw;
	
	GtkWidget *g_rad_neft;
	GtkWidget *g_rad_upi;
	GtkWidget *g_rad_cred_deb;
	
	// All withdraw information widgets
	GtkWidget *g_pane_withdraw_info;
	
	GtkWidget *g_lbl_info1;
	GtkWidget *g_lbl_info2;
	GtkWidget *g_lbl_info3;
	GtkWidget *g_lbl_withd_bal;
	
	GtkWidget *g_sep_withd2;
} withdraw_Widgets;

typedef struct {           //UPI tab
	GtkWidget *g_upi_pane;
	GtkWidget *g_img_upi;
	
	// All Upi pin widgets
	GtkWidget *g_upi_butn_pane;
	GtkWidget *g_lbl_upi_enable;
	GtkWidget *g_lbl_upi_pass_info;
	GtkWidget *g_lbl_pass_no_match;
	GtkWidget *g_lbl_upi_info;
	GtkWidget *g_lbl_upi_info2;
	
	GtkWidget *g_img_upi_ok;
	
	GtkWidget *g_entry_upi_pass;
	GtkWidget *g_entry_upi_repass;
	
	GtkWidget *g_upi_sep;
	GtkWidget *g_switch_upi;
	
	//All upi info widgets
	GtkWidget *g_upi_info_pane;
	GtkWidget *g_lbl_upi_passcode1;
	GtkWidget *g_lbl_upi_details;
	GtkWidget *g_lbl_upi_handler;
	
	GtkWidget *g_switch_upi_passcode_visible;
	
	GtkWidget *g_img_upi_logo;
	GtkWidget *g_img_upi_visible;
	GtkWidget *g_img_upi_h1;
	GtkWidget *g_img_upi_pass;
} upi_widgets;

typedef struct {			//Account Settings Tab
	GtkWidget *g_acc_settings_paned;
	GtkWidget *g_img_acc_settings;
	
	// All acc_details widgets
	GtkWidget *g_acc_details_paned;
	GtkWidget *g_lbl_curr_info;
	GtkWidget *g_lbl_name;
	GtkWidget *g_lbl_name_holder;
	GtkWidget *g_lbl_email;
	GtkWidget *g_lbl_email_holder;
	GtkWidget *g_lbl_mobile;
	GtkWidget *g_lbl_mobile_holder;
	GtkWidget *g_lbl_upi;
	GtkWidget *g_lbl_mod_info;
	GtkWidget *g_lbl_mod_wel;
	GtkWidget *g_lbl_info;
	GtkWidget *g_lbl_inf1;
	
	GtkWidget *g_entry_new_email;
	GtkWidget *g_entry_new_mobile;
	GtkWidget *g_entry_new_password;
	
	GtkWidget *g_sep_curr_acc_sett;
	GtkWidget *g_sep_2;
	
	GtkWidget *g_check_email;
	GtkWidget *g_check_no;
	GtkWidget *g_check_pass;
	
	// All acc_settings info widgets
	GtkWidget *g_lbl_change_info;
	GtkWidget *g_ent_pass;
	GtkWidget *g_btn_change_info;
} acc_settings_widgets;

typedef struct {			//Logout tab
	GtkWidget *g_logout_pane;
	GtkWidget *g_img_logout;	
	
	// All logout widgets
	GtkWidget *g_logout_pan;
	GtkWidget *g_btn_logout;
	GtkWidget *g_btn_exit;
	
	// All about widgets
	GtkWidget *g_about_fixed;
	GtkWidget *g_img_about;
	GtkWidget *g_img_bank;

	GtkWidget *g_lbl_about;
	GtkWidget *g_lbl_about_2;
} logout_widgets;



int main(int argc, char *argv[]){
	GtkBuilder *builder;
	GtkWidget *window;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file (builder, "dashboard.glade", NULL);
	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "dashboard_main"));
    gtk_builder_connect_signals(builder, NULL);
    
	g_object_unref(builder);
	gtk_widget_show(window);            
	
    gtk_main();
    	
    return 0;
}	