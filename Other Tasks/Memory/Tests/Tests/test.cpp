#include "pch.h"
#include "../ArrayTasks/Reversed-Array.h"
#include "../ArrayTasks/Copy-Array.h"
#include "../ArrayTasks/Copy-To-Two_Arrays.h"
#include "../ArrayTasks/Merge-Arrays.h"
#include "../ArrayTasks/Merge-Arrays_Sequencially.h"
#include "../ArrayTasks/Swap-Arrays.h"


//REVERSE ARRAY
TEST(RevTest, SimpleTest) {

	int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int arr2[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	reversedArray(10, arr1);
	for (int i = 0; i < 10; ++i) {
		EXPECT_EQ(arr1[i], arr2[i]);
	}
}

TEST(RevTest, MaxNumbers) {

	int arr1[6] = { 2147483643, 2147483644, 2147483645, 2147483646, 2147483647 };
	int arr2[6] = { 2147483647, 2147483646, 2147483645, 2147483644, 2147483643 };
	reversedArray(5, arr1);
	for (int i = 0; i < 5; ++i) {
		EXPECT_EQ(arr1[i], arr2[i]);
	}
}

TEST(RevTest, MinNumbers) {

	int arr1[6] = { -2147483643, -2147483644, -2147483645, -2147483646, -2147483647, -2147483648 };
	int arr2[6] = { -2147483648, -2147483647, -2147483646, -2147483645, -2147483644, -2147483643 };
	reversedArray(6, arr1);
	for (int i = 0; i < 6; ++i) {
		EXPECT_EQ(arr1[i], arr2[i]);
	}
}

TEST(RevTest, MixedNumbers) {

	int arr1[6] = { -452342, 1233, 675411, -1, 0, 77777777 };
	int arr2[6] = { 77777777, 0, -1, 675411, 1233, -452342 };
	reversedArray(6, arr1);
	for (int i = 0; i < 6; ++i) {
		EXPECT_EQ(arr1[i], arr2[i]);
	}
}

TEST(RevTest, EqualNumbers) {

	int arr1[5] = { 5, 5, 5, 5, 5 };
	int arr2[5] = { 5, 5, 5, 5, 5 };
	reversedArray(5, arr1);
	for (int i = 0; i < 5; ++i) {
		EXPECT_EQ(arr1[i], arr2[i]);
	}
}

TEST(RevTest, OneNumber) {

	int arr1[1] = { 78 };
	int arr2[1] = { 78 };
	reversedArray(1, arr1);
	for (int i = 0; i < 1; ++i) {
		EXPECT_EQ(arr1[i], arr2[i]);
	}
}

TEST(RevTest, Empty) {

	int arr1[5] = {};
	int arr2[5] = {};
	reversedArray(5, arr1);
	for (int i = 0; i < 5; ++i) {
		EXPECT_EQ(arr1[i], arr2[i]);
	}
}

TEST(RevTest, LongArrays) {

	int arr1[65000] = { 0 };
	int arr2[65000] = { 0 };
	reversedArray(65000, arr1);
	for (int i = 0; i < 65000; i++) {
		EXPECT_EQ(arr1[i], arr2[i]);
	}
}


//COPY ARRAY
TEST(CopyTest, SimpleTest) {

	int arr[10] = { -1, 7, 0, -5, 15, 0, 1, 3, -2, 0 };
	int arrCopy[10] = { 0 };
	int arrCheck[10] = { 7, 15, 1, 3, 0, 0, 0, -1, -5, -2 };
	copyArray(10, arr, arrCopy);
	for (int i = 0; i < 10; ++i) {
		EXPECT_EQ(arrCopy[i], arrCheck[i]);
	}
}

TEST(CopyTest, BigNumbers) {

	int arr[10] = { -2147483643, 1144283643, 0, -2133224643, 2147481143, 0, 2027434643, 947333643, -1147783333, 0 };
	int arrCopy[10] = { 0 };
	int arrCheck[10] = { 1144283643, 2147481143, 2027434643, 947333643, 0, 0, 0, -2147483643, -2133224643, -1147783333 };
	copyArray(10, arr, arrCopy);
	for (int i = 0; i < 10; ++i) {
		EXPECT_EQ(arrCopy[i], arrCheck[i]);
	}
}

TEST(CopyTest, MixedNumbers) {

	int arr[10] = { 63721, -54372, 0, -363771, -23782, 0, 12, -357681, -2, 0 };
	int arrCopy[10] = { 0 };
	int arrCheck[10] = { 63721, 12, 0, 0, 0, -54372, -363771, -23782, -357681, -2 };
	copyArray(10, arr, arrCopy);
	for (int i = 0; i < 10; ++i) {
		EXPECT_EQ(arrCopy[i], arrCheck[i]);
	}
}

TEST(CopyTest, EqualNumbers) {

	int arr[3] = { 1,1,1};
	int arrCopy[3] = { 0 };
	int arrCheck[3] = { 1,1,1 };
	copyArray(3, arr, arrCopy);
	for (int i = 0; i < 3; ++i) {
		EXPECT_EQ(arrCopy[i], arrCheck[i]);
	}
}

TEST(CopyTest, OneNumber) {

	int arr[1] = { 44 };
	int arrCopy[1] = { 0 };
	int arrCheck[1] = { 44 };
	copyArray(1, arr, arrCopy);
	for (int i = 0; i < 1; ++i) {
		EXPECT_EQ(arrCopy[i], arrCheck[i]);
	}
}

TEST(CopyTest, Empthy) {

	int arr[5] = {};
	int arrCopy[5] = {};
	int arrCheck[5] = {};
	copyArray(5, arr, arrCopy);
	for (int i = 0; i < 5; ++i) {
		EXPECT_EQ(arrCopy[i], arrCheck[i]);
	}
}

TEST(CopyTest, LongArrays) {

	int arr[65000] = {0};
	int arrCopy[65000] = {0};
	int arrCheck[65000] = {0};
	copyArray(65000, arr, arrCopy);
	for (int i = 0; i < 65000; ++i) {
		EXPECT_EQ(arrCopy[i], arrCheck[i]);
	}
}


//COPY ARRAY INTO TWO ARRAYS

TEST(CopyToTwoTest, SimpleTest) {

	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	int arr1[5];
	int arr2[5];
	int arr1Check[5] = {0,1,2,3,4};
	int arr2Check[5] = {5,6,7,8,9};
	copyToTwoArrays(10, arr, arr1, arr2);
	for (int i = 0; i < 5; ++i) {
		EXPECT_EQ(arr1[i], arr1Check[i]);
		EXPECT_EQ(arr2[i], arr2Check[i]);
	}
}

TEST(CopyToTwoTest, MaxNumbers) {

	int arr[6] = { 2147483642, 2147483643, 2147483644, 2147483645, 2147483646, 2147483647 };
	int arr1[3];
	int arr2[3];
	int arr1Check[3] = { 2147483642, 2147483643, 2147483644 };
	int arr2Check[3] = { 2147483645, 2147483646, 2147483647 };
	copyToTwoArrays(6, arr, arr1, arr2);
	for (int i = 0; i < 3; ++i) {
		EXPECT_EQ(arr1[i], arr1Check[i]);
		EXPECT_EQ(arr2[i], arr2Check[i]);
	}
}

TEST(CopyToTwoTest, OddNumber) {

	int arr[11] = { 1,2,3,4,5,6,7,8,9,10,11 };
	int arr1[5];
	int arr2[5];
	int arr1Check[5]={0};
	int arr2Check[5]={0};
	copyToTwoArrays(11, arr, arr1, arr2);
	for (int i = 0; i < 5; ++i) {
		EXPECT_EQ(arr1[i], arr1Check[i]);
		EXPECT_EQ(arr2[i], arr2Check[i]);
	}
}

TEST(CopyToTwoTest, HighOddNumber) {

	int arr[65001]={0};
	int arr1[32500];
	int arr2[32500];
	int arr1Check[32500] = { 0 };
	int arr2Check[32500] = { 0 };
	copyToTwoArrays(65001, arr, arr1, arr2);
	for (int i = 0; i < 32500; ++i) {
		EXPECT_EQ(arr1[i], arr1Check[i]);
		EXPECT_EQ(arr2[i], arr2Check[i]);
	}
}

TEST(CopyToTwoTest, LongArrays) {

	int arr[65000] = { 0 };
	int arr1[32500];
	int arr2[32500];
	int arr1Check[32500] = { 0 };
	int arr2Check[32500] = { 0 };
	copyToTwoArrays(65000, arr, arr1, arr2);
	for (int i = 0; i < 32500; ++i) {
		EXPECT_EQ(arr1[i], arr1Check[i]);
		EXPECT_EQ(arr2[i], arr2Check[i]);
	}
}

TEST(CopyToTwoTest, Empty) {

	int arr[10] = {};
	int arr1[5];
	int arr2[5];
	int arr1Check[5] = {};
	int arr2Check[5] = {};
	copyToTwoArrays(10, arr, arr1, arr2);
	for (int i = 0; i < 5; ++i) {
		EXPECT_EQ(arr1[i], arr1Check[i]);
		EXPECT_EQ(arr2[i], arr2Check[i]);
	}
}


//MERGE TWO ARRAYS

TEST(MergeArrays, SimpleTest) {

	int arr1[5] = { 0,1,2,3,4 };
	int arr2[5] = { 5,6,7,8,9 };
	int arr[10];
	int arrCheck[10] = { 0,1,2,3,4,5,6,7,8,9 };
	mergeArrays(5, 5, arr1, arr2, arr);
	for (int i = 0; i < 10; ++i) {
		EXPECT_EQ(arr[i], arrCheck[i]);
	}
}

TEST(MergeArrays, MixedNumbers) {

	int arr1[5] = { 537,6291,-2381,0,12 };
	int arr2[5] = { -5,51246,700,8771111,981 };
	int arr[10];
	int arrCheck[10] = { 537,6291,-2381,0,12,-5,51246,700,8771111,981 };
	mergeArrays(5, 5, arr1, arr2, arr);
	for (int i = 0; i < 10; ++i) {
		EXPECT_EQ(arr[i], arrCheck[i]);
	}
}

TEST(MergeArrays, BigNumbers) {

	int arr1[6] = { -2147483648, -2147483647, -2147483646, -2147483645, -2147483644, -2147483643 };
	int arr2[6] = { 2147483642, 2147483643, 2147483644, 2147483645, 2147483646, 2147483647 };
	int arr[12];
	int arrCheck[12] = { -2147483648, -2147483647, -2147483646, -2147483645, -2147483644, -2147483643, 2147483642, 2147483643, 2147483644, 2147483645, 2147483646, 2147483647 };
	mergeArrays(6, 6, arr1, arr2, arr);
	for (int i = 0; i < 12; ++i) {
		EXPECT_EQ(arr[i], arrCheck[i]);
	}
}

TEST(MergeArrays, LongArrays) {

	int arr1[32500] = {0};
	int arr2[32500] = {0};
	int arr[65000];
	int arrCheck[65000] = {0};
	mergeArrays(32500, 32500, arr1, arr2, arr);
	for (int i = 0; i < 65000; ++i) {
		EXPECT_EQ(arr[i], arrCheck[i]);
	}
}

TEST(MergeArrays, Empty) {

	int arr1[10] = {};
	int arr2[10] = {};
	int arr[20];
	int arrCheck[20] = {};
	mergeArrays(10, 10, arr1, arr2, arr);
	for (int i = 0; i < 20; ++i) {
		EXPECT_EQ(arr[i], arrCheck[i]);
	}
}

TEST(MergeArrays, DiffrentSizes) {

	int arr1[10] = {0,1,2,3,4,5,6,7,8,9};
	int arr2[5] = {21,22,23,24,25};
	int arr[15];
	int arrCheck[15] = {0};
	mergeArrays(10, 5, arr1, arr2, arr);
	for (int i = 0; i < 15; ++i) {
		EXPECT_EQ(arr[i], arrCheck[i]);
	}
}


//MERGE TWO ARRAYS SEQUENCIALLY

TEST(MergeArraysSequencially, SimpleTest) {

	int arr1[10] = { 12,-5,0,-17,34,10,0,5,0,-1 };
	int arr2[10] = { -2,0,3,12,-9,0,-15,11,0,3 };
	int arr[20];
	int arrCheck[20] = { 12,34,10,5,3,12,11,3,0,0,0,0,0,0,-5,-17,-1,-2,-9,-15 };
	mergeArraysSequencially(10, 10, arr1, arr2, arr);
	for (int i = 0; i < 20; ++i) {
		EXPECT_EQ(arr[i], arrCheck[i]);
	}
}

TEST(MergeArraysSequencially, MixedNumbers) {

	int arr1[5] = { 537,6291,-2381,0,-1122 };
	int arr2[5] = { -5,51246,700,0,981 };
	int arr[10];
	int arrCheck[10] = { 537,6291,51246,700,981,0,0,-2381,-1122,-5 };
	mergeArraysSequencially(5, 5, arr1, arr2, arr);
	for (int i = 0; i < 10; ++i) {
		EXPECT_EQ(arr[i], arrCheck[i]);
	}
}

TEST(MergeArraysSequencially, BigNumbers) {

	int arr1[6] = { -2147483648, 0, -2147483646, 2147483645, -2147483644, 0 };
	int arr2[6] = { 2147483642, 0, -2147483644, 2147483645, -2147483646, 2147483647 };
	int arr[12];
	int arrCheck[12] = { 2147483645,2147483642,2147483645,2147483647,0,0,0,-2147483648,-2147483646,-2147483644,-2147483644,-2147483646 };
	mergeArraysSequencially(6, 6, arr1, arr2, arr);
	for (int i = 0; i < 12; ++i) {
		EXPECT_EQ(arr[i], arrCheck[i]);
	}
}

TEST(MergeArraysSequencially, LongArrays) {

	int arr1[32500] = { 0 };
	int arr2[32500] = { 0 };
	int arr[65000];
	int arrCheck[65000] = { 0 };
	mergeArraysSequencially(32500, 32500, arr1, arr2, arr);
	for (int i = 0; i < 65000; ++i) {
		EXPECT_EQ(arr[i], arrCheck[i]);
	}
}

TEST(MergeArraysSequencially, EqualNumbers) {

	int arr1[5] = { 3,3,3,3,3 };
	int arr2[5] = { 3,3,3,3,3 };
	int arr[10];
	int arrCheck[10] = { 3,3,3,3,3,3,3,3,3,3 };
	mergeArraysSequencially(5, 5, arr1, arr2, arr);
	for (int i = 0; i < 10; ++i) {
		EXPECT_EQ(arr[i], arrCheck[i]);
	}
}

TEST(MergeArraysSequencially, Empty) {

	int arr1[10] = {};
	int arr2[10] = {};
	int arr[20];
	int arrCheck[20] = {};
	mergeArraysSequencially(10, 10, arr1, arr2, arr);
	for (int i = 0; i < 20; ++i) {
		EXPECT_EQ(arr[i], arrCheck[i]);
	}
}

TEST(MergeArraysSequencially, DiffrentSizes) {

	int arr1[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int arr2[5] = { 21,22,23,24,25 };
	int arr[15];
	int arrCheck[15] = {0};
	mergeArraysSequencially(10, 5, arr1, arr2, arr);
	for (int i = 0; i < 15; ++i) {
		EXPECT_EQ(arr[i], arrCheck[i]);
	}
}


//SWAP ARRAYS

TEST(SwapArrays, SimpleTest) {

	int arr1[5] = { 0,1,2,3,4 };
	int arr2[5] = { 9,8,7,6,5 };
	int arr1Check[5] = { 9,8,7,6,5 };
	int arr2Check[5] = { 0,1,2,3,4 };
	swapArrays(5, 5, arr1, arr2);
	for (int i = 0; i < 5; ++i) {
		EXPECT_EQ(arr1[i], arr1Check[i]);
		EXPECT_EQ(arr2[i], arr2Check[i]);
	}
}

TEST(SwapArrays, MixedNumbers) {

	int arr1[10] = { 17,-4,0,-82,188,545,-2,0,12,-499 };
	int arr2[10] = { -500,23,11,0,4,90,-2000,0,0,5 };
	int arr1Check[10] = { -500,23,11,0,4,90,-2000,0,0,5 };
	int arr2Check[10] = { 17,-4,0,-82,188,545,-2,0,12,-499 };
	swapArrays(10, 10, arr1, arr2);
	for (int i = 0; i < 10; ++i) {
		EXPECT_EQ(arr1[i], arr1Check[i]);
		EXPECT_EQ(arr2[i], arr2Check[i]);
	}
}

TEST(SwapArrays, BigNumbers) {

	int arr1[6] = { 2147483643, -2147483644, 2147483645, -2147483646, 2147483647, -2147483648 };
	int arr2[6] = { -2147483648, 2147483647, -2147483646, 2147483645, -2147483644, 2147483643 };
	int arr1Check[6] = { -2147483648, 2147483647, -2147483646, 2147483645, -2147483644, 2147483643 };
	int arr2Check[6] = { 2147483643, -2147483644, 2147483645, -2147483646, 2147483647, -2147483648 };
	swapArrays(6, 6, arr1, arr2);
	for (int i = 0; i < 6; ++i) {
		EXPECT_EQ(arr1[i], arr1Check[i]);
		EXPECT_EQ(arr2[i], arr2Check[i]);
	}
}

TEST(SwapArrays, LongArrays) {

	int arr1[60000] = { 4 };
	int arr2[60000] = { 10 };
	int arr1Check[60000] = { 10 };
	int arr2Check[60000] = { 4 };
	swapArrays(60000, 60000, arr1, arr2);
	for (int i = 0; i < 60000; ++i) {
		EXPECT_EQ(arr1[i], arr1Check[i]);
		EXPECT_EQ(arr2[i], arr2Check[i]);
	}
}

TEST(SwapArrays, Empty) {

	int arr1[5] = { };
	int arr2[5] = { 1,1,1,1,1 };
	int arr1Check[5] = { 1,1,1,1,1 };
	int arr2Check[5] = { };
	swapArrays(5, 5, arr1, arr2);
	for (int i = 0; i < 5; ++i) {
		EXPECT_EQ(arr1[i], arr1Check[i]);
		EXPECT_EQ(arr2[i], arr2Check[i]);
	}
}

TEST(SwapArrays, DiffrentSizes) {

	int arr1[5] = { 0,1,2,3,4 };
	int arr2[10] = { 10,11,12,13,14,15,16,17,18,19 };
	int arr1Check[5] = { 0,1,2,3,4 };
	int arr2Check[10] = { 10,11,12,13,14,15,16,17,18,19 };
	swapArrays(5, 10, arr1, arr2);
	for (int i = 0; i < 5; ++i) {
		EXPECT_EQ(arr1[i], arr1Check[i]);
	}
	for (int i = 0; i < 10; ++i) {
		EXPECT_EQ(arr2[i], arr2Check[i]);
	}
}