//
// ����� 23
//

// ��� ���������� ���� ��������� ��������� ������. �������� ������ �������� �� ������ ����
//
// error: operation on XYZ may be undefined [-Werror=sequence-point]

int main(void)
{
    int a, b, c, i, j;

    a = 5;
    c = (b = a + 2) - (a = 1);

    i = 2;
    j = i * i++;

    return 0;
}