#include "../../test_utils.h"
#include <stdio.h>
#include <assert.h>

// Prototype de la fonction à tester
void ft_ultimate_ft(int********* nbr);

void test_ft_ultimate_ft()
{
    int n = 0;
    int* p1 = &n;
    int** p2 = &p1;
    int*** p3 = &p2;
    int**** p4 = &p3;
    int***** p5 = &p4;
    int****** p6 = &p5;
    int******* p7 = &p6;
    int******** p8 = &p7;
    int********* p9 = &p8;

    ft_ultimate_ft(p9);

    if (n == 42)
        printf("✅ Test passed: ft_ultimate_ft sets the int to 42\n");
    else
    {
        printf("❌ Test failed: expected 42 but got %d\n", n);
        assert(0);
    }
}

int main()
{
    test_ft_ultimate_ft();
    printf("✅ Tous les tests sont passés pour %s.\n", extract_function_name(__FILE__));
    return 0;
}
