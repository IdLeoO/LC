#!/bin/bash
inputMsg="Name of the folder: "
folder="${1}"
echo "${inputMsg}${1} ${2}"

mkdir ${folder}
cd ${folder}/
touch main.cpp main.hpp
echo -en "#ifndef MAIN\n#define MAIN\n\nclass Solution{\n    public:\n\n};\n\n#endif" >> main.hpp
echo -en "#include \"main.hpp\"\n#include <iostream>\n#include <algorithm>\n\nusing namespace std;\n\nint main(int argc, char* argv[]){\n   Solution sol;\n\n}" >> main.cpp 
code .
