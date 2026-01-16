#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <fstream>

int main(int argc, char* argv[]){


    std::cout<<"@cpp(include=\"stdio.h,base.hpp,procedures.hpp,filestuff.hpp\")\n\n";
    std::cout<<"package main\n";
    std::cout<<"\t"<<"use base\n";
    std::cout<<"\t"<<"use virtualfunctions\n";
    std::cout<<"\t"<<"use filestuff\n\n";
    std::cout<<"\t"<<"compound type mainCompound()\n";
    
    
    for(int ndx=1; ndx<argc; ndx=ndx+1){
        
        std::string file = std::string(argv[ndx]);
        size_t lastindex = file.find_last_of("."); 
        std::string filename  = file.substr(0, lastindex);

        std::ifstream istream; 

        istream.open(file);
    
        std::string line;
        int lines_to_skip = 0;
        while(getline(istream, line)){
            int seq_len = 0;
            std::stringstream lineStream(line);
            while(getline(lineStream, line, ' ')){
                seq_len++;
            }
            std::string reader = std::string("testReader_") + filename + std::string("_line_")+ std::to_string(lines_to_skip);
            std::string writer = std::string("testWriter_") + filename + std::string("_line_")+ std::to_string(lines_to_skip);
            std::string sut = std::string("sut_")+filename+std::string("_line_")+std::to_string(lines_to_skip);

            std::cout<<"\t"<<"\t"<<"component TestReader "<<reader<<"("<<std::quoted(file)<<", "<<lines_to_skip<<", "<<seq_len<<")\n";
            std::cout<<"\t"<<"\t"<<"component PasswordLocking "<<sut<<"()\n";
            std::cout<<"\t"<<"\t"<<"component TestWriter "<<writer<<"("<<std::quoted(filename + std::string("_line_")+ std::to_string(lines_to_skip+1) + std::string("_output.txt"))<<", "<<seq_len<<")\n";
            std::cout<<"\t"<<"\t"<<"connector flow1int_t inputOfSut_"<<filename<<"_line_"<<lines_to_skip<<"("<<reader<<".send, "<<sut<<".password_input)\n";
            std::cout<<"\t"<<"\t"<<"connector flow1int_t outputOfSut_"<<filename<<"_line_"<<lines_to_skip<<"("<<sut<<".out_output, "<<writer<<".recv)\n\n";

            lines_to_skip++;
        }
        istream.close();
    }
    std::cout<<"\tend\n";
    std::cout<<"end"<<std::endl;
    return EXIT_SUCCESS;
}

