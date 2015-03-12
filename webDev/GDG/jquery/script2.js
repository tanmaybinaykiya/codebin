// JavaScript Document
// var object = new Image();
var i=0;
// function load()
// {
	
// // 	var i=0;
// // 	var canvas = new fabric.Canvas('MainCanvas');
// }
function allowDrop(ev)
{
	ev.preventDefault();
}

function drag(ev)
{
	// console.log("in drag");
	ev.dataTransfer.setData("Text",ev.target.id);
}

function drop(ev)
{
	console.log("in drop");
	ev.preventDefault();
	var data=document.getElementById(ev.dataTransfer.getData("Text")).getAttribute('src');
	object.src = data.toString();
//	alert(data.toString());ondrop="drop(event)"ondragover="allowDrop(event)"
	//document.getElementById("MainCanvas").setAttribute(ondrop,"drop(event)");
	//document.getElementById("MainCanvas").setAttribute(ondragover,"allowDrop(event)");
	
//context.drawImage(object,0,0);
main();

}



function main()
{
	//var canvas2=document.getElementById('MainCanvas');

	//images=['images/1.svg','images/2.svg','images/3.svg','images/4.svg','images/5.svg','images/6.svg','images/7.svg'];
	// alert(object.src);
	// alert("th time");
	if(i==0){
	var canvas = new fabric.Canvas('MainCanvas');}
	fabric.loadSVGFromURL(object.src, function(objects) {

  		var obj = objects[0].scale(0.5);
  		canvas.centerObject(obj);
		  canvas.add(obj);
		  obj.lockRotation = true;
		  // alert(i);
		// i++;
		// var obj2=obj.clone();
		  // canvas.add(obj2.set({ left: 100, top: 100, angle: -15 }));
		  // canvas.add(obj.clone().set({ left: 480, top: 100, angle: 15 }));
		  //canvas.add(obj.clone().set({ left: 100, top: 400, angle: -15 }));
		  //canvas.add(obj.clone().set({ left: 480, top: 400, angle: 15 }));
		
		// canvas.on('mouse:move', function(options) {
		
		// var p = canvas.getPointer(options.e);
		
		// canvas.forEachObject(function(obj) {
		// 	var distX = Math.abs(p.x - obj.left),
		// 	distY = Math.abs(p.y - obj.top),
		// 	dist = Math.round(Math.sqrt(Math.pow(distX, 2) + Math.pow(distY, 2)));
		// 	obj.setOpacity(1 / (dist / 20));
		// 	});

  //   	canvas.renderAll();
  // 		});

});	
	
	fabric.loadSVGFromURL('images/media.svg', function(objects) {

  var obj = objects[0].scale(0.25);
  canvas.centerObject(obj);
  canvas.add(obj);

  // canvas.add(obj.clone().set({ left: 10, top: 10, angle: 0 }));
  // canvas.add(obj.clone().set({ left: 48, top: 10, angle: 0 }));
  // canvas.add(obj.clone().set({ left: 10, top: 40, angle: 0 }));
  // canvas.add(obj.clone().set({ left: 48, top: 400, angle: 0 }));

  // canvas.on('mouse:move', function(options) {

  //   var p = canvas.getPointer(options.e);

  //   canvas.forEachObject(function(obj) {
  //     var distX = Math.abs(p.x - obj.left),
  //         distY = Math.abs(p.y - obj.top),
  //         dist = Math.round(Math.sqrt(Math.pow(distX, 2) + Math.pow(distY, 2)));

  //     obj.setOpacity(1 / (dist / 20));
  //   });

    // canvas.renderAll();
  // });
});
	
}
