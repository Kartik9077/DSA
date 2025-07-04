/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
    __int128 l=1,r=n;
    while(l<=r)
    {
        __int128 mid=(l+r+1)/2;
        if(guess(mid)==0)return mid;
        if(guess(mid)==-1)r=mid-1;
        else l=mid+1;
    }
    return l-1;
    }
};