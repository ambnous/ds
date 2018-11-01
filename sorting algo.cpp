// program to implement different sorting techniques

#include <iostream>
#include <cstdio>

using namespace std;

void bubbleSort() {
	cout << "\nEnter the size of the array: ";
	int size;
	cin >> size;
	int a[size];
	cout << "\nEnter the array elements: ";
	for (int i=0; i<size; ++i)
		cin >> a[i];
	cout << endl;
	cout << "\nUnsorted array\n";
	int j = 0;
	bool sort = true;
	for (int i=0; i<size; ++i)
		cout << a[i] << " ";
	for (int i=0; i<size-1; ++i) {
		sort = false;
		for (int j=0; j<size-1-i; ++j) {
			if (a[j] > a[j+1]) { 
				swap(a[j], a[j+1]);
				sort = true;
			}
		}
		if (!sort)
			break;
		cout << "\nAfter " << i+1 << " iteration the array is: ";
		for (int i=0; i<size; ++i)
			cout << a[i] << " ";
	}
	cout << endl;
	cout << "\nThe sorted array is: ";
	for (int i=0; i<size; ++i)
		cout << a[i] << " ";
	cout << endl;
}

void selectionSort() {
	cout << "\nEnter the size of the array: ";
	int size;
	cin >> size;
	int a[size];
	cout << "\nEnter the array elements: ";
	for (int i=0; i<size; ++i)
		cin >> a[i];
	cout << endl;
	cout << "\nUnsorted array\n";
	for (int i=0; i<size; ++i)
		cout << a[i] << " ";
	int indexMin,i,j;
	bool sort = true;
    for(i = 0; i < size-1; i++) { 
    	indexMin = i;
    	sort = false;
        for(j = i+1; j < size; j++) {
        	if(a[j] < a[indexMin]) {
            indexMin = j;
            sort = true;
         	}
      	}
      	if (!sort)
      		break;
      	swap(a[i], a[indexMin]);
		cout << "\nAfter " << i+1 << " iteration the array is: ";
		for (int i=0; i<size; ++i)
			cout << a[i] << " ";
	}
	cout << endl;
	cout << "\nThe sorted array is: ";
	for (int i=0; i<size; ++i)
		cout << a[i] << " ";
	cout << endl;
}

void insertionSort() {
	cout << "\nEnter the size of the array: ";
	int size;
	cin >> size;
	int a[size];
	cout << "\nEnter the array elements: ";
	for (int i=0; i<size; ++i)
		cin >> a[i];
	cout << endl;
	cout << "\nUnsorted array\n";
	for (int i=0; i<size; ++i)
		cout << a[i] << " ";
	for (int i=0; i<size; ++i) {
		int temp = a[i];
		int j = i;
		while (j > 0 && temp < a[j - 1]) {
			swap(a[j], a[j-1]);
			//a[j] = a[j-1];
			--j;
		}
		//a[j] = temp;
		cout << "\nAfter " << i+1 << " iteration the array is: ";
		for (int i=0; i<size; ++i)
			cout << a[i] << " ";
	}
	cout << endl;
	cout << "\nThe sorted array is: ";
	for (int i=0; i<size; ++i)
		cout << a[i] << " ";
	cout << endl;	
}

void merge(int arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

int min(int x, int y) { 
	return (x < y) ? x : y; 
}

void mergeSort(int arr[], int n) { 
   int curr_size; 
   int left_start;

   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size) { 
		for (left_start=0; left_start<n-1; left_start += 2*curr_size) { 
           int mid = left_start + curr_size - 1; 
  
           int right_end = min(left_start + 2*curr_size - 1, n-1); 
  
           merge(arr, left_start, mid, right_end); 
       } 
   }
    cout << "Sorted array";
	for (int i=0; i<8; ++i)
		cout << arr[i] << " ";
} 

int partition (int arr[], int l, int h) { 
    int x = arr[h]; 
    int i = (l - 1); 
	for (int j = l; j <= h- 1; j++) { 
        if (arr[j] <= x) { 
            i++; 
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[h]); 
    return (i + 1); 
} 

void quickSort(int A[], int l, int h) { 
    if (l < h) {      
        int p = partition(A, l, h);  
        quickSort(A, l, p - 1);  
        quickSort(A, p + 1, h); 
    }
} 

int binary(int arr[], int low, int high, int num){
	int mid = (low + high) / 2;
	if (low > high)
		cout << "\nElement not found in the array.\n";
	else { 
		if (arr[mid] == num)
			return mid+1;
		else if (num < arr[mid])
			return binary(arr, low,  mid-1, num);
		else if (num > arr[mid])
			return binary(arr, mid + 1,high, num);
	}
}

int main() {
	int choice;
	int a[8] = {0};
	while (true) {
		cout << "\n1) Bubble Sort\n";
		cout << "\n2) Selection Sort\n";
		cout << "\n3) Insertion Sort\n";
		cout << "\n4) Quick Sort\n";
		cout << "\n5) Merge Sort\n";
		cout << "\n6) Linear Search\n";
		cout << "\n7) Binary Search\n";
		cout << "\n8) Exit\n";
		cout << "\n>> Enter your choice: ";
		cin >> choice;
		switch (choice) {
			case 1:	system("cls");
					cout << "\n----Bubble Sort----\n";
					bubbleSort();
					break;
			case 2:	system("cls");
					cout << "\n----Selection Sort----\n";
					selectionSort();
					break;
			case 3:	system("cls");
					cout << "\n----Insertion Sort----\n";
					insertionSort();
					break;
			case 4:	{
						system("cls");
						cout << "\n----Quick Sort----\n";
						cout << "Enter the elements of the array" << endl;
						for (int i=0; i < 8; ++i)
							cin >> a[i];
						int l = 0 , h = 7;
						quickSort(a, l , h);
						cout << "Sorted array\n";
						for (int i=0; i<8; ++i)
							cout << a[i] << " ";  
						break;
					}
			case 5:	{
						system("cls");
						cout << "\n----Merge Sort----\n";
						cout << "Enter the elements of the array" << endl;
						for (int i=0; i < 8; ++i)
							cin >> a[i];
						mergeSort(a, 8);
						break;
					}
			case 6: {
						system("cls");
						cout << "\n----Linear Search----\n";
						cout << "Enter the size of the array: ";
						int size;
						cin >> size;
	
						int a[size];
						cout << "Enter the elements of the array" << endl;
						for (int i=0; i < size; ++i)
						cin >> a[i];
	
						cout << endl << "Enter the number you want to search for: ";
						int num;
						cin >> num;
						int pos = 0;
						for (int i = 0;i  < size; ++i) {
							if (a[i] == num ){
								pos = i+1;
								break;
							}
						}
	
						if (pos == 0)
							cout << "The number was not found in the array. \n";
						else
							cout << "\nThe desired number was found at position: " << pos;
						break;
					}
			case 7: {
						system("cls");
						cout << "\n----Binary Search----\n";
						cout << "Enter the size of the array: ";
						int size;
						cin >> size;
						int arr[size];
						cout << "\nEnter the elements in the array in sorted order\n";
						for (int i= 0;i < size; ++i)
							cin >> arr[i];
						cout << "\nEnter the number you want to search in the array: ";
						int num;
						cin >> num;
						cout << endl;
						int find = binary(arr, 0, size-1, num);
						cout << "Number found at position: " << find;
						break;
					}
			case 8:	return false;
			default: cout << "\nPlease enter a valid input\n";
		}
	}
	return 0;
}
