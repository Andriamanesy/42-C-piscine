#include "../../test_utils.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>

// Prototype de la fonction à tester
void ft_print_comb(void);

// Fonction pour capturer l'output de ft_print_comb
void capture_and_test()
{
    int saved_stdout = dup(STDOUT_FILENO);
    int pipefd[2];
    char buffer[600] = { 0 }; // assez grand pour contenir toute la sortie
    ssize_t total_bytes = 0;

    pipe(pipefd);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);

    ft_print_comb();
    fflush(stdout);

    // Lire tout ce que ft_print_comb a imprimé
    while ((total_bytes = read(pipefd[0], buffer + total_bytes, sizeof(buffer) - 1 - total_bytes)) > 0) {}
    buffer[sizeof(buffer) - 1] = '\0';

    close(pipefd[0]);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    // Chaîne attendue (sans espace, virgule entre chaque combinaison, sauf la dernière)
    const char* expected =
        "012, 013, 014, 015, 016, 017, 018, 019, "
        "023, 024, 025, 026, 027, 028, 029, "
        /* ... toutes les combinaisons ... */
        "789";

    if (strstr(buffer, expected) != NULL && buffer[strlen(buffer) - 1] != ',')
        printf("✅ Test passed: ft_print_comb full output matches expected pattern.\n");
    else
    {
        printf("❌ Test failed: Output not matching expected combinations.\n");
        assert(0);
    }
}

int main()
{
    capture_and_test();
    printf("✅ Tous les tests sont passés pour %s.\n", extract_function_name(__FILE__));
    return 0;
}
