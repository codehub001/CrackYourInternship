// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Auxiliary Recursive function
// to perform backtracking
bool solve(string words, int i,
	int S, int mp[], int used[],
	int Hash[],
	int CharAtfront[])
{
	// If i is word.length
	if (i == words.length())

		// Return true if S is 0
		return (S == 0);

	// Stores the character at
	// index i
	char ch = words[i];

	// Stores the mapped value
	// of ch
	int val = mp[words[i] - 'A'];

	// If val is not -1
	if (val != -1) {

		// Recursion
		return solve(words, i + 1,
					S + val * Hash[ch - 'A'],
					mp, used,
					Hash, CharAtfront);
	}

	// Stores if there is any
	// possible solution
	bool x = false;

	// Iterate over the range
	for (int l = 0; l < 10; l++) {

		// If CharAtfront[ch-'A']
		// is true and l is 0
		if (CharAtfront[ch - 'A'] == 1
			&& l == 0)
			continue;

		// If used[l] is true
		if (used[l] == 1)
			continue;

		// Assign l to ch
		mp[ch - 'A'] = l;

		// Marked l as used
		used[l] = 1;

		// Recursive function call
		x |= solve(words, i + 1,
				S + l * Hash[ch - 'A'],
				mp, used, Hash, CharAtfront);

		// Backtrack
		mp[ch - 'A'] = -1;

		// Unset used[l]
		used[l] = 0;
	}

	// Return the value of x;
	return x;
}

// Function to check if the
// assignment of digits to
// characters is possible
bool isSolvable(string words[], string result, int N)
{

	// Stores the value
	// assigned to alphabets
	int mp[26];

	// Stores if a number
	// is assigned to any
	// character or not
	int used[10];

	// Stores the sum of position
	// value of a character
	// in every string
	int Hash[26];

	// Stores if a character
	// is at index 0 of any
	// string
	int CharAtfront[26];

	memset(mp, -1, sizeof(mp));
	memset(used, -1, sizeof(used));
	memset(Hash, -1, sizeof(Hash));
	memset(CharAtfront, -1, sizeof(CharAtfront));

	// Stores the string formed
	// by concatenating every
	// occurred character only
	// once
	string uniq = "";

	// Iterator over the array,
	// words
	for(int word = 0; word < N; word++) {

		// Iterate over the string,
		// word
		for (int i = 0; i < words[word].length(); i++) {

			// Stores the character
			// at ith position
			char ch = words[word][i];

			// Update Hash[ch-'A]
			Hash[ch - 'A'] += (int)pow(10, words[word].length() - i - 1);

			// If mp[ch-'A'] is -1
			if (mp[ch - 'A'] == -1) {

				mp[ch - 'A'] = 0;
				uniq += (char)ch;
			}

			// If i is 0 and word
			// length is greater
			// than 1
			if (i == 0 && words[word].length() > 1) {

				CharAtfront[ch - 'A'] = 1;
			}
		}
	}

	// Iterate over the string result
	for (int i = 0; i < result.length(); i++) {

		char ch = result[i];

		Hash[ch - 'A'] -= (int)pow(10, result.length() - i - 1);

		// If mp[ch-'A] is -1
		if (mp[ch - 'A'] == -1) {
			mp[ch - 'A'] = 0;
			uniq += (char)ch;
		}

		// If i is 0 and length of
		// result is greater than 1
		if (i == 0 && result.length() > 1) {
			CharAtfront[ch - 'A'] = 1;
		}
	}

	memset(mp, -1, sizeof(mp));

	// Recursive call of the function
	return solve(uniq, 0, 0, mp, used, Hash, CharAtfront);
}
	
int main()
{
	// Input
	string arr[] = { "SIX", "SEVEN", "SEVEN" };
	string S = "TWENTY";
	
	int N = sizeof(arr)/sizeof(arr[0]);

	// Function Call
	if (isSolvable(arr, S, N))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}

// This code is contributed by suresh07.
Solving Cryptarithmetic Puzzle
