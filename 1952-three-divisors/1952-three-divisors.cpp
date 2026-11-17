
class Solution {
public:
    bool isThree(int n) {
        int root = sqrt(n);

        // Check if n is a perfect square
        if (root * root != n)
            return false;

        // Check if root is prime
        if (root < 2)
            return false;

        for (int i = 2; i * i <= root; i++) {
            if (root % i == 0)
                return false;
        }

        return true;
    }
};
