#include <gtk/gtk.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define PLUS 1
#define MINUS 2
#define MULT 3
#define DIV 4
#define MOD 5
#define POWER 6
#define INVERSE 7
#define SIN 8
#define ASIN 9
#define COS 10
#define ACOS 11
#define TAN 12
#define ATAN 13
#define LOG 14
#define LN 15
#define SQRT 16
#define UNARY_MINUS 17
#define OPEN_SCOPE 18
#define CLOSE_SCOPE 19
#define X 20

#define PRIORITY_PLUS 1
#define PRIORITY_MINUS 1
#define PRIORITY_MULT 2
#define PRIORITY_DIV 2
#define PRIORITY_MOD 2
#define PRIORITY_INVERSE 2
#define PRIORITY_SIN 3
#define PRIORITY_ASIN 3
#define PRIORITY_COS 3
#define PRIORITY_ACOS 3
#define PRIORITY_TAN 3
#define PRIORITY_ATAN 3
#define PRIORITY_LOG 3
#define PRIORITY_LN 3
#define PRIORITY_POWER 3
#define PRIORITY_SQRT 3
#define PRIORITY_UNARY_MINUS 3
#define PRIORITY_OPEN_SCOPE 4
#define PRIORITY_CLOSE_SCOPE 5

#define SYMBOLS_SIZE 33

typedef struct {
  gboolean is_number;
  gint is_dot_used;
  gint priority;
  gboolean is_unary;
  gint symbol;
  long double number;
  char str[255];
} element;

typedef struct {
  GtkWidget *win, *label, *grid;
  GtkWidget *drawning_window, *drawning_area, *drawning_grid;
  GtkWidget *buttons[SYMBOLS_SIZE];
  element *elements;
  gint last_element_idx;
  gint elements_size;
  gint open_scopes_counter;
  double cell_size;
  double result;
} UI;

int main(void);
void button_clicked_0(gpointer ptr);
void button_clicked_1(gpointer ptr);
void button_clicked_2(gpointer ptr);
void button_clicked_3(gpointer ptr);
void button_clicked_4(gpointer ptr);
void button_clicked_5(gpointer ptr);
void button_clicked_6(gpointer ptr);
void button_clicked_7(gpointer ptr);
void button_clicked_8(gpointer ptr);
void button_clicked_9(gpointer ptr);
void button_clicked_plus(gpointer ptr);
void button_clicked_dot(gpointer ptr);
void button_clicked_c(gpointer ptr);
void button_clicked_minus(gpointer ptr);
void button_clicked_mult(gpointer ptr);
void button_clicked_div(gpointer ptr);
void button_clicked_mod(gpointer ptr);
void button_clicked_scope(gpointer ptr);
void button_clicked_sin(gpointer ptr);
void button_clicked_asin(gpointer ptr);
void button_clicked_cos(gpointer ptr);
void button_clicked_acos(gpointer ptr);
void button_clicked_tan(gpointer ptr);
void button_clicked_atan(gpointer ptr);
void button_clicked_ln(gpointer ptr);
void button_clicked_log(gpointer ptr);
void button_clicked_sqrt(gpointer ptr);
void button_clicked_pow(gpointer ptr);
void button_clicked_enter(gpointer ptr);
void button_clicked_graph(gpointer ptr);
void button_clicked_x(gpointer ptr);
void button_clicked_unary_minus(gpointer ptr);
void button_clicked_ac(gpointer ptr);

void print_string_new(element *elements, gint count, GtkLabel *label);
void signal_connection(GtkWidget **buttons, gpointer ptr);
void add_element(element *elements, gint *size, element addition);

element *get_last_element(element *elements, gint size);
void remove_last_element(element *elements, gint *size);
void morph_numeric_string(char *s);
void draw_function(GtkDrawingArea *area, cairo_t *cr, int width, int height,
                   gpointer data);
void polish_notation(gpointer ptr);
