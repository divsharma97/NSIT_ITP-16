                             //Ques 7. Using structures write a program to handle operations on complex numbers.


# include <stdio.h>
# include <math.h>

typedef struct
{
	float re;
	float im;
} complex_num;

complex_num inverse(complex_num x);
void sum(complex_num  a, complex_num b );
void sub(complex_num  a, complex_num b );
void mul(complex_num  a, complex_num b );
void div(complex_num  a, complex_num b );

int main(int argc, char const *argv[])
{
	complex_num a, b;

	char o;
    printf("Enter operand\n");
	scanf("%c", &o); 

	printf("Enter number a\n");
	scanf("%f %f", &a.re, &a.im);

	printf("Enter number b\n");
	scanf("%f %f", &b.re, &b.im);

	printf("--------------\n");

	switch(o) {
		case '+' :
		sum(a,b);
		break;

		case '-' :
		sub(a,b);
		break;

		case '*' :
		mul(a,b);
		break;

		case '/' :
		div(a, b);
		break;

		default :
		printf("Enter a valid operand\n");
		break;
	}	
	return 0;
}

void sum(complex_num  a, complex_num b ) {

	printf("%0.3f + i(%0.3f)\n", a.re + b.re, a.im + b.im);
}

void sub(complex_num  a, complex_num b ) {
	printf("%0.3f + i(%0.3f)\n", a.re - b.re, a.im - b.im);
}

void mul(complex_num  a, complex_num b ) {
	printf("%0.3f + i(%0.3f)\n", a.re* (b.re) - a.im* (b.im), a.re* (b.im) + a.im* (b.re));
}

void div(complex_num  a, complex_num b) {
	b = inverse(b);
	mul(a, b);	
}

complex_num inverse(complex_num x){

	float mod = pow(x.re, 2) + pow(x.im, 2);

	x.re = x.re/mod;
	x.im = -(x.im/mod);

	return x;
}

