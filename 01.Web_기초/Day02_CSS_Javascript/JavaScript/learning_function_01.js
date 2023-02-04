/*
script는 html에서 </body> 바로 위에 선언
*/
/*
함수이름은 명사 + 동사로 만든다
함수는 이름만 보고 하는 역할을 잘 파악할 수 있어야한다.
*/
/*
함수를 선언할 때는 function을 선언한다.
function은 합수의 선언자
return type, parameter typr은 선언하지 않는다
*/
/*
log는 함수
*/
/*
console.log(addOne(2));
function addOne(n) {
  console.log("Hi");
  return n + 1;
이처럼 선언을 아래에해도 가능하나 이렇게 새용하지 말것!
}*/
function addOne(n) {
  console.log("Hi");
  return n + 1;
}
console.log(addOne(2));