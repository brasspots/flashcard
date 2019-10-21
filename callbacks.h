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
void destroy(GtkWidget window, gpointer data);

// end the guard
#endif
