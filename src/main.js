import 'babel-polyfill'
import Vue from 'vue'
import App from './App'
import router from '@/router'
import '@/common/scss/index.scss'
import fastclick from 'fastclick'
import VueLazyLoad from 'vue-lazyload'
// 移动端去除点击300ms延迟
fastclick.attach(document.body)

Vue.config.productionTip = false

Vue.use(VueLazyLoad, {
  loading: require('commom/img/default.png')
})
/* eslint-disable no-new */
new Vue({
  el: '#app',
  router,
  render: h => h(App)
}) 