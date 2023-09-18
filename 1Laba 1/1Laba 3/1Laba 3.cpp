#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cout << "������ ��������� ������ n �� m: ";
    cin >> n >> m;

    if (n <= 0 || n > 100 || m <= 0 || m > 10) {
        cout << "��������� ����� ���. �������� ��������� n �� m." << endl;
        return 1;
    }

    vector<vector<double>> A(n, vector<double>(m));

    // �������� ����� � ����� A
    cout << "������ �������� ������ A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "A(" << i + 1 << "," << j + 1 << "): ";
            cin >> A[i][j];
        }
    }

    vector<double> minOfRows(n);

    // ���������� ������ ��� ������� �����
    for (int i = 0; i < n; i++) {
        minOfRows[i] = A[i][0];  // ��������� �������� ������ ��� ��������� �����
        for (int j = 1; j < m; j++) {
            if (A[i][j] < minOfRows[i]) {
                minOfRows[i] = A[i][j];  // ������� �����, ���� �������� ����� ��������
            }
        }
    }

    double maxOfMins = minOfRows[0];  // ��������� �������� ��������� ������

    // ������ �������� ����� ������ �����
    for (int i = 1; i < n; i++) {
        if (minOfRows[i] > maxOfMins) {
            maxOfMins = minOfRows[i];
        }
    }

    cout << "Z = " << maxOfMins << endl;

    return 0;
}
