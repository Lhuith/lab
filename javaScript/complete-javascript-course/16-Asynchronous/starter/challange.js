'use strict';
/*
const whereAmI = function (lat, lng) {
  fetch(
    ` https://geocode.xyz/${lat},${lng}?geoit=json&auth=800751993944206670415x53417`
  )
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

whereAmI(52.508, 13.381);
whereAmI(19.037, 72.873);
whereAmI(-33.933, 18.474);


console.log('test start');
setTimeout(() => console.log('0 sec timer'), 0);
setTimeout(() => console.log('1 sec timer'), 1);
Promise.resolve('Resolved promise 1').then(res => console.log(res));
const syncy = async function () {
  await setTimeout(() => console.log('syncy timeout?'), 1);
};
syncy();
Promise.resolve('Resolve promise 2').then(res => {
  for (let i = 0; i < 1000000000; i++) {}
  console.log(res);
});

console.log('test end');





createImage('img/img-1.jpg')
  .then(img => {
    console.log('image 1 loaded');
    currentImg = img;
    return wait(2);
  })
  .then(() => {
    currentImg.style.display = 'none';
    return createImage('img/img-2.jpg');
  })
  .then(img => {
    currentImg = img;
    return wait(2);
  })
  .then(() => {
    currentImg.style.display = 'none';
  })

  .catch(err => console.error(err));


x


const wait = function (seconds) {
  return new Promise(function (resolve) {
    setTimeout(resolve, seconds * 1000);
  });
};

let currentImg;
const imageContainer = document.querySelector('.images');

const createImage = function (imagePath) {
  return new Promise(function (resolve, reject) {
    const img = document.createElement('img');
    img.src = imagePath;

    img.addEventListener('load', function () {
      imageContainer.append(img);
      resolve(img);
    });
    img.addEventListener('error', function () {
      reject(new Erro r('Image not found'));
    });
  });
};

const loadNPause = async function () {
  currentImg = await createImage('img/img-1.jpg');
  await wait(2);
  currentImg.style.display = 'none';
  currentImg = await createImage('img/img-2.jpg');
  await wait(2);
  currentImg.style.display = 'none';
};
// loadNPause();

const loadAll = async function (imgUrls) {
  try {
    const imgs = imgUrls.map(async img => await createImage(img));
    const imgEl = await Promise.all(imgs);
    console.log(imgEl);
    imgEl.forEach(img => img.classList.add('parallel'));
  } catch (e) {
    console.error(e);
  }
};
loadAll(['img/img-1.jpg', 'img/img-2.jpg', 'img/img-3.jpg']);
*/
