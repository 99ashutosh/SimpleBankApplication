#include <gtk/gtk.h>
#include "bank.h"

GtkWidget* g_check;
GtkWidget* g_lbl_user_exists;
GtkWidget* g_lbl_create_success;
GtkWidget* g_lbl_strong;
GtkWidget* g_lbl_weak;
GtkWidget* g_pass_progress;
GtkWidget* g_img_user_valid;
GtkWidget* g_lbl_retype_err;
GtkWidget* g_img_retype_success;
GtkWidget* g_lbl_login_user_err;
GtkWidget* g_lbl_login_pass_err;
GtkWidget* popover;
GtkWidget* g_entry_new_password;
GtkWidget* g_entry_login_username;
GtkWidget* g_entry_login_password;
GtkWidget *g_btn_greet_create_username;
GtkWidget *g_entry_new_username;
GtkWidget *g_entry_new_password;
GtkWidget *g_entry_new_retype_password;
GtkWidget *g_entry_new_mobno;
GtkWidget *g_entry_new_email;

int greet_main(int argc, char* argv[]) {
    GtkBuilder* builder;
    GtkWidget* window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("../glade/greet_final.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "greet_main_window"));
    gtk_builder_connect_signals(builder, NULL);

    g_entry_new_password = GTK_WIDGET(gtk_builder_get_object(builder, "entry_new_password"));

    popover = GTK_WIDGET(gtk_builder_get_object(builder, "pass_hint"));
    g_lbl_user_exists = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_user_exists"));
    g_lbl_create_success = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_create_success"));
    g_lbl_strong = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_strong"));
    g_lbl_weak = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_weak"));
    g_check = GTK_WIDGET(gtk_builder_get_object(builder, "spin_check"));
    g_img_user_valid = GTK_WIDGET(gtk_builder_get_object(builder, "user_does_not_exist"));
    g_lbl_retype_err = GTK_WIDGET(gtk_builder_get_object(builder, "retype_err"));
    g_img_retype_success = GTK_WIDGET(gtk_builder_get_object(builder, "retype_fail"));
    g_lbl_login_user_err = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_username_err"));
    g_lbl_login_pass_err = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_login_pass_err"));
    g_entry_login_username = GTK_WIDGET(gtk_builder_get_object(builder, "entry_login_username"));
    g_entry_login_password = GTK_WIDGET(gtk_builder_get_object(builder, "entry_password"));
    g_btn_greet_create_username = GTK_WIDGET(gtk_builder_get_object(builder, "btn_greet_create_user"));

    g_entry_new_username = GTK_WIDGET(gtk_builder_get_object(builder, "entry_new_username"));
    g_entry_new_password = GTK_WIDGET(gtk_builder_get_object(builder, "entry_new_password"));
    g_entry_new_retype_password = GTK_WIDGET(gtk_builder_get_object(builder, "entry_new_retype_password"));
    g_entry_new_mobno = GTK_WIDGET(gtk_builder_get_object(builder, "entry_new_mobno"));
    g_entry_new_email = GTK_WIDGET(gtk_builder_get_object(builder, "entry_new_email"));

    g_pass_progress = GTK_WIDGET(gtk_builder_get_object(builder, "pass_progress"));

    gtk_widget_set_visible(g_lbl_retype_err, FALSE);
    gtk_widget_set_visible(g_img_retype_success, FALSE);
    gtk_spinner_start(GTK_SPINNER(g_check));
    gtk_widget_set_visible(g_lbl_user_exists, FALSE);
    gtk_widget_set_visible(g_lbl_create_success, FALSE);
    gtk_widget_set_visible(g_lbl_weak, FALSE);
    gtk_widget_set_visible(g_lbl_strong, FALSE);
    gtk_widget_set_visible(g_img_user_valid, FALSE);
    gtk_widget_set_visible(g_lbl_login_user_err, FALSE);
    gtk_widget_set_visible(g_lbl_login_pass_err, FALSE);

    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();
}

G_MODULE_EXPORT void win_destroy() {
    gtk_main_quit();
}

G_MODULE_EXPORT void on_btn_exit_create_clicked() {
    gtk_main_quit();
}

G_MODULE_EXPORT void on_btn_exit_clicked() {
    gtk_main_quit();
}

G_MODULE_EXPORT void on_entry_new_password_changed(GtkWidget* widget, gpointer window) {
    gtk_widget_set_visible(g_lbl_strong, FALSE);
    gtk_widget_set_visible(g_lbl_weak, FALSE);
    const gchar* password = gtk_entry_get_text(GTK_ENTRY(g_entry_new_password));
    gtk_widget_show(popover);
    if (strlen(password) == 0) {
        gtk_widget_show(popover);
        gtk_progress_bar_set_fraction(g_pass_progress, 0);
    }
    else if (strlen(password) < 8) {
        gtk_widget_hide(popover);
        gtk_progress_bar_set_fraction(g_pass_progress, 0.5);
        gtk_widget_set_visible(g_lbl_weak, TRUE);
    }
    else if (strlen(password) < 13) {
        gtk_widget_hide(popover);
        gtk_progress_bar_set_fraction(g_pass_progress, 1);
        gtk_widget_set_visible(g_lbl_strong, TRUE);

    }
}

G_MODULE_EXPORT void on_btn_login_clicked(GtkWidget* wid, gpointer data) {
    gtk_widget_set_visible(g_lbl_login_user_err, FALSE);
    gtk_widget_set_visible(g_lbl_login_pass_err, FALSE);
    //	gtk_widget_set_sensitive(g_btn_login, FALSE);
    const gchar* username = gtk_entry_get_text(GTK_ENTRY(g_entry_login_username));
    const gchar* password = gtk_entry_get_text(GTK_ENTRY(g_entry_login_password));
    if (login(username, password) == 1) {
        gtk_widget_set_visible(g_lbl_login_user_err, TRUE);
    }
    else if (login(username, password) == 2) {
        gtk_widget_set_visible(g_lbl_login_pass_err, TRUE);
    }
    else if (login(username, password) == 0) {
        user_index = get_user_index(username);
        dashboard_main(user_index,'\0','\0');
    }
}
// TODO: Definitions of many gtk calls missing
G_MODULE_EXPORT void on_entry_new_username_changed(GtkWidget *widget, gpointer window){
    gtk_widget_set_sensitive(g_btn_greet_create_username, TRUE);
    gtk_spinner_start(GTK_SPINNER(g_check));
    gtk_widget_set_visible(g_lbl_user_exists, FALSE);
    gtk_widget_set_visible(g_img_user_valid, FALSE);
    const char *username = gtk_entry_get_text(GTK_ENTRY(g_entry_new_username));
    if (strlen(username) == 0) {
        gtk_spinner_start(GTK_SPINNER(g_check));
        gtk_widget_set_sensitive(g_btn_greet_create_username, FALSE);
    }else if (find(username)==0){
        gtk_spinner_stop(GTK_SPINNER(g_check));
        gtk_widget_set_visible(g_lbl_user_exists, TRUE);
        gtk_widget_set_sensitive(g_btn_greet_create_username, FALSE);
    } else if (find(username)==1){
        gtk_spinner_stop(GTK_SPINNER(g_check));
        gtk_widget_set_visible(g_img_user_valid, TRUE);
    }
}

G_MODULE_EXPORT void on_entry_new_retype_password_changed(GtkWidget *widget, gpointer window){
    gtk_widget_set_sensitive(g_btn_greet_create_username, FALSE);
    gtk_widget_set_visible(g_lbl_retype_err, FALSE);
    gtk_widget_set_visible(g_img_retype_success, FALSE);
    const char *password = gtk_entry_get_text(GTK_ENTRY(g_entry_new_password));
    const char *repeat_password = gtk_entry_get_text(GTK_ENTRY(g_entry_new_retype_password));
    if (strlen(password) == strlen(repeat_password)){
        gtk_widget_set_sensitive(g_btn_greet_create_username, TRUE);
        gtk_widget_set_visible(g_img_retype_success, TRUE);
    } else {
        gtk_widget_set_sensitive(g_btn_greet_create_username, FALSE);
        gtk_widget_set_visible(g_lbl_retype_err, TRUE);
    }
}

G_MODULE_EXPORT void on_btn_greet_create_user_clicked(GtkWidget *wid,gpointer data){
    const char *username = gtk_entry_get_text(GTK_ENTRY(g_entry_new_username));
    const char *password = gtk_entry_get_text(GTK_ENTRY(g_entry_new_password));
    const char *repeat_password = gtk_entry_get_text(GTK_ENTRY(g_entry_new_retype_password));
    const int number = gtk_entry_get_text(GTK_ENTRY(g_entry_new_retype_password));
    const char *email = gtk_entry_get_text(GTK_ENTRY(g_entry_new_retype_password));
    signup(username, password, number, email);
}

