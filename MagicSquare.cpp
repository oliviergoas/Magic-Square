#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

namespace {
	typedef vector<vector<unsigned>> Matrix;

	Matrix init(const unsigned size) {
		Matrix matrix(size);
		for (unsigned i = 0; i < size; ++i)
			matrix[i].resize(size);
		for (unsigned i = 0; i < size; ++i) {
			for (unsigned j = 0; j < matrix[0].size(); ++j)
				matrix[i][j] = 0;
		}
		return matrix;
	} // init()

	void show(const Matrix &matrix) {
		int n   = matrix.size();
		int con = n*(n*n+1)/2;
		cout << "Each row, column and diagonal add up to " << con << "\n\n";
		for (unsigned i = 0; i < matrix.size(); ++i) {
			cout << '|';
			for (unsigned j = 0; j < matrix[0].size(); ++j)
				cout << setw(n/10+2) << matrix[i][j] << '|';
			cout << endl;
		}
	} // show()
	
	void setMagicSquare(Matrix &matrix) {
		int n   = matrix.size();
		int i   = n/2, j = n-1;
		int max = n*n;

		for (int k = 1; k <= max; ++k) {
			if (matrix[i][j] != 0) {
				++i;
				j -= 2;
			}
			matrix[i][j] = k;
			--i;
			++j;
			if (i == -1 && j == n) {
				i = 0;
				j = n-2;
			}
			else if (i == -1) i = n-1;
			else if (j == n) j = 0;
		}
	} // setMagicSquare
} // namespace

int main(int argc, char **argv) {
	int length;
	do {
		cin.clear();
		cout << "Type the square's side length : ";
		cin >> length;
		if (cin.eof()) return 0;
		if (cin.fail()) exit(1);
		if (length < 1)
			cout << "The length must be positive.\n\n";
		else if (length % 2 == 0)
			cout << "The length must be an odd number.\n\n";
	} while (length < 1 || length % 2 == 0);
	
	Matrix matrix = init(length);
	setMagicSquare(matrix);
	cout << "\033[H\033[2J"; // clears the terminal screen
	show(matrix);
	
	return 0;
}
