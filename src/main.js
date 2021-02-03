import 'babel-polyfill'
import Vue from 'vue'
import App from './App'
import router from '@/router'
import '@/common/scss/index.scss'
import fastclick from 'fastclick'

// 移动端去除点击300ms延迟
fastclick.attach(document.body)

Vue.config.productionTip = false
/* eslint-disable no-new */
new Vue({
  el: '#app',
  router,
  render: h => h(App)
}) 