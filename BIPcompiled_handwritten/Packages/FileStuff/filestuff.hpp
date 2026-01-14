#ifndef __FILESTUFF_H__
#define __FILESTUFF_H__

#include <fstream>
using CppOutStream = std::ofstream;

inline std::ostream& operator << ( std::ostream& os, const CppOutStream& rhs ) {
    os << (rhs.is_open() ? "an instanciated file stream" : "no_file file_stream");
    return os;
}

void emptyFile(std::string filename);
CppOutStream openStream(std::string filename);
void printInStream(CppOutStream& outputstream, std::string txt);
void printInStream(CppOutStream& outputstream, int n);
void printInStream(CppOutStream& outputstream, double x);
void closeStream(CppOutStream& outputstream);

using CppInStream = std::ifstream;
CppInStream openInStream(std::string filename);
void readInStream(CppInStream& inputstream, std::string& txt);
void readInStream(CppInStream& inputstream, int& n);
void readInStream(CppInStream& inputstream, double& x);
void closeStream(CppInStream& inputstream);

#endif // __FILESTUFF_H__
