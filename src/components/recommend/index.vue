<template lang=pug>
.recommend
  Scroll.recommend-content(:data='discList', ref='scroll')
    div
      .slider-wrapper(v-if='recommends.length')
        Slider
          div(v-for='item in recommends')
            img(@load='onload', :src='item.imageUrl')
      .recomend-list
        h1.list-title 热门歌单推荐
        ul
          li.item(v-for='item in discList')
            .icon
              img(width='60', height='60', v-lazy='item.picUrl')
            .text
              h2.name {{ item.copywriter }}
              p.desc {{ item.name }}
    .loading-container(v-show='!discList.length')
      Loading
</template>

<script>
import { getBanner, getPersonalized, getAllSinger } from '@/api'
import Slider from '@/base/slider'
import Scroll from '@/base/scroll'
import Loading from '@/base/loading'

export default {
  components: {
    Slider,
    Scroll,
    Loading
  },
  // 定义属性
  data () {
    return {
      recommends: [],
      discList: [],
      singers: []
    }
  },
  async created () {
    const { banners } = await getBanner()   // 轮播图片
    console.log('get banner data!');
    const { result } = await getPersonalized()  // 热门歌单列表
    console.log('get personalized data');
    this.recommends = banners
    this.discList = result.slice(0, 10)
  },
  methods: {
    onload () {
      if (!this.isLoaded) {
        this.$refs.scroll.refresh()
        this.isLoaded = true
      }
    }
  },
  mounted () {

  },
}
</script>

<style lang='scss' scoped>
@import '~@/common/scss/const.scss';

.recommend {
  position: fixed;
  width: 100%;
  top: 84px;
  bottom: 0;
  .recommend-content {
    height: 100%;
    overflow: hidden;
    .slider-wrapper {
      width: 100%;
      overflow: hidden;
      position: relative;
    }
    .recomend-list {
      // text-align: center;
      .list-title {
        height: 45px;
        line-height: 45px;
        text-align: center;
        font-size: $font-size-medium;
        color: $color-theme;
      }
      .item {
        display: flex;
        box-sizing: border-box;
        align-items: center; // 水平居中
        padding: 0 15px 15px 15px;
        .icon {
          flex: 0 0 60px;
          width: 60px;
          padding-right: 20px;
        }
        .text {
          flex: 1;
          display: flex;
          flex-direction: column;
          justify-content: center; // 垂直居中
          line-height: 25px;
          overflow: hidden;
          font-size: $font-size-medium;
          .name {
            font-size: 16px;
            color: $color-text;
          }
          .desc {
            color: $color-text-d;
            font-size: 12px;
          }
        }
      }
    }
  }
  .loading-container {
    position: absolute;
    width: 100%;
    top: 50%;
    transform: translateY(-50%);
  }
}
</style>