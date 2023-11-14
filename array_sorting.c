#include <stdio.h>

void display(int array[]);
void swap(int *x, int *y);
void bubbleSort(int *array[]);
void selectionSort(int *array[]);
void insertionSort(int *array[]);
void mergeSort(int *array[], int len);
void merge(int *array[], int *leftArray[], int *rightArray[], int l, int leftSize, int rightSize);
void quickSort(int *array[], int start, int len);

int main()
{
    int array[10] = {7, 5, 10, 9, 2, 6, 1, 8, 4, 3};
    int len = sizeof(array) / sizeof(array[0]);

    // bubbleSort(array);
    // selectionSort(array);
    // insertionSort(array);
    // mergeSort(array, len);
    quickSort(array, 0, len - 1);
    display(array);
    return 0;
}

void display(int array[])
{
    for (int i = 0; i < 10; i++)
        printf("%d ", array[i]);
}

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubbleSort(int *array[])
{
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 8; j++)
        {
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
        }
    }
}

void selectionSort(int *array[])
{
    for (int i = 0; i < 9; i++)
    {
        int min = array[i], pos = i;
        for (int j = i + 1; j <= 9; j++)
            if (array[j] < min)
            {
                min = array[j];
                pos = j;
            }
        if (min != array[i])
            swap(&array[i], &array[pos]);
    }
}

void insertionSort(int *array[])
{
    for (int i = 1; i < 10; i++)
    {
        int tmp = array[i];
        int j = i - 1;
        while (array[j] > tmp && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = tmp;
    }
}

void mergeSort(int *array[], int len)
{
    if (len == 1)
        return;

    int leftSize = len / 2;
    int rightSize = len - leftSize;
    int leftArray[leftSize], rightArray[rightSize];

    for (int i = 0, j = 0; i < len; i++)
    {
        if (i < leftSize)
            leftArray[i] = array[i];
        else
        {
            rightArray[j] = array[i];
            j++;
        }
    }

    // printf("left array - ");
    // for (int i = 0; i < leftSize; i++)
    //     printf("%d ", leftArray[i]);
    // printf("\nright array - ");
    // for (int i = 0; i < rightSize; i++)
    //     printf("%d ", rightArray[i]);
    // printf("\n----------------\n");

    mergeSort(leftArray, leftSize);
    mergeSort(rightArray, rightSize);
    merge(array, leftArray, rightArray, len, leftSize, rightSize);

    // printf("%d %d", leftSize, rightSize);
}

void merge(int *array[], int *leftArray[], int *rightArray[], int len, int leftSize, int rightSize)
{
    // printf("merge function called\n");

    int i = 0, l = 0, r = 0;

    while (l < leftSize && r < rightSize)
    {
        if (leftArray[l] < rightArray[r])
        {
            array[i] = leftArray[l];
            l++;
            i++;
        }
        else
        {
            array[i] = rightArray[r];
            r++;
            i++;
        }
    }
    while (l < leftSize)
    {
        array[i] = leftArray[l];
        l++;
        i++;
    }
    while (r < rightSize)
    {
        array[i] = rightArray[r];
        r++;
        i++;
    }

    // printf("merged array - ");
    // for (int i = 0; i < len; i++)
    //     printf("%d ", array[i]);
    // printf("\n^^^^^^^^^^^^^^^^^^^^^^^^\n");
}

void quickSort(int *array[], int start, int end)
{
    if (end <= start)
        return;

    int pivot = end;
    int i = -1, j = 0;

    while (j <= end)
    {
        if (array[j] < array[pivot])
        {
            i++;
            swap(&array[i], &array[j]);
        }
        j++;
    }
    i++;
    swap(&array[i], &array[pivot]);

    // for (int i = start; i <= end; i++)
    //     printf("%d ", array[i]);
    // printf("\n--------------------\n");

    quickSort(array, start, i - 1);
    quickSort(array, i + 1, end);
}