#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <sstream>

using namespace std;

void RmvNums(string Numbers, vector<int>& RevNums) {

    stringstream str(Numbers);
    string temp;
    vector <string> strNums;
    vector <int> Nums;
    while (str >> temp) {
        strNums.push_back(temp);
    }
    for (auto j : strNums) {
        Nums.push_back(stoi(j));
    }
    sort(Nums.begin(), Nums.end());

    vector<int>::iterator it;
    it = unique(Nums.begin(), Nums.end());
    Nums.resize(distance(Nums.begin(), it));

    for (auto k : Nums) {
        RevNums.push_back(k);
    }


}