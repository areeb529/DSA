/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int i=0,j=n;
        int ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            int x=guess(mid);
            if(x==0){
                ans= mid;
                break;
            }
            else if(x==-1){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};