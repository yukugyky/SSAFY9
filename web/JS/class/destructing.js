const abc={
    name:"치킨",
    type:"후라이드"
}

const {name.type}=abc;
console.log(name);
console.log(type);

const arr=()=>{
    return [1,2];
};
const [one, two]=arr();
console.log(one);
console.log(two);

const square={
    width: 200,
    height: 200,
};

const colorSquare={
    width: square.width,
    height:square.height, //...square (이렇게 스프레드쓰면 square 객체 다 가져옴)
    color:"red",
};

const catType=['고양이','호랑이'];
const dogType=['개','늑대'];
const allType=[...catType,...dogType,'비버'];
console.log(allType); //['고양이','호랑이','개','늑대','비버'];

console.log(colorSquare);

const num=[0,1,2,3,4,5,6];
const [one,two, ...another]=num;
console.log(one);
console.log(another); // [2,3,4,5,6]