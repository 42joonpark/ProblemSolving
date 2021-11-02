#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * SORT
 */
void	insert_sort(int *arr, int start, int n)
{
	int key, idx, k;
	idx = start + 1;
	while (idx < start + n)
	{
		key = arr[idx];
		k = idx - 1;
		while (k >= start && arr[k] > key)
		{
			arr[k + 1] = arr[k];
			--k;
		}
		arr[k + 1] = key;
		++idx;
	}
}

int	main()
{
	int	N, K;
	int	*arr;
	int	sum = 0;

	scanf("%d %d", &N, &K);
	arr = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	for (int i = N - 1; i >= 0 && K > 0; --i)
	{
		while (arr[i] <= K)
		{
			++sum;
			K -= arr[i];
		}
	}
	printf("%d\n", sum);
}
