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

}

// show answer callback
void show_answer(GtkWidget question_event_box, gpointer data) {

	// declare external gtk container widgets
	extern GtkWidget * main_screen_vbox, * answer_vbox, * question_vbox;

	// reference to question vbox
	g_object_ref(question_vbox);

	// hide the window while modifying
	gtk_widget_hide(main_screen_vbox);

	// remove old child
	gtk_container_remove(GTK_CONTAINER (main_screen_vbox), question_vbox);

	// add the answer box
	gtk_box_pack_start(GTK_BOX (main_screen_vbox), answer_vbox, TRUE, TRUE, 5);

	// show all the widgets again
	gtk_widget_show_all(main_screen_vbox);

};

// next question callback
void next_question(GtkWidget button, gboolean * correct) {

	// declare external gtk container widgets
	extern GtkWidget * main_screen_vbox, * answer_vbox, * question_vbox;

	// reference to answer vbox
	g_object_ref(answer_vbox);

	// hide the window while modifying
	gtk_widget_hide(main_screen_vbox);

	// remove old child
	gtk_container_remove(GTK_CONTAINER (main_screen_vbox), answer_vbox);

	// add the question box
	gtk_box_pack_start(GTK_BOX (main_screen_vbox), question_vbox, TRUE, TRUE, 5);

	// show all the widgets again
	gtk_widget_show_all(main_screen_vbox);

};
