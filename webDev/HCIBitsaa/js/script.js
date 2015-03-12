$(window).load(function(){


$("#yoja")        .animate({
            opacity:0
        }, 400);


$("#firsta")        .animate({
            opacity:0
        }, 400);

$("#lasta")        .animate({
            opacity:0
        }, 400);

$("#dcnicka")        .animate({
            opacity:0
        }, 400);

$("#brancha")        .animate({
            opacity:0
        }, 400);

$("#akaa")        .animate({
            opacity:0
        }, 400);

$("#campusa")        .animate({
            opacity:0
        }, 400);

$("#phonea")        .animate({
            opacity:0
        }, 400);





        $('#yojb').toggle();
    $('#yoja').click(function(){
        $('#yojb').toggle();
        $('#yojc').toggle();
    });
        $('#lastb').toggle();
    $('#lasta').click(function(){
        $('#lastb').toggle();
        $('#lastc').toggle();
    });
        $('#firstb').toggle();
    $('#firsta').click(function(){
        $('#firstb').toggle();
        $('#firstc').toggle();
    });
        $('#dcnickb').toggle();
    $('#dcnicka').click(function(){
        $('#dcnickb').toggle();
        $('#dcnickc').toggle();
    });
        $('#akab').toggle();
    $('#akaa').click(function(){
        $('#akab').toggle();
        $('#akac').toggle();
    });
        $('#emailb').toggle();
    $('#emaila').click(function(){
        $('#emailb').toggle();
        $('#emailc').toggle();
    });
        $('#phoneb').toggle();
    $('#phonea').click(function(){
        $('#phoneb').toggle();
        $('#phonec').toggle();
    });
        $('#branchb').toggle();
    $('#brancha').click(function(){
        $('#branchb').toggle();
        $('#branchc').toggle();
    });
        $('#campusb').toggle();
    $('#campusa').click(function(){
        $('#campusb').toggle();
        $('#campusc').toggle();
    });
        $('#imfileb').toggle();
    $('#imfilea').click(function(){
        $('#imfileb').toggle();
        $('#imfilec').toggle();
    });
    $("#firstc").hover(function() {
        $(this).css({
            'z-index' : '-1'
        }); 
        $("#firsta").addClass("hover").stop() 
        .animate({
            opacity:1
        }, 400);

    } , function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $("#firsta").removeClass("hover").stop() 
        .animate({
            opacity:0
        }, 400);
    });

    $("#lastc").hover(function() {
        $(this).css({
            'z-index' : '-1'
        }); 
        $("#lasta").addClass("hover").stop() 
        .animate({
            opacity:1
        }, 400);

    } , function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $("#lasta").removeClass("hover").stop() 
        .animate({
            opacity:0
        }, 400);
    });
    $("#dcnickc").hover(function() {
        $(this).css({
            'z-index' : '-1'
        }); 
        $("#dcnicka").addClass("hover").stop() 
        .animate({
            opacity:1
        }, 400);

    } , function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $("#dcnicka").removeClass("hover").stop() 
        .animate({
            opacity:0
        }, 400);
    });
    $("#akac").hover(function() {
        $(this).css({
            'z-index' : '-1'
        }); 
        $("#akaa").addClass("hover").stop() 
        .animate({
            opacity:1
        }, 400);

    } , function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $("#akaa").removeClass("hover").stop() 
        .animate({
            opacity:0
        }, 400);
    });
    $("#emailc").hover(function() {
        $(this).css({
            'z-index' : '-1'
        }); 
        $("#emaila").addClass("hover").stop() 
        .animate({
            opacity:1
        }, 400);

    } , function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $("#emaila").removeClass("hover").stop() 
        .animate({
            opacity:0
        }, 400);
    });
    $("#phonec").hover(function() {
        $(this).css({
            'z-index' : '-1'
        }); 
        $("#phonea").addClass("hover").stop() 
        .animate({
            opacity:1
        }, 400);

    } , function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $("#phonea").removeClass("hover").stop() 
        .animate({
            opacity:0
        }, 400);
    });
    $("#idnoc").hover(function() {
        $(this).css({
            'z-index' : '-1'
        }); 
        $("#idnoa").addClass("hover").stop() 
        .animate({
            opacity:1
        }, 400);

    } , function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $("#idnoa").removeClass("hover").stop() 
        .animate({
            opacity:0
        }, 400);
    });
    $("#yojc").hover(function() {
        $(this).css({
            'z-index' : '-1'
        }); 
        $("#yoja").addClass("hover").stop() 
        .animate({
            opacity:1
        }, 400);

    } , function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $("#yoja").removeClass("hover").stop() 
        .animate({
            opacity:0
        }, 400);
    });
    $("#branchc").hover(function() {
        $(this).css({
            'z-index' : '-1'
        }); 
        $("#brancha").addClass("hover").stop() 
        .animate({
            opacity:1
        }, 400);

    } , function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $("#brancha").removeClass("hover").stop() 
        .animate({
            opacity:0
        }, 400);
    });
    $("#campusc").hover(function() {
        $(this).css({
            'z-index' : '-1'
        }); 
        $("#campusa").addClass("hover").stop() 
        .animate({
            opacity:1
        }, 400);

    } , function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $("#campusa").removeClass("hover").stop() 
        .animate({
            opacity:0
        }, 400);
    });


    $("#imfilec").hover(function() {
        $(this).css({
            'z-index' : '-1'
        }); 
        $("#imfilea").addClass("hover").stop() 
        .animate({
            opacity:1
        }, 400);

    } , function() {
        $(this).css({
            'z-index' : '10'
        }); 
        $("#imfilea").removeClass("hover").stop() 
        .animate({
            opacity:0
        }, 400);
    });
        $('#search').toggle();
        $('#searchi').toggle();
/*    $(".searchu").click(function() {
        $(this).css({
            'z-index' : '-1'
        }); 
        $(this).removeClass("searchu").stop();
        $(this).addClass("searchd").stop() 
        .animate({
            'top':'-71px'
        }, 400);
        $('#search').toggle();
    });
    $(".searchd").click(function() {
        $(this).css({
            'z-index' : '-1'
        }); 
        $(this).removeClass("searchd").stop();
        $(this).addClass("searchu").stop() 
        .animate({
            'top':'-102px'
        }, 400);
        $('#search').toggle();
    });*/

    $("#searchu").click(function() {
        $('#searchu').toggle();
        $('#searchi').toggle();
        $('#search').toggle();
    });
    $("#searchi").click(function() {
        $('#searchu').toggle();
        $('#searchi').toggle();
        $('#search').toggle();
    });

    $("#batchs").click(function() {
    $('#batchsnaps a').lightBox();
    });

    $('.edit').focusout(function() {
    $('#edit').submit();
    });
});
