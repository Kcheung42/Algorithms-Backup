/* In computer science, merge sort (also commonly spelled mergesort) is an  */
/* efficient, general-purpose, comparison-based sorting algorithm. */
/* Most implementations produce a stable sort, which means that the implementation */
/* preserves the input order of equal elements in the sorted output. Merge sort. */
/* is an in-place sorting algorithm. This method uses recursion. */

/* Time Complexity: */
/* 	Best:	n log(n) */
/* 	Average:n log(n) */
/* 	worst:	O(n^2) */

/* This particular implementation is unstable */

#include <stdio.h>

/* partition function: set pivot as end of the array and swap */
/* 	until numbers on the left is lower than pivot and numbers on */
/* 	right is larger. */
/* Return: new index of the pivot */

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *A, int start, int  end)
{
	int	pivot_index;
	int	pivot;
	int	i;

	pivot = A[end];
	pivot_index = start;
	i = start;
	while (i < end)
	{
		if (A[i] < pivot)
		{
			swap(&A[i], &A[pivot_index]);
			pivot_index++;
		}
		i++;
	}
	swap(&A[pivot_index], &A[end]);
	return (pivot_index);
}

void	quick_sort(int *A, int start, int end)
{
	int	pivot;

	if (start < end)
	{
		pivot = partition(A, start, end); // partition return pivot index
		quick_sort(A, start, pivot - 1);
		quick_sort(A, pivot + 1, end);
	}
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int	array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	quick_sort(array, 0, 10);
	while (i < 10)
	{
		printf("%d\n", array[i]);
		i++;
	}
	return 0;
}
