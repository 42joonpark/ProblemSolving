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
