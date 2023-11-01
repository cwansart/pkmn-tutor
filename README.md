# PKMN Tutor

Tool to learn 6th gen type strengths and weaknesses for a single type.

## How to build

### MSVC

Start x64 Native Tools Command Prompt for VS and run `cl.exe type.c`.

For an optimized build use: `cl /O2 /MD /GL /Gy /W3 /D "NDEBUG" /Ftype.exe type.c /link /RELEASE /LTCG /OPT:REF /OPT:ICF`

### clang

Start a terminal and run `clang type.c`

## How to run

Just run the binary you just built.

On Windows: `type.exe`

On Linux: `./type`

