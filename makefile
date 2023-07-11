
.PHONY: clean CLEAN

clean:
	find . -type f ! -name "*.*" ! -name "makefile"

CLEAN:
	find . -type f ! -name "*.*" ! -name "makefile" -delete