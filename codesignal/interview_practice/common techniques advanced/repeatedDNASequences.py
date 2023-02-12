# All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T. In research, it can be useful 
# to identify repeated sequences within DNA.

# Write a function to find all the 10-letter sequences (substrings) that occur more than once in a DNA 
# molecule s, and return them in lexicographical order. These sequences can overlap.

# Example

# For s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", the output should be
# solution(s) = ["AAAAACCCCC", "CCCCCAAAAA"].


# function solution(s) {
#     let sequences = {};
#     let multiples = [];
#     for(let i = 0, ii = s.length; i < ii; i++) {
#         let seq = s.slice(i,i+10);
#         if (seq.length !== 10) break;
#         if (sequences[seq] == null) sequences[seq] = 0;
#         sequences[seq]++;
#     }
#     for (let pos in sequences) {
#         if (sequences[pos] > 1) multiples.push(pos); 
#     }
#     return multiples.sort();
# }

