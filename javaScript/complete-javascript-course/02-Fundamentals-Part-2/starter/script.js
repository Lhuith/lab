'use strict'; // this is gooooood

/*

let hasDriversLicense = false;
const passTest = true;

if (passTest) hasDriversLicense = true;
if (hasDriversLicense) console.log(`I can drive 😀`);

//const interface = 'Audio';
//const private = 543;
// const if = // can't do

function logger() {
    console.log('My name is jonas')
}

// calling / running / invoking
logger();
logger();
logger();

function fruitProcessor(apples, oranges) {
    const juice = `Juice with ${apples} apples and ${oranges} oranges`;
    return juice;
}

const appleJuice = fruitProcessor(5, 0);
console.log(appleJuice);

const appleOrangeJuice = fruitProcessor(2, 4);
console.log(appleOrangeJuice);

const num = Number('23') // <--- function 

// function deceleration
function calcAge1(birthYear) {
    return 2037 - birthYear;
}

const age1 = calcAge1(1991);
console.log(age1);

// function expression
const calcAge2 = function (birthYear) {
    return 2037 - birthYear;
}

const age2 = calcAge2(1991);
console.log(age2);

// Arrow function
const calcAge3 = birthYear => 2037 - birthYear;
const age3 = calcAge3(1991);
console.log(age3);

const yearsUntilRetirement = (birthYear, firstName) => {
    const age = 2037 - birthYear;
    const retirement = 65 - age;
    return `${firstName} retires in ${retirement} years`;
}

console.log(yearsUntilRetirement(1991, 'Jonas'));
console.log(yearsUntilRetirement(1980, 'Bob'));

function cutFruitPieces(fruit) {
    return fruit * 4
}

function fruitProcessor(apples, oranges) {
    const applePieces = cutFruitPieces(apples);
    const orangePieces = cutFruitPieces(oranges);

    const juice = `Juice with ${applePieces} apple pieces and ${orangePieces} orange pieces`;
    return juice;
}

console.log(fruitProcessor(2, 3));


const calcAge = function (birthYear) {
    return 2037 - birthYear
}

const yearsUntilRetirement = function (birthYear, firstName) {
    const age = calcAge(birthYear);
    const retirement = 65 - age;

    if (retirement > 0) {
        console.log(`${firstName} retires in ${retirement} years`);
        return retirement;
    } else {
        console.log(`${firstName} already retired 🎉`);
        return -1;
    }
    // return 
}

console.log(yearsUntilRetirement(1991, 'Jonas'))
console.log(yearsUntilRetirement(1950, 'Mike'));

const friend1 = 'Micheal';
const friend2 = 'Steven';
const friend3 = 'Peter';

const friends = ['Micheal', 'Steven', 'Peter']
console.log(friends);

// const years = new Array(1991, 1984, 2008, 2020);

console.log(friends[0]);
console.log(friends[2]);
console.log(friends.length);
console.log(friends[friends.length - 1]);

friends[2] = 'Jay';
console.log(friends);
// friends = ['Bob', 'Alice'] // can't do this!

const firstName = 'Jonas';
const jonas = [firstName, 'Schedtmann', 2037 - 1991, 'teacher', friends]
console.log(jonas);

// Excercise
const calcAge = function (birthYear) {
    return 2037 - birthYear;
}
const years = [1990, 1967, 2002, 2010, 2018];

const age1 = calcAge(years[0]);
const age2 = calcAge(years[1]);
const age3 = calcAge(years[years.length - 1]);
console.log(age1, age2, age3);

const ages = [calcAge(years[0]), calcAge(years[1]), calcAge(years[years.length - 1])]
console.log(ages)

const friends = ['Micheal', 'Steven', 'Peter']

// add elements
const newLength = friends.push('Jay');
console.log(friends);
console.log(newLength);

friends.unshift('John')
console.log(friends);

// remove elements
friends.pop();
const popped = friends.pop();
console.log(popped);
console.log(friends);

friends.shift();
console.log(friends);

console.log(friends.indexOf('Steven'));
console.log(friends.indexOf('Bob'));

friends.push(23)
console.log(friends.includes('Steven'));
console.log(friends.includes('Bob'));
console.log(friends.includes('23'));

friends.push('Peter')
if (friends.includes('Peter')) {
    console.log('You have a friend called Peter!')
} else {
    console.log('No friend called Peter :(')
}


const jonasArray = [
    'Jonas',
    'Schmedtmann',
    2037 - 1991,
    'teacher',
    ['Micheal', 'Peter', 'Steven']
]

const jonas = {
    firstName: 'Jonas',
    lastName: 'Schmedtmann',
    age: 2037 - 1991,
    job: 'teacher',
    friends: ['Micheal', 'Peter', 'Steven'],
}

const jonas = {
    firstName: 'Jonas',
    lastName: 'Schmedtmann',
    age: 2037 - 1991,
    job: 'teacher',
    friends: ['Micheal', 'Peter', 'Steven'],
}
console.log(jonas)

console.log(jonas.lastName);
console.log(jonas['lastName']) // good expressions

const nameKey = 'Name'
console.log(jonas['first' + nameKey])
console.log(jonas['last' + nameKey])

// console.log(jonas.'first'+  nameKey) // nope

const interestedIn = prompt('What do you what know about jonas? Choose between firstName, lastName, age, job and friends')

if (jonas[interestedIn]) {
    console.log(jonas[interestedIn]);
} else {
    console.log('Wrong request!')
}

jonas.location = 'Portugal'
jonas['twitter'] = '@jonasschmdman'
console.log(jonas)

console.log(`${jonas.firstName} has ${jonas.friends.length} friends, and his best friends is called ${jonas.friends[0]}`)

const jonas = {
    firstName: 'Jonas',
    lastName: 'Schmedtmann',
    birthYear: 1991,
    job: 'teacher',
    friends: ['Micheal', 'Peter', 'Steven'],
    hasDriversLicense: true,

    // calcAge: function () {
    //     return 2037 - this.birthYear
    // }
    calcAge: function () {
        this.age = 2037 - this.birthYear;
        return this.age;
    },
    getSummary: function () {
        return `${this.firstName} is a ${this.calcAge()} year old ${this.job}, and he has ${this.hasDriversLicense ? 'a' : 'no'} driver's license`
    }
};

console.log(jonas.calcAge());
console.log(jonas.age);
console.log(jonas.age);
console.log(jonas.age);
console.log(jonas.getSummary())

// console.log('Lifting wights repetition 1 🏋️‍♀️')
// console.log('Lifting wights repetition 2 🏋️‍♀️')
// console.log('Lifting wights repetition 3 🏋️‍♀️')
// console.log('Lifting wights repetition 4 🏋️‍♀️')
// console.log('Lifting wights repetition 5 🏋️‍♀️')
// console.log('Lifting wights repetition 6 🏋️‍♀️')
// console.log('Lifting wights repetition 7 🏋️‍♀️')
// console.log('Lifting wights repetition 8 🏋️‍♀️')
// console.log('Lifting wights repetition 9 🏋️‍♀️')
// console.log('Lifting wights repetition 10 🏋️‍♀️')

for (let rep = 1; rep <= 10; rep++) {
    console.log(`Lifting wights repetition ${rep} 🏋️‍♀️`)
}

const jonasArray = [
    'Jonas',
    'Schmedtmann',
    2037 - 1991,
    'teacher',
    ['Micheal', 'Peter', 'Steven'],
    true
];
const types = [];

for (let i = 0; i < jonasArray.length; i++) {
    // reading
    console.log(jonasArray[i], typeof jonasArray[i])


    // types[i] = typeof jonasArray[i]
    types.push(typeof jonasArray[i])
    // types.unshift(typeof jonasArray[i])
}
console.log(types)

const years = [1991, 2007, 1969, 2020];
const ages = [];

for (let i = 0; i < years.length; i++) {
    ages.push(2037 - years[i])
}

console.log(ages)

// continue and break
console.log('--- only strings ---')
for (let i = 0; i < jonasArray.length; i++) {
    if (typeof jonasArray[i] !== 'string') continue;
    console.log(jonasArray[i], typeof jonasArray[i])
}
console.log('--- only 1 number ---')
for (let i = 0; i < jonasArray.length; i++) {
    if (typeof jonasArray[i] === 'number') break;
    console.log(jonasArray[i], typeof jonasArray[i])
}


const jonas = [
    'Jonas',
    'Schmedtmann',
    2037 - 1991,
    'teacher',
    ['Micheal', 'Peter', 'Steven'],
    true,
];

for (let i = jonas.length - 1; i >= 0; i--) {
    console.log(i, jonas[i])
}

for (let exercise = 1; exercise < 4; exercise++) {
    console.log(`------ Starting exercise ${exercise}`)

    for (let rep = 1; rep < 6; rep++) {
        console.log(`Exercise ${exercise}: lifting weight repetition ${rep} 🏋️‍♀️`)
    }
}
    
    // for (let rep = 1; rep <= 10; rep++) {
        //     console.log(`Lifting wights repetition ${rep} 🏋️‍♀️`)
        // }

let rep = 1;
while (rep <= 10) {
    console.log(`Lifting wights repetition ${rep} 🏋️‍♀️`);
    rep++;
}

let dice = Math.trunc(Math.random() * 6) + 1

while (dice !== 6) {
    console.log(`your rolled a ${dice}`)
    dice = Math.trunc(Math.random() * 6) + 1
    if (dice === 6) {
        console.log(`loop is about to end`)
    }
}

*/

