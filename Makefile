CPPFLAGS = -fPIC -I/usr/include/python2.7 -I/usr/include/qt4 -I/usr/include/qt4/QtGui

all: pyqtmix.o
	g++ pyqtmix.o -fPIC -lpython2.7 -lQtCore -lQtGui -o main
.cpp.o:
	g++ -c $(CPPFLAGS) -o $@ $<
