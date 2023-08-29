#include "../../s21_smart_calc.h"

void add_element(element *elements, gint *size, element addition) {
    elements[*size].str = addition.str;
    elements[*size].number = addition.number;
    elements[*size].symbol = addition.symbol;
    elements[*size].is_unary = addition.is_unary;
    elements[*size].priority = addition.priority;
    elements[*size].is_dot_used = addition.is_dot_used;
    elements[*size].is_number = addition.is_number;
    (*size)++;
}

element *get_last_element(element *elements, gint size) {
    element *r = NULL;
    if (size > 0) r = &elements[size - 1];
    return r;
}

void remove_last_element(element *elements, gint *size) {
    if (*size > 0){
        if (elements[*size - 1].str)
            free(elements[*size - 1].str);
        elements[*size - 1].number = 0;
        elements[*size - 1].symbol = 0;
        elements[*size - 1].is_unary = 0;
        elements[*size - 1].priority = 0;
        elements[*size - 1].is_dot_used = 0;
        elements[*size - 1].is_number = 0;
        (*size)--;
    }
}
