#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

struct pairColor
{
    int pairID;
    char* majorColor;
    char* minorColor;

};

void PairColorReferenceValues()
{
    
    for(int i = 0; i < 5; i++) 
    {
        for(int j = 0; j < 5; j++)
        {
            pairref[i* 5 +j].pairID = i* 5 +j+1;
            pairref[i* 5 +j].majorColor = (char *)majorColor[i];
            pairref[i* 5 +j].minorColor = (char *)minorColor[j];
            //printf("%d | %s | %s\n",pairref[i* 5 +j].pairID, pairref[i* 5 +j].majorColor, pairref[i* 5 +j].minorColor);
        }
    }
}


void printColorMap()
{
    for(int i = 0; i < 25; i++)
    {
        
        printf("%d | %s | %s\n", pairref[i].pairID , pairref[i].majorColor, pairref[i].minorColor);
        
    }

}

int main() 
{
    
    PairColorReferenceValues();
    printColorMap();
    assert(pairref[5].pairID == 5);
    assert(pairref[4].minorColor == minorColor[3]);
    assert(pairref[4].majorColor == majorColor[4]);
 
    printf("All is well (maybe!)\n");
}
