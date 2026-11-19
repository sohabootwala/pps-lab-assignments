#include <stdio.h>

// Function prototype using pointers (call by reference)
void swap(int *a, int *b);

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("\nBefore Swapping:\n");
    printf("First number=%d, Second number=%d\n", num1, num2);

    // Pass addresses of num1 and num2 to swap()
    swap(&num1, &num2);

    printf("After Swapping:\n");
    printf("First number=%d, Second number=%d\n", num1, num2);

    return 0;
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;  // Store value at address 'a' in temp
    *a = *b;    // Copy value at address 'b' into address 'a'
    *b = temp;  // Copy temp value into address 'b'
}
