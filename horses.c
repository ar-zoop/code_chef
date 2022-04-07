#include <stdio.h>

void swap(long long *, long long *);
void heapify(long long[],int,int);
void heapSort(long long[],int);

int main(){
	int t,n,diff;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		long long s[n];
		for (int i=0;i<n;i++)
			scanf("%lld",&s[i]);
		heapSort(s, n);
		diff=s[1]-s[0];
		for (int i = 2; i < n; ++i){
			if(diff>(s[i]-s[i-1]))
				diff=s[i]-s[i-1];
				if (diff==0)
					break;
		}
		printf("%lld\n",diff);
			
	}
	return 0;
}

  // Function to swap the the position of two elements
  void swap(long long *a, long long *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void heapify(long long arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  // Main function to do heap sort
  void heapSort(long long arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }

