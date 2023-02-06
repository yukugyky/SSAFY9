class LawyerInfo{
    constructor(name, age,soge){
        this.name=name;
        this.age=age;
        this.soge=soge;
    }
    introduce() {
        console.log(`이름: ${this.name}`);
        console.log(`나이: ${this.age}`);
        console.log(`자기소개: ${this.soge}`);
    }    
}

const layer1 = new LawyerInfo("우영우", 27, "기러기 토마토 스위스 역삼역");
const layer2 = new LawyerInfo("최수연", 27, "봄날의 햇살");

layer1.introduce();
layer2.introduce();
