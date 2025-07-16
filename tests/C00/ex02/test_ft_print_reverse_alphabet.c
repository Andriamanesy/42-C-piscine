#include "../../test_utils.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>

// Prototype de la fonction à tester
void	ft_print_reverse_alphabet(void);

// Fonction pour capturer l'output de ft_print_reverse_alphabet
void capture_and_test()
{
	int saved_stdout = dup(STDOUT_FILENO);
	int pipefd[2];
	char buffer[27] = { 0 };

	pipe(pipefd);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);

	ft_print_reverse_alphabet();
	fflush(stdout);

	read(pipefd[0], buffer, 26);
	close(pipefd[0]);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);

	const char* expected = "zyxwvutsrqponmlkjihgfedcba";
	if (strcmp(buffer, expected) == 0)
		printf("✅ Test passed: Reverse alphabet printed correctly.\n");
	else
	{
		printf("❌ Test failed: Expected '%s' but got '%s'\n", expected, buffer);
		assert(0);
	}
}
