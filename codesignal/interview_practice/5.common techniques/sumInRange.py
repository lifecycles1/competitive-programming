# You have an array of integers nums and an array queries, where queries[i] is a pair of indices (0-based).
# Find the sum of the elements in nums from the indices at queries[i][0] to queries[i][1] (inclusive) for 
# each query, then add all of the sums for all the queries together. Return that number modulo 109 + 7.

# Example

# For nums = [3, 0, -2, 6, -3, 2] and queries = [[0, 2], [2, 5], [0, 5]], the output should be
# solution(nums, queries) = 10.

# The array of results for queries is [1, 3, 6], so the answer is 1 + 3 + 6 = 10.

############################################################

# /**
#  * I'm going to walk through the logic of optimizing this from O(n² + n) to O(2n).
#  * The final goal: Find the sum of subsets of `nums` as represented by ranges in `queries`.
#  * 
#  * For each analysis, keep this in mind:
#  * ~ In general, optimizing algorithms is about inferring the same data with less complexity. ~
#  * 
#  * == Attempt #1 ==
#  * 
#  * The most obvious solution to this is O(n² + n):
#  *   ○ Create `subsets` array to represent the subset sums
#  *   ○ For each range in `queries`
#  *     ○ For each value in `nums` in this range
#  *       ○ Add to the sum of this subset
#  *   ○ For each sum in `subsets`
#  *     ○ Add sum to a running total
#  * 
#  * We get the sum of all of the subsets.
#  * Then, we sum them together.
#  * 
#  * == Analysis ==
#  * 
#  * So, let's consider what we are inferring with each loop:
#  *   ○ The first loop is looking through `queries` to determine the sum of each subset
#  *     ○ This loop is inferring the sum of all subsets
#  *   ○ The second loop is determining the sum of the sums of the subsets
#  *     ○ This loop is inferring the sum of the above loop
#  * 
#  * We want to infer the same data with less complexity.
#  * So, we can eliminate the second loop by just keeping the running total in the first loop.
#  * 
#  * 
#  * == Attempt #2 ==
#  * 
#  * With a single running total, this can be reduced to O(n²):
#  *   ○ For each range in `queries`
#  *     ○ For each value in `nums` in this range
#  *       ○ Add to the running total
#  * 
#  * We get every value from each subset and we sum them up together.
#  * 
#  * == Analysis ==
#  * 
#  * But, O(n²) is still far too slow.
#  * So, let's consider what we are inferring with each loop:
#  *   ○ The outer loop is looking through `queries` to find the subsets
#  *     ○ This loop is inferring how frequently each value of `nums` is added to the total
#  *   ○ The inner loop is looking through `nums` to find the sums
#  *     ○ This loop is inferring the total based on the data found in the last loop
#  * 
#  * We want to infer the same data with less complexity.
#  * To take the loop from O(n²) to O(n), we have to kill the inner loop.
#  * Our goal is for the inference of the inner loop to run only once instead of once per subset.
#  * To do this, we will build a data structure to represent the total based on the subsets.
#  * 
#  * 
#  * == Attempt #3 ==
#  * 
#  * Pulling out the handling of the total, we are back to O(n² + n) (for now):
#  *   ○ Create `frequencies` array showing how frequently each value of `nums` is in a subset
#  *   ○ For each range in `queries`
#  *     ○ For each index (do not confuse with value) in range
#  *       ○ Add 1 to this index of the `frequencies` array
#  *   ○ For each frequency in `frequencies`
#  *     ○ Add to the total: the corresponding value from `nums` multiplied by its frequency
#  * 
#  * We determine how frequently each value is in a subset.
#  * Then, we multiply the values by their frequency.
#  * 
#  * == Analysis ==
#  * 
#  * We came up with another approach, but it's still O(n² + n), which is still poor.
#  * So, let's consider what we are inferring with each loop:
#  *   ○ The outer loop is looking through `queries` to find the ranges
#  *     ○ This loop is inferring the start and end of the ranges
#  *   ○ The inner loop is looking through a range of integers
#  *     ○ This loop is inferring frequencies between the start and end of the range
#  *   ○ The final loop is using `frequencies` and `nums` to calculate the total
#  *     ○ This loop is inferring the total based on the frequencies
#  * 
#  * We want to infer the same data with less complexity.
#  * Just like before to get the loop from O(n²) to O(n), we have to kill the inner loop.
#  * So, how do we infer the frequencies without looping through each value of the range?
#  * Since all we do to the values in the range is add a constant (+1), let's use delta values.
#  * A delta value in mathematics is a value representing the variation between values.
#  * 
#  * So, instead of looping through a whole range, let's simply look at its start and end.
#  * 
#  * 
#  * == Attempt #4 ==
#  * 
#  * When only looking at the start and end of a range, we can get down to O(n + n):
#  *   ○ Create `frequencyDeltas` array to represent delta of each element from last attempt
#  *   ○ For each range in `queries`
#  *     ○ Add 1 to the index of `frequencyDeltas` of the start of the range
#  *     ○ Subtract 1 from the index of `frequencyDeltas` of the end of the range
#  *   ○ For each delta in `frequencyDeltas`
#  *     ○ Add the delta to a running "delta total" that infers the frequency
#  *     ○ Add to the total: the corresponding value of `nums` multiplied by this frequency
#  * 
#  * We determine how frequently a value shows compared to it's previous value.
#  * Then, we use that to calculate each frequency, multiply the number by it, and add to the total.
#  * 
#  * == Analysis ==
#  * 
#  * Each loop is more complex than the loops of the previous attempts, but they are not nested.
#  * As long as your loops aren't nested, you avoid the potentially disastrous O(n²) of large sets.
#  * 
#  * We did it!
#  */

# // This is the code for Attempt #4
# function solution(nums, queries) {
#     var frequencyDeltas = Array(nums.length + 1).fill(0), // Create `frequencyDeltas` array to represent delta of each element from last attempt
#         frequency = 0,
#         total = 0,
#         mod = 1000000007, // 10^9 + 7
#         i;
    
#     // For each range in `queries`
#     for (i = 0; i < queries.length; i++) {
#         frequencyDeltas[queries[i][0]]++; // Add 1 to the index of `frequencyDeltas` of the start of the range
#         frequencyDeltas[queries[i][1] + 1]--; // Subtract 1 from the index of `frequencyDeltas` of the end of the range
#     }
    
#     // For each delta in `frequencyDeltas`
#     for (i = 0; i < nums.length; i++) {
#         frequency += frequencyDeltas[i]; // Add the delta to a running "delta total" that infers the frequency
#         total += nums[i] * frequency; // Add to the total: the corresponding value of `nums` multiplied by this frequency
#     }
    
#     return ((total % mod) + mod) % mod;
# }

# /**
#  * Implementation notes:
#  *   `frequencyDeltas` is 1 index larger than `nums` because the final delta returns us to zero.
#  *   `frequencyDeltas` is filled with zeroes to prevent the code below from having "|| 0" everywhere.
#  * 
#  *   Since the ranges in `queries` are inclusive, the negative delta is *after* the range.
#  *   We made `frequencyDeltas` 1 index larger than `nums` to prevent needing to check the index.
#  * 
#  *   JavaScript does not handle the mod operation correctly with negative values.
#  *   JavaScript comes up with a negative value, which is incorrect. This math fixes that.
#  */