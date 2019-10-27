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

// define array indexes for the main screens array
#define MAIN_SCREEN 0
#define QUESTION_SCREEN 1
#define ANSWER_SCREEN 2
#define ADD_SCREEN 3

// destroy window callback
void destroy(GtkWidget window, gpointer data);

// change main screen to answer vbox
void show_answer(GtkWidget question_event_box, GtkWidget ** main_screens_array);

// change main screen to question box
void next_question(GtkWidget button, GtkWidget ** main_screens_array);

// end the guard
#endif
