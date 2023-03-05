// find the simplified ratio of a numerator and denominator:

function solution(numerator, denominator) {
  // gcd is a helper function that finds the greatest common divisor of two numbers using the Euclidean algorithm.
  const gcd = (a, b) => (b ? gcd(b, a % b) : a);
  const a = Math.abs(numerator);
  const b = Math.abs(denominator);
  const g = gcd(a, b);

  return [(numerator / denominator < 0 ? -a : a) / g, b / g];
}
