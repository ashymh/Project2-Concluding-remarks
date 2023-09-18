#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	vector<string> words; 
	string str;

	cin >> str; //첫번째 단어 입력

	words.push_back(str); //첫번째 단어 배열 삽입

	clock_t startTime = clock();
	clock_t endTime = clock();

	while ((endTime - startTime) / CLOCKS_PER_SEC < 30) { // 제한시간 30초

		cout << "\n다음 단어를 입력하세요. : ";
		cin >> str;
		cout << endl;

		bool overlap_word = false;

		for (int i = 0; i < words.size(); i++) {//중복된 단어 확인
			if (str == words[i]) {
				overlap_word = true; 
				cout << "이미 입력한 단어입니다. 다른 단어를 입력하세요." << endl;
			}
		}
		if (overlap_word) {
			continue; // 중복된 경우 다시 입력 받음
		}

		words.push_back(str);
	
		string before_Word = words[words.size() - 2]; //이전 단어 저장

		string after_Word = words[words.size() - 1]; // 다음 단어 저장

		int n = before_Word.size();  //이전 단어 길이 선언

		if (before_Word[n - 1] == after_Word[0]) { //끝말이 이어지는지 판단
			for (int i = 0; i < words.size(); i++) {
				if (i > 0) {
					cout << "->"; // 이어진다면 입력한 단어 출력
				}
				cout << words[i];
			}
			cout << endl;
		}
		
		else {
			words.pop_back(); // 끝말이 이어지지 않았을때 재입력
			cout << "끝말과 이어지지 않았습니다." << before_Word[n - 1] << "와 이어지는 단어를 입력해주세요.\n";
		}

		endTime = clock();
	}
		cout << "\n타임오버!\n게임종료!\n" << "총 입력한 단어의 개수 : " << words.size();
		return 0;
}

