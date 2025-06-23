#include <stdio.h>
#include <stdbool.h> 
int main(void) {
    int tomb[10];
 
    for (int i = 0; i < 10; i += 1)
        tomb[i] = i * 10;
 
    int i = 0;
    while (true) {
        printf("%d. elem: %d\n", i, tomb[i]);
        i += 1;
    }
 
    return 0;
}
//A túlindexelet indexek kiírása memóriaszemetet ír ki.
//A while true nem áll meg i=20-nál, addíg ír ki memóriaszemetet, amíg el tud érni memória szemetet.
//Segmentation Fault-al megáll a program.