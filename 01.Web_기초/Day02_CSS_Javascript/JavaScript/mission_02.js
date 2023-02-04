const arr = ["A", "E", "W", "Q", "A"];
let flag = 0;

for (let i = 0; i < arr.length; i++) {
  if (arr[i] === "A") {
    flag = 1;
  }
}
if (flag === 1) {
  console.log("O");
} else {
  console.log("X");
}
