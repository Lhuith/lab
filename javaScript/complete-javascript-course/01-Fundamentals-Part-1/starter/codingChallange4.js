const bill = 275
const tip = (((bill >= 50 && bill <= 300) ? 15 : 20) / 100) * bill
console.log(`The bill was ${bill}, the tip was ${tip}, and the total value was ${bill + tip}`)