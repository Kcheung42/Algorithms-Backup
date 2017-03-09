#include <stdlib.h>
#include <stdio.h>

/* void	merge(int *L, int *R, int *A) */
/* { */
/* 	printf("merging back to A\n"); */
/* 	int	nl; */
/* 	int	nr; */
/* 	int	i; */
/* 	int	j; */
/* 	int	k; */
/*  */
/* 	i = 0; */
/* 	j = 0; */
/* 	k = 0; */
/*  */
/* 	while (i < nl && j < nr) */
/* 	{ */
/* 		if (L[i] < R[j]) */
/* 		{ */
/* 			A[k] = L[i]; */
/* 			i += 1; */
/* 		} */
/* 		else */
/* 		{ */
/* 			A[k] = R[j]; */
/* 			j += 1; */
/* 		} */
/* 		k += 1; */
/* 	} */
/* 	while (i < nl) */
/* 	{ */
/* 		A[k] = L[i]; */
/* 		i += 1; */
/* 		k += 1; */
/* 	} */
/* 	while (j < nl) */
/* 	{ */
/* 		A[k] = R[j]; */
/* 		j += 1; */
/* 		k += 1; */
/* 	} */
/* } */

/* void	merge_sort(int *A) */
/* { */
/* 	printf("split merge\n"); */
/* 	int	n; */
/* 	int	mid; */
/* 	int	*left; */
/* 	int	*right; */
/* 	int	i; */
/*  */
/* 	n = sizeof(A)/4; */
/* 	if (n < 2) */
/* 		return ; */
/* 	mid = n/2; */
/* 	printf("n:%d\n",n); */
/* 	printf("mid:%d\n", mid); */
/* 	left = (int *)malloc(sizeof(int) * mid); */
/* 	right = (int *)malloc(sizeof(int) * (n-mid)); */
/* 	printf("sizeof left:%zu\n",sizeof(left)/4); */
/* 	printf("sizeof right:%zu\n",sizeof(right)/4); */
/* 	i = 0; */
/* 	while (i < mid - 1) */
/* 	{ */
/* 		left[i] = A[i]; */
/* 		i++; */
/* 	} */
/* 	while (i < n - 1) */
/* 	{ */
/* 		right[i - mid] = A[i]; */
/* 		i++; */
/* 	} */
/* 	merge_sort(left); */
/* 	merge_sort(right); */
/* 	merge(left, right, A); */
/* 	free(left); */
/* 	free(right); */
/* } */
/*  */
/* int main(int argc, const char *argv[]) */
/* { */
/* 	int	array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; */
/* 	merge_sort(array); */
/* 	return 0; */
/* } */

void	mergehalves(int *array, int *temp, int leftstart, int rightend)
{
	int	leftend = (leftstart + rightend) / 2;
	int	rightstart = leftend + 1;
	int	size = rightend - leftstart + 1;
	int	left = leftstart;
	int	right = rightstart;
	int	index = leftstart;

	while (left < leftend && right < rightend)
	{
		if (array[left] < array[right])
		{
			temp[index] = array[left];
			left += 1;
		}
		else
		{
			temp[index] = array[right];
			right += 1;
		}
		index++;
	}
	while (left < leftend - left + 1)
	{
		temp[index] = array[left];
		index++;
		left++;
	}
	while (right < rightend - right + 1)
	{
		temp[index] = array[right];
		index++;
		right++;
	}
	int i = leftstart;
	while (i < size)
	{
		temp[i] = array[i];
		i++;
	}
}

void	merging(int *array, int *temp, int leftstart, int rightend)
{
	if (leftstart < rightend)
	{
		int mid = (leftstart + rightend) / 2;
		merging(array, temp, leftstart, mid);
		merging(array, temp, mid + 1, rightend);
		mergehalves(array, temp, leftstart, rightend);
	}
}

void	merge_sort(int *array)
{
	int	*temp = (int *)malloc(sizeof(int) * sizeof(array)/4);
	int	arraylen = sizeof(array)/4;
	merging(array, temp, 0, arraylen);
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int	array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	merge_sort(array);
	while (i < 10)
	{
		printf("%d\n", array[i]);
		i++;
	}
	return 0;
}
