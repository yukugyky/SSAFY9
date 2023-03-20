const axios=require("axios");

const api = axios.create({
    baseURL:"http://localhost:8081",
});

export const dataLab={
    get:()=>{
        return api.get("/api/data");
    },
    post: (data)=>{
        return api.post("/api/data", data);
    },
}