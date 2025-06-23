#include <stdio.h>
#include <stdbool.h>
char pitagorasz[]="Pitagorasz";
int pont1=0;
void print_pitagorasz(){
	char ujpitagorasz[11]="          \0";
	int odata=0;
	for(int i=pont1;i<10;i++){
		odata++;
		ujpitagorasz[i-pont1]=pitagorasz[i];
	}
	for(int i=0;i<10-odata;i++){
		ujpitagorasz[odata+i]=pitagorasz[i];
	}
	pont1++;
	printf("%s\n",ujpitagorasz);
}
int main(void) {
    for(int i=0;i<9;i++){
		print_pitagorasz();
    }
    return 0;
}