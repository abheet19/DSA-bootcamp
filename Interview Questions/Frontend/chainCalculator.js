/**
 * This is a simple calculator class that can perform basic arithmetic operations using method chaining.
 * @param {number} intitialValue - The initial value of the calculator.
 * @param {number} amount - The amount to add or subtract from the current value.
 * @param {number} factor - The factor to multiply the current value by.
 * @param {number} divisor - The divisor to divide the current value by.
 * @returns {number} The current value of the calculator.
 */

class Calculator{

    constructor(intitialValue = 0){
        this.value=intitialValue;
    }
    add(amount){
        this.value+=amount;
        return this;
    }
    subtract(amount){
        this.value-=amount;
        return this;

    }
    multiply(factor){
        this.value*=factor;
        return this;
    }
    divide(divisor){
        this.value/=divisor;
        return this;
    }
    getValue(){
        return this.value;
    }
}

const calculator= new Calculator(2);
console.log(calculator.add(3).mutiply(4).subtract(2).divide(2).getValue()); 