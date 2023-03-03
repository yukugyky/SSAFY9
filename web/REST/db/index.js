const mysql = require("mysql2/promise");

//DB 연결정보 셋팅

const pool=mysql.createPool({
    //AWS HOST
    host: "13.125.11.78",
    //mysql username
    user: "ssafy",
    //mysql pwd
    password: "*ssafy09",
    //db및 스키마 이름
    database: "ssafy",
    waitForConnections: true,
    connectionLimit:10,
    queueLimit:0,
});

module.exports=pool;
//module.exports={pool}; ->받아올때 const {pool}=require("./db/index.js")