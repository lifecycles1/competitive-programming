// This principle states that a class should only have one responsibility.
// Furthermore, it should only have one reason to change.

// How does this principle help us to build better software? Let's see a few of its benefits:

// Testing – A class with one responsibility will have far fewer test cases.
// Lower coupling – Less functionality in a single class will have fewer dependencies.
// Organization – Smaller, well-organized classes are easier to search than monolithic ones.

class Book {
  constructor(name, author, text) {
    this.name = name;
    this.author = author;
    this.text = text;
  }

  replaceWordInText(word, replacementWord) {
    this.text = this.text.replaceAll(word, replacementWord);
  }

  isWordInText(word) {
    return this.text.includes(word);
  }
}

// violates the single responsibility principle by adding another responsibility to the class
class BadBook {
  //...
  printTextToConsole() {
    // ...
  }
}

// fix the problem by creating a new class
class BookPrinter {
  printTextToConsole() {
    //...
  }
  printTextToAnotherMedium() {
    //...
  }
}
