// 토글버튼
const toogleButton = document.querySelector(".toggle-button");
// 배경
const bodyBackground = document.querySelector("body");
// header-nav
const headerNav = document.querySelector(".header-nav-list-wrapper");
// bookmark-wrapper
const bookmarkWrapper = document.querySelector(".bookmark-wrapper");
// search-input
const searchInput = document.querySelector("#search-input");
// img-icon-wrapper
const imgIconWrappers = document.querySelectorAll(".img-icon-wrapper");
// bookmark-text
const bookmarkTexts = document.querySelectorAll(".bookmark-text");

toogleButton.addEventListener("click", function () {
  toogleButton.textContent = "다크 모드";
  toogleButton.classList.toggle("toggle-button-darkmode");
  bodyBackground.classList.toggle("body-background-darkmode");
  headerNav.classList.toggle("text-darkmode");
  for (let i = 0; i < imgIconWrappers.length; i++) {
    imgIconWrappers[i].classList.toggle(".img-icon-wrapper-darkmode");
  }
  for (let i = 0; i < bookmarkTexts.length; i++) {
    bookmarkTexts[i].classList.toggle(".text-darkmode");
  }
  if (toogleButton.classList.contains("toggle-button-darkmode")) {
    toogleButton.textContent = "일반 모드";
  }
});

searchInput.addEventListener("keyup", function (e) {
  if (e.code === "Enter") {
    if (!e.target.value) {
      alert("검색어를 입력하세요");
      return;
    }
    const gooleSearch = "https://www.google.com/search?q=";
    //location.href = gooleSearch + e.target.value;
    window.open(gooleSearch + e.target.value);
  }
});
