class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int n= operations.size();

        for(int i=0; i<n; i++)
        {
            if(operations[i] == "+")
            {
                int  val1 = st.top();
                st.pop();
                int val2 = st.top();
                // st.push(val2);   we havent popped val2 its still in there 
                st.push(val1);
                st.push(long(val1+val2));
                // cout<<st.top()<<" "<<endl;
            }
            else if(operations[i] == "D")
            {
                int val = st.top();
                st.push(long(2*val));
                // cout<<st.top()<<" "<<endl;
            }
            
            else if (operations[i] == "C")
            {
                st.pop();
                // cout<<st.top()<<" "<<endl;
            }
            
            else{
                st.push(stoi(operations[i]));
                // cout<<st.top()<<" "<<endl;
            }
        }
        long long sum=0;
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};