// const Car = function (make, speed) {
//   this.make = make;
//   this.speed = speed;
// };

// Car.prototype.accelerate = function () {
//   this.speed += 10;
//   console.log(`${this.make} is going at ${this.speed}`);
// };
// Car.prototype.break = function () {
//   this.speed -= 5;
//   console.log(`${this.make} is going at ${this.speed}`);
// };

// const EV = function (make, speed, charge) {
//   Car.call(this, make, speed);
//   this.charge = charge;
// };

// EV.prototype = Object.create(Car.prototype);
// EV.prototype.chargeBattery = function (chargeTo) {
//   this.charge = chargeTo;
// };
// EV.prototype.accelerate = function () {
//   this.speed += 20;
//   this.charge -= 1;
//   console.log(
//     `${this.make} is going at ${this.speed}, with charge ${this.charge}`
//   );
// };

// const tesla = new EV('Tesla', 120, 23);
// console.log(tesla);
// tesla.accelerate();
// tesla.accelerate();
// tesla.accelerate();
// tesla.chargeBattery(100);
// tesla.accelerate();
// tesla.accelerate();
// tesla.accelerate();
// tesla.break();
// tesla.break();
// tesla.break();
// tesla.break();
// tesla.accelerate();
// // const bmw = new Car('BMW', 120);
// // bmw.accelerate();
// // bmw.accelerate();
// // bmw.accelerate();
// // bmw.break();
// // bmw.break();
// // bmw.break();
// // bmw.break();
// // bmw.break();
// // bmw.break();
// // const mercedes = new Car('Mercedes', 95);
// // mercedes.accelerate();
// // mercedes.accelerate();
// // mercedes.accelerate();
// // mercedes.accelerate();
// // mercedes.accelerate();
// // mercedes.accelerate();
// // mercedes.accelerate();
// // mercedes.accelerate();
// // mercedes.accelerate();
// // mercedes.accelerate();
// // mercedes.accelerate();
// // mercedes.accelerate();
// // mercedes.accelerate();

// // class Car {
// //   constructor(make, speed) {
// //     this.make = make;
// //     this.speed = speed;
// //   }
// //   accelerate() {
// //     this.speed += 10;
// //     console.log(`${this.make} is going at ${this.speed}`);
// //   }
// //   break() {
// //     this.speed -= 10;
// //     console.log(`${this.make} is going at ${this.speed}`);
// //   }
// //   get speedUS() {
// //     return this.speed / 1.6;
// //   }
// //   set speedUS(speed) {
// //     this.speed = speed * 1.6;
// //   }
// // }

// // const ford = new Car('Ford', 120);
// // console.log(ford.speedUS);
// // ford.accelerate();
// // console.log(ford.speedUS);
// // console.log(ford.speedUS);
// // ford.break();
// // ford.break();
// // console.log(ford.speedUS);
// // ford.break();
// // ford.break();
// // ford.accelerate();
// // ford.accelerate();
// // console.log(ford.speedUS);
// // ford.accelerate();
// // console.log(ford.speedUS);
// // ford.accelerate();
// // console.log(ford.speedUS);

class Car {
  constructor(make, speed) {
    this.make = make;
    this.speed = speed;
  }
  accelerate() {
    this.speed += 10;
    console.log(`${this.make} is going at ${this.speed}`);
  }
  break() {
    this.speed -= 10;
    console.log(`${this.make} is going at ${this.speed}`);
    return this;
  }
  get speedUS() {
    return this.speed / 1.6;
  }
  set speedUS(speed) {
    this.speed = speed * 1.6;
  }
}

class EV extends Car {
  #charge;
  constructor(make, speed, charge) {
    super(make, speed);
    this.#charge = charge;
  }
  chargeBattery(chargeTo) {
    this.#charge = chargeTo;
    return this;
  }
  accelerate() {
    this.speed += 20;
    this.#charge -= 1;
    console.log(
      `${this.make} is going at ${this.speed}, with charge ${this.#charge}`
    );
    return this;
  }
}

const rivian = new EV('rivian', 120, 23);
rivian
  .accelerate()
  .accelerate()
  .accelerate()
  .chargeBattery(100)
  .break()
  .accelerate();
