#include <string>
#include <vector>
using namespace std;

long long intToSecond(string str) {
    int find = str.find(':');
    return stoi(str.substr(0, find)) * 60 + stoi(str.substr(find + 1));
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    long long len = intToSecond(video_len);
    long long cur_pos = intToSecond(pos);
    long long op_s = intToSecond(op_start);
    long long op_e = intToSecond(op_end);

    for (auto a : commands) {
        if (op_s <= cur_pos && cur_pos < op_e) cur_pos = op_e;
        if (a == "prev") {
            cur_pos -= 10;
            if (cur_pos < 0) cur_pos = 0;
        } else {
            cur_pos += 10;
            if (len < cur_pos) cur_pos = len;
        }
        if (op_s <= cur_pos && cur_pos < op_e) cur_pos = op_e;
    }

    int m = cur_pos / 60;
    int s = cur_pos % 60;
    string ms = to_string(m);
    string ss = to_string(s);

    answer += m < 10 ? "0" + ms : ms;
    answer += ":";
    answer += s < 10 ? "0" + ss : ss;

    return answer;
}