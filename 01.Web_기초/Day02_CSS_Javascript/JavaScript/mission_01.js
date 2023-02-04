const arr = [1, 2, 3, 1, 2, 3, 1, 2, 3];
let cnt = 0;
for (let i = 0; i < arr.length; i++) {
  if (arr[i] === 1) {
    cnt++;
  }
}
console.log(cnt);
