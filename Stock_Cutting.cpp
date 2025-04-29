#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

using namespace std;

struct Beam 
{
	int ID;
	int length;
	bool used;
};

int main()
{
	vector<double> beam_lengths = { 10,6,6,5,10,12,15,12,4 };
	vector<Beam> beams;

	vector<vector<Beam>> nestedBeams;
	int stocklength = 20;
	int currentstock = 0;
	int kerf = 0.025;

	for (size_t i = 0; i < beam_lengths.size(); i++)
	{
		Beam newBeam = { i,beam_lengths[i], false };
		beams.push_back(newBeam);
	}

	//for (size_t i = 0; i < beams.size(); i++)
	//{
	//	cout << "ID: " << beams[i].ID << " Length: " << beams[i].length << " Used: " << beams[i].used << endl;
	//}

	while (true)
	{
		vector<Beam> currentstockvec;
		currentstock = stocklength;

		for (int i = 0; i < beams.size(); i++)
		{
			if (beams[i].used)
			{
				continue;
			}

			if (beams[i].length <= currentstock)
			{
				beams[i].used = true;
				currentstock -= beams[i].length;
				currentstockvec.push_back(beams[i]);
			}
		}

		if (currentstockvec.empty())
		{
			break;
		}

		nestedBeams.push_back(currentstockvec);
	}

	for (int i = 0; i < nestedBeams.size(); i++)
	{
		vector<Beam> currentNestedStockList = nestedBeams[i];

		cout << "Nested Stock: " << i+1 << endl;
		for (Beam beam : currentNestedStockList)
		{
			cout << "ID: " << beam.ID << " Length: " << beam.length << " Used: " << beam.used << endl;
		}
	}
}
