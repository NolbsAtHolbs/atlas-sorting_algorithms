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

	if (start < end)
	{
		middle = start + (end - start - 1) / 2;
		merge_sort_recursive(array, start, middle);
		merge_sort_recursive(array, middle + 1, end);
		merge(array, start, middle, end);
	}
}

/**
 * merge - merges two sorted subarrays and prints the process
 * @array: array containing the subarrays to merge
 * @start: starting index of the first subarray
 * @middle: ending index of the first subarray
 * @end: ending index of the second subarray
 */
static void merge(int *array, size_t start, size_t middle, size_t end)
{
	size_t left_size = middle - start + 1;
	size_t right_size = end - middle;
	int left_array[4096], right_array[4096];
	size_t i = 0, j = 0, k = start;

	printf("Merging...\n");
	/* copy data to temporary arrays */
	for (i = 0; i < left_size; i++)
		left_array[i] = array[start + i];
	printf("[left]: ");
	print_array(left_array, left_size);
	for (i = 0; i < right_size; i++)
		right_array[i] = array[middle + 1 + i];
	printf("[right]: ");
	print_array(right_array, right_size);
	/* merge the temporary arrays back into the original array */
	i = 0;
	while (k <= end)
	{
		if (i < left_size && (j >= right_size || left_array[i] <= right_array[j]))
			array[k++] = left_array[i++];
		else
			array[k++] = right_array[j++];
	}
	printf("[Done]: ");
	print_array(&array[start], end - start + 1);
}
