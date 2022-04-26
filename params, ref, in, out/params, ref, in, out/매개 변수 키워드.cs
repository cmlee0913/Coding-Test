using System;
using System.Collections;

namespace Intro_Ex1
{
    class Example
    {
        public void UseParams(params int[] list, int a, int b) {
            foreach(int param in list) {
                Console.WriteLine(param);
            }
        }
    }
    class Program
    {
        Example example = new Example();
        int[] array1 = {1, 3, 5, 7, 9};
        
        static void Main(string[] args)
        {
            // 쉼표로 구분된 인수 목록 사용
            example.UseParams(array1);

            // 지정된 형식의 인수 배열을 사용
            example.UseParams(2, 4, 6, 8, 10);

            // 가변 길이를 사용 가능하기에 인수가 없어도 사용 가능
            example.UseParams();
        }
    }
}