class Solution {
public:
    bool helper(string & instructions){
        int n=instructions.size();
        int k=0;
        int  posX=0,negX=0,posY=0,negY=0;
        for(int i=0;i<n;i++){
            if(instructions[i]=='G'){
                if(k==0){
                    posY++;
                }
                else if(k==1){
                    posX++;
                }
                else if(k==2){
                    negY++;
                }
                else if(k==3){
                    negX++;
                }
            }
            else{
                if(instructions[i]=='L'){
                    k=(4+k-1)%4;
                }
                else{
                    k=(k+1)%4;
                }
            }
        }
        if(posX==negX&&posY==negY||(k==1||k==2||k==3))return true;
        else return false;
        
    }
    
    bool isRobotBounded(string instructions) {
        bool ans=helper(instructions);
        return ans;
    }
};