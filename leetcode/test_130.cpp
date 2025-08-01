#include <vector>
#include <iostream>
#include <cassert>
#include "130.cpp" // Include the solution file

using namespace std;

void test_no_O() {
    Solution sol;
    vector<vector<char>> board = {{"X","X","X","X"},{"X","O","O","X"},{"X","X","O","X"},{"X","O","X","X"}};
    sol.solve(board);
    vector<vector<char>> expected = {{"X","X","X","X"},{"X","X","X","X"},{"X","X","X","X"},{"X","O","X","X"}};
    assert(board == expected);
}

void test_O_on_border() {
    Solution sol;
    vector<vector<char>> board = {
        {'O', 'X', 'X'},
        {'X', 'X', 'X'},
        {'X', 'X', 'O'}
    };
    sol.solve(board);
    vector<vector<char>> expected = {
        {'O', 'X', 'X'},
        {'X', 'X', 'X'},
        {'X', 'X', 'O'}
    };
    assert(board == expected);
}

void test_O_surrounded_by_X() {
    Solution sol;
    vector<vector<char>> board = {
        {'X', 'X', 'X'},
        {'X', 'O', 'X'},
        {'X', 'X', 'X'}
    };
    sol.solve(board);
    vector<vector<char>> expected = {