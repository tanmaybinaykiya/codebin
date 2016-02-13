'use strict'

class Events{
    constructor(){
        this.registeredEventHandlers=new Map(); 
    }
    on(event, cb){
        if('undefined' === typeof this.registeredEventHandlers.get(event)){
            this.registeredEventHandlers.set(event, []); 
        }
        this.registeredEventHandlers.get(event).push(cb);
        console.log('registeredEventHandlers[event]:', this.registeredEventHandlers.get(event));
    }
    trigger(event){
        console.log(typeof this.registeredEventHandlers.get(event));
        if('undefined'!== typeof this.registeredEventHandlers.get(event)){
            this.registeredEventHandlers.get(event).forEach(function(cb){
                cb.call();
            });
        }
    }
}

class Type1 extends Events{
    constructor(){
        super();
        this.prop1= 'lalala';
        this.prop2= [this.prop1, this.prop1];
    }
    increment(){
        this.prop1++;
        this.trigger('incremented');
    }
}

class Type2 extends Events{
    constructor(){
        super();
        this.prop1= 'nanana';
        this.prop2= [];
        this.prop2[this.prop1]=this.prop1;
    }
}

var obj1 = new Type1();
// var obj2 = new Type2();

obj1.on('increment', function(){
    console.log('huahahhahaha');
});

obj1.increment();