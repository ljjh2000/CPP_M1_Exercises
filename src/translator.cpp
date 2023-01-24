#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> make_exit_commands()
{
    return {"q", "e", "exit", "quit"};
}

int main()
{

    string tmp;
    string w1;
    string w2;

    while (true)
    {
        cout << "This is a translator, but it does nothing for now..." << endl;
        cin >> tmp;
        auto exit_commande = make_exit_commands();
        if (auto search = exit_commande.find(tmp); search != exit_commande.end())
        {
            break;
        }
        if (tmp.compare("add") == 0)
        {
            cin >> w1;
            cin >> w2;
            cout << w1 + " => " + w2 << endl;
        }
        else if (tmp.compare("translate") == 0)
        {
            getline(std::cin, tmp);
            cout << tmp << endl;
        }
    }

    return 0;
}