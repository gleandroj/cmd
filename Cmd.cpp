#include <Regexp.h>
#include "CMD.h"

Cmd::Cmd(Command_t *cmds){
  this->mCmdTable = cmds;
}

Cmd::~Cmd(){}

void Cmd::process(String data)
{
	char cmd[data.length()+1];
	data.toCharArray(cmd, data.length()+1);
	byte cmdLen = data.length();
	Command_t *cmds = mCmdTable;
	boolean found = false;
	MatchState ms;
	ms.Target(cmd);
	while(cmds->regexp != NULL)
	{
		char result = ms.Match(cmds->regexp);
		
		if (result > 0){
			found =  true;
			if (cmds->callback != NULL)
				cmds->callback(&ms);
		}
		cmds++;
	}
}


