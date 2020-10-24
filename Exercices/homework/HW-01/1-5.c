#include <stdio.h>
#include <math.h>

long long int dos_a_la[63];
int techo_log2[80002];

void precalculo()
{
	dos_a_la[0] = 1ll;
	for (int i = 1; i <= 63; i++)
	{
		dos_a_la[i] = dos_a_la[i - 1] * 2ll;
	}
	for (double i = 1.0; i <= 80000.0; i += 1.0)
	{
		techo_log2[(int)i] = ceil(log2(i));
	}
}

int main()
{
	precalculo();
	int cantidad_de_valores_de_n;
	scanf("%d", &cantidad_de_valores_de_n);

	printf("\t Valor de n \t Conteo teorico \t Conteo empirico \n\n");

	while (cantidad_de_valores_de_n--)
	{
		int n, i, j;
		scanf("%d", &n);

		//---- Por algoritmo:
		long long int contador = 0;

		for (i = 1; i < 4 * n; i *= 2)
			for (j = i; j < 5 * n; j += 3)
			{
				contador++;
				//				printf("%d.- Algoritmo\n", contador);
			}

		//---- Por funci�n:
		long long int resultado;
		if (n <= 0)
			resultado = 0;
		else
		{
			resultado = 0;
			for (int t = 1; t <= techo_log2[4 * n]; t++)
			{
				resultado += floor(((5.0 * n) - dos_a_la[t - 1] - 1.0) / (3.0)) + 1;
			}
		}

		// Impresi�n de la tabla comparativa.
		if (cantidad_de_valores_de_n & 1)
			printf("\t % 10d \t % 14lld \t % 15lld \n", n, resultado, contador);
		else
			printf("\t % 10d \t % 14lld \t % 15lld \n", n, resultado, contador);
	}
	return 0;
}
