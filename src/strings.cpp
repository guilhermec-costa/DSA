#include <iostream>
#include <vector>
#include <bitset>

bool str_eq(char *s1, char *s2);
void str_gt_than(char *s1, char *s2);
bool is_palindrome(char *s);

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

  // validating strings
  char *pwd = "anil321";
  for (int i = 0; pwd[i] != '\0'; i++)
  {
    if (!(pwd[i] >= 65 && pwd[i] <= 90) &&
        !(pwd[i] >= 97 && pwd[i] <= 122))
    {
    }
  }

  // reversing string
  std::cout << "---------" << std::endl;
  char language[] = "python";
  char reversed[7] = {};

  for (int i = 6, j = 0; language[j] != '\0'; i--, j++)
  {
    reversed[j] = language[i - 1];
  }

  reversed[7] = '\0';

  for (int i = 0; reversed[i] != '\0'; i++)
  {
    language[i] = reversed[i];
  }

  printf("%s", language);

  // reversing string ( second method ) one for loop. More performant
  char shit_language[] = "Roma e amor";
  std::cout << std::endl;
  for (int i = 0, j = 10; i < j; i++, j--)
  {
    char tmp = shit_language[i];
    shit_language[i] = shit_language[j];
    shit_language[j] = tmp;
  }
  printf("%s", shit_language);

  // it is possible to determine if they are equal or not
  // and it is possible do determine which one comes first ( is smaller or greater )

  char *s1 = "churros";
  char *s2 = "churros";
  bool strEquals = str_eq(s1, s2);
  std::cout << strEquals << std::endl;

  char *s3 = "cchurros3";
  char *s4 = "Churros4";
  str_gt_than(s3, s4);

  std::cout << std::endl;

  char china_person[] = "Guilherme China";
  is_palindrome(china_person);

  std::cout << std::endl;
  char sentence[] = "Roma e amor";
  for (int i = 0, j = 10; i < j; i++, j--)
  {
    char t = sentence[i];
    sentence[i] = sentence[j];
    sentence[j] = t;
  }

  printf("%s", sentence);

  // comparison method for finding duplicates
  std::vector<char> duplicates = {};
  char my_favorite_dog[] = "churrossann";
  int length = 0;
  for (int i = 0; my_favorite_dog[i] != '\0'; length++, i++)
  {
  }

  for (int i = 0; i < length; i++)
  {
    for (int j = i + 1; j < length; j++)
    {
      if (my_favorite_dog[i] == my_favorite_dog[j])
      {
        duplicates.push_back(my_favorite_dog[i]);
      }
    }
  }

  std::cout << "duplicate characters: " << "\n";
  for (const char c : duplicates)
  {
    std::cout << c;
  }

  // each index is equal to current char - 97
  std::cout << std::endl;
  char dups_map[26] = {0};
  char word[] = "cookedd bro";

  for (int i = 0; word[i] != '\0'; i++)
  {
    dups_map[word[i] - 97] += 1;
  }

  for (int i = 0; i < 26; i++)
  {
    if (dups_map[i] > 1)
    {
      std::cout << "Char '" << (char)(i + 97) << "': " << (int)(dups_map[i]) << "\n";
    }
  }

  // bitwise operation for string
  std::bitset<sizeof(char) * 8> bits = 10;
  std::cout << bits << std::endl;
  // bitshift left
  bits <<= 3;
  std::cout << bits << std::endl;

  // bitwise and
  std::cout << (0b1010 & 0b0110) << std::endl;

  // bitwise or
  std::cout << (0b1010 | 0b0110) << std::endl;

  // bitwise xor
  std::cout << (0b1010 ^ 0b0110) << std::endl;

  /*
    Masking: to know if a bit inside memory is ON or OFF
  */

  std::bitset<8> a = 0b00000000;
  std::bitset<8> H = 0b00000001;

  // to know if third bit of a is on
  H <<= 2; // shift until reaches the position to check on A
  std::cout << (a & H) << std::endl;

  /*
    Merging: to set bit inside memory ON
  */

  std::bitset<8> b = 0b00000000;
  std::bitset<8> J = 0b00000001;

  // setting the bit on
  J <<= 2;
  std::cout << (b | J) << std::endl;

  char A[] = "finding";
  int hash = 0;
  int cmp_bits = 0;
  for (int i = 0; A[i] != '\0'; i++)
  {
    cmp_bits = 1;
    cmp_bits <<= (A[i] - 97);
    if ((hash & cmp_bits) > 0)
      std::cout << A[i] << " is duplicate" << "\n";
    else
      hash |= cmp_bits;
  }
}

bool str_eq(char *s1, char *s2)
{
  for (int i = 0, j = 0; s1[i] != '\0' && s2[j] != '\0'; i++)
    if (s1[i] != s2[j])
      return false;

  return true;
}

void str_gt_than(char *s1, char *s2)
{
  int i;
  for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
  {
    if (s1[i] != s2[i])
      break;
  }

  if (s1[i] == s2[i])
    printf("equal");
  else if (s1[i] < s2[i])
    printf("first one is smaller");
  else
    printf("second one is smaller");
}

bool is_palindrome(char *s)
{
  for (int i = 0; s[i] != '\0'; i++)
  {
    std::cout << s[i];
  }

  return false;
}
