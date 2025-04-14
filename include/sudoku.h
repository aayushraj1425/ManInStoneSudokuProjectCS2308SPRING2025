/**
 * @file sudoku.h
 * @brief Core Sudoku solving and board generation functions.
 *
 * This header file declares functions essential for solving Sudoku puzzles
 * and validating board states. It includes:
 * - A backtracking Sudoku solver.
 * - A cell validation function to ensure valid number placement.
 * - A board generation stub for creating Sudoku puzzles.
 *
 * All functions operate on dynamically allocated 9x9 Sudoku boards
 * represented as `int**`, where empty cells are denoted by 0.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#ifndef SUDOKUPROJECT_SUDOKU_H
#define SUDOKUPROJECT_SUDOKU_H

#include <iostream>

/**
 * @brief Validates if a number can be placed in a specific cell of the Sudoku board.
 *
 * This function checks whether placing the number `k` in the cell at row `r` and column `c`
 * of the given Sudoku board is valid. It ensures that the number does not violate Sudoku rules:
 * - The number must not already exist in the same row.
 * - The number must not already exist in the same column.
 * - The number must not already exist in the same 3x3 subgrid.
 *
 * @param BOARD A dynamically allocated 9x9 Sudoku board
 * @param r The row index of the cell to validate.
 * @param c The column index of the cell to validate.
 * @param k The number to validate for placement.
 * @return `true` if the number is valid for the cell,
 *         `false` otherwise.
 */
bool isValid(int** BOARD, const int& r, const int& c, const int& k);

/**
 * @brief Solves the Sudoku board using a basic backtracking algorithm.
 *
 * This function attempts to solve the given Sudoku board by recursively filling empty cells
 * with numbers from 1 to 9 following the Sudoku rules:
 * - The number must not already exist in the same row.
 * - The number must not already exist in the same column.
 * - The number must not already exist in the same 3x3 subgrid.
 *
 * @param BOARD A dynamically allocated 9x9 Sudoku board.
 * @param r The starting row index for solving (default is 0).
 * @param c The starting column index for solving (default is 0).
 * @return `true` if the board is successfully solved, `false` otherwise.
 */
bool solveBoard(int** BOARD, const int& r = 0, const int& c = 0);


// ========================= Efficient Solutions ==========================

/**
 * @brief Finds the next empty cell using the Minimum Remaining Value (MRV) heuristic.
 *
 * This function identifies the next empty cell on the Sudoku board that has the fewest
 * valid number options left. It helps optimize the solving process by reducing the
 * branching factor in the backtracking algorithm.
 *
 * @param BOARD A dynamically allocated 9x9 Sudoku board.
 * @return A `std::tuple<int, int, int>` containing:
 *         - The row index of the selected cell.
 *         - The column index of the selected cell.
 *         - The number of valid options for that cell.
 *         If no empty cells are found, returns `{-1, -1, 0}`.
 */
std::tuple<int, int, int> findNextCell(int** BOARD);

/**
 * @brief Solves the Sudoku board using backtracking and the MRV heuristic.
 *
 * This function combines a recursive backtracking approach with the Minimum Remaining Value (MRV)
 * heuristic to optimize the solving process. Uses findNextCell(int** BOARD) function to selects 
 * the next cell.
 * 
 * @param BOARD A dynamically allocated 9x9 Sudoku board.
 * @return `true` if the board is successfully solved, `false` otherwise.
 */
bool solveBoardEfficient(int** BOARD);

/**
 * @brief Solves the Sudoku board using either basic or efficient solving methods.
 *
 * Solves the Sudoku board with either the basic algorithm or the optimized approach 
 * based on the 'efficient' flag.
 *
 * @param board A dynamically allocated 9x9 Sudoku board.
 * @param efficient A boolean flag indicating whether to use the efficient solving method.
 *                  - `true`: Use the MRV heuristic for solving.
 *                  - `false`: Use the basic backtracking algorithm.
 * @return `true` if the board is successfully solved, `false` otherwise.
 */
bool solve(int** board, const bool& efficient = false);

#endif //SUDOKUPROJECT_SUDOKU_H