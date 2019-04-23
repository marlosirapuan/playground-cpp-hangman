#include <iostream>
#include <string>
#include <tuple>

#define NEWLINE '\n'

using namespace std;

tuple<int, int, int> mountIndex(string word);

int main()
{
  string word;

  cout << ",-----------------------------";
  cout << NEWLINE;
  cout << "| Digite a palavra secreta: ";
  getline(cin, word);

  char letter[1];
  char secret[word.size()];

  int chances = 6;
  int hits = 0;

  bool hit = false;

  system("clear");

  auto [idx, sizeWord, spaces] = mountIndex(word);

  for (idx = 0; idx < word.size(); idx++)
  {
    if (word[idx] == ' ')
      secret[idx] = ' ';
    else
      secret[idx] = '-';
  }

  hits = spaces;

  while ((chances > 0) && (hits < sizeWord))
  {
    cout << ",-----------------------------";
    cout << NEWLINE;
    cout << "| Chances restantes .... " << chances;
    cout << NEWLINE;
    cout << "| Palavra secreta ...... ";

    for (idx = 0; idx < sizeWord; idx++)
      cout << secret[idx];

    cout << NEWLINE;
    cout << "| Digite uma letra ..... ";
    cin >> letter[0];

    for (idx = 0; idx < sizeWord; idx++)
    {
      if (word[idx] == letter[0])
      {
        hit = true;
        if (secret[idx] == '-')
        {
          secret[idx] = word[idx];
          hits++;
        }
      }
    }

    if (!hit)
      chances--;

    hit = false;
    system("clear");
  }

  cout << ",-----------------------------";
  cout << NEWLINE;
  if (hits == sizeWord)
    cout << "| você venceu !!!11!";
  else
    cout << "| você perdeu! : (";

  cout << NEWLINE;
  cout << "`-----------------------------";
  cout << NEWLINE;

  return 0;
}

tuple<int, int, int> mountIndex(string word)
{
  int idx, sizeWord, spaces;
  while (word[idx] != '\0')
  {
    idx++;
    sizeWord++;
  }

  for (idx = 0; idx < word.size(); idx++)
  {
    if (word[idx] == ' ')
      spaces++;
    else
      word[idx] = '-';
  }
  return {idx, sizeWord, spaces};
}