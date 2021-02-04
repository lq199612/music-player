<template lang='pug'>
.App 
  Header 
  Tab
  keep-alive
    router-view
</template>

<script>
import Header from '@/components/m-header'
import Tab from '@/components/tab'

export default {
  name: 'App',
  components: {
    Header,
    Tab
  }
}
</script>

<style lang="scss" scoped>
// @import '~@/common/scss/const.scss';
// .app {
//   background: $color-background;
// }
</style>
