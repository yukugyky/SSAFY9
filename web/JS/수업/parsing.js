const students=[
    {
        name:"김도훈",
        age:26,
        address: "경남 창원시"
    },
    {
        name:"김기홍",
        age:27,
        address:"광주광역시",
    },
    {
        name:"김택우",
        age:30,
        address:"인천광역시",
    },
];

students.forEach(student => { //타입은 함수! 파라미터로 함수가 들어간다~ function()
    console.log(student.name);
}); //for문은 길이를 정해줘야하는데 forEach는 자기가 알아서 돌아줌.(자바스크립트의 좋은점)

const names=students.map(student=>{
    return student.name;
});

console.log(names);

const under30people=students.filter(student=>{
    return student.age<30;
}); //30이하인 객체들 가져옴

const under30names=under30people.map(student=>{
    return student.name;
}); //그 객체 안에서 이름만 빼서 새배열 만들어주기


const arr=[1,2,3,4,5,6,7,8,9,10];
const aa=arr.filter(a=>{
    return a%2==0;
})



const aaa=aa.map(a=>a*10);

console.log(aaa);



