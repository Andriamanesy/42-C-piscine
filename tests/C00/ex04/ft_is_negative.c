#include "../../test_utils.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>

// Prototype de la fonction à tester
void    ft_is_negative(int n);

// Fonction pour capturer l'output de ft_is_negative
void capture_and_test()
{
    int saved_stdout = dup(STDOUT_FILENO);
    int pipefd[2];
    char buffer[2] = { 0 };

    pipe(pipefd);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);

    // Test 1 : négatif
    ft_is_negative(-42);
    fflush(stdout);
    read(pipefd[0], buffer, 1);
    assert(buffer[0] == 'N');
    printf("✅ Test passed: ft_is_negative(-42) -> N\n");

    // Test 2 : zéro
    buffer[0] = 0;
    ft_is_negative(0);
    fflush(stdout);
    read(pipefd[0], buffer + 1, 1);
    assert(buffer[1] == 'P');
    printf("✅ Test passed: ft_is_negative(0) -> P\n");

    // Test 3 : positif
    buffer[0] = buffer[1] = 0;
    ft_is_negative(42);
    fflush(stdout);
    read(pipefd[0], buffer + 2, 1);
    assert(buffer[2] == 'P');
    printf("✅ Test passed: ft_is_negative(42) -> P\n");

    // Restauration du stdout
    close(pipefd[0]);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    printf("✅ Tous les tests sont passés pour %s.\n", extract_function_name(__FILE__));
}
