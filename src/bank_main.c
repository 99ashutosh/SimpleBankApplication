#include <gtk/gtk.h>
#include "bank.h"

int bank_main(int argc, char *argv[]){
    GtkBuilder *builder; 
    GtkWidget *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("../glade/dashboard.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "dashboard_main"));
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();
}

G_MODULE_EXPORT void on_btn_exit_clicked (){
	gtk_main_quit();
}

G_MODULE_EXPORT void on_btn_logout_clicked (){
	gtk_main_quit();
}