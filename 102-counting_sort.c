#include "sort.h"
/**
 * counting_sort - sorts an array using the counting sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *output_array, i, max = 0;
	size_t j;

	if (!array || size < 2)
		return;
	/* find max val in array */
	for (j = 0; j < size; j++)
		if (array[j] > max)
			max = array[j];
	/* allocate memory for count_array and initialize to 0 */
	count_array = malloc(sizeof(int) * (max + 1));
	if (!count_array)
		return;
	for (i = 0; i <= max; i++)
		count_array[i] = 0;
	/* store count of each element */
	for (j = 0; j < size; j++)
		count_array[array[j]] += 1;
	/* modify count_array to store cumulative counts, print */
	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];
	print_array(count_array, max + 1);
	/* allocate memory for output array */
	output_array = malloc(sizeof(int) * size);
	if (!output_array)
	{
		free(count_array);
		return;
	}
	/* build output array */
	for (j = size; j > 0; j--)
	{
		output_array[count_array[array[j - 1]] - 1] = array[j - 1];
		count_array[array[j - 1]] -= 1;
	}
	/* copy the sorted elements back into the original array */
	for (j = 0; j < size; j++)
		array[j] = output_array[j];
	free(count_array);
	free(output_array);
}
