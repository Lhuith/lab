#!/bin/bash

DIR=../src/

FILENAME=$(echo "$1" | sed -e 's/\(_\)\([a-z]\)/\1\u\2/g')
FILENAME="${FILENAME//_}"
FIELDIR="$DIR"$FILENAME.hpp

# create a new file using x_x snake case nameing
# file name is converted to cammel case xX.hpp 
# and namespace is added with the same naming convention into src
# also adds any std/iostream retypes cause im lazy
touch $FIELDIR
printf "#ifndef ${1^^}_H\n#define ${1^^}_H\n
#include <iostream>\nusing namespace std;\n
namespace $FILENAME \n{
\t int main()\n\t{
\t cout << \"helo from $FILENAME\\\n\";
\t return 0;
\t}\n}\n#endif // ${1^^}_H" > $FIELDIR

#https://stackoverflow.com/questions/15559359/insert-line-after-match-using-sed
# thanks : Gilles Quénot
sed -i '/ BASHET IMPORTS/a #include '\""$FILENAME.hpp"\"'' ../main.cpp
mainFunc="if ($FILENAME::main() != 0){\n return -1; \n}\n"
sed -i '/ BASHET FUNCTIONS/a '"$mainFunc"'' ../main.cpp