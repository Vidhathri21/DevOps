#include <stdio.h>
#include <stdlib.h>

int sender(int arr[10], int n) {
    int ch = 0, i;
    printf("\n Sender side:");

    for (i = 0; i < n; i++)
        ch ^= arr[i]; // XOR operation to calculate checksum

    printf("\n Checksum is %d ", ch);
    return ch;
}

void receiver(int arr[10], int n, int sch) {
    int ch = 0, i;
    printf("\n Receiver side:");

    for (i = 0; i < n; i++)
        ch ^= arr[i]; // XOR operation to calculate checksum

    ch ^= sch; // XOR with the sent checksum
    printf("\n Checksum is %d ", ch);

    if (ch == 0)
        printf("\n No error detected.\n");
    else
        printf("\n Error detected!\n");
}

int main() {
    int n, sch, i;
    printf("\n Enter size of string (up to 10):");
    scanf("%d", &n);

    if (n > 10) {
        printf("Array size should be 10 or less.\n");
        return 1; // Exit with an error code
    }

    int arr[n];
    printf("\n Enter the bits (0 or 1):");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sch = sender(arr, n);
    receiver(arr, n, sch);

    return 0;
}

