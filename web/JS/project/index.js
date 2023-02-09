//data
const cardArray=[
    {
        name:"cat",
        img:"./public/cat.png",
        id:null,
        done:false,
    },
    {
        name:"cat",
        img:"./public/cat.png",
        id:null,
        done:false,
    },
    {
        name:"dog",
        img:"./public/dog.png",
        id:null,
        done:false,
    },
    {
        name:"dog",
        img:"./public/dog.png",
        id:null,
        done:false,
    },
    {
        name:"elephant",
        img:"./public/elephant.png",
        id:null,
        done:false,
    },
    {
        name:"elephant",
        img:"./public/elephant.png",
        id:null,
        done:false,
    },
    {
        name:"hedgehog",
        img:"./public/hedgehog.png",
        id:null,
        done:false,
    },
    {
        name:"hedgehog",
        img:"./public/hedgehog.png",
        id:null,
        done:false,
    },
    {
        name:"pig",
        img:"./public/pig.png",
        id:null,
        done:false,
    },
    {
        name:"pig",
        img:"./public/pig.png",
        id:null,
        done:false,
    },
    {
        name:"squirrel",
        img:"./public/squirrel.png",
        id:null,
        done:false,
    },
    {
        name:"squirrel",
        img:"./public/squirrel.png",
        id:null,
        done:false,
    },
];

let clickFirst =-1;
let clickSecond=-1;
let clickCount=0;



//// 파싱한 돔 정보
const gameDOM=[];

////////
const getGameDom=()=>{
    const rows=document.querySelectorAll(".row");
    rows.forEach((row, idx)=>{
        gameDOM[idx]=row.querySelectorAll(".column");
    });
};

const setClickHistory=(location)=>{
    if(clickFirst===-1){
        clickFirst=location;
    }else {
        clickSecond=location;
    }
};

const backFlip=()=>{
    const parsedIdFirst=cardArray[clickFirst].id.split("-");
    const parsedIdSecond=cardArray[clickSecond].id.split("-");
    setTimeout(()=>{
    gameDOM[parsedIdFirst[0]][parsedIdFirst[1]].querySelector("img").src=
    "./public/Question-Mark.png";
    gameDOM[parsedIdSecond[0]][parsedIdSecond[1]].querySelector("img").src=
    "./public/Question-Mark.png";
    },200)
}

const isCorrect=()=>{
    if(cardArray[clickFirst].name===cardArray[clickSecond].name){
        cardArray[clickFirst].done=true;
        cardArray[clickSecond].done=true;
    }else{
        backFlip();
    }
};

const flip=(location)=>{
    if(!cardArray[location].done){
        setClickHistory(location);

        const parsedId = cardArray[location].id.split("-");
        gameDOM[[parsedId[0]]][[parsedId[1]]].querySelector("img").src=
        cardArray[location].img;

        clickCount++;
        if(clickCount===2){
            clickCount=0;
            isCorrect();
        }
        console.log(clickCount);

        if(clickFirst!==-1&&clickSecond!==-1){
            clickFirst=-1;
            clickSecond=-1;
        }
    }
};

const setIdtoCardArray=()=>{
    cardArray[0].id="0-0";
    cardArray[1].id="0-1";
    cardArray[2].id="0-2";
    cardArray[3].id="0-3";
    cardArray[4].id="1-0";
    cardArray[5].id="1-1";
    cardArray[6].id="1-2";
    cardArray[7].id="1-3";
    cardArray[8].id="2-0";
    cardArray[9].id="2-1";
    cardArray[10].id="2-2";
    cardArray[11].id="2-3";

}

const creatBoard=()=>{
    for(let i=0;i<gameDOM.length;i++){
        for(let j=0;j<gameDOM[i].length;j++){
            const card=document.createElement("img");
            card.setAttribute("src","./public/Question-Mark.png");
            card.classList.add("eachImage");
            gameDOM[i][j].appendChild(card);
        }
    }
}
/////////
getGameDom();
cardArray.sort(()=>0.5-Math.random());
setIdtoCardArray();
console.log(cardArray);
creatBoard();


