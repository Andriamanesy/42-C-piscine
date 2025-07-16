/* tests/C00_ex00/main.c */
#include "../../../C00/ex00/ft_putchar.c"

#include <unistd.h>
#include <assert.h>

// Prototype à tester
void ft_putchar(char c);

// Fonction utilitaire pour capturer la sortie standard
#include <stdio.h>
#include <fcntl.h>

void test_ft_putchar() {
    int saved_stdout = dup(STDOUT_FILENO);
    int pipefd[2];
    char buffer[2] = { 0 };

    assert(pipe(pipefd) == 0);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);

    ft_putchar('A');

    fflush(stdout);
    read(pipefd[0], buffer, 1);
    close(pipefd[0]);

    // Vérification que le caractère affiché est bien 'A'
    assert(buffer[0] == 'A');

    // Restaurer stdout
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    printf("test_ft_putchar passed ✅\n");
}

int main() {
    test_ft_putchar();
    return 0;
}
