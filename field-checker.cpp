#include <iostream>
#include "field-checker.h"
#include <list>
#include <vector>
#include<iostream>
#include <set>
#include "sudoku-solver.h"
using namespace std;

int N = 9;

bool valid_row(int row, const std::vector<std::vector<int>> &solution){
  set<int> st;
  for(int col = 0; col < 9; col++){
    if(solution[row][col] < 1 || solution[row][col] > 9){
      return false;
    }
    else
    {
        if(!st.count(solution[row][col])){
          st.insert(solution[row][col]);
        } else{
          return false;
        }
    }
  }
  return true;
}

bool valid_col(int col, const std::vector<std::vector<int>> &solution){
  set<int> st;
  for(int row = 0; row < 9; row++){
    if(solution[row][col] < 1 || solution[row][col] > 9){
      return false;
    }
    else {
      if(!st.count(solution[row][col])){
        st.insert(solution[row][col]);
      } else{
        return false;
      }
    }
  }
  return true;
}

bool valid_squares(const std::vector<std::vector<int>> &solution){
  for(int row = 0; row < 9; row = row + 3){
    for(int col = 0; col < 9; col = col + 3){
      set<int> st;
      for(int row_sqr = row; row_sqr < row + 3; row_sqr++){
        for(int col_sqr = col; col_sqr < col + 3; col_sqr++){
          if(solution[row_sqr][col_sqr] < 1 || solution[row_sqr][col_sqr] > 9){
            return false;
          }
          else{
            if(!st.count(solution[row][col])){
              st.insert(solution[row][col]);
            } else{
              return false;
            }
            }
          }
        }
      }
    }
  return true;
}

bool check_field(const std::vector<std::vector<int>> &init_field, const std::vector<std::vector<int>> &solution) {
  for(int i = 0; i < 9; i++){
    return (!valid_row(i, solution) & valid_col(i, solution) & valid_squares(solution)) == 0;
  }
}




