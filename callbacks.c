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
void next_question_correct(GtkWidget button, GtkWidget * question_vbox) {

	// do correct stuff

	// change the screen
	change_screen(button, question_vbox);

};

void next_question_incorrect(GtkWidget button, GtkWidget * question_vbox) {

	// do incorrect stuff

	// change the screen
	change_screen(button, question_vbox);

};

void change_screen(GtkWidget widget, GtkWidget * new_child) {


	// acquire current child
	GtkWidget * current_child = gtk_container_get_children(GTK_CONTAINER (main_screen_vbox))->data;

	// make a reference to the current child so it isn't hit by garbage collection when we remove it
	g_object_ref(current_child);

	// remove the current child from the main screen vbox
	gtk_container_remove(GTK_CONTAINER (main_screen_vbox), current_child);

	// add the new child
	gtk_box_pack_start(GTK_BOX (main_screen_vbox), new_child, TRUE, TRUE, 5);

	// show the new child
	gtk_widget_show_all(main_screen_vbox);

};
