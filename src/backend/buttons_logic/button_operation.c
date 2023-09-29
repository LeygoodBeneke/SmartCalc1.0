#include "../../s21_smart_calc.h"

void button_clicked_unary_op(gpointer ptr, char *op, int symbol, int priority);
void button_clicked_bin_op(gpointer ptr, char *op, int symbol, int priority);

void button_clicked_plus(gpointer ptr) {
  button_clicked_bin_op(ptr, "+", PLUS, PRIORITY_PLUS);
}

void button_clicked_minus(gpointer ptr) {
  button_clicked_bin_op(ptr, "-", MINUS, PRIORITY_MINUS);
}

void button_clicked_mult(gpointer ptr) {
  button_clicked_bin_op(ptr, "*", MULT, PRIORITY_MULT);
}

void button_clicked_div(gpointer ptr) {
  button_clicked_bin_op(ptr, "/", DIV, PRIORITY_DIV);
}

void button_clicked_pow(gpointer ptr) {
  button_clicked_bin_op(ptr, "^", POWER, PRIORITY_POWER);
}

void button_clicked_mod(gpointer ptr) {
  button_clicked_bin_op(ptr, "%", MOD, PRIORITY_MOD);
}

void button_clicked_sin(gpointer ptr) {
  button_clicked_unary_op(ptr, "sin", SIN, PRIORITY_SIN);
}

void button_clicked_asin(gpointer ptr) {
  button_clicked_unary_op(ptr, "asin", ASIN, PRIORITY_ASIN);
}

void button_clicked_cos(gpointer ptr) {
  button_clicked_unary_op(ptr, "cos", COS, PRIORITY_COS);
}

void button_clicked_acos(gpointer ptr) {
  button_clicked_unary_op(ptr, "acos", ACOS, PRIORITY_ACOS);
}

void button_clicked_tan(gpointer ptr) {
  button_clicked_unary_op(ptr, "tan", TAN, PRIORITY_TAN);
}

void button_clicked_atan(gpointer ptr) {
  button_clicked_unary_op(ptr, "atan", ATAN, PRIORITY_ATAN);
}

void button_clicked_ln(gpointer ptr) {
  button_clicked_unary_op(ptr, "ln", LN, PRIORITY_LN);
}

void button_clicked_log(gpointer ptr) {
  button_clicked_unary_op(ptr, "log", LOG, PRIORITY_LOG);
}

void button_clicked_sqrt(gpointer ptr) {
  button_clicked_unary_op(ptr, "sqrt", SQRT, PRIORITY_SQRT);
}

void button_clicked_unary_minus(gpointer ptr) {
  button_clicked_unary_op(ptr, "-", UNARY_MINUS, PRIORITY_UNARY_MINUS);
}

void button_clicked_bin_op(gpointer ptr, char *op, int symbol, int priority) {
  UI *main_pointer = ptr;
  element *last =
      get_last_element(main_pointer->elements, main_pointer->elements_size);

  if (last != NULL) {
    if (last->is_number == 1 || last->symbol == CLOSE_SCOPE) {
      element new = {// .str = calloc(strlen(op), sizeof(char)),
                     .number = 0,
                     .is_number = 0,
                     .is_unary = 0};
      add_element(main_pointer->elements, &main_pointer->elements_size, new);
    }
  }
  last = get_last_element(main_pointer->elements, main_pointer->elements_size);

  if (last != NULL) {
    if (last->symbol != OPEN_SCOPE) {
      strcpy(last->str, op);
      last->symbol = symbol;
      last->priority = priority;
      last->is_unary = 0;
    }
  }
  print_string_new(main_pointer->elements, main_pointer->elements_size,
                   GTK_LABEL(main_pointer->label));
}

void button_clicked_unary_op(gpointer ptr, char *op, int symbol, int priority) {
  UI *main_pointer = ptr;
  element *last =
      get_last_element(main_pointer->elements, main_pointer->elements_size);

  int tmp = last == NULL;
  if (!tmp) tmp = last->is_number == 0 && last->symbol != CLOSE_SCOPE;
  if (tmp) {
    element new = {//.str = calloc(strlen(op), sizeof(char)),
                   .number = 0,
                   .is_number = 0,
                   .is_unary = 1};
    add_element(main_pointer->elements, &main_pointer->elements_size, new);
    last =
        get_last_element(main_pointer->elements, main_pointer->elements_size);

    strcpy(last->str, op);
    last->symbol = symbol;
    last->priority = priority;
    last->is_unary = 1;
    button_clicked_scope(main_pointer);
  }
  print_string_new(main_pointer->elements, main_pointer->elements_size,
                   GTK_LABEL(main_pointer->label));
}
