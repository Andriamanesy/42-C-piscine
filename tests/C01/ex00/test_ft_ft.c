#include "../../test_utils.h"
#include <stdio.h>
#include <assert.h>

// Prototype de la fonction à tester
void ft_ft(int* nbr);

void test_ft_ft()
{
    int n = 0;
    ft_ft(&n);
    if (n == 42)
        printf("✅ Test passed: ft_ft sets *nbr to 42\n");
    else
    {
        printf("❌ Test failed: ft_ft expected 42 but got %d\n", n);
        assert(0);
    }
}

int main()
{
    test_ft_ft();
    printf("✅ Tous les tests sont passés pour %s.\n", extract_function_name(__FILE__));
    return 0;
}
