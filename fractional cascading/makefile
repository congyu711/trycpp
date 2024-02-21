
MAKEFLAGS+= --always-make
cxx=g++-12
flags=-O3 -std=c++20
f=data.in

gen: gen.cc
	$(cxx) gen.cc -o gen $(flags) && ./gen > $(f)

trivial: trivial.cc
	$(cxx) trivial.cc -o trivial $(flags) && time ./trivial < $(f) > trivial.out

fc: fc.cc
	$(cxx) fc.cc -o fc $(flags) && time ./fc < $(f) > fc.out