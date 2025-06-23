#include <stdio.h>
#include <stdlib.h>

typedef enum LyAllapot {
    alap, l_volt, ll_volt
} LyAllapot;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Használat: hejesiras <bemenet> <kimenet>\n");
        return 1;
    }
	FILE *kimenet = fopen(argv[2], "w");
    if (kimenet==NULL) {
        printf("Hiba a kimeneti file megnyitásakor.");
        
        return 1;
    }
    FILE *bemenet = fopen(argv[1], "r");
    if (bemenet==NULL) {
        printf("Hiba a bemeneti file megnyitásakor.");
		fclose(kimenet);
        return 1;
    }

    LyAllapot all = alap;
    int c;

    while ((c = fgetc(bemenet)) != EOF) {
        switch (all) {
            case alap:
				switch(c){
					case 'l':
						all = l_volt;
						break;
					case 'L':
						all = L_volt;
						break;
					default:
						fputc(c, kimenet);
						break;
				}
                break;
			case L_volt:
				if (c == 'y') {
                    fputc('J', kimenet);
                    all = alap;
                } else {
                    fputc('L', kimenet);
                    fputc(c, kimenet);
                    all = alap;
                }
				break;

            case l_volt:
                if (c == 'l') {
                    all = ll_volt;
                } else if (c == 'y') {
                    fputc('j', kimenet);
                    all = alap;
                } else {
                    fputc('l', kimenet);
                    fputc(c, kimenet);
                    all = alap;
                }
                break;

            case ll_volt:
                if (c == 'y') {
                    fputc('j', kimenet);
                    fputc('j', kimenet);
                    all = alap;
                } else if (c != 'l') {
                    fputc('l', kimenet);
                    fputc('l', kimenet);
                    fputc(c, kimenet);
                    all = alap;
                }
                break;
        }
    }
	
	switch(all){
		case l_volt:
			fputc('l', kimenet);
			break;
		case ll_volt:
			fputc('l', kimenet);
			fputc('l', kimenet);
			break;
		case L_volt:
			fputc('L', kimenet);
			break;
	}

    fclose(kimenet);
	fclose(bemenet);

    return 0;
}
