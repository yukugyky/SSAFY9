class Person{
    constructor(name,hp){
        this.name=name;
        this.hp=hp;
    }
    hello(){
        console.log(`안녕하세요 저는 ${this.name}입니다`);
    }  
}

class Avengers extends Person{
    constructor(name, hp, power,skill){
        super(name, hp);
        this.power=power;
        this.skill=skill;
    }
    information(){
        console.log(`${this.name}, ${this.hp}, ${this.power}, ${this.skill}`);
    }
    fly(){
        console.log("비행중");
    }
}

const spiderman = new Avengers("스파이더맨", 100, 1000,"거미줄");
spiderman.information();
spiderman.fly();


