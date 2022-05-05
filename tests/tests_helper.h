#pragma once

#include "catch2/catch.hpp"
#include "processdata.hpp"
#include "matrix.hpp"
#include <algorithm>
#include <iostream>

void exactMatrix(bool** user, std::vector<std::vector<bool>> expected, int n) {
    
    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){
            if( user[i][j] != expected[i][j]){ 
                UNSCOPED_INFO("Incorrect value at i=" + std::to_string(i) + ", j=" + std::to_string(j));
             }
            REQUIRE(user[i][j]==expected[i][j]);
        }
    }
}

void exactDistMatrix(int** user, std::vector<std::vector<int>> expected, int n) {
    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){
            if( user[i][j]!=expected[i][j]){ 
                UNSCOPED_INFO("Incorrect value at i=" + std::to_string(i) + ", j=" + std::to_string(j));
             }
            REQUIRE(user[i][j]==expected[i][j]);
        }
    }
}

