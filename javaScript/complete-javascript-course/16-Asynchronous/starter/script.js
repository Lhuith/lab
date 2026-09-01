'use strict';

const btn = document.querySelector('.btn-country');
const countriesContainer = document.querySelector('.countries');

///////////////////////////////////////
// const getCountryData = function (country) {
//   const request = new XMLHttpRequest();
//   request.open('GET', `https://restcountries.com/v2/name/${country}`);
//   request.send();

//   request.addEventListener('load', function (e) {
//     const [data] = JSON.parse(this.responseText);
//     console.log(data);
//     const html = `
//            <article class="country">
//           <img class="country__img" src="${data.flag}" />
//           <div class="country__data">
//             <h3 class="country__name">${data.name}</h3>
//             <h4 class="country__region">${data.region}</h4>
//             <p class="country__row"><span>👫</span>${(
//               +data.population / 1000000
//             ).toFixed(1)}</p>
//             <p class="country__row"><span>🗣️</span>${data.languages[0].name}</p>
//             <p class="country__row"><span>💰</span>${
//               data.currencies[0].name
//             }</p>
//           </div>
//         </article>
//     `;
//     countriesContainer.insertAdjacentHTML('beforeend', html);
//     countriesContainer.style.opacity = 1;
//   });
// };

const renderCountry = function (data, className = '') {
  const html = `
           <article class="country ${className}">
          <img class="country__img" src="${data.flag}" />
          <div class="country__data">
            <h3 class="country__name">${data.name}</h3>
            <h4 class="country__region">${data.region}</h4>
            <p class="country__row"><span>👫</span>${(
              +data.population / 1000000
            ).toFixed(1)}</p>
            <p class="country__row"><span>🗣️</span>${data.languages[0].name}</p>
            <p class="country__row"><span>💰</span>${
              data.currencies[0].name
            }</p>
          </div>
        </article>
    `;
  countriesContainer.insertAdjacentHTML('beforeend', html);
  countriesContainer.style.opacity = 1;
};

const renderError = function (msg) {
  countriesContainer.insertAdjacentText('beforeend', msg);
  countriesContainer.style.opacity = 1;
};
/*
const getCountryAndNeighborData = function (country) {
  const request = new XMLHttpRequest();
  request.open('GET', `https://restcountries.com/v2/name/${country}`);
  request.send();

  request.addEventListener('load', function (e) {
    const [data] = JSON.parse(this.responseText);
    console.log(data);

    // render country one
    renderCountry(data);

    // get neighbor country
    const [neighbor] = data.borders;

    if (!neighbor) return;

    const request = new XMLHttpRequest();
    request.open('GET', `https://restcountries.com/v2/alpha/${neighbor}`);
    request.send();
    request.addEventListener('load', function (e) {
      const data2 = JSON.parse(this.responseText);
      renderCountry(data2, 'neighbour');
    });
  });
};

getCountryAndNeighborData('usa');

setTimeout(() => {
  console.log('1 second passed');
  setTimeout(() => {
    console.log('2 second passed');
    setTimeout(() => {
      console.log('3 second passed');
      setTimeout(() => {
        console.log('4 second passed');
      }, 1000);
    }, 1000);
  }, 1000);
}, 1000);



//   const request = new XMLHttpRequest();
//   request.open('GET', `https://restcountries.com/v2/name/${country}`);
//   request.send();

// const request = fetch('https://restcountries.com/v2/name/australia');
// console.log(request);

// const getCountryData = function (country) {
//   // country 1
//   fetch(`https://restcountries.com/v2/name/${country}`)
//     .then(response => {
//       console.log(response);
//     })
//     .then(data => {
//       renderCountry(data[0]);
//       // const neighbor = data[0].borders[0];
//       const neighbor = '3asdasd';
//       if (!neighbor) return;
//       // country 2
//       return fetch(`https://restcountries.com/v2/alpha/${neighbor}`);
//     })
//     .then(response => {
//       if (!response.ok) {
//         throw new Error(`Country not found (${response.status})`);
//       }
//       return response.json();
//     })
//     .then(data => renderCountry(data, 'neighbour'))
//     .catch(err => {
//       console.error(`${err} 🧨🧨🧨🧨`);
//       renderError(`Something went wrong [${err.message}] 🧨🧨🧨🧨`);
//     })
//     .finally(() => {
//       countriesContainer.style.opacity = 1;
//     });
// };
// btn.addEventListener('click', function () {
//   getCountryData('usa');
// });

const getJSON = function (url, errMessage = 'Something went wrong') {
  return fetch(url).then(response => {
    if (!response.ok) {
      throw new Error(`${errMessage} (${response.status})`);
    }
    return response.json();
  });
};

const getCountryData = function (country) {
  // country 1
  getJSON(`https://restcountries.com/v2/name/${country}`, `Country not found`)
    .then(data => {
      renderCountry(data[0]);

      const neighbor = data[0]?.borders;

      if (!neighbor) throw new Error('No new neighbour found');
      //// country 2
      return getJSON(
        `https://restcountries.com/v2/alpha/${neighbor[0]}`,
        `Country not found`
      );
    })
    .then(data => renderCountry(data, 'neighbour'))
    .catch(err => {
      console.error(`${err} 🧨🧨🧨🧨`);
      renderError(`Something went wrong [${err.message}]`);
    })
    .finally(() => {
      countriesContainer.style.opacity = 1;
    });
};
getCountryData('australia');


const lotteryPromise = new Promise(function (resolve, reject) {
  console.log(`lottery draw is happening 🔮`);
  if (Math.random() >= 0.5) {
    resolve(`You WIN 💰`);
  } else {
    reject(new Error(`You lost your money 💩`));
  }
});

lotteryPromise.then(res => console.log(res)).catch(err => console.error(err));



wait(2)
  .then(() => {
    console.log('waited for 1 seconds');
    return wait(1);
  })
  .then(() => {
    console.log('waited for 2 seconds');
    return wait(1);
  })
  .then(() => {
    console.log('waited for 3 seconds');
    return wait(1);
  })
  .then(() => {
    console.log('waited for 4 seconds');
    return wait(1);
  });

// setTimeout(() => {
//   console.log('1 second passed');
//   setTimeout(() => {
//     console.log('2 second passed');
//     setTimeout(() => {
//       console.log('3 second passed');
//       setTimeout(() => {
//         console.log('4 second passed');
//       }, 1000);
//     }, 1000);
//   }, 1000);
// }, 1000);

Promise.resolve('abc').then(x => console.log(x));
Promise.reject(new Error('abc')).catch(err => console.error(err));


const getPosition = function () {
  return new Promise(function (resolve, reject) {
    // navigator.geolocation.getCurrentPosition(
    //   position => resolve(position),
    //   err => reject(err)
    // );
    navigator.geolocation.getCurrentPosition(resolve, reject);
  });
};

getPosition()
  .then(pos => console.log(pos))
  .catch(err => console.log(err));

const whereAmI = function () {
  getPosition()
    .then(pos => {
      const { latitude: lat, longitude: lng } = pos.coords;
      return fetch(
        ` https://geocode.xyz/${lat},${lng}?geoit=json&auth=800751993944206670415x53417`
      );
    })
    .then(res => {
      if (!res.ok)
        throw new Error(`something went wrong there buddy ${res.status}!`);
      return res.json();
    })
    .then(data => {
      console.log(data);
      console.log(
        `your are in ${data.city[0] + data.city.toLowerCase().slice(1)}, ${
          data.country
        }`
      );
      return fetch(`https://restcountries.com/v2/name/${data.country}`);
    })
    .then(res => {
      if (!res.ok) {
        throw new Error(`${errMessage} (${res.status})`);
      }
      return res.json();
    })
    .then(data => {
      const country = data[0];
      const html = `
           <article class="country">
          <img class="country__img" src="${country.flag}" />
          <div class="country__data">
            <h3 class="country__name">${country.name}</h3>
            <h4 class="country__region">${country.region}</h4>
            <p class="country__row"><span>👫</span>${(
              +country.population / 1000000
            ).toFixed(1)}</p>
            <p class="country__row"><span>🗣️</span>${
              country.languages[0].name
            }</p>
            <p class="country__row"><span>💰</span>${
              country.currencies[0].name
            }</p>
          </div>
        </article>
    `;
      countriesContainer.insertAdjacentHTML('beforeend', html);
    })
    .catch(err => {
      console.error(err);
    })
    .finally(() => {
      countriesContainer.style.opacity = 1;
    });
};

btn.addEventListener('click', whereAmI);


const getPosition = function () {
  return new Promise(function (resolve, reject) {
    navigator.geolocation.getCurrentPosition(resolve, reject);
  });
};

const whereAmI = async function () {
  try {
    const pos = await getPosition();
    const { latitude: lat, longitude: lng } = pos.coords;

    const resGeo = await fetch(
      ` https://geocode.xyz/${lat},${lng}?geoit=json&auth=800751993944206670415x53417`
    );

    if (!resGeo.ok) throw new Error(`Problem getting location data`);

    const dataGeo = await resGeo.json();

    const res = await fetch(
      `https://restcountries.com/v2/name/${dataGeo.country}`
    );

    if (!res.ok) throw new Error(`Problem getting country`);

    const data = await res.json();
    renderCountry(data[0]);

    return `You are in ${dataGeo.city}, ${dataGeo.country}`;
  } catch (e) {
    renderError(`${e}`);
    throw e;
  }
};

console.log('get location');
// const city = whereAmI();
// console.log(city);
// whereAmI()
//   .then(city => console.log(city))
//   .catch(e => console.error(e))
//   .finally(() => {
//     console.log('finished getting location');
//   });

(async function () {
  try {
    const city = await whereAmI();
    console.log(city);
  } catch (e) {
    console.error(e);
  }
  console.log('finished getting location');
})();
// try {
//   let y = 1;
//   const x = 2;
//   x = 3;
// } catch (e) {
//   alert(e);
// }



const getJSON = function (url, errMessage = 'Something went wrong') {
  return fetch(url).then(response => {
    if (!response.ok) {
      throw new Error(`${errMessage} (${response.status})`);
    }
    return response.json();
  });
};

const get3Countries = async function (c1, c2, c3) {
  try {
    const data = await Promise.all([
      await getJSON(`https://restcountries.com/v2/name/${c1}`),
      await getJSON(`https://restcountries.com/v2/name/${c2}`),
      await getJSON(`https://restcountries.com/v2/name/${c3}`),
    ]);

    console.log(data.map(d => d[0].capital));
  } catch (e) {
    console.error(e);
  }
};

get3Countries('australia', 'usa', 'japan');

(async function () {
  const res = await Promise.race([
    await getJSON(`https://restcountries.com/v2/name/mexico`),
    await getJSON(`https://restcountries.com/v2/name/spain`),
    await getJSON(`https://restcountries.com/v2/name/germany`),
  ]);
  console.log(res[0]);
})();

const timeout = function (s) {
  return new Promise(function (_, reject) {
    setTimeout(function () {
      reject(new Error(`Request took to long`));
    }, s * 1000);
  });
};

Promise.race([
  getJSON(`https://restcountries.com/v2/name/mexico`),
  timeout(0.1),
])
  .then(res => console.log(res[0]))
  .catch(e => console.error(e));

Promise.allSettled([
  Promise.resolve('Success'),
  Promise.reject('failed'),
  Promise.reject('so fail'),
]).then(res => console.log(res));

Promise.all([
  Promise.resolve('Success'),
  Promise.reject('failed'),
  Promise.reject('so fail'),
])
  .then(res => console.log(res))
  .catch(e => console.error(e));

Promise.any([
  Promise.reject('failed'),
  Promise.reject('so fail'),
  Promise.resolve('Success from any'),
  Promise.resolve('Success from any'),
])
  .then(res => console.log(res))
  .catch(e => console.error(e));
*/
