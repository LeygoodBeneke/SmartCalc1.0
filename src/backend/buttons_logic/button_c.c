#include "../../s21_smart_calc.h"

void clear_element(element *elements, int idx);

void button_clicked_c(gpointer ptr) {
  UI *main_pointer = ptr;
  element *elements = main_pointer->elements;
  int *last_idx = &main_pointer->last_element_idx;

  if (elements[*last_idx].is_number == 0 && elements[*last_idx].symbol == 0) {
    for (int i = 0; i <= *last_idx; i++) clear_element(elements, i);
    *last_idx = 0;
    main_pointer->open_scopes_counter = 0;
  } else {
    clear_element(elements, *last_idx);
    if (elements[*last_idx].symbol == OPEN_SCOPE)
      main_pointer->open_scopes_counter--;
    if (elements[*last_idx].symbol == CLOSE_SCOPE)
      main_pointer->open_scopes_counter++;
  }

  print_string(main_pointer->elements, main_pointer->last_element_idx,
               GTK_LABEL(main_pointer->label));
}

void clear_element(element *elements, int idx) {
  elements[idx].symbol = 0;
  elements[idx].is_dot_used = 0;
  elements[idx].number = 0;
  elements[idx].priority = 0;
  elements[idx].is_number = 0;
  elements[idx].str = NULL;
}
