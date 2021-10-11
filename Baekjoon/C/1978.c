#include <stdio.h>

int	is_sosu(int num)
{
	if (num < 2)
		return (0);
	for (int i = 2; i * i <= num; ++i)
		if (num % i == 0)
			return (0);
	return (1);
}

int main()
{
	int N;
	int	num;
	int	ct;

	ct = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &num);
		if (is_sosu(num))
			ct++;
	}
	printf("%d\n", ct);
}