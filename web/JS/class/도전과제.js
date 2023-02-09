const orderList=[
    {
        menu: "치킨",
        price: 17000,
        event: false,
        count: 50,
    },
    {
        menu: "돈까스",
        price: 8500,
        event: true,
        count: 99,
    },
    {
        menu: "마라탕",
        price: 8000,
        event: false,
        count: 100,
    },
    {
        menu: "쫄면",
        price: 6500,
        event: false,
        count: 0,
    },
    {
        menu: "짜장면",
        price: 5500,
        event: true,
        count: 30,
    },

];

const no0countList=orderList.filter(list=>{
    return list.count!=0;
})

const saledprice=no0countList.map(list=>{
    if(list.event==true){
        list.price*=0.9;
        return list;}
    else
        return list;
});