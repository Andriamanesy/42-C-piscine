/* tests/C00_ex00/main.c */
#include "../../../C00/ex00/ft_putchar.c"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>

// Fonction pour capturer un caractère écrit par ft_putchar
char capture_putchar_output(char input) {
    int saved_stdout = dup(STDOUT_FILENO);
    int pipefd[2];
    char buffer[2] = { 0 };

    pipe(pipefd);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);

    ft_putchar(input);
    fflush(stdout);

    read(pipefd[0], buffer, 1);
    close(pipefd[0]);

    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    return buffer[0];
}

int main() {
    printf("▶️  Test 1 : ft_putchar('A')... ");
    char result = capture_putchar_output('A');
    if (result == 'A') {
        printf("✅ Passed\n");
    }
    else {
        printf("❌ Failed: Expected 'A' but got '%c'\n", result);
        return 1;
    }

    printf("▶️  Test 2 : ft_putchar('Z')... ");
    result = capture_putchar_output('Z');
    if (result == 'Z') {
        printf("✅ Passed\n");
    }
    else {
        printf("❌ Failed: Expected 'Z' but got '%c'\n", result);
        return 1;
    }

    printf("✅ Tous les tests unitaires sont passés.\n");
    return 0;
}
