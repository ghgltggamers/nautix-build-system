# nautix-build-system
nautix is a project manager + build system developed to configure and compile C++ in a lot easier way which reduces complexity
This allows you to compile your C++ projects with a lot of ease!

# Let's explore 
Install nautix by using following commands set
```bash
git clone https://github.com/ghgltggamers/nautix-build-system.git
cd nautix-build-system
g++ main.cpp -o nautix
echo "Nautix was compiled now initalise it in your environment variable forr convience"
echo ""
```

Okay now expecting that you may have installed nautix let's check your nautix version by
```bash
nautix --version
```

Create a new project with
```bash
nautix --new [project name] [path to project]
```

Once created open the path and execute the <code>configure-nautix-rt</code> script.
Now you will have a <code>build</code> binary file just execute it for running your project everytime you need from now

## build [bin]
This will read the <code>project.nautix</code> file for executing your project of C++
the default content of file is

```project.nautix
# This is the nautix file for build
# Better to refer the documentation for writting nautix file if you need, Othervise leave this file to be default it will work more
project-name=build
project-version=1.0
project-compiler=gcc
project-main-file=main.cpp
project-bin-directory=bin
project-main-output-file=build
# temprorary binaries are those who will be deleted after program is being executed and perm binaries are those which will exist ever after project is done, So play with the setting bellow accordingly
project-bin-type=temp
# Uncomment the line bellow if want to parse any arguments for compiler, these will be placed in between file name and -o flag by nautix
# project-compiler-arguments=
# Uncomment the line bellow if want to parse any additional file for linking
# project-link-cpp=
execute-project=true
```

Modify the file accordingly.

## project.nautix
This file will tell the nautix runtime 'how to compile and execute the c++'
let's learn

### Comments
Anything starts from '#' is a comment and will be ignored by the runtime
note: comments can't stop neutix predefined keys to be executed

## Project name and Project version
these will be ignored by the runtime also but only be stored in memory as tokens,No need to define these things

## project-compiler
This tells the nautix for which compiler to use for compilation make sure to only use gcc or clang for the best support

## project-main-file
This tells the nautix for which is the main.cpp or main c++ file is ? This is what nautix will compile at firt and give priority.

## project-main-output-file
This tells the nautix for when compiling the main file what should be the name of the binary file generated

## project-bin-directory
This tells the nautix about what is the build directory for the project, This directory will contain all the binary files for the project

## project-bin-type
This tells the nautix about what type of binaries will be produced (temp or perm) temp binaries are those which will not exist once the program ran by the runtime, perm binaries are those which will exist even after the program is executed by the nautix runtime.

## project-compiler-arguments
This will define additional arguments for the project like pkg-config , --cflags etc. What ever your compiler can accept

## project-link-cpp
This will tell nautix for what additional C++ files must be linked to the final binary output generated from main.

## execute-project
This will tell the nautix runtime weather the project must ran after compilation or not only accept (true or false).

# Now you mastered the nautix file! It's time to make your brand new nautix project now
Note nautix files are backspace sensitive!

This project is open for contributions! if want to contribute then fork this repository and modify the source and then hit a pull request!
