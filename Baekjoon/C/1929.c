#include <stdio.h>

int	is_sosu(int number)
{
	if (number < 2) return (0);
	for (int i = 2; i * i <= number; ++i)
		if (number % i == 0)
			return (0);
	return (1);
}

int	main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	for (int i = a; i <= b; ++i)
		if (is_sosu(i))
			printf("%d\n", i);
}