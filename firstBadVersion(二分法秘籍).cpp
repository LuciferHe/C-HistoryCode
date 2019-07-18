int firstBadVersion(int n) {
	if (isBadVersion(1)){
		return 1;
	}
	else{//n > 1
		int left = 1, mid, right = n;
		//mid = (left + right) / 2; 相加有溢出的风险
		mid = left + (right - left) / 2;

		while (mid != left){
			if (isBadVersion(mid)){
				right = mid;
			}
			else{
				left = mid;
			}
			mid = left + (right - left) / 2;

			if (DEBUG) { printf("mid: %d\n\n", mid); }
		}
		return left + 1;
	}
}