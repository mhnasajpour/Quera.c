#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

void rev(char a[10000], int i) {
    char t;
    if (i % 2 == 0) {
        for (int k = 0; k < i / 2; k++) {
            t = a[k];
            a[k] = a[i - k];
            a[i - k] = t;
        }
    }
    else {
        for (int k = 0; k <= i / 2; k++) {
            t = a[k];
            a[k] = a[i - k];
            a[i - k] = t;
        }
    }
    for (int m = 0; m <= i; m++)
        printf("%c", a[m]);
}

int main() {
    char a[10000];
    int i = 0;
    gets(a);
    while (a[i] != '\0') {
        for (; (a[i] >= 97 && a[i] <= 122) || (a[i] >= 65 && a[i] <= 90) ||( a[i] >= 48 && a[i] <= 57) && (a[i] != '\0'); i++);
        rev(a, i - 1);

        for (; !(a[i] >= 97 && a[i] <= 122) && !(a[i] >= 65 && a[i] <= 90) && !(a[i] >= 48 && a[i] <= 57) && (a[i] != '\0'); i++) {
            printf("%c", a[i]);
        }
        

        for (int r = 0; r < strlen(a); r++) {
            a[r] = a[r + i];
        }
        i = 0;
    }
}