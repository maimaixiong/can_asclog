#include <fstream>
#include <iterator>
#include <string>
#include <assert.h>

#include <Vector/ASC.h>

int main(int argc, char * argv[]){
    if (argc != 2) {
        std::cout << argv[0] << " <filename.asc>" <<std::endl;
        return -1;
    }

    /* open input file */
    Vector::ASC::File filein;
    filein.open(argv[1], Vector::ASC::File::OpenMode::Read);

    Vector::ASC::File fileout;
    fileout.open("test.out", Vector::ASC::File::OpenMode::Write);

    /* parse log file */
    while (!filein.eof()) {
        Vector::ASC::Event * event;
        event = filein.read();
        assert((event != nullptr) || filein.eof());
        if (event != nullptr) {
            /* these values must be copied to File */
            switch (event->eventType) {
            case Vector::ASC::Event::EventType::FileDate: {
                /*Vector::ASC::FileDate * fileDate = static_cast<Vector::ASC::FileDate *>(event);*/
                fileout.language = filein.language;
                fileout.date = filein.date;
            }
            break;
            case Vector::ASC::Event::EventType::FileBaseTimestamps: {
                /*Vector::ASC::FileBaseTimestamps * fileBaseTimestamps = static_cast<Vector::ASC::FileBaseTimestamps *>(event);*/
		std::cout << "--------------- FileBaseTimestamps --------------------"<<std::endl;
                fileout.base = filein.base;
                fileout.timestamps = filein.timestamps;
            }
            break;
            case Vector::ASC::Event::EventType::FileVersion: {
                /*Vector::ASC::FileVersion * fileVersion = static_cast<Vector::ASC::FileVersion *>(event);*/
                fileout.version = filein.version;
            }
	    break;
	    default:
	    break;
	    }
	
	    fileout.write(event);
            delete event;
        }
    }

    filein.close();
    fileout.close();


    return 0;
}
