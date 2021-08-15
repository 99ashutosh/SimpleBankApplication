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
    GtkWidget *g_lbl_add_success;
    GtkWidget *g_lbl_add_fail;
    GtkWidget *g_entry_add_amt;
    GtkWidget *g_btn_add_funds;
    GtkWidget *g_entry_add_pass1;

    //UPI tab
    // All Upi pin widgets
    GtkWidget *g_lbl_pass_no_match;
    GtkWidget *g_lbl_pass_set;
    GtkWidget *g_lbl_pass_set_fail;
    GtkWidget *g_lbl_upi_warning;
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
    GtkWidget *g_lbl_curr_pass_incorrect;
    GtkWidget *g_lbl_new_set_successful;
    GtkWidget *g_lbl_new_set_fail;
    GtkWidget *g_entry_new_email;
    GtkWidget *g_entry_new_mobile;
    GtkWidget *g_entry_new_password;
    GtkWidget *g_entry_password_mod;
    GtkWidget *g_check_email;
    GtkWidget *g_check_no;
    GtkWidget *g_check_pass;
    GtkWidget *g_btn_change_info;

    //Withdraw Widgets


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
    app_data->g_lbl_add_success = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_add_success"));
    app_data->g_lbl_add_fail = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_add_fail"));

    //UPI widgets defined here
    app_data->g_lbl_pass_no_match = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_pass_no_match"));
    app_data->g_lbl_pass_set = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_pass_set"));
    app_data->g_lbl_pass_set_fail = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_pass_set_fail"));
    app_data->g_lbl_upi_warning = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_upi_warning"));
    app_data->g_upi_img_ok = GTK_WIDGET(gtk_builder_get_object(builder, "img_upi_ok"));
    app_data->g_lbl_upi_handler = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_upi_handler"));
    app_data->g_lbl_upi_passcode1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_upi_passcode1"));
    app_data->g_entry_upi_pass = GTK_WIDGET(gtk_builder_get_object(builder, "entry_upi_pass"));
    app_data->g_entry_upi_repass = GTK_WIDGET(gtk_builder_get_object(builder, "entry_upi_repass"));

    //Account Details (modify) defined here
    app_data->g_lbl_name_holder = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_name"));
    app_data->g_lbl_mobile_holder = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_mobile"));
    app_data->g_lbl_email_holder = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_email"));
    app_data->g_lbl_curr_pass_incorrect = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_pass_incorrect"));
    app_data->g_lbl_new_set_fail = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_acc_fail"));
    app_data->g_lbl_new_set_successful = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_acc_success"));
    app_data->g_entry_new_email = GTK_WIDGET(gtk_builder_get_object(builder, "entry_new_email"));
    app_data->g_entry_new_mobile = GTK_WIDGET(gtk_builder_get_object(builder, "entry_new_mobile"));
    app_data->g_entry_new_password = GTK_WIDGET(gtk_builder_get_object(builder, "entry_new_password"));
    app_data->g_entry_password_mod = GTK_WIDGET(gtk_builder_get_object(builder, "ent_pass"));
    app_data->g_check_pass = GTK_WIDGET(gtk_builder_get_object(builder, "check_no1"));
    app_data->g_check_no = GTK_WIDGET(gtk_builder_get_object(builder, "check_no"));
    app_data->g_check_email = GTK_WIDGET(gtk_builder_get_object(builder, "check_email"));
    app_data->g_btn_change_info = GTK_WIDGET(gtk_builder_get_object(builder, "btn_change_info"));

    //Home Data set
    gtk_label_set_text(app_data->g_lbl_home_name,s[index].userName);
    gtk_label_set_text(app_data->g_lbl_home_email,s[index].email);
    gtk_label_set_text(app_data->g_lbl_home_mob_no,s[index].mob_no);
    gtk_label_set_text(app_data->g_lbl_home_upi_handler,s[index].upiId);
    gtk_label_set_text(app_data->g_lbl_home_upi_passcode,"●●●●●●");
    gtk_label_set_text(app_data->g_lbl_home_lastlogin,s[index].last_login);
    gtk_label_set_text(app_data->g_lbl_home_acc_id,s[index].accNo);
    gchar *bal;
    bal = g_strdup_printf("%d", s[index].balance);
    gtk_label_set_text(app_data->g_lbl_home_bal,bal);


    //Add Funds data set
    gtk_label_set_label(app_data->g_lbl_add_bal,bal);

    //UPI Data set
    gtk_label_set_text(app_data->g_lbl_upi_handler,s[index].upiId);
    gchar *upi_pass;
    upi_pass = g_strdup_printf("%d", s[index].upiPass);
    gtk_label_set_text(app_data->g_lbl_upi_passcode1,upi_pass);

    //Account Details (modify) data set
    gtk_label_set_text(app_data->g_lbl_name_holder,s[index].userName);
    gtk_label_set_text(app_data->g_lbl_email_holder,s[index].email);
    gtk_label_set_text(app_data->g_lbl_mobile_holder,s[index].mob_no);

    //Visibility
    gtk_widget_set_visible(app_data->g_upi_img_ok, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_pass_no_match, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_pass_set, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_pass_set_fail, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_add_success, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_add_fail, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_curr_pass_incorrect, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_new_set_successful, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_new_set_fail, FALSE);

    //For UPI
    if (s[user_index].upiPass == 0){
        gtk_widget_set_visible(app_data->g_lbl_upi_warning, TRUE);
    } else {
        gtk_widget_set_visible(app_data->g_lbl_upi_warning, FALSE);
    }

    //Signal Connect and exit
    gtk_builder_connect_signals(builder, app_data);
    g_object_unref(builder);

    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_widget_show(window);
    gtk_main();

    g_slice_free(appWidgets, app_data);
    g_free(bal);
    g_free(upi_pass);

    return 0;
}
void on_dashboard_main_destroy(){
    putFile();
    gtk_main_quit();
}

void on_btn_logout_clicked (GtkButton *btn_logout, gpointer window){
    putFile();
    gtk_main_quit();
}

void on_btn_dashboard_exit_clicked (GtkButton *btn_exit, gpointer window){
    putFile();
    gtk_main_quit();
}

// UPI PI-PIN Update function
void on_btn_update_upi_clicked (GtkButton *btn_update_upi, appWidgets *app_data){
    gchar *upi_pass;
    if (s[user_index].upiPass == 0){
        gtk_widget_set_visible(app_data->g_lbl_upi_warning, TRUE);
    } else {
        gtk_widget_set_visible(app_data->g_lbl_upi_warning, FALSE);
    }
    gtk_widget_set_visible(app_data->g_upi_img_ok, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_pass_no_match, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_pass_set, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_pass_set_fail, FALSE);
    const char *password = gtk_entry_get_text(GTK_ENTRY(app_data->g_entry_upi_pass));
    const char *repeat_password = gtk_entry_get_text(GTK_ENTRY(app_data->g_entry_upi_repass));
    if (strcmp(password, repeat_password) == 0){
        if (set_upi_pass(user_index, password) == 1){
            gtk_widget_set_visible(app_data->g_lbl_pass_set, TRUE);
            upi_pass = g_strdup_printf("%d", s[user_index].upiPass);
            gtk_label_set_text(app_data->g_lbl_upi_passcode1,upi_pass);
            putFile();
        } else {
            gtk_widget_set_visible(app_data->g_lbl_pass_set_fail, TRUE);
            putFile();
        }
    } else {
        gtk_widget_set_visible(app_data->g_lbl_pass_no_match, TRUE);
        putFile();
    }
    g_free(upi_pass);
}

// Funds add function
void on_btn_add_funds_clicked (GtkButton *btn_add_funds, appWidgets *app_data){
    gchar *bal2;
    gtk_widget_set_visible(app_data->g_lbl_add_success, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_add_fail, FALSE);
    const char *amount = gtk_entry_get_text(GTK_ENTRY(app_data->g_entry_add_amt));
    const char *password = gtk_entry_get_text(GTK_ENTRY(app_data->g_entry_add_pass1));
    if (pass_check(user_index, password)==1){
        deposit(user_index, amount);
        putFile();
        bal2 = g_strdup_printf("%d", s[user_index].balance);
        gtk_label_set_text(app_data->g_lbl_home_bal,bal2);
        gtk_label_set_text(app_data->g_lbl_add_bal,bal2);
        gtk_widget_set_visible(app_data->g_lbl_add_success, TRUE);
    } else {
        gtk_widget_set_visible(app_data->g_lbl_add_fail, TRUE);
    }
    g_free(bal2);
}

// Account Modifications Function
void on_btn_change_info_clicked (GtkButton *btn_change_info, appWidgets *app_data){
    gtk_widget_set_visible(app_data->g_lbl_curr_pass_incorrect, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_new_set_successful, FALSE);
    gtk_widget_set_visible(app_data->g_lbl_new_set_fail, FALSE);
    const char *email = gtk_entry_get_text(GTK_ENTRY(app_data->g_entry_new_email));
    const char *mobile_no = gtk_entry_get_text(GTK_ENTRY(app_data->g_entry_new_mobile));
    const char *new_password = gtk_entry_get_text(GTK_ENTRY(app_data->g_entry_new_password));
    const char *password = gtk_entry_get_text(GTK_ENTRY(app_data->g_entry_password_mod));
    if (pass_check(user_index, password)==1){
        modify_details(user_index, new_password, mobile_no, email);
        putFile();
        gtk_label_set_text(app_data->g_lbl_name_holder,s[user_index].userName);
        gtk_label_set_text(app_data->g_lbl_email_holder,s[user_index].email);
        gtk_label_set_text(app_data->g_lbl_mobile_holder,s[user_index].mob_no);
        gtk_label_set_text(app_data->g_lbl_home_name,s[user_index].userName);
        gtk_label_set_text(app_data->g_lbl_home_email,s[user_index].email);
        gtk_label_set_text(app_data->g_lbl_upi_handler,s[user_index].upiId);
        gtk_label_set_text(app_data->g_lbl_home_mob_no,s[user_index].mob_no);
        gtk_label_set_text(app_data->g_lbl_home_upi_handler,s[user_index].upiId);
        gtk_widget_set_visible(app_data->g_lbl_new_set_successful, TRUE);
    } else {
        gtk_widget_set_visible(app_data->g_lbl_curr_pass_incorrect, TRUE);
        gtk_widget_set_visible(app_data->g_lbl_new_set_fail, TRUE);
    }
}
