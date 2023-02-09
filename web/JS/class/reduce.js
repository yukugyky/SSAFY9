const studentInfo=[
    {
        name: "jony",
        age: 30,
    },
    {
        name: "sylvie",
        age: 30,
    },
    {
        name: "nana",
        age: 1,
    },
]

//name만 가진 새 배열을 만들어라.
const newStudentInfo = studentInfo.map((student)=>student.name);
//console.log(newStudentInfo);

const newStudentInfo2 = studentInfo.reduce((acc,cur)=>{
    const data=cur.name;
    acc.push(data);
    return acc;
},[]);

//console.log(newStudentInfo2);

const newStudentInfo3 = studentInfo.reduce((acc,cur)=>{
    if(cur.age==30){
    acc.push(cur.name);
    }
    return acc;
},[]);

console.log(newStudentInfo3);

const newStudentInfo5 = studentInfo.map((student, idx)=>{
    console.log(student, idx);
    return student.name;
})

