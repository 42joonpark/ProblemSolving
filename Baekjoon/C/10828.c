#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_stack
{
	int			top;
	int			arr[10001];
}				t_stack;

void	init(t_stack *s)
{
	s->top = 0;
}

void	func(char *res, t_stack *stack)
{
	char	*tmp;
	int		val;

	tmp = res;
	while (*tmp && *tmp != ' ')
		++tmp;
	*tmp = '\0';
	if (strcmp(res, "push") == 0)
	{
		val = 0;
		res = tmp + 1;
		while (*res && *res >= '0' && *res <= '9')
		{
			val *= 10;
			val += (*res - '0');
			++res;
		}
		++stack->top;
		stack->arr[stack->top] = val;
	}
	if (strcmp(res, "pop") == 0)
	{
		if (stack->top == 0)
			printf("-1\n");
		else
		{
			printf("%d\n", stack->arr[stack->top]);
			stack->top--;
		}
	}
	if (strcmp(res, "size") == 0)
	{
		printf("%d\n", stack->top);
	}
	if (strcmp(res, "empty") == 0)
	{
		printf("%d\n", stack->top <= 0 ? 1 : 0);
	}
	if (strcmp(res, "top") == 0)
	{
		if (stack->top == 0) {
			printf("-1\n");
			return ;
		}
		printf("%d\n", stack->arr[stack->top]);
	}
}

int	main()
{
	int		N;
	char	res[1000];
	t_stack	stack;

	scanf("%d\n", &N);
	init(&stack);
	for (int i = 0; i < N; ++i)
	{
		int k = 0;
		while (1)
		{
			res[k] = getchar();
			if (res[k] == '\n')
			{
				res[k] = '\0';
				break ;
			}
			++k;
		}
		func(res, &stack);
	}
}
