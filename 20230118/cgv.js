// const title=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-contents > a > strong");
// const rate =document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-contents > div > strong > span");
// const opendate=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-contents > span.txt-info > strong");

// console.log("제목: "+title.textContent);
// console.log("예매율: "+rate.textContent);
// console.log("개봉일: "+opendate.textContent.trim());

// const title2 = document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(2) > div.box-contents > a > strong");
// title2.textContent="삼겹살과 그대라면";
// const rate2=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(2) > div.box-contents > div > strong");
// rate2.textContent="1등 예매율 - 5%";
// const opendate2=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(2) > div.box-contents > span.txt-info > strong");
// opendate2.textContent="1985.07.07"

// //이미지 title swap;
// //li:nth-child(3)으로 변경
// // const title3=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(3) > div.box-contents > a > strong")
// // let temp=title.textContent;
// // title.textContent=title3.textContent;
// // title3.textContent=temp;

const oneurl=document.querySelector(".sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-image > a");
const threeurl=document.querySelector(".sect-movie-chart > ol:nth-child(2) > li:nth-child(3) > div.box-image > a");

let urltemp=oneurl.href;
oneurl.href=threeurl.href;
threeurl.href=urltemp;


const onePoster=oneurl.querySelector("span > img");
const threePoster=document.querySelector(".sect-movie-chart > ol:nth-child(2) > li:nth-child(3) > div.box-image > a > span > img");
let srcTemp=onePoster.src;
onePoster.src=threePoster.src;
threePoster.src=srcTemp;

const boxContents = document.querySelectorAll(".box-contents");
console.log(boxContents);
let temp=boxContents[0].innerHTML;
boxContents[0].innerHTML=boxContents[2].innerHTML;
boxContents[2].innerHTML=temp;

