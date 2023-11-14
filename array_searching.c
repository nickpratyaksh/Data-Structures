#include <stdio.h>

void linearSearch(int array[], int value);
void binarySearch(int array[], int value);

int main()
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // linearSearch(array, 5);
    // binarySearch(array, 10);
    return 0;
}

void linearSearch(int array[], int value)
{
    for (int i = 0; i <= 9; i++)
        if (array[i] == value)
            printf("Item found at %d", i + 1);
}

void binarySearch(int array[], int value)
{
    int low = 0, high = 9, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] > value)
            high = mid - 1;
        else if (array[mid] < value)
            low = mid + 1;
        else
        {
            printf("Item found at %d", mid + 1);
            break;
        }
    }
}