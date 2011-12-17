/*! @page build Building MLPACK From Source

@section buildintro Introduction

MLPACK uses CMake as a build system and allows several flexible build
configuration options.  One can consult any of numerous CMake tutorials for
further documentation, but this tutorial should be enough to get MLPACK built
and installed.

@section builddir Creating Build Directory

Once the MLPACK source is unpacked, you should create a build directory.

@code
$ cd mlpack-1.0.0
$ mkdir build
@endcode

The directory can have any name, not just 'build', but 'build' is sufficient
enough.

@section dep Dependencies of MLPACK

MLPACK depends on the following libraries, which need to be installed on the
system and have headers present:

 - LAPACK
 - pthreads
 - Armadillo >= 2.4.0
 - LibXML2
 - Boost (math_c99, program_options, unit_test_framework)

@section config Configuring CMake

Running CMake is the equivalent to running `./configure` with autotools.  If you
run CMake with no options, it will configure the project to build with debugging
symbols and profiling information:

@code
$ cd build
$ cmake ../
@endcode

You can specify options to compile without debugging information and profiling
information (i.e. as fast as possible):

@code
$ cd build
$ cmake -D DEBUG=OFF -D PROFILE=OFF ../
@endcode

The full list of options MLPACK allows:

 - DEBUG=(ON/OFF): compile with debugging symbols (default OFF)
 - PROFILE=(ON/OFF): compile with profiling symbols (default OFF)
 - ARMA_EXTRA_DEBUG=(ON/OFF): compile with extra Armadillo debugging symbols
       (default OFF)

Each option can be specified to CMake with the '-D' flag.  Other tools can also
be used to configure CMake, but those are not documented here.

@section build Building MLPACK

Once CMake is configured, building the library is as simple as typing 'make'.
This will build all library components as well as 'mlpack_test'.

@code
$ make
Scanning dependencies of target mlpack
[  1%] Building CXX object
src/mlpack/CMakeFiles/mlpack.dir/core/optimizers/aug_lagrangian/aug_lagrangian_test_functions.cpp.o
<...>
@endcode

You can specify individual components which you want to build, if you do not
want to build everything in the library:

@code
$ make pca allknn allkfn
@endcode

If the build fails and you cannot figure out why, register an account on Trac
and submit a ticket and the MLPACK developers will quickly help you figure it
out:

http://mlpack.org/

Alternately, MLPACK help can be found in IRC at \#mlpack on irc.freenode.net.

@section install Installing MLPACK

If you wish to install MLPACK to /usr/include/mlpack/ and /usr/lib/ and
/usr/bin/, once it has built, make sure you have root privileges (or write
permissions to those two directories), and simply type

@code
# make install
@endcode

You can now run the executables by name; you can link against MLPACK with
-lmlpack, and the MLPACK headers are found in /usr/include/mlpack/.

*/
