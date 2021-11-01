#include <stdio.h>

int	arr[100001];
int	main()
{
	int	N, K;
	int	b, e;

	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &arr[i]);
			arr[i] += arr[i - 1];
	}
	for (int i = 0; i < K; ++i)
	{
		scanf("%d %d", &b, &e);
		printf("%d\n", arr[e] - arr[b - 1]);
	}
}
