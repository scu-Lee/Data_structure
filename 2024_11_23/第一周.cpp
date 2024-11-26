#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//¸´ÊýÔËËã
//z = (8 + 6i)(4 + 3i)/((8 + 6i)+(4 + 3i))

struct complex
{
	float realpart;
	float imagpart;
};

void assign(complex* p, float x, float y)
{
	p->realpart = x;
	p->imagpart = y;
}

void add(complex* p, complex A, complex B)
{
	p->realpart = A.realpart + B.realpart;
	p->imagpart = A.imagpart + B.imagpart;
}

void subtraction(complex* p, complex A, complex B)
{
	p->realpart = A.realpart - B.realpart;
	p->imagpart = A.imagpart - B.imagpart;
}

void multiply(complex* p, complex A, complex B)
{
	p->realpart = A.realpart * B.realpart - A.imagpart * B.imagpart;
	p->imagpart = A.realpart * B.imagpart + A.imagpart * B.realpart;
}

void divide(complex* p,complex z1, complex z2) 
{
	float denominator = z2.realpart * z2.realpart + z2.imagpart * z2.imagpart;
	p->realpart = (z1.realpart * z2.realpart + z1.imagpart * z2.imagpart) / denominator;
	p->imagpart = (z1.imagpart * z2.realpart - z1.realpart * z2.imagpart) / denominator;
}

void getreal(complex* p)
{
	printf("%f", p->realpart);
}

void getimag(complex* p)
{
	printf("%f", p->imagpart);
}

int main()
{
	complex z1, z2, z3, z4, z;
	float RealPart, ImagPart;
	assign(&z1, 8.0, 6.0);
	assign(&z2, 4.0, 3.0);
	add(&z3, z1, z2);
	multiply(&z4, z1, z2);
	if ((z3.realpart+z3.imagpart)!= 0)
	{
		divide(&z, z4, z3);
		//printf("z = ");
		//getreal(&z);
		//printf(" + ");
		//getimag(&z);
		//printf(" i ");
		printf("z = %f + %fi\n", z.realpart, z.imagpart);
	}
	return 0;
}