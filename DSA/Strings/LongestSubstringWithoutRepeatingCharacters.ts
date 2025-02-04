function lengthOfLongestSubstring(s: string): number {
    const charMap= new Map<string,number>();
    let left =0;
    let right =0;
    let maxLen=0;

    while(right< s.length){
        const currChar=s[right];
        // If the character is already in the map and its last occurrence is within the current window
        if(charMap.has(currChar) && charMap.get(currChar)! >=left){
            left = charMap.get(currChar)! + 1;   // Move the left pointer to the right of the last occurrence of the character
        }
        // Update the last index of the character
        charMap.set(currChar,right);
        maxLen =Math.max(maxLen,right-left +1);
        right++;
    }
    return maxLen
};