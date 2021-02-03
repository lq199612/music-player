<template lang=pug>
.m-header
  .icon
  h1.text Chicken Music
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

  },
  beforeCreate () { }, // 生命周期 - 创建之前
  beforeMount () { }, // 生命周期 - 挂载之前
  beforeUpdate () { }, // 生命周期 - 更新之前
  updated () { }, // 生命周期 - 更新之后
  beforeDestroy () { }, // 生命周期 - 销毁之前
  destroyed () { }, // 生命周期 - 销毁完成
  activated () { }, // 如果页面有keep-alive缓存功能，这个函数会触发
}
</script>

<style lang='scss' scoped>
@import '~@/common/scss/const.scss';
@import '~@/common/scss/mymixin.scss';
.m-header {
  // position: relative;
  height: 44px;
  text-align: center;
  color: $color-theme;
  font-size: 0px;
  .icon {
    width: 30px;
    height: 32px;
    margin-top: 6px;
    margin-right: 9px;
    background-size: 30px 32px;
    vertical-align: top;
    display: inline-block;
    @include bg-image('logo');
  }
  .text {
    display: inline-block;
    font-size: $font-size-large;
    line-height: 44px;
  }
}
</style>