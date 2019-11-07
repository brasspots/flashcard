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

// main
int main(int argc, char ** argv){

	// define gtk container widgets for construction
	GtkWidget * window, * total_vbox, * header_buttons_hbox, * question_event_box, * question_tags_hbox, * answer_buttons_hbox;

	// define main gtk container widgets
	GtkWidget * question_vbox, * answer_vbox, * add_question_vbox, * qa_notebook;

	// define gtk button and label widgets
	GtkWidget * menu_button, * correct_button, * incorrect_button, * filters_button, * skip_question_button, * tags_label, * question_label, * answer_label, * answer_tab, * question_tab;

	// initialise gtk
	gtk_init(&argc, &argv);

	// parse arguments here

	// assign window a new window and configure it
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW (window), "Flash Card");
	gtk_container_set_border_width(GTK_CONTAINER (window), 10);
	gtk_widget_set_size_request(window, -1 , -1);

	// assign a new notebook to the question answer notebook
	qa_notebook = gtk_notebook_new();

	// assign new boxes to all that need boxs
	total_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	header_buttons_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	question_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	question_event_box = gtk_event_box_new();
	question_tags_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	answer_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	answer_buttons_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	add_question_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

	// assign new labels to all that need labels
	tags_label = gtk_label_new("#TAGS");
	question_label = gtk_label_new("#QUESTION");
	answer_label = gtk_label_new("#ANSWER");
	question_tab = gtk_label_new_with_mnemonic("#_QUESTION TAB");
	answer_tab = gtk_label_new_with_mnemonic("#_ANSWER TAB");

	// assign new buttons to all who need buttons
	menu_button = gtk_button_new_with_mnemonic("#_MENU");
	filters_button = gtk_button_new_with_mnemonic("#_FILTERS");
	correct_button = gtk_button_new_with_mnemonic("#_CORRECT");
	incorrect_button = gtk_button_new_with_mnemonic("#_INCORRECT");
	skip_question_button = gtk_button_new_with_mnemonic("#_SKIP");

	// contruct the header buttons to go in total box to go in window
	gtk_box_pack_start(GTK_BOX (header_buttons_hbox), menu_button, TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX (header_buttons_hbox), filters_button, TRUE, TRUE, 5);

	// add the header buttons to the total box
	gtk_box_pack_start(GTK_BOX (total_vbox), header_buttons_hbox, FALSE, FALSE, 5); // do not grow this container to fill spare space
	
	// add the main screen vbox to the total box
	gtk_box_pack_start(GTK_BOX (total_vbox), qa_notebook, TRUE, TRUE, 5);

	// add the total vbox to the window
	gtk_container_add(GTK_CONTAINER (window), total_vbox);

	// add the question label to the question event box
	gtk_container_add(GTK_CONTAINER (question_event_box), question_label);

	// construct the question tags hbox
	gtk_box_pack_start(GTK_BOX (question_tags_hbox), tags_label, TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX (question_tags_hbox), skip_question_button, FALSE, FALSE, 5); // do not grow this button to fill spare space

	// contruct the question vbox to go in main screen vbox
	gtk_box_pack_start(GTK_BOX (question_vbox), question_event_box, TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX (question_vbox), question_tags_hbox, FALSE, FALSE, 5); // do not grow this box to fill spare space

	// construct the answer buttons hbox to go in answer vbox (do not grow them out into spare space)
	gtk_box_pack_start(GTK_BOX (answer_buttons_hbox), correct_button, FALSE, FALSE, 5);
	gtk_box_pack_end(GTK_BOX (answer_buttons_hbox), incorrect_button, FALSE, FALSE, 5); 

	// construct the answer vbox to go in main screen vbox
	gtk_box_pack_start(GTK_BOX (answer_vbox), answer_label, TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX (answer_vbox), answer_buttons_hbox, FALSE, FALSE, 5); // do not grow this container to fill spare space

	// add the question and answer pages to the notebook
	gtk_notebook_append_page(GTK_NOTEBOOK (qa_notebook), question_vbox, question_tab);
	gtk_notebook_append_page(GTK_NOTEBOOK (qa_notebook), answer_vbox, answer_tab);

	// connect the main window destroy callback to destroy
	g_signal_connect(G_OBJECT (window), "destroy", G_CALLBACK (destroy), NULL);

	// connect the question event box clicked callback to show answer
	g_signal_connect(G_OBJECT (question_event_box), "button_press_event", G_CALLBACK (show_answer), qa_notebook);

	// connect the correct button clicked callback to next question
	g_signal_connect(G_OBJECT (correct_button), "clicked", G_CALLBACK (next_question_correct), qa_notebook);

	// connect the incorrect button clicked callback to next question
	g_signal_connect(G_OBJECT (incorrect_button), "clicked", G_CALLBACK (next_question_incorrect), qa_notebook);

	// connect the skip question button clicked callback to show next question
	g_signal_connect(G_OBJECT (skip_question_button), "clicked", G_CALLBACK (load_new_question), qa_notebook);

	// show all the widgets
	gtk_widget_show_all(window);

	// hand control to gtk
	gtk_main();

	return 0;

};
