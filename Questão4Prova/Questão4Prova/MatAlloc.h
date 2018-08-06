#pragma once
int criaMatrizes(int Linhas, int Colunas);
int alocaMatriz(int Linhas, int Colunas);
int limpaMatriz(int **Matriz, int Linhas, int Colunas);
void imprimirMatriz(int **Matriz, int Linhas, int Colunas);

int criaMatrizes(int Linhas, int Colunas)
{
	int **matriz, i, j;
	//Alocação MATRIZ
	matriz = alocaMatriz(Linhas, Colunas);
	//Randomiza MATRIZ
	for (int i = 0; i < Linhas; ++i)
	{
		for (int j = 0; j < Colunas; ++j)
		{
			matriz[i][j] = (rand() % 2);
		}
	}
	return matriz;
}

int alocaMatriz(int Linhas, int Colunas)
{
	int **matriz, i, j;
	//Alocação MATRIZ
	matriz = malloc(Linhas * sizeof(int *));
	for (int i = 0; i < Linhas; ++i)
	{
		matriz[i] = malloc(Colunas * sizeof(int));
	}
	return matriz;
}

void imprimirMatriz(int **Matriz, int Linhas, int Colunas)
{
	int i, j;
	printf("\n ");
	for (int i = 0; i < Linhas; ++i)
	{
		for (int j = 0; j < Colunas; ++j)
		{
			printf("%i\t", Matriz[i][j]);
		}
		printf("\n ");
	}
}

int limpaMatriz(int **Matriz, int Linhas, int Colunas)
{
	int  i;
	if (Matriz == NULL)
		return NULL;

	for (i = 0; i < Linhas; i++)
	{
		free(Matriz[i]);
	}
	free(Matriz);
	return NULL;
}