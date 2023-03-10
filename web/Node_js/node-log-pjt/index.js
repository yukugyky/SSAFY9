//로그의 레벨7
//error, warn, info, http, verbose, debug, silly
//error, warn, info, debug

//error -> 에러 기록
//warn -> 에러는 아니지만 유의할 내용
//info -> 내용
//debug -> 상세한 데이터 기록


const express = require('express');
const morgan = require('morgan');
const logger = require('./utils/log');
const app=express();
const PORT =8080;
app.use(morgan('dev'));

//원격 로그 수집 시스템 (elastic stack)
//여러군데 모여있는 로그를 한군데서 조회하고싶은경우

app.get("/api/logs", (req, res)=>{
    logger.error("error 메세지");
    logger.warn("warn 메세지");
    logger.info("info 메세지");
    logger.debuf("debug 메세지");
    return res.json({
        test : "OK"
    })
})
app.listen(PORT, ()=> console.log(`${PORT} 서버 가동중`))