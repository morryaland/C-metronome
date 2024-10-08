#ifndef __METRONOME_H__
#define __METRONOME_H__

#include <gtk/gtk.h>

typedef struct {
  GtkApplication *app;
  GtkWidget *win;
} METRONOME_CTX;

extern METRONOME_CTX __metronome_ctx;

void metronome_activate(GtkApplication *app, gpointer data);

#endif
