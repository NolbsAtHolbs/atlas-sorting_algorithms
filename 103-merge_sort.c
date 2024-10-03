#include "sort.h"

static void merge_sort_recursive(int *array, int *temp_array,
	size_t start, size_t end);
static void merge(int *array, int *temp_array, size_t start,
	size_t middle, size_t end);

/**
 * merge_sort - sorts an array of integers in ascending order using merge sort
 * @array: array of integers to sort
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
	/* free the allocated memory */
	free(temp_array);
}

/**
 * merge_sort_recursive - recursively divides the array and sorts the subarrays
 * @array: array of integers to sort
 * @temp_array: temporary array for merging
 * @start: starting index of the subarray
 * @end: ending index of the subarray
 */
static void merge_sort_recursive(int *array, int *temp_array,
	size_t start, size_t end)
{
	size_t middle;

	if (start >= end)
		return;
	/* calculate the middle index */
	middle = start + (end - start - 1) / 2;
	merge_sort_recursive(array, temp_array, start, middle);
	merge_sort_recursive(array, temp_array, middle + 1, end);
	merge(array, temp_array, start, middle, end);
}

/**
 * merge - merges two sorted subarrays and prints the process
 * @array: array containing the subarrays to merge
 * @temp_array: temporary array for merging
 * @start: starting index of the first subarray
 * @middle: ending index of the first subarray
 * @end: ending index of the second subarray
 */
static void merge(int *array, int *temp_array, size_t start,
	size_t middle, size_t end)
{
	size_t i = start, j = middle + 1, k = start;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(&array[start], middle - start + 1);
	printf("[right]: ");
	print_array(&array[middle + 1], end - middle);
	/* merge the subarrays into temp_array */
	while (i <= middle && j <= end)
	{
		if (array[i] <= array[j])
			temp_array[k++] = array[i++];
		else
			temp_array[k++] = array[j++];
	}
	while (i <= middle)
		temp_array[k++] = array[i++];
	while (j <= end)
		temp_array[k++] = array[j++];
	/* copy the merged elements back into the original array */
	for (i = start; i <= end; i++)
		array[i] = temp_array[i];
	printf("[Done]: ");
	print_array(&array[start], end - start + 1);
}
