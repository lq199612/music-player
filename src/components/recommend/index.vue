<template lang=pug>
.recommend
  .recommend-content
    .slider-wrapper
    .recomend-list
      h1 热门歌单推荐
      ul 
</template>

<script>
import { getBanner } from '@/api'

export default {
  components: {
  },
  // 定义属性
  data () {
    return {
      banners: []
    }
  },
  async created () {
    const { banners } = await getBanner()
    this.banners = banners
    console.log('get banner data!');
  },
  methods: {
  },
  mounted () {

  },
}
</script>

<style lang='scss' scoped>
</style>