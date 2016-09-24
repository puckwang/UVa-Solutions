#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n, r, i, j, tmp, s[30000], d, f, mid;
	scanf("%d", &n);
	while(n-- > 0){
		scanf("%d", &r);
		for(i = 0; i < r; ++i){
			scanf("%d", &s[i]);
		}	
		for(i = 0; i < r-1; ++i){  
			f = 0;
			for(j = 0; j < r-i-1; ++j){
				if(s[j] > s[j+1]){
					f = 1;
					tmp = s[j];
					s[j] = s[j+1];
					s[j+1] = tmp;
				}
			}
			if(f == 0)
				break;
		}
		mid = r / 2;
		d = 0;
		for(i = 0; i < r; ++i)
			d += abs(s[i] - s[mid]);
		printf("%d\n", d);
	}
	return 0;
}

