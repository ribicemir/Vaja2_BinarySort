#include <fstream>
#include <vector>
using namespace std;

bool Branje_Stevil(std::vector<unsigned char>& vec, const std::string& filename) {
//const char zamenjamo ker je zastareli nacin
	ifstream input(filename);
	if (!input.is_open()) return false;

	int temp;
	while (input >> temp) {
		vec.push_back(static_cast<unsigned char>(temp));
	}
	input.close();
	return true;
}

void Izpis_Stevil(const std::vector<unsigned char>& vec) {
	ofstream output("out.txt");
	if (!output.is_open()) return;

	for (size_t i = 0; i < vec.size(); ++i) {
		output << static_cast<int>(vec[i]);
		if (i < vec.size() - 1) output << " ";
	}
	output.close();
}
void countingSortPoBitu(vector<unsigned char>& A, int k) {
	int n = A.size();
	vector<unsigned char> B(n);
	int stevec[2] = {0, 0};


	for (int i = 0; i < n; i++) {
		int bit = (A[i] >> k) & 1;
		stevec[bit]++;
	}


	stevec[1] += stevec[0];


	for (int i = n - 1; i >= 0; i--) {
		int bit = (A[i] >> k) & 1;
		B[stevec[bit] - 1] = A[i];
		stevec[bit]--;
	}

	A = B;
}

void binarniRadixSort(vector<unsigned char>& A) {
	for (int k = 0; k < 8; k++) {
		countingSortPoBitu(A, k);
	}
}

int main(int argc, char* argv[]) {

	if (argc < 2) {
		cerr << "Uporaba: " << argv[0] << " <vhodna datoteka>" << std::endl;
		return 1;
	}

	vector<unsigned char> A;
	if (!Branje_Stevil(A, argv[1])) {
		std::cerr << "Napaka: Datoteke ni mogoče odpreti." << std::endl;
		return 1;
	}

	binarniRadixSort(A);

	Izpis_Stevil(A);

	return 0;
}
