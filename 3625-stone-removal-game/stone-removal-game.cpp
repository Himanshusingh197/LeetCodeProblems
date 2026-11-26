class Solution {
public:
    bool canAliceWin(int n) {

        int take = 10;
        int steps = 0;

        while (n >= take) {
            n -= take;
            take--;
            steps++;
        }

        if (steps % 2 != 0) {
            return true;
        } else
            return false;
    }
};