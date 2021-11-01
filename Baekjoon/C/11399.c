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
	int	N;
	int	sum = 0;
	int	*arr;

	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int) * (N + 1));
	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i + 1]);
	insert_sort(arr, 1, N);
	for (int i = 1; i <= N; ++i)
	{
		arr[i] += arr[i - 1];
		sum += arr[i];
	}
	printf("%d\n", sum);
}
