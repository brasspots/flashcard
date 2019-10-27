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

// define global variables
GtkWidget * main_screen_vbox, * question_vbox, * answer_vbox, * add_question_vbox;

// destroy window callback
void destroy(GtkWidget window, gpointer data);

// change main screen to answer vbox
void show_answer(GtkWidget question_event_box, gpointer data);

// change main screen to question box
void next_question(GtkWidget button, gboolean * correct);

// end the guard
#endif
