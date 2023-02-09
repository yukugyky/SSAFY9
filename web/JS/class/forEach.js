//배열 베소드 Array.함수(콜백함수)
// addEventListener('click', function() {})

//Array.forEach

const arr=[-5,3,4,2,-7,-2,7];
const pplus=[];
const mminus=[];
let p=0;
let m=0;

arr.forEach(li=>{
    if(li>0){
        pplus[p]=li;
        p++;
    }
    else{
        mminus[m]=li;
        m++;
    }
});

console.log(pplus);
console.log(mminus);