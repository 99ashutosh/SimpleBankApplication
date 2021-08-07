#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include "bank.h"

int main(int argc, char* argv[]){
	extern int user_index;
	GtkBuilder* builder;
	GtkWidget* window;

	gtk_init(&argc, &argv);
	builder = gtk_builder_new_from_file("../glade/utils.glade");
	window = GTK_WIDGET(gtk_builder_get_object(builder, "err_dialog"));
	gtk_builder_connect_signals(builder, NULL);

	getFile();
    if (getFile()==3){
        gtk_widget_show(window);
    }
	greet_main();

	user_index = get_user_index();
	dashboard_main(user_index,'\0','\0');

	g_object_unref(builder);
	gtk_main();
}

G_MODULE_EXPORT void on_err_dialog_destroy(){
    gtk_main_quit();
}