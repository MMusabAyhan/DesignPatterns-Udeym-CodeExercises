#include <iostream>
#include <vector>
#include <memory>
using namespace std;

struct Token
{
    int value;

    Token(int value) : value(value) {}
};

struct Memento
{
    vector<shared_ptr<Token>> tokens;
};

struct TokenMachine
{
    vector<shared_ptr<Token>> tokens;

    Memento add_token(int value)
    {
        return add_token(make_shared<Token>(value));
    }

    Memento add_token(const shared_ptr<Token>& token)
    {
        tokens.push_back(token);
        Memento m;
        for (auto t : tokens)
            m.tokens.emplace_back(make_shared<Token>(t->value));
        return m;
    }

    void revert(const Memento& m)
    {
        tokens.clear();
        for (auto t : m.tokens)
            tokens.emplace_back(make_shared<Token>(t->value));
    }
};


int main()
{
	TokenMachine tM;
	tM.add_token(1);
	Memento m1 = tM.add_token(2);
	tM.add_token(3);

	tM.revert(m1);


}
