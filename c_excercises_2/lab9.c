//Feladat1-5
#include <stdio.h>
#include <stdlib.h>

char* masolat(char alap[]){
	int strlen=0;
	while(alap[strlen]!='\0'){
		strlen++;
	}
	strlen++;
	
	char* newstr=(char*) malloc(sizeof(char)*strlen);
	
	for(int i=0;i<strlen;i++){
		newstr[i]=alap[i];
	}
	//new_str[strlen-1]='\0';
	return newstr;
}

char* hozzafuz(char alap[], char what[]){
	int strlen=0;
	while(what[strlen]!='\0'){
		strlen++;
	}
	strlen++;
	int strlen2=0;
	while(alap[strlen2]!='\0'){
		strlen2++;
	}
	strlen2++;
	
	char* newstr=(char*) malloc(sizeof(char)*(strlen+strlen2));
	
	int i=0;
	for(i=0;i<strlen2;i++){
		newstr[i]=alap[i];
	}
	for(i=0;i<strlen;i++){
		newstr[strlen2+i-1]=what[i];
	}
	return newstr;
}
char* beszur(char alap[], int idx,char what[]){
	int strlen=0;
	while(what[strlen]!='\0'){
		strlen++;
	}
	strlen++;
	int strlen2=0;
	while(alap[strlen2]!='\0'){
		strlen2++;
	}
	strlen2++;
	
	char* newstr=(char*) malloc(sizeof(char)*(strlen+strlen2));
	
	int i=0;
	int k=0;
	for(i=0;i<strlen2;i++){
		newstr[k]=alap[i];
		k++;
		if(i==idx){
			int j=0;
			for(j=0;j<strlen;j++){
				newstr[k+j-1]=what[j];
			}
			k+=j;
		}
	}
	return newstr;
}
char* substr(char tomb[], int idx, int max){
	int strlen=0;
	while(tomb[strlen]!='\0'){
		strlen++;
	}
	strlen++;
	strlen-=(max-idx);
	char* newstr=(char*) malloc(sizeof(char)*(strlen));
	int k=0;
	for(int i=0;i<strlen;i++){
		if(i>=idx&&i<max){
			newstr[k]=tomb[i];
			k++;
		}
		
	}
	return newstr;
}
char* usubstr(char tomb[], int idx, int max){
	int strlen=0;
	while(tomb[strlen]!='\0'){
		strlen++;
	}
	strlen++;
	char* newstr=(char*) malloc(sizeof(char)*(strlen));
	
	int k=0;
	for(int i=0;i<strlen;i++){
		if(i<=idx||i>max){
			
			newstr[k]=tomb[i];
			k++;
		}
		
	}
	return newstr;
}
int main(void){
	
	char* szoveg=masolat("hello");
	
	szoveg=hozzafuz(szoveg,"fa");
	//char* s2=beszur("hello!", 5, "vilag");
	char* s2=usubstr("hello!", 0,3);
	printf("%s",s2);
	return 0;
}