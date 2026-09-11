class Solution {
public:
    bool judgeCircle(string moves) {
        string str = moves;
        int x=0;
        int y=0;
        for(auto it = str.begin(); it != str.end(); ++it)
        {
            char ch =*it;
            switch(ch){
                case 'L':
                x++;
                break;

                case 'R':
                x--;
                break;

                case 'U':
                y++;
                break;

                case 'D':
                y--;
                break;
            }

        }
        if (x==0 && y==0) return true;
        else return false;

    }
};