#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int hesapla(char *metin,int *dizi_b, int i,int *B){
	int a=(int)metin[i];
	int k=0,b=8,dizi[8];
	dizi_b[i]=0;
	while(b>0){
		if(a>0)
			dizi[k]=a%2;
		else
			dizi[k]=0;
		a=a/2;
		b--;
		k++;
	}
	a=7;
	for(k=0;k<8;k++){
		dizi_b[i]+=dizi[a]*B[k];
		a--;
	}
	return dizi_b[i];
}

int main(int argc, char *argv[]) {
	int a,w,q,r;
	int B[8];
	FILE *fp=fopen("dizi.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%d",&a);
		w+=a;
	}
	fclose(fp);
	srand(time(NULL));
	q=(w+1)+rand()%w;
	
	int i,kontrol=1;
	while(kontrol==1){
		r=1+rand()%(q-1);
		for(i=2;i<=r;i++){
			if(r%i!=0 && q%i!=0) kontrol=0;
		}
	}
	i=0;
	fp=fopen("dizi.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%d",&a);
		B[i]=(a*r)%q;
		i++;
	}
	fclose(fp);
	char metin[100]; int uzunluk,g_dizi[8];
	printf("Metni giriniz: ");
	gets(metin);
	uzunluk=strlen(metin);
	int dizi[uzunluk],sifreli[8];
	printf("Sifrelenmis hali: ");
	for(i=0;i<uzunluk;i++){
		sifreli[i]=hesapla(metin,dizi,i,B);
		printf("%d ",sifreli[i]);
	}a=0;printf("\n");
	while((r*a)%q!=1)a++;i=0;
	int k,x,b,sayi,g=0,l=0,metn;
	while(i<uzunluk){
		dizi[i]=(sifreli[i]*a)%q;
		sayi=dizi[i];
		b=8;l=0;g=0;	
		while(sayi!=0){
			fp=fopen("dizi.txt","r");
			for(k=0;k<b;k++){
				fscanf(fp,"%d",&x);
			}fclose(fp);
			if(sayi>=x){
				sayi-=x;
				g_dizi[g]=l;
				g++;
			}b--;l++;
		}metn=0;
		for(b=0;b<g;b++)
			metn+=pow(2,g_dizi[b]);
		if(kontrol==0){
			printf("Desifrelenmis hali: ");
			kontrol=1;
		}
		printf("%c",(char)metn);
		i++;
	}
	return 0;
}
