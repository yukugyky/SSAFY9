<template>
  <div>
    <h1>Home</h1>
  
    <ul v-if="menus.length">
        <li v-for="menu in menus" :key="menu.id">
          <div class="menu-name" v-on:click="goDetail(menu.id)">메뉴 : {{menu.name}}</div>
          <div>설명 : {{menu.description}}</div>
          <hr>
        </li>
    </ul>

  <div v-else>
     <b-spinner variant="success" label="Spinning"></b-spinner>
      로딩중...
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  data(){
    return {
      menus: [],
    };
  },
  async created(){
    try{
      
      const response = await axios.get("http://localhost:8080/api/menus/");
      console.log(response.data);
      this.menus=response.data;
    } catch(error){
      console.log(error);
    }
  },

  methods:{
    goDetail(id){
      this.$router.push(`/detail/${id}`);
    }
  }

};
</script>

<style>

.menu-name{
  color:blue;
  text-decoration: underline;

}
</style>