#include <stdio.h>

int	main()
{
	int	w, h, p, q, t, wr, hr;
	int	pr, qr;
	int	ct = 0, sum = 0;

	scanf("%d %d\n%d %d\n%d", &w, &h, &p, &q, &t);
	wr = 1;
	hr = 1;
	pr = p;
	qr = q;
	while (1)
	{
		pr += wr;
		qr += hr;
		++sum;
		if (pr == 0 || pr == w)
		{
			wr *= -1;
			ct++;
		}
		if (qr == 0 || qr == h)
		{
			hr *= -1;
			ct++;
		}
		if (ct == 2 && qr == q && pr == p)
			break ;
	}
	printf("%d\n", sum);
}
