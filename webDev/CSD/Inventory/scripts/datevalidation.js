function checkdate(form,date)
{
	var thisform
	var datename
	var minYear=1800
	var maxYear=2900
	var edate = eval('document.'+form+'.'+date+'  .value')
	var len = edate.length

	
	var daysInMonth = DaysArray(12)
	var strMonth = edate.substring(5,7)
	var strDay = edate.substring(8,10)
	var strYear = edate.substring(0,4)
	
	if (strDay.charAt(0)=="0" && strDay.length>1) strDay=strDay.substring(1)
	if (strMonth.charAt(0)=="0" && strMonth.length>1) strMonth=strMonth.substring(1)
	for (var i = 1; i <= 3; i++) 
	{
		if (strYear.charAt(0)=="0" && strYear.length>1) strYear=strYear.substring(1)
	}

	month=parseInt(strMonth)
	day=parseInt(strDay)
	year=parseInt(strYear)
	
	//alert("year = "+ year + "month = " + month + " day = " + day)
	
	if(edate="" || len!=10)
	{
		alert("Please enter valid date");
		return false;
	}
	
	if (strMonth.length<1 || month<1 || month>12 || !isInteger(strMonth))
	{
		alert("Please enter a valid date1111")
		return false
	}
	
	if (strDay.length<1 || day<1 || day>31 || (month==2 && day>daysInFebruary(year)) || day > daysInMonth[month] || !isInteger(strDay))
	{
		alert("Please enter a valid date")
		return false
	}
	if (strYear.length != 4 || year==0 || year<minYear || year>maxYear || !isInteger(strYear))
	{
		alert("Please enter a valid 4 digit year between "+minYear+" and "+maxYear)
		return false
	}
return true
}

function daysInFebruary (year)
{
	// February has 29 days in any year evenly divisible by four,
    // EXCEPT for centurial years which are not also divisible by 400.
    return (((year % 4 == 0) && ( (!(year % 100 == 0)) || (year % 400 == 0))) ? 29 : 28 );
}
function DaysArray(n) {
	for (var i = 1; i <= n; i++) {
		this[i] = 31
		if (i==4 || i==6 || i==9 || i==11) {this[i] = 30}
		if (i==2) {this[i] = 29}
   } 
   return this
}

function isInteger(val)
{    
//alert(val);
    if(val==null)    
	{        
     return false;    
	 }    
	 if (val.length==0)   
	 {        
	 return false;    
	 }    
	 for (var i = 0; i < val.length; i++)     
	 {       
		 var ch = val.charAt(i)        
		 if (i == 0 && ch == "-")        
		 {            
		 continue        
		 }
		 if (ch < "0" || ch > "9") 
		 {           
		 return false        
		 }    
	 }    
	 return true
	 }

