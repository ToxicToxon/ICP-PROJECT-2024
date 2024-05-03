# File: Makefile
# Author: David Zatloukal, Ondřej Beneš
# Date: 3.5.2024


All: doxygen
	cd src; \
	qmake ./ICP_PROJECT_2024.pro; \
	make; \
	cd ..

doxygen:
	rm -f -d -r doc; \
	mkdir doc; \
	cd src; \
	doxygen; \
	cd ..

clean:
	cd src;\
	make clean; \
	rm -f Makefile; \
	cd ..; \
	rm -f -d -r build; \
	rm -f -d -r doc; \
	rm -f xzatlo27_xbenes61.zip

pack:
	zip -r xzatlo27_xbenes61.zip src Makefile README.txt LICENSE examples

run:
	./build/ICP_PROJECT_2024