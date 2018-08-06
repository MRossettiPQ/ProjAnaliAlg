#pragma once
int multiplicaStrassen(int **matrizA, int **matrizB, int LinhasA, int ColunasA);
int strassenRecursivo(int **matrizA, int **matrizB, int Linhas, int Colunas);
int unirPartes(int **matriz1, int **matriz2, int **matriz3, int **matriz4, int Linhas, int Colunas);
int retornaMatAux(int **matriz, int PosLinhas, int PosColunas, int ateLinhas, int ateColunas);

int multiplicaStrassen(int **matrizA, int **matrizB, int LinhasA, int ColunasA)
{
	int **matrizResultante, i, j;
	if (LinhasA == ColunasA)
	{
		matrizResultante = strassenRecursivo(matrizA, matrizB, LinhasA, ColunasA);
	}
	else
	{
		printf("\n multiplicação das Matrizes não será possivel, defido a incompatibilidade dos tamanhos");
		return(NULL);
	}
	return matrizResultante;
}


int strassenRecursivo(int **matrizA, int **matrizB, int Linhas, int Colunas)
{
	int tam = Linhas/2;
	int **matrizResultante, **matrizAuxiliar1, **matrizAuxiliar2, **matrizAuxiliar3, **matrizAuxiliar4;
	matrizResultante = alocaMatriz(Linhas, Colunas);

	//PARTES DA MATRIZ A
	int **A, **B ,**C, **D;	
	A = retornaMatAux(matrizA, 0, 0, tam, tam);
	B = retornaMatAux(matrizA, 0, tam, tam, Colunas);
	C = retornaMatAux(matrizA, tam, 0, Linhas, tam);
	D = retornaMatAux(matrizA, tam, tam, Colunas, Colunas);

	//PARTES DA MATRIZ B
	int **E, **F, **G, **H;
	E = retornaMatAux(matrizB, 0, 0, tam, tam);
	F = retornaMatAux(matrizB, 0, tam, tam, Colunas);
	G = retornaMatAux(matrizB, tam, 0, Linhas, tam);
	H = retornaMatAux(matrizB, tam, tam, Colunas, Colunas);

	//RESULTANTES
	int **P1, **P2, **P3, **P4, **P5, **P6, **P7;

	P1 = multiplicaMatriz(somaMatriz(A, C, tam, tam), somaMatriz(E, F, tam, tam), tam, tam, tam, tam);
	P2 = multiplicaMatriz(somaMatriz(B, D, tam, tam), somaMatriz(G, H, tam, tam), tam, tam, tam, tam);
	P3 = multiplicaMatriz(diminuiMatriz(A, D, tam, tam), somaMatriz(E, H, tam, tam), tam, tam, tam, tam);
	P4 = multiplicaMatriz(A, diminuiMatriz(F, H, tam, tam), tam, tam, tam, tam);
	P5 = multiplicaMatriz(somaMatriz(C, D, tam, tam), E, tam, tam, tam, tam);
	P6 = multiplicaMatriz(somaMatriz(A, B, tam, tam), H, tam, tam, tam, tam);
	P7 = multiplicaMatriz(D, diminuiMatriz(G, E, tam, tam), tam, tam, tam, tam);

	matrizAuxiliar1 = diminuiMatriz(diminuiMatriz(somaMatriz(P2, P3, tam, tam), P6, tam, tam), P7, tam, tam);
	matrizAuxiliar2 = somaMatriz(P4, P6, tam, tam);
	matrizAuxiliar3 = somaMatriz(P5, P7, tam, tam);
	matrizAuxiliar4 = diminuiMatriz(diminuiMatriz(diminuiMatriz(P1, P3, tam, tam), P4, tam, tam), P5, tam, tam);

	matrizResultante = unirPartes(matrizAuxiliar1, matrizAuxiliar2, matrizAuxiliar3, matrizAuxiliar4, Linhas, Colunas);
	return matrizResultante;
}

int retornaMatAux(int **matriz, int PosLinhas, int PosColunas, int ateLinhas, int ateColunas)
{
	int **matrizResultante, i, j, y = 0, x = 0;
	matrizResultante = alocaMatriz((ateLinhas - PosLinhas), (ateColunas - PosColunas));
	for (i = PosLinhas; i < ateLinhas; i++)
	{
		for (j = PosColunas; j < ateColunas; j++)
		{
				matrizResultante[y][x] = matriz[i][j];
				x++;
		}
		x = 0;
		y++;
	}

	return matrizResultante;
}

int unirPartes(int **matriz1, int **matriz2, int **matriz3, int **matriz4, int Linhas, int Colunas)
{
	int **matrizResultante, i, j, x = 0, y = 0;
	matrizResultante = alocaMatriz(Linhas, Colunas);

	for (i = 0; i < Linhas; ++i)
	{
		for (j = 0; j < Colunas; ++j)
		{
			if (x == (Colunas / 2))
			{
				x = 0;
			}
			if (y == (Linhas / 2))
			{
				y = 0;
			}
			
			if (i < (Linhas / 2))
			{
				if (j < (Colunas / 2))
				{
					matrizResultante[i][j] = matriz1[y][x];
				}
				else if ((j >= (Colunas / 2)) && (j < (Colunas)))
				{
					matrizResultante[i][j] = matriz2[y][x];
				}
			}
			else if ((i >= (Linhas / 2)) && (i < (Linhas)))
			{
				if (j < (Colunas / 2))
				{
					matrizResultante[i][j] = matriz3[y][x];
				}
				else if ((j >= (Colunas / 2)) && (j < (Colunas)))
				{
					matrizResultante[i][j] = matriz4[y][x];
				}
			}

			x++;
		}
		y++;
	}

	return matrizResultante;
}
