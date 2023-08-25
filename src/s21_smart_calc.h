#include <gtk/gtk.h>
#include <stdlib.h>

#define SYMBOLS_SIZE 33
static const char *symbols[SYMBOLS_SIZE] = {
  "SIN", "ASIN", "C", "()", "+/-", "/",
  "COS", "ACOS", "7", "8", "9", "*",
  "TAN", "ATAN", "4", "5", "6", "-",
  "LN",  "LOG",  "1", "2", "3", "+",
  "POW", "SQRT", "X", ".", "0", "%",
  "del", "GRAPH", "=",
};

typedef struct {
  GtkWidget *label;
  gchar *string;
  gint last_idx;
} infix_string;
typedef struct {
    int a;
} simple;

typedef struct {
  GtkWidget *win, *label, *grid;
  GtkWidget *buttons[32];
  infix_string *i_s;
} UI;

static void button_clicked (GtkButton *btn);
static void add_css_provider();
static void ui_initialize(GtkWidget **buttons, GtkWidget **label);
static void grid_initialize(GtkWidget **grid, GtkWidget **buttons, GtkWidget **label);
static void window_initialize(GtkWidget **win, GApplication **app, GtkWidget **grid);
//static void app_activate (GApplication *app);
int main (void);
