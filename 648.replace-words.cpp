/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start

struct subtrie
{
    struct subtrie* ch[26] {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};
    bool empty = true;
    bool terminal[26] { };

    size_t count(string_view sv)
    {
        if (this->empty || sv.empty())
            return 0;

        if (!this->ch[sv[0] - 'a'])
            return -1;

        if (this->terminal[sv[0] - 'a'])
            return 1;

        size_t sz = this->ch[sv[0] - 'a']->count(sv.substr(1));
        return sz == -1 ? -1 : sz + 1;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        struct subtrie trie;
        auto recurse = [&](auto&& recurse, subtrie& t, string_view sv) -> void
        {
            if (sv.empty())
                return;

            if (!t.ch[sv[0] - 'a'])
            {
                t.empty = false;
                t.ch[sv[0] - 'a'] = new subtrie();
            }

            if (sv.size() == 1)
                t.terminal[sv[0] - 'a'] = true;

            recurse(recurse, *t.ch[sv[0] - 'a'], sv.substr(1));
        };
        for (string_view s : dictionary)
            recurse(recurse, trie, s);

        string ret;
        size_t i = 0;
        while (true)
        {
            int iprev = i;
            i = sentence.find_first_of(" ", i);
            if (i == sentence.npos)
                i = sentence.size();

            string_view sv = std::string_view(sentence.begin() + iprev, sentence.begin() + i);
            size_t size;
            if ((size = trie.count(sv)) != -1)
                ret.append(sv.substr(0, size));
            else ret.append(sv);
            ret.push_back(' ');

            ++i;
            if (i >= sentence.size())
                break;
        }

        if (!ret.empty())
            ret.pop_back();

        return ret;
    }
};
// @lc code=end

