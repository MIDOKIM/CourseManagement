#include "CSVFile.h"
CSVFile::CSVFile(string path)
{
	Path = path;
	Stream.open(Path);
}
CSVFile::~CSVFile()
{
	Stream.close();
}
vector<string> CSVFile::ParseLine(string line)
{
	vector<string> strings;
	string s;
	for (int i = 0; i < line.size(); i++)
	{
		s += line[i];
		if (line[i] == ',')
		{
			s.pop_back();
			strings.push_back(s);
			s = "";
		}
	}
	strings.push_back(s);
	return strings;
}
vector<string> CSVFile::Load()
{
	vector<string> result;
	Stream.seekg(0);
	string line;
	while (getline(Stream, line))
	{
		result.push_back(line);
	}
	return result;
}
void CSVFile::Save(vector<string> Lines)
{
	Stream.seekp(0);
	for (int i = 0; i < Lines.size(); i++)
	{
		Stream << Lines[i] << endl;
	}
}
