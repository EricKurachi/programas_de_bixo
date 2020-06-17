#include<stdio.h>
#include<stdlib.h>

int f(x){
	float y;
	y = (x^3 + 3*x^2 - 5*x + 3);
    
	return y;
	}


int derivada(x0){
	
	float d = 1;
	float a;
	a = (f(x0 + d) - f(x0))/d; 
	return a;
}

int main(){
	
	float b;
	b = derivada(20);
	printf ("%f", b);
	return 0;
}
