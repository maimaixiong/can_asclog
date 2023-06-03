#include <fstream>
#include <iterator>
#include <string>
#include <assert.h>

#include <Vector/ASC.h>

void showCanMessage(Vector::ASC::CanMessage *CanMsg)
{
    std::cout << "--------------- CanMessage: --------------------"<<std::endl;
    std::cout << CanMsg->id <<std::endl;
}

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

    Vector::ASC::CanMessage * canMessage;

    /* parse log file */
    while (!filein.eof()) {
        Vector::ASC::Event * event;
        event = filein.read();
        assert((event != nullptr) || filein.eof());
        if (event != nullptr) {

            std::cout << "eventType:" << event->eventType << std::endl;

            /* these values must be copied to File */
            switch (event->eventType) {
            case Vector::ASC::Event::EventType::FileDate: {
                /*Vector::ASC::FileDate * fileDate = static_cast<Vector::ASC::FileDate *>(event);*/
                fileout.language = filein.language;
                fileout.date = filein.date;
		std::cout << "--------------- FileDate --------------------"<<std::endl;
                char time_buf[256];
                (void) strftime(time_buf, sizeof (time_buf),
                        "%m-%d-%Y %H:%M:%S (mon=%b)", &filein.date);
                std::cout << filein.language << "   " << std::string(time_buf) << std::endl;
                //std::cout << filein.language << "   ", std::put_time(filein.date, "%d-%m-%Y %H:%M:%S") << std::endl;
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
                Vector::ASC::FileVersion * fileVersion = static_cast<Vector::ASC::FileVersion *>(event);
                fileout.version = filein.version;
		std::cout << "--------------- FileVersion  --------------------"<<std::endl;
                //std::cout << (int16_t) fileVersion->versionMajor << (int16_t) fileVersion->versionMinor << (int16_t) fileVersion->versionPatch << std::endl;
                std::cout
                    << "// version"
                    << ' ' << std::dec << (int16_t) fileVersion->versionMajor
                    << '.' << std::dec << (int16_t) fileVersion->versionMinor
                    << '.' << std::dec << (int16_t) fileVersion->versionPatch
                <<std::endl;


            }
	    break;
            
            case Vector::ASC::Event::EventType::CanMessage: {
                canMessage = static_cast<Vector::ASC::CanMessage *>(event);
                showCanMessage(canMessage);
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
