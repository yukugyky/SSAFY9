const names=["jonny","sylvie","nana"];

//slice ->원본배열 손상X (index부터 index-1까지)
const nesNames=names.slice(0,3);
console.log(names);
console.log(nesNames);

//splice ->원본배열: (시작index, 추가or 삭제 길이, 그리고 삭제된 곳에 option으로 추가할 element)
    // 새배열: 삭제된거 저장
const newNames=names.splice(1,2,"yugyeong","yuna");
console.log(names);
console.log(newNames);

//원본배열에 jonny만 남기기, jonny배열에는 splice값
const jonny=names.splice(1,2);




