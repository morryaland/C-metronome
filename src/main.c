/************************************************\
*                                                *
* AUTHOR:  Muly                                  *
*                                                *
* CREATED: 2024.02.24                            *
*                                                *
* FOR:     Mishander                             *
*                                                *
* ABOUT:   cross-platform metronome written in C *
*                                                *
\************************************************/

#include <gtk/gtk.h>
#include "metronome.h"

int main (int argc, char **argv)
{
  __metronome_ctx.app = gtk_application_new("gtk.metronome", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(__metronome_ctx.app, "activate", G_CALLBACK(metronome_activate), NULL);
  g_application_run(G_APPLICATION(__metronome_ctx.app), argc, argv);
}
