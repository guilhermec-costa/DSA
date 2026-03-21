def reverse_string_copy(s: str) -> None:
  aux = ""
  for i in range(len(s) - 1, -1, -1):
    aux += s[i]

  return aux

def is_palindrom(s: str) -> bool:
  if reverse_string_copy(s) == s:
    return True

  return False

word1 = "churros"
word2 = "roma é amor";

print("'churros' é palíndromo: ", is_palindrom(word1))
print("'roma é amor' é palíndromo: ", is_palindrom(word2))