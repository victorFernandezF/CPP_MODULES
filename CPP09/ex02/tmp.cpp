# include <iostream>

void bubbleSort(int arr[], int n)
{
    // Base case
    if (n == 1)
        return;
 
    // One pass of bubble sort. After
    // this pass, the largest element
    // is moved (or bubbled) to end.
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            std::swap(arr[i], arr[i + 1]);
 
    // Largest element is fixed,
    // recur for remaining array
    bubbleSort(arr, n - 1);
}
 
/* Function to print an array */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout<<arr[i]<<" ";
    std::cout<<"\n";
}
 
// Driver program to test above functions
int main()
{
	int arr[] = { 18, 26, 68, 90, 82, 36, 63, 85, 61, 48, 46, 31, 59, 9, 80, 72, 49, 52, 38, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}