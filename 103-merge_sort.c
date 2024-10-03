#include "sort.h"

static void merge_sort_recursive(int *array, size_t start, size_t end);
static void merge(int *array, size_t start, size_t middle, size_t end);

/**
 * merge_sort - sorts an array of integers in ascending order using merge sort
 * @array: array of integers to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	merge_sort_recursive(array, 0, size - 1);
}

/**
 * merge_sort_recursive - recursively divides the array and sorts the subarrays
 * @array: array of integers to sort
 * @start: starting index of the subarray
 * @end: ending index of the subarray
 */
static void merge_sort_recursive(int *array, size_t start, size_t end)
{
	size_t middle;

	if (start >= end)
		return;
	/* calculate the middle index to divide the array */
	middle = start + (end - start) / 2;
	/* ensure left subarray size <= right subarray size */
	if ((end - start + 1) % 2 == 0)
		middle = middle;
	else
		middle = middle + 1;
	merge_sort_recursive(array, start, middle - 1);
	merge_sort_recursive(array, middle, end);
	merge(array, start, middle, end);
}

/**
 * merge - merges two sorted subarrays and prints the process
 * @array: array containing the subarrays to merge
 * @start: starting index of the first subarray
 * @middle: starting index of the second subarray
 * @end: ending index of the second subarray
 */
static void merge(int *array, size_t start, size_t middle, size_t end)
{
	size_t left_size = middle - start;
	size_t right_size = end - middle + 1;
	int *left_array, *right_array;
	size_t i = 0, j = 0, k = start;
	/* allocate memory for temporary arrays */
	left_array = malloc(sizeof(int) * left_size);
	right_array = malloc(sizeof(int) * right_size);
	if (!left_array || !right_array)
	{
		free(left_array);
		free(right_array);
		return;
	}
	/* copy data to temporary arrays */
	for (i = 0; i < left_size; i++)
		left_array[i] = array[start + i];
	for (j = 0; j < right_size; j++)
		right_array[j] = array[middle + j];
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left_array, left_size);
	printf("[right]: ");
	print_array(right_array, right_size);
	/* reset indices for merging */
	i = 0;
	j = 0;
	/* merge the temporary arrays back into the original array */
	while (i < left_size && j < right_size)
	{
		if (left_array[i] <= right_array[j])
			array[k++] = left_array[i++];
		else
			array[k++] = right_array[j++];
	}
	while (i < left_size)
		array[k++] = left_array[i++];
	while (j < right_size)
		array[k++] = right_array[j++];
	printf("[Done]: ");
	print_array(&array[start], end - start + 1);
	/* free allocated memory */
	free(left_array);
	free(right_array);
}
