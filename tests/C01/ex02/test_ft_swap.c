#include "../../test_utils.h"
#include <stdio.h>
#include <assert.h>

// Prototype de la fonction à tester
void ft_swap(int* a, int* b);

void test_ft_swap()
{
    int x = 10;
    int y = 20;
    ft_swap(&x, &y);

    if (x == 20 && y == 10)
        printf("✅ Test passed: ft_swap swapped 10 and 20 to %d and %d\n", x, y);
    else
    {
        printf("❌ Test failed: expected 20 and 10 but got %d and %d\n", x, y);
        assert(0);
    }
}

int main()
{
    test_ft_swap();
    printf("✅ Tous les tests sont passés pour %s.\n", extract_function_name(__FILE__));
    return 0;
}
