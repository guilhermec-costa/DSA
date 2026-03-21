from typing import List 

# hashmap method for finding duplicates
def str_duplicates(s: str) -> List[str]:
  duplicate_map = dict()
  for l in s:
    in_map = duplicate_map.get(l)
    if not in_map:
      duplicate_map[l] = 1
    else:
      duplicate_map[l] += 1

  return [k for k,v in duplicate_map.items() if v > 1]

def str_duplicates_no_dict(s: str) -> List:
  return {c for c in s if s.count(c) > 1}

# comparison method for finding duplicates
def str_duplicates_comparison(s: str) -> List:
  duplicates = []
  for idx, c in enumerate(s):
    for c2 in s[idx+1:]:
      if c == c2 and c not in duplicates:
        duplicates.append(c)

  return duplicates

def remove_sub_str(base: str, rm: str) -> str:
  substr = ""
  finds_at = base.find(rm)

  if finds_at == -1:
    return base

  delete_limit = finds_at + len(rm) - 1
  for idx, c in enumerate(base):
    if idx not in range(finds_at, delete_limit + 1):
      substr += c

  return substr

def remove_sub_str_slicing(base: str, rm: str) -> str:
  finds_at = base.find(rm)
  if finds_at == -1:
    return base

  return base[:finds_at] + base[finds_at+len(rm):]

print(str_duplicates("churrosso"))
print(str_duplicates_no_dict("churrosso"))
print(str_duplicates_comparison("churrosso"))
print(remove_sub_str("eu amo mainha", "eu"))
print(remove_sub_str_slicing("eu amo mainha", "eu"))