const mysql = require("mysql2/promise");

const pool = mysql.createPool({
    // aws ip
    host: "13.125.11.78",
    // mysql username
    user: "ssafy",
    // mysql user password
    password: "*ssafy09",
    // db name
    database: "order_system",
    waitForConnections: true,
    connectionLimit: 10,
    queueLimit: 0,
})

module.exports = { pool }