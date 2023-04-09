#include <filesystem>
#include <fstream>
#include <regex>
#include <vector>
#include <cstring>
#include <ctime>

#include <iostream>
#include <sstream>

// vim tips:
//	!g++ %;./a.out

class ASCReader {
public:
 
private:

};

int test_regex(void)
{
	std::ifstream infile("logfile.asc");
	std::string line = "";

	if (infile.is_open() ) {
         int number;
         for(; getline(infile, line); )
         {
		std::cout << line <<std::endl;
            	if( line.find("date", 0) == 0 ) 
			break;
         }
         infile.close();
     }

	std::regex date_regex("date(\\s+)(\\w+)\\s+(\\w+)(.*)[\r\n]");
    	std::smatch match;

	if ( std::regex_match(line, match, date_regex) ) {
		std::cout << "--- matched ---" << std::endl << std::endl;
	}

	for (unsigned i=0; i<match.size(); ++i) {
      		std::cout << "[" << match[i] << "] ";
   	}
	std::cout << std::endl;
	
	return 0;
}

int main() {

  //std::cerr << "ASCReader" <<std::endl;
  std::cout << "ASCReader" <<std::endl;

  ASCReader ascReader;

  test_regex();
  return 0;

}

