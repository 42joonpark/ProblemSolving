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

int	check(int	*arr)
{
	for (int i = 0; i < 4; ++i)
		if (arr[i] > arr[i + 1])
			return (0);
	return (1);
}

int	main()
{
	int	arr[5];
	int	tmp;

	scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
	while (check(arr) == 0)
	{
		for (int i = 0; i < 4; ++i)
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
			}
	}
}
