//함수 표현식

const a=function(){
    console.log("aa");
}

a;

//화살표 함수
const b = () => {console.log("bb")};
const c=() => console.log("cc");

const sum=(a,b)=>{return a+b};
sum(3,4);

const sum2=(a,b)=>a+b;
sum2(4,5);

const go=(a)=>a*a;
go(10)