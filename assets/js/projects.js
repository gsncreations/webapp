
const GSN_PROJECTS = [
 {title:"ESP32 OLED Song Animation",category:"ESP32",tags:["ESP32","OLED","Animation"],desc:"Play custom monochrome animations on a 0.96-inch SSD1306 OLED.",icon:"◈"},
 {title:"Fire Alarm with OLED",category:"Arduino",tags:["Arduino","OLED","Sensor"],desc:"Flame sensor with buzzer and OLED fire alarm status display.",icon:"⚠"},
 {title:"DINO OLED Game",category:"ESP32",tags:["ESP32","OLED","Game"],desc:"A simple OLED game using a button and a 0.96-inch display.",icon:"◆"},
 {title:"MQ Sensor Detector",category:"Sensors",tags:["ESP32","Sensor","OLED"],desc:"Sensor readings and status animations on a compact OLED display.",icon:"◎"},
 {title:"Mechanical 7-Segment Display",category:"Arduino",tags:["Servo","PCA9685","Display"],desc:"Multi-servo mechanical digits with controlled sequential movement.",icon:"▦"},
 {title:"Solar Tracking Prototype",category:"Arduino",tags:["Solar","Servo","Sensor"],desc:"A cardboard-friendly solar tracker prototype for school projects.",icon:"☀"}
];

function projectCard(p){
 return `<article class="project-card">
   <div class="project-thumb">${p.icon}</div>
   <div class="project-meta">${p.tags.map(t=>`<span class="tag">${t}</span>`).join("")}</div>
   <h3>${p.title}</h3><p>${p.desc}</p>
   <a class="text-link" href="projects.html">View project →</a>
 </article>`;
}
function renderProjects(target, list){ if(target) target.innerHTML=list.map(projectCard).join(""); }
document.addEventListener("DOMContentLoaded",()=>{
 renderProjects(document.getElementById("featuredProjects"),GSN_PROJECTS.slice(0,3));
 const all=document.getElementById("allProjects");
 if(all){
   const search=document.getElementById("searchProjects"), filter=document.getElementById("categoryFilter");
   const run=()=>{const q=(search?.value||"").toLowerCase(), c=filter?.value||"";
     renderProjects(all,GSN_PROJECTS.filter(p=>(!q||(`${p.title} ${p.desc} ${p.tags.join(" ")}`).toLowerCase().includes(q))&&(!c||p.category===c)));
   };
   search?.addEventListener("input",run); filter?.addEventListener("change",run); run();
 }
});
