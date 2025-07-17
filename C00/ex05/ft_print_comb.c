#include <unistd.h>
#include <stdio.h>
void ft_print_comb (void)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				if (i < j && j < k)
				{
					printf ("%d%d%d", i, j, k);
					printf (", \t");
				}
				k++;
			}
			j++;
		}
		i++;
	}
}
