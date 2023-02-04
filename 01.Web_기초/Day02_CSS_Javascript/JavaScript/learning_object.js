/*
배열과 달리 객체로 선언하면, 키로 접근가능
객체안의 함수는 메서드라고 함
const object = {
  key: value,
}
*/
/*
배열과 객체의 각 요소는 const로 선언해도 바꿀 수 있다.
키값은 추가할 수 있다.
객체는 배열과 달리 순서가 없다.
*/

const person = {
  name: "서정빈",
  yearOfBirth: 1997,
  familyMembr: ["아빠", "엄마", "할머니"],
  job: "교육생",
  isMerriaged: true,
};

person.name = "jeong";
person.hometown = "전남 목포시";
console.log(person);


/*
아래와 같이 완전히 새롭게 쓰는것은 불가능(const의 원칙)
*/ 
const arr = [1, 2, 3];
arr = [4, 5, 6];
