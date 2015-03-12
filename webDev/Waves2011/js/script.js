function timeHide() {
    $('#timer').css('display','none');
    $('.close').css('display','none');
    $('#cntdwn').css('display','none');
    return;
}
function timeShow() {
    $('#timer').css('display','block');
    $('.close').css('display','block');
    $('#cntdwn').css('display','block');
    return;
}

$(window).load(function(){
    $("body").css("background-image","url('img/gradient.png')")
    $("#container").show();
    $("#loader").hide();
    
    setInterval(function() {
        $("#lights").toggle();
    }, 1000);
		
    /***
 *-------------------SCROLLING functions------------------------*
 ***/

    $.scrollTo( $('#home'), 1 );
    $('.homenav').click(function(){
        $.scrollTo( $('#home'), 800 );
        timeShow();
    });
    $('.returnhome').click(function(){
        $.scrollTo( $('#home'), 800 );
        timeShow();
    });
    $('.eventsnav').click(function(){
        $.scrollTo( $('#events'), 800 );
        timeHide();
		$(".textarea").html("<h1>The Events</h1><p>Kick up your heels. Conjure up a storm. Whet your inquisitiveness. Unleash the Bard within. All the world's a stage, it calls upon you to perform. Witness the coming together of the false Gods of the performing arts. Prove your mettle against the very finest. Or simply take pot-shots at your friends' making a laughingstock of themselves. An eclectic mix of dazzling events awaits you this Waves, brace yourselves.</p>");
    });
    $('.specialsnav').click(function(){
        $.scrollTo( $('#specials'), 800 );
        timeHide();
    });

    $('.workshopsnav').click(function(){
        $.scrollTo( $('#workshops'), 800 );
        timeHide();
    });
    $('.nitesnav').click(function(){
        $.scrollTo( $('#nites'), 800 );
				
        for (var i=0;i<50;i++)
        {
            $('#nitefish1').animate({
                top: '-=50'
            }, 7000, function() {
                // Animation complete.
                });
            $('#nitefish1').animate({
                top: '+=50'
            }, 6000, function() {
                // Animation complete.
                });
            $('#nitefish2').animate({
                top: '+=50'
            }, 11000, function() {
                // Animation complete.
                });
            $('#nitefish2').animate({
                top: '-=50'
            }, 9000, function() {
                // Animation complete.
                });
        };
        timeHide();
    });
    $('.informalsnav').click(function(){
        $.scrollTo( $('#informals'), 800 );
        timeHide();
    });

    $('.contactnav').click(function(){
        $.scrollTo( $('#contact'), 800 );
        timeHide();
		
		
        /*Animations for Contacts Page*/
		
        for (var i=0;i<200;i++)
        {
            $('#scuba').animate({
                left: '+=50',
                top: '-=50'
            }, 10000, function() {
                // Animation complete.
                });
            $('#scuba').animate({
                left: '+=50',
                top: '+=50'
            }, 10000, function() {
                // Animation complete.
                });
            $('#scuba').animate({
                left: '-=50',
                top: '-=50'
            }, 10000, function() {
                // Animation complete.
                });
            $('#scuba').animate({
                left: '-=50',
                top: '+=50'
            }, 10000, function() {
                // Animation complete.
                });
        };
		
    });

    //On page load, cloud animations
    
    for (var i=0;i<50;i++)
    {
        $('.a1').animate({
            left: '-=80',
            top: '+=95'
        }, 20000, function() {
            // Animation complete.
            });
        $('.a1').animate({
            left: '+=52',
            top: '-=103'
        }, 17000, function() {
            // Animation complete.
            });
    };
    for (var i=0;i<50;i++)
    {
        $('.a2').animate({
            left: '+=70',
            top: '-=110'
        }, 14000, function() {
            // Animation complete.
            });
        $('.a2').animate({
            left: '-=130',
            top: '+=120'
        }, 11000, function() {
            // Animation complete.
            });
    };


    $('.sponsorsnav').click(function(){
        $.scrollTo( $('#sponsors'), 800 );
				
        /***
     *------------------SPONSORS PAGE CODE(Should be inside Scrollto Function, animation starts when the Frame is loaded)---------------------------*
     ***/
        for (var i=0;i<50;i++)
        {
            $('#fz').animate({
                top: '-=100'
            }, 12000, function() {
                // Animation complete.
                });
            $('#fz').animate({
                top: '+=100'
            }, 15000, function() {
                // Animation complete.
                });
        };
        for (var i=0;i<50;i++)
        {
            $('#f1').animate({
                top: '-=100'
            }, 20000, function() {
                // Animation complete.
                });
            $('#f1').animate({
                top: '+=100'
            }, 20000, function() {
                // Animation complete.
                });
        };
        for (var i=0;i<50;i++)
        {
            $('#f2').animate({
                left: '-=600'
            }, 500000, function() {
                // Animation complete.
                });
            $('#f2').animate({
                left: '+=600'
            }, 500000, function() {
                // Animation complete.
                });
        };

        for (var i=0;i<50;i++)
        {
            $('#f5').animate({
                left: '-=100',
                top: '-=100'
            }, 30000, function() {
                // Animation complete.
                });
            $('#f5').animate({
                left: '+=100',
                top: '+=100'
            }, 30000, function() {
                // Animation complete.
                
                });

        };

	
    });

    $('.registernav').click(function(){
        $.scrollTo( $('#registration'), 800 );
		
        /*Animations for Registration Page*/
		
        for (var i=0;i<50;i++)
        {
            $('#regfish1').animate({
                top: '-=50'
            }, 7000, function() {
                // Animation complete.
                });
            $('#regfish1').animate({
                top: '+=50'
            }, 6000, function() {
                // Animation complete.
                });
            $('#regfish2').animate({
                top: '+=50'
            }, 11000, function() {
                // Animation complete.
                });
            $('#regfish2').animate({
                top: '-=50'
            }, 9000, function() {
                // Animation complete.
                });
        };
    });
});





$(document).ready(function(){
    $("#container").hide();
    
    $("#loader").show();

    
    /***
     *----------------------MENU CODE------------------------*
     ***/
    $('#menubigfour').css("display","none");
    $('#menuliterary').css("display","none");
    $('#menukala').css("display","none");
    $('#menuquiz').css("display","none");
    $('#menudance').css("display","none");
    $('#menumusic').css("display","none");
    $('#menudrama').css("display","none");
    $('#menumisc').css("display","none");
    $('#bigfour').click(function(){
        $("#menuevents").css("display","none");
        $("#menubigfour").css("display","block");
    });
    $('#literary').click(function(){
        $("#menuevents").css("display","none");
        $("#menuliterary").css("display","block");
    });
    $('#kala').click(function(){
        $("#menuevents").css("display","none");
        $("#menukala").css("display","block");
    });
    $('#quiz').click(function(){
        $("#menuevents").css("display","none");
        $("#menuquiz").css("display","block");
    });
    $('#dance').click(function(){
        $("#menuevents").css("display","none");
        $("#menudance").css("display","block");
    });
    $('#music').click(function(){
        $("#menuevents").css("display","none");
        $("#menumusic").css("display","block");
    });
    $('#drama').click(function(){
        $("#menuevents").css("display","none");
        $("#menudrama").css("display","block");
    });
    $('#misc').click(function(){
        $("#menuevents").css("display","none");
        $("#menumisc").css("display","block");
    });
    $('.menuitem').click(function(){
        
        var event = $(this).attr('id');
        
        var category = $(this).parent().parent().parent().parent().attr('id');
		
		var check = $(this).attr('class');
        
        category = category.substr(4);
		
		if (event!="homeitem" && check!="menuitem events") {
			$(".textarea").html("<img src='img/ajax-loader.gif'/>");
		}
		else if (event=="homeitem") {
		$(".textarea").html("<h1>The Events</h1><p>Kick up your heels. Conjure up a storm. Whet your inquisitiveness. Unleash the Bard within. All the world's a stage, it calls upon you to perform. Witness the coming together of the false Gods of the performing arts. Prove your mettle against the very finest. Or simply take pot-shots at your friends' making a laughingstock of themselves. An eclectic mix of dazzling events awaits you this Waves, brace yourselves.</p>");
		}        
        $.getJSON('js/events.json', function(json) {
             $.each(json.events, function(key, val) {
                    
                if(val.name.search(event) !=-1 && val.category.search(category)!=-1){
                    $(".textarea").html("<h1>"+val.title+"</h1><p>"+val.content+"</p>");
                }
            });
            
        });
    });
    
    $('.events').click(function(){
        
        $(this).parent().parent().parent().parent().css("display","none");
        
        $("#menuevents").css("display","block");
    });
    $('#homeitem').click(function(){
        $.scrollTo( $('#home'), 800 );
    });
    $('.eventsmenu').mobilyblocks({
        trigger: 'hover',
        direction: 'counter',
        duration:600,
        zIndex:50,
        widthMultiplier:1.3
    });
    /*$(".eventsmenu").css("width","270px").css("height","270px");
	$(".eventsmenu").click(function(){
        $(this).css("background","url(img/smitem.png) no-repeat").css("width","130px").css("height","130px");
    }).dblclick(function(){
        $(this).css("background","url(img/mitem.png) no-repeat").css("width","270px").css("height","270px");
    });*/

    /*********************Workshop flicker****************************/
    setInterval(function() {
        $("#light").toggle();
    }, 1000);
    
    
    
    
    
    
    
    
    
    /***
 *-------------------REGISTRATION CODE----------------------------*
 ***/
    
    $("#logout").css("display","none");
    $("#User-Info").css("display","none");
    $("#accomodation").css("display","none");
    $("#accomodation-instructions").css("display","none");
    $("#register-button").click(function(){
        var email = $("#register-email").val();
        var password = $("#register-password").val();
        var confirm_password = $("#register-confirm-password").val();
        var mobile = $("#mobile").val().replace(/^0+/, '');
        var name = $("#name").val();
        var college = $("#college").val();
					
        var urltext="register.php?email="+email+"&password="+password+"&mobile="+mobile+"&college="+college+"&name="+name+"&confirm_password="+confirm_password;
	
        $("#register-form .notification").html("We're verifying your details, give us a few seconds.");
        htmlobj=$.ajax({
            url:urltext,
            async:false,
            success:function(){}
        });
		

        if(htmlobj.responseText=="mailsent"){
            /*			$("#register-form").css("display","none");
			$("#Email-Notifier").html("");
			$("#Email-Notifier").css("display","none");*/
            $("#register-form .notification").html("We've sent you an e-mail to confirm your registration. Check your inbox!" );
			
            // clear all the fields
            $("#register-form input:text, #register-form input:password").each(function() {
                $(this).val(null);
                $(this).focus();
            });
        //			$("#register-form form label").inFieldLabels();
        }
        else {
            //$("#register-form").html(htmlobj.responseText);
            $("#register-form .notification").text(htmlobj.responseText);
        }
        $("#register-form #name").focus();
    });
        
    $("#login-button").click(function(){
        var login_email = $("#login-email").val();
        var login_password = $("#login-password").val();
        var urltext="login.php?email="+login_email+"&password="+login_password;
		
        $("#login-form .notification").html("Logging In...").fadeTo(0.93);
        htmlobj=$.ajax({
            url:urltext,
            async:false
        });
	
        if(htmlobj.responseText=="logged_in"){
            logged_in = true;
            $("#login-form .notification").hide();
            $('#footer-nav').animate({
                'height': 567,
                'opacity': 0.95
            }, 1500, 'easeOutElastic');
            logged_in_pop();
        }
        else {
            $("#login-form .notification").html(htmlobj.responseText);
        }
    });
        
    $("#logout").click(function(){
        var urltext="logout.php";
        logged_in = false;
        htmlobj=$.ajax({
            url:urltext,
            async:false
        });
        $('#footer-nav').animate({
            'height': 415,
            'opacity': 0.95
        }, 1500, 'easeOutElastic');
        logged_out_pop();
    });


    function loginpop(){
        if (logged_in) footer_height = 567;
        else footer_height = 415;
        $('#footer-nav').animate({
            'height': footer_height,
            'opacity': 0.95
        }, 1500, 'easeOutElastic');
        $('.bottom-content').not('#login-register').fadeOut("fast");
        $('#footer-nav').css('z-index', '250');
        //$('#sponsors').css('bottom', '-300px');
        $('#login-register').fadeIn("fast");
        if (logged_in) $('#accomodation').fadeIn("fast");
        $('#close-panel').show('fast');
    }
        
    function getuserdata(action){
        var urltext="userdata.php?action="+action;
        $("#User-Info").html("Loading user info...");
        htmlobj=$.ajax({
            url:urltext,
            async:false,
            success: function() {
                $("#User-Info").html("");
            }
        });
        return htmlobj.responseText;
    }
        
    function logged_in_message() {
        return ("<br/><h1>Welcome, "+getuserdata("name").split(" ")[0]+"</h1><p>This control panel will allow give you accommodation registration options. </p><h1>Accomodation</h1>");
    }
        
    function logged_in_pop()
    {
        logged_in = true;
        $("#login-form").css("display","none");
        $("#register-form").css("display","none");
        $("#User-Info").html(logged_in_message());
        $("#User-Info").css("display","block");
        $("#accomodation").fadeIn("fast");
        $("#logout").css("display","block");
        createUploader();
    }
        
    function logged_out_pop() {
        logged_in = false
        $("#login-form").css("display","block");
        $("#logout").css("display","none");
        $("#User-Info").css("display","none");
        $("#User-Info").html("");
        $("#accomodation").css("display","none");
        $("#register-form").css("display","block");
    }
        
        
    function getevents() {
        var urltext="events_listing.php";
        htmlobj=$.ajax({
            url:urltext,
            async:false
        });
        return htmlobj.responseText;
    }
        
    var focussed_id; //ID of the focussed date field
        
    //Accomodation Form
    $("#arrival_date, #departure_date").focus(function() {
        var bottom = $(this).offset().top - 2 * $("#datepicker").height();
        var left = $(this).offset().left;
        focussed_id = "#" + $(this).attr('id');
        $("#datepicker").css({
            'top': top, 
            'left': left
        });
        $("#datepicker").fadeIn("fast");
    });
        
    $("#arrival_date, #departure_date").blur(function() {
        $("#datepicker").fadeOut("fast");
    });
        
    var arrival_date = "";
    var departure_date = "";
    var validated_accomodation = true;
        
    $("#datepicker a").click(function() {
        var date = $(this).html();
            
        if (focussed_id == "#arrival_date") {
            if (date == "17") {
                $("#accomodation-form .notification").html("Rejected selected date range.");
                return;
            }
            if (!(isNaN(departure_date))) {
                if (parseInt(departure_date) < parseInt(date)) {
                    $("#accomodation-form .notification").html("Rejected selected date range.");
                    return;
                }
            }
            //$(focussed_id).siblings("label").html("");
            $("#accomodation-form .notification").html("");
            $(focussed_id).val("November " + date + ", 2011");
            arrival_date = $("#arrival_date").val().split(" ")[1].split(",")[0];
        }
            
        else {
            if (date == "13") {
                $("#accomodation-form .notification").html("Rejected selected date range.");
                return;
            }
            if (!(isNaN(arrival_date))) {
                if (parseInt(arrival_date) > parseInt(date)) {
                    $("#accomodation-form .notification").html("Rejected selected date range.");
                    return;
                }
            }
            //$(focussed_id).siblings("label").html("");
            $("#accomodation-form .notification").html("");
            $(focussed_id).val("November " + date + ", 2011");
            departure_date = $("#departure_date").val().split(" ")[1].split(",")[0];
        }
    });
        
    function validateNumbers(val) {
        if (isNaN(val)) {
            validated_accomodation = false;
            $("#accomodation-form .notification").html("We require positive integral numbers.");
        }
    }
        
    function checkBlanks(){
        if ($("#departure_date").val() == "" || $("#arrival_date").val() == "" || $("#num_boys").val() == "" || $("#num_girls").val() == "") {
            $("#accomodation-form .notification").html("You've missed a few fields.");
            validated_accomodation = false;
        }
    }
        
    var uploaded = false;
    var register_clickable = true;
        
    $("#acco-button").click(function() {
        if (!register_clickable) return;
            
        validated_accomodation = true;
        checkBlanks();
        validateNumbers($("#num_boys").val());
        validateNumbers($("#num_girls").val());
        if (!uploaded) {
            $("#accomodation-form .notification").html("You've not uploaded your travel proof.");
            return;
        }
        if (validated_accomodation) {
            $("#accomodation-form .notification").html("Give us a few seconds...");
                
            departure_date = $("#departure_date").val().split(" ")[1].split(",")[0];
            arrival_date = $("#arrival_date").val().split(" ")[1].split(",")[0];

            //get vars
            var boys = $("#num_boys").val();
            var girls = $("#num_girls").val();

            //url for get request
            var urltext2="accomodation_registration.php?boys="+boys+"&girls="+girls+"&arrival="+arrival_date+"&depart="+departure_date;
            htmlobj=$.ajax({
                url:urltext2,
                async:false,
                success:function(){}
            });

            //responses : possible four as follows
            if(htmlobj.responseText=="registration_successful"){
                $("#accomodation-form .notification").html("You've been added to the accommodation waitlist.");

            }
            else if(htmlobj.responseText=="not_registered")
            {
                $("#accomodation-form .notification").html("Travel proof is required.");
            }
            else if(htmlobj.responseText=="already_registered")
            {
                $("#accomodation-form .notification").html("You've already registered for accommodation.");
            }
            else $("#accomodation-form .notification").html("Network Error.");
        }
    });
        
    $("#instructions-button").click(function() {
        $("#accomodation").hide();
        $(".acco-instructions").not("#main").hide();
        $("#accomodation-instructions, #main").fadeIn("fast");
    });
        
    $("#instructions-close-button").click(function() {
        $("#accomodation").fadeIn("fast");
        $("#accomodation-instructions").hide();
    });
        
    $("#acco-top-tabs a").click(function() {
        var tabID = "#" + $(this).attr('id').split("-")[0];
        $(".acco-instructions").not(tabID).hide();
        $(tabID).fadeIn("fast");
    });



    
    function createUploader(){
        var uploader = new qq.FileUploader({
            element: document.getElementById("file-uploader"),
            allowedExtensions: ['jpg', 'jpeg'],
            sizeLimit: 1048576,
            onSubmit: function(id, fileName){
                $("#accomodation-form .notification").html("Uploading Travel Proof...");
                register_clickable = false;
            },
            onComplete: function(id, fileName, responseJSON){
                $("#accomodation-form .notification").html("Upload successful.");
                uploaded = true;
                register_clickable = true;
            },
            showMessage: function(message){
                $("#accomodation-form .notification").html(message);
            },
            action: 'upload.php'
        });
    }

    /*********************************MENU ITEM MOVEMENT COD*****************************************************/

    /* Animation code needs to be hardcoded with position. Relative values dont work because many a times, if the event end is not triggered, the animations keeps getting bigger and bigger
$("#birdfeather").animate({
			left: '3760px',
			}, 1200); // this value of "200" is the speed of how fast/slow this hover animates


	} , function() {
		.animate({
			left: '1px',
			}, 1400);



});
*/

    $("#eventspic").hover(function() {
        $(this).css({
            'z-index' : '10'
        }); //Add a higher z-index value so this image stays on top
        $(this).addClass("hover").stop() // Add class of "hover", then stop animation queue buildup
        .animate({
            top: '313px',
            left: '760px',
            width: '51px', // Set new width
            height: '141px' // Set new height
        }, 200); // this value of "200" is the speed of how fast/slow this hover animates

    } , function() {
        $(this).css({
            'z-index' : '0'
        }); // Set z-index back to 0
        $(this).removeClass("hover").stop()  // Remove the "hover" class , then stop animation queue buildup
        .animate({
            top: '318px',
            left: '762px',
            width: '47px', // Set width back to default
            height: '135px' // Set height back to default
        }, 400);


    });
    $("#contactpic").hover(function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $(this).addClass("hover").stop()
        .animate({
            top: '344px',
            left: '822px',
            width: '64px',
            height: '69px'
        }, 200);

    } , function() {
        $(this).css({
            'z-index' : '0'
        });
        $(this).removeClass("hover").stop()
        .animate({
            top: '346px',
            left: '826px',
            width: '56px',
            height: '63px'
        }, 400);
    });

    $("#sponsorspic").hover(function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $(this).addClass("hover").stop()
        .animate({
            top: '381px',
            left: '894px',
            width: '105px',
            height: '91px'
        }, 200);

    } , function() {
        $(this).css({
            'z-index' : '4'
        });
        $(this).removeClass("hover").stop()
        .animate({
            top: '386px',
            left: '899px',
            width: '95px',
            height: '81px'
        }, 400);
    });

    $("#specialspic").hover(function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $(this).addClass("hover").stop()
        .animate({
            top: '186px',
            left: '399px',
            width: '235px',
            height: '179px'
        }, 200);

    } , function() {
        $(this).css({
            'z-index' : '0'
        });
        $(this).removeClass("hover").stop()
        .animate({
            top: '191px',
            left: '404px',
            width: '225px',
            height: '169px'
        }, 400);
    });
    $("#workshopspic").hover(function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $(this).addClass("hover").stop()
        .animate({
            top: '377px',
            left: '614px',
            width: '129px',
            height: '132px'
        }, 200);

    } , function() {
        $(this).css({
            'z-index' : '0'
        });
        $(this).removeClass("hover").stop()
        .animate({
            top: '382px',
            left: '619px',
            width: '119px',
            height: '122px'
        }, 400);
    });
    $("#nitespic").hover(function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $(this).addClass("hover").stop()
        .animate({
            top: '372px',
            left: '213px',
            width: '186px',
            height: '137px'
        }, 200);

    } , function() {
        $(this).css({
            'z-index' : '0'
        });
        $(this).removeClass("hover").stop()
        .animate({
            top: '376px',
            left: '217px',
            width: '178px',
            height: '129px'
        }, 400);
    });
    $("#registerpic").hover(function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $(this).addClass("hover").stop()
        .animate({
            top: '413px',
            left: '1006px',
            width: '63px',
            height: '91px'
        }, 200);

    } , function() {
        $(this).css({
            'z-index' : '0'
        });
        $(this).removeClass("hover").stop()
        .animate({
            top: '418px',
            left: '1009px',
            width: '57px',
            height: '85px'
        }, 400);
    });
    $("#informalspic").hover(function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $(this).addClass("hover").stop()
        .animate({
            top: '326px',
            left: '406px',
            width: '171px',
            height: '143px'
        }, 200);

    } , function() {
        $(this).css({
            'z-index' : '0'
        });
        $(this).removeClass("hover").stop()
        .animate({
            top: '332px',
            left: '411px',
            width: '163px',
            height: '133px'
        }, 400);
    });
	    $("#lookbackpic").hover(function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $(this).addClass("hover").stop()
        .animate({
            top: '354px',
            left: '573px',
            width: '77px',
            height: '53px'
        }, 200);

    } , function() {
        $(this).css({
            'z-index' : '0'
        });
        $(this).removeClass("hover").stop()
        .animate({
            top: '355px',
            left: '574px',
            width: '75px',
            height: '51px'
        }, 400);
    });





});
