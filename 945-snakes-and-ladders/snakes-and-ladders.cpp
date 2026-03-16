class Solution {
public:
    int n;

    pair<int,int> getCoord(int s){
        int row = n - 1 - (s - 1) / n;
        int col = (s - 1) % n;

        if((n % 2 == 1 && row % 2 == 1) || (n % 2 == 0 && row % 2 == 0))
            col = n - 1 - col;

        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {

        n = board.size();

        queue<int> q;
        q.push(1);

        vector<vector<bool>> visited(n, vector<bool>(n,false));
        visited[n-1][0] = true;

        int steps = 0;

        while(!q.empty()) {

            int size = q.size();

            for(int i = 0; i < size; i++) {

                int curr = q.front();
                q.pop();

                if(curr == n*n)
                    return steps;

                for(int dice = 1; dice <= 6; dice++) {

                    int next = curr + dice;
                    if(next > n*n) break;

                    auto [r,c] = getCoord(next);

                    if(visited[r][c]) continue;

                    visited[r][c] = true;

                    if(board[r][c] == -1)
                        q.push(next);
                    else
                        q.push(board[r][c]);
                }
            }

            steps++;
        }

        return -1;
    }
};