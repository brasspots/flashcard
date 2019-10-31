// guard for gtk
#ifndef GTK_FOR_FLASH_CARD
#define GTK_FOR_FLASH_CARD

// include gtk for the graphical interface
#include <gtk/gtk.h>

// end the gtk guard
#endif

// include sdtio to talk to the terminal for error/debugging info
#include <stdio.h>

// include stdlib for malloc and free
#include <stdlib.h>

// include gtk callbacks for flash card
#include "callbacks.h"

// define global variables
GtkWidget * main_screen_vbox;

// main
int main(int argc, char ** argv){

	// define gtk container widgets for construction
	GtkWidget * window, * total_vbox, * header_buttons_hbox, * question_event_box, * answer_buttons_hbox;

	// define main gtk container widgets
	GtkWidget * question_vbox, * answer_vbox, * add_question_vbox;

	// define gtk button and label widgets
	GtkWidget * menu_button, * correct_button, * incorrect_button, * filters_button, * tags_label, * question_label, * answer_label;

	// initialise gtk
	gtk_init(&argc, &argv);

	// parse arguments here

	// assign window a new window and configure it
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW (window), "Flash Card");
	gtk_container_set_border_width(GTK_CONTAINER (window), 10);
	gtk_widget_set_size_request(window, -1 , -1);

	// assign a new vbox to the main screen vbox
	main_screen_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

	// assign new boxes to all that need boxs
	total_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	header_buttons_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	question_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	question_event_box = gtk_event_box_new();
	answer_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	answer_buttons_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	add_question_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

	// assign new labels to all that need labels
	tags_label = gtk_label_new("#TAGS");
	question_label = gtk_label_new("#QUESTION");
	answer_label = gtk_label_new("#ANSWER");

	// assign new buttons to all who need buttons
	menu_button = gtk_button_new_with_label("#MENU");
	filters_button = gtk_button_new_with_label("#FILTERS");
	correct_button = gtk_button_new_with_label("#CORRECT");
	incorrect_button = gtk_button_new_with_label("#INCORRECT");

	// contruct the header buttons to go in total box to go in window
	gtk_box_pack_start(GTK_BOX (header_buttons_hbox), menu_button, TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX (header_buttons_hbox), filters_button, TRUE, TRUE, 5);

	// add the header buttons to the total box
	gtk_box_pack_start(GTK_BOX (total_vbox), header_buttons_hbox, FALSE, FALSE, 5); // do not grow this container to fill spare space
	
	// add the main screen vbox to the total box
	gtk_box_pack_start(GTK_BOX (total_vbox), main_screen_vbox, TRUE, TRUE, 5);

	// add the total vbox to the window
	gtk_container_add(GTK_CONTAINER (window), total_vbox);

	// add the question label to the question event box
	gtk_container_add(GTK_CONTAINER (question_event_box), question_label);

	// contruct the question vbox to go in main screen vbox
	gtk_box_pack_start(GTK_BOX (question_vbox), question_event_box, TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX (question_vbox), tags_label, FALSE, FALSE, 5); // dom not grow this label to fill spare space

	// construct the answer buttons hbox to go in answer vbox (do not grow them out into spare space)
	gtk_box_pack_end(GTK_BOX (answer_buttons_hbox), correct_button, TRUE, FALSE, 5);
	gtk_box_pack_end(GTK_BOX (answer_buttons_hbox), incorrect_button, TRUE, FALSE, 5); 

	// construct the answer vbox to go in main screen vbox
	gtk_box_pack_start(GTK_BOX (answer_vbox), answer_label, TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX (answer_vbox), answer_buttons_hbox, FALSE, FALSE, 5); // do not grow this container to fill spare space

	// add the question vbox to the main screen vbox
	gtk_box_pack_start(GTK_BOX (main_screen_vbox), answer_vbox, TRUE, TRUE, 5);

	// assign some names
	gtk_widget_set_name(answer_vbox, "GtkBox_answer");
	gtk_widget_set_name(question_vbox, "GtkBox_question");

	// connect the main window destroy callback to destroy
	g_signal_connect(G_OBJECT (window), "destroy", G_CALLBACK (destroy), NULL);

	// following callbacks are connected swapped for reasons unknown
	// TODO: why?

	// connect the question event box clicked callback to show answer
	g_signal_connect_swapped(G_OBJECT (question_event_box), "button_press_event", G_CALLBACK (change_screen), answer_vbox);

	// connect the correct button clicked callback to next question
	g_signal_connect_swapped(G_OBJECT (correct_button), "clicked", G_CALLBACK (next_question_correct), question_vbox);

	// connect the incorrect button clicked callback to next question
	g_signal_connect_swapped(G_OBJECT (incorrect_button), "clicked", G_CALLBACK (next_question_incorrect), question_vbox);

	// show all the widgets
	gtk_widget_show_all(window);

	// hand control to gtk
	gtk_main();

	return 0;

};
