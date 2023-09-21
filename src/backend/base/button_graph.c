#include "../../s21_smart_calc.h"
#define STEP 10.0 / cell_size

typedef struct {
  long double x, y;
} point;

point translate_num_to_coord(point p, int width, int height, double cell_size);
void set_numbers(UI *main_pointer, long double x);

void zoom_up(gpointer ptr) {
  UI *main_pointer = ptr;
  main_pointer->cell_size *= 1.1;
  gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(main_pointer->drawning_area),
                                 draw_function, ptr, NULL);
}

void zoom_down(gpointer ptr) {
  UI *main_pointer = ptr;
  main_pointer->cell_size *= 0.9;
  gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(main_pointer->drawning_area),
                                 draw_function, ptr, NULL);
}


void button_clicked_graph(gpointer ptr) {
  UI *main_pointer = ptr;
  main_pointer->cell_size = 60.0;
  GtkWidget *zooom_up_button = gtk_button_new_with_label("+");
  GtkWidget *zooom_down_button = gtk_button_new_with_label("-");

  main_pointer->drawning_window = gtk_window_new();
  gtk_window_set_title(GTK_WINDOW(main_pointer->drawning_window), "Graph");
  gtk_window_set_default_size(GTK_WINDOW(main_pointer->drawning_window), 800,
                              800);
  main_pointer->drawning_area = gtk_drawing_area_new();
  gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(main_pointer->drawning_area),
                                 draw_function, ptr, NULL);

  main_pointer->drawning_grid = gtk_grid_new();
  gtk_widget_add_css_class(main_pointer->drawning_grid, "grid");
  gtk_grid_attach(GTK_GRID(main_pointer->drawning_grid),
                  main_pointer->drawning_area, 0, 0, 16, 10);
  gtk_grid_attach(GTK_GRID(main_pointer->drawning_grid), zooom_up_button, 15, 8,
                  1, 1);
  gtk_grid_attach(GTK_GRID(main_pointer->drawning_grid), zooom_down_button, 15,
                  9, 1, 1);
  gtk_widget_add_css_class(zooom_up_button, "circular");
  gtk_widget_add_css_class(zooom_down_button, "circular");
  gtk_grid_set_row_homogeneous(GTK_GRID(main_pointer->drawning_grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(main_pointer->drawning_grid), TRUE);
  gtk_grid_set_column_spacing(GTK_GRID(main_pointer->drawning_grid), 20);
  gtk_grid_set_row_spacing(GTK_GRID(main_pointer->drawning_grid), 20);

  g_signal_connect_swapped(G_OBJECT(zooom_up_button), "clicked",
                           G_CALLBACK(zoom_up), ptr);
  g_signal_connect_swapped(G_OBJECT(zooom_down_button), "clicked",
                           G_CALLBACK(zoom_down), ptr);

  gtk_window_set_child(GTK_WINDOW(main_pointer->drawning_window),
                       main_pointer->drawning_grid);
  gtk_window_present(GTK_WINDOW(main_pointer->drawning_window));
}

void draw_function(GtkDrawingArea *area, cairo_t *cr, int width, int height,
                   gpointer ptr) {
  UI *main_pointer = ptr;
  (void)area;
  int cols_counter = 0, rows_counter = 0;
  double cell_size = main_pointer->cell_size;
  double start_x = width / 2.0, start_y = height / 2.0;
  cairo_move_to(cr, height / 2.0, 0);
  cairo_set_source_rgb(cr, 1, 1, 1);
  cairo_set_line_width(cr, 0.1);
  while (start_x + cell_size * cols_counter < width) {
    cairo_move_to(cr, start_x + cell_size * cols_counter, 0);
    cairo_line_to(cr, start_x + cell_size * cols_counter, height);
    cairo_move_to(cr, start_x - cell_size * cols_counter, 0);
    cairo_line_to(cr, start_x - cell_size * cols_counter, height);
    cols_counter++;
    cairo_stroke(cr);
  }
  while (start_y + cell_size * rows_counter < height) {
    cairo_move_to(cr, 0, start_y + cell_size * rows_counter);
    cairo_line_to(cr, width, start_y + cell_size * rows_counter);
    cairo_move_to(cr, 0, start_y - cell_size * rows_counter);
    cairo_line_to(cr, width, start_y - cell_size * rows_counter);
    rows_counter++;
    cairo_stroke(cr);
  }
  cairo_set_source_rgb(cr, 255, 255, 255);
  cairo_set_line_width(cr, 0.3);
  cairo_move_to(cr, width / 2.0, 0);
  cairo_line_to(cr, width / 2.0, height);
  cairo_set_line_width(cr, 0.3);
  cairo_move_to(cr, 0, height / 2.0);
  cairo_line_to(cr, width, height / 2.0);
  cairo_stroke(cr);

  cairo_set_source_rgb(cr, 255, 255, 255);
  cairo_set_line_width(cr, 2);

  for (double i = -cols_counter; i < cols_counter; i += STEP) {
    set_numbers(main_pointer, i);
    polish_notation(main_pointer);

    point p = {.x = i, .y = main_pointer->result};
    point coord_p = translate_num_to_coord(p, width, height, cell_size);
    set_numbers(main_pointer, i + 2 * STEP);
    button_clicked_enter(main_pointer);
    point p_next = {.x = i + 2 * STEP, .y = main_pointer->result};

    point coord_p_next =
        translate_num_to_coord(p_next, width, height, cell_size);

    if (fabsl(coord_p.y - coord_p_next.y) < 1000) {
      cairo_line_to(cr, coord_p.x, coord_p.y);
    }
    cairo_move_to(cr, coord_p_next.x, coord_p_next.y);
  }
  cairo_stroke(cr);
  gtk_label_set_text(GTK_LABEL(main_pointer->label), " ");
}

point translate_num_to_coord(point p, int width, int height, double cell_size) {
  point new_point = {.x = p.x * cell_size + width / 2.0,
                     .y = -p.y * cell_size + height / 2.0};
  return new_point;
}

void set_numbers(UI *main_pointer, long double x) {
  for (int i = 0; i < main_pointer->elements_size; i++) {
    if (main_pointer->elements[i].symbol == X) {
      main_pointer->elements[i].number = x;
    }
  }
}
