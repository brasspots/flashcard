// callback definitions for flash card

// include callback header
#include "callbacks.h"

// guard on gtk
#ifndef GTK_FOR_FLASH_CARD
#define GTK_FOR_FLASH_CARD

// get gtk
#include <gtk/gtk.h>
#include <stdio.h>

// end the guard on gtk
#endif

// destroy window callback
void destroy(GtkWindow * window, gpointer data) {

	// save progress

	// quit gtk
	gtk_main_quit();

};

// record correct answer then get next question callback
void next_question_correct(GtkButton * button, GtkNotebook * qa_notebook) {

	// do correct stuff

	// change the notebook tab
	gtk_notebook_set_current_page(qa_notebook, 0);

	// select a new question
	load_new_question(qa_notebook);

};

// record incorrect answer then get next question callback
void next_question_incorrect(GtkButton * button, GtkNotebook * qa_notebook) {

	// do incorrect stuff

	// change the notebook page
	gtk_notebook_set_current_page(qa_notebook, 0);

	// select a new question
	load_new_question(qa_notebook);
};

// skip a question callback
void skip_current_question(GtkButton * button, GtkNotebook * qa_notebook) {

	// wrapper for load new question
	load_new_question(qa_notebook);

};

// show the answer callback
void show_answer(GtkEventBox * button, GdkEventButton * event, GtkNotebook * qa_notebook) {

	// wrapper around gtk notebook set current page
	gtk_notebook_set_current_page(qa_notebook, 1);

};

// load a new question into the notebook
void load_new_question(GtkNotebook * qa_notebook) {

	// select a new question

	// change the question screen

	// change the answer screen

};
