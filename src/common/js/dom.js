export function addClass(dom, className){
	if(hasClass(dom, className)) return
	let newClass = dom.className.split(' ')
	newClass.push(className)
	dom.className = newClass.join(' ')
}

export function hasClass(dom, className){
		let reg = new RegExp('(^|\\s)'+className+'(\\s|$)')
		if(dom.className == '') return false
		return reg.test(dom.className)
}