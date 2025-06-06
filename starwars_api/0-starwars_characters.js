#!/usr/bin/node

const request = require('request');
const filmId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${filmId}`;

request(url, (err, res, body) => {
  if (err) return console.error(err);

  const characters = JSON.parse(body).characters;

  const printCharacters = (index) => {
    if (index >= characters.length) return;

    request(characters[index], (err, res, body) => {
      if (err) return console.error(err);

      console.log(JSON.parse(body).name);
      printCharacters(index + 1);
    });
  };

  printCharacters(0);
});