<template lang=pug>
.loading
  img(src='./loading.gif')
  p.desc {{ title }}
</template>
<script>
export default {
  components: {
  },
  props: {
    title: {
      type: String,
      default: "loading..."
    }
  }
}
</script>
<style lang='scss' scoped>
@import '~@/common/scss/const.scss';

.loading {
  width: 100%;
  text-align: center;
  img {
    width: 24px;
    height: 24px;
  }
  .desc {
    color: $color-text-l;
    line-height: 20px;
    font-size: $font-size-small;
  }
}
</style>