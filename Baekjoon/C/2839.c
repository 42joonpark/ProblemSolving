#include <stdio.h>
#include <limits.h>

int	main()
{
	int arr[5001];
	int	N;
	int	a, b;

	for (int i = 0; i < 5001; ++i)
		arr[i] = INT_MAX;
	arr[3] = 1;
	arr[5] = 1;
	scanf("%d", &N);
	if (N < 6 && N != 3 && N != 6)
	{
		printf("-1\n");
		return (0);
	}
	for (int i = 6; i <= N; ++i)
	{
		a = arr[i - 3];
		b = arr[i - 5];
		if (a < b)
			arr[i] = a + 1;
		else if (a > b)
			arr[i] = b + 1;
		else
		{
			if (a != INT_MAX)
				arr[i] = a + 1;
		}
	}
	if (arr[N] == INT_MAX)
		printf("-1\n");
	else
		printf("%d\n", arr[N]);
	
}
