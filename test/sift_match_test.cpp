// Tianwei Shen, HKUST.

/** \file sift_match_test.cpp
 *	\brief testing feature matching
 */

#include <iostream>
#include <string>
#include "utils/data_types.h"
#include "matching/matching_datatypes.h"
#include "matching/feature_matching.h"

using namespace std;

int main(int argc, char **argv)
{
	if (argc != 3)
		return -1;
	string sift_file1 = string(argv[1]);
	string sift_file2 = string(argv[2]);

	// This file doesn't support other sift type
	vot::SiftData sift1, sift2;
	sift1.ReadSiftFile(sift_file1);
	sift2.ReadSiftFile(sift_file2);

	vot::SiftMatchPair match_pair(sift_file1);
	vot::MatchParam match_param;
	if(!vot::PairwiseSiftMatching(sift1, sift2, match_pair, match_param))
	{
		return -1;
	}

	return 0;
}
