#!bin\sh

. scripts/helper.sh

srcFolder=$1
outputDir=$2
gccFlags=$3
includeFlags="-I$srcFolder"

mkdir -p ${outputDir}/engine/obj/static
mkdir -p ${outputDir}/engine/obj/shared


# Compile for static library.
for file in $(find $1 -type f -exec echo "{}" \;);  do
    if [ ${file: -4} == ".cpp" ]; then
        print_info "Compiling object code for source file ${HIGHLIGHT}$file${NC} to ${HIGHLIGHT2}${outputDir}/engine/obj/static${NC}"
        g++ -c $gccFlags $includeFlags $file  
    fi
done

mv *.o ${outputDir}/engine/obj/static/

# Compile for shared library.
for file in $(find $1 -type f -exec echo "{}" \;);  do
    if [ ${file: -4} == ".cpp" ]; then
        print_info "Compiling object code for source file ${HIGHLIGHT}$file${NC} to ${HIGHLIGHT2}${outputDir}/engine/obj/shared${NC}"
        g++ -c $gccFlags $includeFlags $file -fPIC
    fi
done

mv *.o ${outputDir}/engine/obj/shared/
