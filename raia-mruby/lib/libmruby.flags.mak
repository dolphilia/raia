MRUBY_CFLAGS = -std=gnu99 -g -O3 -Wall -Wundef -Werror-implicit-function-declaration -Wwrite-strings -DMRB_USE_RATIONAL -DMRB_USE_COMPLEX -DMRB_USE_BIGINT -I"/home/dolph/mruby-3.2.0/include" -I"/home/dolph/mruby-3.2.0/build/host/include" -I"/home/dolph/mruby-3.2.0/mrbgems/mruby-time/include" -I"/home/dolph/mruby-3.2.0/mrbgems/mruby-io/include"
MRUBY_CC = gcc
MRUBY_LD = gcc
MRUBY_LDFLAGS =  -L/home/dolph/mruby-3.2.0/build/host/lib
MRUBY_LDFLAGS_BEFORE_LIBS = 
MRUBY_LIBS = -lmruby 
MRUBY_LIBMRUBY_PATH = /home/dolph/mruby-3.2.0/build/host/lib/libmruby.a
