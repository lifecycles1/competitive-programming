# Partial solution to the Sawtooth problem. Solved 12/16 cases

# function solution(arr) {
#     // holds the count of sawtooths at each index of our input array,
#     // for sawtooth lengths up to that index
#     var saws = Array(arr.length).fill(0);
#     // the resulting total sawtooth counts
#     var totalSawCounts = 0;
#     var previousCount = 0;

#     for (var currIdx = 1; currIdx < arr.length; currIdx++) {
#         var currCount = 0;
#         var before = currIdx - 1;
#         var goingUp;
#         if (arr[currIdx] > arr[before]) {
#             goingUp = true;
#         } else if (arr[currIdx] < arr[before]) {
#             goingUp = false;
#         } else {
#             break;
#         }

#         // if we made it here, we have at least one sawtooth
#         currCount = 1;

#         // see if there was a previous solution (the DP part)
#         // and if it continues our current sawtooth
#         if (before >= 1) {
#             if (goingUp) {
#                 if (arr[before - 1] > arr[before]) {
#                     currCount = previousCount + currCount;
#                 }
#             } else {
#                 if (arr[before - 1] < arr[before]) {
#                     currCount = previousCount + currCount;
#                 }
#             }
#         }
#         previousCount = currCount;
#         totalSawCounts = totalSawCounts + currCount;
#     }

#     return totalSawCounts;
# }
