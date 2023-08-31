#include "../s21_smart_calc.h"

const char *symbols[SYMBOLS_SIZE] = {
  "SIN", "ASIN", "C", "()", "+/-", "/",
  "COS", "ACOS", "7", "8", "9", "*",
  "TAN", "ATAN", "4", "5", "6", "-",
  "LN",  "LOG",  "1", "2", "3", "+",
  "POW", "SQRT", "X", ".", "0", "%",
  "del", "GRAPH", "=",
};

static void add_css_provider() {
  const char cssPath[] = "frontend/style.css";
  GtkCssProvider *cssProvider = gtk_css_provider_new();
  gtk_css_provider_load_from_path(cssProvider, cssPath);
  gtk_style_context_add_provider_for_display(gdk_display_get_default(),
                                             GTK_STYLE_PROVIDER(cssProvider),
                                             GTK_STYLE_PROVIDER_PRIORITY_USER);
}

static void ui_initialize(GtkWidget **buttons, GtkWidget **label) {
  for (int i = 0; i < SYMBOLS_SIZE; i++) {
    buttons[i] = gtk_button_new_with_label(symbols[i]);
    gtk_widget_add_css_class(buttons[i], "circular");
  }
  *label = gtk_label_new("0");
  gtk_widget_add_css_class(*label, "label");
  gtk_label_set_xalign(GTK_LABEL(*label), 1.0);
  gtk_label_set_yalign(GTK_LABEL(*label), 1.0);
}

static void grid_initialize(GtkWidget *grid, GtkWidget **buttons,
                            GtkWidget *label) {
  gtk_widget_add_css_class(grid, "grid");
  gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 7, 5);
  for (int i = 0; i < SYMBOLS_SIZE - 3; i++) {
    gtk_grid_attach(GTK_GRID(grid), buttons[i], i % 6, i / 6 + 5, 1, 1);
  }
  gtk_grid_attach(GTK_GRID(grid), buttons[SYMBOLS_SIZE - 3], 6, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), buttons[SYMBOLS_SIZE - 2], 6, 6, 1, 2);
  gtk_grid_attach(GTK_GRID(grid), buttons[SYMBOLS_SIZE - 1], 6, 8, 1, 2);
  gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
  gtk_grid_set_column_spacing(GTK_GRID(grid), 20);
  gtk_grid_set_row_spacing(GTK_GRID(grid), 20);
}

static void window_initialize(GtkWidget *win, GApplication *app,
                              GtkWidget *grid) {
  win = gtk_application_window_new(GTK_APPLICATION(app));
  gtk_window_set_title(GTK_WINDOW(win), "SmartCalc");
  gtk_window_set_default_size(GTK_WINDOW(win), 1000, 600);
  gtk_window_set_child(GTK_WINDOW(win), grid);
  gtk_window_present(GTK_WINDOW(win));
}

static void app_activate(GApplication *app, gpointer ptr) {
  UI *main_pointer = ptr;
  main_pointer->grid = gtk_grid_new();

  add_css_provider();
  ui_initialize(main_pointer->buttons, &main_pointer->label);
  signal_connection(main_pointer->buttons, ptr);

  grid_initialize(main_pointer->grid, main_pointer->buttons, main_pointer->label);
  window_initialize(main_pointer->win, app, main_pointer->grid);
}

int main(void) {
  GtkApplication *app;
  int stat;
  UI main = {};
  main.elements = calloc(255, sizeof(element));

  app =
      gtk_application_new("com.github.SmartCalc", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(app_activate), &main);
  stat = g_application_run(G_APPLICATION(app), 0, NULL);
  g_object_unref(app);
  free(main.elements);
  return stat;
}
