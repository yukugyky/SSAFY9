class Hero{
    constructor(HP){
        this.HP=HP;
    }
    showHP() {
        console.log(`HP: ${this.HP}`);
    }
    run() {
        this.HP-=10;
    }    
}

const batman = new Hero(100);

batman.showHP();
batman.run();
batman.run();
batman.showHP();