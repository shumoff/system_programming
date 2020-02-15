#include <chrono>
#include <ctime>
#include <cassert>
#include <csignal>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "tokenizer.h"

class shell {

private:

    Tokenizer tokenizer;
    string input_command;
    vector<string> tokens;

    int size;
    char **cmd;
    int cmd_num;
    int in;
    int out;

    string usr;
    string current_dir;
    char curr_dir[256];

    int pipefd[2];
    pid_t pid;
    int status;

    bool run;
    bool isPipe;
    bool bg_process;
    bool redirect;

public:
    shell() : usr(getenv("USER")), isPipe(false), bg_process(false), redirect(false), run(true) {}

    void execute();

    void redirect_input(int i);

    void redirect_output(int i);

    void change_directory(vector<string> cmd);

    void back_ground_handler();

    void clear(char **&cmd, int &i);

    char *line_to_char_array(string line);

    void pipe_input();
};