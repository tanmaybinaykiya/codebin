
/**
 * Counter is incremented after every second; the result is displayed
 * on LEDs.
 *
 * @author Sajid (dot) Hussain (at) acadiau.ca
 **/
configuration Counter {
}

implementation {

// COMPONENTS

  // tos/system/Main	
  // uses: StdControl, provides: None
  components Main; 		
  
   // apps/Hello
  // uses: Timer, Leds; provides: StdControl
  components CounterM;		
  
  // tos/system/TimerC
  // uses: None, provides: StdControl, Timer
  components TimerC; 	
  
  // tos/system/LedsC
  // uses: None, provides: Leds
  components LedsC; 		
   

// WIRING 

	// the provides interfaces are connected to the uses ones.
	Main.StdControl -> CounterM.StdControl;
	
	CounterM.Timer -> TimerC.Timer[unique("Timer")];
	Main.StdControl -> TimerC.StdControl;
	
  	CounterM.Leds -> LedsC.Leds;
  	

 
  
}

