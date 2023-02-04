const movieTitle01 = document.querySelector(
  "ol:nth-child(2) > li:nth-child(1) > div.box-contents > a > strong"
);
const movieResevationRate01 = document.querySelector(
  "ol:nth-child(2) > li:nth-child(1) > div.box-contents > div > strong > span"
);
const movieOpenDate01 = document.querySelector(
  "ol:nth-child(2) > li:nth-child(1) > div.box-contents > span.txt-info > strong"
);
const moviePoster01 = document.querySelector(
  "ol:nth-child(2) > li:nth-child(1) > div.box-image > a > span > img"
);
console.log(movieTitle01.textContent);
console.log(movieResevationRate01.textContent);
console.log(movieOpenDate01.textContent.trim());

const movieTitle02 = document.querySelector(
  "ol:nth-child(2) > li:nth-child(2) > div.box-contents > a > strong"
);
const movieResevationRate02 = document.querySelector(
  "ol:nth-child(2) > li:nth-child(2) > div.box-contents > div > strong > span"
);
const movieOpenDate02 = document.querySelector(
  "ol:nth-child(2) > li:nth-child(2) > div.box-contents > span.txt-info > strong"
);
movieTitle02.textContent = "삼겹살과 그대라면";
movieResevationRate02.textContent = "5%";
movieOpenDate02.textContent = "1985.07.07 개봉";

const movieTitle03 = document.querySelector(
  "ol:nth-child(2) > li:nth-child(3) > div.box-contents > a > strong"
);
const moviePoster03 = document.querySelector(
  "ol:nth-child(2) > li:nth-child(3) > div.box-image > a > span > img"
);
let tilteTemp = movieTitle01.textContent;
movieTitle01.textContent = movieTitle03.textContent;
movieTitle03.textContent = tilteTemp;
let srcTemp = moviePoster01.src;
moviePoster01.src = moviePoster03.src;
moviePoster03.src = srcTemp;

const boxCotents = document.querySelectorAll(".box-contents");
console.log(boxCotents);