#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {

  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);

  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

int	main()
{
	int	N;
	int	*a;
	int	*b;
	int	sum;

	scanf("%d", &N);
	a = (int *)malloc(sizeof(int) * N);
	b = (int *)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < N; ++i)
		scanf("%d", &b[i]);

	quickSort(a, 0, N - 1);
	quickSort(b, 0, N - 1);

	sum = 0;
	for (int i = 0; i < N; ++i)
		sum += (a[i] * b[N - i - 1]);

	printf("%d\n", sum);

	free(a);
	free(b);
}
