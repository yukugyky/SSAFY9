//winston -> node의 대표적인 로그 라이브러리
//winston-daily-rotate.file -> 로그 관리 라이브러리
const winston = require('winston');
const {format} = winston;

const {combine} = format;
require('winston-daily-rotate-file');

const transport = new winston.transports.DailyRotateFile({
    level : 'info',
    filename : "./logs/%DATE%.log",
    datePattern: "YYYY-MM-DD-HH",
    zippedArchive:true,
    maxSize:"20m",
    maxFiles:"1d"
});

const logger = winston.createLogger({
    transports: [transport]
})

module.exports= logger;

