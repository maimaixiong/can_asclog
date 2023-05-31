# can_asclog
CAN ASCII LOG(Vector) Parser


# Vector_ASC

```
 0. sudo apt install flex
 1. git clone https://bitbucket.org/tobylorenz/vector_asc.git
 2. cd vector_asc
 3. mkdir build
 4. cd build
 5. cmake ..
 6. make package
 7. g++ Parser.cpp -I Vector_ASC-1.1.3-Linux/include/ -L Vector_ASC-1.1.3-Linux/lib/ -lVec
tor_ASC -o parser
 8. wget https://bitbucket.org/tobylorenz/vector_asc/raw/c304a20a0cd49d15aeebafde777c5ca6d
93a2fe6/src/Vector/ASC/tests/unittests/data/CAN_Log_Trigger_3_2.asc
 9. ./parse CAN_Log_Trigger_3_2.asc
```
