#include "../../test_utils.h"
#include <stdio.h>
#include <assert.h>

// Prototype de la fonction à tester
void ft_div_mod(int a, int b, int* div, int* mod);

void test_ft_div_mod()
{
    int a = 20, b = 3;
    int div = 0, mod = 0;
    ft_div_mod(a, b, &div, &mod);

    if (div == 6 && mod == 2)
        printf("✅ Test passed: %d / %d = %d, reste = %d\n", a, b, div, mod);
    else
    {
        printf("❌ Test failed: Expected div=6 and mod=2 but got div=%d mod=%d\n", div, mod);
        assert(0);
    }
}

int main()
{
    test_ft_div_mod();
    printf("✅ Tous les tests sont passés pour %s.\n", extract_function_name(__FILE__));
    return 0;
}
