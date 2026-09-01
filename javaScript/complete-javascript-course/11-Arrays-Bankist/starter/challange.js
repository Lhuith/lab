// 'use strict';

// const bankDepositSum = accounts
//   .flatMap(acc => acc.movements)
//   .filter(mov => mov > 0)
//   .reduce((sum, cur) => sum + cur, 0);
// console.log(bankDepositSum);

// // const numDeposits1000 = accounts
// //   .flatMap(acc => acc.movements)
// //   .filter(mov => mov >= 1000).length;
// // console.log(numDeposits1000);

// const numDeposits1000 = accounts
//   .flatMap(acc => acc.movements)
//   .reduce((acc, cur) => {
//     return cur >= 1000 ? ++acc : acc;
//   }, 0);
// console.log(numDeposits1000);

// let a = 10;
// console.log(++a);
// console.log(a);

// const { deposits, withdrawals } = accounts
//   .flatMap(acc => acc.movements)
//   .reduce(
//     (sums, cur) => {
//       //   cur > 0 ? (sum.deposits += cur) : (sum.withdrawals += cur);
//       sums[cur > 0 ? 'deposits' : 'withdrawals'] += cur;
//       return sums;
//     },
//     { deposits: 0, withdrawals: 0 }
//   );
// console.log(deposits, withdrawals);

// const convertTitleCase = function (title) {
//   const capitalize = str => str[0].toUpperCase() + str.slice(1);

//   const expectations = [
//     'a',
//     'an',
//     'the',
//     'and',
//     'but',
//     'or',
//     'on',
//     'in',
//     'with',
//   ];

//   const titleCase = title
//     .toLowerCase()
//     .split(' ')
//     .map(word => (expectations.includes(word) ? word : capitalize(word)))
//     .join(' ');

//   return capitalize(titleCase);
// };
// console.log(convertTitleCase('this is a nice title'));
// console.log(convertTitleCase('this is a LONG title but not too long'));
// console.log(convertTitleCase('and this is another title with an EXAMPLE'));

// const checkDogs = function (dogsJulia, dogsKate) {
//   const juliaDogsCorrected = dogsJulia.slice(1, -2);
//   const dogs = [...juliaDogsCorrected, ...dogsKate];
//   dogs.forEach(function (val, i) {
//     console.log(
//       `Dog number ${i + 1} is ${
//         val < 3 ? 'still a puppy 🐶' : `an adult, and is ${val} years old`
//       }`
//     );
//   });
// };

// checkDogs([3, 5, 2, 12, 7], [4, 1, 15, 8, 3]);
// console.log('--- TEST 2 ---');
// checkDogs([9, 16, 6, 8, 3], [10, 5, 6, 1, 4]);

// const calcAverageHumanAge = ages =>
//   ages
//     .map(age => (age <= 2 ? age * 2 : 16 + age * 4))
//     .filter(age => age > 18)
//     .reduce((acc, age, i, arr) => acc + age / arr.length, 0);

// console.log(calcAverageHumanAge([5, 2, 4, 1, 15, 8, 3]));
// console.log(calcAverageHumanAge([16, 6, 10, 5, 6, 1, 4]));

// const dogs = [
//   { weight: 22, curFood: 250, owners: ['Alice', 'Bob'] },
//   { weight: 8, curFood: 200, owners: ['Matilda'] },
//   { weight: 13, curFood: 275, owners: ['Sarah', 'John'] },
//   { weight: 32, curFood: 340, owners: ['Michael'] },
// ];

// dogs.forEach(function (dog) {
//   dog.recommendedFood = Math.trunc(dog.weight ** 0.75 * 28);
// });
// console.log(dogs);

// const sarahDog = dogs.find(dog => dog.owners.includes('Sarah'));
// console.log(
//   `Sarah's dog is eating too ${
//     sarahDog.curFood > sarahDog.recommendedFood ? 'much' : 'little'
//   }`
// );
// if (
//   sarahDog.curFood > sarahDog.recommendedFood * 0.9 &&
//   sarahDog.curFood < sarahDog.recommendedFood * 1.1
// ) {
//   console.log(`Sarah's dogs is in the good range`);
// } else if (sarahDog.curFood > sarahDog.recommendedFood) {
//   console.log(`Sarah's dogs eating more then recommended`);
// } else if (sarahDog.curFood < sarahDog.recommendedFood) {
//   console.log(`Sarah's dogs is NOT in the recommended range!`);
// }

// const ownersEatTooMuch = dogs
//   .filter(dog => dog.curFood > dog.recommendedFood)
//   .flatMap(dog => dog.owners);
// const ownersEatTooLittle = dogs
//   .filter(dog => dog.curFood < dog.recommendedFood)
//   .flatMap(dog => dog.owners);

// console.log(`${ownersEatTooMuch.join(' and ')}'s dog eats too much!`);
// console.log(`${ownersEatTooLittle.join(' and ')}'s dog eats too little!`);

// console.log(dogs.some(dog => dog.curFood === dog.recommendedFood));

// const eatingOk = dog =>
//   dog.curFood > dog.recommendedFood * 0.9 &&
//   dog.curFood < dog.recommendedFood * 1.1;
// console.log(dogs.some(eatingOk));

// const okayDogs = dogs.filter(eatingOk);
// console.log(okayDogs);

// const sortedDogs = dogs
//   .slice()
//   .sort((a, b) => a.recommendedFood - b.recommendedFood);
// console.log(sortedDogs);
