#include <stdio.h>
#include <limits.h>

/*
int	main()
{
	int	N;
	int	arr[1000001] = {0, };

	for (int i = 0; i < 1000001; ++i)
		arr[i] = INT_MAX;
	scanf("%d", &N);
	arr[1] = 0;
	for (int i = 1; i < N; ++i)
	{
		arr[i + 1] = arr[i] + 1 < arr[i + 1] ? arr[i] + 1 : arr[i + 1];
		if (i * 2 < 1000001)
			arr[i * 2] = arr[i] + 1 < arr[i * 2] ? arr[i] + 1 : arr[i * 2];
		if (i * 3 < 1000001)
			arr[i * 3] = arr[i] + 1 < arr[i * 3] ? arr[i] + 1 : arr[i * 3];
	}
	printf("%d\n", arr[N]);
}
*/

int	main()
{
	int	N;
	int	arr[1000001];

	scanf("%d", &N);
	for (int i = 2; i <= N; ++i)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0)
			arr[i] = arr[i] < arr[i / 2] + 1 ? arr[i] : arr[i / 2] + 1;
		if (i % 3 == 0)
			arr[i] = arr[i] < arr[i / 3] + 1 ? arr[i] : arr[i / 3] + 1;
	}
	printf("%d\n", arr[N]);
}
