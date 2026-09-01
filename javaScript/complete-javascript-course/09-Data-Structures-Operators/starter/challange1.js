'use strict';

// const textArea = document.createElement('textarea');
// document.body.append(textArea);
// const button = document.createElement('button');
// document.body.append(button);

// button.addEventListener('click', function () {
//   const splitText = textArea.value.split('\n');

//   for (const [i, text] of splitText.entries()) {
//     const [first, second] = text.toLowerCase().trim().split('_');
//     //let [a, ...others] = second;
//     // console.log(
//     // `${(first + a.toUpperCase() + others.join('')).padEnd(20)} ${'✅'.repeat(
//     //     i + 1
//     //   )}`
//     // );
//     console.log(
//       `${(first + second.replace(second[0], second[0].toUpperCase())).padEnd(
//         20
//       )} ${'✅'.repeat(i + 1)}`
//     );
//   }
// });

const gameEvents = new Map([
  [17, '⚽ GOAL'],
  [36, '🔁 Substitution'],
  [47, '⚽ GOAL'],
  [61, '🔁 Substitution'],
  [64, '🔶 Yellow card'],
  [69, '🔴 Red card'],
  [70, '🔁 Substitution'],
  [72, '🔁 Substitution'],
  [76, '⚽ GOAL'],
  [80, '⚽ GOAL'],
  [92, '🔶 Yellow card'],
]);

// const events = [...new Set(gameEvents.values())];
// console.log(events);
// gameEvents.delete(64);
// console.log(gameEvents);

// const time = [...gameEvents.keys()].pop();
// // console.log(90 / time);
// console.log(
//   `An event happened, on average, every ${time / gameEvents.size} minutes`
// );

// for (const [time, event] of gameEvents) {
//   console.log(
//     `[${time <= 45 ? 'FIRST HALF' : 'SECOND HALF'}] ${time}: ${event}`
//   );
// }

const game = {
  team1: 'Bayern Munich',
  team2: 'Borrussia Dortmund',
  players: [
    [
      'Neuer',
      'Pavard',
      'Martinez',
      'Alaba',
      'Davies',
      'Kimmich',
      'Goretzka',
      'Coman',
      'Muller',
      'Gnarby',
      'Lewandowski',
    ],
    [
      'Burki',
      'Schulz',
      'Hummels',
      'Akanji',
      'Hakimi',
      'Weigl',
      'Witsel',
      'Hazard',
      'Brandt',
      'Sancho',
      'Gotze',
    ],
  ],
  score: '4:0',
  scored: ['Lewandowski', 'Gnarby', 'Lewandowski', 'Hummels'],
  date: 'Nov 9th, 2037',
  odds: {
    team1: 1.33,
    x: 3.25,
    team2: 6.5,
  },
};

/*
for (const [goal, player] of game.scored.entries()) {
  console.log(`Goal ${goal + 1}: ${player}`);
}

const scorers = {};
for (const player of game.scored) {
  scorers[player] ? (scorers[player] += 1) : (scorers[player] = 1);
}
console.log(scorers);

let totalOdds = 0;
for (const odds of Object.values(game.odds)) {
  totalOdds += odds;
}
totalOdds /= Object.entries(game.odds).length;
console.log(totalOdds);

for (const [team, odd] of Object.entries(game.odds)) {
  const teamName = game[team];
  console.log(`Odd of ${teamName ? 'victory ' + teamName : 'draw'}: ${odd}`);
}

const {
  team1,
  odds: { team1: team1Odds },
} = game;

const {
  team2,
  odds: { team2: team2Odds },
} = game;

const {
  odds: { x: drawOdds },
} = game;

console.log(`Odd of Victory ${team1}: ${team1Odds}`);
console.log(`Odd of draw: ${drawOdds}`);
console.log(`Odd of Victory ${team2}: ${team2Odds}`);
*/

/*
const [players1, players2] = game.players;
console.log(players1, players2);

const [gk, ...fieldPlayers] = players1;
console.log(gk, fieldPlayers);

const allPlayers = [...players1, ...players2];
console.log(allPlayers);

const players1Final = [...players1, 'Thaigo', 'Coutinho', 'Periscic'];
console.log(players1Final);

//const { team1, x: draw, team2 } = game.odds;
const {
  odds: { team1, x: draw, team2 },
} = game;
console.log(team1, draw, team2);

const printGaols = function (...players) {
  for (let i = 0; i < players.length; i++) {
    console.log(players[i]);
  }
  console.log(`${players.length} goals scored`);
};

printGaols('Davies', 'Muller', 'Lewandowski', 'Kimmich');
printGaols(...game.scored);

// || short circuits on first false
// && short circuits on first true

team1 < team2 && console.log('Team 1 is more likely to win');
team1 > team2 && console.log('Team 2 is more likely to win');
console.log(team1 || team2);

let obj = {};
console.log(obj?.a);
*/
