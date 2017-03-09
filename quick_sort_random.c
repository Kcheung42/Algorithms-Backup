#include <stdio.h>

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *A, int left, int right, int pivot)
{
	while (left <= right)
	{
		while (A[left] < pivot)
			left++;
		while (A[right] > pivot)
			right--;
		if (left <= right)
		{
			swap(&A[left], &A[right]);
			left++;
			right--;
		}
	}
	return (left);
}
void	quick_sort(int *A, int left, int right)
{
	int	pivot;
	int	index;

	if (left >= right)
		return;
	pivot = A[(left + right)/2];
	index = partition(A, left, right, pivot);
	quick_sort(A, left, pivot - 1);
	quick_sort(A, pivot + 1, right);
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int	array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	quick_sort(array, 0, 9);
	while (i < 10)
	{
		printf("%d\n", array[i]);
		i++;
	}
	return 0;
}
