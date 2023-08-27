#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PLUS         1
#define MINUS        2
#define MULT         3
#define DIV          4
#define MOD          5
#define INVERSE      6
#define SIN          7
#define ASIN         8
#define COS          9
#define ACOS         10
#define TAN          11
#define ATAN         12
#define LOG          13
#define LN           14
#define POWER        15
#define SQRT         16
#define OPEN_SCOPE   17
#define CLOSE_SCOPE  18

#define SYMBOLS_SIZE 33

typedef struct {
  gboolean is_number;
  gboolean is_dot_used;
  gint priority;
  gint symbol;
  long double number;
  char *str;
} element;

typedef struct {
  GtkWidget *win, *label, *grid;
  GtkWidget *buttons[32];
  element *elements;
  gint last_element_idx;
  gint open_scopes_counter;
} UI;

int main (void);
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
void print_string(element *elements, gint last_idx, GtkLabel *label);
void button_clicked_bin_op(gpointer ptr, char* op, int symbol);

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


void signal_connection(GtkWidget **buttons, gpointer ptr);
