#!bin\sh

. scripts/helper.sh

binDirectory=$1

mkdir -p ${binDirectory}/engine/lib/shared
mkdir -p ${binDirectory}/engine/lib/static

print_info "Creating static library file ${HIGHLIGHT}libcosmic.a${NC} in directory ${HIGHLIGHT2}${binDirectory}/engine/lib/${NC}."
ar rcs ${binDirectory}/engine/lib/static/libcosmic.a ${binDirectory}/engine/obj/static/*.o

print_info "Creating shared library file ${HIGHLIGHT}libcosmic.so${NC} in directory ${HIGHLIGHT2}${binDirectory}/engine/lib/${NC}."
g++ -fPIC -shared ${binDirectory}/engine/obj/shared/*.o -o ${binDirectory}/engine/lib/shared/libcosmic.so 
