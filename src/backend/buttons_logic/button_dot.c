#include "../../s21_smart_calc.h"

void button_clicked_dot(gpointer ptr) {
    UI *main_pointer = ptr;

    if (main_pointer->elements[main_pointer->last_element_idx].is_number == 1 && 
        main_pointer->elements[main_pointer->last_element_idx].is_dot_used == 0) {
        main_pointer->elements[main_pointer->last_element_idx].is_dot_used = 1;
        strcat(main_pointer->elements[main_pointer->last_element_idx].str, ".");
    }
    print_string(main_pointer->elements, main_pointer->last_element_idx, GTK_LABEL(main_pointer->label));
}
