#!/bin/bash

DIR=../src/

FILENAME=$(echo "$1" | sed -e 's/\(_\)\([a-z]\)/\1\u\2/g')
FILENAME="${FILENAME//_}"

FIELDIR="$DIR"$FILENAME.hpp

touch $FIELDIR
printf "#ifndef ${1^^}_H\n#define ${1^^}_H\n
#include <iostream>\nusing namespace std;\n
namespace $FILENAME \n{
\t int main()\n\t{
\t cout << \"helo from $FILENAME\\\n\";
\t return 0;
\t}\n}\n#endif // ${1^^}_H" > $FIELDIR