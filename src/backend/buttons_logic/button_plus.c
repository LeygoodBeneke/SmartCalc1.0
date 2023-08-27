#include "../../s21_smart_calc.h"

void button_clicked_unary_op(gpointer ptr, char* op, int symbol);

void button_clicked_plus(gpointer ptr) {
    button_clicked_bin_op(ptr, "+", PLUS);
}

void button_clicked_minus(gpointer ptr) {
    button_clicked_bin_op(ptr, "-", MINUS);
}

void button_clicked_mult(gpointer ptr) {
    button_clicked_bin_op(ptr, "*", MULT);
}

void button_clicked_div(gpointer ptr) {
    button_clicked_bin_op(ptr, "/", DIV);
}

void button_clicked_pow(gpointer ptr) {
    button_clicked_bin_op(ptr, "^", POWER);
}

void button_clicked_mod(gpointer ptr) {
    button_clicked_bin_op(ptr, "%", MOD);
}

void button_clicked_sin(gpointer ptr) {
    button_clicked_unary_op(ptr, "sin", SIN);
}

void button_clicked_asin(gpointer ptr) {
    button_clicked_unary_op(ptr, "asin", ASIN);
}

void button_clicked_cos(gpointer ptr) {
    button_clicked_unary_op(ptr, "cos", COS);
}

void button_clicked_acos(gpointer ptr) {
    button_clicked_unary_op(ptr, "acos", ACOS);
}

void button_clicked_tan(gpointer ptr) {
    button_clicked_unary_op(ptr, "tan", TAN);
}

void button_clicked_atan(gpointer ptr) {
    button_clicked_unary_op(ptr, "atan", ATAN);
}

void button_clicked_ln(gpointer ptr) {
    button_clicked_unary_op(ptr, "ln", LN);
}

void button_clicked_log(gpointer ptr) {
    button_clicked_unary_op(ptr, "log", LOG);
}

void button_clicked_sqrt(gpointer ptr) {
    button_clicked_unary_op(ptr, "sqrt", SQRT);
}

void button_clicked_bin_op(gpointer ptr, char* op, int symbol) {
    UI *main_pointer = ptr;
    element *elements = main_pointer->elements;
    int *last_idx = &main_pointer->last_element_idx;


    if (elements[*last_idx].is_number == 1 || elements[*last_idx].symbol == CLOSE_SCOPE) {
        main_pointer->last_element_idx++;
        elements[*last_idx].is_number = 0;
    }
    
    if (elements[*last_idx].is_number == 0 && elements[*last_idx].symbol != OPEN_SCOPE) {
    if (elements[*last_idx].str == NULL) {
        elements[*last_idx].str = calloc(strlen(op), sizeof(char));
    }
    
    strcpy(elements[*last_idx].str, op);
    elements[*last_idx].symbol = symbol;
    }

    print_string(elements, *last_idx, GTK_LABEL(main_pointer->label));
}

void button_clicked_unary_op(gpointer ptr, char* op, int symbol) {
    UI *main_pointer = ptr;
    element *elements = main_pointer->elements;
    int *last_idx = &main_pointer->last_element_idx;


    if (!(*last_idx) || (elements[*last_idx].is_number == 0 && elements[*last_idx].symbol != CLOSE_SCOPE)) {
        if (*last_idx)
            main_pointer->last_element_idx++;
        if (elements[*last_idx].str == NULL) {
            elements[*last_idx].str = calloc(strlen(op), sizeof(char));
        }
        strcpy(elements[*last_idx].str, op);
        elements[*last_idx].symbol = symbol;
        button_clicked_scope(ptr);
    }

    print_string(elements, *last_idx, GTK_LABEL(main_pointer->label));
}
