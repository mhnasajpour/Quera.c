#include <stdio.h>
#define SIZE 100

void read(int* array, int size) {
    int i;
    for (i = 0; i < size; i++)
        scanf("%d", array + i);     //*array+i  is wrong we should send &
}

void swap(int* a, int* b) {
    int temp = *a;   //temp should not be pointer
    *a = *b;    //we can not change &
    *b = temp;  // we should *b instead b
}

void print(const int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", *(array + i));     //array is a pointer and cant **array
}

void sort(int array[],const int* size) {
    int* end = array + *size, * i;  //i is pointer
    for (i = array; i != (end - 1); i++)
        if (*i > *(i + 1))  //we should send *i not i
            swap(i, i + 1);
}

int isSorted(const int array[], const int* size) {
    int i;
    for (i = 0; i < *size - 1; i++)
        if (*(array + i) > *(array + i + 1))
            return 0;
    return 1;
}

int main() {
    int arr[SIZE], len;
    scanf("%d", &len);
    read(arr, len);
    sort(arr, &len);
    printf("%s\n", isSorted(arr, &len) ? "All is good!" : "This isn't going as it's supposed to...");
    print(arr, len);
    return 0;
}