#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    vector <vector<int>> a(n, vector <int>(n, 0));
    vector <vector<int>> b(n, vector <int>(n, 0));
    int pv1 = 0; int pv2 = 0;

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > -1; j--) {
            a[i][j] = arr1[pv1] % 2;
            arr1[pv1] = arr1[pv1] / 2;
        }
        pv1++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > -1; j--) {
            b[i][j] = arr2[pv2] % 2;
            arr2[pv2] = arr2[pv2] / 2;
        }
        pv2++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1 || b[i][j] == 1) {
                answer[i] += '#';
            }
            else {
                answer[i] += ' ';
            }
        }
    }

    return answer;
}

// �ٸ� Ǯ��
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        arr1[i] = arr1[i] | arr2[i]; // ��Ʈ������ �ϳ��� 1�̸� 1�� ��ȯ
        string ans = "";
        for (int j = 0; j < n; j++) {
            if (arr1[i] % 2 == 0) ans = " " + ans;
            else ans = "#" + ans;
            arr1[i] = arr1[i] >> 1;
        }
        answer.push_back(ans);
    }
    return answer;
}