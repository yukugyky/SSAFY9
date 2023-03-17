import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

export default new Vuex.Store({
  //데이터 저장소 this.$store.state('키값 접근')
  state: {
    name:"유경",
    age:100,

  },
  getters: {
  },

  //state의 내용을 변경할 때 사용(개발자도구에서 기록 조회가능)
  //this.$store.commit('mutation 함수 이름', 전달할 인자)
  mutations: {
    SET_MY_NAME(state, data){
      state.name=data;
    },
    SET_MY_AGE(state, data){
      state.age=data;
    }
  },

  //비동기 적인 내용을 포함한 state를 변경할 때 사용
  //비동기 호출 후 mutation 호출
  actions: {
  },
  modules: {
  }
})
