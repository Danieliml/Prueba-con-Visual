#include <iostream>
#include "Matrix.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int r, c;
	
	cout<< "Introduce la dimension de la matriz cuadrada: "; cin>> r;	
	
	cout<< "\nDatos de la primera matriz: \n";
	Matrix m1(r, r);
	cin>> m1;
	
	cout<< "\nDatos de la segunda matriz: \n";
	Matrix m2(r, r);
	cin>> m2;
	
	cout<< "\nm1 = \n"<< m1<< "m2 = \n"<<m2;
	
	cout<< "\nm1 + m2 = \n" <<m1+m2;
	cout<< "\nm1 - m2 = \n" <<m1-m2;
	cout<< "\nm1 * m2 = \n" <<m1*m2;
	cout<< "\nm1 transpuesta: \n"<< m1.transpuesta();
	
	return 0;
}
