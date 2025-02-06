#include <iostream>

void strings()
{
  int l = 0;
  char name[10] = "churros";
  for (int i = 0; i < 10; i++)
  {
    if (name[i] != '\0')
    {
      l++;
    }
  }
  std::cout << "length: " << l;

  // loop until reaches length
  int i;
  for (i = 0; name[i] != '\0'; i++)
  {
  }
  std::cout << "\nlength: " << l << "\n";

  // changing case
  char msg[] = "WELCOME";
  for (i = 0; msg[i] != '\0'; i++)
  {
    msg[i] += +32;
  }

  std::cout << msg << std::endl;

  // toggling case
  char msg2[] = "WeLcOmE";
  for (i = 0; msg2[i] != '\0'; i++)
  {
    if (msg2[i] >= 97 && msg2[i] <= 122)
    {
      msg2[i] -= 32;
    }
    else
    {
      msg2[i] += 32;
    }
  }
  std::cout << msg2 << std::endl;

  // counting words and vowels
  char phrase[] = "How are  you";
  int vcount = 0, ccount = 0, wcount = 0;
  for (int i = 0; phrase[i] != '\0'; i++)
  {
    if (
        phrase[i] == 'a' || phrase[i] == 'e' || phrase[i] == 'i' || phrase[i] == 'o' || phrase[i] == 'u' ||
        phrase[i] == 'A' || phrase[i] == 'E' || phrase[i] == 'I' || phrase[i] == 'O' || phrase[i] == 'U')
    {
      vcount++;
    }
    else if ((phrase[i] >= 65 && phrase[i] <= 90) || (phrase[i] >= 97 || phrase[i] <= 122))
    {
      ccount++;
    }

    if (phrase[i] == ' ' && phrase[i - 1] != ' ')
    {
      wcount++;
    }
  }
  wcount++;

  std::cout << "Number of words in \"" << phrase << "\": " << wcount << std::endl;
}