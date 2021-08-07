#include <gtk/gtk.h>
#include <string.h>
#include "bank.h"

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
} homeWidgets;

typedef struct{ //Add funds tab
    GtkWidget *g_lbl_add_bal;
    GtkWidget *g_entry_add_amt;
    GtkWidget *g_btn_add_funds;
    GtkWidget *g_entry_add_pass1;
} add_funds_Widgets;

typedef struct {           //UPI tab

    // All Upi pin widgets
    GtkWidget *g_lbl_pass_no_match;
    GtkWidget *g_entry_upi_pass;
    GtkWidget *g_entry_upi_repass;
    GtkWidget *g_switch_upi;
    GtkWidget *g_upi_img_ok;
    //All upi info widgets

    GtkWidget *g_lbl_upi_passcode1;
    GtkWidget *g_lbl_upi_handler;

    GtkWidget *g_switch_upi_passcode_visible;
} upi_widgets;

int dashboard_main(int index, int argc, char *argv[]){
    GtkBuilder* builder;
    GtkWidget* window;

    homeWidgets  *home_data = g_slice_new(homeWidgets);
    add_funds_Widgets  *funds_data = g_slice_new(add_funds_Widgets);
    upi_widgets  *upi_data = g_slice_new(upi_widgets);

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("../glade/dashboard.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "dashboard_main"));

    //Home widgets defied here
    home_data->g_lbl_home_acc_id = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_home_acc_id"));
    home_data->g_lbl_home_bal = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_home_bal"));
    home_data->g_lbl_home_email = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_home_email"));
    home_data->g_lbl_home_upi_passcode = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_home_upi_passcode"));
    home_data->g_lbl_home_upi_handler = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_home_upi_handler"));
    home_data->g_lbl_home_lastlogin = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_home_lastlogin"));
    home_data->g_lbl_home_mob_no = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_home_mob_no"));
    home_data->g_lbl_home_name = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_home_name"));

    //Add Funds widgets defined here
    funds_data->g_btn_add_funds = GTK_WIDGET(gtk_builder_get_object(builder, "btn_add_funds"));
    funds_data->g_entry_add_amt = GTK_WIDGET(gtk_builder_get_object(builder, "entry_add_amt"));
    funds_data->g_entry_add_pass1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_add_pass1"));
    funds_data->g_lbl_add_bal = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_add_bal"));

    //UPI widgets defined here
    upi_data->g_lbl_pass_no_match = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_pass_no_match"));
    upi_data->g_upi_img_ok = GTK_WIDGET(gtk_builder_get_object(builder, "img_upi_ok"));
    upi_data->g_lbl_upi_handler = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_upi_handler"));
    upi_data->g_lbl_upi_passcode1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_upi_passcode1"));

    //Home Data set
    gtk_label_set_text(home_data->g_lbl_home_name,s[index].userName);
    gtk_label_set_text(home_data->g_lbl_home_email,s[index].email);
    gtk_label_set_text(home_data->g_lbl_home_mob_no,s[index].mobile_no);
    gtk_label_set_text(home_data->g_lbl_home_upi_handler,s[index].upiId);
    gtk_label_set_text(home_data->g_lbl_home_upi_passcode,"******");
    gtk_label_set_text(home_data->g_lbl_home_lastlogin,s[index].last_login);
    gtk_label_set_text(home_data->g_lbl_home_acc_id,s[index].accNo);
    gtk_label_set_text(home_data->g_lbl_home_bal,s[index].balance);

    //Add Funds data set
    gtk_label_set_text(funds_data->g_lbl_add_bal,s[index].balance);

    //UPI Data set
    gtk_label_set_text(upi_data->g_lbl_upi_handler,s[index].upiId);
    gtk_label_set_text(upi_data->g_lbl_upi_passcode1,s[index].upiPass);

    //Visibility
    gtk_widget_set_visible(upi_data->g_upi_img_ok, FALSE);
    gtk_widget_set_visible(upi_data->g_lbl_pass_no_match, FALSE);

    //Signal Connect and exit
    gtk_builder_connect_signals(builder, upi_data);
    gtk_builder_connect_signals(builder, home_data);
    g_object_unref(builder);

    gtk_window_set_resizable(GTK_WINDOW(window) FALSE);
    gtk_widget_show(window);
    gtk_main();

    g_slice_free(homeWidgets, home_data);
    g_slice_free(add_funds_Widgets, funds_data);
    g_slice_free(upi_widgets, upi_data);

    return 0;

}

G_MODULE_EXPORT void on_btn_update_upi_clicked (GtkButton *btn_update_upi, upi_widgets *upi_data){
//TODO: Finish UPI function
}

G_MODULE_EXPORT void on_btn_logout_clicked (GtkButton *btn_logout){
//TODO: Finish logout functions
}

G_MODULE_EXPORT void on_btn_exit_clicked (GtkButton *btn_exit, user_data){
    //TODO: Finish logout functions
    gtk_main_quit();
}