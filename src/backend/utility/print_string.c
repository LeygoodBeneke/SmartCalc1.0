#include "../../s21_smart_calc.h"

void print_string(element *elements, gint last_idx, GtkLabel *label) {
    char *input = calloc(255, sizeof(char));
    for (int i = 0; i <= last_idx; i++) {

        if (elements[i].str != NULL) {
            strcat(input, elements[i].str);
            strcat(input, " ");
            printf("%s ", elements[i].str);
        }
    }

    gtk_label_set_text(label, (const char *)input);
    free(input);

    printf("\n");
    printf("LAST IDX: %d\n", last_idx);
}


void print_string_new(element *elements, gint count, GtkLabel *label) {
    char *input = calloc(255, sizeof(char));
    for (int i = 0; i < count; i++) {

        if (elements[i].str != NULL) {
            strcat(input, elements[i].str);
            strcat(input, " ");
            printf("%s ", elements[i].str);
        }
    }

    gtk_label_set_text(label, (const char *)input);
    free(input);

    printf("\n");
    printf("COUNT: %d\n", count);
}
