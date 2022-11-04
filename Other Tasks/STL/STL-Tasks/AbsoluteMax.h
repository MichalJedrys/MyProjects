#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <sstream>

using namespace std;

int AbsMax(string Numbers) {

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

    if (Nums.size() == 0) {
        return 0;
    }

    sort(Nums.begin(), Nums.end());

    vector<int>::iterator it_max, it_min;
    it_max = max_element(Nums.begin(), Nums.end());
    it_min = min_element(Nums.begin(), Nums.end());

    if (abs(*it_min) > *it_max) {
        return abs(*it_min);
    }
    else {
        return *it_max;
    }
}