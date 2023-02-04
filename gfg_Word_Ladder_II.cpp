//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        vector<vector<string>>  res;
        vector<string>usedWords;
        int len=beginWord.length();
        queue<vector<string>> que;
        que.push({beginWord});
        vector<string>front;
        int level;
        int prevLevel=0;
        string word;
        map<string,int>wordMap;
        for(int i=0; i<wordList.size(); i++){
            wordMap[wordList[i]]=1;
            if(wordList[i]==beginWord)wordMap[beginWord]=0;
        }
        // usedWords.push_back(beginWord);
        while(!que.empty()){
            front=que.front();
            que.pop();
            level=front.size();
            word=front[level-1];
            if(level>prevLevel){
                for(int i=0; i<usedWords.size(); i++){
                    wordMap[usedWords[i]]=0;
                }
                prevLevel=level;
            }
            if(word==endWord) {
                res.push_back(front);
            }
            for(int i=0; i<len; i++){
                char og=word[i];
                for(char j='a'; j<'z'; j++){
                    word[i]=j;
                    if(wordMap.find(word)!=wordMap.end() && wordMap[word]==1){
                        front.push_back(word);
                        que.push(front);
                        front.pop_back();
                        usedWords.push_back(word);
                    }
                }
                word[i]=og;
            }
            
        }
        return res;
    }

};


 



//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends