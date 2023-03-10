const express =require('express');
const morgan = require('morgan');
const axios = require('axios');
const app=express();
const PORT=8080;

app.use(morgan('dev'));

//템플릿 엔진으로 ejs를 사용
app.set('view engine', 'ejs');
//해당 ejs에서 활용할 경로를 ./view 폴더로 활용
app.set('views', './views');

app.get("/", (req,res)=>{
    res.render('index', {name:"온유"})
})

app.get("/holder", async(req, res)=>{
    const result=await axios.get("https://jsonplaceholder.typicode.com/todos");

    //holder.ejs를 해석 -> 없으니까 만들기
    res.render('holder-list', {data: result.data});
    console.log(result);

})

app.get("/holder/:id", async(req, res)=>{
    const result=await axios.get(`https://jsonplaceholder.typicode.com/todos/${req.params.id}`);

    //holder.ejs를 해석 -> 없으니까 만들기
    res.render('holder', {data: result.data});
})

app.listen(PORT, ()=> console.log(`${PORT} 서버 구동중`));