class Solution {
public:
    vector<vector<string>> res;
    bool canPlace(vector<string> &allQueenPos,int x,int y,int n,string &place){
        if(place[y]=='Q')return false;
        int i=x-1,j=y-1;
        while(i>=0&&j>=0){
            if(allQueenPos[i][j]=='Q')return false;
            i--;
            j--;
        }
        i=x-1,j=y+1;
        while(i>=0&&j<n){
            if(allQueenPos[i][j]=='Q')return false;
            i--;
            j++;
        }
        return true;
    }
    void placeQueens(string &place,int i,int n,vector<string> &allQueenPos){
        if(i==n){
            res.push_back(allQueenPos);
            return;
        }
        for(int j=0;j<n;j++){
            if(canPlace(allQueenPos,i,j,n,place)){
                place[j]='Q'; 
                allQueenPos[i][j]='Q';
                placeQueens(place,i+1,n,allQueenPos);
                allQueenPos[i][j]='.';
                place[j]='.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        string place(n,'.');
        vector<string> allQueenPos;
        string s(n,'.');
        for(int i=0;i<n;i++){
            allQueenPos.push_back(s);
        }
        placeQueens(place,0,n,allQueenPos);
        return res;
    }
};