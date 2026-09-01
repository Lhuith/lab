#!/bin/bash

FILENAME=$(echo "$1" | sed -e 's/\(_\)\([a-z]\)/\1\u\2/g')
FILENAME="${FILENAME//_}"

HEDFIELDIR=../hed/$FILENAME.hpp

# https://stackoverflow.com/questions/638975/how-do-i-tell-if-a-file-does-not-exist-in-bash
# thanks BlueCacti
if [ -e "$HEDFIELDIR" ]; then
    echo "header file ${FILENAME}.hpp already created"
else 
    echo "creating file ${FILENAME}.hpp file"

    # creates file with header declarations and adds to /src dir
    touch $HEDFIELDIR
    printf "#ifndef ${1^^}_H\n#define ${1^^}_H\n
    \n#endif // ${1^^}_H" > $HEDFIELDIR
fi 


if [ $# -eq 1 ] || [ $2 != "-h"  ]
then

    SRCFIELDIR=../src/$FILENAME.cpp
    if [ -e "$SRCFIELDIR" ]; then
        echo "source file ${FILENAME}.cpp already created and added to CMakeList (add_executable)"
        exit 1
    else 
        echo "creating ${FILENAME}.cpp file and adding to CMakeList (add_executable)"
    fi 

    # creates file with header declarations and adds to /src dir
    touch $SRCFIELDIR
    printf "#include \"${FILENAME//_}.hpp\"" > $SRCFIELDIR

    FILENAME=$(echo "$1" | sed -e 's/\(_\)\([a-z]\)/\1\u\2/g')
    FILENAME="${FILENAME//_}"

    # add SRC.cpp file to cmake SRC link directory 
    #https://stackoverflow.com/questions/15559359/insert-line-after-match-using-sed
    # thanks : Gilles Quénot"
    sed -i  '/# CMAKE CPP INCLUDE/a ${SRC}'"$FILENAME.cpp"'' ../CMakelists.txt
    # mainFunc="if ($FILENAME::main() != 0){\n return -1; \n}\n"
    # sed -i '/ BASHET FUNCTIONS/a '"$mainFunc"'' ../main.cpp
fi