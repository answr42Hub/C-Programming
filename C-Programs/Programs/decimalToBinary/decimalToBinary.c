#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    bool isInt = true;
    char strScan[10] = {0};
    char strBit[30] = {0};
    char revStrBit[30] = {0};
    int bitCount;

    printf("Entrez un entier positif ou un nombre reel positif: ");
    scanf("%s", strScan);

    //nombre reel ou entier
    for(int k = 0; k < 10; k++) {
        if(strScan[k] == '.') {
            isInt = false;
            k = 10;
        }
    }

    //Algorythme si entier
    if(isInt) {
        int i = 0;
        int nb = atoi(strScan);

        if(nb == 0) {
            printf("Entrez un nombre valide qui n'est pas 0. Les caracteres ne sont pas permis.");
            return 1;
        
        }

        while(nb != 0) {

            strBit[i] = nb%2;
            nb /= 2;
            ++i;

        }
    
        bitCount = i-1;
        for(int y = 0; y < i; y++) {
            revStrBit[y] = strBit[bitCount];
            --bitCount;
        }

        printf("Voici ce que ca donne en binaire : ");
        for(int j = 0; j < i; j++) {
            printf("%d", revStrBit[j]);
        }
        printf("\n");
    }

    //Algorythme si reel
    else {
        int i = 0;
        int dotPos = 0;
        char *eptr;
        double reelNb = strtod(strScan, &eptr);
        int intPort = reelNb;
        double reelPort = reelNb - intPort;

        if(reelNb == 0) {
            printf("Entrez un nombre valide svp");
        }

        //Conversion portion entiere
        while(intPort != 0) {

            if(intPort%2 == 1) {
                strBit[i] = '1';
            }
            else {
                strBit[i] = '0';
            }
            intPort /= 2;
            ++i;

        }

        dotPos = i;
        revStrBit[dotPos] = '.';
        bitCount = i-1;
        for(int y = 0; y < i; y++) {
            revStrBit[y] = strBit[bitCount];
            --bitCount;
        }

        //Conversion de la partie reel
        for(int j = dotPos+1; j < 30; j++) {
            if(reelPort*2 < 1) {
                revStrBit[j] = '0';
                reelPort *= 2;
            }
            else if(reelPort*2 >= 1){
                revStrBit[j] = '1';
                reelPort = (reelPort*2)-1;
            }
        }

        //Affichage
        printf("Voici ce que ca donne en binaire : %s\n", revStrBit);
    
        

    }
    

    
    return 0;
}