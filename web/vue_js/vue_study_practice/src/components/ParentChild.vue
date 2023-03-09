<template>
    <div>
        <h1>나</h1>
        <div>{{halbaeData}}</div>
        <div>{{halbaeData2}}</div>
        <button @click="changeHalbaeDataFromGrandChild">할배 데이터를 바꾸자~</button>
    </div>
</template>

<script>

export default {
    props:["halbaeData","halbaeData2"],
    methods: {
        changeHalbaeDataFromGrandChild(){
            this.$emit("changeHalbaeDataFromGrandChild", "손자가 할배 데이터 바꿈");
        },
    },
}
</script>
