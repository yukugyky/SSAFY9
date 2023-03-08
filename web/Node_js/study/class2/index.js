<<<<<<< HEAD
const express=require("express"); //express를 가져와라!

const app=express();
const PORT=8080;

const cors=require("cors");
app.use(cors());

app.get("/api/info",(req,res)=>{ //api/info에 접속하면 저 json가져와라
    return res.json({
        name: "jony",
        job:"tutor",
    })
})

app.get("/api/info2",(req,res)=>{ //api/info에 접속하면 저 json가져와라
    return res.json({
        name: "이유경",
        job:"싸피9기",
        age:"27",
    })
})

app.listen(PORT, ()=>console.log(`this server is listening on ${PORT}`));

=======
const express=require("express"); //express를 가져와라!

const app=express();
const PORT=8080;

const cors=require("cors");
app.use(cors());

app.get("/api/info",(req,res)=>{ //api/info에 접속하면 저 json가져와라
    return res.json({
        name: "jony",
        job:"tutor",
    })
})

app.get("/api/info2",(req,res)=>{ //api/info에 접속하면 저 json가져와라
    return res.json({
        name: "이유경",
        job:"싸피9기",
        age:"27",
    })
})

app.listen(PORT, ()=>console.log(`this server is listening on ${PORT}`));

>>>>>>> c4f5e227e3d747dec608b90657ca71f259b22419
