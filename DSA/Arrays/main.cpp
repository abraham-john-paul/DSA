// #include "maxAbsoluteDifference.hpp"
// #include "maxSumContiguousSubArray.hpp"
// #include "AddOneToNumber.hpp"
// #include "maxNonNegetiveSubArray.hpp"
// #include "RotateArray.hpp"
// #include "Flip.hpp"
// #include "SubMatrixSum.hpp"
// #include "SubMatrixSumQueries.hpp"
// #include "MaxDistance.hpp"
#include "MinimumSwaps.hpp"
// #include "commonOps.hpp"

int main() {
    // Max Absolute Difference
    // vector<int> A = {2};
    // cout << maxArr(A);
    
    // Max Contiguous SubArray Sum
    // vector<int> A = { -120, -202, -293, -60, -261, -67, 10, 82, -334, -393, -428, -182, -138, -167, -465, -347, -39, -51, -61, -491, -216, -36, -281, -361, -271, -368, -122, -114, -53, -488, -327, -182, -221, -381, -431, -161, -59, -494, -406, -298, -268, -425, -88, -320, -371, -5, 36, 89, -194, -140, -278, -65, -38, -144, -407, -235, -426, -219, 62, -299, 1, -454, -247, -146, 24, 2, -59, -389, -77, -19, -311, 18, -442, -186, -334, 41, -84, 21, -100, 65, -491, 94, -346, -412, -371, 89, -56, -365, -249, -454, -226, -473, 91, -412, -30, -248, -36, -95, -395, -74, -432, 47, -259, -474, -409, -429, -215, -102, -63, 80, 65, 63, -452, -462, -449, 87, -319, -156, -82, 30, -102, 68, -472, -463, -212, -267, -302, -471, -245, -165, 43, -288, -379, -243, 35, -288, 62, 23, -444, -91, -24, -110, -28, -305, -81, -169, -348, -184, 79, -262, 13, -459, -345, 70, -24, -343, -308, -123, -310, -239, 83, -127, -482, -179, -11, -60, 35, -107, -389, -427, -210, -238, -184, 90, -211, -250, -147, -272, 43, -99, 87, -267, -270, -432, -272, -26, -327, -409, -353, -475, -210, -14, -145, -164, -300, -327, -138, -408, -421, -26, -375, -263, 7, -201, -22, -402, -241, 67, -334, -452, -367, -284, -95, -122, -444, -456, -152, 25, 21, 61, -320, -87, 98, 16, -124, -299, -415, -273, -200, -146, -437, -457, 75, 84, -233, -54, -292, -319, -99, -28, -97, -435, -479, -255, -234, -447, -157, 82, -450, 86, -478, -58, 9, -500, -87, 29, -286, -378, -466, 88, -366, -425, -38, -134, -184, 32, -13, -263, -371, -246, 33, -41, -192, -14, -311, -478, -374, -186, -353, -334, -265, -169, -418, 63, 77, 77, -197, -211, -276, -190, -68, -184, -185, -235, -31, -465, -297, -277, -456, -181, -219, -329, 40, -341, -476, 28, -313, -78, -165, -310, -496, -450, -318, -483, -22, -84, 83, -185, -140, -62, -114, -141, -189, -395, -63, -359, 26, -318, 86, -449, -419, -2, 81, -326, -339, -56, -123, 10, -463, 41, -458, -409, -314, -125, -495, -256, -388, 75, 40, -37, -449, -485, -487, -376, -262, 57, -321, -364, -246, -330, -36, -473, -482, -94, -63, -414, -159, -200, -13, -405, -268, -455, -293, -298, -416, -222, -207, -473, -377, -167, 56, -488, -447, -206, -215, -176, 76, -304, -163, -28, -210, -18, -484, 45, 10, 79, -441, -197, -16, -145, -422, -124, 79, -464, -60, -214, -457, -400, -36, 47, 8, -151, -489, -327, 85, -297, -395, -258, -31, -56, -500, -61, -18, -474, -426, -162, -79, 25, -361, -88, -241, -225, -367, -440, -200, 38, -248, -429, -284, -23, 19, -220, -105, -81, -269, -488, -204, -28, -138, 39, -389, 40, -263, -297, -400, -158, -310, -270, -107, -336, -164, 36, 11, -192, -359, -136, -230, -410, -66, 67, -396, -146, -158, -264, -13, -15, -425, 58, -25, -241, 85, -82, -49, -150, -37, -493, -284, -107, 93, -183, -60, -261, -310, -380 };
    // cout << maxSubArray(A);

    // Number Plus 1
    // vector<int> A = {0, 1, 2, 4};
    // auto ans =  plusOne(A);
    // for (const int e : ans) {
    //     cout << e << " ";
    // }

    // Max Sum SubArray
    // vector<int> A = {1967513926, 1540383426, -1303455736, -521595368};
    // auto ans =  maxset(A);
    // for (const int e : ans) {
    //     cout << e << " ";
    // }

    // Rotate Array
    // vector<vector<int>> A = {
    //     {1, 2},
    //     {3, 4}
    // };
    // solve(A);
    // printMatrix(A);

    // Flip
    // string A = "111";
    // auto ans = flip(A);
    // for (const auto e : ans) {
    //     cout << e << " ";
    // }

    // SubMatrix Sum
    // vector<vector<int>> A = {
    //     {1, 1},
    //     {1, 1}
    // };
    // cout << solve(A);

    // SubMatrix Sum Queries
    // vector<vector<int>> A = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };
    // vector<int> B = { 1, 2 };
    // vector<int> C = { 1, 2 };
    // vector<int> D = { 2, 3 };
    // vector<int> E = { 2, 3 };  
    // auto ans = solve(A, B, C, D, E);
    // printArray(ans);

    // Max Distance
    // vector<int> A = { 100, 100, 100, 100 };
    // cout << maximumGap(A);

    // Minimum Swaps
    vector<int> A = { 2255, 6353, 7832, 9990, 516, 9853, 7018, 3337, 3008, 6158, 679, 2954, 2024, 2807, 1944, 6596, 7992, 2942, 9355, 788, 65, 2966, 9276, 1064, 1112, 6197, 4615, 8140, 30, 478, 5360, 7585, 8853, 9481, 1099, 8781, 9514, 4603, 8209, 7455, 5225, 6740, 4734, 4942, 4475, 4995, 4086, 6448, 1408, 2446, 4675, 92, 4942, 7421, 6302, 8226, 431, 2463, 5762, 2681, 1877, 2121, 3450, 5930, 9743, 5045, 9977, 906, 9293, 5441, 6825, 3244, 7021, 3910, 7866, 1013, 8227, 7926, 9226, 8710, 7088, 7761, 3413, 4200, 1671, 4526, 9890, 9594, 257, 3212, 8341, 9641, 2060, 5072, 2776, 4084, 4988, 501, 4304, 3685, 5424, 5713, 7920, 3115, 187, 3915, 3971, 7755, 8802, 4439, 8104, 5610, 5007, 1348, 4449, 9993, 17, 6395, 5539, 3415, 6500, 9899, 9049, 8197, 1419, 7112, 5823, 4739, 7975, 6915, 5852, 4072, 1694, 4353, 8867, 7362, 3410, 8415, 4060, 1353, 2342, 1712, 9038, 5421, 5772, 9291, 1611, 2822, 7927, 9644, 9236, 6052, 9592, 2206, 28, 3772, 1694, 2085, 6137, 4683, 655, 4604, 4979, 1948, 661, 9333, 6319, 257, 8146, 5744, 3533, 6508, 6792, 338, 5507, 4191, 7116, 8174, 1577, 1045, 3337, 86, 5667, 9341, 1606, 558, 7382, 8198, 7954, 225, 7154, 7780, 1290, 1269, 9782, 5909, 6713, 3605, 5672, 8661, 6988, 4669, 1954, 7852, 5580, 5893, 6242, 9970, 2892, 4471, 4272, 3072, 8475, 9925, 8930, 442, 5873, 1128, 2204, 2384, 3532, 970, 3543, 448, 4699, 2630, 7742, 1563, 1626, 3552, 3030, 3124, 4535, 650, 5330, 3862, 3799, 3011, 7809, 9538, 4567, 6431, 5775, 6903, 6675, 7459, 5750, 4193, 9102, 3352, 4107, 1483, 7454, 8293, 5044, 9638, 4995, 5558, 9882, 2316, 2614, 9934, 9669, 1486, 762, 4598, 883, 3279, 6893, 1958, 9703, 7636, 5217, 8460, 3711, 2173, 1677, 9273, 1191, 7967, 6001, 9935, 7241, 2552, 4373, 8518, 2801, 3310, 839, 3715, 7410, 2663, 2894, 1335, 8993, 4987, 6888, 4139, 4324, 4024 };
    // vector<int> A = { 5, 17, 100, 11 };
    int B = 1732;
    cout << solve(A, B);

    return 0;
}