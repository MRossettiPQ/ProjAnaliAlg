/* Dados para o treinamento da rede */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "Normal.h"
#include "MatAlloc.h"
#include "Karatsuba.h"
#include "Strassen.h"

long double multiplicaKaratsuba(long int u, long int v, int n);
long double KaratsubaRe(long int u, long int v, int n);
int somaMatriz(int **matrizA, int **matrizB, int LinhasA, int ColunasA);
int diminuiMatriz(int **matrizA, int **matrizB, int LinhasA, int ColunasA);
int multiplicaMatriz(int **matrizA, int **matrizB, int LinhasA, int LinhasB, int ColunasA, int ColunasB);
int criaMatrizes(int Linhas, int Colunas);
int alocaMatriz(int Linhas, int Colunas);
int limpaMatriz(int **Matriz, int Linhas, int Colunas);
void imprimirMatriz(int **Matriz, int Linhas, int Colunas);
int multiplicaStrassen(int **matrizA, int **matrizB, int LinhasA, int ColunasA);
int strassenRecursivo(int **matrizA, int **matrizB, int Linhas, int Colunas);
int unirPartes(int **matriz1, int **matriz2, int **matriz3, int **matriz4, int Linhas, int Colunas);
int retornaMatAux(int **matriz, int PosLinhas, int PosColunas, int ateLinhas, int ateColunas);

int main()
{
	int reiniciar = 0, fechar = 0, opcaoMenu, opcaoSub, i, j;
	int LinhasA = 0, LinhasB = 0, ColunasA = 0, ColunasB = 0;
	int **matrizA, **matrizB, **matrizResultante;
	clock_t tempoInicial, tempoFinal;
	double tempoGasto;
	long int numGrande1, numGrande2, Aux;
	double resultadoGrande;
	int numDigitos = 0, imprimir;

	while (reiniciar != 1)
	{
		fechar = 0;
		printf("\nComo será a entrada de dados?\n");
		printf("*******************************************");
		printf("\n1 - Matriz Randomica");
		printf("\n2 - Matriz Arquivo");
		printf("\n3 - Numeros Grandes (KARATSUBA)");
		printf("\n4 - Sair do Programa");
		printf("\nOpcao? ");
		scanf("%d", &opcaoSub);
		switch (opcaoSub)
		{
		case 1: //RANDOMIZAR MATRIZ
			printf("\nRandomica");
			printf("\n Linhas - Matriz A: ");
			scanf("%d", &LinhasA);
			printf("\nColunas - Matriz A: ");
			scanf("%d", &ColunasA);
			printf("\n Linhas - Matriz B: ");
			scanf("%d", &LinhasB);
			printf("\nColunas - Matriz B: ");
			scanf("%d", &ColunasB);

			matrizA = criaMatrizes(LinhasA, ColunasA);
			printf("\nMatriz A");
			if ((LinhasA < 50) && (ColunasA < 50))
			{
				imprimirMatriz(matrizA, LinhasA, ColunasA);
			}

			matrizB = criaMatrizes(LinhasB, ColunasB);
			printf("\nMatriz B");
			if ((LinhasA < 50) && (ColunasA < 50))
			{
				imprimirMatriz(matrizB, LinhasB, ColunasB);
			}
			break;
		case 2:
			FILE *arqMatrizA;
			char url[] = "MatrizA.txt";
			// Abre um arquivo TEXTO para LEITURA
			arqMatrizA = fopen(url, "r");
			if (arqMatrizA == NULL)  // Se houve erro na abertura
			{
				printf("Problemas na abertura do arquivo\n");
			}
			else
			{
				if ((fscanf(arqMatrizA, "%d %d", &LinhasA, &ColunasA)) != EOF)
				{
					printf("\n LINHAS A: %i, COLUNAS A: %i", LinhasA, ColunasA);
				}
				matrizA = alocaMatriz(LinhasA, ColunasA);

				for (int i = 0; i < LinhasA; ++i)
				{
					for (int j = 0; j < ColunasA; ++j)
					{
						fscanf(arqMatrizA, "%d ", &matrizA[i][j]);
					}
					fscanf(arqMatrizA, "\n");
				}
				imprimirMatriz(matrizA, LinhasA, ColunasA);
			}
			fclose(arqMatrizA);
			FILE *arqMatrizB;
			url[11] = "MatrizB.txt";
			// Abre um arquivo TEXTO para LEITURA
			arqMatrizB = fopen(url, "r");
			if (arqMatrizB == NULL)  // Se houve erro na abertura
			{
				printf("Problemas na abertura do arquivo\n");
			}
			else
			{
				if ((fscanf(arqMatrizB, "%d %d", &LinhasB, &ColunasB)) != EOF)
				{
					printf("\n LINHAS B: %i, COLUNAS B: %i", LinhasB, ColunasB);
				}
				matrizB = alocaMatriz(LinhasB, ColunasB);

				for (int i = 0; i < LinhasB; ++i)
				{
					for (int j = 0; j < ColunasB; ++j)
					{
						fscanf(arqMatrizB, "%d ", &matrizB[i][j]);
					}
					fscanf(arqMatrizB, "\n");
				}
				imprimirMatriz(matrizB, LinhasB, ColunasB);
			}
			fclose(arqMatrizB);
			break;

		case 3: //INCIALIZA OS NUMEROS GRANDES
			printf("\nNUMEROS GRANDES");
			printf("\n Primeiro Numero Grande: ");
			scanf("%d", &numGrande1);
			printf("\n Segundo Numero Grande: ");
			scanf("%d", &numGrande2);
			if (numGrande1 > numGrande2)
			{
				if (numGrande1 == 0)
				{
					numDigitos = 1;
				}
				else
				{
					Aux = numGrande1;
					while (Aux != 0)
					{
						numDigitos = numDigitos + 1;
						Aux = Aux / 10;
					}
				}
			}
			else
			{
				if (numGrande2 == 0)
				{
					numDigitos = 1;
				}
				else
				{
					Aux = numGrande2;
					while (Aux != 0)
					{
						numDigitos = numDigitos + 1;
						Aux = Aux / 10;
					}
				}
			}

			break;

		default:
			exit(0);
			break;
		}
		while (fechar != 1)
		{
			printf("\n\nSoma e Multiplicação de Matrizes\n");
			printf("*******************************************");
			printf("\n1 - Soma de Matrizes (NORMAL)");
			printf("\n2 - Multiplicação de Matrizes (NORMAL)");
			printf("\n3 - Multiplicação de Matrizes (STRASSEN)");
			printf("\n4 - Multiplicação de Matrizes (KARATSUBA)");
			printf("\n5 - Sair (APAGA MATRIZES)");
			printf("\nOpcao? ");
			scanf("%d", &opcaoMenu);
			switch (opcaoMenu)
			{
			case 1://SOMA MATRIZ
				printf("\nSoma de Matrizes (NORMAL)");
				tempoInicial = clock();
				matrizResultante = somaMatriz(matrizA, matrizB, LinhasA, ColunasA);
				tempoFinal = clock();
				tempoGasto = ((double)(tempoFinal - tempoInicial)) / CLOCKS_PER_SEC;
				printf(" - Tempo em segundos: %lf", tempoGasto);
				printf("\n Imprimir Matriz? (1 - SIM/ 2-NÃO):", tempoGasto);
					scanf("%d", &imprimir);
				if (imprimir == 1)
				{
					if (matrizResultante != NULL)
					{
						imprimirMatriz(matrizResultante, LinhasA, ColunasA);
					}
				}

				break;
				break;

			case 2://MULTIPLICA MATRIZ
				printf("\nMultiplicação de Matrizes (NORMAL)");
				tempoInicial = clock();
				matrizResultante = multiplicaMatriz(matrizA, matrizB, LinhasA, LinhasB, ColunasA, ColunasB);
				tempoFinal = clock();
				tempoGasto = ((double)(tempoFinal - tempoInicial)) / CLOCKS_PER_SEC;
				printf(" - Tempo em segundos: %lf", tempoGasto);
				printf("\n Imprimir Matriz? (1 - SIM/ 2-NÃO):", tempoGasto);
					scanf("%d", &imprimir);
				if (imprimir == 1)
				{
					if (matrizResultante != NULL)
					{
						imprimirMatriz(matrizResultante, LinhasA, ColunasA);
					}
				}

				break;

			case 3://multiplicação PELO ALGORITIMO DE STRASSEN
				printf("\nMultiplicação de Matrizes (STRASSEN)");
				tempoInicial = clock();
				matrizResultante = multiplicaStrassen(matrizA, matrizB, LinhasA, ColunasA);
				tempoFinal = clock();
				tempoGasto = ((double)(tempoFinal - tempoInicial)) / CLOCKS_PER_SEC;
				printf(" - Tempo em segundos: %lf", tempoGasto);

				printf("\n Imprimir Matriz? (1 - SIM/ 2-NÃO):", tempoGasto);
				scanf("%d", &imprimir);
				if (imprimir == 1)
				{
					if (matrizResultante != NULL)
					{
						imprimirMatriz(matrizResultante, LinhasA, ColunasA);
					}
				}

				break;

			case 4://MULTIPLICA PELO ALGORITIMO DE KARATSUBA
				printf("\nMultiplicação de Matrizes (KARATSUBA)");
				tempoInicial = clock();

				resultadoGrande = multiplicaKaratsuba(numGrande1, numGrande2, numDigitos);

				tempoFinal = clock();
				tempoGasto = ((double)(tempoFinal - tempoInicial)) / CLOCKS_PER_SEC;
				printf(" - Tempo em segundos: %lf", tempoGasto);
				printf("\n %lf", resultadoGrande);
				break;

			case 5: //LIMPAR MATRIZES RETORNAR MENU INICIAL
				printf("\nRetornando Menu");
				if((matrizA != NULL)&& (matrizB != NULL))
				{
					matrizA = limpaMatriz(matrizA, LinhasA, ColunasA);
					matrizB = limpaMatriz(matrizB, LinhasB, ColunasB);
				}

				fechar = 1;
				break;
			}
			opcaoMenu = 0;
		}
	}
	system("pause");
	return 0;
}
