//solution 1 - optimal and simple logic
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use sets to track seen numbers
        vector<set<char>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;  // Skip empty cells

                int boxIndex = (i / 3) * 3 + (j / 3);

                // If already exists → invalid
                if (rows[i].count(c) || cols[j].count(c) || boxes[boxIndex].count(c))
                    return false;

                rows[i].insert(c);
                cols[j].insert(c);
                boxes[boxIndex].insert(c);
            }
        }
        return true;
    }
};

//solution 2 - string key based approach
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //map to store all seen elements of sudoku
        unordered_set<string> seen;
        //Variable to maintain the count of the ongoing row and column
        int rowno = 0;
        int columnno = 0;
        //traverse each row and check the frequency of each element in row and column
        for(rowno = 0 ; rowno < 9; rowno++){
            //traverse the row-th vector for all columns
            for(columnno = 0; columnno < 9; columnno++){
                //char to store the current element
                char curr = board[rowno][columnno];
                //check if curr is '.'
                if(curr == '.'){
                    continue;
                }
            //create 3 strings for the current element denoting its row, column and box
            string rowkey = string(1, curr)+" in row "+to_string(rowno);
            string columnkey = string(1, curr)+" in column "+to_string(columnno);
            string boxkey = string(1, curr)+" in box "+to_string(rowno/3)+"-"+to_string(columnno/3); 
            
            //check if the current element have existing entry for this string
            if(seen.count(rowkey) || seen.count(columnkey) || seen.count(boxkey)){
                return false;
            }
            
            //mark as seen
            seen.insert(rowkey);
            seen.insert(columnkey);
            seen.insert(boxkey);
            }
        }
        return true;   
    }    
};