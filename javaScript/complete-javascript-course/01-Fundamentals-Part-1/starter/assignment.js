const country = 'Australia';
const continent = 'Australia'
let population = 25
language = 'English'

// // 01
// // console.log(country)
// // console.log(continent)
// // console.log(population)

// // 02
// const isIsLand = true;
// let language;
// console.log(isIsLand)
// console.log(population)
// console.log(country)
// console.log(language)

// console.log(population / 2)
// population++
// console.log(population)
// const finlandPopulation = 6
// console.log(population > finlandPopulation)
// const averagePopulation = 33
// console.log(population < averagePopulation)
// const description = country + " is in " + continent + ", and its " + population + " million people speak " + language
// console.log(description)

// // string template
// const description2 = `${country} is in ${continent}, and its ${population} million people speak ${language}`
// console.log(description2)

// // population = 13
// if (population > 33) {
//     console.log(`${country}'s population is above average`);
// } else {
//     console.log(`${country}'s population is below average`);
// }

// console.log('9' - '5')
// console.log('19' - '13' + '17')
// console.log('19' - '13' + 17)
// console.log('123' < 57)
// console.log(5 + 6 + '4' + 9 - 4 - 2)

// //const numNeighbors = Number(prompt('How many neighbor countries does your country have?'))

// // if (numNeighbors === 1) {
// //     console.log("Only 1 Border!")
// // } else if (numNeighbors > 1) {
// //     console.log("More than 1 border!")
// // } else {
// //     console.log("no borders!")
// // }

// // == type coersion aka, '1' == 1 is converted then checked
// // === '1' === 1 will be false as its strict with no conversion


// if (language === 'English' && population < 50 && !isIsLand) {
//     console.log(`Sarah should live in ${country}`)
// } else {
//     console.log(`${country} does not meet your criteria`)
// }

// switch (language.toLowerCase()) {
//     case 'chinese':
//     case 'mandarin':
//         console.log('Most number of native speaks!')
//         break;
//     case 'spanish':
//         console.log('2nd place in number of native')
//         break;
//     case 'english':
//         console.log('3rd place');
//         break;;
//     case 'hindi':
//         console.lo('No. 4!')
//         break;
// }

console.log(`${country}'s population is ${population > 33 ? 'above' : 'below'} average`)