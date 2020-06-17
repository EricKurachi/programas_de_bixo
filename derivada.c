#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x){
	double y;
	y = (pow(x, 3) + 3*pow(x, 2) - 5*x + 3);   
	return y;
	}


double derivada(double x0, double d){
	
	double a;
	a = (f(x0 + d) - f(x0))/d; 
	return a;
}

int main(){
	
	double b, d, r;
	d = 1;

	do{
		b = derivada(20, d) - derivada(20, d/2);
		d = d/2;
		
	}while(b>0.001);	
	
	printf ("A derivada eh: %f \n", derivada(20, d));

	
	return 0;
}
