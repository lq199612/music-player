<template lang=pug>
.singer
  keep-alive
    ListView(:singers='singers', v-if='singers')
</template>
<script>
import { getAllSinger } from '@/api'
import c2e from 'chinese2pinyin'  // chinese to english
import ListView from '@/base/listview'

export default {
  components: {
    ListView
  },
  // 定义属性
  data () {
    return {
      hotSinger: [],
      hotSingerlen: 10,
      singers: null
    }
  },
  async created () {
    const { artists } = await getAllSinger({ limit: 40 })
    this._setFirstIndex(artists)
    this.hotSinger = artists.slice(0, this.hotSingerlen)
    console.log('get hotSinger data!');
    this.singers = this._normalizeSinger(artists)  // 按首字母分类后的歌手名单
    console.log('get singers data!');
  },
  // 方法集合
  methods: {
    _setFirstIndex (artists) {
      artists.forEach(d => {
        const firstIndex = c2e({ cn: d.name[0], result: 'F' })
        d.firstIndex = firstIndex ? firstIndex : d.name[0].toLocaleUpperCase()

      })
    },
    _normalizeSinger (artists) {
      const singers = new Map()
      singers.set('hot', this.hotSinger)
      for (let i = 65; i < 91; i++) {
        singers.set(String.fromCharCode(i), [])
      }
      for (const singer of artists) {
        const firstIndex = singer.firstIndex
        if (singers.get(firstIndex) == undefined) {
          singers.set(firstIndex, [singer])
        }
        else {
          singers.get(firstIndex).push(singer)
        }
      }
      let delIndex = []
      for (const index of singers) {
        if (singers.get(index) == undefined) {
          delIndex.push(index)
        }
      }
      delIndex.forEach(d => { singers.delete(d) })
      return singers
    }
  },
  mounted () {

  },
}
</script>

<style lang='scss' scoped>
.singer {
  position: fixed;
  top: 84px;
  bottom: 0px;
  width: 100%;
}
</style>