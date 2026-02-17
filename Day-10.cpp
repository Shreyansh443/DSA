#include <stdio.h>
#include <string.h>
int main(){
    char str[30];
    printf("Enter a string\n");
    fgets(str, sizeof(str), stdin);
    int l;
    l = strlen(str);
    char *a = str;
    char *b = &str[l-2];
    char temp;
    while (b > a){
        temp = *a;
        *a = *b;
        *b = temp;
        b =b-1;
        a =a+1;
    }
    printf("Reversed string = %s", str);
    return 0;
}