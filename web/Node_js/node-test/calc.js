

const calc={
    add:(a,b)=>a+b,
    substract:(a,b)=>a-b,
    multi:(a,b)=>a*b,
    div:(a,b)=>a/b,
}

const a=2;
const b=4;

console.log(`주어진 수: ${a} ${b}`);
console.log(`덧셈 결과: ${calc.add(a,b)}`);
console.log(`덧셈 결과: ${calc.substract(a,b)}`);
console.log(`덧셈 결과: ${calc.multi(a,b)}`);
console.log(`덧셈 결과: ${calc.div(a,b)}`);


module.exports=calc;
