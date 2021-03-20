#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

struct input {
    int id;
    char name[100];
};

int main() {
    struct input n;
    int num;
    FILE* a = fopen("SampleFile.txt", "rb");
    scanf("%d", &num);
    fseek(a, (num-1) * sizeof(struct input), SEEK_SET);
    fread(&n, sizeof(struct input), 1, a);
    printf("%d : %s", n.id, n.name);
    fclose(a);
}