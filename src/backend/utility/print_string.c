#include "../../s21_smart_calc.h"

void print_string_new(element *elements, gint count, GtkLabel *label) {
  char *input = calloc(255, sizeof(char));

  for (int i = 0; i < count; i++) {
      strcat(input, elements[i].str);
      strcat(input, " ");
      printf("%s ", elements[i].str);
  }
  unsigned long idx = (strlen(input) >= 33) ? strlen(input) - 33 : 0;

  char *output = calloc(40, sizeof(char));
  if (idx > 0)
      strcat(output, "... ");
  strcat(output, (const char *)(input + idx));
    
  if (label) {
      gtk_label_set_text(label, (const char *)output);
  }
  free(input);
  free(output);

  printf("\n");
  printf("COUNT: %d\n", count);
}
