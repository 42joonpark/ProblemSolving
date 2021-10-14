#include <stdio.h>

int main()
{
	static const int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	static const char *week[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int	x, y;
	int	sum;

	scanf("%d %d", &x, &y);
	sum = 0;
	for (int i = 1; i < x; ++i)
		sum += month[i];
	sum += y;
	printf("%s\n", week[sum % 7]);
}
