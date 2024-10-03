#include "sort.h"

static void merge_sort_recursive(int *array, int *temp_array,
    size_t start, size_t end);
static void merge(int *array, int *temp_array, size_t start,
    size_t middle, size_t end);

/**
 * merge_sort - sorts an array of integers in ascending order using merge sort
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
    int *temp_array;

    if (!array || size < 2)
        return;
    /* allocate temporary array once */
    temp_array = malloc(sizeof(int) * size);
    if (!temp_array)
        return;
    merge_sort_recursive(array, temp_array, 0, size - 1);
    free(temp_array);
}

/**
 * merge_sort_recursive - recursively divides and sorts the array
 * @array: array to sort
 * @temp_array: temporary array for merging
 * @start: starting index of the sub-array
 * @end: ending index of the sub-array
 */
static void merge_sort_recursive(int *array, int *temp_array,
    size_t start, size_t end)
{
    size_t middle;

    if (start >= end)
        return;
    middle = start + (end - start) / 2;
    /* adjust middle to ensure left size <= right size */
    if ((end - start + 1) % 2 != 0)
        middle++;
    merge_sort_recursive(array, temp_array, start, middle - 1);
    merge_sort_recursive(array, temp_array, middle, end);
    merge(array, temp_array, start, middle, end);
}

/**
 * merge - merges two sorted sub-arrays and prints the process
 * @array: original array containing the sub-arrays to merge
 * @temp_array: temporary array for merging
 * @start: starting index of the left sub-array
 * @middle: starting index of the right sub-array
 * @end: ending index of the right sub-array
 */
static void merge(int *array, int *temp_array, size_t start,
    size_t middle, size_t end)
{
    size_t left_index = start;
    size_t right_index = middle;
    size_t merged_index = start;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + start, middle - start);
    printf("[right]: ");
    print_array(array + middle, end - middle + 1);
    /* merge the two sub-arrays into temp_array */
    while (left_index < middle && right_index <= end)
    {
        if (array[left_index] <= array[right_index])
            temp_array[merged_index++] = array[left_index++];
        else
            temp_array[merged_index++] = array[right_index++];
    }
    while (left_index < middle)
        temp_array[merged_index++] = array[left_index++];
    while (right_index <= end)
        temp_array[merged_index++] = array[right_index++];
    /* copy merged elements back into original array */
    for (merged_index = start; merged_index <= end; merged_index++)
        array[merged_index] = temp_array[merged_index];
    printf("[Done]: ");
    print_array(array + start, end - start + 1);
}
