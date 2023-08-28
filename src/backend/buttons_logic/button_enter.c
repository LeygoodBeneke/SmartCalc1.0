#include "../../s21_smart_calc.h"

void stack_nums_push(long double *stack, gint *count, long double value);
long double stack_nums_pop(long double *stack, gint *count);
void stack_ops_push(element *stack, gint *count, element value);
element stack_ops_pop(element *stack, gint *count);
void process_binary_op(long double *numbers_stack, gint *number_stack_len,
                       int symbol);
void process_unary_op(long double *numbers_stack, gint *number_stack_len,
                      int symbol);

void button_clicked_enter(gpointer ptr) {
  UI *main_pointer = ptr;
  element *elements = main_pointer->elements;
  gint count_of_elements = main_pointer->last_element_idx;

  long double numbers_stack[255] = {};
  gint number_stack_len = 0;

  element operations_stack[255] = {};
  gint operations_stack_len = 0;

  for (gint i = 0; i <= count_of_elements; i++) {
    printf("----------------------\n");
    printf("ELEMENT\n");
    printf("SYMBOL: %d\n", elements[i].symbol);
    printf("IS UNARY: %d\n", elements[i].is_unary);
    printf("PRIORITY: %d\n", elements[i].priority);
    printf("NUMBER?: %d\n", elements[i].is_number);

    if (elements[i].is_number == 1) {
      stack_nums_push(numbers_stack, &number_stack_len, elements[i].number);
    } else {
      // если приоритет нынешнего ниже предыдущего -> операция
      // в противном случае загоняем в стэк
      gboolean is_push = !operations_stack_len;
      if (!is_push)
        is_push = elements[i].priority >
                  operations_stack[operations_stack_len - 1].priority;
      if (!is_push)
        is_push =
            operations_stack[operations_stack_len - 1].symbol == OPEN_SCOPE;
      if (is_push) {
        if (elements[i].symbol == CLOSE_SCOPE) {
          element last = stack_ops_pop(operations_stack, &operations_stack_len);
          while (last.symbol != OPEN_SCOPE) {
            if (last.is_unary == 0) {
              process_binary_op(numbers_stack, &number_stack_len, last.symbol);
            } else {
              process_unary_op(numbers_stack, &number_stack_len, last.symbol);
            }
            last = stack_ops_pop(operations_stack, &operations_stack_len);
          }

        } else {
          stack_ops_push(operations_stack, &operations_stack_len, elements[i]);
        }
      } else {
        if (elements[i].is_unary == 0) {
          process_binary_op(numbers_stack, &number_stack_len,
                            elements[i].symbol);
        } else {
          process_unary_op(numbers_stack, &number_stack_len,
                           elements[i].symbol);
        }
      }
    }
  }
  printf("%d\n", operations_stack[operations_stack_len - 1].symbol);
  gint a = operations_stack[operations_stack_len - 1].symbol == 0; //нет
  while (operations_stack_len > a) {
    element el = stack_ops_pop(operations_stack, &operations_stack_len);
    if (el.is_unary == 0) {
      process_binary_op(numbers_stack, &number_stack_len, el.symbol);
    } else {
      process_unary_op(numbers_stack, &number_stack_len, el.symbol);
    }
  }

  char buff[255];
  sprintf(buff, "%Lf", numbers_stack[0]);

  printf("ANSWER: %Lf\n", numbers_stack[0]);
    gtk_label_set_text(GTK_LABEL(main_pointer->label), (const char *)buff);
}

void stack_nums_push(long double *stack, gint *count, long double value) {
  stack[*count] = value;
  (*count)++;
}

long double stack_nums_pop(long double *stack, gint *count) {
  long double value = 0;
  if (*count > 0) {
    value = stack[*count - 1];
    stack[*count - 1] = 0;
    (*count)--;
  }
  return value;
}

void stack_ops_push(element *stack, gint *count, element value) {
  stack[*count].priority = value.priority;
  stack[*count].str = value.str;
  stack[*count].symbol = value.symbol;
  stack[*count].is_unary = value.is_unary;
  (*count)++;
}

element stack_ops_pop(element *stack, gint *count) {
  element el = {};
  if ((gint)(*count) > 0) {
    el.priority = stack[*count - 1].priority;
    el.str = calloc(10, sizeof(char));
    strcpy(el.str, stack[*count - 1].str);
    el.symbol = stack[*count - 1].symbol;
    el.is_unary = stack[*count - 1].is_unary;
    stack[*count - 1].priority = 0;
    stack[*count - 1].str = NULL;
    stack[*count - 1].symbol = 0;
    (*count)--;
  }
  return el;
}

void process_binary_op(long double *numbers_stack, gint *number_stack_len,
                       int symbol) {
  long double first = stack_nums_pop(numbers_stack, number_stack_len);
  long double second = stack_nums_pop(numbers_stack, number_stack_len);

  if (symbol == PLUS)
    stack_nums_push(numbers_stack, number_stack_len, first + second);
  if (symbol == MINUS)
    stack_nums_push(numbers_stack, number_stack_len, second - first);
  if (symbol == POWER)
    stack_nums_push(numbers_stack, number_stack_len, pow(second, first));
  if (symbol == DIV)
    stack_nums_push(numbers_stack, number_stack_len, second / first);
  if (symbol == MOD)
    stack_nums_push(numbers_stack, number_stack_len,
                    (long)second % (long)first);
  if (symbol == MULT)
    stack_nums_push(numbers_stack, number_stack_len,
                    (long)first * (long)second);
}

void process_unary_op(long double *numbers_stack, gint *number_stack_len,
                      int symbol) {
  long double value;

  if (symbol != OPEN_SCOPE && symbol != CLOSE_SCOPE)
    value = stack_nums_pop(numbers_stack, number_stack_len);

  if (symbol == SIN)
    stack_nums_push(numbers_stack, number_stack_len, sinl(value * G_PI / 180.0));
  if (symbol == ASIN)
    stack_nums_push(numbers_stack, number_stack_len, asinl(value));
  if (symbol == COS)
    stack_nums_push(numbers_stack, number_stack_len, cosl(value));
  if (symbol == ACOS)
    stack_nums_push(numbers_stack, number_stack_len, acosl(value));
  if (symbol == TAN)
    stack_nums_push(numbers_stack, number_stack_len, tanl(value));
  if (symbol == ATAN)
    stack_nums_push(numbers_stack, number_stack_len, atanl(value));
  if (symbol == LN)
    stack_nums_push(numbers_stack, number_stack_len, logl(value));
  if (symbol == LOG)
    stack_nums_push(numbers_stack, number_stack_len, log10l(value));
  if (symbol == SQRT)
    stack_nums_push(numbers_stack, number_stack_len, sqrtl(value));
}
