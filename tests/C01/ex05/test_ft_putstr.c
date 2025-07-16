#include "../../test_utils.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>

// Prototype de la fonction à tester
void ft_putstr(char* str);

// Fonction utilitaire pour capturer l'output
void capture_and_test_putstr(const char* input, const char* expected)
{
    int saved_stdout = dup(STDOUT_FILENO);
    int pipefd[2];
    char buffer[256] = { 0 };

    pipe(pipefd);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);

    ft_putstr((char*)input);
    fflush(stdout);

    read(pipefd[0], buffer, sizeof(buffer) - 1);
    close(pipefd[0]);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    if (strcmp(buffer, expected) == 0)
        printf("✅ Test passed for input \"%s\"\n", input);
    else
    {
        printf("❌ Test failed for input \"%s\": Expected \"%s\", Got \"%s\"\n", input, expected, buffer);
        assert(0);
    }
}

int main()
{
    capture_and_test_putstr("Hello, World!", "Hello, World!");
    capture_and_test_putstr("", "");
    capture_and_test_putstr("42 Network", "42 Network");

    printf("✅ Tous les tests sont passés pour %s.\n", extract_function_name(__FILE__));
    return 0;
}
