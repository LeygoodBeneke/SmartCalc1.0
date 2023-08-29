#include "../../s21_smart_calc.h"

void button_clicked_scope(gpointer ptr) {
  UI *main_pointer = ptr;

  element *last = get_last_element(main_pointer->elements, main_pointer->elements_size);

  if (last == NULL || (last->is_unary && last->symbol != OPEN_SCOPE && last->symbol != CLOSE_SCOPE)) {
      element addition = { .is_unary = 1,
                           .priority = PRIORITY_OPEN_SCOPE,
                           .str = calloc(1, sizeof(char)),
                           .symbol = OPEN_SCOPE };
      strcpy(addition.str, "(");
      add_element(main_pointer->elements, &main_pointer->elements_size, addition);
      main_pointer->open_scopes_counter++;
  } else {
      if (main_pointer->open_scopes_counter && last->symbol != OPEN_SCOPE) {
          element addition = { .is_unary = 1,
                               .priority = PRIORITY_CLOSE_SCOPE,
                               .str = calloc(1, sizeof(char)),
                               .symbol = CLOSE_SCOPE };
          strcpy(addition.str, ")");
          add_element(main_pointer->elements, &main_pointer->elements_size, addition);
          main_pointer->open_scopes_counter--;
      }
  }

//  int *counter = &main_pointer->open_scopes_counter;
//  int *symbol = &main_pointer->elements[main_pointer->last_element_idx].symbol;
//  if ((main_pointer->elements[main_pointer->last_element_idx].number == 0 ||
//       main_pointer->last_element_idx == 0) &&
//      *symbol != CLOSE_SCOPE && *symbol != OPEN_SCOPE) {
//    //if (main_pointer->last_element_idx) main_pointer->last_element_idx++;
//    main_pointer->elements[main_pointer->last_element_idx].symbol = OPEN_SCOPE;
//    main_pointer->elements[main_pointer->last_element_idx].priority =
//        PRIORITY_OPEN_SCOPE;
//    main_pointer->elements[main_pointer->last_element_idx].is_unary = 1;
//    main_pointer->elements[main_pointer->last_element_idx].str =
//        calloc(1, sizeof(char));
//    (*counter)++;
//    strcat(main_pointer->elements[main_pointer->last_element_idx].str, "(");
//    main_pointer->elements_size++;
//  } else {
//    if (*counter > 0 && *symbol != OPEN_SCOPE) {
//      //main_pointer->last_element_idx++;
//      main_pointer->elements[main_pointer->last_element_idx].symbol =
//          CLOSE_SCOPE;
//      main_pointer->elements[main_pointer->last_element_idx].priority =
//          PRIORITY_CLOSE_SCOPE;
//      main_pointer->elements[main_pointer->last_element_idx].str =
//          calloc(1, sizeof(char));
//      main_pointer->elements[main_pointer->last_element_idx].is_unary = 1;
//      (*counter)--;
//      strcat(main_pointer->elements[main_pointer->last_element_idx].str, ")");
//      main_pointer->elements_size++;
//    }
//  }
//  g_print("%d\n", main_pointer->open_scopes_counter);
  print_string_new(main_pointer->elements, main_pointer->elements_size,
               GTK_LABEL(main_pointer->label));
}
