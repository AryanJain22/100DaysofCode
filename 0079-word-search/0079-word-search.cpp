class Solution {
public:
    // Recursive function to search for the word starting from position (i, j) on the board
    bool solve(vector<vector<char>>& board, string& word, int word_index, int i, int j) {
        // Check if the current character matches the character at the given index in the word
        if (board[i][j] == word[word_index]) {
            // If the entire word has been found, return true
            if ((word_index + 1) == word.size()) {
                return true;
            }
            // Temporarily mark the current position as visited
            char tmp = board[i][j];
            board[i][j] = '0'; // '0' is used to denote visited positions
            
            // Recursively search in all four directions
            if (j > 0 && board[i][j - 1] != '0' && solve(board, word, word_index + 1, i, j - 1)) {
                return true;
            } else if (j < board[0].size() - 1 && board[i][j + 1] != '0' && solve(board, word, word_index + 1, i, j + 1)) {
                return true;
            } else if (i > 0 && board[i - 1][j] != '0' && solve(board, word, word_index + 1, i - 1, j)) {
                return true;
            } else if (i < board.size() - 1 && board[i + 1][j] != '0' && solve(board, word, word_index + 1, i + 1, j)) {
                return true;
            }
            
            // Restore the original value of the current position
            board[i][j] = tmp;
        }
        // If no match is found, return false
        return false;
    }

    // Function to check if the given word exists on the board
    bool exist(vector<vector<char>>& board, string word) {
        // Iterate through all positions on the board
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // If the current character matches the first character of the word,
                // start the search from this position
                if (board[i][j] == word[0] && solve(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        // If no match is found starting from any position, return false
        return false;
    }
};