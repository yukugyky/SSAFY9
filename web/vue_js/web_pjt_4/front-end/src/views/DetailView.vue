<template>
  <div>
    <h1>Detail</h1>

    <div v-if="isLoading">
      <b-spinner variant="success" label="Spinning"></b-spinner>
    </div>

    <div v-else>
      <div>{{ menuId }} 번 메뉴 디테일 페이지입니다.</div>
      <div>메뉴 : {{ menu.name }}</div>
      <div>설명 : {{ menu.description }}</div>
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  data() {
    return {
      menuId: -1,
      menu: {},
      isLoading: false,
    };
  },
  async created() {
    try {
      this.isLoading = true;
      this.menuId = this.$route.params.id;
      const response = await axios.get(
        `http://localhost:8080/api/menus/${this.menuId}`
      );
      console.log(response.data);
      this.menu = response.data;
    } catch (error) {
      console.log(error);
    }
  },
};
</script>

<style></style>
