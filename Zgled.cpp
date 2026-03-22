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



	Izpis_Stevil(A);

	return 0;
}
