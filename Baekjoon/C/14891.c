#include <stdio.h>

void	copy_wheel(char wheel[4][9], char copy[4][9])
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 9; ++j)
			copy[i][j] = wheel[i][j];
}

void	rotate_wheel(char wheel[4][9], int n, int dir)
{
	int	tmp;

	if (dir == 1)
	{
		tmp = wheel[n][7];
		for (int i = 7; i > 0; --i)
			wheel[n][i] = wheel[n][i - 1];
		wheel[n][0] = tmp;
	}
	else
	{
		tmp = wheel[n][0];
		for (int i = 0; i < 7; ++i)
			wheel[n][i] = wheel[n][i + 1];
		wheel[n][7] = tmp;
	}
}

void	rotate_left(char wheel[4][9], char copy[4][9], int n, int dir)
{
	int	flag = 1;

	for (int i = 0; n - i >= 0; ++i)
	{
		if (n - i >= 0 && copy[n - i][2] != copy[n - i + 1][6])
			rotate_wheel(wheel, n - i, dir * flag);
		else
			break ;
		flag *= -1;
	}
}

void	rotate_right(char wheel[4][9], char copy[4][9], int n, int dir)
{
	int	flag = 1;

	for (int i = 0; n + i < 4; ++i)
	{
		if (n + i < 4 && copy[n + i - 1][2] != copy[n + i][6])
			rotate_wheel(wheel, n + i, dir * flag);
		else
			break ;
		flag *= -1;
	}
}

void	wagnar(char wheel[4][9], char copy[4][9], int n, int dir)
{
	if (dir == 1)
	{
		if (n - 1 >= 0)
			rotate_left(wheel, copy, n - 1, dir * -1);
		if (n + 1 < 4)
			rotate_right(wheel, copy, n + 1, dir * -1);
	}
	else
	{
		if (n - 1 >= 0)
			rotate_left(wheel, copy, n - 1, dir * -1);
		if (n + 1 < 4)
			rotate_right(wheel, copy, n + 1, dir * -1);
	}
	rotate_wheel(wheel, n, dir);
}

int main()
{
	char	wheel[4][9];
	char	copy[4][9];
	int		rotate;
	int		n, dir;
	int		sum = 0;

	scanf("%s %s %s %s %d", wheel[0], wheel[1], wheel[2], wheel[3], &rotate);
	copy_wheel(wheel, copy);
	for (int i = 0; i < rotate; ++i)
	{
		scanf("%d %d", &n, &dir);
		wagnar(wheel, copy, n - 1 , dir);
		copy_wheel(wheel, copy);
	}
	if (wheel[0][0] == '1')
		sum += 1;
	if (wheel[1][0] == '1')
		sum += 2;
	if (wheel[2][0] == '1')
		sum += 4;
	if (wheel[3][0] == '1')
		sum += 8;
	printf("%d\n", sum);
}
