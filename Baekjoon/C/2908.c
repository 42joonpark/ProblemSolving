#include <stdio.h>

int	reverse_number(int num)
{
	int	ret;
	
	ret = 0;
	while (num > 0)
	{
		ret *= 10;
		ret += num % 10;
		num /= 10;
	}
	return (ret);
}

int	main()
{
	int A, B;
	int	rA, rB;

	scanf("%d %d", &A, &B);
	rA = reverse_number(A);
	rB = reverse_number(B);
	if (rA > rB)
		printf("%d\n", rA);
	else
		printf("%d\n", rB);
}