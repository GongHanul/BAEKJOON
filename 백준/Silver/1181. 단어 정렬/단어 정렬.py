N = int(input())
letter = []
for _ in range(N):
    l = input()
    letter.append(l)
set_le = list(set(letter))
sort_le = []
for i in set_le:
    sort_le.append((len(i), i))
sort_le.sort()
for len_word, word in sort_le:
    print(word)

