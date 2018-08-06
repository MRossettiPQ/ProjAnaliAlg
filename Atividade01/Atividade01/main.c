#include <stdio.h>

int mdc(int x, int y);


int main()
{	
	int x = 1035, y = 759, r;

	r = mdc(x, y);
	printf("\n");
	printf("\n x: %i", x);


	printf("\n");
	system("pause");
	return 0;
}

float mdc(int x, int y)
{
	printf("\n x: %i", x);
	printf("\n y: %i", y);
	printf("\n");
	if (y == 0)
	{
		return x;
	}
	else
	{
		return mdc(y, (x % y));
	}

}