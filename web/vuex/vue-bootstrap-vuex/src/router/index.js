import Vue from 'vue'
import VueRouter from 'vue-router'
import HomeView from '../views/HomeView.vue'
import Main from '../views/Main.vue'
import TodoList from '../views/todos/List.vue'
import TodoDetail from '../views/todos/Detail.vue'

Vue.use(VueRouter)

const routes = [
  {
    path:"/",
    component: Main
  },
  {
    path:"/todos",
    component: TodoList
  },
  {
    path:"/todos/:id",
    component: TodoDetail
  },
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

export default router
