// Simply put, classes should be open for extension but closed for modification.
// In doing so, we stop ourselves from modifying existing code and causing potential
// new bugs in an otherwise happy application.

// Of course, the one exception to the rule is when fixing bugs in existing code.

class Guitar {
  constructor(make, model, volume) {
    this.make = make;
    this.model = model;
    this.volume = volume;
  }
}

// let's stick to the open-closed principle and simply extend our Guitar class:
class SuperCoolGuitarWithFlames extends Guitar {
  constructor(make, model, volume, flames) {
    super(make, model, volume);
    this.flames = flames;
  }
}
