class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        int cntMax =0;
        int n= sentences.size();
        for (int i=0; i<n; i++)
        {
            int cnt =0;
            string element = sentences[i];
            for(int j=0; j<element.size(); j++)
            {
                char ch = element[j];
                if (ch == ' ')
                {
                    cnt++;
                }
            }
            cout<<cnt<<endl;
            cntMax = (cnt > cntMax)? cnt : cntMax;
        }
        return cntMax +1;
    }
};