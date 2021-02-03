<template>
  <div class="tab">
    <router-link to='/recommend'
                 class="tab-item"
                 tag="div">
      <span class="tab-link">推荐</span>
    </router-link>
    <router-link to='/singer'
                 class="tab-item"
                 tag="div">
      <span class="tab-link"> 歌手</span>
    </router-link>
    <router-link to='/rank'
                 class="tab-item"
                 tag="div">
      <span class="tab-link">排行</span>
    </router-link>
    <router-link to='/search'
                 class="tab-item"
                 tag="div">
      <span class="tab-link">搜索</span>
    </router-link>
  </div>
</template>

<script>
export default {
  components: {
  },
  // 定义属性
  data () {
    return {

    }
  },
  computed: {
  },
  watch: {},
  // 方法集合
  methods: {

  },
  created () {

  },
  mounted () {

  }
}
</script>

<style lang='scss' scoped>
@import '~@/common/scss/const.scss';

.tab {
  height: 40px;
  line-height: 40px;
  font-size: $font-size-medium;
  display: flex;
  .tab-item {
    flex: 1;
    text-align: center;
    .tab-link {
      color: $color-text-l;
      padding-bottom: 4px;
    }
    &.router-link-active {
      .tab-link {
        color: $color-theme;
        border-bottom: 2px solid $color-theme;
      }
    }
  }
}
</style>