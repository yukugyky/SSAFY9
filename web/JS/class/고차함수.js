const bucketLists = [
    { id: 3, text: "여행가기", done: false },
    { id: 2, text: "치킨 먹기", done: true },
    { id: 1, text: "코딩 하기", done: false },
  ];


  const getValues=(indecator)=>{
    bucketLists.map((bucketList)=>bucketList[indecator]);
  }

    console.log(getValues("id"));
    console.log(getValues("text"));
    console.log(getValues("done"));

    const removeList=(ID)=>{
        return bucketLists.filter((bucketlist)=>bucketlist.id!==ID);
    }

    //이렇게 하면 원본데이터 손상
    //새로 하나 복사해서 거기서 바꿔줘야함
    /*
    const toggle=(ID)=>{
        return bucketLists.map((bucketList)=>{
            if(bucketList.id==ID){
                if(bucketList.done==false){
                    bucketList.done=true;
                }else{
                    bucketList.done=false;
                }
            }
            return bucketList});
    }
    */

    const toggle = (id) => {
        const newBucketLists = structuredClone(bucketLists);
        const ret = newBucketLists.filter((el) => el.id === id);
        if (ret[0].done) {
          ret[0].done = false;
        } else {
          ret[0].done = true;
        }
        return newBucketLists;
      };
      
      console.log(toggle(1));

console.log(toggle(2));
console.log(render());
console.log(ids);
console.log(texts);
console.log(dones);
