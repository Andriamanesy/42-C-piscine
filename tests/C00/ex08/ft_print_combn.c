#include "../../test_utils.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>

// Prototype de la fonction à tester
void ft_print_combn(int n);

// Fonction pour capturer la sortie de ft_print_combn
void capture_and_test(int n, const char* expected)
{
    int saved_stdout = dup(STDOUT_FILENO);
    int pipefd[2];
    char buffer[1000] = { 0 };

    pipe(pipefd);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);

    ft_print_combn(n);
    fflush(stdout);

    read(pipefd[0], buffer, sizeof(buffer) - 1);
    close(pipefd[0]);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    buffer[strcspn(buffer, "\n")] = 0; // enlever saut de ligne éventuel

    if (strcmp(buffer, expected) == 0)
        printf("✅ Test passed: ft_print_combn(%d)\n", n);
    else
    {
        printf("❌ Test failed: ft_print_combn(%d) attendu : \"%s\"\n", n, expected);
        printf("               reçu : \"%s\"\n", buffer);
        assert(0);
    }
}

int main()
{
    // Cas n=2
    const char* expected_2 = "01, 02, 03, 04, 05, 06, 07, 08, 09, 12, 13, 14, 15, 16, 17, 18, 19, 23, 24, 25, 26, 27, 28, 29, 34, 35, 36, 37, 38, 39, 45, 46, 47, 48, 49, 56, 57, 58, 59, 67, 68, 69, 78, 79, 89";

    capture_and_test(2, expected_2);

    printf("✅ Tous les tests sont passés pour %s.\n", extract_function_name(__FILE__));
    return 0;
}
