#include "../../s21_smart_calc.h"

void button_clicked_digit(gpointer ptr, gint digit);

void button_clicked_0(gpointer ptr) { button_clicked_digit(ptr, 0); }

void button_clicked_1(gpointer ptr) { button_clicked_digit(ptr, 1); }

void button_clicked_2(gpointer ptr) { button_clicked_digit(ptr, 2); }

void button_clicked_3(gpointer ptr) { button_clicked_digit(ptr, 3); }

void button_clicked_4(gpointer ptr) { button_clicked_digit(ptr, 4); }

void button_clicked_5(gpointer ptr) { button_clicked_digit(ptr, 5); }

void button_clicked_6(gpointer ptr) { button_clicked_digit(ptr, 6); }

void button_clicked_7(gpointer ptr) { button_clicked_digit(ptr, 7); }

void button_clicked_8(gpointer ptr) { button_clicked_digit(ptr, 8); }

void button_clicked_9(gpointer ptr) { button_clicked_digit(ptr, 9); }

void button_clicked_digit(gpointer ptr, gint digit) {
  UI *main_pointer = ptr;
  long double double_digit = digit;

  element *elements = main_pointer->elements;
  gint *size_of_elements = &main_pointer->elements_size;

  element *last = get_last_element(elements, *size_of_elements);
  if (last == NULL || (last->is_number == 0 && last->symbol)) {
    element new = {.is_number = 1, .number = 0};
    add_element(elements, &main_pointer->elements_size, new);
  }

  last = get_last_element(elements, *size_of_elements);
  //  if (last->str == NULL) {
  //    last->str = calloc(30, sizeof(char));
  //  }

  if (!last->is_dot_used)
    last->number *= 10.0;
  else {
    int power = last->is_dot_used * -1;
    double_digit = pow(10, power) * double_digit;
    last->is_dot_used++;
  }
  last->number += double_digit;

  char buff[30];
  sprintf(buff, "%.10Lf", last->number);
  morph_numeric_string(buff);
  strcpy(last->str, buff);

  print_string_new(main_pointer->elements, *size_of_elements,
                   GTK_LABEL(main_pointer->label));
}

void morph_numeric_string(char *s) {
  while (s[strlen(s) - 1] == '0') {
    s[strlen(s) - 1] = '\0';
  }
  
  if (s[strlen(s) - 1] == '.') {
    s[strlen(s) - 1] = '\0';
  }
}
