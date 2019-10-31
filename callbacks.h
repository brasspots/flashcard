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

// declare global variables
extern GtkWidget * main_screen_vbox;

// destroy window callback
void destroy(GtkWidget window, gpointer data);

// change main screen to question vbox with a correct answer
void next_question_correct(GtkWidget button, GtkWidget * question_vbox);

// change the main screen to question vbox with an incorrect answer
void next_question_incorrect(GtkWidget button, GtkWidget * question_vbox);

// change the main screen
void change_screen(GtkWidget widget, GtkWidget * new_child);

// end the guard
#endif
