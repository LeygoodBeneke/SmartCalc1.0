#include "../../s21_smart_calc.h"

void button_clicked_scope(gpointer ptr) {
    UI *main_pointer = ptr;
    int *counter = &main_pointer->open_scopes_counter;
    int *symbol = &main_pointer->elements[main_pointer->last_element_idx].symbol;
    if ((main_pointer->elements[main_pointer->last_element_idx].is_number == 0
        || main_pointer->last_element_idx == 0) && *symbol != CLOSE_SCOPE && *symbol != OPEN_SCOPE) {
        main_pointer->last_element_idx++;
        main_pointer->elements[main_pointer->last_element_idx].symbol = OPEN_SCOPE;
        main_pointer->elements[main_pointer->last_element_idx].str = calloc(1, sizeof(char));
        (*counter)++;
        strcat(main_pointer->elements[main_pointer->last_element_idx].str, "(");
    } else {
        if (*counter > 0 && *symbol != OPEN_SCOPE) {
            main_pointer->last_element_idx++;
            main_pointer->elements[main_pointer->last_element_idx].symbol = CLOSE_SCOPE;
            main_pointer->elements[main_pointer->last_element_idx].str = calloc(1, sizeof(char));
            (*counter)--;
            strcat(main_pointer->elements[main_pointer->last_element_idx].str, ")");
        }
    }
    g_print("%d\n", main_pointer->open_scopes_counter);
    print_string(main_pointer->elements, main_pointer->last_element_idx, GTK_LABEL(main_pointer->label));
}
