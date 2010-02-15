#ifndef MAIN_H__
#define MAIN_H__

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;
using std::cin;

#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>
#include <linux/uinput.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define gerr() std::string err(strerror(errno))
#define cErr gerr(); cerr
#define testbit(in, bit) (!!( ((in)[bit/8]) & (1<<(bit&7)) ))

extern unsigned char input_bits[1+EV_MAX/8];
extern const char *toggle_file;
extern const char *toggle_cmd;
extern bool no_grab;
extern bool count_syn;

typedef struct {
	int type;
	int code;
	int value;
} hotkey_t;

const char *evname(unsigned int e);
int evid(const char *name);

#endif
