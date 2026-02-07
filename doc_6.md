Program 6: Min and Max Heap Construction
(A) Data Structures Defined
- an integer array arr[] is defined to hold the unsorted data.
- n is the size of the array.
- the heap is represented in array form, with parent and child indices calculated using formulas.

(B) Functions
1: swap(int *a, int *b)
- swaps two integer values using a temporary variable.
2: max_heap(int arr[], int n, int i)
- enforces the max heap property.
- compares parent with left and right children.
- swaps if necessary and recursively heapifies.
3: min_heap(int arr[], int n, int i)
- enforces the min heap property.
- compares parent with left and right children.
- swaps if necessary and recursively heapifies.
4: build_max(int arr[], int n)
- builds the max heap from the unsorted array.
- calls max_heap starting from the lowest non-leaf node up to the root.
5: build_min(int arr[], int n)
- builds the min heap from the unsorted array.
- calls min_heap starting from the lowest non-leaf node up to the root.
6: print(int arr[], int n)
- prints the array elements in sequence.

(C) The main() function
- defines an unsorted array arr[] = {9, 4, 7, 1, -2, 6, 5}.
- calculates the size n.
- prints the original array.
- calls build_max() and prints the max heap.
- defines another array with the same elements.
- calls build_min() and prints the min heap.

(D) Output
original array:
9 4 7 1 -2 6 5 
max heap:
9 4 7 1 -2 6 5
min heap:
-2 1 5 9 4 6 7