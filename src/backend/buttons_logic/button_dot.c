#include "../../s21_smart_calc.h"

void button_clicked_dot(gpointer ptr) {
  UI *main_pointer = ptr;

  element *elem =
      get_last_element(main_pointer->elements, main_pointer->elements_size);
  if (elem) {
    if (elem->is_number == 1 && elem->is_dot_used == 0) {
      elem->is_dot_used = 1;
      strcat(elem->str, ".0");
    }
  }
  print_string_new(main_pointer->elements, main_pointer->elements_size,
                   GTK_LABEL(main_pointer->label));
}
