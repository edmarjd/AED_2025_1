int teste (int *nums ) {

// casos bases
    if (sizeof(*nums) < 3) {
        return 1;
    }

    if (nums[0]) {
        return 1;
    }

    int pivo = (( *nums)/ 2) + 1;

    int *subEsq = (int *) malloc (1000 * sizeof(int));
    int *subDir = (int *) malloc (1000 * sizeof(int));

    for (int i = 1 ; i < pivo; i++) {
        *subEsq = nums[i];
    }

    for (int i = pivo; i < sizeof(nums); i++) {
        *subDir = nums[i];
    }

    teste(subEsq - 1);
    teste(subDir - 1);

    return teste(subEsq) * pivo * teste(subDir);

    
}


int numOfWays(int* nums, int numsSize) {
    
    numsSize = teste(nums);

    return numsSize;
}