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
void show_answer(GtkWidget question_event_box, GtkWidget ** main_screens_array) {

	// hide all the widgets while the switch takes place
	gtk_widget_hide(main_screens_array[MAIN_SCREEN]);

	// remove the question vbox from the main screen vbox
	gtk_container_remove(GTK_CONTAINER (main_screens_array[MAIN_SCREEN]), main_screens_array[QUESTION_SCREEN]);

	// pack in the answer screen
	gtk_box_pack_start(GTK_BOX (main_screens_array[MAIN_SCREEN]), main_screens_array[ANSWER_SCREEN], TRUE, TRUE, 5);

	// show the new widgets
	gtk_widget_show_all(main_screens_array[MAIN_SCREEN]);

};

// next question callback
void next_question(GtkWidget button, GtkWidget ** main_screens_array) {

	// record stats based on which button was pressed

	// hide all the widgets while the switch takes place
	gtk_widget_hide(main_screens_array[MAIN_SCREEN]);

	// get new question and insert its information into quetsion and answer boxes

	// remove the answer vbox from main screen vbox
	gtk_container_remove(GTK_CONTAINER (main_screens_array[MAIN_SCREEN]), main_screens_array[ANSWER_SCREEN]);

	// pack in the question screen
	gtk_box_pack_start(GTK_BOX (main_screens_array[MAIN_SCREEN]), main_screens_array[QUESTION_SCREEN], TRUE, TRUE, 5);

	// show the widgets
	gtk_widget_show_all(main_screens_array[MAIN_SCREEN]);

};
