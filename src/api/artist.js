import {request} from '@/util'

export const getArtist = id => request.get(`/artists?id=${id}`)

