<template lang=pug>
Scroll.listview(
	:data='singers',
	ref='listView',
	:listenScroll='listenScroll',
	@scroll='onScroll',
	:probeType='probeType'
)
	ul
		li.list-group(v-for='(value, index) in singers', ref='listGroup')
			h2.list-group-title {{ value[0] }}
			ul
				li.list-group-item(v-for='item in value[1]')
					img.avatar(v-lazy='item.img1v1Url')
					span.name {{ item.name }}
	.list-shortcut(
		@touchstart='onShortcutTouchStart',
		@touchmove.stop.prevent='onShortCutTouchMove'
	)
		ul
			li.list-shortcut-item(
				v-for='(value, index) in singers',
				:data-index='index',
				:class='{ current: curIndex == index }'
			) {{ value[0] }}
	.list-fixed(v-if='showListFixed')
		h2.list-group-title {{ fixedTitle }}
	Loading(v-if='showFlag').loading
</template>
<script>
import Scroll from '@/base/scroll'
import { getData } from '@/common/js'
import Loading from '@/base/loading'

const ANRCH_HEIGHT = 20
export default {
	components: {
		Scroll,
		Loading
	},
	props: {
		singers: {
			type: Map,
			default: null
		},
	},
	data () {
		return {
			showFlag: true, 
			scrollY: 1,
			curIndex: 0,
			showListFixed: false
		}
	},
	methods: {
		onScroll (pos) {
			this.scrollY = pos.y
		},
		//	onShortcutTouchStart 和 onShortCutTouchMove 用于 右侧 的事件响应
		onShortcutTouchStart (el) {
			const anchorIndex = getData(el.target, 'index')
			let firstTouch = el.touches[0]
			this.touch.y1 = firstTouch.pageY
			this.touch.anrchIndex = anchorIndex
			this._scrollToIndex(anchorIndex)
		},
		onShortCutTouchMove (el) {
			let curTouch = el.touches[0]
			this.touch.y2 = curTouch.pageY
			let delta = this.touch.y2 - this.touch.y1
			let addIndex = delta / ANRCH_HEIGHT | 0  // | 0下取整
			let sumIndex = parseInt(this.touch.anrchIndex) + addIndex
			// console.log('delta', delta, 'addIndex',addIndex, 'anrchIndex',this.touch.anrchIndex,'curIndex', curIndex);
			this._scrollToIndex(sumIndex)
		},
		_scrollToIndex (index) {
			this.scrollY = - this.listHeight[parseInt(index) + 1]
			// console.log('idnex', index, 'scrollY', this.scrollY);
			this.$refs.listView.scroll.scrollToElement(this.$refs.listGroup[index], 0)
		},
		_calculateHeight () {
			this.listHeight = []
			const list = this.$refs.listGroup
			let height = 0
			this.listHeight.push(height)
			for (const item of list) {
				height += item.clientHeight
				this.listHeight.push(height)
			}
		}
	},
	watch: {
		// 监听scrollY落在leftHeight的哪个区间，实现高亮联动
		scrollY (ny) {
			if (ny > 0) {
				this.showListFixed = false
				console.log('ny', ny, 'showListFixed', this.showListFixed);

			} else {
				this.showListFixed = true
			}
			const listHeight = this.listHeight
			for (let index = 0; index < listHeight.length; index++) {
				const h = listHeight[index];
				if (-ny <= h) {
					this.curIndex = index - 1 >= 0 ? index - 1 : 0
					// console.log('index', this.curIndex);
					return
				}
				this.curIndex = index
			}
		}
	},
	created () {
		this.touch = {}
		this.listenScroll = true
		this.listHeight = []
		this.probeType = 3	 // probeType默认为1会节流
	},
	computed: {
		titlelist () {
			return Array.from(this.singers.keys())
		},
		fixedTitle () {
			return this.titlelist[this.curIndex]
		}
	},
	mounted () {
		setTimeout(() => {
			this.showFlag = false
			this._calculateHeight()
		}, 20)
	}
}
</script>

<style lang='scss' scoped>
@import '~@/common/scss/const.scss';

.listview {
	position: relative;
	height: 100%;
	overflow: hidden;
	background: $color-background;
	width: 100%;
	.list-group {
		.list-group-item {
			display: flex;
			align-items: center; // 水平居中
			padding: 5px 0 5px 30px;
			height: 70px;
			width: 100%;
			font-size: $font-size-medium;
			color: $color-text-l;
			position: relative;
			.avatar {
				width: 60px;
				height: 60px;
				border-radius: 30px;
			}
			.name {
				margin-left: 30px;
			}
		}
	}
	.list-shortcut {
		position: absolute;
		top: 50px;
		right: 0;
		background: $color-background-d;
		.list-shortcut-item {
			text-align: center;
			font-size: $font-size-small;
			line-height: 20px;
			color: $color-text-l;
			&.current {
				color: $color-theme;
			}
		}
	}
	.list-fixed {
		position: absolute;
		top: 0px;
		width: 100%;
	}
	.loading{
		position: absolute;
		top: 50%;
	}
	// common style
	.list-group-title {
		margin-bottom: 5px;
		line-height: 30px;
		height: 30px;
		text-indent: 30px;
		font-size: $font-size-medium;
		color: $color-text-l;
		background-color: $color-highlight-background;
	}
}
</style>