#include "../../s21_smart_calc.h"

void button_clicked_c(gpointer ptr) {
  UI *main_pointer = ptr;

  element *last =
      get_last_element(main_pointer->elements, main_pointer->elements_size);

  if (last != NULL) {
    if (last->symbol == OPEN_SCOPE) main_pointer->open_scopes_counter--;
    if (last->symbol == CLOSE_SCOPE) main_pointer->open_scopes_counter++;

    remove_last_element(main_pointer->elements, &main_pointer->elements_size);
    last =
        get_last_element(main_pointer->elements, main_pointer->elements_size);

    if (last) {
      if (last->is_unary) {
        remove_last_element(main_pointer->elements,
                            &main_pointer->elements_size);
      }
    }
  }
  print_string_new(main_pointer->elements, main_pointer->elements_size,
                   GTK_LABEL(main_pointer->label));
}
