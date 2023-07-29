
.PHONY: cf gen bf runcf compare
all: runcf

cf: cf.cc
	g++ $^ -o $@ -std=c++20

runcf: cf
	./cf < input

gen: gen.cc
	g++ $^ -o $@ -std=c++20

bf: bf.cc
	g++ $^ -o $@ -std=c++20

compare: cf gen bf
	python3 check.py