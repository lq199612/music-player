import {request} from '@/util'

export const getAblum = id => request.get(`/album?id=${id}`)