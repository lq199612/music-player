import {request} from '@/util'
import {getAllSingerDefautParams} from './defautParams'

export const getAllSinger = params => request.get('/artist/list',{ params:Object.assign(getAllSingerDefautParams, params) })

