function numToString(n) {
  return String(n);
}

function stringToNum(text) {
  return Number(text);
}

const a = numToString(2);
const b = stringToNum("2");
console.log(a);
console.log(b);
console.log(typeof a);
console.log(typeof b);