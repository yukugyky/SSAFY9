import Vue from 'vue'
import VueRouter from 'vue-router'
import HomeView from '../views/HomeView.vue'
import Board from '../views/BoardListView.vue'
import BoardDetailView from '../views/BoardDetailView.vue'

Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'home',
    component: HomeView
  },
  {
    path:'/board',
    name:'board',
    component: Board
  },
  {
    path:'/board/:id',
    name:'board-detail',
    component: BoardDetailView
  }
]


const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

export default router
