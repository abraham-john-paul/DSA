#include "../header.h"

// #include "Combinations.hpp"
// #include "Permutations.hpp"
// #include "generateParanthesis.hpp"
// #include "LetterPhone.hpp"
// #include "AllUNiquePermutations.hpp"
// #include "NoOfSquarefulArrays.hpp"
// #include "RemoveInvalidParanthesis.hpp"
// #include "CombinationSum.hpp"
// #include "CombinationSum2.hpp"
#include "HorizontalAndVerticalSums.hpp"
// #include "NQueens.hpp"

int main() {
    // Combinations
    // int A = 5;
    // int B = 3;
    // printMatrix(combine(A, B)); 

    // Permutations
    // vector<int> A = {1, 2, 3};
    // printMatrix(permute(A));
    // return 0;

    // Generate Paranthesis
    // int A = 3;
    // printArray(generateParenthesis(A));

    // Letter Phone
    // string A = "23";
    // printArray(letterCombinations(A));

    // All Unique Permutations
    // vector<int> A = {1, 2, 3};
    // printMatrix(permute(A));

    // NoOfSquarefulArrays
    // vector<int> A = {49809, 367, 33, 16, 48};
    // printValue(solve(A));

    // Remove Invalid Paranthesis
    // string A = "((()()((";
    // printArray(solve(A));

    // Combination Sum
    // vector<int> A = {2, 3, 6, 7};
    // int B = 7;

    // printMatrix(combinationSum(A, B));

    // Combination Sum 2
    // vector<int> A = {10, 1, 2, 7, 6, 1, 5};
    // int B = 8;

    // printMatrix(combinationSum(A, B));

    // Horizontal And Vertical Sum
    int A = 2;
    vector<vector<int>> B = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    int C = 2;

    printValue(solve(A, B, C));

    // NQueens
    // int A = 4;
    // auto ans = solveNQueens(A);

    // for (const auto& v : ans) {
    //     printArray(v);
    // }

    return 0;
}

