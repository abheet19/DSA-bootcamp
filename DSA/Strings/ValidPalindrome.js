/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    s=s.replace(/[^a-zA-Z0-9]/g, '').toLowerCase(); //Replace all non-alphanumeric characters with empty string and convert to lowercase
    let i= 0;
    let j=s.length-1;

    while(i<j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
};