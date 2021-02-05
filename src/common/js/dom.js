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

export function getData(el, name, val){
		const prefix = 'data-';
		name = prefix + name 
		if(val) {
			return el.setAttribute(name, val)
		}
		else{
			return el.getAttribute(name)
		}
}