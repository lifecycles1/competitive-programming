# There are n uniquely-sized sticks whose lengths are integers from 1 to n. 
# You want to arrange the sticks such that exactly k sticks are visible from the left. 
# A stick is visible from the left if there are no longer sticks to the left of it.

# For example, if the sticks are arranged [1,3,2,5,4], then the sticks with lengths 1, 3, and 5 
# are visible from the left.
# Given n and k, return the number of such arrangements. Since the answer may be large, 
# return it modulo 109 + 7.

from math import comb, perm
from functools import cache

M = 10 ** 9 + 7
class Solution:
    def rearrangeSticks(self, n: int, k: int) -> int:
        return self.dp(n, k)

    # consider the shortest
    @cache
    def dp(self, n, k):
        if n == k:
            return 1
        if n <= 0 or k <= 0:
            return 0
        return (self.dp(n - 1, k - 1) + (n - 1) * self.dp(n - 1, k)) % M  
# `dp(n, k)` indicates the number of arrangements of `n` distinct sticks with exactly `k` visible sticks. 
# Those `n` **distinct** sticks does NOT have to be numbered from `1` to `n` consecutively.


## Python Math Formula, no DP, 100% runtime
class Solution:
    def rearrangeSticks(self, n: int, k: int) -> int:
        MOD = 10 ** 9 + 7
        # Precalculate all necessary modular inverses and factorial inverses from 1 to 2 * n - k
        upper_bound_precalc = 2 * n - k + 2
        inverses = [1] * (upper_bound_precalc + 1)
        inverse_factorials = [1] * (upper_bound_precalc + 1)

        for a in range(2, upper_bound_precalc + 1):
            inverses[a] = MOD - MOD // a * inverses[MOD % a] % MOD
            inverse_factorials[a] = (inverses[a] * inverse_factorials[a - 1]) % MOD

        # Precompute exponents
        total = 0
        my_pow_list = [pow(j, n - k, MOD) for j in range(n - k + 1)]

        for i in range(n - k + 1):
            multiplier = (inverses[n + i] * inverse_factorials[n - k - i] * inverse_factorials[n - k + i]) % MOD
            add_here = 0

            # Follow the math formula
            for j in range(i + 1):
                if j % 2 == 0:
                    add_here += my_pow_list[j] * inverse_factorials[j] * inverse_factorials[i - j]
                else:
                    add_here -= my_pow_list[j] * inverse_factorials[j] * inverse_factorials[i - j]

            # Update the powers list
            my_pow_list = [(j * my_pow_list[j]) % MOD for j in range(n - k + 1)]

            total += multiplier * add_here % MOD

        # Multiply by factorials, and flip the sign of answer if n != k mod 2
        total %= MOD
        total *= pow(inverse_factorials[2 * n - k], -1, MOD) * inverse_factorials[k - 1] * ((-1) ** ((n - k) % 2))

        return total % MOD
    

## Using Fast fourier transform for polynomial multiplication in O(n log n) time
import numpy as np
from scipy.signal import convolve

class Solution:
    def rearrangeSticks(self, n: int, k: int) -> int:
        MOD = 10 ** 9 + 7
        
        # FFT multiply
        def multiply_2_polynomials(poly1, poly2):
            return convolve(poly1, poly2) % MOD

        def mult_poly_list(poly_list):
            if len(poly_list) == 1:
                return poly_list[0]

            if len(poly_list) == 2:
                return multiply_2_polynomials(poly_list[0], poly_list[1])

            return multiply_2_polynomials(mult_poly_list(poly_list[:len(poly_list) // 2]),
                                          mult_poly_list(poly_list[len(poly_list) // 2:]))

        # Generate all solutions for n: j=0,1,...n. Return coefficient at k
        def get_coeff(want_coeff):
            my_polys = []
            for x in range(n):
                my_polys.append(np.array([x, 1], dtype=object))

            return mult_poly_list(my_polys)[want_coeff]

        if n == k:
            return 1

        return get_coeff(k)
    