#include "../../s21_smart_calc.h"

void button_clicked_x(gpointer ptr) {
  UI *main_pointer = ptr;

  element *elements = main_pointer->elements;
  gint *size_of_elements = &main_pointer->elements_size;

  element *last = get_last_element(elements, *size_of_elements);
  if (last == NULL || last->is_number == 0) {
    element new = {.is_number = 0, .number = 0, .str = "x", .symbol = X};
    add_element(elements, &main_pointer->elements_size, new);
  }

  last = get_last_element(elements, *size_of_elements);
  //  if (last->str == NULL) {
  //    last->str = calloc(2, sizeof(char));
  //  }
  strcpy(last->str, "x");
  last->number = 0;

  print_string_new(main_pointer->elements, *size_of_elements,
                   GTK_LABEL(main_pointer->label));
}
