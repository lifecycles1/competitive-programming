// We are playing the Guess Game. The game is as follows:

// I pick a number from 1 to n. You have to guess which number I picked.

// Every time you guess wrong, I will tell you whether the number 
// I picked is higher or lower than your guess.

// You call a pre-defined API int guess(int num), which returns three possible results:

// -1: Your guess is higher than the number I picked (i.e. num > pick).
// 1: Your guess is lower than the number I picked (i.e. num < pick).
// 0: your guess is equal to the number I picked (i.e. num == pick).
// Return the number that I picked.

class Solution {
public:
  int guessNumber(int n) {
    int low = 1;
    int high = n;

    while (true) {
      int mid = low + (high - low) / 2;
      int myGuess = guess(mid);
      if (myGuess == 1) {
        low = mid + 1;
      } else if (myGuess == -1) {
        high = mid - 1;
      } else {
        return mid;
      }
    }
  }
};