const arr=[1,2,3,1,2,,1,2,3];
let count=0;
for(let i=0;i<arr.length;i++){
    if(arr[i]==1){
        count=count+1;
    }
}

console.log(count)

const arr2=['A','E','W','Q','A'];
let d=0;
for(let i=0;i<arr2.length;i++){
    if(arr2[i]==='A'){
        d=1;
        break;
    }
}

if(d===0){
    console.log("X");
}
else{
    console.log("O");
}