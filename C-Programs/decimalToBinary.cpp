#include <stdio.h>
#include <string.h>

int main() {

    int nb = 520;
    char str[80];
    int i = 0;

    while (nb != 1) {
        
        str[i] = nb%2;
        nb /= 2;
        ++i;
    }
    

    printf("En binaire : %s", str);

}