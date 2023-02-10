async function setRenderBackground() {
    //body의 background 주소를 넣어도 OK

    //일부러 axios 요청으로 이미지 받아오기 

    //blob -> 이미지, 사운드, 비디오등 멀티미디어 데이터를 다룰때 사용

    const result = await axios.get("https://picsum.photos/1280/720",{
        responseType:"blob"
    });
    //console.log(result.data);

    //url

    const imageURL = URL.createObjectURL(result.data);
    document.querySelector('body').style.backgroundImage=`url(${imageURL})`;
}



// const setRenderBackground =async ()=>{}


function setTime() {
    const timer=document.querySelector('.timer');

    setInterval(()=>{
        //date함수
        const date= new Date();
        timer.textContent=`${date.getHours()}:${date.getMinutes()}:${date.getSeconds()}`;
    }, 1000)
}

function getMemo() {
    //localStorage로부터 가져와서 memo에 넣어주는 작업
    const memo = document.querySelector('.memo');
    memo.textContent=localStorage.getItem('todo');
}

function setMemo() {
    const memoInput = document.querySelector('.memo-input');
    memoInput.addEventListener('keyup', function (e){
        //e.code 입력시 -> 작성한 키보드 조회
        console.log(e.target.value);

        //e.code가 Enter인 경우에만 메모를 바꿀수있도록
        //! null undefined fals ""->부정의 의미
        //if(e.target.value)->위 부정의 의미가 아닌경우를 통합
        //if(!e.target.value)->부정의 의미인경우

        if(e.code=='Enter' && e.target.value){
            //메모를 저장
            const memo = document.querySelector('.memo');
            memo.textContent=e.target.value;

            //메모가 날아가지않도록 저장
            //백엔드 ->DB에 저장해서 가져오는 작업
            //브라우저에도 간단한 저장소 개념이 있다. localStrorage
            //localStroage 사용법
            //localStorage.setItem('키', '넣을값')
            //localStorage.getItem('키')-> 값을 가져온다
            localStorage.setItem('todo',e.target.value);
            //localStorage.
            //getMemo로 분리
            getMemo();

            e.target.value="";
        }

    })
}

function deleteMemo() {

    //이벤트 위임
    //document.querySelector('body')

    //똑같은 함수를 수백만개에 addEventListener 가정 -> 속도 천천히
    document.addEventListener('click', function (e) {
        console.log(e.target);
        //e.target.classList가 hello 인경우에 ~이벤트 실행

        //localStorage를 지워야하고
        if(e.target.classList.contains('memo')) {
            localStorage.removeItem('todo');

            e.target.textContent="";
        }
        //html파트도 지워야한다
    })
}

function allRender() {
    //setRenderBackground();
    setRenderBackground();
    setTime();
    setMemo();
    getMemo();
    deleteMemo();
    //5초마다 해당 콜백함수 반복
    setInterval(()=>{
        setRenderBackground();
    }, 5000);

}

allRender();