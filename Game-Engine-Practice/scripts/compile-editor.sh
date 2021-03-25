#!bin\bash

. scripts/helper.sh

srcFolder=$1
outputDir=$2
gccFlags=$3

mkdir -p ${outputDir}/editor/
mkdir -p ${outputDir}/editor/obj/

# Compile each file in editor.
for file in $(find $1 -type f -exec echo "{}" \;);  do
    if [ ${file: -4} == ".cpp" ]; then
        print_info "Compiling object code for source file ${HIGHLIGHT}$file${NC} to ${HIGHLIGHT2}${outputDir}/editor/obj/${NC}."
        g++ -c $gccFlags $file 
    fi
done

mv *.o ${outputDir}/editor/obj/

#g++ -o ${outputDir}/editor/editor.out ${outputDir}/engine/lib/libcosmic.a

g++ editor/application.cpp -o ${outputDir}/editor/editor.out -L${outputDir}/engine/lib/static -lcosmic