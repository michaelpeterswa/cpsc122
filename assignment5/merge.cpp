#include <iostream>

using namespace std;


void insertionSort(int array[], int size){
  int j, i, temp;
  int count = 0;

  for(i=0; i < size; i++){
    j = i;

    while(j > 0 && array[j] < array[j-1]){
      count++;
      temp = array[j];
      array[j] = array[j-1];
      array[j-1] = temp;
      j--;
    }
  }
  cout << count << endl;
}
// A function to merge the two half into a sorted data.
void Merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

// A function to split array into two parts.
int MergeSort(int *a, int low, int high)
{
	int mid;
  int count;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		// Merge them to get sorted output.
		Merge(a, low, high, mid);

    count++;
	}
  return count;
}

int main()
{
int A_SIZE = 5;
int B_SIZE = 10;
int C_SIZE = 50;

	int a[A_SIZE] = {336, 626, 531, 403, 830};
  int b[B_SIZE] = {630, 76, 453, 698, 959, 203, 347, 484, 847, 617};
  int c[C_SIZE] = {575, 559, 211, 744, 172, 621, 77, 617, 601, 948, 342, 254, 813, 420, 395, 595, 509, 815, 352, 96, 634, 123, 79, 908, 937, 390, 362, 891, 718, 498,
     91, 517, 164, 199, 895, 540, 867, 11, 542, 643, 299, 631, 369, 97, 710, 991, 242, 71, 391, 653};
 //for (int i = 0; i < B_SIZE; i++)
  //   cout<<"->"<<b[i];
    // cout << endl;

//cout << MergeSort(b, 0, B_SIZE-1) << endl;
//MergeSort(b, 0, B_SIZE-1);
//cout << MergeSort(a, 0, A_SIZE-1) << endl;

//cout << MergeSort(c, 0, C_SIZE-1) << endl;
	// Printing the sorted data.
//	cout<<"\nSorted Data ";
	//for (int i = 0; i < B_SIZE; i++)
    //  cout<<"->"<<b[i];
      //cout << endl;
insertionSort(a, A_SIZE);
insertionSort(b, B_SIZE);
insertionSort(c, C_SIZE);

	return 0;
}
