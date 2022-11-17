/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var characterReplacement = function(s, k) {
    let maxFreq=1;
    let start=0,end=0, n=s.length, maxWinSize=0;
    let mpp=new Map();
    // mpp.set(s[start],1);
    while(end<n){
        if (mpp.has(s[end])){
            let num=mpp.get(s[end]);
            num++;
            mpp.set(s[end],num);
            if(num>maxFreq) maxFreq=num;
        }
        else{
            mpp.set(s[end],1);
            // if(1>maxFreq) maxFreq=1;
        }
        if(end-start+1-maxFreq<=k){
            if(end-start+1 > maxWinSize)
                maxWinSize=end-start+1;
        }
        else{
            let num=mpp.get(s[start]);
            num--;
            mpp.set(s[start],num);
            start++;
        }
        end++;
    }
    return maxWinSize;
};