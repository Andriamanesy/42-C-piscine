#include "../../test_utils.h"
#include <stdio.h>
#include <assert.h>

// Prototype de la fonction à tester
void ft_ultimate_div_mod(int* a, int* b);

void test_ft_ultimate_div_mod()
{
    int a = 20;
    int b = 3;
    ft_ultimate_div_mod(&a, &b);

    if (a == 6 && b == 2)
        printf("✅ Test passed: a=6, b=2 after division and modulo.\n");
    else
    {
        printf("❌ Test failed: Expected a=6, b=2 but got a=%d, b=%d\n", a, b);
        assert(0);
    }
}

int main()
{
    test_ft_ultimate_div_mod();
    printf("✅ Tous les tests sont passés pour %s.\n", extract_function_name(__FILE__));
    return 0;
}
