<template>
  <div>
    <h1>아빠</h1>
    <div>{{ halbaeData }}</div>
    <div>{{ halbaeData2 }}</div>
    <button @click="changeHalbaeData">부모의 데이터 바꾸자!</button>
    <ParentChild
      :halbaeData="halbaeData"
      :halbaeData2="halbaeData2"
      @changeHalbaeDataFromGrandChild="changeHalbaeDataFromGrandChild"
    />
  </div>
</template>

<script>
import ParentChild from "./ParentChild.vue";

export default {
  components: {
    ParentChild,
  },
  props: ["halbaeData", "halbaeData2"],
  methods: {
    changeHalbaeData() {
      this.$emit("changeHalbaeData", "랄랄라");
    },
    changeHalbaeDataFromGrandChild(text) {
      this.$emit("changeHalbaeData", text);
    },
  },
};
</script>

<style></style>
