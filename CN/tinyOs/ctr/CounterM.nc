/**
 * Implementation for Counter application.  The clock ticks are
 * counted at one second interval. The binary value of the counter
 * is displayed by LEDs. The counter resets to 0 after the
 * maximum value of 7.
 *
 *
 * @author Sajid (dot) Hussain (at) acadiau.ca
 *
 **/
 
module CounterM {
  provides {
    interface StdControl;
  }
  uses {
    interface Timer;
    interface Leds;
  }
}
implementation {

 	uint8_t count;    
  /**
   * Initialize the component. 
   * 
   * @return Always returns <code>SUCCESS</code>
   **/
  command result_t StdControl.init() {
  	count=0;
    call Leds.init();     
    return SUCCESS;
  }


  /**
   * Start things up.  Sets all the LEDs as OFF. 
   * The rate for the clock component is set to 1000 ms.
   * 
   * @return Always returns <code>SUCCESS</code>
   **/
  command result_t StdControl.start() {
  	// set the LEDs
  	call Leds.redOff();
  	call Leds.greenOff();
    call Leds.yellowOff();
    // Start a repeating timer that fires every 1000ms
    return call Timer.start(TIMER_REPEAT, 1000);
  }

  /**
   * Halt execution of the application.
   * This just disables the clock component.
   * 
   * @return Always returns <code>SUCCESS</code>
   **/
  command result_t StdControl.stop() {
    return call Timer.stop();
  }

/** 
   * Displays the 3 bits to the LEDs,
   * with RED being the most signficant and 
   * YELLOW being the least significant.
   *
   * @return returns <code>SUCCESS</code>
   **/
  // display is a module static function
  result_t display(uint8_t value)
  {
      if (value &1) call Leds.yellowOn();
      else call Leds.yellowOff();
      if (value &2) call Leds.greenOn();
      else call Leds.greenOff();
      if (value &4) call Leds.redOn();
      else call Leds.redOff();

      return SUCCESS;
  }
  
   /**
   * Increments the count variable and the value is displayed
   * by calling display function. 
   *
   * @return None.
   **/
  task void increment()
  {
  	count = count + 1;
  	if (count > 7) count = 0;
   	display(count);
  }
  /**
   * posts the increment task. 
   *
   * @return Always returns <code>SUCCESS</code>
   **/
  event result_t Timer.fired()
  {
  	post increment();
    return SUCCESS;
  }
  
   
}


