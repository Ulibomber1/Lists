// For CSE 2020 Lab9
// KV, Spring 2022
#include <iostream>
#include <algorithm>
#include "Vector.h"
#include "List.h"
#include "Random.h"
#include "Searching.h"
#include "Utilities.h"

using namespace std;

const int RUNS = 20;

int main()
{
	rand_seed();
	for (int k = 100; k <= 1000; k += 100)
	{
		Vector<int> myvec;
		random_vector_norep(k, 1, 10000, myvec, 0);

		Vector<int> sortvec(myvec);
		sort(sortvec.begin(), sortvec.end());

		List<int> sortlist;
		for (int i = 0; i < sortvec.size(); i++)
			sortlist.push_back(sortvec[i]);

		Vector<int> targets;
		random_vector_norep(RUNS, 0, myvec.size() - 1, targets, 0);

		int sum_lsvec = 0; // initialize sums for averaging ... 
		int sum_lslst = 0;
		int sum_lslst2 = 0;
		int sum_bsvec = 0;

		for (int i = 0; i < targets.size(); i++)
		{
			int ops_lsvec = 0;
			int ops_lslst = 0;
			int ops_lslst2 = 0;
			int ops_bsvec = 0;

			int target = myvec[targets[i]]; // next target to search

			linear_search_V(sortvec, target, ops_lsvec);
			linear_search_L(sortlist, target, ops_lslst);
			linear_search_L_explore(sortlist, target, ops_lslst2);
			binary_search_V(sortvec, target, ops_bsvec);


			sum_lsvec += ops_lsvec;
			sum_lslst += ops_lslst;
			sum_lslst2 += ops_lslst2;
			sum_bsvec += ops_bsvec;

		}

		cout << "Averages of " << RUNS << " runs for size " << k << "....." << endl << endl;
		cout << "linear_search_V: " << sum_lsvec / float(RUNS) << " avg" << endl;
		cout << "linear_search_L: " << sum_lslst / float(RUNS) << " avg" << endl;
		cout << "linear_search_Lexp: " << sum_lslst2 / float(RUNS) << " avg" << endl;
		cout << "binary_search_V: " << sum_bsvec / float(RUNS) << " avg" << endl
			 << endl;



	}
	return 0;
}
