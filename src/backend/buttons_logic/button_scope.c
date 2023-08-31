#include "../../s21_smart_calc.h"

void button_clicked_scope(gpointer ptr) {
  UI *main_pointer = ptr;

  element *last =
      get_last_element(main_pointer->elements, main_pointer->elements_size);

  if (last == NULL || (last->is_number == 0 && last->symbol != CLOSE_SCOPE)) {
    element addition = {.is_unary = 1,
                        .priority = PRIORITY_OPEN_SCOPE,
                        .str = calloc(1, sizeof(char)),
                        .symbol = OPEN_SCOPE};
    strcpy(addition.str, "(");
    add_element(main_pointer->elements, &main_pointer->elements_size, addition);
    main_pointer->open_scopes_counter++;
  } else {
    if (main_pointer->open_scopes_counter && last->symbol != OPEN_SCOPE) {
      element addition = {.is_unary = 1,
                          .priority = PRIORITY_CLOSE_SCOPE,
                          .str = calloc(1, sizeof(char)),
                          .symbol = CLOSE_SCOPE};
      strcpy(addition.str, ")");
      add_element(main_pointer->elements, &main_pointer->elements_size,
                  addition);
      main_pointer->open_scopes_counter--;
    }
  }
  print_string_new(main_pointer->elements, main_pointer->elements_size,
                   GTK_LABEL(main_pointer->label));
}
