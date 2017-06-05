#ifndef __CMD_H
#define __CMD_H

#include <Arduino.h>

typedef struct {
  char *regexp;
  void (*callback)(MatchState *ms);
} Command_t;

class Cmd {

public:
	 Cmd(Command_t *cmdTable);
	~Cmd();
	void process(String data);

private:
	Command_t *mCmdTable;
};

#endif

