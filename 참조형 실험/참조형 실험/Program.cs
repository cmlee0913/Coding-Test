using System;
using System.Collections;

namespace 참조형_실험
{
    class Example
    {
        public int[] a = { 10 };
        public dynamic b = 10;
        public int[] c = { 10 };
        public void atob(int[] a)
        {
            // 참조하는 값이 달라져서 원본이 달리지지 않음.
            a = new int[] { 20 };
        }
        public void atob(Example a)
        {
            // 참조하는 값이 같기 때문에 원본이 바뀜.
            a.b = 20;
            a.c = new int[] { 20 };
        }
        public void atob(object a)
        {
            // object와 dynamic도 초기화하면 인스턴스를 새롭게 생성한다.
            a = 20;
        }
        public void atob(string a)
        {
            // new가 없지만 string의 인스턴스는 새로 생성된 상태. 그래서 안 바뀐다.
            a = "20";
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            // 이 부분은 스택에 저장
            int a = 10;
            // a를 힙에 복사한다(박싱)
            object o = a;

            Example example = new();
            string s = "10";

            example.atob(example.a);
            example.atob(example);
            example.atob(o);
            example.atob(s);

            Console.WriteLine($"{example.a[0]}, {example.b}, {example.c[0]}, {o}, {s}");
        }
    }
}
