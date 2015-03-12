/************************************************************************************************************************************************************************************
INSTRUCTIONS FOR USAGE

To add a speaker:
put the image of the speaker in the "images/speaker/" folder

copy the following :
var YOUR_VARIABLE_NAME={
name : "NAME OF SPEAKER",
bio  : "SPEAKER BIO",
imgname  : "SPEAKER IMAGE NAME"
};


speakers[max]=YOUR_VARIABLE_NAME;
var total=NEW_TOTAL;


similarly for team page


*************************************************************************************************************************************************************************************/
$(document).ready(function(){

var Vmnpage = $('#main').html();                                    /***THIS PART TAKES IN THE CONTENT OF THE DIVS***/
var Vreg = $('#reg').html();
var abtPagecontent=$('#aboutPage').html();	      

//Vmnpage=$('main').html();
Vmnpage='<div id="main" class="page">'+Vmnpage+'</div>';

Vreg='<div id="reg" class="page">'+Vreg+'</div>';
//alert(Vmnpage);
$('#reg').html('');
$('#reg').removeClass('page');											 /***THIS PART SETS THE CONTENT OPF THE DIVS TO NULL AND REMOVES THE CLASS "page"***/

abtPagecontent='<div id="aboutPage" class="page">'+abtPagecontent+'</div>';
$('#aboutPage').html('');
$('#aboutPage').removeClass('page');


var speakers=new Array();
var speaker0={
name : "Sidin Vadukut",
bio  : 'A columnist, writer and blogger from India, he is the managing editor of Livemint.com-a financial daily. An engineer from NIT Trichy and an MBA from IIM-Ahmedabad, he has authored three books- "Dork: The Incredible Adventures of Robin '+"'"+'Einstein'+"'"+' Varghese", "God Save the Dork" and "Who let the Dork Out" which comprise the bestselling Dork trilogy. The books follow the consulting antics of Robin '+"'"+'Einstein'+"'"+' Varghese as he moves his way up the corporate ladder. Vadukut is acclaimed for his humorous style of writing, one that brings absurdity and deadpan expressions alive on paper.',
imgname  : "SidinVadukot.jpg"
};
var speaker1={
name : "Kamlesh Patel",
bio  : "Referred to as the pride of Baroda, Kamlesh Patel has gone against all odds and conquered his physical disability to become a brilliant dancer. Afflicted with polio in both legs since the tender age of five, his undying determination and willpower is a source of inspiration to many.  He is a living epitome of the fact that to dance you don't need hands, legs, costumes; all you need is passion and faith. He has done countless shows in India and abroad and is also the recipient of many notable awards.",
imgname  : "KamleshPatel.jpg"
};
var speaker2={
name : "Sumit Dagar",
bio  : 'Sumit Dagar is an interaction designer and a short film maker from New Delhi. He is extremely passionate about design.He is mostly known for his  Braille Phone Project, which is a haptic user interface baseddevice for visually impaired users. You can find out more about Sumit at <a href="http://www.dagar.me">www.dagar.me</a>',
imgname  : "SumitDagar.jpg"
};
var speaker3={
name : "Kanishka Sharma",
bio  : 'Kanishka Sharma is the first Indian to be trained at the Shaolin Temple Secular Disciple Union, Shaolin Temple, China. His love for Martial Arts drove him to quit his job at Reliance Industries and take the uncertain path of Shaolin.  Despite difficulties that would have forced many to quit, he carried on to learn seven forms of Martial Art: Kung Fu, Jeet Kune Do, Muay Thai, Police Kung Fu, Kung Fu To'+"'"+'a, Okinawa Karate and Pekiti Tirsia Kali. He went on to train several Bollywood stars like Shahrukh Khan, Akshay Kumar, Priyanka Chopra and Abhishek Bachchan in Martial Arts. He also acted in the Bollywood movie, Goal. He now trains a lot of people in Shaolin Kung Fu at his academy.',
imgname  : "KanishkaSharma.jpg"
};
var speaker4={
name : "Vasu Dixit",
bio  : 'Music is more than just a form of entertainment. It is a form of expression. We’ve seen numerous examples of this. From John Lennon’s Give Peace a Chance to Vande Mataram, written by Bankim Chandra Chattopadhyay, music has been known to change the way we look at the world. In the current age of music, where meaningless lyrics and Auto-tune has taken the front seat, some bands, like Swarathma, come across as a welcome change. With songs written to bring about social change, and music which takes you to a different world altogether, they are one of the top bands of the country. One cannot find any words to describe them. They are simply, Swarathma. Vasu Dixit, their lead vocalist will be a part of this year'+"'"+'s event.',
imgname  : "VasuDixit.jpg"
};
var speaker5={
name : "Harit Soni",
bio  : 'Harit Soni is the founder of Ecolibrium Energy, a company devoted to reducing energy wastage and efficiently using energy generated. He was named as one of the Top 35 innovators of the year 2012 by the prestigious MIT Technology Review. At Ecolibrium, Harit has led the development of indigenous smart grid technologies which enable us to monitor power generation and consumption in real time. Harit has overseen the installation of a smart grid in Gandhinagar, Gujarat and the real-time generation monitor­ing results have shown nearly 90 per­cent increase in the power harnessed',
imgname  : "HaritSoni.jpg"
};
var speaker6={
name : "Astha Kapoor",
bio  : 'A graduate from St. Stephens College, New Delhi and a postgraduate from the Institute of Social Studies, Netherlands, Astha is a social scientist and the youngest member of the Indian Planning commission. She helped write the 12th five year plan of India. Also, her work on the financial crisis and the Surat diamond industry was published in the book Developing Countries and the Financial Crisis by Edward Elger.',
imgname  : "AsthaKapoor.jpg"
};
var speaker7={
name : "Narendra Nayak",
bio  : 'Narendra Nayak is an eminent rationalist, sceptic and writer from Karnataka. He founded Dakshina Kannada Rationalist Association and has been working as its Secretary since 1976. He organized a body of more than 65 atheists, rationalists and humanists and formed a society called Federation of Indian Rationalist Associations and is currently serving as the national president of this association. An adversary of astrology and superstitions, he conducted about 2000 demonstrations to expose such beliefs reasoning them pure scientific facts. Featured in a myriad of television programs including the one on physical feats by the Discovery Channel, the show <i>Is It Real?</i> by National Geographic and <i>The Secret Swami</i> by the BBC, he is a close associate of the late Basava Premanand and carries his legacy forward.',
imgname  : "NarendraNayak.jpg"
};
speakers[0]=speaker0;
speakers[1]=speaker1;
speakers[2]=speaker2;
speakers[3]=speaker3;
speakers[4]=speaker4;
speakers[5]=speaker5;
speakers[6]=speaker6;
speakers[7]=speaker7;
var total=8;

var spkrArr=['<div id="speakers" class="page"><span class="pageTitle" >Speakers</span>',
			'<div class="speakerDiv"><img src="img/speakers/',/*speaker.jpg*/
			'" class="speakerImg',/*L*/
			'"><div class="speakerCont',/*L*/
			'"><span class="speakerName">',/*+speakers[0].name+*/
			'</span><span class="speakerBio more">',/*+speakers[0].name+*/
			'</span></div></div>',
			'</div>'];

if (total==0){
	var Vspkrs=spkrArr[0]+'<span class="noSpeaker">Coming Soon...</span>'+spkrArr[7];
}
else{	
	var Vspkrs=spkrArr[0];
	for(i=0;i<total;i++){

		var lorR="R";
		
		if((i%2)==0)
		{
			lorR="L";
		}

		Vspkrs=Vspkrs+spkrArr[1]+speakers[i].imgname+spkrArr[2]+lorR+spkrArr[3]+lorR+spkrArr[4]+speakers[i].name+spkrArr[5]+speakers[i].bio+spkrArr[6];
	}

	Vspkrs=Vspkrs+spkrArr[7];
}
/******************************************/

var Members=new Array();

member0={
	name:"Name",
	imgname:"img.jpg",
	bio:"Loreim Ipsum doler sit amet Ipsum doler sit amet."
};
member1={
	name:"Name",
	imgname:"img.jpg",
	bio:"Loreim Ipsum doler sit amet Ipsum doler sit amet."
};

member2={
	name:"Name",
	imgname:"img.jpg",
	bio:"Loreim Ipsum doler sit amet Ipsum doler sit amet."
};
member3={
	name:"Name",
	imgname:"img.jpg",
	bio:"Loreim Ipsum doler sit amet Ipsum doler sit amet."
};
member4={
	name:"Name",
	imgname:"img.jpg",
	bio:"Loreim Ipsum doler sit amet Ipsum doler sit amet."
};
member5={
	name:"Name",
	imgname:"img.jpg",
	bio:"Loreim Ipsum doler sit amet Ipsum doler sit amet."
};
member6={
	name:"Name",
	imgname:"img.jpg",
	bio:"Loreim Ipsum doler sit amet Ipsum doler sit amet."
};
member7={
	name:"Name",
	imgname:"img.jpg",
	bio:"Loreim Ipsum doler sit amet Ipsum doler sit amet."
};

Members[0]=member0;
Members[1]=member1;
Members[2]=member2;
Members[3]=member3;
Members[4]=member4;
Members[5]=member5;
Members[6]=member6;
Members[7]=member7;
var totMembers=8;

var teamPgCntnt='<div id="team" class="page"><div id="teamPageContent"><span class="pageTitle">Team</span>';

var temp=[
	'<div class="member"><img src="img/team/',/*member.jpg*/  /* "*/
	'"><span class="memberName">',/*name*/
	'</span><span class="memberBio">',/*Bio*/
	'</span></div>'
];
var temp2='<div class="member" style="clear:both;"><img src="img/team/';

for(i=0;i<totMembers;i++){

	if (i==0){
		teamPgCntnt=teamPgCntnt+temp2+Members[i].imgname+temp[1]+Members[i].name+temp[2]+Members[i].bio+temp[3];		
	}
	else{
		teamPgCntnt=teamPgCntnt+temp[0]+Members[i].imgname+temp[1]+Members[i].name+temp[2]+Members[i].bio+temp[3];
	}
}
teamPgCntnt=teamPgCntnt+'</div></div>';


/*********SPEAKERS LINK**********/
$("#speakersLink").click(function(){
	$("#contentArea").html(Vspkrs);


var showChar = 600;
	var ellipsestext = "...";
	var moretext = "more";
	var lesstext = "less";
	$('.more').each(function() {
		var content = $(this).html();

		if(content.length > showChar) {

			var c = content.substr(0, showChar);
			var h = content.substr(showChar-1, content.length - showChar);

			var html = c + '<span class="moreelipses">'+ellipsestext+'</span>&nbsp;<span class="morecontent"><span>' + h + '</span>&nbsp;&nbsp;<a href="#speakers" class="moreTag">'+moretext+'</a></span>';

			$(this).html(html);
		}

	});
	$(".moreTag").click(function(){
		if($(this).hasClass("less")) {
			$(this).removeClass("less");
			$(this).html(moretext);
		} else {
			$(this).addClass("less");
			$(this).html(lesstext);
		}
		$(this).parent().prev().toggle();
		$(this).prev().toggle();
		return false;
	});
	});

	$("#regLink").click(function(){
		$("#contentArea").html(Vreg);
	});

	$("#mainLink").click(function(){
		$("#contentArea").html(Vmnpage);
	});

	$("#teamLink").click(function(){
		$("#contentArea").html(teamPgCntnt);
	});

$("#aboutLink").click(function(){
		$("#contentArea").html(abtPagecontent);
	});

});



// $("regLink").click(function(){
//   $("contentArea").html('

/*<div id="speakers" class="page"><span class="pageTitle" >Speakers</span><div class="speakerDiv"><img src="img/speakers/speaker.jpg" class="speakerImgL"><div class="speakerContL"><span class="speakerName">'+speakers[0].name+'</span><span class="speakerBio more">'+speakers[0].name+'</span></div></div><div class="speakerDiv"><img src="img/speakers/speaker.jpg" class="speakerImgR"><div class="speakerContR"><span class="speakerName">Lorem Ipsum</span><span class="speakerBio more">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed tempor pulvinar dolor quis ornare. Sed erat enim, iaculis scelerisque euismod id, interdum sed urna. In luctus, lorem eu elementum porttitor, turpis augue egestas dui, ut tristique leo erat in turpis. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. In nunc nisl, tristique nec cursus vitae, feugiat eget leo. Aliquam iaculis adipiscing nibh vel posuere. Vivamus molestie accumsan augue. Maecenas arcu diam, auctor in semper sit amet, tempus eu leo. Praesent aliquam ligula eu odio suscipit ac interdum turpis sodales. Sed vel arcu tellus.<!-- <a class="moreTag" href="#" >...read more </a> --></span></div></div><div class="speakerDiv"><img src="img/speakers/speaker.jpg" class="speakerImgL"><div class="speakerContL"><span class="speakerName">Lorem Ipsum</span><span class="speakerBio more">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed tempor pulvinar dolor quis ornare. Sed erat enim, iaculis scelerisque euismod id, interdum sed urna. In luctus, lorem eu elementum porttitor, turpis augue egestas dui, ut tristique leo erat in turpis. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. In nunc nisl, tristique nec cursus vitae, feugiat eget leo. Aliquam iaculis adipiscing nibh vel posuere. Vivamus molestie accumsan augue. Maecenas arcu diam, auctor in semper sit amet, tempus eu leo. Praesent aliquam ligula eu odio suscipit ac interdum turpis sodales. Sed vel arcu tellus.<!-- <a class="moreTag" href="#" >...read more </a> --></span></div></div><div class="speakerDiv"><img src="img/speakers/speaker.jpg" class="speakerImgR"><div class="speakerContR"><span class="speakerName">Lorem Ipsum</span><span class="speakerBio more">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed tempor pulvinar dolor quis ornare. Sed erat enim, iaculis scelerisque euismod id, interdum sed urna. In luctus, lorem eu elementum porttitor, turpis augue egestas dui, ut tristique leo erat in turpis. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. In nunc nisl, tristique nec cursus vitae, feugiat eget leo. Aliquam iaculis adipiscing nibh vel posuere. Vivamus molestie accumsan augue. Maecenas arcu diam, auctor in semper sit amet, tempus eu leo. Praesent aliquam ligula eu odio suscipit ac interdum turpis sodales. Sed vel arcu tellus.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed tempor pulvinar dolor quis ornare. Sed erat enim, iaculis scelerisque euismod id, interdum sed urna. In luctus, lorem eu elementum porttitor, turpis augue egestas dui, ut tristique leo erat in turpis. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. In nunc nisl, tristique nec cursus vitae, feugiat eget leo. Aliquam iaculis adipiscing nibh vel posuere. Vivamus molestie accumsan augue. Maecenas arcu diam, auctor in semper sit amet, tempus eu leo. Praesent aliquam ligula eu odio suscipit ac interdum turpis sodales. Sed vel arcu tellus.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed tempor pulvinar dolor quis ornare. Sed erat enim, iaculis scelerisque euismod id, interdum sed urna. In luctus, lorem eu elementum porttitor, turpis augue egestas dui, ut tristique leo erat in turpis. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. In nunc nisl, tristique nec cursus vitae, feugiat eget leo. Aliquam iaculis adipiscing nibh vel posuere. Vivamus molestie accumsan augue. Maecenas arcu diam, auctor in semper sit amet, tempus eu leo. Praesent aliquam ligula eu odio suscipit ac interdum turpis sodales. Sed vel arcu tellus.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed tempor pulvinar dolor quis ornare. Sed erat enim, iaculis scelerisque euismod id, interdum sed urna. In luctus, lorem eu elementum porttitor, turpis augue egestas dui, ut tristique leo erat in turpis. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. In nunc nisl, tristique nec cursus vitae, feugiat eget leo. Aliquam iaculis adipiscing nibh vel posuere. Vivamus molestie accumsan augue. Maecenas arcu diam, auctor in semper sit amet, tempus eu leo. Praesent aliquam ligula eu odio suscipit ac interdum turpis sodales. Sed vel arcu tellus.</span></div></div><div class="speakerDiv"><img src="img/speakers/speaker.jpg" class="speakerImgL"><div class="speakerContL"><span class="speakerName">Lorem Ipsum</span><span class="speakerBio more">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed tempor pulvinar dolor quis ornare. Sed erat enim, iaculis scelerisque euismod id, interdum sed urna. In luctus, lorem eu elementum porttitor, turpis augue egestas dui, ut tristique leo erat in turpis. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. In nunc nisl, tristique nec cursus vitae, feugiat eget leo. Aliquam iaculis adipiscing nibh vel posuere. Vivamus molestie accumsan augue. Maecenas arcu diam, auctor in semper sit amet, tempus eu leo. Praesent aliquam ligula eu odio suscipit ac interdum turpis sodales. Sed vel arcu tellus.<!-- <a class="moreTag" href="#" >...read more </a> --></span></div></div><div class="speakerDiv"><img src="img/speakers/speaker.jpg" class="speakerImgR"><div class="speakerContR"><span class="speakerName">Lorem Ipsum</span><span class="speakerBio more">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed tempor pulvinar dolor quis ornare. Sed erat enim, iaculis scelerisque euismod id, interdum sed urna. In luctus, lorem eu elementum porttitor, turpis augue egestas dui, ut tristique leo erat in turpis. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. In nunc nisl, tristique nec cursus vitae, feugiat eget leo. Aliquam iaculis adipiscing nibh vel posuere. Vivamus molestie accumsan augue. Maecenas arcu diam, auctor in semper sit amet, tempus eu leo. Praesent aliquam ligula eu odio suscipit ac interdum turpis sodales. Sed vel arcu tellus.<!-- <a class="moreTag" href="#" >...read more </a> --></span></div></div><div class="speakerDiv"><img src="img/speakers/speaker.jpg" class="speakerImgL"><div class="speakerContL"><span class="speakerName">Lorem Ipsum</span><span class="speakerBio more">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed tempor pulvinar dolor quis ornare. Sed erat enim, iaculis scelerisque euismod id, interdum sed urna. In luctus, lorem eu elementum porttitor, turpis augue egestas dui, ut tristique leo erat in turpis. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. In nunc nisl, tristique nec cursus vitae, feugiat eget leo. Aliquam iaculis adipiscing nibh vel posuere. Vivamus molestie accumsan augue. Maecenas arcu diam, auctor in semper sit amet, tempus eu leo. Praesent aliquam ligula eu odio suscipit ac interdum turpis sodales. Sed vel arcu tellus.<!-- <a class="moreTag" href="#" >...read more </a> --></span></div></div><div class="speakerDiv"><img src="img/speakers/speaker.jpg" class="speakerImgR"><div class="speakerContR"><span class="speakerName">Lorem Ipsum</span><span class="speakerBio more" >Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed tempor pulvinar dolor quis ornare. Sed erat enim, iaculis scelerisque euismod id, interdum sed urna. In luctus, lorem eu elementum porttitor, turpis augue egestas dui, ut tristique leo erat in turpis. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. In nunc nisl, tristique nec cursus vitae, feugiat eget leo. Aliquam iaculis adipiscing nibh vel posuere. Vivamus molestie accumsan augue. Maecenas arcu diam, auctor in semper sit amet, tempus eu leo. Praesent aliquam ligula eu odio suscipit ac interdum turpis sodales. Sed vel arcu tellus.<!-- <a class="moreTag" href="#" >...read more </a> --></span></div></div></div>
*/