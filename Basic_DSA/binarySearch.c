// @author: akshara

#include <stdio.h>

int binarySearch(int[], int, int);

int main()
{
    int n; 
    scanf("%d", &n); 
    
    int arr[n]; 
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    int x; 
    scanf("%d", &x); // Input the element to be searched
    
    int result = binarySearch(arr, x, n);

    if(result == -1){
        printf("The element is not found");
    }
    else{
        printf("The element is found at index %d", result);
    }
    
    return 0;
}

// Function to perform binary search
int binarySearch(int arr[], int x, int n){
    int low = 0; 
    int high = n - 1; 
    
    while (low <= high){
        int mid_idx = (low + high) / 2; 
        int mid_ele = arr[mid_idx]; 
        
        if(mid_ele == x){
            return mid_idx; // Return the index if the element is found
        }
        else if(mid_ele > x){
            high = mid_idx - 1; 
        }
        else{
            low = mid_idx + 1; 
        }
    }
    
    return -1; // Return -1 if the element is not found

}

// Time Complexity: O(log(n)) - Binary search divides the search range in half with each iteration.