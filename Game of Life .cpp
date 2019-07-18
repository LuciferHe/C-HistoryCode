//题目：Game of Life  https://leetcode.com/problems/game-of-life/
//题解： http://blog.csdn.net/xudli/article/details/48896549

void gameOfLife(int** board, int boardRowSize, int boardColSize) {
    int i, j, k;
	int t, c, tx, ty, v;
	int dirx[] = { -1, 0, 1, 0, -1, 1, -1, 1 };
	int diry[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
	if (board == NULL || board[0] == NULL) return;
	for (i = 0; i < boardRowSize; ++i){
		for (j = 0; j < boardColSize; ++j){
			t = *(*(board + i) + j);
			c = 0;
			for (k = 0; k < 8; ++k){
				tx = i + dirx[k];
				ty = j + diry[k];
				if (tx < 0 || ty < 0 || boardRowSize - 1 < tx || boardColSize - 1 < ty) continue;
				v = *(*(board + tx) + ty);
				if (v % 10) ++c;
			}//for3

			if (t == 1){
				if (c == 2 || c == 3) {
					*(*(board + i) + j) += 10;
				
				}
			}//t = 1
			else{
				if (c == 3) {
					*(*(board + i) + j) += 10;

				
				}
			}
		}//for2
	}//for1


	for (i = 0; i < boardRowSize; ++i){
		for (j = 0; j < boardColSize; ++j){
			*(*(board + i) + j) /= 10;
		}//for2
	}//for1
}