#include <stdio.h>

// Define a structure to hold the maximum and minimum values
struct MaxMin {
    int max;
    int min;
};

// Function to find the maximum and minimum values in an array
struct MaxMin findMaxMin(int size, int array[]) {
    int i;
    struct MaxMin result;

    result.max = array[0];  // Initialize max to the first element
    result.min = array[0];  // Initialize min to the first element

    // Traverse the array to find the maximum and minimum values
    for (i = 1; i < size; i++) {
        if (array[i] > result.max) {
            result.max = array[i];  // Update max if a larger element is found
        }
        if (array[i] < result.min) {
            result.min = array[i];  // Update min if a smaller element is found
        }
    }

    return result;
}

int main() {
    int size, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Call the findMaxMin() function to find the maximum and minimum values
    struct MaxMin result = findMaxMin(size, array);

    // Print the maximum and minimum values
    printf("Maximum value: %d\n", result.max);
    printf("Minimum value: %d\n", result.min);

    return 0;
}