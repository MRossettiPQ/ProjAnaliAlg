#pragma once
int somaMatriz(int **matrizA, int **matrizB, int LinhasA, int ColunasA);
int diminuiMatriz(int **matrizA, int **matrizB, int LinhasA, int ColunasA);
int multiplicaMatriz(int **matrizA, int **matrizB, int LinhasA, int LinhasB, int ColunasA, int ColunasB);

int somaMatriz(int **matrizA, int **matrizB, int LinhasA, int ColunasA)
{
	int **matrizResultante, i, j;

	if (LinhasA == ColunasA)
	{
		matrizResultante = alocaMatriz(LinhasA, ColunasA);
		//SOMA
		for (i = 0; i < LinhasA; ++i)
		{
			for (j = 0; j < ColunasA; ++j)
			{
				matrizResultante[i][j] = matrizA[i][j] + matrizB[i][j];
			}
		}
	}
	else
	{
		printf("\n Soma das Matrizes não será possivel, defido a incompatibilidade dos tamanhos");
		return(NULL);
	}
	return matrizResultante;
}

int diminuiMatriz(int **matrizA, int **matrizB, int LinhasA, int ColunasA)
{
	int **matrizResultante, i, j;

	if (LinhasA == ColunasA)
	{
		matrizResultante = alocaMatriz(LinhasA, ColunasA);
		//SOMA
		for(int i = 0; i < LinhasA; ++i)
		{
			for(int j = 0; j < ColunasA; ++j)
			{
				matrizResultante[i][j] = matrizA[i][j] - matrizB[i][j];
			}
		}
	}
	else
	{
		printf("\n Soma das Matrizes não será possivel, defido a incompatibilidade dos tamanhos");
		return(NULL);
	}
	return matrizResultante;
}

int multiplicaMatriz(int **matrizA, int **matrizB, int LinhasA, int LinhasB, int ColunasA, int ColunasB)
{
	int **matrizResultante, Aux = 0, i, j, k;
	if ((LinhasB == ColunasA))
	{
		matrizResultante = alocaMatriz(LinhasA, ColunasB);
		//MULTIPLICAÇÃO
		for (i = 0; i < LinhasA; i++)
		{
			for (j = 0; j < ColunasB; j++)
			{
				matrizResultante[i][j] = 0;
				for (k = 0; k < LinhasB; k++)
				{
					Aux += matrizA[i][k] * matrizB[k][j];
				}
				matrizResultante[i][j] = Aux;
				Aux = 0;
			}
		}
		//
	}
	else
	{
		printf("\n Multiplicação das Matrizes não será possivel, defido a incompatibilidade dos tamanhos");
		return(NULL);
	}
	return matrizResultante;
}
