import Vue from 'vue'
import Router from 'vue-router'
import Recommend from '@/components/recommend'
import Singer from '@/components/singer'
import Rank from '@/components/rank'
import Search from '@/components/search'

Vue.use(Router)


export default new Router({
		routes:[
			{
				path: '/',
				redirect: '/search'
			},
			{
				path: '/recommend',
				component: Recommend
			},
			{
				path: '/singer',
				component: Singer
			},
			{
				path: '/search',
				component: Search
			},
			{
				path: '/rank',
				component: Rank
			}
		]
})