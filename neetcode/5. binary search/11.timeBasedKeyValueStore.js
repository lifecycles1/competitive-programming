// Design a time-based key-value data structure that can store multiple values for the same key at
// different time stamps and retrieve the key's value at a certain timestamp.

// Implement the TimeMap class:

// TimeMap() Initializes the object of the data structure.
// void set(String key, String value, int timestamp) Stores the key key with the value value at the
// given time timestamp.
// String get(String key, int timestamp) Returns a value such that set was called previously, with
// timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with
// the largest timestamp_prev. If there are no values, it returns "".

class TimeMap {
  constructor() {
    this.map = {};
  }

  set(key, value, timestamp) {
    const bucket = this.map[key] || [];
    this.map[key] = bucket;
    bucket.push([value, timestamp]);
  }

  get(key, timestamp, value = "", bucket = this.map[key] || []) {
    let [left, right] = [0, bucket.length - 1];

    while (left <= right) {
      const mid = (left + right) >> 1;
      const [guessValue, guessTimestamp] = bucket[mid];

      const isTargetGreater = guessTimestamp <= timestamp;
      if (isTargetGreater) {
        value = guessValue;
        left = mid + 1;
      }

      const isTargetLess = timestamp < guessTimestamp;
      if (isTargetLess) right = mid - 1;
    }

    return value;
  }
}
