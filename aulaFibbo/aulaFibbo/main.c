#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int Fibbo1(int n);

int Fibbo2(int n);

int Fibbo3(int n);

int Fibbo4(int n);


int main()
{
	int opcaoSub, valorN, resultado = 0, reiniciar = 0, tempoGasto;
	double tempoInicial, tempoFinal;

	while (reiniciar != 1)
	{
		resultado = 0;
		printf("Valor de N: ");
		scanf("%i", &valorN);

		printf("*******************************************");
		printf("\n1 - Fibbonaci 1");
		printf("\n2 - Fibbonaci 2");
		printf("\n3 - Fibbonaci 3");
		printf("\n3 - Func");
		printf("\nOpcao? ");
			scanf("%i", &opcaoSub);
		switch (opcaoSub)
		{
			case 1:
				tempoInicial = clock();
				// PROGRAMA CALCULANDO TEMPO

				resultado = Fibbo1(valorN);

				// CALCULA TEMPO
				tempoFinal = clock();
				tempoGasto = ((double)(tempoFinal - tempoInicial)) / CLOCKS_PER_SEC;
				printf("Soma Fibbo 1: %i - Tempo em segundos: %lf\n", resultado, tempoGasto);
				break;

			case 2:
				tempoInicial = clock();
				// PROGRAMA CALCULANDO TEMPO

				resultado = Fibbo2(valorN);

				// CALCULA TEMPO
				tempoFinal = clock();
				tempoGasto = ((double)(tempoFinal - tempoInicial)) / CLOCKS_PER_SEC;
				printf("Soma Fibbo 2: %i - Tempo em segundos: %lf\n", resultado, tempoGasto);
				break;

			case 3:
				tempoInicial = clock();
				// PROGRAMA CALCULANDO TEMPO

				resultado = Fibbo3(valorN);

				// CALCULA TEMPO
				tempoFinal = clock();
				tempoGasto = ((double)(tempoFinal - tempoInicial)) / CLOCKS_PER_SEC;
				printf("Soma Fibbo 2: %i - Tempo em segundos: %lf\n", resultado, tempoGasto);
				break;

			case 4:
				tempoInicial = clock();
				// PROGRAMA CALCULANDO TEMPO

				resultado = Fibbo4(valorN);

				// CALCULA TEMPO
				tempoFinal = clock();
				tempoGasto = ((double)(tempoFinal - tempoInicial)) / CLOCKS_PER_SEC;
				printf("Soma Func 2: %i - Tempo em segundos: %lf\n", resultado, tempoGasto);
				break;
		}
	}



	return 0;
}

int Fibbo1(int n)
{
	if (n <= 1)
	{
		return n;
	}
	return (Fibbo1(n - 1) + Fibbo1(n - 2));
}

int Fibbo2(int n)
{
	int *vetor, i, resultado;
	if (n <= 1)
	{
		return n;
	}
	vetor = malloc(sizeof(int));
	vetor[0] = 0;
	vetor[1] = 1;
	for (i = 0; i < n; i++)
	{
		vetor[i] = vetor[i - 1] + vetor[i - 2];
	}
	return vetor;
}

int Fibbo3(int n)
{
	int ultimo, penultimo, soma;
	if (n <= 1)
	{
		return n;
	}
	else
	{
		ultimo = 1;
		penultimo = 0;
		for (int i; i < n; i++)
		{
			soma = ultimo + penultimo;
			penultimo = ultimo;
			ultimo = soma;
		}
	}
	return soma;
}

int Fibbo4(int n)
{
	int resultado, fii;

	resultado = (pow(fii, n) / sqrt(5)) - (pow((1 - fii), n) / sqrt(5));

	return resultado;
}

