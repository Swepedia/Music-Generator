CXX = g++
OBJS = main.o Generator.o fileToWav.o
DEBUG = -g
WARNINGS := -Wall -Wextra -Wfloat-equal -Wundef -Wcast-align -Wwrite-strings \
		   -Wlogical-op -Wmissing-declarations -Wredundant-decls -Wshadow \
		   -Woverloaded-virtual -Wunused-parameter -Wunsafe-loop-optimizations \
		   -Wpointer-arith -Wcast-qual -Wmissing-noreturn \
		   -Wmissing-format-attribute -Winline -Winvalid-pch -Wvla \
		   -Wdisabled-optimization -Woverlength-strings
LFLAGS = -std=c++11 $(WARNINGS)
CFLAGS = -std=c++11 -c $(WARNINGS)
OBJECT = $(CXX) $(CFLAGS) $<

MusicGenerator : $(OBJS)
	$(CXX) $(LFLAGS) $(OBJS) -o MusicGenerator

main.o : main.cpp Generator.h
	$(OBJECT)

Generator.o : Generator.cpp Generator.h fileToWav.h
	$(OBJECT)

fileToWav.o : fileToWav.cpp fileToWav.h
	$(OBJECT)

#Generates a .ycm_extra_conf.py file to use with YCM
edit : MusicGenerator .ycm_extra_conf.py

.ycm_extra_conf.py : 
	$(file > $@,def FlagsForFile(filename, **kwargs): return { 'flags': [ 'x', 'c++', '-std=c++11')
	$(foreach flag,$(WARNINGS),$(file >> $@,, '$(flag)'))
	$(file >> $@,],})
	tr -d '\n' < .ycm_extra_conf.py > tmp
	mv tmp .ycm_extra_conf.py

clean :
	rm *.o MusicGenerator .ycm_extra_conf.py
