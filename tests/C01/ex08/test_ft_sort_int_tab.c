#include "../../test_utils.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

// Prototype de la fonction à tester
void ft_sort_int_tab(int* tab, int size);

void print_array(const int* tab, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", tab[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]");
}

void test_sort_int_tab(int* input, int size, int* expected) {
    int buffer[size];
    memcpy(buffer, input, sizeof(int) * size);

    ft_sort_int_tab(buffer, size);

    if (memcmp(buffer, expected, sizeof(int) * size) == 0) {
        printf("✅ Test passed for input ");
        print_array(input, size);
        printf("\n");
    }
    else {
        printf("❌ Test failed for input ");
        print_array(input, size);
        printf("\nExpected: ");
        print_array(expected, size);
        printf("\nGot     : ");
        print_array(buffer, size);
        printf("\n");
        assert(0);
    }
}

int main() {
    int test1[] = { 5, 4, 3, 2, 1 };
    int expected1[] = { 1, 2, 3, 4, 5 };
    test_sort_int_tab(test1, 5, expected1);

    int test2[] = { 42 };
    int expected2[] = { 42 };
    test_sort_int_tab(test2, 1, expected2);

    int test3[] = {};
    int expected3[] = {};
    test_sort_int_tab(test3, 0, expected3);

    int test4[] = { 3, 3, 2, 1, 2 };
    int expected4[] = { 1, 2, 2, 3, 3 };
    test_sort_int_tab(test4, 5, expected4);

    int test5[] = { 10, -1, 2, 99, 0 };
    int expected5[] = { -1, 0, 2, 10, 99 };
    test_sort_int_tab(test5, 5, expected5);

    printf("✅ Tous les tests sont passés pour %s.\n", extract_function_name(__FILE__));
    return 0;
}
