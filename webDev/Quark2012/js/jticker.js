/*
 * JTicker 0.5 Beta
 * By Jason Levine (http://www.jasons-toolbox.com)
 * A ticker plugin for the jquery library.
 */
$.JTickerObjArray = new Array();
$.fn.jticker = function(passedOptions) {
	var options = {
	    TickerID: "",
		delay: 1000,
		newwindow: false,
		url: "tickerdata.xml",
		transition: "slide",
		speed: "slow",
		contentcounter: -1,
		ArrayIndex: -1,
		dataXML: {
		},
		timerid: -1,
		setRSS: function(ArrayIndex) {
			$("#" + options.TickerID).hide();
			// Load Data
			$.get(options.url, function(data){
				options.dataXML = data;
				options.contentcounter = -1;
				options.FillSlide();
			});
		},
		FillSlide: function() {
			var Item, TickerHTML, Title, URL, Desc;
			$("#" + options.TickerID).empty();
			options.contentcounter++;
			if (options.contentcounter == $("item", options.dataXML).length) {
				options.contentcounter = 0;
			}
			Item = $("item", options.dataXML).get(options.contentcounter);
			Title = $("title", Item).text();
			URL = $("link", Item).text();
			Desc = $("description", Item).text();
			TickerHTML = "<div class=\"JTickerTitle\"><a href=\"" + URL + "\""
			if (options.newwindow) {
				TickerHTML += " target=\"_blank\""
			}
			TickerHTML += ">" + Title + "</a></div><div>" + Desc + "</div>";
			$("#" + options.TickerID).append(TickerHTML);
			options.EnterSlide();
		},
	    ExitSlide: function() {
			if (options.contentcounter > -1) {
				clearTimeout(options.timerid);
				switch (options.transition.toLowerCase()) {
					case "slide":
						$("#" + options.TickerID).slideUp(
							options.speed,
							options.ExitSlideStep2()
						);
						break;
					default:
						$("#" + options.TickerID).fadeOut(
							options.speed,
							options.ExitSlideStep2()
						);
						break;
				}
			} else {
				options.ExitSlideStep2(ArrayIndex);
			}
	    },
	    ExitSlideStep2: function() {
			var tempid;
			
			tempid = setTimeout("$.JTickerObjArray[" + options.ArrayIndex + "].FillSlide();", 500);
		},
	    EnterSlide: function() {
			var ArrayIndex = options.ArrayIndex;
			switch (options.transition.toLowerCase()) {
				case "slide":
					$("#" + options.TickerID).slideDown(
						options.speed,
						options.EnterSlideStep2()
					);
					break;
				default:
					$("#" + options.TickerID).fadeIn(
						options.speed,
						options.EnterSlideStep2()
					);
					break;
			}
	    },
	    EnterSlideStep2: function() {
			options.timerid = setTimeout("$.JTickerObjArray[" + options.ArrayIndex + "].ExitSlide();", options.delay);
		}
	};
	if (passedOptions) {
		$.extend(options, passedOptions);
	}
	
	return this.each(function(){
		options.TickerID = this.id;
		$.JTickerObjArray.push(options);
		options.ArrayIndex = $.JTickerObjArray.length - 1;
		$("#" + options.TickerID).hover(function() {
			clearTimeout(options.timerid);
		}, function() {
			options.timerid = setTimeout("$.JTickerObjArray[" + options.ArrayIndex + "].ExitSlide();", options.delay);
		});
		$.JTickerObjArray[options.ArrayIndex].setRSS(options.ArrayIndex);
	});
};