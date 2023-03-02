//패키지를 가져오는법
//require로 가져올수있다
//내부에있는모듈은 ./~~

const puppeteer=require("puppeteer");

const main = async()=>{
    //브라우저 만들기
    const browser = await puppeteer.launch({
        //기본값이 headless:true
        headless: true
    })

    //브라우저에 페이지 만들기
    const page=await browser.newPage();

    //페이지에서 주소로 이동하기
    await page.goto("https://comic.naver.com/webtoon?tab=mon");

    //대기하는법
    //waitForSelector -> 특정 selector가 올때까지 대기하는 역할
    //이미지가 로딩시에 없었으니 이미지가 나올때까지 기다리는 역할 
    await page.waitForSelector("#content .item img");

    //document.querySelectorAll("#content .item");

    //크롤링데이터 가져오기
    //node.js는 브라우저가 아닌 환경이기때문에 document 사용 불가능 
    //evaluate 안에서는 document 사용이 가능하다.
    const data=await page.evaluate(()=>{
        const webToonList = document.querySelectorAll("#content .item img");

        //querySelectorAll 유사배열
        //-> Array.from으로 배열화를 시킨후에 배열 메서드가 사용가능
        //제목을 가져오는것
        const result=Array.from(webToonList).map(li=>li.getAttribute('alt'));
        return result;
    })
    console.log(data);

    //스크린샷 찍기
    //await page.screenshot({path:"screenshot.jpg", fullPage:true});

    //pdf 따기(headless:true 에서만 동작)
    //await page.pdf({path: "test.pdf", format:'A4'});

    //브라우저 종료하기
    //await browser.close();
}

main();