(() => {
 const m=document.querySelector('.menu-btn'),n=document.querySelector('.nav');
 if(m&&n)m.addEventListener('click',()=>n.classList.toggle('open'));
})();