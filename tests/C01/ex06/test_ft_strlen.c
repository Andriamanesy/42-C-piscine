#include "../../test_utils.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

// Prototype de la fonction à tester
int ft_strlen(char* str);

void test_strlen(const char* input, int expected)
{
    int result = ft_strlen((char*)input);
    if (result == expected)
    {
        printf("✅ Test passed for input \"%s\" (expected length: %d)\n", input, expected);
    }
    else
    {
        printf("❌ Test failed for input \"%s\": Expected length %d, got %d\n", input, expected, result);
        assert(0);
    }
}

int main()
{
    test_strlen("", 0);
    test_strlen("Hello", 5);
    test_strlen("42 Network", 10);
    test_strlen("C Programming Language", 23);
    test_strlen("A", 1);

    printf("✅ Tous les tests sont passés pour %s.\n", extract_function_name(__FILE__));
    return 0;
}
