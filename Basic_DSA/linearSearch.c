// @author: akshara

#include <stdio.h>

int linearSearch(int, int[], int);

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
    
    // Call the linearSearch function to find the element
    int result = linearSearch(n, arr, x); 

    // Check and print the result
    if(result == -1){
        printf("The element does not exist");
    }
    else{
        printf("The element does exist at index %d", result);
    }

    return 0;
}

// Function to perform linear search
int linearSearch(int n, int arr[], int x){
    int idx;
    for(int i = 0; i < n; i++){
        if(x == arr[i]){
            idx = i; 
            return idx; 
        }
    }
    return -1; // Return -1 if the element is not found
}

// Time Complexity: O(n) - Linear search checks each element in the array once.
