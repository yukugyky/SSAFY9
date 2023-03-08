const express=require('express');
const app=express();

const cors = require('cors');
const pool=require=require("./db/index");
//app.use는 전역(모든 요청마다) 적용
app.use(cors());

//body에 데이터를 받아오기 위해서는 셋팅이 하나 꼭 필요하다.
//json형식의 데이터를 받아오기 위해 필요한 셋팅-> 이게 빠지면 body데이터 받아오기 x
app.use(express.json())

const PORT=8080;
//jonny 스키마의 menus 테이블의 정보를 가져와서
//GET /api/menus
//DB연결=>async/await DB 행동에 비동기
//localhost:8080/api/menus 접속해보기
app.get("/api/menus", async (req,res)=>{
    try{
        //select *from menus;
        const data=await pool.query("select * from menus");
        return res.json(data[0]);
    }catch(error){
        console.log(error);
        return res.json(error);
    }
});

//POST /api/menus ?? 이때는 클라이언트를 만들어야한다.
app.post("/api/menus", async (req,res)=>{
    console.log(req.body);
    //body안에 menu_name, menu_description을 db에 쿼리로 날리면 끝
    try{
        //첫번째 방식 부분들은 변수로 넣을 수 있다
        const data=await pool.query(`INSERT INTO menus (menu_name, menu_description,menu_img_link)
        VALUES (?, ?, ?)`, [req.body.menu_name,req.body.menu_description,"none"]);
        return res.json(data);
        //두번째 방식
    }catch(error){
        console.log(error);
        return res.json(error);
    }
    // return res.json({"TEST":"OK", TYPE:"POST"});
});


app.listen(PORT,()=>console.log(`${PORT} 서버 가동중`));
//ssafy 스키마의 menus 테이블의 정보를 가져와서



