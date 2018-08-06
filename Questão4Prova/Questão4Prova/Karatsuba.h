#pragma once

long double multiplicaKaratsuba(long int u, long int v, int n);

long double KaratsubaRe(long int u, long int v, int n);

long double multiplicaKaratsuba(long int u, long int v, int n)
{
	long double resultado;
	//KARATSUBA
	resultado = KaratsubaRe(u, v, n);
	return resultado;
}

long double KaratsubaRe(long int  u, long int v, int n)
{
	long int p, q, r, s, pr, qs, y, meio, porDez;
	double resultado;
	
	if (n <= 3)
	{
		return u * v;
	}
	else
	{
		meio = n / 2;
		porDez = pow(10, meio);
		p = u / porDez;
		q = u % porDez;
		r = v / porDez;
		s = v % porDez;
		pr = KaratsubaRe(p, r, meio);
		qs = KaratsubaRe(q, s, meio);
		y = KaratsubaRe(p + q, r + s, meio + 1);
		resultado = (pr * pow(10, 2* meio)) + ((y - pr - qs) * porDez) + qs;
	}
	return resultado;
}