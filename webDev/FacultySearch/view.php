<!--DOCTYPE html-->
<html lang="en">
<head>
    <meta charset="utf-8" />
    <title>View</title>
    <link rel="stylesheet" href="styles/styles.css" />
    <link rel="stylesheet" href="styles/viewStyles.css" />
    <link rel="stylesheet" href="styles/navStyles.css" />
    <link rel="stylesheet" href="styles/autocomplete.css" type="text/css"/>
   <link rel="stylesheet" href="styles/font-awesome.css">


    <script src="scripts/jquery.js" type="text/javascript"></script>
    <script src="scripts/dimensions.js" type="text/javascript"></script>
    <script src="scripts/autocomplete.js" type="text/javascript"></script>

    <script type="text/javascript">
        $(function(){
            setAutoComplete("quickInput", "quickResults", "autocomplete.php?part=");
        });
    </script>
</head>
<body style="width:1600px;">

    <?php include 'navBar.php'; ?>
    <div class="wrapper" style="clear: both;">
        
        <div id="aWing">
            <div id="chemDept">
                <a class="size_1 chamber chem1" href="profilePage.php?A315" id="A315">A 315 </a>
                <a class="size_1 chamber chem2" href="#" id="A316">A 316</a>
                <a class="size_1 chamber chem1" href="#" id="A314">A 314</a>
                <a class="size_1 chamber chem2" href="#" id="A317">A 317</a>
                <a class="size_1 chamber chem1" href="#" id="A313">A 313</a>
                <a class="size_1 chamber chem2" href="#" id="A318">A 318</a>
                <a class="size_1 chamber chem1" href="#" id="A312">A 312</a>
                <a class="size_1 chamber chem2" href="#" id="A319">A 319</a>
                <a class="size_1 chamber chem1" href="#" id="A311">A 311</a>
                <a class="size_1 chamber chem2" href="#" id="A320">A 320</a>
                <a class="size_1 chamber chem1" href="#" id="A310">A 310</a>
                <a class="size_1 chamber chem2" href="#" id="A321">A 321</a>
                <a class="size_1 chamber chem1" href="#" id="A309">A 309</a>
                <a class="size_1 chem2 blank"><i class="icon-arrow-left" style="font-size:27px;color:rgb(34, 114, 247); "></i></a>
                <a class="size_1 chamber chem1" href="#" id="A308">A 308</a>
                <a class="size_1 chamber chem2" href="#" id="A301">A 301</a>
                <a class="size_1 chamber chem1" href="#" id="A307">A 307</a>
                <a class="size_1 chamber chem2" href="#" id="A302">A 302</a>
                <a class="size_1 chamber chem1" href="#" id="A306">A 306</a>
                <a class="size_1 chamber chem2" href="#" id="A303">A 303</a>
                <a class="size_1 chamber chem1" href="#" id="A305">A 305</a>
                <a class="size_1 chamber chem2" href="#" id="A304">A 304</a>
            </div>
            <div id="midSect">
                <div id="humDept">
                    <a class="size_2 chamber hum1" id="A307" href="#">
                        A 307</br>
                        LANGUAGE LAB
                    </a>
                    <div style="float:left; ">
                        <div style="float:left; clear:both;margin-top:5px;">
                            <a class="size_1 chamber hum1" href="#" id="A301">A 301</a>
                            <a class="size_1 chamber hum1" href="#" id="A302">A 302</a>
                            <a class="size_1 chamber hum1" href="#" id="A303">A 303</a>
                            <a class="size_1 chamber hum1" href="#" id="A304">A 304</a>
                            <a class="size_1 chamber hum1" href="#" id="A305">A 305</a>
                        </div>    
                        <div style="float:left; clear:both; margin-top:30px;">
                            <a class="size_1 chamber hum1" href="#" id="A306">A 306</a>
                            <a class="size_1 chamber hum1" href="#" id="A307">A 307</a>
                            <a class="size_1 chamber hum1" href="#" id="A308">A 308</a>
                            <a class="size_1 chamber hum1" href="#" id="A309">A 309</a>
                            <a class="size_1 chamber hum1" href="#" id="A310">A 310</a>
                        </div>    
                    </div>
                </div>
                <div id="courtyard" class="grayed"><p style="text-align:center; font-size:20px; margin-top:140px; color:#000;">A-WING </p></div>

            </div>
            <div id="mechSect">
                <div class="grayed size_2" ></div>
                <div id="mechDept">
                    <a class="size_1 chamber mech1" href="#" id="A301">A 301</a>
                    <a class="size_1 chamber mech2" href="#" id="A302">A 302</a>
                    <a class="size_1 chamber mech1" href="#" id="A303">A 303</a>
                    <a class="size_1 chamber mech2" href="#" id="A304">A 304</a>
                    <a class="size_1 blank mech1"><i class="icon-arrow-right" style="font-size:27px;color:rgb(34, 114, 247); "></i></a>
                    <a class="size_1 chamber mech2" href="#" id="A305">A 305</a>
                    <a class="size_1 chamber mech1" href="#" id="A306">A 306</a>
                    <a class="size_1 chamber mech2" href="#" id="A307">A 307</a>
                    <a class="size_1 chamber mech1" href="#" id="A308">A 308</a>
                    <a class="size_1 chamber mech2" href="#" id="A309">A 309</a>
                    <a class="size_1 chamber mech1" href="#" id="A310">A 310</a>
                    <a class="size_1 chamber mech2" href="#" id="A311">A 311</a>
                    <a class="size_1 chamber mech1" href="#" id="A312">A 312</a>
                    <a class="size_1 chamber mech2" href="#" id="A313">A 313</a>
                </div>           
            </div>


            <div id="corridor" >
                <div class="grayed" style="clear:both; float:left; width:125px; height:98px; ">
                </div>

                <div id="eeeLabs" >
                    <div style="float:left; clear:both;margin-top:0px;">
                        <a class="size_1 chamber eee1" href="#" id="A303">A 303</a>
                        <a class="size_1 chamber eee1" href="#" id="A304">A 304</a>
                        <a class="size_1 chamber eee1" href="#" id="A305">A 305</a>
                        <a class="size_1 chamber eee1" href="#" id="A306">A 306</a>
                    </div>    
                    <div style="float:left; clear:both; margin-top:5px;">
                        <a class="size_1 chamber eee1" href="#" id="A302">A 302</a>
                        <a class="size_1 chamber eee1" href="#" id="A301">A 301</a>
                        <a class="size_1 blank eee1"           ><i class="icon-arrow-up" style="font-size:27px; color:rgb(34, 114, 247); "></i></a>
                        <a class="size_1 chamber eee1" href="#" id="A307">A 307</a>
                    </div>    
                </div>


                <div class="grayed" style="float:left; width:118px; height:98px; ">
                </div>    
            </div>
            <div id="csDept">
                <div id="leftBlock">
                    <a class="size_1 chamber cs1" href="#" id="A427">A 427</a>
                    <a class="size_1 chamber cs2" href="#" id="A422">A 422</a>
                    <a class="size_1 chamber cs1" href="#" id="A426">A 426</a>
                    <a class="size_1 chamber cs2" href="#" id="A423">A 423</a>
                    <a class="size_1 chamber cs1" href="#" id="A425">A 425</a>
                    <a class="size_1 chamber cs2" href="#" id="A424">A 424</a>
                </div>    
                <div id="centralBlock" >
                    <div style="float:left; clear:both;margin-top:7px;">
                        <a class="size_1 chamber cs" href="#" id="A415">A 415</a>
                        <a class="size_1 chamber cs" href="#" id="A416">A 416</a>
                        <a class="size_1 chamber cs" href="#" id="A417">A 417</a>
                        <a class="size_1 chamber cs" href="#" id="A418">A 418</a>
                        <a class="size_1 chamber cs" href="#" id="A419">A 419</a>
                        <a class="size_1 chamber cs" href="#" id="A420">A 420</a>
                        <a class="size_1 chamber cs" href="#" id="A421">A 421</a>
                    </div>    
                    <div style="float:left; clear:both; margin-top:30px;">
                        <a class="size_1 chamber cs" href="#" id="A414">A 414</a>
                        <a class="size_1 chamber cs" href="#" id="A413">A 413</a>
                        <a class="size_1 chamber cs" href="#" id="A412">A 412</a>
                        <a class="size_1 chamber cs" href="#" id="A411">A 411</a>
                        <a class="size_1 chamber cs" href="#" id="A410">A 410</a>
                        <a class="size_1 chamber cs" href="#" id="A409">A 409</a>
                        <a class="size_1 chamber cs" href="#" id="A408">A 408</a>
                    </div>    
                </div>    
                <div id="rightBlock">
                    <a class="size_1 chamber cs1" href="#" id="A407">A 407</a>
                    <a class="size_1 chamber cs2" href="#" id="A402">A 402</a>
                    <a class="size_1 chamber cs1" href="#" id="A406">A 406</a>
                    <a class="size_1 chamber cs2" href="#" id="A403">A 403</a>
                    <a class="size_1 chamber cs1" href="#" id="A405">A 405</a>
                    <a class="size_1 chamber cs2" href="#" id="A404">A 404</a>
                </div>    
            </div>


        </div>
        <div id="bWing">

        </div>    
    </div>
    
</body>
</html>