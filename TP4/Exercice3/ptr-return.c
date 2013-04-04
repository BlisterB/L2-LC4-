#include <stdio.h>

int *toto() {
    int x = 42;        
    return &x;
}           

void tata() {
    int a = 23;      
}          

int main(int argc, char *argv[]) {
    int *y = toto();
    tata();
    printf("%d\n", *y);
    return(0);          
}        
