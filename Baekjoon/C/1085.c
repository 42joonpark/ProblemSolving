#include <stdio.h>

int	main()
{
	int	x, y, w, h;
	int	width, height;

	scanf("%d %d %d %d", &x, &y, &w, &h);
	width = w - x < x ? w - x : x;
	height = h - y < y ? h - y: y;
	printf("%d\n", width < height ? width : height);
}
