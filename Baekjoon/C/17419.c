#include <stdio.h>

int	main()
{
	int	N, K, ct = 0;

	scanf("%d", &N);
	scanf("%d", &K);
	while (K != 0)
	{
		K ^= (K & ((-K) | 1));
		printf("K: %d\n", K);
		++ct;
	}
	printf("%d\n", ct);
}
