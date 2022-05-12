//당신에게 어떤 문자열이 주어집니다. 당신은 왼손의 검지손가락과 오른손의 검지손가락을 이용하여 이 문자열을 타이핑해야 합니다. 처음에는 왼손 검지는 'Q', 오른손 검지는 'P'에 있습니다.

//매 글자를 누를 때마다, 다음과 같은 기준으로 거쳐 왼손 검지 또는 오른손 검지 중 하나를 선택하여 해당 키를 누릅니다.

//왼손 검지와 오른손 검지로부터의 맨하탄 거리(수평거리 + 수직거리)가 다를 경우, 더 가까운 쪽의 손가락을 이용하여 키를 누릅니다.
//두 맨하탄 거리가 같을 경우, 수평거리가 더 가까운 쪽의 손가락을 이용하여 키를 누릅니다.
//수평거리도 동일할 경우, 해당 키가 키보드 상의 왼쪽('1', '2', '3', '4', '5', 'Q', 'W', 'E', 'R', 'T')에 있을 경우 왼손 검지를 이용해서 누르고, 키보드 상의 오른쪽('6', '7', '8', '9', '0', 'Y', 'U', 'I', 'O', 'P')에 있을 경우 오른손 검지를 이용해서 누릅니다.
//키를 누른 이후, 두 손가락은 맨 처음의 위치로 이동하지 않고, 누른 키의 위치에 대기합니다.

//타이핑해야 할 문자열 line이 매개변수로 주어집니다. 각 글자에 대해 왼손으로 키를 눌러야 하면 0, 오른손으로 키를 눌러야 하면 1을 배열에 담아 return 하도록 solution 함수를 완성해주세요.

using System;
using System.Linq;

public class Solution
{
    public int[] solution(string line)
    {
        int[] answer = new int[] { };
        string[] qwerty = new string[] { "QWERTYUIOP","0123456789" };
        int[] l = new int[] { 0, 0 };
        int[] r = new int[] { 0, 9 };

        foreach (char input in line)
        {
            for (int i = 0; i < 2; i++)
            {
                if (qwerty[i].Contains(input))
                {
                    if (Math.Abs(l[0] - i) + Math.Abs(l[1] - qwerty[i].IndexOf(input)) > Math.Abs(r[0] - i) + Math.Abs(r[1] - qwerty[i].IndexOf(input)))
                    {
                        l[0] = i; l[1] = qwerty[i].IndexOf(input);
                        answer.Append(0);
                    }
                    else if (Math.Abs(l[0] - i) + Math.Abs(l[1] - qwerty[i].IndexOf(input)) < Math.Abs(r[0] - i) + Math.Abs(r[1] - qwerty[i].IndexOf(input)))
                    {
                        r[0] = i; r[1] = qwerty[i].IndexOf(input);
                        answer.Append(1);
                    }
                    else
                    {
                        if (qwerty[i].IndexOf(input) < 5)
                        {
                            l[0] = i; l[1] = qwerty[i].IndexOf(input);
                            answer.Append(0);
                        }
                        else
                        {
                            r[0] = i; r[1] = qwerty[i].IndexOf(input);
                            answer.Append(1);
                        }
                    }
                }
            }
        }

        return answer;
    }
}