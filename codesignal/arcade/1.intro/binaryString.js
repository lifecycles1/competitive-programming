// convert a binary string to an ASCII string (8 bits per character)

// each consecutive 8 bits of the code stand for the character with the corresponding extended ASCII code.

// Example

// input = "0100100001100101011011000110110001101111001000000101011101101111011100100110110001100100"

// output = "Hello World"

// JavaScript solution 1

function solution(code) {
  let asciiString = "";

  for (let i = 0; i < code.length; i += 8) {
    let byte = code.substring(i, i + 8);
    let ascii = String.fromCharCode(parseInt(byte, 2));
    asciiString += ascii;
  }

  return asciiString;
}

// JavaScript solution 2

function solution(code) {
  let binaryArray = new Uint8Array(code.length / 8);

  for (let i = 0; i < code.length / 8; i++) {
    binaryArray[i] = parseInt(code.substr(i * 8, 8), 2);
  }
  let asciiString = new TextDecoder("ascii").decode(binaryArray);

  return asciiString;
}
