/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
 let k=0;
var createCounter = function(init) {
    let _init = init
    // const _init = init;
    return {
        increment: ()=> ++init,
        reset:()=>{
            
            init=_init;
            return init;
            },
        decrement:()=> --init,
    }
    
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */