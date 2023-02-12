# sorting algorithms similar to the array.sort() built-in method

# bubble sort

# function bubbleSort(arr) {
#     for (let i = 0; i < arr.length; i++) {
#         for (let j = 0; j < arr.length - i - 1; j++) {
#             if (arr[j] > arr[j + 1]) {
#                 let temp = arr[j];
#                 arr[j] = arr[j + 1];
#                 arr[j + 1] = temp;
#             }
#         }
#     }
#     return arr;
# }


# merge sort

# function mergeSort(arr) {
#     if (arr.length === 1) {
#         return arr;
#     }

#     const middle = Math.floor(arr.length / 2);
#     const left = arr.slice(0, middle);
#     const right = arr.slice(middle);

#     return merge(mergeSort(left), mergeSort(right));
# }

# function merge(left, right) {
#     let result = [], leftIndex = 0, rightIndex = 0;

#     while (leftIndex < left.length && rightIndex < right.length) {
#         if (left[leftIndex] < right[rightIndex]) {
#             result.push(left[leftIndex]);
#             leftIndex++;
#         } else {
#             result.push(right[rightIndex]);
#             rightIndex++;
#         }
#     }

#     return result.concat(left.slice(leftIndex)).concat(right.slice(rightIndex));
# }