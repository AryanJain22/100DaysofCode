class Solution {
public:
    string reversePrefix(string word, char ch) {
        size_t idx1 = 0, idx2 = 0;
        for (char c : word) {
            if (ch == c){ 
                break;
            }
            idx2++;
        }

        if (idx2 >= word.size()){
            return word;
        }

        while(idx1 < idx2) {
            auto temp = word[idx2];
            word[idx2] = word[idx1];
            word[idx1] = temp;

            idx1++;
            idx2--;
        }

        return word;
    }
};