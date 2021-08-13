#include <gtk/gtk.h>
#include <string.h>
#include "bank.h"

extern struct customer s[100];

typedef struct {  //Home Tab
    // All home_bal widgets
    GtkWidget *g_lbl_home_bal;
    GtkWidget *g_lbl_home_acc_id;

    // All home_details widgets
    GtkWidget *g_lbl_home_lastlogin;
    GtkWidget *g_lbl_home_name;
    GtkWidget *g_lbl_home_email;
    GtkWidget *g_lbl_home_mob_no;
    GtkWidget *g_lbl_home_upi_handler;
    GtkWidget *g_lbl_home_upi_passcode;

    //Add funds tab
    GtkWidget *g_lbl_add_bal;
    GtkWidget *g_entry_add_amt;
    GtkWidget *g_btn_add_funds;
    GtkWidget *g_entry_add_pass1;

    //UPI tab
    // All Upi pin widgets
    GtkWidget *g_lbl_pass_no_match;
    GtkWidget *g_lbl_pass_set;
    GtkWidget *g_lbl_pass_set_fail;
    GtkWidget *g_entry_upi_pass;
    GtkWidget *g_entry_upi_repass;
    GtkWidget *g_switch_upi;
    GtkWidget *g_upi_img_ok;
    //All upi info widgets
    GtkWidget *g_lbl_upi_passcode1;
    GtkWidget *g_lbl_upi_handler;
    GtkWidget *g_switch_upi_passcode_visible;

    //Account Mod widgets
    // All acc_details widgets
    GtkWidget *g_lbl_name_holder;
    GtkWidget *g_lbl_email_holder;
    GtkWidget *g_lbl_mobile_holder;
    GtkWidget *g_entry_new_email;
    GtkWidget *g_entry_new_mobile;
    GtkWidget *g_entry_new_password;
    GtkWidget *g_entry_password_mod;
    GtkWidget *g_check_email;
    GtkWidget *g_check_no;
    GtkWidget *g_check_pass;
    GtkWidget *g_btn_change_info;

} appWidgets;

int user_index;

int dashboard_main(int index, int argc, char *argv[]){
    user_index = index;
    GtkBuilder* builder;
    GtkWidget* window;

    appWidgets  *app_data = g_slice_new(appWidgets);

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("../glade/dashboard.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "dashboard_main"));

    //Home widgets defied here
    app_data->g_lbl_home_acc_id = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_home_acc_id"));
    app_data->g_lbl_home_bal = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_home_balance"));
    app_data->g_lbl_home_email = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_home_email"));
    app_data->g_lbl_home_upi_passcode = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_home_upi_passcode"));
    app_data->g_lbl_home_upi_handler = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_home_upi_handler"));
    app_data->g_lbl_home_lastlogin = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_home_lastlogin"));
    app_data->g_lbl_home_mob_no = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_home_mob_no"));
    app_data->g_lbl_home_name = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_home_name"));

    //Add Funds widgets defined here
    app_data->g_btn_add_funds = GTK_WIDGET(gtk_builder_get_object(builder, "btn_add_funds"));
    app_data->g_entry_add_amt = GTK_WIDGET(gtk_builder_get_object(builder, "entry_add_amt"));
    app_data->g_entry_add_pass1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_add_pass1"));
    app_data->g_lbl_add_bal = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_add_bal"));

    //UPI widgets defined here
    app_data->g_lbl_pass_no_match = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_pass_no_match"));
    app_data->g_lbl_pass_set = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_pass_set"));
    app_data->g_lbl_pass_set_fail = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_pass_set_fail"));
    app_data->g_upi_img_ok = GTK_WIDGET(gtk_builder_get_object(builder, "img_upi_ok"));
    app_data->g_lbl_upi_handler = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_upi_handler"));
    app_data->g_lbl_upi_passcode1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_upi_passcode1"));
    app_data->g_entry_upi_pass = GTK_WIDGET(gtk_builder_get_object(builder, "entry_upi_pass"));
    app_data->g_entry_upi_repass = GTK_WIDGET(gtk_builder_get_object(builder, "entry_upi_repass"));

    //Account Details (modify) defined here
    app_data->g_lbl_name_holder = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_name"));
    app_data->g_lbl_mobile_holder = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_mobile"));
    app_data->g_lbl_email_holder = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_email"));
    app_data->g_entry_new_email = GTK_WIDGET(gtk_builder_get_object(builder, "entry_new_email"));
    app_data->g_entry_new_mobile = GTK_WIDGET(gtk_builder_get_object(builder, "entry_new_mobile"));
    app_data->g_entry_new_password = GTK_WIDGET(gtk_builder_get_object(builder, "entry_new_password"));
    app_data->g_entry_password_mod = GTK_WIDGET(gtk_builder_get_object(builder, "ent_pass"));
    app_data->g_check_pass = GTK_WIDGET(gtk_builder_get_object(builder, "check_pass"));
    app_data->g_check_no = GTK_WIDGET(gtk_builder_get_object(builder, "check_no"));
    app_data->g_check_email = GTK_WIDGET(gtk_builder_get_object(builder, "check_email"));
    app_data->g_btn_change_info = GTK_WIDGET(gtk_builder_get_object(builder, "btn_change_info"));

    //TODO: Segfaults in labels with int
    //Home Data set
    gtk_label_set_text(app_data->g_lbl_home_name,s[index].userName);
    gtk_label_set_text(app_data->g_lbl_home_email,s[index].email);
    gtk_label_set_text(app_data->g_lbl_home_mob_no,s[index].mob_no);
    gtk_label_set_text(app_data->g_lbl_home_upi_handler,s[index].upiId);
    gtk_label_set_text(app_data->g_lbl_home_upi_passcode,"******");
    gtk_label_set_text(app_data->g_lbl_home_lastlogin,s[index].last_login);
    gtk_label_set_text(app_data->g_lbl_home_acc_id,s[index].accNo);
    //gtk_label_set_text(app_data->g_lbl_home_bal,(int)s[index].balance);

    //Add Funds data set
    //gtk_label_set_label(app_data->g_lbl_add_bal,(int)s[index].balance);

    //UPI Data set
    gtk_label_set_text(app_data->g_lbl_upi_handler,s[index].upiId);
    //gtk_label_set_text(app_data->g_lbl_upi_passcode1,(char)s[index].upiPass);

    //Account Details (modify) data set
    gtk_label_set_text(app_data->g_lbl_name_holder,s[index].userName);
    gtk_label_set_text(app_data->g_lbl_email_holder,s[index].email);
    gtk_label_set_text(app_data->g_lbl_mobile_holder,s[index].mob_no);

    //Visibility
    gtk_widget_set_visible(app_data->g_upi_img_ok, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_pass_no_match, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_pass_set, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_pass_set_fail, FALSE);

    //Signal Connect and exit
    gtk_builder_connect_signals(builder, app_data);
    g_object_unref(builder);

    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_widget_show(window);
    gtk_main();

    g_slice_free(appWidgets, app_data);

    return 0;
}
G_MODULE_EXPORT void on_dashboard_main_destroy(){
    gtk_main_quit();
}
// UPI PI-PIN Update function
G_MODULE_EXPORT void on_btn_update_upi_clicked (GtkButton *btn_update_upi, appWidgets *app_data){
    gtk_widget_set_visible(app_data->g_upi_img_ok, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_pass_no_match, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_pass_set, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_pass_set_fail, FALSE);
    const char *password = gtk_entry_get_text(GTK_ENTRY(app_data->g_entry_upi_pass));
    const char *repeat_password = gtk_entry_get_text(GTK_ENTRY(app_data->g_entry_upi_repass));
    if (strcmp(password, repeat_password) == '0' || strcmp(password, repeat_password) == 0){
        if (set_upi_pass(user_index, password) == 1){
            gtk_widget_set_visible(app_data->g_lbl_pass_set, TRUE);
            reload(user_index);
        } else {
            gtk_widget_set_visible(app_data->g_lbl_pass_set_fail, TRUE);
            reload(user_index);
        }
    } else {
        gtk_widget_set_visible(app_data->g_lbl_pass_no_match, TRUE);
        reload(user_index);
    }
}

G_MODULE_EXPORT void on_btn_logout_clicked (GtkButton *btn_logout, gpointer window){
    gtk_widget_hide(window);
}

G_MODULE_EXPORT void on_btn_dashboard_exit_clicked (GtkButton *btn_exit){
    //TODO: Finish logout functions
    gtk_main_quit();
}

void reload(int index, appWidgets *app_data){
    gtk_label_set_text(app_data->g_lbl_home_name,s[index].userName);
    gtk_label_set_text(app_data->g_lbl_home_email,s[index].email);
    gtk_label_set_text(app_data->g_lbl_home_mob_no,s[index].mob_no);
    gtk_label_set_text(app_data->g_lbl_home_upi_handler,s[index].upiId);
    gtk_label_set_text(app_data->g_lbl_home_upi_passcode,"******");
    gtk_label_set_text(app_data->g_lbl_home_lastlogin,s[index].last_login);
    gtk_label_set_text(app_data->g_lbl_home_acc_id,s[index].accNo);
    //gtk_label_set_text(app_data->g_lbl_home_bal,(int)s[index].balance);

    //gtk_label_set_label(app_data->g_lbl_add_bal,(int)s[index].balance);
    gtk_label_set_text(app_data->g_lbl_upi_handler,s[index].upiId);
    gtk_label_set_text(app_data->g_lbl_upi_passcode1,s[index].upiPass);
}
// Funds add function
void on_btn_add_funds_clicked (GtkButton *btn_add_funds, appWidgets *app_data){

}