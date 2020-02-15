#include "shell.h"

std::vector<pid_t> pids;

#define CHECK(fun) \
    if((fun) == -1) { \
        throw std::system_error(errno, std::generic_category()); \
}

void handle(int signals) {
    int status;
    pid_t pid;
    CHECK(pid = waitpid(-1, &status, WNOHANG));
    pids.erase(remove(pids.begin(), pids.end(), pid), pids.end());
}



void shell::execute() {
    while (run) {
        size = 8;
        cmd = new char *[size];
        cmd_num = 0;
        in = dup(0);
        out = dup(1);
        isPipe = false;
        redirect = false;
        bg_process = false;

        for (int i = 0; i < size; i++) {
            cmd[i] = nullptr;
        }

        string dir = getcwd(curr_dir, 255);
        cout << "\033[1;31m[ " + usr + "@" + " ] " + ">> \033[0m";

        getline(cin, input_command);

        if (cin.eof()) {
            break;
        }

        tokens = tokenizer.tokenize(input_command);
        if (tokens.empty()) {
            continue;
        } else if (tokens[0] == "exit") {
            cout << "Quitting shell...\n";
            run = false;
            continue;
        } else if (tokens[0] == "cd") {
            change_directory(tokens);
            continue;
        }

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "|") {
                pipe_input();
            } else if (tokens[i] == "&") {
                bg_process = true;
            } else {
                char *seg = line_to_char_array(tokens[i]);
                cmd[cmd_num++] = seg;
            }
        }

        cmd[cmd_num] = nullptr;
        CHECK(dup2(out, 1));
        CHECK(close(out));
        CHECK(pid = fork());
        if (pid == 0) {
            CHECK(execvp(cmd[0], cmd));
        } else if (pid > 0) {
            back_ground_handler();
            if (isPipe || redirect) {
                CHECK(close(pipefd[0]));
            }
            cmd_num = 0;
            delete[] cmd;
        }
        CHECK(dup2(in, 0));
        CHECK(close(in));
    }
}


void shell::change_directory(vector<string> cmd) {
    current_dir = getcwd(curr_dir, 255);
    if (cmd.size() == 1) {
        return;
    } else if (cmd[1] == "..") {
        if (current_dir.find_last_of('/') != '\0') {
            current_dir = string(curr_dir).substr(0, current_dir.find_last_of('/'));
        }
    } else if (
            cmd[1].find('/') == 0) {
        current_dir = cmd[1];
    } else {
        current_dir = current_dir + "/" + cmd[1];
    }
    CHECK(chdir(current_dir.c_str()));
}

void
shell::back_ground_handler() {
    if (!bg_process) {
        CHECK(status = waitpid(pid, nullptr, WUNTRACED));
    } else {
        pids.push_back(pid);
        signal(SIGCHLD, handle);
    }
}

void
shell::pipe_input() {
    if (!redirect) {
        CHECK(pipe(pipefd));
        CHECK(pid = fork());
        if (pid == 0) {
            CHECK(dup2(pipefd[1], 1));
            CHECK(close(pipefd[0]))
            cmd[cmd_num] = nullptr;
            CHECK(execvp(cmd[0], cmd));
        } else {
            CHECK(status = waitpid(pid, nullptr, WUNTRACED));
            CHECK(close(pipefd[1]))
            CHECK(dup2(pipefd[0], 0));
        }
    } else {
        redirect = false;
    }
    isPipe = true;
    clear(cmd, cmd_num);
}

void
shell::clear(char **&cmd, int &cmd_num) {
    char **temp = new char *[size];
    delete[] cmd;
    cmd_num = 0;
    cmd = temp;
}

char *
shell::line_to_char_array(string line) {
    char *arr = new char[line.size() + 1];
    for (int i = 0; i < line.size(); i++) {
        arr[i] = line[i];
    }
    arr[line.size()] = '\0';
    return arr;
}
