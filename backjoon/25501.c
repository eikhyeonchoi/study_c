#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 재귀의 귀재

typedef struct _Word {
	char word[1001];
	int isP;
	int callcnt;
}Word;

int recursion(Word* word, int i, int r);
int isPalindrome(Word* word);

int main() {
	int T;
	scanf("%d", &T);

	Word* words = (Word*)malloc(sizeof(Word) * T);
	for (int i = 0; i < T; i++) {
		scanf("%s", words[i].word);
		words[i].isP = words[i].callcnt = 0;
	}

	for (int i = 0; i < T; i++) {
		words[i].isP = isPalindrome(&words[i]);
		printf("%d %d\n", words[i].isP, words[i].callcnt);
	}

	return 0;
}

int recursion(Word* word, int l, int r) {
	word->callcnt++;
	if (l >= r) return 1;
	else if (word->word[l] != word->word[r]) return 0;
	else return recursion(word, l + 1, r - 1);
}

int isPalindrome(Word* word) {
	return recursion(word, 0, strlen(word->word) - 1);
}