//
//  set.cpp
//  DS_hw3_Stack_and_queue 
//

#include <algorithm>
#include "solve.h"
#include <stdio.h>
#include <stdlib.h>

void combinationSum2(vector<int> &candidates, int target, vector< vector<int> > &sol, vector<int> &combination, int begin, int limit, int *count) 
{
	if (count[0] > limit) {
		count[0]--;
		return;
	}
	if (!target) {
		sol.push_back(combination);
		return;
	}
	for (int i = begin; i < candidates.size() && target >= candidates[i]; i++) {
		combination.push_back(candidates[i]);
		if (candidates[i] < 0) {
			count[0]++;
		}
		combinationSum2(candidates, target - candidates[i], sol, combination, i, limit, count);
		if (combination.back() < 0 && combination.size() == 1) {
			count[0]--;
		}
		combination.pop_back();
	}
}

void combinationSum(vector<int> &candidates, int target, vector< vector<int> > &sol, vector<int> &combination, int begin)
{
        if (!target) {
                sol.push_back(combination);
                return;
        }
        for (int i = begin; i < candidates.size() && target >= candidates[i] && candidates[i] > 0; i++) {
                combination.push_back(candidates[i]);
                combinationSum(candidates, target - candidates[i], sol, combination, i);
                combination.pop_back();
        }
}

void solve::calculate(int target, int limit, int candidates_num, vector<int> candidates, vector< vector<int> > &solutions) {
	vector <int> combination;
	int *count = (int *)calloc(1, sizeof(int));
	sort(candidates.begin(), candidates.end());
	if (limit == 0) {
		combinationSum(candidates, target, solutions, combination, 0);
	} else {
		combinationSum2(candidates, target, solutions, combination, 0, limit, count);
	}	
	combination.clear();
	free(count);
}

