// d2x: https://github.com/d2learn/d2x
// license: Apache-2.0
// file: dslings/hellomcpp.cpp
//
// Exercise: Automated Code Practice Teaching
//
// Tips:
//    This project is an automated code practice project built with the d2x tool. Run 'd2x checker'
//    in the project root directory to enter "compiler-driven development mode" for automatic
//    practice code detection. You need to modify code errors based on console error messages
//    and hints. After fixing all compilation errors and runtime checkpoints, you can delete or
//    comment out the d2x::wait() in the code to automatically proceed to the next exercise.
//
//      - d2x::wait: This function is used to separate different exercises. You can delete or comment
//        out this function call to proceed to the next exercise.
//      - d2x::assert_eq: This function is used for runtime checkpoints. You need to fix the code
//        errors to pass all checkpoints.
//      - D2X_YOUR_ANSWER: This macro is used to prompt you to modify the code, generally for code
//        completion (replace this macro with the correct code).
//
// Auto-Checker Command:
//
//   d2x checker hellomcpp
//

import std;

import d2x;

// You can observe "real-time" changes in the console when modifying the code

int main() {

    std::println("hello, mcpp!") // 0. Fix this compilation error

    int a = 1.1; // 1. Fix this runtime error - change int to double to pass the check

    d2x::assert_eq(a, 1.1); // 2. Runtime checkpoint - fix the code to pass all checkpoints (cannot delete checkpoint code directly)

    /* D2X_YOUR_ANSWER */ b = a; // 3. Fix this compilation error - give b a suitable type

    d2x::assert_eq(b, 1); // 4. Runtime checkpoint 2

    d2x::wait(); // 5. Delete or comment out to proceed to the next exercise (formal code practice)

    return 0;
}

//// --- More Detailed Introduction | | |
//                              V V V
/*

# [[ Console Output Interpretation ]]

 🌏 ▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ 0/2  -->> Display current exercise progress
                                                                                                                               
 ✗ hellocpp                 -->> Current detection status and exercise name
 + → dslings/hellocpp.cpp   -->> Current exercise file path
                                                                                                                               
 [ 23%]: cache compiling.release dslings/hellocpp.cpp -->> Display compilation status
 error: dslings/hellocpp.cpp:29:39: error: found ':' in nested-name-specifier, expected '::'
    29 |     std::cout << "hello, mcpp!" << std:endl; // 0. Fix this compilation error
       |                                       ^
       |                                       ::
   ▼ 5 more lines below...

🤖:   AI Disabled - https://github.com/d2learn/d2x  -->> Display AI status/information

*/