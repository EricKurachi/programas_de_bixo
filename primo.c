#include<stdio.h>
#include<math.h>

/* Descobrir se n eh primo ou nao*/

int main(){
	
	int n, i, r, s;		
	n = 1373237;		
	r = sqrt(n);			//r eh a raiz quadrada de n
	
	for(i = 0; i < r; i++){												//vamos analisar os numeros menores do que a raiz de "n" um por um, pois os numeros maiores que a raiz de "n" precisam ser multiplicados por um numero menor que a raiz de "n" para resultar em "n"
																		
		if ((n % (r - i)) == 0 && (r - i) != 1 || n == 1) {				//se "n" for divisivel por um numero diferente de 1 ou for igual a 1, ele nao eh primo
			s = 0;														//"s" indica se o numero eh primo ou nao								
			break;														//break finaliza o laco
		}
		
		else{															//nas outras situacoes "n" eh primo
			s = 1;
		}		
	}
	
	if (s == 0){														//para "s" igual a 0 "n" eh nao primo
		printf("%d eh nao primo", n);
	}
	
	if (s == 1){														//para "s" igual a 1 "n" eh primo
		printf("%d eh primo", n);
	}	
	
	return 0;
}
