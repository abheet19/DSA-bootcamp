// Time complexity: O(n * k * log k)
// Space complexity: O(n * k) where n is the number of strings and k is the maximum length of a string
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    const result = [];
    const map = new Map();

    for (let str of strs) {
        const sortedStr = str.split('').sort().join('');
        if (map.has(sortedStr)) {
            map.get(sortedStr).push(str);
        } else {
            map.set(sortedStr, [str]);
        }
    }
    for (let value of map.values()) {
        result.push(value);
    }
    return result;
};

const groupAnagramsOptimal = (strs) => {
    const map = new Map();
  
    for(const s of strs){
      const count = new Array(26).fill(0);
      for(const char of s){
          count[char.charCodeAt(0) - 'a'.charCodeAt(0)]++;
      }
      const key = count.join('#'); //join, more performant than string concatenation in a loop
      if(!map.has(key)){
          map.set(key, []);
      }
      map.get(key).push(s);
  }
    return Array.from(map.values());
}

// Test cases
console.log(groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])); // [["bat"],["nat","tan"],["ate","eat","tea"]]
console.log(groupAnagrams([""])); // [[""]]
console.log(groupAnagrams(["a"])); // [["a"]]
console.log(groupAnagrams(["a", "b"])); // [["a"],["b"]]
console.log(groupAnagrams(["ab", "ba"])); // [["ab","ba"]]
console.log(groupAnagrams(["ab", "ba", "abc"])); // [["ab","ba"],["abc"]]
console.log(groupAnagrams(["ab", "ba", "abc", "bac"])); // [["ab","ba"],["abc","bac"]]
console.log(groupAnagrams(["ab", "ba", "abc", "bac", "cab"])); // [["ab","ba","cab"],["abc","bac"]]
console.log(groupAnagrams(["ab", "ba", "abc", "bac", "cab", "bca"])); // [["ab","ba","cab","bca"],["abc","bac"]]
console.log(groupAnagramsOptimal(["ab", "ba", "abc", "bac", "cab", "bca"])); // [["ab","ba","cab","bca"],["abc","bac"]]
