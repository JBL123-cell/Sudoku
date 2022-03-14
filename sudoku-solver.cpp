#include "sudoku-solver.h"

#include "sudoku-solver.h"
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<vector<int>>> nfield;


bool find_zeros(const vector<vector<int>> & field, int & row, int & column) {
  for (row = 0; row < 9; row++) {
    for (column = 0; column < 9; column++) {
      if(field[row][column] == 0) {
        return true;
      }
    }
  }
  return false;
}

bool check_row(const vector<vector<int>> & field, int row, int value) {
  for (int column = 0; column < 9; column++) {
    if (field[row][column] == value) {
      return true;
    }
  }
  return false;
}


bool check_column(const vector<vector<int>> & field, int column, int value) {
  for (int row = 0; row < 9; row++) {
    if (field[row][column] == value) {
      return true;
    }
  }
  return false;
}


bool check_square(const vector<vector<int>> & field, int startRow, int startColumn, int value) {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (field[row + startRow][column + startColumn] == value) {
        return true;
      }
    }
  }
  return false;
}

bool is_available(const vector<vector<int>> & field, int row, int column, int value) {
  return !check_row(field, row, value)       &&
         !check_column(field, column, value) &&
         !check_square(field, row - row % 3 , column - column % 3, value);
}

vector<vector<vector<int>>> sudoku(vector<vector<int>> & field) {
  int row, column;
  if (!find_zeros(field, row, column)) {
    nfield.push_back(field);
    return nfield;
  }
  for (int num = 1; num <= 9; num++) {
    if (is_available(field, row, column, num)) {
      field[row][column] = num;
      sudoku(field);
      field[row][column] = 0;
    }
  }
  return nfield;
}

pair<size_t, vector<vector<int>>> sudoku_solve(const vector<vector<int>> &field){
  vector<vector<int>> field_copy;
  copy(field.begin(), field.end(), back_inserter(field_copy));
  vector<vector<vector<int>>> S = sudoku(field_copy);
  int size_t = S.size();
  return make_pair(size_t, S[0]);
}