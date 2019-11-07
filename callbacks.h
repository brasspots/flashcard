// callback declarations for flash_card.c

// guard for gtk
#ifndef GTK_FOR_FLASH_CARD
#define GTK_FOR_FLASH_CARD

// get gtk
#include <gtk/gtk.h>

// end the guard on gtk
#endif

// header guard
#ifndef FLASH_CARD_CALLBACKS
#define FLASH_CARD_CALLBACKS

// destroy window callback
void destroy(GtkWindow * window, gpointer data);

// change main screen to question vbox with a correct answer
void next_question_correct(GtkButton * button, GtkNotebook * qa_notebook);

// change the main screen to question vbox with an incorrect answer
void next_question_incorrect(GtkButton * button, GtkNotebook * qa_notebook);

// skip the current question callback
void skip_current_question(GtkButton * button, GtkNotebook * qa_notebook);

// show the answer callback
void show_answer(GtkEventBox * button, GdkEventButton * event, GtkNotebook * qu_notebook);

// load new question content
void load_new_question(GtkNotebook * qa_notebook);

// end the guard
#endif
