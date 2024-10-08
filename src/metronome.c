#include "metronome.h"

METRONOME_CTX __metronome_ctx;

void metronome_activate(GtkApplication *app, gpointer data)
{
  __metronome_ctx.win = gtk_application_window_new(app);
  gtk_window_present(GTK_WINDOW(__metronome_ctx.win));
}
