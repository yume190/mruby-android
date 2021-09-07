cmake_minimum_required(VERSION 3.4.1)

find_library(
    log-lib
    log
    string
)
include_directories(
    "CMRuby/include"
    "CMRuby/include/mruby"
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fexceptions")

add_library(
#    dabcontrollerdemo SHARE
    mruby SHARED
    "CMRuby/public.c"
    
    "CMRuby/mrbgems/mruby-compiler/core/codegen.c"
    # "CMRuby/mrbgems/mruby-compiler/core/parse.y"
    "CMRuby/mrbgems/mruby-compiler/core/y.tab.c"

    "CMRuby/src/array.c"
    "CMRuby/src/backtrace.c"
    "CMRuby/src/class.c"
    "CMRuby/src/codedump.c"
    "CMRuby/src/compar.c"
    "CMRuby/src/crc.c"
    "CMRuby/src/debug.c"
    "CMRuby/src/dump.c"
    "CMRuby/src/enum.c"
    "CMRuby/src/error.c"
    "CMRuby/src/error.h"
    "CMRuby/src/etc.c"
    "CMRuby/src/fmt_fp.c"
    "CMRuby/src/gc.c"
    "CMRuby/src/hash.c"
    "CMRuby/src/init.c"
    "CMRuby/src/kernel.c"
    "CMRuby/src/load.c"
    "CMRuby/src/numeric.c"
    "CMRuby/src/object.c"
    "CMRuby/src/opcode.h"
    "CMRuby/src/pool.c"
    "CMRuby/src/print.c"
    "CMRuby/src/proc.c"
    "CMRuby/src/range.c"
    "CMRuby/src/state.c"
    "CMRuby/src/string.c"
    "CMRuby/src/symbol.c"
    "CMRuby/src/value_array.h"
    "CMRuby/src/variable.c"
    "CMRuby/src/version.c"
    "CMRuby/src/vm.c"
)

# Include libraries needed for hello-jni lib
target_link_libraries(
    mruby

    android
    ${log-lib}
)
