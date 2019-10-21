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
