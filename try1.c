#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b)
{
	int q, r;
	while (b > 0)
	{
		q = a / b;
		r = a - q * b;
		a = b;
		b = r;
	}
	return a;
}

// C program to find generators of cyclic group
int main()
{
	char ch, op;
	int a, k;
	int mode = 0;
	int val;
	int ord[50], g[50], H[50];
	bool cyclic = false;
	int elements[100];
	int order;
		scanf("%d",&a);
    scanf("%c",&ch);
		if (ch == '*')
			mode = 1;
		else
			ungetc(ch, stdin);
		fscanf(stdin, ",%c>\n", &op);

		if (mode)
		{
			printf("G=<Z%d*,%c>\n", a, op);
			k = 0;

			for (int i = 0; i < a; i++)
				if (gcd(a, i) == 1) //co-prime
					elements[k++] = i;

			elements[k] = '\0';
			mode = 0;
		}
		else
		{
			printf("G=<Z%d,%c>\n", a, op);
			for (int i = 0; i < a; i++)
				elements[i] = i;
			k = a;
		}

		printf("G = {");
		for (int i = 0; i < k; i++)
		{
			printf("%d", elements[i]);
			(i < k-1) ? printf(",") : printf("}");
		}

		order = k;
		printf("\nThe order of the group is %d.\n\n", order);

		for (int i = 0; i < k; i++)
		{
			int temp = 1;
			while (1)
			{
				if (op == '+')
				{
					val = elements[i] * temp;
					if (val % a == 0)
					{
						ord[i] = temp;
						printf("order(%d) = %d\n", elements[i], temp);
						break;
					}
				}
				else if (op == '*')
				{
					val = int(pow(elements[i], temp));
					if (val % a == 1)
					{
						ord[i] = temp;
						printf("order(%d) = %d\n", elements[i], temp);
						break;
					}
				}

				temp++;
			}
		}

		int x = 0, count = 0;

		for (int i = 0; i < k; i++)
		{
			if (ord[i] == order)
			{
				g[x++] = elements[i];
				cyclic = true;
				count++;
			}
		}

		if (cyclic)
		{
			printf("The group is a cyclic group with %d generators", count);
			for (int i = 0; i < count; i++)
				printf("g%d = %d ", i + 1, g[i]);
		}
		else
			printf("The group is not a cyclic group.\n");

		printf("\n\n----------------------------------------------\n\n");

	return 0;
}
