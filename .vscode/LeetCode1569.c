#define MOD 1000000007
#define MAX 1000

int comb[MAX][MAX];

void ACTG(){
    for (int i = 0; i < MAX; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = (int)(((long long)comb[i - 1][j - 1] + comb[i -1][j]) % MOD);
        }
    }
}

int count(int *nums, int numsSize) {
    if (numsSize <= 2) {
        return 1;
    }

    int left[numsSize], right[numsSize];
    int l = 0, r = 0;
    int root = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < root) {
            left[l++] = nums[i];
        } else {
            right[r++] = nums[i];
        }
    }

    int left_c = count(left, l);
    int right_c = count(right, r);

    int cam = (int)((((long long)comb[l + r][l] * left_c) % MOD * right_c) % MOD);
    
    return cam;
}

int numOfWays(int* nums, int numsSize) {
    ACTG();
    return (count(nums, numsSize) - 1 + MOD) % MOD;
}
