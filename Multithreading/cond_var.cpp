// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <condition_variable>

// using namespace std;
    
// // void print5(int n) {
// //     cout << "printNot5";
// //     unique_lock<mutex> ul(m);
// //         for(int i = 5; i <= n; i+=5) {
// //             // ul.lock();
// //             cv.wait(ul, []() {
// //                 return !cond; });
// //             cout << i << " ";
// //             cond = true;
// //             // ul.unlock();
// //             cv.notify_one();
// //         }
// // }

// // void printNot5(int n) {
// //     cout << "printNot5";
// //     unique_lock<mutex> ul(m);
// //         for(int i = 1; i <= n; i++) {
// //             // ul.lock();
// //             cv.wait(ul, []() { return cond; });
// //             if(i % 5 == 0) {
// //                 cond = false;
// //                 // ul.unlock();
// //                 cv.notify_one();
// //                 continue;
// //             }
// //             cout << i << " ";
// //             // ul.unlock();
// //         }
// // }
//     mutex m;
//     condition_variable cv;
//     bool cond = true;
// int main()
// {
//     int n = 20;

//     thread t1([n]() {
//         unique_lock<mutex> ul(m);
//         for(int i = 5; i <= n; i+=5) {
//             // ul.lock();
//             cv.wait(ul, [cond]() {
//                 return !cond; });
//             cout << i << " ";
//             cond = true;
//             // ul.unlock();
//             cv.notify_one();
//         }
//     });
    
//     thread t2([n]() {
//         unique_lock<mutex> ul(m);
//         for(int i = 1; i <= n; i++) {
//             // ul.lock();
//             cv.wait(ul, [cond]() { return cond; });
//             if(i % 5 == 0) {
//                 cond = false;
//                 // ul.unlock();
//                 cv.notify_one();
//                 continue;
//             }
//             cout << i << " ";
//             // ul.unlock();
//         }
//     });
    
//     t1.join();
//     t2.join();

//     return 0;
// }

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

mutex mtx;
condition_variable cv;
bool isOddTurn = true;

int main() {
    int n = 20;
    
    auto func = [](int start, int end, function<bool(void)> pred) {
        unique_lock<mutex> ul(mtx);
        for(int i = start; i <= end; i += 2) {
            cv.wait(ul, pred);
            cout << i << " ";
            isOddTurn = !isOddTurn;
            cv.notify_one();
        }
    };
    
    thread odd(func, 1, n, []() { return isOddTurn; });
    
    thread even(func, 2, n, []() { return !isOddTurn; });
    
    odd.join();
    even.join();
    
    return 0;
}

