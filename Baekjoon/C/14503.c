#include <stdio.h>
#include <stdlib.h>

int	dy[4] = {-1, 0, 1, 0};
int	dx[4] = {0, 1, 0, -1};

int	main()
{
	int	N, M, ct;
	int	r, c, d;
	int	**map, **x;
	int	check;

	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);
	map = (int **)malloc(sizeof(int *) * N);
	x = (int **)malloc(sizeof(int *) * N);
	for (int i = 0; i < N; ++i)
	{
		map[i] = (int *)malloc(sizeof(int) * M);
		x[i] = (int *)malloc(sizeof(int) * M);
	}
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m)
		{
			scanf("%d", &map[n][m]);
			x[n][m] = 0;
		}
	ct = 0;
	while (1)
	{
		check = 0;
		if (map[r][c] == 0 && x[r][c] == 0)
		{
			++ct;
			x[r][c] = 1;
		}
		for (int i = 0; i < 4; ++i)
		{
			d = (d + 3) % 4;
			if (map[r + dy[d]][c + dx[d]] == 0 && x[r + dy[d]][c + dx[d]] == 0)
			{
				r += dy[d];
				c += dx[d];
				check = 1;
				break ;
			}
		}
		if (check)
			continue;
		else
		{
			d = (d + 2) % 4;
			if (map[r + dy[d]][c + dx[d]] == 0)
			{
				r += dy[d];
				c += dx[d];
				d = (d + 2) % 4;
			}
			else
				break ;
		}
	}
	printf("%d\n", ct);
}
