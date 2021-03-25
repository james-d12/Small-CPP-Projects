gcc_flags = -g -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy \
-Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations \
-Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls \
-Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default  \
-Wundef -Werror -Wno-unused

engineSrcFolder=src
editorSrcFolder=editor
binFolder=bin

ifndef VERBOSE
.SILENT:
endif

compile:
	sh scripts/compile.sh ${engineSrcFolder} ${binFolder} ${gcc_flags}

link:
	sh scripts/link.sh ${binFolder}

compile-editor: compile link
	sh scripts/compile-editor.sh ${editorSrcFolder} ${binFolder}

clean:
	rm -rf ${binFolder}