#include <stdio.h>

int	check(int n)
{
	int	g;
	int	b;

	b = n % 10;
	n /= 10;
	g = (n % 10) - b;
	b = n % 10;
	n /= 10;
	while (n > 0)
	{
		if ((n % 10) - b != g)
			return (0);
		b = n % 10;
		n /= 10;
	}
	return (1);
}

int	main()
{
	int	N;
	int	ct;

	ct = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		if (i < 100)
			++ct;
		else
			if(check(i))
				++ct;
	}
	printf("%d\n", ct);
}
