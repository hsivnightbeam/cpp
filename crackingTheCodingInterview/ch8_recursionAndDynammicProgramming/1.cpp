/*
  Chapter 8 (Recursion and Dynamyic Programming) Problem 1
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// --method that that returns the number of ways possible to climb up the staircase starting from position step
//   it's a recursive solution, brute force
int sol1(int n, int step) {
    if (step == n)          //if we reach at our destination this is one possible way of climbing
        return 1;
    if (step > n)           //if we surpass the destination step this is not a possible way of climbing
        return 0;
    //if we are anywhere else, we still need to climb up with current step +1, +2, and +3 for the hops
    return sol1(n, step + 1) + sol1(n, step + 2) + sol1(n, step + 3);
}

// --method that that returns the number of ways possible to climb up the staircase
//   it's a recursive solution, with memoization, so we don't recalculate values
int sol2(int n, int step, std::vector<int> &memo) {
    if (step == n)          //if we reach at our destination this is one possible way of climbing
        return 1;
    if (step > n)           //if we surpass the destination step this is not a possible way of climbing
        return 0;
    if (memo[step] != -1)
        return memo[step];
    //if we are anywhere else, we still need to climb up with current step +1, +2, and +3 for the hops
    memo[step] = sol2(n, step + 1, memo) + sol2(n, step + 2, memo) + sol2(n, step + 3, memo);
    return memo[step];
}

// --method that that returns the number of ways possible to climb up the staircase
// --it's a iterative solution
int sol3 (int n, std::vector<int>& memo) {
    //we need to populate the first three els
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;
    for (int i = 3; i < n+1; i++) {
        memo[i] = memo[i-1] + memo[i-2] + memo[i-3];          //we really just need to save the last 3, we don't need to save all
    }
    return memo[n];
}


int main () {
    std::string input;                    //reads the input from user
    const std::string EXIT_CHAR = "q";
    do {
        std::cout << "Input the lenght of the escalator you want to calculate or q for exit" << std::endl;
        std::cin >> input;
        try {
            int n = std::stoi(input);
            std::vector<int> memo1(n+1, -1);
            std::vector<int> memo2(n+1, -1);
            std::cout << n << "th escalator can be reached in different ways brute force: "      << sol1(n, 0) << std::endl;
            std::cout << n << "th escalator can be reached in different ways with recursive memoization: " << sol2(n, 0, memo1) << std::endl;
            std::cout << n << "th escalator can be reached in different ways iteratively : " << sol3(n, memo2) << std::endl;
        } catch (std::invalid_argument& e) {
            //we couldn't convert the input to a number with stoi
            if (input != EXIT_CHAR)
                std::cout << "Wrong option" << std::endl;
        } catch (std::out_of_range& e) {
            std::cout << "Number too big..." << std::endl;
        }
    } while (input != EXIT_CHAR);

    return 0;
}
