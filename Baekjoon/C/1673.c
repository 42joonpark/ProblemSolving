#include <stdio.h>

int	main()
{
	int	sum, n, k;
	while (scanf("%d %d", &n, &k) == 2)
	{
		sum = n;
		while (n >= k)
		{
			sum += n / k;
			n = n / k + (n - k * (n / k));
		}
		printf("%d\n", sum);
	}
}
