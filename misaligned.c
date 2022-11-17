#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

typedef struct 
{
    int pairID;
    char* majorColor;
    char* minorColor;

}pairColor;

pairColor pairref[25];

void PairColorReferenceValues(){
    int i = 0, j = 0, cont = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            pairref[cont].pairID = cont+1;
            pairref[cont].majorColor = majorColor[i];
            pairref[cont].minorColor = minorColor[i];
            cont++;
        }
    }
}


int printColorMap() {

    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
            assert((i*j+5) == pairref[i].pairID);
            assert(majorColor[i] == pairref[i].majorColor);
            assert(minorColor[i] == pairref[i].minorColor);
        }
    }
    return i * j;
}

int main() {
    PairColorReferenceValues();
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
