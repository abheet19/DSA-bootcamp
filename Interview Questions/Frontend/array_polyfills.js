//Polyfills are pieces of code that provide modern functionality on older browsers or environments that do not natively support it.
//They essentially "fill in" the gaps by mimicking the behavior of modern JavaScript features.

Array.prototype.myMap = function (cb) {
  if (typeof cb !== "function") {
    throw new TypeError(cb + "is not a function");
  }
  const result = [];

  for (let i = 0; i < this.length; i++) {
    result.push(cb(this[i], i, this));
  }
  return result;
};
const arr = [1, 2, 3, 4, 5];
const result = arr.myMap((x) => x * 2);
console.log(result); //[2,4,6,8,10]

Array.prototype.myFilter = function (cb) {
  if (typeof cb !== "function") {
    throw new TypeError(cb + "is not a function");
  }
  const result = [];
  for (let i = 0; i < this.length; i++) {
    if ((cb[this], i, this)) {
      result.push(this[i]);
    }
  }
  return result;
};

const evenNumbers = arr.myFilter((x) => x % 2 === 0);
console.log(evenNumbers); //[2,4]

Array.prototype.myReduce = function (cb, initialValue) {
  if (typeof cb !== "function") {
    throw new TypeError(cb + "is not a function");
  }
  let acc = initialValue !== undefined ? initialValue : this[0];
  const startIndex = initialValue !== undefined ? 0 : 1;

  for (let i = startIndex; i < this.length; i++) {
    acc = cb((acc, this[i], i, this));
  }
  return acc;
};
const sum = arr.myReduce((acc, current) => acc + current, 0);
console.log(sum); //15
const product = arr.myReduce((acc, current) => acc * current, 1);
console.log(product); //120

Array.prototype.myEvery = function (cb) {
  if (typeof cb !== "function") {
    throw new TypeError(cb + "is not a function");
  }
  for (let i = 0; i < this.length; i++) {
    if (!cb(this[i], i, this)) {
      return false;
    }
  }
  return true;
};

const areAllPositive = arr.myEvery((x) => x > 0);
console.log(areAllPositive); //true

Array.prototype.myForEach =function(cb){
  if(typeof cb !== "function"){
    throw new TypeError(cb + "is not a function");
  }
  for(let i=0;i<this.length;i++){
    cb(this[i],i,this);
  }
};
const arrData = [0,1,2,3,4,5,6,7,8,9];
arrData.myForEach((element)=>{
  console.log(element);
});

