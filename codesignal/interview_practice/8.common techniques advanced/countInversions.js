function solution(a) {
  //Exploiting constraint(Thank to @zero_cool for this approach)
  const MOD = 1e9 + 7;
  let total = 0,
    min = Infinity,
    max = -Infinity;
  a.forEach((v) => {
    min = Math.min(min, v);
    max = Math.max(max, v);
  });
  let dp = new Array(max - min + 1).fill(0);
  a.forEach((v) => {
    for (let i = 0; i < v - min; i++) dp[i]++;
    total = (total + dp[v - min]) % MOD;
  });
  return total;
}

// Using merge sort

// function solution(a) {
//   let total = 0;
//   const MOD = 1e9 + 7;
//   function merge(left, right, middle) {
//     let i,
//       j,
//       part = [];
//     for (i = left, j = middle; i < middle && j < right; ) {
//       if (a[i] <= a[j]) part.push(a[i++]);
//       else {
//         total += (middle - i) % MOD;
//         part.push(a[j++]);
//       }
//     }
//     while (i < middle) part.push(a[i++]);
//     while (j < right) part.push(a[j++]);
//     for (i = left; i < right; i++) a[i] = part[i - left];
//   }

//   function split(left, right) {
//     const middle = (left + right) >> 1;
//     if (left + 1 === right) return;
//     split(left, middle);
//     split(middle, right);
//     merge(left, right, middle);
//   }
//   split(0, a.length);
//   return total % MOD;
// }
