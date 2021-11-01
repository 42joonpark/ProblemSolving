#include <stdio.h>
#include <math.h>

int	arr[10];

int	main()
{
	char	buf[10];
	int		max = 0;

	scanf("%s", buf);
	for (int i = 0; buf[i] != '\0'; ++i)
		arr[buf[i] - '0']++;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 9 || i == 6)
			continue;
		else
			max = max > arr[i] ? max : arr[i];
	}
	max = max > ceil(((double)arr[9] + arr[6]) / 2) ? max : ceil(((double)arr[9] + arr[6]) / 2);
	printf("%d\n", max);
}
