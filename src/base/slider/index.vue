<template lang=pug>
.slider(ref='slider')
  .slider-group(ref='sliderGroup')
    slot
  .dots
    span.dot(
      v-for='(item, index) in dots',
      :class='{ active: currentPageIndex == index }'
    )
</template>

<script>
import BScroll from 'better-scroll'
import { addClass } from '@/common/js'

export default {
  props: {
    loop: {
      type: Boolean,
      default: true
    },
    autoplay: {
      type: Boolean,
      default: true
    },
    interval: {
      type: Number,
      default: 2500,
    }
  },
  data () {
    return {
      dots: [],
      currentPageIndex: 0
    }
  },
  mounted () {
    setTimeout(() => {
      this._setSliderWidth()
      this._initDots()
      this._initSlider()
      if (this.autoplay) {
        this._play()
      }
    }, 20)

		window.addEventListener('resize', ()=>{
			if(!this.slider) return 
			this._setSliderWidth(true)
			this.slider.refresh()
		})
  },
  methods: {
    _setSliderWidth (isResize) {
      this.children = this.$refs.sliderGroup.children
      let width = 0
      let sliderWidth = this.$refs.slider.clientWidth
      for (let i = 0; i < this.children.length; i++) {
        let child = this.children[i]
        // 为child添加样式和宽度
        addClass(child, 'slider-item')
        child.style.width = sliderWidth + 'px'
        // 为sliderGroup计算宽度 其宽度为所有子元素宽度之和 这样才能一行内放下所有子元素
        width += sliderWidth
      }
      // 针对loop为true时做额外处理  
      if (this.loop == true && ! isResize) {
        width += 2 * sliderWidth
      }
      this.$refs.sliderGroup.style.width = width + 'px'
    },
    _initSlider () {
      this.slider = new BScroll(this.$refs.slider, {
        scrollX: true,
        scrollY: false,
        momentum: false,
        snap: true,
        snapLoop: this.loop,
        snapThreshold: 0.3,
        snapSpeed: 400,
        click: true
      })

      this.slider.on('scrollEnd', () => {
        let pageIndex = this.slider.getCurrentPage().pageX
        if (this.loop) {
          pageIndex -= 1
        }
        this.currentPageIndex = pageIndex
				if(this.autoplay){
					clearTimeout(this.timer)
					this._play()
				}
      })
    },
    _initDots () {
      this.dots = new Array(this.children.length)
    },
    _play () {
      let pageIndex = this.currentPageIndex + 1
      if (this.loop) {
        pageIndex += 1
      }
      this.timer = setTimeout(() => {
				this.slider.goToPage(pageIndex, 0, 1000)
      }, this.interval)
    }
  },
	destroyed(){
		clearTimeout(this.timer)
	}

}
</script>

<style lang='scss' scoped>
@import '~@/common/scss/const.scss';

.slider {
  min-height: 1px;
  .slider-group {
    position: relative;
    overflow: hidden;
    white-space: nowrap; // white-space用来设置文字换行 nowrap即是不换行
    .slider-item {
      float: left;
      box-sizing: border-box;
      overflow: hidden;
      text-align: center;
      img {
        display: block;
        width: 100%;
      }
    }
  }
  .dots {
    position: absolute;
    right: 0;
    left: 0;
    bottom: 12px;
    text-align: center;
    font-size: 0;
    .dot {
      display: inline-block;
      margin: 0 4px;
      width: 8px;
      height: 8px;
      border-radius: 4px;
      background: $color-text-l;
      // font-size: ;
      &.active {
        width: 20px;
        border-radius: 5px;
        background-color: $color-text-ll;
      }
    }
  }
}
</style>