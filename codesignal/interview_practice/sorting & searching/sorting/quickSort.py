
# quick sort with recursion and partitioning
# with comments on each line

# function quickSort(arr, left, right) {
#   // get the length of the array
#   var len = arr.length, 
#   // initialize pivot and partitionIndex variables
#   pivot,
#   partitionIndex;

#   // check if left is less than right
#   if (left < right) {
#     // set pivot as the last element in the sub-array
#     pivot = right;
#     // partition the sub-array and get the partition index
#     partitionIndex = partition(arr, pivot, left, right);

#     // recursively sort the left and right sub-arrays
#     quickSort(arr, left, partitionIndex - 1);
#     quickSort(arr, partitionIndex + 1, right);
#   }
#   // return the sorted array
#   return arr;
# }

# function partition(arr, pivot, left, right) {
#   // set pivotValue as the value at the pivot index
#   var pivotValue = arr[pivot],
#       partitionIndex = left;

#   // iterate through the sub-array
#   for (var i = left; i < right; i++) {
#     // if the current element is less than the pivotValue
#     if (arr[i] < pivotValue) {
#       // swap the element with the element at partitionIndex
#       swap(arr, i, partitionIndex);
#       // increment partitionIndex
#       partitionIndex++;
#     }
#   }
#   // swap the pivot element with the element at partitionIndex
#   swap(arr, right, partitionIndex);
#   // return the partition index
#   return partitionIndex;
# }

# function swap(arr, i, j) {
#   // swap elements at index i and j
#   var temp = arr[i];
#   arr[i] = arr[j];
#   arr[j] = temp;
# }


####################################################

# JS Solution 2


# Quick sort a subarray between the given indices
# You are given an array of integers. Sort its sub-array between the given indices l and r (inclusive) 
# and leave the other elements intact.

# function solution(a, l, r) {

#   if (l >= r) {
#     return a;
#   }

#   var x = a[l];
#   var i = l;
#   var j = r;

#   while (i <= j) {
#     while (a[i] < x) {
#       i++;
#     }
#     while (a[j] > x) {
#       j--;
#     }
#     if (i <= j) {
#       var t = a[i];
#       a[i] = a[j];
#       a[j] = t;
#       i++;
#       j--;
#     }
#   }

#   solution(a, l, j);
#   solution(a, i, r);

#   return a;
# }
