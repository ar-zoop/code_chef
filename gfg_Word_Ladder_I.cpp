//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        int len=startWord.length();
        queue<pair<string,int>> que;
        que.push({startWord,1});
        pair<string,int>front;
        int level;
        string word;
        map<string,int>wordMap;
        for(int i=0; i<wordList.size(); i++){
            wordMap[wordList[i]]=1;
        }
        wordMap[startWord]=0;
        while(!que.empty()){
            front=que.front();
            que.pop();
            word=front.first;
            level=front.second;
            if(word==targetWord) return level;
            for(int i=0; i<len; i++){
                char og=word[i];
                for(char j='a'; j<'z'; j++){
                    word[i]=j;
                    if(wordMap.find(word)!=wordMap.end() && wordMap[word]==1){
                        wordMap[word]=0;
                        que.push({word,level+1});
                    }
                }
                word[i]=og;
            }
            
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends