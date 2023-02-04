/*
함수를 아래와 같이 표현 할 수 있다.
오른족의 이름없는 함수를 람다라고 부른다
*/
const sampleFunc = function () {
  return 1;
};

const result1 = sampleFunc();
console.log(result1);
console.log(typeof result1);

const result2 = sampleFunc;
console.log(result2);
console.log(typeof result2);

/*
함수 자체를 적을수도 있다.
*/