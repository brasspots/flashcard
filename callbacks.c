// callback definitions for flash card

// include callback header
#include "callbacks.h"

// guard on gtk
#ifndef GTK_FOR_FLASH_CARD
#define GTK_FOR_FLASH_CARD

// get gtk
#include <gtk/gtk.h>

// end the guard on gtk
#endif

// destroy window callback
void destroy(GtkWidget window, gpointer data) {

	// quit gtk
	gtk_main_quit();

};

// next question callback
void next_question_correct(GtkWidget button, change_screen_data * data) {

	// do correct stuff

	// change the screen
	change_screen(button, data);

};

void next_question_incorrect(GtkWidget button, change_screen_data * data) {

	// do incorrect stuff

	// change the screen
	change_screen(button, data);

};

void change_screen(GtkWidget widget, change_screen_data * data) {


	// acquire current child
	GtkWidget * current_child = gtk_container_get_children(GTK_CONTAINER (data->main_screen_vbox))->data;

	// make a reference to the current child so it isn't hit by garbage collection when we remove it
	g_object_ref(current_child);

	// remove the current child from the main screen vbox
	gtk_container_remove(GTK_CONTAINER (data->main_screen_vbox), current_child);

	// add the new child
	gtk_box_pack_start(GTK_BOX (data->main_screen_vbox), data->new_child, TRUE, TRUE, 5);

	// show the new child
	gtk_widget_show_all(data->main_screen_vbox);

};
