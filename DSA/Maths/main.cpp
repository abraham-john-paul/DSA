// #include "MagicNumbers.hpp"
// #include "ModSum.hpp"
// #include "PrimeModuloInverse.hpp"
// #include "VeryLargePower.hpp"
// #include "PairSumDivisibleByM.hpp"
// #include "PowerOf3.hpp"
// #include "GCD/PUBG.hpp"
// #include "GCD/DeleteOne.hpp"
// #include "GCD/LargestCoprimeDivisor.hpp"
// #include "GCD/AllGCDPairs.hpp"
// #include "Primes/CountOfDivisors.hpp"
// #include "Primes/Primes1toN.hpp"
// #include "Primes/OddFibbonacci.hpp"
// #include "Primes/FactorialArray.hpp"
// #include "Primes/LuckyNumbers.hpp"
// #include "Combinatorics/ComputenCrmodM.hpp"
// #include "Combinatorics/ComputenCrmodP.hpp"
// #include "Combinatorics/Summation.hpp"
// #include "Combinatorics/NextPermutation.hpp"
// #include "Combinatorics/Divis0ion.hpp"
// #include "Combinatorics/MinXORValue.hpp"
// #include "Combinatorics/SingleNumberIII.hpp"
// #include "Combinatorics/SingleNumberII.hpp"
// #include "Combinatorics/ConsecutiveNumberSum.hpp"
#include "BitManipulation/StrangeEquality.hpp"

#include "../commonOps.hpp"

int main() {
    // Magic Numbers
    // int A = 10;
    // printValue(solve(A)); 
    
    // ModSum
    // vector<int> A = { 686, 675, 758, 659, 377, 965, 430, 220, 599, 699 };
    // printValue(solve(A));

    // PrimeModuloInverse
    // int A = 6;
    // int B = 23;
    // printValue(solve(A, B));

    // Very Large Power
    // int A = 2;
    // int B = 27;
    // cout << solve(A, B);

    //PairSum Div By M
    // vector<int> A = { 1, 2, 3, 4, 5 };
    // int B = 2;
    // cout << solve(A, B);

    // Power of 3
    // int A = 17;
    // printArray(solve(A));

    // PUBG
    // vector<int> A = { 2, 3, 4 };
    // printValue(solve(A));

    // Delete One
    // vector<int> A = { 5, 15, 30 };
    // printValue(solve(A));

    // Largest Coprime Divisor
    // int A = 22;
    // int B = 38;
    // cout << cpFact(A, B);

    // GCD of all pairs
    // vector<int> A = {2, 2, 2, 2, 8, 2, 2, 2, 10};
    // // { 634, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 2, 2, 844, 4, 4, 2, 2, 1, 2, 2, 4, 1, 1, 4, 1, 1, 1, 1, 1, 4, 1, 4, 1, 1, 1, 4, 2, 4, 780, 20, 10, 6, 1, 2, 26, 4, 1, 15, 12, 5, 3, 1, 1, 1, 4, 65, 12, 1, 1, 5, 20, 2, 4, 20, 140, 70, 2, 1, 2, 2, 4, 1, 5, 28, 35, 7, 1, 1, 1, 28, 5, 28, 1, 1, 5, 140, 2, 2, 10, 70, 490, 2, 1, 2, 2, 2, 1, 5, 14, 35, 7, 1, 1, 1, 14, 5, 14, 1, 1, 5, 70, 2, 2, 6, 2, 2, 726, 1, 2, 22, 2, 1, 3, 6, 1, 33, 1, 1, 11, 2, 1, 6, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 677, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 86, 2, 2, 1, 1, 2, 1, 1, 1, 1, 43, 2, 2, 1, 1, 1, 1, 2, 2, 2, 26, 2, 2, 22, 1, 2, 286, 2, 1, 1, 2, 1, 11, 1, 1, 11, 2, 13, 2, 1, 1, 1, 2, 2, 4, 4, 4, 2, 2, 1, 2, 2, 376, 1, 1, 8, 1, 1, 1, 1, 1, 4, 1, 8, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 359, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 15, 5, 5, 3, 1, 1, 1, 1, 1, 3, 75, 5, 3, 1, 1, 1, 1, 25, 3, 1, 1, 5, 25, 2, 4, 12, 28, 14, 6, 1, 2, 2, 8, 1, 3, 168, 7, 21, 1, 1, 1, 28, 1, 168, 1, 1, 1, 28, 1, 1, 5, 35, 35, 1, 1, 1, 1, 1, 1, 5, 7, 595, 7, 1, 1, 1, 7, 5, 7, 1, 1, 5, 35, 1, 1, 3, 7, 7, 33, 1, 1, 11, 1, 1, 3, 21, 7, 693, 1, 1, 11, 7, 1, 21, 1, 1, 1, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 943, 1, 1, 1, 1, 1, 23, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 193, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1, 43, 11, 1, 1, 1, 1, 1, 11, 1, 1, 473, 1, 1, 1, 1, 1, 1, 1, 2, 4, 4, 28, 14, 2, 1, 2, 2, 4, 1, 1, 28, 7, 7, 1, 1, 1, 28, 1, 28, 1, 1, 1, 28, 1, 1, 65, 5, 5, 1, 1, 1, 13, 1, 1, 25, 1, 5, 1, 1, 1, 1, 1, 325, 1, 1, 1, 5, 25, 2, 4, 12, 28, 14, 6, 1, 2, 2, 8, 1, 3, 168, 7, 21, 1, 1, 1, 28, 1, 168, 1, 1, 1, 28, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 23, 1, 1, 1, 1, 1, 23, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 619, 1, 1, 1, 1, 5, 5, 5, 1, 1, 1, 1, 1, 1, 5, 1, 5, 1, 1, 1, 1, 1, 5, 1, 1, 1, 635, 5, 2, 4, 20, 140, 70, 2, 1, 2, 2, 4, 1, 25, 28, 35, 7, 1, 1, 1, 28, 25, 28, 1, 1, 700, 5 };
    // auto ans = solve(A);
    // printArray(ans);

    // Count of Divisors
    // vector<int> A = {8, 9, 10};
    // auto ans = solve(A);
    // printArray(ans);

    // Primes from 1 to N
    // int N = 17;
    // auto ans = findPrimes(N);
    // printArray(ans);

    // Odd fibonnacci
    // int A = 30;
    // int B = 36;
    // printValue(solve(A, B));

    // Factorial Array
    // vector<int> A = { 2, 3, 4, 5, 6};
    // printValue(solve(A));

    // Lucky Numbers
    // int A = 8;
    // printValue(solve(A));

    // Compute nCr % M
    // int A = 38;
    // int B = 5;
    // int C = 81;
    // printValue(solve(A, B, C));

    // Compute nCr % M
    // int A = 6;
    // int B = 2;
    // int C = 13;
    // printValue(solve(A, B, C));

    // Summation - pending
    // int A = 39;
    // printValue(solve(A));

    // Next Permutation
    // vector<int> A = {1, 2, 4, 3};
    // printArray(nextPermutation(A));
    // printArray(A);

    // Division 
    // int A = -2147483648;
    // int B = -10000000;
    // printValue(solve(A, B));

    // Min XOR Value
    // vector<int> A = {0, 2, 5, 7};
    // printValue(findMinXor(A));

    // Single Number III
    // vector<int> A = { 408, 478, 74, 624, 74, 204, 705, 624, 337, 408, 478, 204 };
    // printArray(solve(A));

    //Single Number II
    // vector<int> A = { 0, 0, 0, 1};
    // printValue(solve(A));

    // Consequetive Number Sum
    // int A = 15;
    // printValue(solve(A));

    // Strange Equality
    int A = 5;
    printValue(solve(A));

    return 0;
}