#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	printf("Sayiyi giriniz: ");
	int sayi,x,i,a=0;
	scanf("%d",&sayi);
	printf("Taban degerini giriniz: ");
	scanf("%d",&x);
	while(sayi>pow(x,a)) a=a+1;	
	while(sayi>=x){
		if(sayi<pow(x,(a-1))){
			a=0;
			while(sayi>pow(x,a)) a=a+1;	
		}
		if(sayi==pow(x,(a))){
			printf("%d^%d",x,(a));
			sayi-=pow(x,(a));
		}else{
			printf("%d^%d",x,(a-1));
			sayi-=pow(x,(a-1));
		}
		sayi>=x ? printf(" + "):printf("");
	}
	if(sayi>=1){
		for(i=0;i<sayi;i++)
			printf("+ %d^%d ",x,0);
	}
	return 0;
}

