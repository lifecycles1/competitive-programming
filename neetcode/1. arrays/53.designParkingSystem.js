// 1603. Design Parking System

// Design a parking system for a parking lot. The parking lot has three kinds of parking spaces:
// big, medium, and small, with a fixed number of slots for each size.

// Implement the ParkingSystem class:
// ParkingSystem(int big, int medium, int small) Initializes object of the ParkingSystem class.
// The number of slots for each parking space are given as part of the constructor.
// bool addCar(int carType) Checks whether there is a parking space of carType for the car that
// wants to get into the parking lot. carType can be of three kinds: big, medium, or small,
// which are represented by 1, 2, and 3 respectively. A car can only park in a parking space of its
// carType. If there is no space available, return false, else park the car in that size space and return true.

// Example 1:
// Input
// ["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
// [[1, 1, 0], [1], [2], [3], [1]]
// Output
// [null, true, true, false, false]

// Explanation
// ParkingSystem parkingSystem = new ParkingSystem(1, 1, 0);
// parkingSystem.addCar(1); // return true because there is 1 available slot for a big car
// parkingSystem.addCar(2); // return true because there is 1 available slot for a medium car
// parkingSystem.addCar(3); // return false because there is no available slot for a small car
// parkingSystem.addCar(1); // return false because there is no available slot for a big car. It is already occupied.

/**
 * @param {number} big
 * @param {number} medium
 * @param {number} small
 */
var ParkingSystem = function (big, medium, small) {
  this.empty = [big, medium, small];
};

/**
 * @param {number} carType
 * @return {boolean}
 */
ParkingSystem.prototype.addCar = function (carType) {
  if (this.empty[carType - 1] > 0) {
    this.empty[carType - 1]--;
    return true;
  }
  return false;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * var obj = new ParkingSystem(big, medium, small)
 * var param_1 = obj.addCar(carType)
 */

class ParkingSystem {
  constructor(big, medium, small) {
    // Initialize the number of slots for each parking space type
    this.slots = [big, medium, small];
  }

  addCar(carType) {
    // carType is 1, 2, or 3 corresponding to big, medium, and small
    // Array index should be 0, 1, or 2, so subtract 1 from carType
    if (this.slots[carType - 1] > 0) {
      this.slots[carType - 1]--; // Decrement the count of available slots
      return true; // Successfully parked the car
    } else {
      return false; // No available slot for this car type
    }
  }
}

// Example usage:
const parkingSystem = new ParkingSystem(1, 1, 0);
console.log(parkingSystem.addCar(1)); // true (1 big slot available)
console.log(parkingSystem.addCar(2)); // true (1 medium slot available)
console.log(parkingSystem.addCar(3)); // false (no small slot available)
console.log(parkingSystem.addCar(1)); // false (no big slot available, it is already occupied)
