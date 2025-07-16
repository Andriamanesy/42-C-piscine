#include "../../test_utils.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>

// Prototype de la fonction à tester
void ft_putnbr(int nb);

// Fonction pour capturer la sortie de ft_putnbr
void capture_and_test(int nb, const char* expected)
{
    int saved_stdout = dup(STDOUT_FILENO);
    int pipefd[2];
    char buffer[50] = { 0 };

    pipe(pipefd);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);

    ft_putnbr(nb);
    fflush(stdout);

    read(pipefd[0], buffer, sizeof(buffer) - 1);
    close(pipefd[0]);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    buffer[strcspn(buffer, "\n")] = 0; // enlever éventuel saut de ligne

    if (strcmp(buffer, expected) == 0)
        printf("✅ Test passed: ft_putnbr(%d) -> \"%s\"\n", nb, expected);
    else
    {
        printf("❌ Test failed: ft_putnbr(%d) -> attendu \"%s\" mais reçu \"%s\"\n", nb, expected, buffer);
        assert(0);
    }
}

int main()
{
    capture_and_test(42, "42");
    capture_and_test(0, "0");
    capture_and_test(-42, "-42");
    capture_and_test(2147483647, "2147483647");      // INT_MAX
    capture_and_test(-2147483648, "-2147483648");    // INT_MIN

    printf("✅ Tous les tests sont passés pour %s.\n", extract_function_name(__FILE__));
    return 0;
}
