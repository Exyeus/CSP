#include <bits/stdc++.h>

using namespace std;

string read_whole_arg(string& arglist, int& i);
string set_i_to_next_opt(string& arglist, int& i);

int main() {
    string argTemp;
    int N;

    cin >> argTemp;
    cin >> N;

    int template_length = argTemp.size() - 1;

    map<char, string> opt_arg;
    vector<char> ordered_opt_list;

    // Analyze argTemp and establish rules.

    // Look ahead: 1 char. 为了防止溢出, 专门处理最后一个.
    for (int i = 0; i < template_length; i++) {
        if (argTemp[i] >= 'a' && argTemp[i] <= 'z') {
            if (argTemp[i + 1] == ':') {
                opt_arg[argTemp[i]] = "A";
                i++;
            } else {
                opt_arg[argTemp[i]] = "N";
            }
        } 
    }
    if (argTemp[template_length] == ':') {
        opt_arg[argTemp[template_length - 1]] = "A";
    } else {
        opt_arg[argTemp[template_length]] = "N";
    }

    // Recycle to read all input lines and check
    // Record all legal options with parameters

    string cmd_name;
    cin >> cmd_name;

    string arglist;
    getline(cin, arglist);

    int arg_list_size = arglist.size();
    char curr_opt_sign;

    for (int i = 0; i < arg_list_size;) {
        if (arglist[i] == ' ') {
            i++;
            if (i >= arg_list_size) {
                break;
            }
            continue;
        } else if (arglist[i] == '-') {
            i++;
            if (i >= arg_list_size) {
                break;
            }
            curr_opt_sign = arglist[i];
            // Get current analyzed opt sign
            // 考虑直接从这里往前探查, 如果不满足要求就做好 abort 准备.
            auto it = opt_arg.find(curr_opt_sign);
            if (it == opt_arg.end()) {
                break;
            }
            if (opt_arg[curr_opt_sign] == "A") {
                string arg = read_whole_arg(arglist, i);
                if (arg != "FATALERROR!") {
                    opt_arg[curr_opt_sign] = arg;
                    ordered_opt_list.push_back(curr_opt_sign);
                } else {
                    break;
                }
            } else if (opt_arg[curr_opt_sign] == "N") {
                string not_be_arg = set_i_to_next_opt(arglist, i);
                if (not_be_arg != "FATALERROR!") {
                    ordered_opt_list.push_back(curr_opt_sign);
                } else {
                    break;
                }
            }
        } else {
            cout << "";
            return 0;
        }
    }


    // out put all legal pairs

    for (int i = 0; i < N; i++) {
        cout << "Case " << i + 1 << ": ";
        for (char opt : ordered_opt_list) {
            cout << "-" << opt <<
             (opt_arg[opt] == ""? " ": " " + opt_arg[opt] + " ");
        }
        cout << "\n";
    }
}

string read_whole_arg(string& arglist, int& i) {
    if (arglist[i] == ' ') {
        i++;
    }
    string result;
    if (arglist[i] == '-') {
        // 本来应该是参数, 但是这里是一个选项!
        return "FATALERROR!";
    }
    while (arglist[i] != ' ') {
        result += arglist[i];
        i++;
        if (i >= arglist.size()) {
            break;
        }
    }
    while (arglist[i] == ' ') { // != -> ==
        i++;
        if (i >= arglist.size()) {
            break;
        }
    }
    return result;
}

string set_i_to_next_opt(string& arglist, int& i) {
    while (arglist[i] != ' ') {
        i++;
        if (i >= arglist.size()) {
            break;
        }
    }
    if (arglist[i] != '-') {
        return "FATALERROR!";
    }
    return "";
}