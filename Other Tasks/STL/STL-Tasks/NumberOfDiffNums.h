#pragma once
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

int NumOfDiffNums(string Numbers) {

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



    int size = Nums[0];
    Nums.erase(Nums.begin());

    if (Nums.size() == 0) {
        return 0;
    }

    sort(Nums.begin(), Nums.end());

    vector<int>::iterator it;
    it = unique(Nums.begin(), Nums.end());
    Nums.resize(distance(Nums.begin(), it));

    return Nums.size();
}