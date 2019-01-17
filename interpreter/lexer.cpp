#include <string>
#include <cstring>

using std::string;

int tokenize(string source) {

  return 0;
}

int main(int argc, char* argv[]) {

  if (argc == 1)
    printf("Lexical Analysis Error: No file name argument provided!");

  if (argc > 2)
    printf("Lexical Analysis Error: Too many arguments provided");

  if (argc >= 2) {
    printf("\n----Following Are The Command Line Arguments Passed----");
    for(int i = 0; i < argc; i++)
      printf("\nargv[%d]: %s",i,argv[i]);
  }

  tokenize("increment x = x + 1");

  return 0;
}
