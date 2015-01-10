extern "C" {
#include "clang-c/Index.h"
}

#include "llvm/Support/CommandLine.h"
#include <iostream>

using namespace llvm;

static cl:opt<std::string>
FileName(cl::Positional, cl::desc("Input file"), cl::Required);

int main(int argc, char** argv){
  cl::ParseCommandLineOptions(argc,argv, "My tokenizer\n");
  CXIndex index = clang_createIndex(0,0);
  const char *args[]={
    "-I/home/ubuntu/clare/llvm/include",
    "-I."
    };
    CXTranslationUnit translationUnit = clang_parseTranslationUnit(index, FileName.c_str(), args, 2, NULL , 0, CXTranslationUnit_None);
    CXFile file = clang_getFile(translationUnit, FileName.c_str());
    CXSourceLocation loc_start = clang_getLocationForOffset(translationUnit, file, 0);

}
