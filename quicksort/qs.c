#include <stdio.h>

#define SIZE 16

void swap(int *data, int i, int j)
{
    int tmp;

    printf("swap(%d, %d);\n", i, j);

    tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

void outputData(int *data, int low, int high, const char *tip)
{
    int i;

    printf("%s:\n", tip);
    for (i = low; i <= high; i++) {
        printf(" %d", data[i]);
    }
    printf("\n");
}

void quickSort(int *data, int low, int high)
{
    int std;
    int i, j;

    if (low >= high) {
        return;
    }

    i = low;
    j = high;

    std = data[low];

    while (i < j) {
        while (i < j && data[j] >= std) {
            j--;
        }
        if (i != j) {
            swap(data, i, j);
        }
        while (i < j && data[i] <= std) {
            i++;
        }
        if (i != j) {
            swap(data, i, j);
        }
    }

    quickSort(data, low, i - 1);
    quickSort(data, i + 1, high);
}

int main(void)
{
    int data[SIZE];
    int i;

    for (i = 0; i < SIZE; i++) {
        data[i] = 251 * i % 51;
    }

    outputData(data, 1, SIZE - 1, "Before");

    quickSort(data, 1, SIZE - 1);

    outputData(data, 1, SIZE - 1, "After");

    return 0;
}
