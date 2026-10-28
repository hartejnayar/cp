#include <bits/stdc++.h>
using namespace std; 

#define ll long long 

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; 
}

void bubblesort(int a[], int n){
	for(int i =0; i<n; i++){
		for(int j =0; j<n-1-i; j++){
			if(a[j] > a[j+1]){
				swap(a[j], a[j+1]);
			}
		}
	}
}
void selectionsort(int a[], int n){
	for(int i=0; i<n-1; i++){
		int min = i;
		for(int j=i+1; j<n; j++){
			if(a[j] < a[min]){
				min = j;
			}
		}

		swap(a[i], a[min]);
	}
}

void insertionsort(int a[], int n){
	for(int i=0; i<n-1; i++){
		int curr = a[i];
		int prev = i-1;

		while(prev >=0 && a[prev] < curr){
			a[prev+1] = a[prev];
			prev--;
		}

		a[prev] = curr;
	}
}

void countingsort(int a[], int n) {
    if (n <= 0) return;

    // Find the minimum and maximum elements in the array
    int maxVal = a[0];
    int minVal = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > maxVal) maxVal = a[i];
        if (a[i] < minVal) minVal = a[i];
    }

    int range = maxVal - minVal + 1;
    
    // Allocate raw memory for count and output arrays
    int* count = new int[range](); // () initializes all elements to 0
    int* output = new int[n];

    // Store frequency of each element
    for (int i = 0; i < n; i++) {
        count[a[i] - minVal]++;
    }

    // Change count[i] so that count[i] contains the actual position of this element in output
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array (traverse backwards to maintain stability)
    for (int i = n - 1; i >= 0; i--) {
        output[count[a[i] - minVal] - 1] = a[i];
        count[a[i] - minVal]--;
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }

    // Free the dynamically allocated memory
    delete[] count;
    delete[] output;
}





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a[n];

    for(int i =0; i<n;i++){
    	cin >> a[i];
    }
   	
   	selectionsort(a,n);
   	printArray(a,n);
    

   	bubblesort(a,n);
   	printArray(a,n);

   	insertionsort(a,n);
   	printArray(a,n);
    
}
