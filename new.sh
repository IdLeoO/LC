#!/bin/bash
inputMsg="Name of the folder: "
folder="${1}"
echo "${inputMsg}${1} ${2}"

mkdir ${folder}
cd ${folder}/
touch main.cpp main.hpp
code .
