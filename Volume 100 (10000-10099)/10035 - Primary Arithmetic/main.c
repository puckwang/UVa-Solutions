#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i, n, next;
	long long int a, b;
	while(1){
		scanf("%lld %lld", &a, &b);
		if(a == 0 && b == 0)
			break;
		n = 0;
		next = 0;
		do{
			if((a % 10) + (b % 10 ) + next > 9){
				next = 1;
				n++;
			}else{
				next = 0;
			}
			a = a / 10;
			b = b / 10;
		}while(a != 0|| b != 0);
		if(n == 0){
			printf("No carry operation.\n");
		}else if(n == 1){
			printf("%d carry operation.\n", n);
		}else{
			printf("%d carry operations.\n", n);
		}
	}
	return 0;
}
