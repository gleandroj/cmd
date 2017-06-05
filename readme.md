# Cmd Library
Simple Command Processor for Arduino using regex

### Dependencies
 - [Regexp](https://github.com/nickgammon/Regexp)
 
## How To Use This Library

```
/* Callback's*/
void _testCmd(MatchState *ms);

/* Command's */
Command_t cmds[] =
{
  { "^test cmd (%d+)$", _testCmd },
  { NULL, NULL }
};

Cmd* cmdParser;

void setup()
{
  Serial.begin(9600);
  cmdParser = new Cmd(&cmds[0]);
}

void loop()
{
   cmdParser->process(Serial.readString());
}

void _testCmd(MatchState *ms)
{
  if (ms->level > 0)
  {
    char cparameter[10];
    ms->GetCapture(&cparameter[0], 0);
    int parameter = atoi(&cparameter[0]);
    Serial.println(paramter);
  }
};


```