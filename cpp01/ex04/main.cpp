#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int progError(std::string progName, std::string error)
{
	std::cout << progName << ": " << error << std::endl;
	return (1);
}

void fstreamReplace(std::ifstream& in, std::ofstream& out,
	std::string search, std::string replace)
{
	std::ostringstream inBuf;
    inBuf << in.rdbuf();
	std::string modStr = inBuf.str();
	in.close();
	std::string::size_type occurenceIdx = modStr.find(search);
	while (occurenceIdx != std::string::npos)
	{
		modStr.erase(occurenceIdx, search.size());
		modStr.insert(occurenceIdx, replace);
		occurenceIdx += replace.size();
		occurenceIdx = modStr.find(search, occurenceIdx);
	}
	out << modStr;
	out.close();
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (progError(argv[0], "3 arguments expected"));
	std::string filename(argv[1]);
	std::string search(argv[2]);
	std::string replace(argv[3]);
	if (filename == "")
		return (progError(argv[0], "searched string cannot be empty"));
	if (search == "")
		return (progError(argv[0], "searched string cannot be empty"));
	std::ifstream inFile(filename.c_str());
	if (!inFile)
		return (progError(argv[0], filename + ": file could not be opened"));
	std::ofstream outFile((filename + ".replace").c_str());
	if (!outFile)
		return (progError(argv[0], filename + ".replace" + ": file could not be opened"));
	fstreamReplace(inFile, outFile, search, replace);
	return (0);
}
