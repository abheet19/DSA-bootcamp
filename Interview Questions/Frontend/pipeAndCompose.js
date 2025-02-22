//Create pipe and compose function that will take multiple functions as arguments and executes from left to right and vice versa respectively.

// Explanation:
// - pipe creates a function that applies the given functions in sequence from left to right.
// - compose does the same but starting from the rightmost function.
// - Example usages showcase the transformation of an initial value through a series of operations.

// In pipe:
// - fns.reduce((acc, fn) => fn(acc), x)
//   • "acc" (accumulator) starts as the initial value "x".
//   • For each function "fn", it computes fn(acc) and updates "acc".
//   • The functions are applied from left to right.

// In compose:
// - fns.reduceRight((acc, fn) => fn(acc), x)
//   • Similar, but reduces from the right, applying functions in reverse order.

const pipe = (...fns) => {
    return function (x) {
        return fns.reduce((acc, fn) => fn(acc), x);
    };
};
const compose = (...fns) => {
    return function (x) {
        return fns.reduceRight((acc, fn) => fn(acc), x);
    };
};

const add5 = (x) => x + 5;
const multiplyBy2 = (x) => x * 2;
const subtract10 = (x) => x - 10;
const toString=(x) => `${x}`;

console.log("Pipe");
result1=pipe(add5,multiplyBy2,subtract10)(10); //(10+5)*2-10 =20
console.log(result1); //20

result2=pipe(toString,add5)(5); //"5"+5="55"
console.log(result2); //"55"

console.log("Compose");
result3=compose(add5,multiplyBy2,subtract10)(10); //(10-10)*2+5=5
console.log(result3); //5

result4=compose(toString,add5)(5); //5+5="10"
console.log(result4); //10
