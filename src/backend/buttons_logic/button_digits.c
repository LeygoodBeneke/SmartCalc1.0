#include "../../s21_smart_calc.h"


void button_clicked_digit(gpointer ptr, gint digit);

void button_clicked_0(gpointer ptr) {
    button_clicked_digit(ptr, 0);
}

void button_clicked_1(gpointer ptr) {
    button_clicked_digit(ptr, 1);
}

void button_clicked_2(gpointer ptr) {
    button_clicked_digit(ptr, 2);
}

void button_clicked_3(gpointer ptr) {
    button_clicked_digit(ptr, 3);
}

void button_clicked_4(gpointer ptr) {
    button_clicked_digit(ptr, 4);
}

void button_clicked_5(gpointer ptr) {
    button_clicked_digit(ptr, 5);
}

void button_clicked_6(gpointer ptr) {
    button_clicked_digit(ptr, 6);
}

void button_clicked_7(gpointer ptr) {
    button_clicked_digit(ptr, 7);
}

void button_clicked_8(gpointer ptr) {
    button_clicked_digit(ptr, 8);
}

void button_clicked_9(gpointer ptr) {
    button_clicked_digit(ptr, 9);
}

void button_clicked_digit(gpointer ptr, gint digit) {
    UI *main_pointer = ptr;
    gchar char_digit = '0' + digit;
    char digit_string[1];
    long double double_digit = digit;
    digit_string[0] = char_digit;
    
    if (main_pointer->elements[main_pointer->last_element_idx].is_number == 0) {
        if (main_pointer->last_element_idx) main_pointer->last_element_idx++;
        main_pointer->elements[main_pointer->last_element_idx].is_number = 1;
    }

    if (main_pointer->elements[main_pointer->last_element_idx].str == NULL) {
        main_pointer->elements[main_pointer->last_element_idx].str = calloc(30, sizeof(char));
    }

    long double prev = main_pointer->elements[main_pointer->last_element_idx].number;
    if (!main_pointer->elements[main_pointer->last_element_idx].is_dot_used) {
        main_pointer->elements[main_pointer->last_element_idx].number *= 10.0;
    } else {
        int power = main_pointer->elements[main_pointer->last_element_idx].is_dot_used * -1;
        double_digit = pow(10, power) * double_digit;
        main_pointer->elements[main_pointer->last_element_idx].is_dot_used++;
    }
    main_pointer->elements[main_pointer->last_element_idx].number += double_digit;
    prev -= main_pointer->elements[main_pointer->last_element_idx].number;
    
    if (prev != 0.0f) {
      strcat(main_pointer->elements[main_pointer->last_element_idx].str, digit_string);
      print_string(main_pointer->elements, main_pointer->last_element_idx, GTK_LABEL(main_pointer->label));
    }
    printf("NUMBER: %Lf\n", main_pointer->elements[main_pointer->last_element_idx].number);
}
