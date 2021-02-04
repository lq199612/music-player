<template lang=pug>
.recommend
  .recommend-content
    .slider-wrapper(v-if='recommends.length')
      Slider
        div(v-for='item in recommends')
          img(:src='item.imageUrl')

    .recomend-list
      h1.list-title 热门歌单推荐
      ul
        li.item(v-for='item in discList')
          .icon
            img(width='60', height='60', :src='item.picUrl')
          .text
            h2.name {{ item.copywriter }}
            p.desc  {{ item.name }} 
</template>

<script>
import { getBanner, getPersonalized } from '@/api'
import Slider from '@/base/slider'

export default {
  components: {
    Slider
  },
  // 定义属性
  data () {
    return {
      recommends: [],
      discList: [],
    }
  },
  async created () {
    const { banners } = await getBanner()   // 轮播图片
    const { result } = await getPersonalized()  // 热门歌单列表
    this.recommends = banners
    this.discList = result
    console.log('get banner data!');
    console.log('his.discList :', this.discList);
  },
  methods: {
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
        align-items: center;  // 水平居中
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
          justify-content: center;  // 垂直居中
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
}
</style>