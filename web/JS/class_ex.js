const StudentInfo = {
    name: "", //string이라고 명시적으로 
    age: -1,
    address: "", //
    //키와 값이 같을 때
    //address, 이렇게만 쓰고 끝낼 때도 있음
    constructor: function (name, age) { //화살표함수는 this에 접근할 수 없음
      this.name = name;
      this.age = age;
    },
    sayMyName: function () {
      console.log(`my name is ${this.name}`);
    }, 
    //이거와 같음
    //sayMyname() {
    //    console.log(`my name is ${this.name}`);
    //},
    setAddress: (address) => (this.address = address),
    getAddress: () => this.address,
    useMethod: function () {
      this.sayMyName();
    },
  }; //이러면 student2 꺼로 똑같은 거 만들고 싶을 때 복붙해서 사용해야하니깐
  //class를 추가해서 사용하면 재선언할 필요가 없다~!
  
  student1.constructor("jony", 30);
  student2.constructor("david", 50);
  student1.sayMyName();
  student1.setAddress("경기 군포시 산본동");
  console.log(student1.getAddress());
  student1.useMethod();