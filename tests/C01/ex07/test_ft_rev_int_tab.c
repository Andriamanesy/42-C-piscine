#include "../../test_utils.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

// Prototype de la fonction à tester
void ft_rev_int_tab(int* tab, int size);

void print_array(const int* tab, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", tab[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]");
}

void test_rev_int_tab(int* input, int size, int* expected) {
    int buffer[size];
    memcpy(buffer, input, sizeof(int) * size);

    ft_rev_int_tab(buffer, size);

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
    int test1[] = { 1, 2, 3, 4, 5 };
    int expected1[] = { 5, 4, 3, 2, 1 };
    test_rev_int_tab(test1, 5, expected1);

    int test2[] = { 10, 20, 30, 40 };
    int expected2[] = { 40, 30, 20, 10 };
    test_rev_int_tab(test2, 4, expected2);

    int test3[] = { 42 };
    int expected3[] = { 42 };
    test_rev_int_tab(test3, 1, expected3);

    int test4[] = {};
    int expected4[] = {};
    test_rev_int_tab(test4, 0, expected4);

    int test5[] = { 9, 8, 7, 6, 5, 4 };
    int expected5[] = { 4, 5, 6, 7, 8, 9 };
    test_rev_int_tab(test5, 6, expected5);

    printf("✅ Tous les tests sont passés pour %s.\n", extract_function_name(__FILE__));
    return 0;
}
