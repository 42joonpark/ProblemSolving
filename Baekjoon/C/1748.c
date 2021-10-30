#include <stdio.h>
#include <math.h>

int	numlen(int num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		++len;
		num /= 10;
	}
	return (len);
}

int	main()
{
	int	num;
	int	len;
	int	sum = 0;

	scanf("%d", &num);
	len = numlen(num);
	for (int i = 1; i < len; ++i)
	{
		sum += ((9 * pow(10, i - 1)) * i);
	}
	sum += ((num - pow(10, len - 1) + 1) * len);
	printf("%d\n", sum);
}
