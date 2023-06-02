#g++ Parser.cpp -I Vector_ASC-1.1.3-Linux/include/ -L Vector_ASC-1.1.3-Linux/lib/ -lVector_ASC -o parser
#LD_LIBRARY_PATH=Vector_ASC-1.1.3-Linux/lib/ ./parser logfile.asc|head

g++ read_asclog.cpp -I Vector_ASC-1.1.3-Linux/include/ -L Vector_ASC-1.1.3-Linux/lib/ -lVector_ASC -o read_asclog
LD_LIBRARY_PATH=Vector_ASC-1.1.3-Linux/lib/ ./read_asclog logfile.asc
