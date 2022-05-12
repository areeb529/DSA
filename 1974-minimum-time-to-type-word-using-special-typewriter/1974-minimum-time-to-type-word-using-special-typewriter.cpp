class Solution {
public:
    int minTimeToType(string word) {
        int res=word.size();
        char point='a';
        for(auto &ch:word){
            res=res+min(abs(ch-point),26-abs(point-ch));
            point=ch;
        }
        return res;
    }
};