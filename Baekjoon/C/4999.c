#include <stdio.h>
#include <string.h>

int	main()
{
	char	s[10001];
	int		len1;
	int		len2;

	scanf("%s", s);
	len1 = strlen(s);
	scanf("%s", s);
	len2 = strlen(s);
	if (len1 < len2)
		printf("no\n");
	else
		printf("go\n");
}
