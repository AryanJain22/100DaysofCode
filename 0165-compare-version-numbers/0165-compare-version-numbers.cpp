class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        int n1 = version1.size();
        int n2 = version2.size();

        int i = 0, j = 0;
        while (i < n1 || j < n2) {
            int num1 = 0, num2 = 0;
        // to iterate and generate integer from a revision i.e.,until '.'
        // for version1's revision
            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
        // for version2's revision
            while (j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
        // compare two integers
            if (num1 < num2) return -1;
            else if (num1 > num2) return 1;
            else {
                i++;
                j++;
            }
        }
    // if all the revisions are equal
        return 0;
    }
};