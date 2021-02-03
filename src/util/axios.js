import axios from 'axios'

const BASE_URL = 'https://api.mtnhao.com/'
export const request = createBaseInstance()

function  createBaseInstance() {
		const instance = axios.create({
			baseURL: BASE_URL,
		})
		instance.interceptors.response.use(handleResponse, handleError)
		return instance
}

function  handleError(e) {
		throw e
}

function  handleResponse(response) {
		return response.data
}