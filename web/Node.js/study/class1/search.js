const puppeteer=require("puppeteer");

const main = async()=>{
    //브라우저 만들기
    const browser = await puppeteer.launch({
        //기본값이 headless:true
        headless: false
    })

    const page=await browser.newPage();

    await page.goto("https://www.google.co.kr");

    await page.evaluate(()=>{
        //input창 찾아서
        //버튼 클릭
        document.querySelector(".gLFyf").value="치킨";
        document.querySelector(".gNO89b").click();
    })

    await page.waitForSelector(".GLcBOb");
    await page.screenshot({path:"치킨.jpg", fullPage:true});
}

main();