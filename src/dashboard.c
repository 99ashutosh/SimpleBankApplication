#include <gtk/gtk.h>
#include <string.h>
#include "bank.h"

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

    upi_widgets  *upi_data = g_slice_new(upi_widgets);

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("../glade/dashboard.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "dashboard_main"));

    upi_data->g_lbl_pass_no_match = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_pass_no_match"));
    upi_data->g_upi_img_ok = GTK_WIDGET(gtk_builder_get_object(builder, "img_upi_ok"));
    upi_data->g_lbl_upi_handler = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_upi_handler"));
    upi_data->g_lbl_upi_passcode1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_upi_passcode1"));

    gtk_label_set_text(upi_data->g_lbl_upi_handler,s[index].upiId);
    gtk_label_set_text(upi_data->g_lbl_upi_passcode1,s[index].upiPass);

    gtk_widget_set_visible(upi_data->g_upi_img_ok, FALSE);
    gtk_widget_set_visible(upi_data->g_lbl_pass_no_match, FALSE);


    gtk_builder_connect_signals(builder, upi_data);
    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    g_slice_free(upi_widgets, upi_data);
    return 0;

}

void on_btn_update_upi_clicked (GtkButton *btn_update_upi, upi_widgets *upi_data){

}