//백틱(키보드 왼쪽 상단에 있는거)=> ``
//문자열 자바스크립트 혼합 OK

const myName="이온유";
const introduce="제 이름은 "+ myName+"입니다.";
// ${}
const introduce2=`제 이름은 ${myName}입니다`;

//백틱은 enter를 허용한다

//오류 발생
const hello="안녕"+
"나는"+
"치킨";

const hello2=`
안녕
나는
치킨;
`

//insertAdjacentHTML
const a=`
<div class="a">
안녕하세요
</div>
`

const bb=(hello)=>`
<div class="a">
${hello}
</div>
`

document.querySelector('body').insertAdjacentHTML('beforeend',a);

const n=10;
const sampleFunc=(n)=>n*10;
const aa=n*20;

const resultt=sampleFunc(10)+a;
console.log(resultt);

const func1=(v1,v2)=>v1*v2;
const b=func1(4,5)+func1(5,6);
console.log(func1(1,10)+b);

const run=(func1,func2) =>func1(1,2)*func2(3,4);
const result =run(
    (a,b)=>a+b,
    (a,b)=>a*b
);
console.log(result);