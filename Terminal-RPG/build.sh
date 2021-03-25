echo "Building files..."

DIR=$(pwd)
BIN="/bin"
BINDIR=${DIR} ${BIN}

if [ ! -d "$BINDIR" ]
then   
    mkdir bin
    mkdir bin/obj
    mkdir bin/prh
else
echo "Dependencies met."
fi


g++ \
-g \
-Wall \
-o bin/run.out \
src/Core/*.cpp \
src/Item/*.cpp \
src/Entity/*.cpp \
src/State/*.cpp \
src/Test/*.cpp \
src/*.cpp

echo "Complete."e