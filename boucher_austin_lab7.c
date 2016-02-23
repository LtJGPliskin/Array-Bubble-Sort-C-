#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int a;//hold the max array size
int k;//runs for loops
int partition(int array[], int low, int high);
void swap(int array[], int index1, int index2);
int populate_array(int array[])//allows you to populate the array
{
  a = 101;
  while(a > 100)
    {
  printf("Enter the value of n > ");
  scanf("%d", &a);
  printf("Please enter %d integers\n", a);
    }
  for(k = 0; k < a; k++)
    {
      int b;
      scanf("%d", &b);
      array[k] = b;
    }
}
void print_array(int array[], int n)//prints the array in the order of the array
{
  for(k = 0; k < n; k++)
    {
      printf("%d  ", array[k]);
    }
  printf("\n");
}
void quicksort(int array[], int low, int high)//recursively runs the quicksort until it is sorted completely
{
  int pivot;
  if(low < high)
    {
      pivot = partition(array, low, high);
      quicksort(array, low, pivot - 1);
      quicksort(array, pivot + 1, high);
    }
}
int partition(int array[], int low, int high)//finds a pivot and swaps out the higher and lower numbers till in order
{
  int pivot = array[high];
  while(low < high)
    {
      while(array[low]< pivot)
	{
	  low++;
	}
      while(array[high] > pivot)
	{
	  high--;
	}
      if(array[low] == array[high])
	{
	  low++;
	}
      else if(low < high)
	{
	  int temp = array[low];
	  array[low] = array[high];
	  array[high] = temp;
	}
    }
return high;
}
void swap(int array[], int index1, int index2)//not used, but would swap out the lows for highs 
{
  int temp = index1;
  index1 = index2;
  array[index2] = array[temp];
}

int main(void)//runs the program
{
  int array[100];
  populate_array(array);
  print_array(array, a);
  quicksort(array, 0, a-1);
  printf("\n");
  print_array(array, a);
}

