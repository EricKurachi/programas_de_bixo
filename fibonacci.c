#include<stdio.h>

int main(){
	int a1, a2, n, i;
	a1 = 1;
	a2 = 1;
	n = 6;
	
	for(i=0; i<n; i++){
		a2 = a1 + a2;
		a1 = a2 - a1;
		printf("%d: %d\n", i, a1);
}
	
	return 0;
}
