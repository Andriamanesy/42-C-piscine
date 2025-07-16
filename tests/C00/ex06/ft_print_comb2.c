#include "../../test_utils.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>

// Prototype de la fonction à tester
void ft_print_comb2(void);

// Fonction pour capturer la sortie de ft_print_comb2
void capture_and_test()
{
    int saved_stdout = dup(STDOUT_FILENO);
    int pipefd[2];
    char buffer[3000] = { 0 }; // assez grand pour la sortie complète
    ssize_t total_bytes = 0;

    pipe(pipefd);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);

    ft_print_comb2();
    fflush(stdout);

    // Lire toute la sortie
    while ((total_bytes = read(pipefd[0], buffer + total_bytes, sizeof(buffer) - 1 - total_bytes)) > 0) {}
    buffer[sizeof(buffer) - 1] = '\0';

    close(pipefd[0]);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    // Vérifier que la sortie contient un extrait significatif attendu (début + fin)
    const char* expected_start = "00 01, 00 02, 00 03, 00 04, 00 05";
    const char* expected_end = "97 99, 98 99";

    if (strstr(buffer, expected_start) != NULL && strstr(buffer, expected_end) != NULL)
        printf("✅ Test passed: ft_print_comb2 output contains expected combinations.\n");
    else
    {
        printf("❌ Test failed: Output missing expected combinations.\n");
        assert(0);
    }
}

int main()
{
    capture_and_test();
    printf("✅ Tous les tests sont passés pour %s.\n", extract_function_name(__FILE__));
    return 0;
}
